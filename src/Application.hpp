#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP
#include "System.hpp"
#include "TransaqConnector.hpp"

class Application {
    static Application* app;
    TransaqConnector connector;

    HMODULE hm = 0;
    Application() {

    }
public:
    static Application& getApplication() {
        if (app) return *app;
        app = new Application();
        return *app;
    }

    TransaqConnector& getConnector() {
        return connector;
    }
    static void destroy() {
        delete app;
    }

    void run(const std::string& login, const std::string& password) {
        // Application Core
        System::loadLibrary(hm, "D:\\repo\\ScalpAssistant\\src\\lib\\finam\\txmlconnector64.dll");

        if (hm) {


            // TransaqConnector

        }
        connector.getUser().initialize(login, password);
    }
    void close() {

    }
};

Application* Application::app = nullptr;

#endif