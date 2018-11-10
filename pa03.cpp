#include "maze.h"
#include "maze.cpp"
#include <iostream>

using namespace std;

int main()
{
  //////////////Var Declaration////////////////
	string myInfo[2];
	myInfo[0] = "zlfkdd";
	myInfo[1] = "12543794";
	string *matrix;
	int rows = 0;
	int cols = 0;
	int xStart = 0;
	int yStart = 0;
	int xCurr = 0;
	int yCurr = 0;
	int endX = 0;
	int endY = 0;
	int mapCounter = 0;   // keep track of the number map we're on
	int trapC = 0;
	bool solRes;
	direction dir = NORTH;

	//////////////Program Start/////////////////////////
	do
  {
	//cout << "How many rows and columns would you like?" << endl;
	cin  >> rows;
	cin  >> cols;
	if(rows == 0 || cols == 0) 
		return 0;
	//getline(cin, rows);
	cin.ignore();

	matrix = build_matrix(rows);
	fill_matrix(matrix, rows);
	find_start(matrix, rows, xStart, yStart);
	xCurr = xStart;
	yCurr = yStart;
	//cerr << "N is located at (" << xCurr <<","<< yCurr << ")"<< endl;
  //canMove = valid_move(matrix, xCurr, yCurr, dir);
  //cout << "The object can move is " << canMove << endl;
  //cout << "The object at that space is " << matrix[0][3] << endl;
  solRes = find_exit(matrix, xCurr, yCurr);
  //find_exit(matrix, xCurr, yCurr);
  if(solRes)
  {
    cout <<  "Map " << mapCounter << " -- Solution found:" << endl;
  }
  else
  {
     cout << "Map " << mapCounter << " -- No solution found:" << endl;
  }

	print_matrix(matrix, rows);
	delete_matrix(matrix, rows);
	mapCounter++;
  } while((rows*cols)>0);
  return 0;
}

