#ifndef _SYSTEM_H
#define _SYSTEM_H
#include <string>
#include <iostream>
// #include <format>
#include <source_location>
#include <windows.h>

namespace System {
    enum class MessageType {
        Default = 0,
        Error = 1,
        Notification
    };

    void terminate(const int& code = 0) {
        // danger code
        exit(0);
    }
    inline void print(const std::string& msg, MessageType type = MessageType::Default) {
        std::string title;
        switch(type) {
            case MessageType::Error : {
                title = "Error";
                break;
            }
            case MessageType::Notification: {
                title = "Notification";
                break;
            }
            default:
                title = "MSG";
        }


        std::cout << "[" << title << "]: " << msg << std::endl;
    }

    const bool loadLibrary(HMODULE& hm, const std::string& path) {
        hm = LoadLibrary(path.c_str());
        int err = GetLastError();

        if (!hm) {
            print("Cannot load library. Error code: " + std::to_string(err) + " | Path: " + path, MessageType::Error);

            terminate();
        } else {
            print("Library: " + path + " loaded.");
        }

        return true;
    }
};
#endif