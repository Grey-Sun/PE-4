#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> CreateBoard(){
    std::vector<std::vector<std::string>> board {
        {".", ".", "."},
        {".", ".", "."},
        {".", ".", "."}
    };
    return board;
}

int main(){
    std::vector<std::vector<std::string>> game_board = CreateBoard();
    return 0;
}