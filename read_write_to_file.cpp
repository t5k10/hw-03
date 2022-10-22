#include "read_write_to_file.h"
#include <iostream>
#include <climits>

const std::string high_scores_filename = "high_scores.txt";
      
bool write_to_file(std::string user_name, int attempts_count) {
    std::fstream file{high_scores_filename, std::ios_base::out | std::ios_base::in};
    if (!file.is_open()) {
        file.clear();
        file.open(high_scores_filename, std::ios_base::app);
    }
    std::string name;
    int score;
    bool exist_name = false;
    while (true) { 
        int pos_in_file = file.tellp();
        file >> name;
        file >> score;
        file.ignore();
        if (file.fail()) break;
        if (user_name == name) {
            if (attempts_count < score) {
                exist_name = true;
                file.seekp(pos_in_file);
                file << name << ' ' << attempts_count << std::endl; 
            } 
            else exist_name = true; 
        }
    }
    if (!exist_name) {
        file.clear();
        file << user_name << ' ' << attempts_count << std::endl;
    }
    file.close();
    return true;    
}

bool read_from_file() {
    std::ifstream in_file{high_scores_filename, std::ios_base::in};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return false;
    }
    std::cout << "High scores table:" << std::endl;
    std::string username;
    int high_score = 0; 
    while (true) {
        in_file >> username;
        in_file >> high_score; 
        in_file.ignore();
        if (in_file.fail()) break;
        std::cout << username << '\t' << high_score << std::endl;
    } 
    in_file.close();
    return true;
}
