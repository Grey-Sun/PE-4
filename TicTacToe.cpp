#include <iostream>
#include <vector>
#include <string>

/**
    Displays the game board in the terminal window.

    @param game_board A two dimentional vector corresponding to the game board.
*/
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

/**
    Creates and returns a two dimentional board for an xox game.

    @return game_board A two dimentional vector corresponding to the game board.
*/
std::vector<std::vector<std::string>> CreateBoard(){
    std::vector<std::vector<std::string>> board {
        {".", ".", "."},
        {".", ".", "."},
        {".", ".", "."}
    };
    return board;
}


/**
    Takes a location to play and a marker to place their and updates the board 
    at the specified location with the specified marker.
    
    @param location A  vector with row and column where the user would like to go
    @param marker A string marker corresponding to x or o, depending on who the user is.
    @param game_board 2d vector correspondign the the game board.
*/
void PlaceMarker(std::vector<int> location, std::string marker, std::vector<std::vector<std::string>> &game_board){
    game_board.at(location.front()).at(location.back()) = marker;
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
    PlaceMarker(std::vector<int>{0,0},"x",game_board);
    DisplayBoard(game_board);
    return 0;
}