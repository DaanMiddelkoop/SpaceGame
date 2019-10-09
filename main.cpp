#include <iostream>
#include <raytraceengine.h>

#include <vector>

int main() {
    std::cout << "SpaceGame v0.1\n";
    RT::init();

    RT::Window* window = RT::createWindow();
    RT::RayTraceContext* rtcontext = RT::createWorld( );

    RT::Mesh* player = rtcontext->createMesh();

    std::vector<float> vertices = std::vector<float>();

    for (int x = 1; x < 4; x++) {
        for (int y = 1; y < 4; y++) {
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

    while (!RT::windowShouldClose(window)) {

        rtcontext->draw(window);

        RT::update(window);


    }

}
