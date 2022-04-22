#ifndef _TRANSAQ_CONNECTOR
#define _TRANSAQ_CONNECTOR
#include <string>
#include <iostream>

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

    void print();
};

class TransaqConnector {
    User user;

public:
    TransaqConnector();
    TransaqConnector(const std::string& login, const std::string& password);

    User& getUser() {
        return user;
    }

    ~TransaqConnector();
};

#endif