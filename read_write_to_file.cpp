#include "read_write_to_file.h"
#include <iostream>
#include <climits>

const std::string high_scores_filename = "high_scores.txt";
     
     // Write 
bool write_to_file(std::string user_name, int attempts_count) {
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
         std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
         return false;
    }
    out_file << user_name << ' ';
    out_file << attempts_count;
    out_file << std::endl;
    out_file.close();
    return true;
}

     // Read 
bool read_from_file() {
    std::ifstream in_file{high_scores_filename};
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
