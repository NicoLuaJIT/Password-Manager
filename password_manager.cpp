#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Password {
    std::string password;
};

void CreatePassword(std::string &name, std::vector<Password> &v) {
    std::cout << "Create your password: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Password successfully created.\n";
    v.push_back({name});
}

void ReadPassword(std::string &name, std::vector<Password> &v) {
    std::cout << "Enter your password: ";
    std::getline(std::cin >> std::ws, name);
    auto it = std::find_if(v.begin(), v.end(), [&](const Password& p) {
        return p.password == name;
    });

    if (it != v.end()) {
        std::cout << "Password found.\n";
    } else {
        std::cout << "Password not found.\n";
    }
}

void GetPasswords(std::vector<Password> &v) {
    int counter = 1;
    for (const auto &i : v) {
        std::cout << "Password #" << counter << ": " << i.password << "\n";
        counter += 1;
    }
}

int main() {
    std::vector<Password> previousPasswords = {};
    while (true) {
        int choice;
        std::cout << "0. Exit\n1. Create Password\n2. Put Password\n3. Show All Previous Passwords\nChoice: ";
        std::cin >> choice;
        switch (choice) {
            case 0: return 0;
            case 1: { std::string password; CreatePassword(password, previousPasswords); break; }
            case 2: { std::string password; ReadPassword(password, previousPasswords); break; }
            case 3: {GetPasswords(previousPasswords); break; }
        }
    }
}
