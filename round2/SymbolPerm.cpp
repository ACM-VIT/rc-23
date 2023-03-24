#include <iostream>
#include <cmath>
#include <limits>

int main() {
    int t;
    while (!(std::cin >> t)) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n') {
            continue;
        }
    }

    for (int i = 0; i < t; i++) {
        int a, b;
        while (!(std::cin >> a)) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }

        while (!(std::cin >> b)) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }

        int result = static_cast<int>(std::pow(a, b)) % (a + b);

        std::cout << result << std::endl;
    }

    return 0;
}