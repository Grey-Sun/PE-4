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

void DisplayBoard(std::vector<std::vector<std::string>> game_board){
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            std::cout << game_board[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<std::vector<std::string>> game_board = CreateBoard();
    return 0;
}