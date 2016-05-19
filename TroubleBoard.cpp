#include "TroubleBoard.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

TroubleBoard::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	out = NULL;
}

TroubleBoard::TroubleBoard()
{
	bluestart = NULL;
	tail_ = NULL;
	greenstart = NULL;
	yellowstart = NULL;
	redstart = NULL;
	size_ = 0;
}

bool TroubleBoard::empty() const
{
	if (size_ == 0) return true;
	else return false;
}

unsigned int TroubleBoard::size() const
{
	return size_;
}

void TroubleBoard::print() const
{
	//>0 Nodes
	if (bluestart != NULL)
	{	
		Node* temp;
		temp = bluestart;
		cout << (temp->value)<< ",  ";
		for (int i = 0; i < 50; i++)
		{
			temp = temp->next;
			cout << (temp->value)<< "  " ;
		}
		cout << endl;
		cout << (bluestart->value)<< ",  ";
		cout << (greenstart->value)<< ",  ";
		cout << (yellowstart->value)<< ",  ";
		cout << (redstart->value)<< ",  ";			
		temp = bluestart;
		cout << endl;		
			
		for(int i = 0; i < 7; i++)
		{
			temp = temp->next;
		}
		cout << (temp->value)<< ",  ";
		for (int i = 0; i < 4; i++)
		{
			temp = temp->out;
			cout << (temp->value)<< " " ;
		}
		cout << endl;
		temp = greenstart;	
		for(int i = 0; i < 7; i++)
		{
			temp = temp->next;
		}
		cout << (temp->value)<< ",  ";		
		for (int i = 0; i < 4; i++)
		{
			temp = temp->out;
			cout << (temp->value)<< " " ;
		}
		cout << endl;
		temp = yellowstart;
		for(int i = 0; i < 7; i++)
		{
			temp = temp->next;
		}
		cout << (temp->value)<< ",  ";				
		for (int i = 0; i < 4; i++)
		{
			temp = temp->out;
			cout << (temp->value)<< " " ;
		}
		cout << endl;
		temp = redstart;
		for(int i = 0; i < 7; i++)
		{
			temp = temp->next;
		}
		cout << (temp->value)<< ",  ";				
		for (int i = 0; i < 4; i++)
		{
			temp = temp->out;
			cout << (temp->value)<< " " ;
		}				

	}
	else
	//No Nodes
	{
		cout << "List is empty.";
	}
	cout <<"\n";
}
//for setting the main spaces
bool TroubleBoard::insert_back(DataType value)
{
	if(size_ >= CAPACITY) return false;
	Node* newBack = new Node(value);
	newBack->next = NULL;
	newBack->out = NULL;
	//No Nodes
	if (bluestart == NULL)
	{
		bluestart = newBack;
		tail_ = newBack;
		size_ = size_ + 1;
		return true;
	}
	//>1 Nodes
	else
	{	
		Node* temp;
		temp = tail_;
		tail_-> next = newBack;
		tail_ = newBack;
		newBack->next = NULL;
		tail_ -> out = NULL;
		size_ = size_ + 1;
		if (value == 24)
		{
			newBack->next = bluestart;
		}
		return true;
	}
}
//inserting start pointers
bool TroubleBoard::insert_pointers()
{
	Node* traverse;
	traverse = bluestart;
	for (int i = 0; i <= 6; i++)
	{
		traverse = traverse -> next;
	}
	greenstart = traverse;
	for (int i = 0; i <= 6; i++)
	{
		traverse = traverse -> next;
	}
	yellowstart = traverse;
	for (int i = 0; i <= 6; i++)
	{
		traverse = traverse -> next;
	}	
	redstart = traverse;

	return true;
}
//inserting game pieces
bool TroubleBoard::initialize()
{
	b1 = bluestart;
	b2 = bluestart;
	b3 = bluestart;
	b4 = bluestart;
	g1 = greenstart;
	g2 = greenstart;
	g3 = greenstart;
	g4 = greenstart;
	y1 = yellowstart;
	y2 = yellowstart;
	y3 = yellowstart;
	y4 = yellowstart;
	r1 = redstart;
	r2 = redstart;
	r3 = redstart;
	r4 = redstart;
	return true;
}
//inserting home spaces
bool TroubleBoard::insert_home(DataType value)
{
	if(size_ >= CAPACITY) return false;
	Node* newhome = new Node(value);
	newhome->next = NULL;
	newhome->out = NULL;
	
	Node* insert;
	Node* parent;
	//greenhome
	if (value == 211 || value == 212 || value == 213 || value == 214)
	{
		insert = bluestart;		
		for(int i = 0; i < 6; i++)
		{
			insert = insert->next;
		}
	}
	//yellowhome
	if (value == 311 || value == 312 || value == 313 || value == 314)
	{	
		insert = greenstart;	
		for(int i = 0; i < 6; i++)
		{
			insert = insert->next;
		}
	}
	//redhome
	if (value == 411 || value == 412 || value == 413 || value == 414)
	{	
		insert = yellowstart;	
		for(int i = 0; i < 6; i++)
		{
			insert = insert->next;
		}
	}
	//bluehome
	if (value == 111 || value == 112 || value == 113 || value == 114)
	{
		insert = redstart;		
		for(int i = 0; i < 6; i++)
		{
			insert = insert->next;
		}
	}			
				
	while (insert != NULL)
	{
		parent = insert;
		insert = insert->out;
	}
	parent->out=newhome;
	size_++;
	return true;
}
//inserting actual start space for each colour outside the board
bool TroubleBoard::insert_start(DataType value)
{
	if(size_ >= CAPACITY) return false;
	Node* newstart = new Node(value);
	newstart->next = NULL;
	newstart->out = NULL;
	//blue
	if (value == 101)
	{
		newstart->next = bluestart;
		bluestart = newstart;
	}
	//green
	if (value == 201)
	{
		newstart->next = greenstart;
		greenstart = newstart;
	}
	//yellow
	if (value == 301)
	{
		newstart->next = yellowstart;
		yellowstart = newstart;
	}
	//red
	if (value == 401)
	{
		newstart->next = redstart;
		redstart = newstart;
	}		
				
	size_++;
	return true;
}
//Checks if winning condition
bool TroubleBoard::IsWin()
{
	// Blue Win (home spaces for blue are 111, 112, 113, 114)
	if (b1->value > 110 && b2->value > 110 && b3->value > 110 && b4->value > 110)
	{
		cout << "Blue wins!";
		return true;
	}
	// Green Win (home spaces for green are 211, 212, 213, 214)	
	if (g1->value > 210 && g2->value > 210 && g3->value > 210 && g4->value > 210)
	{
		cout << "Green wins!";
		return true;
	}
	// Yellow Win (home spaces for yellow are 311, 312, 313, 314)
	if (y1->value > 310 && y2->value > 310 && y3->value > 310 && y4->value > 310)
	{
		cout << "Yellow wins!";
		return true;
	}		
	// Yellow Win (home spaces for yellow are 411, 412, 413, 414)
	if (r1->value > 410 && r2->value > 410 && r3->value > 410 && r4->value > 410)
	{
		cout << "Red wins!";
		return true;
	}
	return false;		
	
}

