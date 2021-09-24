#include <iostream>
#include <vector>
#include <string>


void DisplayBoard(std::vector<std::vector<std::string>> game_board){
    for (std::vector<std::string> i : game_board)
    {  
        for (std::string i2 : i)
        {
            std::cout << i2 << " ";
        }   
        std::cout << std::endl;
    }
 }

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
    DisplayBoard(game_board);
    return 0;
}