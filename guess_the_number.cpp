#include "play_game.h"

int main(int argc, char** argv) {
    
    if (argc >= 2) {
        std::string arg1 = argv[1];
        if (arg1.compare("-max") == 0) {
            const int max_value = std::atoi(argv[2]); 
            play_the_game(max_value);
        } else if (arg1 == "-table") {
            read_from_file();        
        } else if (arg1 == "-level") {
            const int level = std::atoi(argv[2]);
            int max_value = 0 ;
            if (level == 1) max_value = 9;
            else if (level == 2) max_value = 49;
            else if (level == 3) max_value = 99;
            play_the_game(max_value);
        }
    } 
    else { 
        play_the_game(); 
    }        
}