bool TroubleBoard::Move(string decision, int roll)
{
	if (decision == "b1")
	{
		if (b1 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b1->next == b2 || b1->next == b3 || b1->next == b4) //if piece would land on space where another piece of the same colour is occupying
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					b1 = b1->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b3 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				b1 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "b2")
	{
		if (b2 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b2->next == b1 || b2->next == b3 || b2->next == b4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					b2 = b2->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == b1 || temp == b3 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				b2 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "b3")
	{
		if (b3 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b3->next == b2 || b3->next == b1 || b3->next == b4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					b3 = b3->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b1 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				b3 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "b4")
	{
		if (b4 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b4->next == b2 || b4->next == b3 || b4->next == b1)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					b4 = b4->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b3 || temp == b1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				b4 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "g1")
	{
		if (g1 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g1->next == g2 || g1->next == g3 || g1->next == g4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					g1 = g1->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g3 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				g1 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "g2")
	{
		if (g2 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g2->next == g1 || g2->next == g3 || g2->next == g4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					g2 = g2->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == g1 || temp == g3 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				g2 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "g3")
	{
		if (g3 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g3->next == g2 || g3->next == g1 || g3->next == g4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					g3 = g3->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g1 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				g3 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "g4")
	{
		if (g4 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g4->next == g2 || g4->next == g3 || g4->next == g1)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					g4 = g4->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g3 || temp == g1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				g4 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "y1")
	{
		if (y1 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y1->next == y2 || y1->next == y3 || y1->next == y4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					y1 = y1->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y3 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				y1 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "y2")
	{
		if (y2 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y2->next == y1 || y2->next == y3 || y2->next == y4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					y2 = y2->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == y1 || temp == y3 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				y2 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "y3")
	{
		if (y3 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y3->next == y2 || y3->next == y1 || y3->next == y4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					y3 = y3->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y1 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				y3 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "y4")
	{
		if (y4 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y4->next == y2 || y4->next == y3 || y4->next == y1)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					y4 = y4->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y3 || temp == y1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				y4 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "r1")
	{
		if (r1 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r1->next == r2 || r1->next == r3 || r1->next == r4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					r1 = r1->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r3 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				r1 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "r2")
	{
		if (r2 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r2->next == r1 || r2->next == r3 || r2->next == r4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					r2 = r2->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == r1 || temp == r3 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				r2 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "r3")
	{
		if (r3 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r3->next == r2 || r3->next == r1 || r3->next == r4)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					r3 = r3->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r1 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				r3 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}
	if (decision == "r4")
	{
		if (r4 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r4->next == r2 || r4->next == r3 || r4->next == r1)
				{
					cout << "You cannot move " << (decision) << " out of the start position because one of your other pieces is occupying the space" << endl;
					return false;
				}
				else
				{
					r4 = r4->next;
					SendToStart(decision);
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << " " << " out of the start position because you did not roll a 6" << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << " " << (roll) << " spaces because there is not enough spaces to travel" << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r3 || temp == r1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << " " << (roll) << " spaces because another one of your pieces is occupying that space" << endl;
				return false;
			}
			else
			{
				r4 = temp;
				SendToStart(decision);
				return true;
			}	
		}
	}																						
}

bool TroubleBoard::SendToStart(string gamePiece) //this function will detect if two pieces share the same space
{
	if(gamePiece == "b1") //b1
	{
		if (b1 == g1) g1 = greenstart;
		if (b1 == g2) g2 = greenstart;
		if (b1 == g3) g3 = greenstart;
		if (b1 == g4) g4 = greenstart;
		if (b1 == y1) y1 = yellowstart;
		if (b1 == y2) y2 = yellowstart;
		if (b1 == y3) y3 = yellowstart;
		if (b1 == y4) y4 = yellowstart;
		if (b1 == r1) r1 = redstart;
		if (b1 == r2) r2 = redstart;
		if (b1 == r3) r3 = redstart;
		if (b1 == r4) r4 = redstart;
		return true;	
	}
	if(gamePiece == "b2") //b2
	{
		if (b2 == g1) g1 = greenstart;
		if (b2 == g2) g2 = greenstart;
		if (b2 == g3) g3 = greenstart;
		if (b2 == g4) g4 = greenstart;
		if (b2 == y1) y1 = yellowstart;
		if (b2 == y2) y2 = yellowstart;
		if (b2 == y3) y3 = yellowstart;
		if (b2 == y4) y4 = yellowstart;
		if (b2 == r1) r1 = redstart;
		if (b2 == r2) r2 = redstart;
		if (b2 == r3) r3 = redstart;
		if (b2 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "b3") //b3
	{
		if (b3 == g1) g1 = greenstart;
		if (b3 == g2) g2 = greenstart;
		if (b3 == g3) g3 = greenstart;
		if (b3 == g4) g4 = greenstart;
		if (b3 == y1) y1 = yellowstart;
		if (b3 == y2) y2 = yellowstart;
		if (b3 == y3) y3 = yellowstart;
		if (b3 == y4) y4 = yellowstart;
		if (b3 == r1) r1 = redstart;
		if (b3 == r2) r2 = redstart;
		if (b3 == r3) r3 = redstart;
		if (b3 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "b4") //b4
	{
		if (b4 == g1) g1 = greenstart;
		if (b4 == g2) g2 = greenstart;
		if (b4 == g3) g3 = greenstart;
		if (b4 == g4) g4 = greenstart;
		if (b4 == y1) y1 = yellowstart;
		if (b4 == y2) y2 = yellowstart;
		if (b4 == y3) y3 = yellowstart;
		if (b4 == y4) y4 = yellowstart;
		if (b4 == r1) r1 = redstart;
		if (b4 == r2) r2 = redstart;
		if (b4 == r3) r3 = redstart;
		if (b4 == r4) r4 = redstart;
		return true;
	}	
	if(gamePiece == "g1") //g1
	{
		if (g1 == b1) b1 = bluestart;
		if (g1 == b2) b2 = bluestart;
		if (g1 == b3) b3 = bluestart;
		if (g1 == b4) b4 = bluestart;
		if (g1 == y1) y1 = yellowstart;
		if (g1 == y2) y2 = yellowstart;
		if (g1 == y3) y3 = yellowstart;
		if (g1 == y4) y4 = yellowstart;
		if (g1 == r1) r1 = redstart;
		if (g1 == r2) r2 = redstart;
		if (g1 == r3) r3 = redstart;
		if (g1 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "g2") //g2
	{
		if (g2 == b1) b1 = bluestart;
		if (g2 == b2) b2 = bluestart;
		if (g2 == b3) b3 = bluestart;
		if (g2 == b4) b4 = bluestart;
		if (g2 == y1) y1 = yellowstart;
		if (g2 == y2) y2 = yellowstart;
		if (g2 == y3) y3 = yellowstart;
		if (g2 == y4) y4 = yellowstart;
		if (g2 == r1) r1 = redstart;
		if (g2 == r2) r2 = redstart;
		if (g2 == r3) r3 = redstart;
		if (g2 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "g3")
	{
		if (g2 == b1) b1 = bluestart;
		if (g2 == b2) b2 = bluestart;
		if (g2 == b3) b3 = bluestart;
		if (g2 == b4) b4 = bluestart;
		if (g2 == y1) y1 = yellowstart;
		if (g2 == y2) y2 = yellowstart;
		if (g2 == y3) y3 = yellowstart;
		if (g2 == y4) y4 = yellowstart;
		if (g2 == r1) r1 = redstart;
		if (g2 == r2) r2 = redstart;
		if (g2 == r3) r3 = redstart;
		if (g2 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "g4")
	{
		if (g4 == b1) b1 = bluestart;
		if (g4 == b2) b2 = bluestart;
		if (g4 == b3) b3 = bluestart;
		if (g4 == b4) b4 = bluestart;
		if (g4 == y1) y1 = yellowstart;
		if (g4 == y2) y2 = yellowstart;
		if (g4 == y3) y3 = yellowstart;
		if (g4 == y4) y4 = yellowstart;
		if (g4 == r1) r1 = redstart;
		if (g4 == r2) r2 = redstart;
		if (g4 == r3) r3 = redstart;
		if (g4 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "y1")
	{
		if (y1 == b1) b1 = bluestart;
		if (y1 == b2) b2 = bluestart;
		if (y1 == b3) b3 = bluestart;
		if (y1 == b4) b4 = bluestart;
		if (y1 == g1) g1 = greenstart;
		if (y1 == g2) g2 = greenstart;
		if (y1 == g3) g3 = greenstart;
		if (y1 == g4) g4 = greenstart;
		if (y1 == r1) r1 = redstart;
		if (y1 == r2) r2 = redstart;
		if (y1 == r3) r3 = redstart;
		if (y1 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "y2")
	{
		if (y2 == b1) b1 = bluestart;
		if (y2 == b2) b2 = bluestart;
		if (y2 == b3) b3 = bluestart;
		if (y2 == b4) b4 = bluestart;
		if (y2 == g1) g1 = greenstart;
		if (y2 == g2) g2 = greenstart;
		if (y2 == g3) g3 = greenstart;
		if (y2 == g4) g4 = greenstart;
		if (y2 == r1) r1 = redstart;
		if (y2 == r2) r2 = redstart;
		if (y2 == r3) r3 = redstart;
		if (y2 == r4) r4 = redstart;
		return true;
	}
	if(gamePiece == "y3")
	{
		if (y3 == b1) b1 = bluestart;
		if (y3 == b2) b2 = bluestart;
		if (y3 == b3) b3 = bluestart;
		if (y3 == b4) b4 = bluestart;
		if (y3 == g1) g1 = greenstart;
		if (y3 == g2) g2 = greenstart;
		if (y3 == g3) g3 = greenstart;
		if (y3 == g4) g4 = greenstart;
		if (y3 == r1) r1 = redstart;
		if (y3 == r2) r2 = redstart;
		if (y3 == r3) r3 = redstart;
		if (y3 == r4) r4 = redstart;
		return true;
	}	
	if(gamePiece == "y4")
	{
		if (y4 == b1) b1 = bluestart;
		if (y4 == b2) b2 = bluestart;
		if (y4 == b3) b3 = bluestart;
		if (y4 == b4) b4 = bluestart;
		if (y4 == g1) g1 = greenstart;
		if (y4 == g2) g2 = greenstart;
		if (y4 == g3) g3 = greenstart;
		if (y4 == g4) g4 = greenstart;
		if (y4 == r1) r1 = redstart;
		if (y4 == r2) r2 = redstart;
		if (y4 == r3) r3 = redstart;
		if (y4 == r4) r4 = redstart;
		return true;
	}								
	if(gamePiece == "r1")
	{
		if (r1 == b1) b1 = bluestart;
		if (r1 == b2) b2 = bluestart;
		if (r1 == b3) b3 = bluestart;
		if (r1 == b4) b4 = bluestart;
		if (r1 == g1) g1 = greenstart;
		if (r1 == g2) g2 = greenstart;
		if (r1 == g3) g3 = greenstart;
		if (r1 == g4) g4 = greenstart;
		if (r1 == y1) y1 = yellowstart;
		if (r1 == y2) y2 = yellowstart;
		if (r1 == y3) y3 = yellowstart;
		if (r1 == y4) y4 = yellowstart;
		return true;
	}
	if(gamePiece == "r2")
	{
		if (r2 == b1) b1 = bluestart;
		if (r2 == b2) b2 = bluestart;
		if (r2 == b3) b3 = bluestart;
		if (r2 == b4) b4 = bluestart;
		if (r2 == g1) g1 = greenstart;
		if (r2 == g2) g2 = greenstart;
		if (r2 == g3) g3 = greenstart;
		if (r2 == g4) g4 = greenstart;
		if (r2 == y1) y1 = yellowstart;
		if (r2 == y2) y2 = yellowstart;
		if (r2 == y3) y3 = yellowstart;
		if (r2 == y4) y4 = yellowstart;
		return true;
	}
	if(gamePiece == "r3")
	{
		if (r3 == b1) b1 = bluestart;
		if (r3 == b2) b2 = bluestart;
		if (r3 == b3) b3 = bluestart;
		if (r3 == b4) b4 = bluestart;
		if (r3 == g1) g1 = greenstart;
		if (r3 == g2) g2 = greenstart;
		if (r3 == g3) g3 = greenstart;
		if (r3 == g4) g4 = greenstart;
		if (r3 == y1) y1 = yellowstart;
		if (r3 == y2) y2 = yellowstart;
		if (r3 == y3) y3 = yellowstart;
		if (r3 == y4) y4 = yellowstart;
		return true;
	}
	if(gamePiece == "r4")
	{
		if (r4 == b1) b1 = bluestart;
		if (r4 == b2) b2 = bluestart;
		if (r4 == b3) b3 = bluestart;
		if (r4 == b4) b4 = bluestart;
		if (r4 == g1) g1 = greenstart;
		if (r4 == g2) g2 = greenstart;
		if (r4 == g3) g3 = greenstart;
		if (r4 == g4) g4 = greenstart;
		if (r4 == y1) y1 = yellowstart;
		if (r4 == y2) y2 = yellowstart;
		if (r4 == y3) y3 = yellowstart;
		if (r4 == y4) y4 = yellowstart;
		return true;
	}				
}

bool TroubleBoard::IsPossible(string decision, int roll) //helper function to AnyPossible, similar to Move except only check which is possible
{
	if (decision == "b1")
	{
		if (b1 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b1->next == b2 || b1->next == b3 || b1->next == b4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b3 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "b2")
	{
		if (b2 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b2->next == b1 || b2->next == b3 || b2->next == b4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == b1 || temp == b3 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "b3")
	{
		if (b3 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b3->next == b2 || b3->next == b1 || b3->next == b4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b1 || temp == b4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "b4")
	{
		if (b4 == bluestart)
		{
			if (roll == 6) //MoveToStart
			{
				if (b4->next == b2 || b4->next == b3 || b4->next == b1)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = b4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 24) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == b2 || temp == b3 || temp == b1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "g1")
	{
		if (g1 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g1->next == g2 || g1->next == g3 || g1->next == g4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g3 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "g2")
	{
		if (g2 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g2->next == g1 || g2->next == g3 || g2->next == g4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == g1 || temp == g3 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "g3")
	{
		if (g3 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g3->next == g2 || g3->next == g1 || g3->next == g4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g1 || temp == g4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision);
				return true;
			}	
		}
	}
	if (decision == "g4")
	{
		if (g4 == greenstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (g4->next == g2 || g4->next == g3 || g4->next == g1)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = g4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 6) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == g2 || temp == g3 || temp == g1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "y1")
	{
		if (y1 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y1->next == y2 || y1->next == y3 || y1->next == y4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y3 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "y2")
	{
		if (y2 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y2->next == y1 || y2->next == y3 || y2->next == y4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == y1 || temp == y3 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "y3")
	{
		if (y3 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y3->next == y2 || y3->next == y1 || y3->next == y4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y1 || temp == y4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision);
				return true;
			}	
		}
	}
	if (decision == "y4")
	{
		if (y4 == yellowstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (y4->next == y2 || y4->next == y3 || y4->next == y1)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = y4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 12) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == y2 || temp == y3 || temp == y1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "r1")
	{
		if (r1 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r1->next == r2 || r1->next == r3 || r1->next == r4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r1;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r3 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "r2")
	{
		if (r2 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r2->next == r1 || r2->next == r3 || r2->next == r4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r2;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == r1 || temp == r3 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "r3")
	{
		if (r3 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r3->next == r2 || r3->next == r1 || r3->next == r4)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r3;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r1 || temp == r4) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}
	if (decision == "r4")
	{
		if (r4 == redstart)
		{
			if (roll == 6) //MoveToStart
			{
				if (r4->next == r2 || r4->next == r3 || r4->next == r1)
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
				else
				{
					cout << "You can move " << (decision) << endl;
					return true;
				}	
			}	
			else
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
		}
		else
		{
			Node* temp;
			temp = r4;
			bool goHome = false; //temp will go towards home if true
			for (int i = 0; i < roll; i++)
			{
				if (temp->value == 18) //last space before going home, tells it to go to home space
				{
					goHome = true;
				}
				if (!goHome)
				{
					temp = temp->next;
				}
				if (goHome)
				{
					temp = temp->out;
				}
				if (temp == NULL) //if run out of spaces
				{
					cout << "You cannot move " << (decision) << endl;
					return false;
				}
			}
			if (temp == r2 || temp == r3 || temp == r1) //if space is occupied
			{
				cout << "You cannot move " << (decision) << endl;
				return false;
			}
			else
			{
				cout << "You can move " << (decision) << endl;
				return true;
			}	
		}
	}																						
}

bool TroubleBoard::AnyPossible(int roll, string playerColour) //Determines if any roll is possible
{
	if (playerColour == "blue")
	{
		if (IsPossible("b1", roll) == false & IsPossible("b2", roll) == false & IsPossible("b3", roll) == false & IsPossible("b4", roll) == false)
		{
			cout << "You cannot move any of your pieces with " << (roll);
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');	
			return false;
		}
		else
		{
			return true;
		}
	}
	if (playerColour == "green")
	{
		if (IsPossible("g1", roll) == false & IsPossible("g2", roll) == false & IsPossible("g3", roll) == false & IsPossible("g4", roll) == false)
		{
			cout << "You cannot move any of your pieces with " << (roll);
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');			
			return false;
		}
		else
		{
			return true;
		}
	}	
	if (playerColour == "yellow")
	{
		if (IsPossible("y1", roll) == false & IsPossible("y2", roll) == false & IsPossible("y3", roll) == false & IsPossible("y4", roll) & false)
		{
			cout << "You cannot move any of your pieces with " << (roll);	
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			return false;
		}
		else
		{
			return true;
		}
	}
	if (playerColour == "red")
	{
		if (IsPossible("r1", roll) == false & IsPossible("r2", roll) == false & IsPossible("r3", roll) == false & IsPossible("r4", roll) == false)
		{
			cout << "You cannot move any of your pieces with " << (roll);	
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');		
			return false;
		}
		else
		{
			return true;
		}
	}	
	
}
bool TroubleBoard::DisplayBoard()
{
	cout << "                GR";
	cout << endl;
	//greenstart
	if (g1 == greenstart && g2 != greenstart && g3 != greenstart && g4 != greenstart)
	{
		cout << "                g1";
		cout << endl;
	}
	if (g1 == greenstart && g2 == greenstart && g3 != greenstart && g4 != greenstart)
	{
		cout << "              g2g1";
		cout << endl;
	}
	if (g1 == greenstart && g2 != greenstart && g3 == greenstart && g4 != greenstart)
	{
		cout << "              g3g1";
		cout << endl;
	}
	if (g1 == greenstart && g2 != greenstart && g3 != greenstart && g4 == greenstart)
	{
		cout << "              g4g1";
		cout << endl;
	}	
	if (g1 == greenstart && g2 == greenstart && g3 == greenstart && g4 != greenstart)
	{
		cout << "            g3g2g1";
		cout << endl;
	}
	if (g1 == greenstart && g2 != greenstart && g3 == greenstart && g4 == greenstart)
	{
		cout << "            g4g3g1";
		cout << endl;
	}
	if (g1 == greenstart && g2 == greenstart && g3 != greenstart && g4 == greenstart)
	{
		cout << "            g4g2g1";
		cout << endl;
	}			
	if (g1 == greenstart && g2 == greenstart && g3 == greenstart && g4 == greenstart)
	{
		cout << "          g4g3g2g1";
		cout << endl;
	}
	if (g1 != greenstart && g2 == greenstart && g3 != greenstart && g4 != greenstart)
	{
		cout << "                g2";
		cout << endl;
	}	
	if (g1 != greenstart && g2 == greenstart && g3 == greenstart && g4 != greenstart)
	{
		cout << "              g3g2";
		cout << endl;
	}
	if (g1 != greenstart && g2 == greenstart && g3 != greenstart && g4 == greenstart)
	{
		cout << "              g4g2";
		cout << endl;
	}	
	if (g1 != greenstart && g2 == greenstart && g3 == greenstart && g4 == greenstart)
	{
		cout << "            g4g3g2";
		cout << endl;
	}
	if (g1 != greenstart && g2 != greenstart && g3 == greenstart && g4 != greenstart)
	{
		cout << "                g3";
		cout << endl;
	}
	if (g1 != greenstart && g2 != greenstart && g3 == greenstart && g4 == greenstart)
	{
		cout << "              g4g3";
		cout << endl;
	}
	if (g1 != greenstart && g2 != greenstart && g3 != greenstart && g4 == greenstart)
	{
		cout << "                g4";
		cout << endl;
	}
	if (g1 != greenstart && g2 != greenstart && g3 != greenstart && g4 != greenstart)
	{
		cout << "                  ";
		cout << endl;
	}	
	//space 200
	if (b1->value == 200)
	{
		cout << "                b1";
		cout << endl; 
	}
	else if (b2->value == 200)
	{
		cout << "                b2";
		cout << endl; 
	}
	else if (b3->value == 200)
	{
		cout << "                b3";
		cout << endl; 
	}
	else if (b4->value == 200)
	{
		cout << "                b4";
		cout << endl; 
	}
	else if (g1->value == 200)
	{
		cout << "                g1";
		cout << endl; 
	}
	else if (g2->value == 200)
	{
		cout << "                g2";
		cout << endl; 
	}
	else if (g3->value == 200)
	{
		cout << "                g3";
		cout << endl; 
	}
	else if (g4->value == 200)
	{
		cout << "                g4";
		cout << endl;
	}
	else if (y1->value == 200)
	{
		cout << "                y1";
		cout << endl; 
	}
	else if (y2->value == 200)
	{
		cout << "                y2";
		cout << endl; 
	}
	else if (y3->value == 200)
	{
		cout << "                y3";
		cout << endl; 
	}
	else if (y4->value == 200)
	{
		cout << "                y4";
		cout << endl; 
	}
	else if (r1->value == 200)
	{
		cout << "                r1";
		cout << endl; 
	}
	else if (r2->value == 200)
	{
		cout << "                r2";
		cout << endl;
	}
	else if (r3->value == 200)
	{
		cout << "                r3";
		cout << endl; 
	}
	else if (r4->value == 200)
	{
		cout << "                r4";
		cout << endl; 
	}
	else
	{
		cout << "                GS";
		cout << endl; 		
	}
	//space 6
	if (b1->value == 6)
	{
		cout << "              b1";
	}
	else if (b2->value == 6)
	{
		cout << "              b2";
	}
	else if (b3->value == 6)
	{
		cout << "              b3"; 
	}
	else if (b4->value == 6)
	{
		cout << "              b4";
	}
	else if (g1->value == 6)
	{
		cout << "              g1";
	}
	else if (g2->value == 6)
	{
		cout << "              g2";
	}
	else if (g3->value == 6)
	{
		cout << "              g3";
	}
	else if (g4->value == 6)
	{
		cout << "              g4";
	}
	else if (y1->value == 6)
	{
		cout << "              y1";
	}
	else if (y2->value == 6)
	{
		cout << "              y2";
	}
	else if (y3->value == 6)
	{
		cout << "              y3"; 
	}
	else if (y4->value == 6)
	{
		cout << "              y4";
	}
	else if (r1->value == 6)
	{
		cout << "              r1";
	}
	else if (r2->value == 6)
	{
		cout << "              r2";
	}
	else if (r3->value == 6)
	{
		cout << "              r3";
	}
	else if (r4->value == 6)
	{
		cout << "              r4";
	}
	else
	{
		cout << "              06";		
	}	
	//space 7
	if (b1->value == 7)
	{
		cout << "  b1";
		cout << endl; 
	}
	else if (b2->value == 7)
	{
		cout << "  b2";
		cout << endl; 
	}
	else if (b3->value == 7)
	{
		cout << "  b3";
		cout << endl;
	}
	else if (b4->value == 7)
	{
		cout << "  b4";
		cout << endl; 
	}
	else if (g1->value == 7)
	{
		cout << "  g1";
		cout << endl;
	}
	else if (g2->value == 7)
	{
		cout << "  g2";
		cout << endl; 
	}
	else if (g3->value == 7)
	{
		cout << "  g3";
		cout << endl; 
	}
	else if (g4->value == 7)
	{
		cout << "  g4";
		cout << endl; 
	}
	else if (y1->value == 7)
	{
		cout << "  y1";
		cout << endl;
	}
	else if (y2->value == 7)
	{
		cout << "  y2";
		cout << endl; 
	}
	else if (y3->value == 7)
	{
		cout << "  y3";
		cout << endl;
	}
	else if (y4->value == 7)
	{
		cout << "  y4";
		cout << endl;
	}
	else if (r1->value == 7)
	{
		cout << "  r1";
		cout << endl; 
	}
	else if (r2->value == 7)
	{
		cout << "  r2";
		cout << endl; 
	}
	else if (r3->value == 7)
	{
		cout << "  r3";
		cout << endl; 
	}
	else if (r4->value == 7)
	{
		cout << "  r4";
		cout << endl; 
	}
	else
	{
		cout << "  07";
		cout << endl; 		
	}
	//space 5																		
	if (b1->value == 5)
	{
		cout << "            b1";
	}
	else if (b2->value == 5)
	{
		cout << "            b2";
	}
	else if (b3->value == 5)
	{
		cout << "            b3"; 
	}
	else if (b4->value == 5)
	{
		cout << "            b4";
	}
	else if (g1->value == 5)
	{
		cout << "            g1";
	}
	else if (g2->value == 5)
	{
		cout << "            g2";
	}
	else if (g3->value == 5)
	{
		cout << "            g3";
	}
	else if (g4->value == 5)
	{
		cout << "            g4";
	}
	else if (y1->value == 5)
	{
		cout << "            y1";
	}
	else if (y2->value == 5)
	{
		cout << "            y2";
	}
	else if (y3->value == 5)
	{
		cout << "            y3"; 
	}
	else if (y4->value == 5)
	{
		cout << "            y4";
	}
	else if (r1->value == 5)
	{
		cout << "            r1";
	}
	else if (r2->value == 5)
	{
		cout << "            r2";
	}
	else if (r3->value == 5)
	{
		cout << "            r3";
	}
	else if (r4->value == 5)
	{
		cout << "            r4";
	}
	else
	{
		cout << "            05";		
	}	
	//space 201
	if (g1->value == 211)
	{
		cout << "  g1"; 
	}
	else if (g2->value == 211)
	{
		cout << "  g2";
	}
	else if (g3->value == 211)
	{
		cout << "  g3";
	}
	else if (g4->value == 211)
	{
		cout << "  g4";
	}
	else
	{
		cout << "  G1";		
	}
	//space 22
	if (b1->value == 8)
	{
		cout << "  b1";
		cout << endl; 
	}
	else if (b2->value == 8)
	{
		cout << "  b2";
		cout << endl; 
	}
	else if (b3->value == 8)
	{
		cout << "  b3";
		cout << endl; 
	}
	else if (b4->value == 8)
	{
		cout << "  b4";
		cout << endl;
	}
	else if (g1->value == 8)
	{
		cout << "  g1";
		cout << endl;
	}
	else if (g2->value == 8)
	{
		cout << "  g2";
		cout << endl; 
	}
	else if (g3->value == 8)
	{
		cout << "  g3";
		cout << endl;
	}
	else if (g4->value == 8)
	{
		cout << "  g4";
		cout << endl; 
	}
	else if (y1->value == 8)
	{
		cout << "  y1";
		cout << endl; 
	}
	else if (y2->value == 8)
	{
		cout << "  y2";
		cout << endl; 
	}
	else if (y3->value == 8)
	{
		cout << "  y3";
		cout << endl; 
	}
	else if (y4->value == 8)
	{
		cout << "  y4";
		cout << endl; 
	}
	else if (r1->value == 8)
	{
		cout << "  r1";
		cout << endl; 
	}
	else if (r2->value == 8)
	{
		cout << "  r2";
		cout << endl; 
	}
	else if (r3->value == 8)
	{
		cout << "  r3";
		cout << endl; 
	}
	else if (r4->value == 8)
	{
		cout << "  r4";
		cout << endl;
	}
	else
	{
		cout << "  08";
		cout << endl; 		
	}
	//space 4																		
	if (b1->value == 4)
	{
		cout << "          b1";
	}
	else if (b2->value == 4)
	{
		cout << "          b2";
	}
	else if (b3->value == 4)
	{
		cout << "          b3"; 
	}
	else if (b4->value == 4)
	{
		cout << "          b4";
	}
	else if (g1->value == 4)
	{
		cout << "          g1";
	}
	else if (g2->value == 4)
	{
		cout << "          g2";
	}
	else if (g3->value == 4)
	{
		cout << "          g3";
	}
	else if (g4->value == 4)
	{
		cout << "          g4";
	}
	else if (y1->value == 4)
	{
		cout << "          y1";
	}
	else if (y2->value == 4)
	{
		cout << "          y2";
	}
	else if (y3->value == 4)
	{
		cout << "          y3"; 
	}
	else if (y4->value == 4)
	{
		cout << "          y4";
	}
	else if (r1->value == 4)
	{
		cout << "          r1";
	}
	else if (r2->value == 4)
	{
		cout << "          r2";
	}
	else if (r3->value == 4)
	{
		cout << "          r3";
	}
	else if (r4->value == 4)
	{
		cout << "          r4";
	}
	else
	{
		cout << "          04";		
	}	
	//space 202
	if (g1->value == 212)
	{
		cout << "    g1"; 
	}
	else if (g2->value == 212)
	{
		cout << "    g2";
	}
	else if (g3->value == 212)
	{
		cout << "    g3";
	}
	else if (g4->value == 212)
	{
		cout << "    g4";
	}
	else
	{
		cout << "    G2";		
	}
	//space 9
	if (b1->value == 9)
	{
		cout << "    b1";
		cout << endl;
	}
	else if (b2->value == 9)
	{
		cout << "    b2";
		cout << endl;
	}
	else if (b3->value == 9)
	{
		cout << "    b3";
		cout << endl;
	}
	else if (b4->value == 9)
	{
		cout << "    b4";
		cout << endl; 
	}
	else if (g1->value == 9)
	{
		cout << "    g1";
		cout << endl; 
	}
	else if (g2->value == 9)
	{
		cout << "    g2";
		cout << endl; 
	}
	else if (g3->value == 9)
	{
		cout << "    g3";
		cout << endl; 
	}
	else if (g4->value == 9)
	{
		cout << "    g4";
		cout << endl;
	}
	else if (y1->value == 9)
	{
		cout << "    y1";
		cout << endl;
	}
	else if (y2->value == 9)
	{
		cout << "    y2";
		cout << endl; 
	}
	else if (y3->value == 9)
	{
		cout << "    y3";
		cout << endl; 
	}
	else if (y4->value == 9)
	{
		cout << "   y4";
		cout << endl;
	}
	else if (r1->value == 9)
	{
		cout << "    r1";
		cout << endl; 
	}
	else if (r2->value == 9)
	{
		cout << "    r2";
		cout << endl; 
	}
	else if (r3->value == 9)
	{
		cout << "    r3";
		cout << endl; 
	}
	else if (r4->value == 9)
	{
		cout << "    r4";
		cout << endl; 
	}
	else
	{
		cout << "    09";
		cout << endl; 		
	}
	//space 3																		
	if (b1->value == 3)
	{
		cout << "        b1";
	}
	else if (b2->value == 3)
	{
		cout << "        b2";
	}
	else if (b3->value == 3)
	{
		cout << "        b3"; 
	}
	else if (b4->value == 3)
	{
		cout << "        b4";
	}
	else if (g1->value == 3)
	{
		cout << "        g1";
	}
	else if (g2->value == 3)
	{
		cout << "        g2";
	}
	else if (g3->value == 3)
	{
		cout << "        g3";
	}
	else if (g4->value == 3)
	{
		cout << "        g4";
	}
	else if (y1->value == 3)
	{
		cout << "        y1";
	}
	else if (y2->value == 3)
	{
		cout << "        y2";
	}
	else if (y3->value == 3)
	{
		cout << "        y3"; 
	}
	else if (y4->value == 3)
	{
		cout << "        y4";
	}
	else if (r1->value == 3)
	{
		cout << "        r1";
	}
	else if (r2->value == 3)
	{
		cout << "        r2";
	}
	else if (r3->value == 3)
	{
		cout << "        r3";
	}
	else if (r4->value == 3)
	{
		cout << "        r4";
	}
	else
	{
		cout << "        03";		
	}	
	//space 203
	if (g1->value == 213)
	{
		cout << "      g1"; 
	}
	else if (g2->value == 213)
	{
		cout << "      g2";
	}
	else if (g3->value == 213)
	{
		cout << "      g3";
	}
	else if (g4->value == 213)
	{
		cout << "      g4";
	}
	else
	{
		cout << "      G3";		
	}
	//space 10
	if (b1->value == 10)
	{
		cout << "      b1";
	}
	else if (b2->value == 10)
	{
		cout << "      b2";
	}
	else if (b3->value == 10)
	{
		cout << "      b3";
	}
	else if (b4->value == 10)
	{
		cout << "      b4";
	}
	else if (g1->value == 10)
	{
		cout << "      g1";
	}
	else if (g2->value == 10)
	{
		cout << "      g2";
	}
	else if (g3->value == 10)
	{
		cout << "      g3";
	}
	else if (g4->value == 10)
	{
		cout << "      g4";
	}
	else if (y1->value == 10)
	{
		cout << "      y1";
	}
	else if (y2->value == 10)
	{
		cout << "      y2";
	}
	else if (y3->value == 10)
	{
		cout << "      y3"; 
	}
	else if (y4->value == 10)
	{
		cout << "     y4";
	}
	else if (r1->value == 10)
	{
		cout << "      r1";
	}
	else if (r2->value == 10)
	{
		cout << "      r2";
	}
	else if (r3->value == 10)
	{
		cout << "      r3";
	}
	else if (r4->value == 10)
	{
		cout << "      r4";
	}
	else
	{
		cout << "      10";		
	}
	cout << "      ";
	if (y3 == yellowstart)
	{
		cout << "y3";		
	}
	else
	{
		cout << "  ";
	}
	cout << endl;								
	//space 2																		
	if (b1->value == 2)
	{
		cout << "      b1";
	}
	else if (b2->value == 2)
	{
		cout << "      b2";
	}
	else if (b3->value == 2)
	{
		cout << "      b3"; 
	}
	else if (b4->value == 2)
	{
		cout << "      b4";
	}
	else if (g1->value == 2)
	{
		cout << "      g1";
	}
	else if (g2->value == 2)
	{
		cout << "      g2";
	}
	else if (g3->value == 2)
	{
		cout << "      g3";
	}
	else if (g4->value == 2)
	{
		cout << "      g4";
	}
	else if (y1->value == 2)
	{
		cout << "      y1";
	}
	else if (y2->value == 2)
	{
		cout << "      y2";
	}
	else if (y3->value == 2)
	{
		cout << "      y3"; 
	}
	else if (y4->value == 2)
	{
		cout << "      y4";
	}
	else if (r1->value == 2)
	{
		cout << "      r1";
	}
	else if (r2->value == 2)
	{
		cout << "      r2";
	}
	else if (r3->value == 2)
	{
		cout << "      r3";
	}
	else if (r4->value == 2)
	{
		cout << "      r4";
	}
	else
	{
		cout << "      02";		
	}	
	//space 204
	if (g1->value == 214)
	{
		cout << "        g1"; 
	}
	else if (g2->value == 214)
	{
		cout << "        g2";
	}
	else if (g3->value == 214)
	{
		cout << "        g3";
	}
	else if (g4->value == 214)
	{
		cout << "        g4";
	}
	else
	{
		cout << "        G4";		
	}
	//space 11
	if (b1->value == 11)
	{
		cout << "        b1";
	}
	else if (b2->value == 11)
	{
		cout << "        b2";
	}
	else if (b3->value == 11)
	{
		cout << "        b3";
	}
	else if (b4->value == 11)
	{
		cout << "        b4";
	}
	else if (g1->value == 11)
	{
		cout << "        g1"; 
	}
	else if (g2->value == 11)
	{
		cout << "        g2";
	}
	else if (g3->value == 11)
	{
		cout << "        g3";
	}
	else if (g4->value == 11)
	{
		cout << "        g4";
	}
	else if (y1->value == 11)
	{
		cout << "        y1";
	}
	else if (y2->value == 11)
	{
		cout << "        y2";
	}
	else if (y3->value == 11)
	{
		cout << "        y3";
	}
	else if (y4->value == 11)
	{
		cout << "        y4";
	}
	else if (r1->value == 11)
	{
		cout << "        r1"; 
	}
	else if (r2->value == 11)
	{
		cout << "        r2";
	}
	else if (r3->value == 11)
	{
		cout << "        r3";
	}
	else if (r4->value == 11)
	{
		cout << "        r4"; 
	}
	else
	{
		cout << "        11";		
	}
	cout << "    ";
	if (y3 == yellowstart)
	{
		cout << "y3";		
	}
	else
	{
		cout << "  ";
	}
	cout << endl;	
	cout << "BL";
	//space 1																		
	if (b1->value == 1)
	{
		cout << "  b1";
	}
	else if (b2->value == 1)
	{
		cout << "  b2";
	}
	else if (b3->value == 1)
	{
		cout << "  b3"; 
	}
	else if (b4->value == 1)
	{
		cout << "  b4";
	}
	else if (g1->value == 1)
	{
		cout << "  g1";
	}
	else if (g2->value == 1)
	{
		cout << "  g2";
	}
	else if (g3->value == 1)
	{
		cout << "  g3";
	}
	else if (g4->value == 1)
	{
		cout << "  g4";
	}
	else if (y1->value == 1)
	{
		cout << "  y1";
	}
	else if (y2->value == 1)
	{
		cout << "  y2";
	}
	else if (y3->value == 1)
	{
		cout << "  y3"; 
	}
	else if (y4->value == 1)
	{
		cout << "  y4";
	}
	else if (r1->value == 1)
	{
		cout << "  r1";
	}
	else if (r2->value == 1)
	{
		cout << "  r2";
	}
	else if (r3->value == 1)
	{
		cout << "  r3";
	}
	else if (r4->value == 1)
	{
		cout << "  r4";
	}
	else
	{
		cout << "  01";		
	}	
	//space 12
	cout << "            ";
	if (b1->value == 12)
	{
		cout << "          b1";
	}
	else if (b2->value == 12)
	{
		cout << "          b2"; 
	}
	else if (b3->value == 12)
	{
		cout << "          b3"; 
	}
	else if (b4->value == 12)
	{
		cout << "          b4"; 
	}
	else if (g1->value == 12)
	{
		cout << "          g1"; 
	}
	else if (g2->value == 12)
	{
		cout << "          g2"; 
	}
	else if (g3->value == 12)
	{
		cout << "          g3";
	}
	else if (g4->value == 12)
	{
		cout << "          g4"; 
	}
	else if (y1->value == 12)
	{
		cout << "          y1"; 
	}
	else if (y2->value == 12)
	{
		cout << "          y2";
	}
	else if (y3->value == 12)
	{
		cout << "          y3";
	}
	else if (y4->value == 12)
	{
		cout << "          y4"; 
	}
	else if (r1->value == 12)
	{
		cout << "          r1";
	}
	else if (r2->value == 12)
	{
		cout << "          r2"; 
	}
	else if (r3->value == 12)
	{
		cout << "          r3";
	}
	else if (r4->value == 12)
	{
		cout << "          r4"; 
	}
	else
	{
		cout << "          12";		
	}
	cout << "  ";
	if (y2 == yellowstart)
	{
		cout << "y2";		
	}
	else
	{
		cout << "  ";
	}
	cout << endl;		
	//space 100
	if (b1 == bluestart)
	{
		cout << "b1";		
	}
	else
	{
		cout << "  ";
	}
	if (b1->value == 100)
	{
		cout << "b1";
	}
	else if (b2->value == 100)
	{
		cout << "b2";
	}
	else if (b3->value == 100)
	{
		cout << "b3"; 
	}
	else if (b4->value == 100)
	{
		cout << "b4";
	}
	else if (g1->value == 100)
	{
		cout << "g1";
	}
	else if (g2->value == 100)
	{
		cout << "g2";
	}
	else if (g3->value == 100)
	{
		cout << "g3";
	}
	else if (g4->value == 100)
	{
		cout << "g4";
	}
	else if (y1->value == 100)
	{
		cout << "y1";
	}
	else if (y2->value == 100)
	{
		cout << "y2";
	}
	else if (y3->value == 100)
	{
		cout << "y3"; 
	}
	else if (y4->value == 100)
	{
		cout << "y4";
	}
	else if (r1->value == 100)
	{
		cout << "r1";
	}
	else if (r2->value == 100)
	{
		cout << "r2";
	}
	else if (r3->value == 100)
	{
		cout << "r3";
	}
	else if (r4->value == 100)
	{
		cout << "r4";
	}
	else
	{
		cout << "BS";		
	}
	//space 101
	if (b1->value == 111)
	{
		cout << "  b1"; 
	}
	else if (b2->value == 111)
	{
		cout << "  b2";
	}
	else if (b3->value == 111)
	{
		cout << "  b3";
	}
	else if (b4->value == 111)
	{
		cout << "  b4";
	}
	else
	{
		cout << "  B1";		
	}
	//space 102
	if (b1->value == 112)
	{
		cout << "b1"; 
	}
	else if (b2->value == 112)
	{
		cout << "b2";
	}
	else if (b3->value == 112)
	{
		cout << "b3";
	}
	else if (b4->value == 112)
	{
		cout << "b4";
	}
	else
	{
		cout << "B2";		
	}
	//space 103
	if (b1->value == 113)
	{
		cout << "b1"; 
	}
	else if (b2->value == 113)
	{
		cout << "b2";
	}
	else if (b3->value == 113)
	{
		cout << "b3";
	}
	else if (b4->value == 113)
	{
		cout << "b4";
	}
	else
	{
		cout << "B3";		
	}
	//space 104
	if (b1->value == 114)
	{
		cout << "b1"; 
	}
	else if (b2->value == 114)
	{
		cout << "b2";
	}
	else if (b3->value == 114)
	{
		cout << "b3";
	}
	else if (b4->value == 114)
	{
		cout << "b4";
	}
	else
	{
		cout << "B4";		
	}
	cout << "      ";
	//space 304
	if (y1->value == 314)
	{
		cout << "y1"; 
	}
	else if (y2->value == 314)
	{
		cout << "y2";
	}
	else if (y3->value == 314)
	{
		cout << "y3";
	}
	else if (y4->value == 314)
	{
		cout << "y4";
	}
	else
	{
		cout << "Y4";		
	}
	//space 303
	if (y1->value == 313)
	{
		cout << "y1"; 
	}
	else if (y2->value == 313)
	{
		cout << "y2";
	}
	else if (y3->value == 313)
	{
		cout << "y3";
	}
	else if (y4->value == 313)
	{
		cout << "y4";
	}
	else
	{
		cout << "Y3";		
	}
	//space 302
	if (y1->value == 312)
	{
		cout << "y1"; 
	}
	else if (y2->value == 312)
	{
		cout << "y2";
	}
	else if (y3->value == 312)
	{
		cout << "y3";
	}
	else if (y4->value == 312)
	{
		cout << "y4";
	}
	else
	{
		cout << "Y2";		
	}
	//space 301
	if (y1->value == 311)
	{
		cout << "y1"; 
	}
	else if (y2->value == 311)
	{
		cout << "y2";
	}
	else if (y3->value == 311)
	{
		cout << "y3";
	}
	else if (y4->value == 311)
	{
		cout << "y4";
	}
	else
	{
		cout << "Y1";		
	}
	//space 300										
	if (b1->value == 300)
	{
		cout << "  b1";
	}
	else if (b2->value == 300)
	{
		cout << "  b2";
	}
	else if (b3->value == 300)
	{
		cout << "  b3"; 
	}
	else if (b4->value == 300)
	{
		cout << "  b4";
	}
	else if (g1->value == 300)
	{
		cout << "  g1";
	}
	else if (g2->value == 300)
	{
		cout << "  g2";
	}
	else if (g3->value == 300)
	{
		cout << "  g3";
	}
	else if (g4->value == 300)
	{
		cout << "  g4";
	}
	else if (y1->value == 300)
	{
		cout << "  y1";
	}
	else if (y2->value == 300)
	{
		cout << "  y2";
	}
	else if (y3->value == 300)
	{
		cout << "  y3"; 
	}
	else if (y4->value == 300)
	{
		cout << "  y4";
	}
	else if (r1->value == 300)
	{
		cout << "  r1";
	}
	else if (r2->value == 300)
	{
		cout << "  r2";
	}
	else if (r3->value == 300)
	{
		cout << "  r3";
	}
	else if (r4->value == 300)
	{
		cout << "  r4";
	}
	else
	{
		cout << "  YS";		
	}
	if (y1 == yellowstart)
	{
		cout << "y1";		
	}
	else
	{
		cout << "  ";
	}	
	cout << endl;
	if (b2 == bluestart)
	{
		cout << "b2";		
	}
	else
	{
		cout << "  ";
	}	
	//space 24																		
	if (b1->value == 24)
	{
		cout << "  b1";
	}
	else if (b2->value == 24)
	{
		cout << "  b2";
	}
	else if (b3->value == 24)
	{
		cout << "  b3"; 
	}
	else if (b4->value == 24)
	{
		cout << "  b4";
	}
	else if (g1->value == 24)
	{
		cout << "  g1";
	}
	else if (g2->value == 24)
	{
		cout << "  g2";
	}
	else if (g3->value == 24)
	{
		cout << "  g3";
	}
	else if (g4->value == 24)
	{
		cout << "  g4";
	}
	else if (y1->value == 24)
	{
		cout << "  y1";
	}
	else if (y2->value == 24)
	{
		cout << "  y2";
	}
	else if (y3->value == 24)
	{
		cout << "  y3"; 
	}
	else if (y4->value == 24)
	{
		cout << "  y4";
	}
	else if (r1->value == 24)
	{
		cout << "  r1";
	}
	else if (r2->value == 24)
	{
		cout << "  r2";
	}
	else if (r3->value == 24)
	{
		cout << "  r3";
	}
	else if (r4->value == 24)
	{
		cout << "  r4";
	}
	else
	{
		cout << "  24";		
	}	
	//space 13
	cout << "            ";
	if (b1->value == 13)
	{
		cout << "          b1";
	}
	else if (b2->value == 13)
	{
		cout << "          b2"; 
	}
	else if (b3->value == 13)
	{
		cout << "          b3"; 
	}
	else if (b4->value == 13)
	{
		cout << "          b4";
	}
	else if (g1->value == 13)
	{
		cout << "          g1";
	}
	else if (g2->value == 13)
	{
		cout << "          g2";
	}
	else if (g3->value == 13)
	{
		cout << "          g3";
	}
	else if (g4->value == 13)
	{
		cout << "          g4";
	}
	else if (y1->value == 13)
	{
		cout << "          y1";
	}
	else if (y2->value == 13)
	{
		cout << "          y2"; 
	}
	else if (y3->value == 13)
	{
		cout << "          y3";
	}
	else if (y4->value == 13)
	{
		cout << "          y4";
	}
	else if (r1->value == 13)
	{
		cout << "          r1"; 
	}
	else if (r2->value == 13)
	{
		cout << "          r2";
	}
	else if (r3->value == 13)
	{
		cout << "          r3";
	}
	else if (r4->value == 13)
	{
		cout << "          r4";
	}
	else
	{
		cout << "          13";		
	}
	cout << "  YE" << endl; 
	if (b3 == bluestart)
	{
		cout << "b3";		
	}
	else
	{
		cout << "  ";
	}	
	//space 23																		
	if (b1->value == 23)
	{
		cout << "    b1";
	}
	else if (b2->value == 23)
	{
		cout << "    b2";
	}
	else if (b3->value == 23)
	{
		cout << "    b3"; 
	}
	else if (b4->value == 23)
	{
		cout << "    b4";
	}
	else if (g1->value == 23)
	{
		cout << "    g1";
	}
	else if (g2->value == 23)
	{
		cout << "    g2";
	}
	else if (g3->value == 23)
	{
		cout << "    g3";
	}
	else if (g4->value == 23)
	{
		cout << "    g4";
	}
	else if (y1->value == 23)
	{
		cout << "    y1";
	}
	else if (y2->value == 23)
	{
		cout << "    y2";
	}
	else if (y3->value == 23)
	{
		cout << "    y3"; 
	}
	else if (y4->value == 23)
	{
		cout << "    y4";
	}
	else if (r1->value == 23)
	{
		cout << "    r1";
	}
	else if (r2->value == 23)
	{
		cout << "    r2";
	}
	else if (r3->value == 23)
	{
		cout << "    r3";
	}
	else if (r4->value == 23)
	{
		cout << "    r4";
	}
	else
	{
		cout << "    23";		
	}	
	//space 404
	if (r1->value == 414)
	{
		cout << "        r1"; 
	}
	else if (r2->value == 414)
	{
		cout << "        r2";
	}
	else if (r3->value == 414)
	{
		cout << "        r3";
	}
	else if (r4->value == 414)
	{
		cout << "        r4";
	}
	else
	{
		cout << "        R4";		
	}
	//space 14
	if (b1->value == 14)
	{
		cout << "        b1";
		cout << endl; 
	}
	else if (b2->value == 14)
	{
		cout << "        b2";
		cout << endl; 
	}
	else if (b3->value == 14)
	{
		cout << "        b3";
		cout << endl; 
	}
	else if (b4->value == 14)
	{
		cout << "        b4";
		cout << endl; 
	}
	else if (g1->value == 14)
	{
		cout << "        g1";
		cout << endl; 
	}
	else if (g2->value == 14)
	{
		cout << "        g2";
		cout << endl; 
	}
	else if (g3->value == 14)
	{
		cout << "        g3";
		cout << endl; 
	}
	else if (g4->value == 14)
	{
		cout << "        g4";
		cout << endl; 
	}
	else if (y1->value == 14)
	{
		cout << "        y1";
		cout << endl; 
	}
	else if (y2->value == 14)
	{
		cout << "        y2";
		cout << endl; 
	}
	else if (y3->value == 14)
	{
		cout << "        y3";
		cout << endl; 
	}
	else if (y4->value == 14)
	{
		cout << "        y4";
		cout << endl; 
	}
	else if (r1->value == 14)
	{
		cout << "        r1";
		cout << endl; 
	}
	else if (r2->value == 14)
	{
		cout << "        r2";
		cout << endl; 
	}
	else if (r3->value == 14)
	{
		cout << "        r3";
		cout << endl; 
	}
	else if (r4->value == 14)
	{
		cout << "        r4";
		cout << endl; 
	}
	else
	{
		cout << "        14";
		cout << endl; 		
	}
	if (b4 == bluestart)
	{
		cout << "b4";		
	}
	else
	{
		cout << "  ";
	}	
	//space 22																		
	if (b1->value == 22)
	{
		cout << "      b1";
	}
	else if (b2->value == 22)
	{
		cout << "      b2";
	}
	else if (b3->value == 22)
	{
		cout << "      b3"; 
	}
	else if (b4->value == 22)
	{
		cout << "      b4";
	}
	else if (g1->value == 22)
	{
		cout << "      g1";
	}
	else if (g2->value == 22)
	{
		cout << "      g2";
	}
	else if (g3->value == 22)
	{
		cout << "      g3";
	}
	else if (g4->value == 22)
	{
		cout << "      g4";
	}
	else if (y1->value == 22)
	{
		cout << "      y1";
	}
	else if (y2->value == 22)
	{
		cout << "      y2";
	}
	else if (y3->value == 22)
	{
		cout << "      y3"; 
	}
	else if (y4->value == 22)
	{
		cout << "      y4";
	}
	else if (r1->value == 22)
	{
		cout << "      r1";
	}
	else if (r2->value == 22)
	{
		cout << "      r2";
	}
	else if (r3->value == 22)
	{
		cout << "      r3";
	}
	else if (r4->value == 22)
	{
		cout << "      r4";
	}
	else
	{
		cout << "      22";		
	}	
	//space 403
	if (r1->value == 413)
	{
		cout << "      r1"; 
	}
	else if (r2->value == 413)
	{
		cout << "      r2";
	}
	else if (r3->value == 413)
	{
		cout << "      r3";
	}
	else if (r4->value == 413)
	{
		cout << "     r4";
	}
	else
	{
		cout << "      R3";		
	}
	//space 15
	if (b1->value == 15)
	{
		cout << "      b1";
		cout << endl; 
	}
	else if (b2->value == 15)
	{
		cout << "      b2";
		cout << endl; 
	}
	else if (b3->value == 15)
	{
		cout << "      b3";
		cout << endl; 
	}
	else if (b4->value == 15)
	{
		cout << "      b4";
		cout << endl; 
	}
	else if (g1->value == 15)
	{
		cout << "      g1";
		cout << endl; 
	}
	else if (g2->value == 15)
	{
		cout << "      g2";
		cout << endl; 
	}
	else if (g3->value == 15)
	{
		cout << "      g3";
		cout << endl; 
	}
	else if (g4->value == 15)
	{
		cout << "      g4";
		cout << endl; 
	}
	else if (y1->value == 15)
	{
		cout << "      y1";
		cout << endl; 
	}
	else if (y2->value == 15)
	{
		cout << "      y2";
		cout << endl; 
	}
	else if (y3->value == 15)
	{
		cout << "      y3";
		cout << endl; 
	}
	else if (y4->value == 15)
	{
		cout << "     y4";
		cout << endl; 
	}
	else if (r1->value == 15)
	{
		cout << "      r1";
		cout << endl; 
	}
	else if (r2->value == 15)
	{
		cout << "      r2";
		cout << endl; 
	}
	else if (r3->value == 15)
	{
		cout << "      r3";
		cout << endl; 
	}
	else if (r4->value == 15)
	{
		cout << "      r4";
		cout << endl; 
	}
	else
	{
		cout << "      15";
		cout << endl; 		
	}
	//space 21																		
	if (b1->value == 21)
	{
		cout << "          b1";
	}
	else if (b2->value == 21)
	{
		cout << "          b2";
	}
	else if (b3->value == 21)
	{
		cout << "          b3"; 
	}
	else if (b4->value == 21)
	{
		cout << "          b4";
	}
	else if (g1->value == 21)
	{
		cout << "          g1";
	}
	else if (g2->value == 21)
	{
		cout << "          g2";
	}
	else if (g3->value == 21)
	{
		cout << "          g3";
	}
	else if (g4->value == 21)
	{
		cout << "          g4";
	}
	else if (y1->value == 21)
	{
		cout << "          y1";
	}
	else if (y2->value == 21)
	{
		cout << "          y2";
	}
	else if (y3->value == 21)
	{
		cout << "          y3"; 
	}
	else if (y4->value == 21)
	{
		cout << "          y4";
	}
	else if (r1->value == 21)
	{
		cout << "          r1";
	}
	else if (r2->value == 21)
	{
		cout << "          r2";
	}
	else if (r3->value == 21)
	{
		cout << "          r3";
	}
	else if (r4->value == 21)
	{
		cout << "          r4";
	}
	else
	{
		cout << "          21";		
	}	
	//space 402
	if (r1->value == 412)
	{
		cout << "    g1"; 
	}
	else if (r2->value == 412)
	{
		cout << "    g2";
	}
	else if (r3->value == 412)
	{
		cout << "    g3";
	}
	else if (r4->value == 412)
	{
		cout << "    g4";
	}
	else
	{
		cout << "    R2";		
	}
	//space 16
	if (b1->value == 16)
	{
		cout << "    b1";
		cout << endl; 
	}
	else if (b2->value == 16)
	{
		cout << "    b2";
		cout << endl; 
	}
	else if (b3->value == 16)
	{
		cout << "    b3";
		cout << endl; 
	}
	else if (b4->value == 16)
	{
		cout << "    b4";
		cout << endl; 
	}
	else if (g1->value == 16)
	{
		cout << "    g1";
		cout << endl; 
	}
	else if (g2->value == 16)
	{
		cout << "    g2";
		cout << endl; 
	}
	else if (g3->value == 16)
	{
		cout << "    g3";
		cout << endl; 
	}
	else if (g4->value == 16)
	{
		cout << "    g4";
		cout << endl; 
	}
	else if (y1->value == 16)
	{
		cout << "    y1";
		cout << endl; 
	}
	else if (y2->value == 16)
	{
		cout << "    y2";
		cout << endl; 
	}
	else if (y3->value == 16)
	{
		cout << "    y3";
		cout << endl; 
	}
	else if (y4->value == 16)
	{
		cout << "   y4";
		cout << endl; 
	}
	else if (r1->value == 16)
	{
		cout << "    r1";
		cout << endl; 
	}
	else if (r2->value == 16)
	{
		cout << "    r2";
		cout << endl; 
	}
	else if (r3->value == 16)
	{
		cout << "    r3";
		cout << endl; 
	}
	else if (r4->value == 16)
	{
		cout << "    r4";
		cout << endl; 
	}
	else
	{
		cout << "    16";
		cout << endl; 		
	}
	//space 20																		
	if (b1->value == 20)
	{
		cout << "            b1";
	}
	else if (b2->value == 20)
	{
		cout << "            b2";
	}
	else if (b3->value == 20)
	{
		cout << "            b3"; 
	}
	else if (b4->value == 20)
	{
		cout << "            b4";
	}
	else if (g1->value == 20)
	{
		cout << "            g1";
	}
	else if (g2->value == 20)
	{
		cout << "            g2";
	}
	else if (g3->value == 20)
	{
		cout << "            g3";
	}
	else if (g4->value == 20)
	{
		cout << "            g4";
	}
	else if (y1->value == 20)
	{
		cout << "            y1";
	}
	else if (y2->value == 20)
	{
		cout << "            y2";
	}
	else if (y3->value == 20)
	{
		cout << "            y3"; 
	}
	else if (y4->value == 20)
	{
		cout << "            y4";
	}
	else if (r1->value == 20)
	{
		cout << "            r1";
	}
	else if (r2->value == 20)
	{
		cout << "            r2";
	}
	else if (r3->value == 20)
	{
		cout << "            r3";
	}
	else if (r4->value == 20)
	{
		cout << "            r4";
	}
	else
	{
		cout << "            20";		
	}	
	//space 401
	if (r1->value == 411)
	{
		cout << "  r1"; 
	}
	else if (g2->value == 411)
	{
		cout << "  r2";
	}
	else if (g3->value == 411)
	{
		cout << "  r3";
	}
	else if (g4->value == 411)
	{
		cout << "  r4";
	}
	else
	{
		cout << "  R1";		
	}
	//space 17
	if (b1->value == 17)
	{
		cout << "  b1";
		cout << endl; 
	}
	else if (b2->value == 17)
	{
		cout << "  b2";
		cout << endl; 
	}
	else if (b3->value == 17)
	{
		cout << "  b3";
		cout << endl; 
	}
	else if (b4->value == 17)
	{
		cout << "  b4";
		cout << endl; 
	}
	else if (g1->value == 17)
	{
		cout << "  g1";
		cout << endl; 
	}
	else if (g2->value == 17)
	{
		cout << "  g2";
		cout << endl; 
	}
	else if (g3->value == 17)
	{
		cout << "  g3";
		cout << endl; 
	}
	else if (g4->value == 17)
	{
		cout << "  g4";
		cout << endl; 
	}
	else if (y1->value == 17)
	{
		cout << "  y1";
		cout << endl; 
	}
	else if (y2->value == 17)
	{
		cout << "  y2";
		cout << endl; 
	}
	else if (y3->value == 17)
	{
		cout << "  y3";
		cout << endl; 
	}
	else if (y4->value == 17)
	{
		cout << "  y4";
		cout << endl; 
	}
	else if (r1->value == 17)
	{
		cout << "  r1";
		cout << endl; 
	}
	else if (r2->value == 17)
	{
		cout << "  r2";
		cout << endl; 
	}
	else if (r3->value == 17)
	{
		cout << "  r3";
		cout << endl; 
	}
	else if (r4->value == 17)
	{
		cout << "  r4";
		cout << endl; 
	}
	else
	{
		cout << "  17";
		cout << endl; 		
	}
	//space 19
	if (b1->value == 19)
	{
		cout << "              b1";
	}
	else if (b2->value == 19)
	{
		cout << "              b2";
	}
	else if (b3->value == 19)
	{
		cout << "              b3"; 
	}
	else if (b4->value == 19)
	{
		cout << "              b4";
	}
	else if (g1->value == 19)
	{
		cout << "              g1";
	}
	else if (g2->value == 19)
	{
		cout << "              g2";
	}
	else if (g3->value == 19)
	{
		cout << "              g3";
	}
	else if (g4->value == 19)
	{
		cout << "              g4";
	}
	else if (y1->value == 19)
	{
		cout << "              y1";
	}
	else if (y2->value == 19)
	{
		cout << "              y2";
	}
	else if (y3->value == 19)
	{
		cout << "              y3"; 
	}
	else if (y4->value == 19)
	{
		cout << "              y4";
	}
	else if (r1->value == 19)
	{
		cout << "              r1";
	}
	else if (r2->value == 19)
	{
		cout << "              r2";
	}
	else if (r3->value == 19)
	{
		cout << "              r3";
	}
	else if (r4->value == 19)
	{
		cout << "              r4";
	}
	else
	{
		cout << "              19";		
	}	
	//space 18
	if (b1->value == 18)
	{
		cout << "  b1";
		cout << endl; 
	}
	else if (b2->value == 18)
	{
		cout << "  b2";
		cout << endl; 
	}
	else if (b3->value == 18)
	{
		cout << "  b3";
		cout << endl; 
	}
	else if (b4->value == 18)
	{
		cout << "  b4";
		cout << endl; 
	}
	else if (g1->value == 18)
	{
		cout << "  g1";
		cout << endl; 
	}
	else if (g2->value == 18)
	{
		cout << "  g2";
		cout << endl; 
	}
	else if (g3->value == 18)
	{
		cout << "  g3";
		cout << endl; 
	}
	else if (g4->value == 18)
	{
		cout << "  g4";
		cout << endl; 
	}
	else if (y1->value == 18)
	{
		cout << "  y1";
		cout << endl; 
	}
	else if (y2->value == 18)
	{
		cout << "  y2";
		cout << endl; 
	}
	else if (y3->value == 18)
	{
		cout << "  y3";
		cout << endl; 
	}
	else if (y4->value == 18)
	{
		cout << "  y4";
		cout << endl; 
	}
	else if (r1->value == 18)
	{
		cout << "  r1";
		cout << endl; 
	}
	else if (r2->value == 18)
	{
		cout << "  r2";
		cout << endl; 
	}
	else if (r3->value == 18)
	{
		cout << "  r3";
		cout << endl; 
	}
	else if (r4->value == 18)
	{
		cout << "  r4";
		cout << endl; 
	}
	else
	{
		cout << "  18";
		cout << endl; 		
	}
	//space 400
	if (b1->value == 400)
	{
		cout << "                b1";
		cout << endl; 
	}
	else if (b2->value == 400)
	{
		cout << "                b2";
		cout << endl; 
	}
	else if (b3->value == 400)
	{
		cout << "                b3";
		cout << endl; 
	}
	else if (b4->value == 400)
	{
		cout << "                b4";
		cout << endl; 
	}
	else if (g1->value == 400)
	{
		cout << "                g1";
		cout << endl; 
	}
	else if (g2->value == 400)
	{
		cout << "                g2";
		cout << endl; 
	}
	else if (g3->value == 400)
	{
		cout << "                g3";
		cout << endl; 
	}
	else if (g4->value == 400)
	{
		cout << "                g4";
		cout << endl; 
	}
	else if (y1->value == 400)
	{
		cout << "                y1";
		cout << endl; 
	}
	else if (y2->value == 400)
	{
		cout << "                y2";
		cout << endl; 
	}
	else if (y3->value == 400)
	{
		cout << "                y3";
		cout << endl; 
	}
	else if (y4->value == 400)
	{
		cout << "                y4";
		cout << endl; 
	}
	else if (r1->value == 400)
	{
		cout << "                r1";
		cout << endl; 
	}
	else if (r2->value == 400)
	{
		cout << "                r2";
		cout << endl; 
	}
	else if (r3->value == 400)
	{
		cout << "                r3";
		cout << endl; 
	}
	else if (r4->value == 400)
	{
		cout << "                r4";
		cout << endl; 
	}
	else
	{
		cout << "                RS";
		cout << endl; 		
	}
	//red start
	if (r1 == redstart && r2 != redstart && r3 != redstart && g4 != redstart)
	{
		cout << "                r1";
		cout << endl;
	}
	if (r1 == redstart && r2 == redstart && r3 != redstart && r4 != redstart)
	{
		cout << "                r1r2";
		cout << endl;
	}
	if (r1 == redstart && r2 != redstart && r3 == redstart && r4 != redstart)
	{
		cout << "                r1r3";
		cout << endl;
	}
	if (r1 == redstart && r2 != redstart && r3 != redstart && r4 == redstart)
	{
		cout << "                r1r4";
		cout << endl;
	}	
	if (r1 == redstart && r2 == redstart && r3 == redstart && r4 != redstart)
	{
		cout << "                r1r2r3";
		cout << endl;
	}
	if (r1 == redstart && r2 != redstart && r3 == redstart && r4 == redstart)
	{
		cout << "                r1r3r4";
		cout << endl;
	}
	if (r1 == redstart && r2 == redstart && r3 != redstart && r4 == redstart)
	{
		cout << "                r1r2r4";
		cout << endl;
	}			
	if (r1 == redstart && r2 == redstart && r3 == redstart && r4 == redstart)
	{
		cout << "                r1r2r3r4";
		cout << endl;
	}
	if (r1 != redstart && r2 == redstart && r3 != redstart && r4 != redstart)
	{
		cout << "                r2";
		cout << endl;
	}	
	if (r1 != redstart && r2 == redstart && r3 == redstart && r4 != redstart)
	{
		cout << "                r2r3";
		cout << endl;
	}
	if (r1 != redstart && r2 == redstart && r3 != redstart && r4 == redstart)
	{
		cout << "                r2r4";
		cout << endl;
	}	
	if (r1 != redstart && r2 == redstart && r3 == redstart && r4 == redstart)
	{
		cout << "                r2r3r4";
		cout << endl;
	}
	if (r1 != redstart && r2 != redstart && r3 == redstart && r4 != redstart)
	{
		cout << "                r3";
		cout << endl;
	}
	if (r1 != redstart && r2 != redstart && r3 == redstart && r4 == redstart)
	{
		cout << "                r3r4";
		cout << endl;
	}
	if (r1 != redstart && r2 != redstart && r3 != redstart && r4 == redstart)
	{
		cout << "                r4";
		cout << endl;
	}
	if (r1 != redstart && r2 != redstart && r3 != redstart && r4 != redstart)
	{
		cout << "                  ";
		cout << endl;
	}									
}				
