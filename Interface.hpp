#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <limits>

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "TroubleBoard.hpp"
#include <ctime> //Needed for the true randomization
#include <cstdlib>
using namespace std;


class TroubleBoardGame
{
public:
TroubleBoard board;

bool blueFirstTurn;
bool greenFirstTurn;
bool yellowFirstTurn;
bool redFirstTurn;

string BluePlayerType, GreenPlayerType, YellowPlayerType, RedPlayerType;

	bool buildgameboard()
	{
		//for true randomization
		srand(time(NULL));
		//turn format changes once a 6 is rolled from the colour
		blueFirstTurn = true;
		greenFirstTurn = true;
		yellowFirstTurn = true;
		greenFirstTurn = true;
		//setting up the board using a linked list
		board.insert_back(100);
		board.insert_back(1);
		board.insert_back(2);
		board.insert_back(3);
		board.insert_back(4);
		board.insert_back(5);
		board.insert_back(6);
		board.insert_back(200);
		board.insert_back(7);
		board.insert_back(8);
		board.insert_back(9);
		board.insert_back(10);
		board.insert_back(11);
		board.insert_back(12);
		board.insert_back(300);
		board.insert_back(13);
		board.insert_back(14);
		board.insert_back(15);
		board.insert_back(16);
		board.insert_back(17);
		board.insert_back(18);
		board.insert_back(400);
		board.insert_back(19);
		board.insert_back(20);
		board.insert_back(21);
		board.insert_back(22);
		board.insert_back(23);
		board.insert_back(24);
		//start pointers are place at each colour's start
		board.insert_pointers();
		//'home' spaces
		board.insert_home(211);
		board.insert_home(212);
		board.insert_home(213);
		board.insert_home(214);
		board.insert_home(311);
		board.insert_home(312);
		board.insert_home(313);
		board.insert_home(314);
		board.insert_home(411);
		board.insert_home(412);
		board.insert_home(413);
		board.insert_home(414);
		board.insert_home(111);
		board.insert_home(112);
		board.insert_home(113);
		board.insert_home(114);
		//actual start spaces that are outside the board
		board.insert_start(101);
		board.insert_start(201);
		board.insert_start(301);
		board.insert_start(401);
		//confirmation that it printed correctly
		board.print();
		//game pieces positioned at starting positions
		board.initialize();
		cout << endl;
		cout << "Welcome to Trouble";
		cout << endl;
		
		BluePlayerType = GetPlayerType("blue");
		GreenPlayerType = GetPlayerType("green");
		YellowPlayerType = GetPlayerType("yellow");
		RedPlayerType = GetPlayerType("red");		
		
		int PlayerNumber = 1;
		//4 players, 4 colours
		while (!board.IsWin())	
		{
			Turn(PlayerNumber);
			PlayerNumber++;
			if (PlayerNumber == 5)
			{
				PlayerNumber = 1;
			}
		}						
	}
	
	
	bool Turn(int PlayerNumber)
	{
		if (PlayerNumber == 1)
		{
			string decision = "b1";
			//if a six was not rolled prior
			if (blueFirstTurn == true)
			{
				for (int i = 0; i < 3; i++)
				{
					int roll = rand()%6 + 1;
					cout << "Blue rolled a " << (roll);
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					if (roll == 6)
					{
						board.Move(decision, roll);
						blueFirstTurn = false;
						board.DisplayBoard();
						break;
					}
					if (i == 2)
					{
						cout << "You cannot move any of your pieces";
						cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
						return false;
					}					
				}
			}
			int roll = 0;
			do
			{
				roll = rand()%6 + 1;
				cout << "Blue rolled a " << (roll);
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				if (board.AnyPossible(roll, "blue") == true) // ends roll if nothing possible, will display what is possible
				{
					board.DisplayBoard();
					if (BluePlayerType == "human") HumanNumberSelection("blue", roll);
					if (BluePlayerType == "ai") AiNumberSelection("blue", roll);
					board.DisplayBoard();	
				}
			}	while (roll == 6); //repeat if a 6 is rolled
		}
		if (PlayerNumber == 2)
		{
			if (greenFirstTurn == true)
			{
				for (int i = 0; i < 3; i++)
				{
					int roll = rand()%6 + 1;
					cout << "Green rolled a " << (roll);
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					if (roll == 6)
					{
						board.Move("g1", roll);
						board.DisplayBoard();
						greenFirstTurn = false;
						break;
					}
					if (i == 2)
					{
						cout << "You cannot move any of your pieces";
						cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
						return false;
					}					
				}
			}
			int roll = 0;
			do
			{
				roll = rand()%6 + 1;
				cout << "Green rolled a " << (roll);
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				if (board.AnyPossible(roll, "green") == true) // ends roll if nothing possible, will display what is possible
				{
					board.DisplayBoard();
					if (BluePlayerType == "human") HumanNumberSelection("green", roll);
					if (BluePlayerType == "ai") AiNumberSelection("green", roll);
					board.DisplayBoard();	
				}
			}	while (roll == 6);
		}		
		if (PlayerNumber == 3)
		{
			if (yellowFirstTurn == true)
			{
				for (int i = 0; i < 3; i++)
				{
					int roll = rand()%6 + 1;
					cout << "Yellow rolled a " << (roll);
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					if (roll == 6)
					{
						board.Move("y1", roll);
						board.DisplayBoard();
						yellowFirstTurn = false;
						break;
					}
					if (i == 2)
					{
						cout << "You cannot move any of your pieces";
						cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
						return false;
					}
				}
			}
			int roll = 0;
			do
			{
				roll = rand()%6 + 1;
				cout << "Yellow rolled a " << (roll);
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				if (board.AnyPossible(roll, "yellow") == true) // ends roll if nothing possible, will display what is possible
				{
					board.DisplayBoard();
					if (BluePlayerType == "human") HumanNumberSelection("yellow", roll);
					if (BluePlayerType == "ai") AiNumberSelection("yellow", roll);	
					board.DisplayBoard();
				}
			}	while (roll == 6);
		}
		if (PlayerNumber == 4)
		{
			if (redFirstTurn == true)
			{
				for (int i = 0; i < 3; i++)
				{
					int roll = rand()%6 + 1;
					cout << "Red rolled a " << (roll);
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					if (roll == 6)
					{
						board.Move("r1", 6);
						board.DisplayBoard();
						redFirstTurn = false;
						break;
					}
					if (i == 2)
					{
						cout << "You cannot move any of your pieces";
						cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
						return false;
					}					
				}
			}
			int roll = 0;
			do
			{
				roll = rand()%6 + 1;
				cout << "Red rolled a " << (roll);
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				if (board.AnyPossible(roll, "red") == true) // ends roll if nothing possible, will display what is possible
				{
					board.DisplayBoard();
					if (BluePlayerType == "human") HumanNumberSelection("red", roll);
					if (BluePlayerType == "ai") AiNumberSelection("red", roll);	
					board.DisplayBoard();
				}
			}	while (roll == 6);
		}												
	}
	
