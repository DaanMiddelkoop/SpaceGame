#include <iostream>
#include <raytraceengine.h>

#include <vector>
#include <chrono>
#include <thread>
#include <stdint.h>
#include <math.h>

int main() {
    std::cout << "SpaceGame v0.1\n";
    RT::init();

    RT::Window* window = RT::createWindow();
    RT::RayTraceContext* rtcontext = RT::createWorld( );

    RT::Mesh* player = rtcontext->createMesh();

    std::vector<float> vertices = std::vector<float>();
    std::vector<float> uvcoords = std::vector<float>();

    int something = 20;
    for (int x = -something; x < something; x++) {
        for (int y = -something; y < something; y++) {
            vertices.push_back(0.1 * x);
            vertices.push_back(0.1 * y);
            vertices.push_back(0.0f);

            vertices.push_back(0.1 * x + 0.1);
            vertices.push_back(0.1 * y);
            vertices.push_back(0.0f);

            vertices.push_back(0.1 * x + 0.05);
            vertices.push_back(0.1 * y + 0.1);
            vertices.push_back(0.0f);

            float x2 = (float)x + something;
            float y2 = (float)y + something;

            float step = (1.0 / (float)(something));

            uvcoords.push_back(x2 * step);
            uvcoords.push_back(y2 * step);

            uvcoords.push_back(x2 * step + step);
            uvcoords.push_back(y2 * step);

            uvcoords.push_back(x2 * step + (step / 2.0));
            uvcoords.push_back(y2 * step + step);
        }


    }

    uint8_t texture_data[16] = {
        255, 0, 0, 255,
        0, 255, 0, 255,
        0, 0, 255, 255,
        255, 0, 255, 255
    };

    RT::TextureHandle texture = rtcontext->createTexture();

    std::cout << "Reaching this?!!!!!\n";
    texture.setData(2, 2, (uint8_t*)&texture_data);

    RT::MaterialHandle material = rtcontext->createMaterial();
    material.setTexture(&texture);


    //player->setVertices(vertices.data(), vertices.size());


    player->setMaterial(&material);
    RT::ObjLoader objLoader = RT::ObjLoader();
    objLoader.loadObjFile("/home/daan/projects/SpaceGame/objFiles/monkey.obj");
    objLoader.inflate(player);



    //player->setUVCoords(uvcoords.data(), uvcoords.size());


    //player->build();
    player->setPosition(1.0, 0.0, 0.0);

    rtcontext->setCameraPosition(0.0f, 0.0f, 0.0f);
    rtcontext->setCameraDirection(0.0f, 0.0f, -1.0f);


    float distance = 4.0f;
    float frame = 0.0f;

    std::cout << "amount of pixels reserved on gpu: " << rtcontext->getPixels()->size() << "\n";

    float x = 0;
    while (!RT::windowShouldClose(window)) {
        //std::cout << "drawwwwww\n";
        frame += 0.01f;
        rtcontext->setCameraPosition(distance * sin(frame), 0.0, distance * cos(frame));
        rtcontext->setCameraDirection(-distance * sin(frame), 0.0, -distance * cos(frame));
        rtcontext->draw(window);
        rtcontext->setDebugInfo(x, 0, 0);

        RT::update(window);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));

        x += 1;

    }

}
