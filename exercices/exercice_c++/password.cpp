#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted):
	_raw_value(password) {
        if (is_encrypted) {
            _encrypted_value = password;
        } else {
            encrypt(password);
        };
};
void Password::encrypt(const std::string &password) {
    // Encrypt password with cesar

    // For each char in password
    // Add 3 to the ASCII value
    // Store the new char in _encrypted_value
    for (char c : password) {
        _encrypted_value += c + 3;
    };
};
std::string Password::str() const {
	return _encrypted_value;
}
bool Password::operator==(const std::string &str) const {
    return str == _encrypted_value;
}
bool Password::operator==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
}
std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    return os;
}
