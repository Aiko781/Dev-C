#include <string>

class Password {
    private:
        std::string _raw_value;
        std::string _encrypted_value;
        void encrypt(const std::string &password);
        void is_valid(std::string password);

    public:
        Password(const std::string &password, bool is_encrypted = false);
        std::string str();

        bool operator ==(const std::string &str) const;
        bool operator ==(const Password &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Password &p);
};