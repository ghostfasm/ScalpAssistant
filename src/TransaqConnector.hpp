#ifndef _TRANSAQ_CONNECTOR
#define _TRANSAQ_CONNECTOR
#include <string>
#include <iostream>
#include <fstream>
#include "lib/finam/Functions.hpp"
#include "System.hpp"

#define TACCESS_API  __declspec(dllimport)

class User {
    std::string login;
    std::string password;
public:
    User() {

    }

    User(const std::string& login, const std::string& password) :
        login(login), password(password) {

    }
    ~User() {

    }

    inline std::string getLogin() const {
        return login;
    }

    inline std::string getPassword() const {
        return password;
    }

    inline void setLogin(const std::string& login) {
        this->login = login;
    }

    inline void setPassword(const std::string& password) {
        this->password = password;
    }

    void initialize(const std::string& login, const std::string& password) {
        setLogin(login);
        setPassword(password);
    }

    void print() {
        std::cout << "User: " << login << "\nPassword: " << password << std::endl;
    }
};

class TransaqConnector {
    User user;

    HMODULE hm = 0;
    typeFreeMemory FreeMemory;
    initialize initLog;

public:
    enum class CommandType {
        CONNECT = 0
    };

    TransaqConnector() {

    }
    TransaqConnector(const std::string& login, const std::string& password) {
        user.setLogin(login);
        user.setPassword(password);


        System::loadLibrary(hm, "D:\\repo\\ScalpAssistant\\src\\lib\\finam\\txmlconnector64.dll");

        if (hm) {
            FreeMemory = reinterpret_cast<typeFreeMemory>(GetProcAddress(hm, "FreeMemory"));
            initLog = reinterpret_cast<initialize>(GetProcAddress(hm,"Initialize"));
            initLog(const_cast<BYTE*> (reinterpret_cast<const BYTE*>("D:\\test")), 2);
        }
    }

    bool connect() {
        if (user.getLogin().size() == 0 || user.getPassword().size() == 0) {
            System::print("Check login and password.", System::MessageType::Error);
            return false;
        }

        System::print("TransaqConnector - connected.", System::MessageType::Notification);
        return true;
    }

    void disconnect() {
        System::print("TransaqConnector - disconnected.", System::MessageType::Notification);
    }


    inline User& getUser() {
        return user;
    }

    bool sendCommand() {
        typeSendCommand SendCommand =
            reinterpret_cast<typeSendCommand>(GetProcAddress(hm,"SendCommand"));
        if (!SendCommand) {
            System::print("\"SendCommand\" not found (0x" + std::to_string(GetLastError()) + ")\n", System::MessageType::Error);
            return false;
        } else {
            // BYTE* ss = SendCommand(cmd);

            BYTE* ss = SendCommand(const_cast<BYTE*> (reinterpret_cast<const BYTE*>(
                "<command id='connect'>"
                "<login>KOKS</login><password>koks</password>"
                "<host>192.168.15.14</host><port>3901</port>"
                "<logsdir>.\\LOGS\\</logsdir><loglevel>0</loglevel></command>")));

            std::ofstream out("log.txt");
            std::cout << reinterpret_cast<const char*>(ss) << std::endl;
            out << reinterpret_cast<const char*>(ss);
            out.close();
        
            FreeMemory(ss);
        }

        return true;
    }

    bool CALLBACK acceptor(BYTE *pData)
    {
        // xmlfile<<pData<<std::endl;
        FreeMemory(pData);
        return true;
    }

    ~TransaqConnector();
};

#endif