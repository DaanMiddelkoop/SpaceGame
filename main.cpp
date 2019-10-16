#include <iostream>
#include <raytraceengine.h>

#include <vector>
#include <chrono>
#include <thread>

int main() {
    std::cout << "SpaceGame v0.1\n";
    RT::init();

    RT::Window* window = RT::createWindow();
    RT::RayTraceContext* rtcontext = RT::createWorld( );

    RT::Mesh* player = rtcontext->createMesh();

    std::vector<float> vertices = std::vector<float>();

    int something = 5;
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
        }

    }

    player->setVertices(vertices.data(), vertices.size());
    player->build();
    rtcontext->setCameraPosition(0.0f, 0.0f, -5.0f);
    rtcontext->setCameraDirection(0.0f, 0.0f, 1.0f);

    float x = 0;
    while (!RT::windowShouldClose(window)) {
        //std::cout << "drawwwwww\n";
        rtcontext->draw(window);
        rtcontext->setDebugInfo(x, 0, 0);

        RT::update(window);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));

        x += 1;

    }

}
