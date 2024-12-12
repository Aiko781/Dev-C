#include "password.hpp"
#include <iostream>
#include <cassert>
#include <memory>

Password::Password(const std::string &password, bool is_encrypted) : _raw_value(password) {
    try {
        is_valid(password);
    } catch (const std::invalid_argument &e) {
        throw std::invalid_argument("Invalid password");
    }
    if (!is_encrypted) {
        encrypt(password);
    }
}

void Password::is_valid(std::string password) {
    if (password.size() < 6) {
        throw std::invalid_argument("Password must be at least 6 characters long");
    }
    if (password.find_first_of("0123456789") == std::string::npos) {
        throw std::invalid_argument("Password must contain at least one digit");
    }
    if (password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) {
        throw std::invalid_argument("Password must contain at least one uppercase letter");
    }
    if (password.find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
        throw std::invalid_argument("Password must contain at least one lowercase letter");
    }
    if (password.find_first_of("!@#$%^&*()_+-=") == std::string::npos) {
        throw std::invalid_argument("Password must contain at least one special character");
    }
}


void Password::encrypt(const std::string &password) {
    // encrypt password by using a simple algorithm
    for (char c : password) {
        _encrypted_value += c + 7;
    }
}

std::string Password::str() {
    return _encrypted_value;
}

// sert à comparer un mot de passe en clair avec un mot de passe crypté
bool Password::operator ==(const std::string &str) const {
    return str == _encrypted_value;
}

// sert à comparer deux mots de passe cryptés
bool Password::operator ==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
}

// sert à afficher un mot de passe crypté
std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    return os;
}

int main() {
    auto password = std::make_unique<Password>("123456");
    assert(password != "123456");
    std::cout << password == "123456" << std::endl;

    auto saved_password = password.str();
    auto password2 = std::make_unique<Password>(saved_password, true);
    assert(password == password2);

}