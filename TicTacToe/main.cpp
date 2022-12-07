#include<iostream>
#include<map>
#include<random>
#include<string>
using namespace std;

void printBoard(map<string, string> &boardMap);
void currentMove(map<string, string> &boardMap, bool &isPlayersTurn, bool &isGameEnd, string playerLetter, string computerLetter);
void checkIfGameIsOver(map<string, string> boardMap, string whoIsCheck, bool &isGameEnd);

int main()
{
	string playerLetter;
	string computerLetter;
	bool isGameEnd = false;
	bool isPlayersTurn = true;
	int computerMoves = 0;
	int playerMoves = 0;
	map<string, string> boardMap;
	boardMap["0,0"] = "_";
	boardMap["1,0"] = "_";
	boardMap["2,0"] = "_";
	boardMap["0,1"] = "_";
	boardMap["1,1"] = "_";
	boardMap["2,1"] = "_";
	boardMap["0,2"] = "_";
	boardMap["1,2"] = "_";
	boardMap["2,2"] = "_";

	while (playerLetter != "x" || playerLetter != "o") 
	{
		cout << "Would you like to play as 'x' or 'o'? Please enter." << endl;
		cin >> playerLetter;
		if (playerLetter == "o") 
		{
			cout << "You have chosen 'o'" << endl;
			computerLetter = "x";
			break;
		}
		else if (playerLetter == "x") 
		{
			cout << "You have chosen 'x'" << endl;
			computerLetter = "o";
			break;
		}
		else if (playerLetter != "x" || playerLetter != "o") {
			cout << "You have chosen an invalid value. Please select 'o' or 'x'." << endl;
		}
	}//Asks the player if they would like to be x or o, rejects any other entries.

	printBoard(boardMap);
	
	while (isGameEnd == false)
	{
		currentMove(boardMap, isPlayersTurn, isGameEnd, playerLetter, computerLetter);
	}

	return 0;
}

void printBoard(map<string, string> &boardMap) {
	cout << endl;
	cout << " " << boardMap["0,2"] << " | " << boardMap["1,2"] << " | " << boardMap["2,2"] << endl;
	cout << "-----------" << endl;
	cout << " " << boardMap["0,1"] << " | " << boardMap["1,1"] << " | " << boardMap["2,1"] << endl;
	cout << "-----------" << endl;
	cout << " " << boardMap["0,0"] << " | " << boardMap["1,0"] << " | " << boardMap["2,0"] << endl;
	cout << endl;
}//Runs through the array of board values, outputting each one to the cli.

void currentMove(map<string, string> &boardMap, bool &isPlayersTurn, bool &isGameEnd, string playerLetter, string computerLetter) 
{
	if (isPlayersTurn == true) //Players Turn
	{
		string tempCoordinate;					
		cout << "Please enter the coordinates of your next move as 'x,y' ?" << endl;
		cin >> tempCoordinate;
		if (boardMap[tempCoordinate] == "_") //Checks if the entered coordinates are an empty space on the board.
		{
			boardMap[tempCoordinate] = playerLetter;
			checkIfGameIsOver(boardMap, playerLetter, isGameEnd);
			isPlayersTurn = false;
		}
		else { //Rejects the entry and requests the player input again.
			cout << "The coordinate you have input is not valid." << endl;
			isPlayersTurn = true;
		}
	}
	else //Computers Turn
	{
		int ranX = (rand() % 3);
		int ranY = (rand() % 3);
		auto coordinate = to_string(ranX) + "," + to_string(ranY); //converts the generated numbers from INT to STRING
		if (boardMap[coordinate] == "_") //checks if the generated coordinates are an empty space on the board.
		{
			boardMap[coordinate] = computerLetter;
			cout << "The computer has chosen " << coordinate << endl;
			checkIfGameIsOver(boardMap, computerLetter, isGameEnd);
			isPlayersTurn = true;
		}
		else //retakes turn 
		{
			isPlayersTurn = false;
		}
	}
	printBoard(boardMap);
}

void checkIfGameIsOver(map<string, string> boardMap, string whoIsCheck, bool &isGameEnd)
{
	if (boardMap["0,0"] == whoIsCheck && boardMap["1,0"] == whoIsCheck && boardMap["2,0"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["0,1"] == whoIsCheck && boardMap["1,1"] == whoIsCheck && boardMap["2,1"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["0,2"] == whoIsCheck && boardMap["1,2"] == whoIsCheck && boardMap["2,2"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["0,0"] == whoIsCheck && boardMap["0,1"] == whoIsCheck && boardMap["0,2"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["1,0"] == whoIsCheck && boardMap["1,1"] == whoIsCheck && boardMap["1,2"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["2,0"] == whoIsCheck && boardMap["2,1"] == whoIsCheck && boardMap["2,2"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["0,0"] == whoIsCheck && boardMap["1,1"] == whoIsCheck && boardMap["2,2"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else if (boardMap["0,2"] == whoIsCheck && boardMap["1,1"] == whoIsCheck && boardMap["0,0"] == whoIsCheck) {
		cout << endl;
		cout << whoIsCheck + " has won!" << endl;
		isGameEnd = true;
	}
	else //checks for a draw
	{
		if (boardMap["0,0"] == "_") {
			isGameEnd = false;
		}
		else if (boardMap["1,0"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["2,0"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["0,1"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["1,1"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["0,2"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["1,2"] == "_")
		{
			isGameEnd = false;
		}
		else if (boardMap["2,2"] == "_")
		{
			isGameEnd = false;
		}
		else {
			isGameEnd = true;
			cout << endl;
			cout << "DRAW" << endl;
		}
	}
	
}
