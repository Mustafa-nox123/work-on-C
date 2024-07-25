#include <iostream>
#include <vector>

bool isConsecutive(const std::string& str) {
    if (str[0] == '\0') {
        return false;
    }

    // Check ascending order
    bool ascending = true;
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] != str[i - 1] + 1) {
            ascending = false;
            break;
        }
    }

    if (ascending) {
        return true;
    }

    // Check descending order
    bool descending = true;
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] != str[i - 1] - 1) {
            descending = false;
            break;
        }
    }

    return descending;
}

void displayConsecutive(const std::string& str) {
    std::vector<char> consecutive;
    for (size_t i = 0; i < str.length(); ++i) {
        consecutive.push_back(str[i]);
        if (i + 1 == str.length() || str[i] != str[i + 1] - 1) {
            if (consecutive.size() > 1) {
                std::cout << "Consecutive numbers: ";
                for (const auto& ch : consecutive) {
                    std::cout << ch;
                }
                std::cout << std::endl;
            }
            consecutive.clear();
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string of characters: ";
    std::cin >> input;

    if (isConsecutive(input)) {
        std::cout << "The input contains consecutive numbers." << std::endl;
        displayConsecutive(input);
    } else {
        std::cout << "The input does not contain consecutive numbers." << std::endl;
    }

    return 0;
}


