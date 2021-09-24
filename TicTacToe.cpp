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


int main(){
    std::vector<std::vector<std::string>> game_board = CreateBoard();
    PlaceMarker(std::vector<int>{0,0},"x",game_board);
    DisplayBoard(game_board);
    return 0;
}