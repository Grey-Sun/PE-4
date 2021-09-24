#include <iostream>
#include <vector>
#include <string>
/*
Simon Israily and Grayson Arstingstall
PE4 CSCI 3010 Fall 2021
*/

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


/**
    Takes a board 2D vector and returns a integer vector with a row and column value.
    
    @param board is the 2D game board 
*/
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
        std::cout << "Invalid location, please pick a new spot on the board" << std::endl;
    }
}
//main game flow 
int main(){
    std::vector<std::vector<std::string>> game_board = CreateBoard(); //make an empty board
    int counter = 0;
    while(true) { //infinite loop to keep the game going until no one can make a move
        DisplayBoard(game_board); //display the board before the turn
        if (counter % 2 == 0){ //even counter number
            std::cout << "It is Player 1s turn" << std::endl;
            std::vector<int> choice = GetPlayerChoice(game_board); //get the player choice for the move
            PlaceMarker(choice, "X", game_board); //place an X at the point on the board
        }
        else{
            std::cout << "It is Player 2s turn" << std::endl;
            std::vector<int> choice = GetPlayerChoice(game_board); //get player choice
            PlaceMarker(choice, "O", game_board); //place an O in that spot on the board
        }
        if(counter > 9){ //if the board is full
            break;
        }
        counter++; //increment the counter
    }
        
        
    return 0;
}