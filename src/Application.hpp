#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP
#include "TransaqConnector.hpp"

class Application {
    static Application* app;
    Application() {}

    
public:
    static Application& getApplication() {
        if (app) return *app;
        app = new Application();
        return *app;
    }
    static void destroy() {
        delete app;
    }

    void run();
    void close();
};

Application* Application::app = nullptr;

#endif