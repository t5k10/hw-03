#include "play_game.h"
#include "read_write_to_file.h"


void play_the_game(const int max) {
    std::srand(std::time(nullptr));
    const int target_value = std::rand() % max;
    int current_value = 0;
    bool not_win = true;
    int attempts_count = 0;
    std::cout << "Hi! Enter your name, please:\n";
    std::string user_name;
    std::cin >> user_name;
    std::cout << "Enter your guess:\n";
    while (not_win) {
        std::cin >> current_value;
        ++attempts_count; 
        if (!std::cin || current_value > max || current_value < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad value!\n";
            std::cout << "Enter your guess:\n";
        }
        else if (current_value < target_value) {
            std::cout << "Less than " << current_value << '\n';
        }   
        else if (current_value > target_value) {
            std::cout << "Greater than " << current_value << '\n';
        }
        else {
            std::cout << "You win! Attempts = " << attempts_count << '\n';
            not_win = false;
        }
    }
    write_to_file(user_name, attempts_count);
    read_from_file();
}

void play_the_game() {
    std::srand(std::time(nullptr));
    const int max_value = 100;
    const int target_value = std::rand() % max_value;
    int current_value = 0;
    bool not_win = true;
    int attempts_count = 0;
    std::cout << "Hi! Enter your name, please:\n";
    std::string user_name;
    std::cin >> user_name;
    std::cout << "Enter your guess:\n";
    while (not_win) {
        std::cin >> current_value;
        ++attempts_count; 
        if (!std::cin || current_value > max_value || current_value < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad value!\n";
            std::cout << "Enter your guess:\n";
        }
        else if (current_value < target_value) {
            std::cout << "Less than " << current_value << '\n';
        }   
        else if (current_value > target_value) {
            std::cout << "Greater than " << current_value << '\n';
        }
        else {
            std::cout << "You win! Attempts = " << attempts_count << '\n';
            not_win = false;
        }
    }
    write_to_file(user_name, attempts_count);
    read_from_file();
}