	string HumanNumberSelection(string playerColour, int roll)
	{
		string selectedPiece = "0";
		bool inputCorrect = false;
		while (!inputCorrect)
		{
			if (playerColour == "blue")
			{
				cout << "Which piece would you like to move? b1, b2, b3 or b4? ";
				cin >> selectedPiece;
				if (selectedPiece == "b1" || selectedPiece == "b2" || selectedPiece == "b3" || selectedPiece == "b4")
				{
					if (board.Move(selectedPiece, roll)) //if possible to roll
					{
						inputCorrect = true;
					}
					else
					{
						cout << "You cannot move that piece, please pick a piece that you can move.";
					}
				}
				else //not valid string
				{
					cout << "You did not pick a valid blue piece.";
				}
				
			}
			if (playerColour == "green")
			{
				cout << "Which piece would you like to move? g1, g2, g3 or g4? ";
				cin >> selectedPiece;
				if (selectedPiece == "g1" || selectedPiece == "g2" || selectedPiece == "g3" || selectedPiece == "g4")
				{
					if (board.Move(selectedPiece, roll))
					{
						inputCorrect = true;
					}
					else
					{
						cout << "You cannot move that piece, please pick a piece that you can move.";
					}
				}
				else
				{
					cout << "You did not pick a valid green piece";
				}
				
			}
			if (playerColour == "yellow")
			{
				cout << "Which piece would you like to move? y1, y2, y3 or y4? ";
				cin >> selectedPiece;
				if (selectedPiece == "y1" || selectedPiece == "y2" || selectedPiece == "y3" || selectedPiece == "y4")
				{
					if (board.Move(selectedPiece, roll))
					{
						inputCorrect = true;
					}
					else
					{
						cout << "You cannot move that piece, please pick a piece that you can move.";
					}
				}
				else
				{
					cout << "You did not pick a valid yellow piece";
				}
				
			}
			if (playerColour == "red")
			{
				cout << "Which piece would you like to move? r1, r2, r3 or r4? ";
				cin >> selectedPiece;
				if (selectedPiece == "r1" || selectedPiece == "r2" || selectedPiece == "r3" || selectedPiece == "r4")
				{
					if (board.Move(selectedPiece, roll))
					{
						inputCorrect = true;
					}
					else
					{
						cout << "You cannot move that piece, please pick a piece that you can move.";
					}
				}
				else
				{
					cout << "You did not pick a valid red piece";
				}		
			}							
		}
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		return selectedPiece;
	}
	
