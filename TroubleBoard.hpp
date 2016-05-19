// TroubleBoard.hpp
// Board implements a linked list using a linked set of nodes.
// No memory is allocated on creation, but only as elements are added
// to the list.

#ifndef TROUBLE_BOARD_HPP
#define TROUBLE_BOARD_HPP
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class TroubleBoard
{
    friend class TroubleBoardGame;
    
public:
    // Can be seen outside as TroubleBoard::DataType
    typedef int DataType;

    // This type of list can basically grow as large as we want it to,
    // so we'll just pick an arbitrary large value as the capacity for
    // all lists of this type.
    static const unsigned int CAPACITY = 65536;

private:
    // The node structure used for the Trouble Board.
    struct Node {
        Node(DataType value);
        DataType value;
        Node* next;
        Node* out;
    };

// CONSTRUCTOR
public:
    // Create a new empty LinkedList.
    TroubleBoard();

// ACCESSORS
public:
    // Returns the number of elements in the list.
    unsigned int size() const;
    // Returns the maximum number of elements the list can hold.
    unsigned int capacity() const;
    // Returns true if the list is empty, false otherwise.
    bool empty() const;

    // Prints all elements in the list to the standard output.
    void print() const;

// MUTATORS
public:
    // NOTE: all mutators for this class are boolean functions, returning
    // true if the call succeeds, and false if it fails
    // Inserts a value at the beginning of the list.
    
    bool insert_home(DataType val);
    
    bool insert_start(DataType val);
    
    bool insert_pointers();
    
    bool initialize();
    //Checks for winning condition
    bool IsWin();
    //Displaying the board
    bool DisplayBoard();
    //Moving the game piece
    bool Move(string decision, int roll);
    //Checks to see if any piece is possible
    bool AnyPossible(int roll, string playerColour);
    //Checks to see if a piece is possible
    bool IsPossible(string decision, int roll);
    //If another colour piece lands on top of a piece, that piece gets sent to the start
    bool SendToStart(string gamePiece);
    // Inserts a value at the end of the list.
    bool insert_back(DataType val);
    
// MEMBER VARIABLES
private:
    // A pointer to the head node of the list.
    // A pointer to the tail node of the list.
    Node* tail_;
    
    //start pointers
    Node* bluestart;
    
    Node* greenstart;
    
    Node* yellowstart;
    
    Node* redstart;
    
    //game pieces
    Node* b1;
    
    Node* b2;
    
    Node* b3;
    
    Node* b4;
    
    Node* g1;
    
    Node* g2;
    
    Node* g3;
    
    Node* g4;
    
    Node* y1;
    
    Node* y2;
    
    Node* y3;
    
    Node* y4;
    
    Node* r1;
    
    Node* r2;
    
    Node* r3;
    
    Node* r4;
    
    // The number of elements in the list.
    unsigned int size_;
    
private:
    // Copy constructor. Declared private so we don't misuse it.
    TroubleBoard(const TroubleBoard& rhs) {}
    // Assignment operator. Declared private so we don't misuse it.
    TroubleBoard& operator=(const TroubleBoard& rhs) {}
};

#endif  //TROUBLE_BOARD_HPP
