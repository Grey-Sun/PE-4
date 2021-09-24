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

std::vector<int> GetPlayerChoice(std::vector<std::vector<std::string>> board) {
    while (true){ //set infinite condition to keep looping
        std::vector<int> coordinate;
        std::cout << "Please enter the column coordinate for your move (0-2): ";//prompt user for column
        int column;
        std::cin >> column; //get column
        std::cout << "Please enter the row coordinate for your move (0-2): "; //prompt user for row input
        int row;
        std::cin >> row; //get row
        if (board[column][row] == "."){ //make sure that the corresponding coordinate is valid
            coordinate.push_back(row); //if so add the coordinate to the vector
            coordinate.push_back(column);
            return coordinate; //exit the loop
        }
    }
}

int main(){
    std::vector<std::vector<std::string>> game_board = CreateBoard();
    DisplayBoard(game_board);
    return 0;
}