	string AiNumberSelection(string playerColour, int roll)
	{
		string selectedPiece = GetRandomDecision(playerColour);
		while ( ! board.Move(selectedPiece, roll))
		{
			selectedPiece = GetRandomDecision(playerColour);
		}
		return selectedPiece;
	}
	string GetRandomDecision(string playerColour)
	{
		switch (rand()%4 + 1)
		{
			case 1:
				if (playerColour == "blue") 
				{
					cout << "Blue picked b1";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "b1";
				}	
				if (playerColour == "green")
				{
					cout << "Green picked g1";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "g1";
				}				
				if (playerColour == "yellow") 
				{
					cout <<  "Yellow picked y1";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "y1";
				}	
				if (playerColour == "red") 
				{
					cout << "Red picked r1";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "r1";
				}		
			case 2:
				if (playerColour == "blue") 
				{
					cout <<  "Blue picked b2";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "b2";
				}	
				if (playerColour == "green")
				{
					cout <<  "Green picked g2";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "g2";
				}				
				if (playerColour == "yellow") 
				{
					cout << "Yellow picked y2";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "y2";
				}	
				if (playerColour == "red") 
				{
					cout << "Red picked r2";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "r2";
				}	
			case 3:
				if (playerColour == "blue") 
				{
					cout <<  "Blue picked b3";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "b3";
				}	
				if (playerColour == "green")
				{
					cout <<  "Green picked g3";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "g3";
				}				
				if (playerColour == "yellow") 
				{
					cout << "Yellow picked y3";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "y3";
				}	
				if (playerColour == "red") 
				{
					cout <<  "Red picked r3";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "r3";
				}	
			case 4:
				if (playerColour == "blue") 
				{
					cout <<  "Blue picked b4";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "b4";
				}	
				if (playerColour == "green")
				{
					cout <<  "Green picked g4";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "g4";
				}				
				if (playerColour == "yellow") 
				{
					cout << "Yellow picked y4";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "y4";
				}	
				if (playerColour == "red") 
				{
					cout << "Red picked r4";
					cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
					return "r4";
				}																	
		}
	}
	string GetPlayerType (string playerColour)
	{
		cout << endl;
		string playerType = "a";
		bool inputCorrect = false;
		while (!inputCorrect)
		{
			cout << "Enter the player type for " << (playerColour) << ", human or ai: ";
			cin >> playerType;
			if (playerType == "human" || playerType == "ai")
			{
				inputCorrect = true;
			}
			else
			{
				cout << "You must choose 'human' or 'ai'";
			}
		}
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		return playerType;
	}
};


#endif
