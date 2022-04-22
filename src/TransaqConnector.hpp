#ifndef _TRANSAQ_CONNECTOR
#define _TRANSAQ_CONNECTOR
#include <string>
struct User {
    std::string login;
    std::string password;

    User(const std::string& login, const std::string& password) :
        login(login), password(password) {

    }
    ~User() {

    }
};

class TransaqConnector {
    User* user = nullptr;

public:
    TransaqConnector(const std::string& login, const std::string& password): user(new User(login, password)) {

    }
    ~TransaqConnector() {
        delete user;
    }
};

#endif