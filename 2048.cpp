#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

//global variables used to determine score and victory
int score = 0;
bool victory = false;
bool loss = false;

//adds a randomly generated space to the board
void randomSpace(int*& board){
	while(true){
		int random = rand() % 16;
		if(board[random] == 0){
			board[random] = 2;
			return;
		}
	}
}

bool moveAvailable(int* board){
	for(int i = 0; i < 16; i++){
		int top = i - 4;
		int bottom = i + 4;
		int left;
		if(i%4 == 0)
			left = -1;
		else
			left = i - 1;

		int right;
		if((i+1)%4 == 0)
			right = -1;
		else
			right = i + 1;
		
		if(top > -1)
			if(board[i] == board[top])
				return true;
		if(bottom < 16)
			if(board[i] == board[bottom])
				return true;
		if(left > -1)
			if(board[i] == board[left])
				return true;
		if(right > -1)
			if(board[i] == board[right])
				return true;
	}
	return false;
}

//prints the board with formatted statements to allow for a neat board
void printBoard(int* board){
	printf("\n\nSCORE: %d\n\n", score);
	char** strings = new char*[16];
	for(int i = 0; i < 16; i++){
		strings[i] = new char[5];
		if(board[i] == 0)
			strings[i][0] = ' ';
		else{
			string temp = to_string(board[i]);
			strcpy(strings[i], temp.c_str());
		}
	}
	printf("%4s|%4s|%4s|%4s\n", strings[0],strings[1],strings[2],strings[3]);
	for(int i = 4; i < 16; i+=4){
		printf("----|----|----|----\n");
		printf("%4s|%4s|%4s|%4s\n", strings[i],strings[i+1],strings[i+2],strings[i+3]);
	}
	printf("\n(w): Up\n(a): Left\n(s): Down\n(d): Right\n--------------------\n\nEnter an option: ");
	return;
}

//checks to see if the whole board is full (used for end game scenarios)
bool fullBoard(int* board){
	for(int i = 0; i < 16; i++)
		if(board[i] == 0)
			return false;
	return true;
}

//the code to shift up and left is similar so i made it generic to reduce the amount of code
void shiftUpLeft(int*& board, int maxCol, int incrementOuter, int incrementInner){
	bool anyChanges = false;
	for(int i = 0; i < maxCol; i+= incrementOuter){
		bool changesInner;

		//shifts all of the cells up/left
		do{
			changesInner = false;
			for(int j = i+incrementInner; j <= i+(3*incrementInner); j+=incrementInner){
				if(board[j - incrementInner] == 0 && board[j] > 0){
					board[j - incrementInner] = board[j];
					board[j] = 0;
					changesInner = true;
					anyChanges = true;
				}
			}
		}
		while(changesInner);

		//combines cells if they are equal
		for(int j = i+incrementInner; j <= i+(3*incrementInner); j+=incrementInner){
			if(board[j - incrementInner] == board[j] && board[j] != 0){
				board[j - incrementInner] *= 2;
				score += board[j - incrementInner];
				if(board[j + incrementInner] == 2048)
					victory = true;
				board[j] = 0;
				anyChanges = true;
			}
		}

		// shifts all of the cells up/left again
		do{
			changesInner = false;
			for(int j = i+incrementInner; j <= i+(3*incrementInner); j+=incrementInner){
				if(board[j - incrementInner] == 0 && board[j] > 0){
					board[j - incrementInner] = board[j];
					board[j] = 0;
					changesInner = true;
					anyChanges = true;
				}
			}
		}
		while(changesInner);
	}

	//determines whether to end the game or add a space
	if(!anyChanges && fullBoard(board) && !moveAvailable(board))
		loss = true;
	else if(anyChanges)
		randomSpace(board);
}

//generic function to shift down/right.  requires less code this way
void shiftDownRight(int*& board, int minCol, int incrementOuter, int incrementInner){
	bool anyChanges = false;
	for(int i = minCol; i < 16; i += incrementOuter){
		bool changesInner;

		//used to shift all of the cells down/right
		do{
			changesInner = false;
			for(int j = i-incrementInner; j >= i-(3*incrementInner); j-= incrementInner){
				if(board[j + incrementInner] == 0 && board[j] > 0){
					board[j + incrementInner] = board[j];
					board[j] = 0;
					changesInner = true;
					anyChanges = true;
				}
			}
		}
		while(changesInner);

		//combines all cells that need to be combined
		for(int j = i-incrementInner; j >= i-(3*incrementInner); j-= incrementInner){
			if(board[j + incrementInner] == board[j] && board[j] != 0){
				board[j + incrementInner] *= 2;
				score += board[j + incrementInner];
				if(board[j + incrementInner] == 2048)
					victory = true;
				board[j] = 0;
				anyChanges = true;
			}
		}

		//shifts down/right again
		do{
			changesInner = false;
			for(int j = i-incrementInner; j >= i-(3*incrementInner); j-= incrementInner){
				if(board[j + incrementInner] == 0 && board[j] > 0){
					board[j + incrementInner] = board[j];
					board[j] = 0;
					changesInner = true;
					anyChanges = true;
				}
			}
		}
		while(changesInner);
	}

	//checks to see if the end of game condition has occured
	if(!anyChanges && fullBoard(board) && !moveAvailable(board))
		loss = true;
	else if(anyChanges)
		randomSpace(board);
}

string pickRandomLetter(){
	switch(rand() % 3){
	case 0:
		return "a";
	case 1:
		return "s";
	case 2:
		return "d";
	case 3:
		return "w";
	default:
		return "s";

	}
}
int main(){

	//creates a 1D array as the 16 spots in the table
	int* board = new int[16];
	srand (time(NULL));
	//int count = 0;

	//populates the board with zeros
	for(int i = 0; i < 16; i++)
		board[i] = 0;

	//adds 2 random spaces for the beginning of the game
	randomSpace(board);
	randomSpace(board);

	//while the game has not been won or lost, keep going
	while(true){
		printBoard(board);
		string buffer;
		cin >> buffer;

		//forces the user to enter a valid option
		while(buffer.compare("w") != 0 && buffer.compare("a") != 0 && buffer.compare("s") != 0 && buffer.compare("d") != 0){
			printf("NOT A VALID OPTION!!\n\nEnter an option: ");
			cin >> buffer;
		}

		//shifts according to the number entered
		if(buffer.compare("w") == 0)
			shiftUpLeft(board, 4, 1, 4);
		else if(buffer.compare("a") == 0)
			shiftUpLeft(board, 14, 4, 1);
		else if(buffer.compare("s") == 0)
			shiftDownRight(board, 12, 1, 4);
		else if(buffer.compare("d") == 0)
			shiftDownRight(board, 3, 4, 1);
		else
			printf("NOT A VALID OPTION!!\n");
		if(victory){
			printf("\n\n\n\nYOU WON!!!!!!\n\n\n\n");
			return 0;
		}
		else if(loss){
			printf("\n\n\n\nYou lost.....\n\n\n\n");
			return 0;
		}
	}
	return 0;
}