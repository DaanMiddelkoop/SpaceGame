#include <iostream>
#include <raytraceengine.h>

int main() {
    std::cout << "SpaceGame v0.1\n";
    RT::init();

    RT::Window* window = RT::createWindow();
    RT::RayTraceContext* rtcontext = RT::createWorld( );

    while (!RT::windowShouldClose(window)) {

        rtcontext->draw(window);

        RT::update(window);


    }

}
