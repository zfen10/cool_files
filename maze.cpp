#include "maze.h"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::string;


void get_identity(string my_id[])
{
    cout << my_id[0] << endl;
		cout << my_id[1] << endl;
}


string * build_matrix(int rows)
{
	string *mazerows = new string [rows];
	/*
	for(int i = 0; i<rows; i++)
  {
    mazerows[i] = new string
  }
  */
	return mazerows;
}


void fill_matrix(string *matrix, int rows)
{
  //cout << "Please enter text to fill your array." << endl;
  for(int i = 0; i < rows; i++)
  {
    //cerr << "word " << i;
    getline(cin, matrix[i]);
  }
}


void print_matrix(string *matrix, int rows)
{
  //cout << "Printing Maze" << endl;
  for(int i = 0; i < rows; i++)
  {
    //cerr << "word " << i;
    cout << matrix[i] << endl;
  }
  cout << endl;
}


void delete_matrix(string *matrix, int rows)
{
  /*for(int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }*/
  delete[] matrix;
  matrix = NULL;
}


void find_start(string *matrix, int rows, int &x, int &y)
{
  for(int i = 0; i < rows; i++)
    for(int q = 0; q < matrix[0].length(); q++)
    {
      if(matrix[i][q] == 'N')
      {
        y = i;
        x = q;
      }
    }
  return;
}

bool find_exit(string *matrix, int x, int y)
{
  int counter = 4;
  bool foundE;
  if(at_end(matrix,x,y))
    return true;

  

  if(matrix[y][x] != 'N')
  {
    matrix[y][x] = '@';
  }    
  
	for(int i = 0; i<counter; i++)
	{
	  if(i == 0)
	  {
	    if(valid_move(matrix, x, y, WEST))
	    	foundE = find_exit(matrix,x-1,y);
	  }
	  else if(i == 1)
	  {
	    if(valid_move(matrix, x, y, NORTH))
	    {
	      foundE = find_exit(matrix,x,y-1);
	    }
	  }
	  else if(i == 2)
	  {
	    if(valid_move(matrix, x, y, SOUTH))
	    {
	      foundE = find_exit(matrix,x,y+1);
	    }
	  }
	  else if(i == 3)
	  {
	    if(valid_move(matrix, x, y, EAST))
	    {
	      foundE = find_exit(matrix,x+1,y);
	    }
	  }
	  if(foundE)
	  	return true;
    //return find_exit(matrix,x,y);
    }
    if(!foundE && matrix[y][x]!= 'N')
  	  matrix[y][x] = ' ';

  return foundE;
}


bool at_end(string *matrix, int x, int y)
{
  //if(matrix[y][x] == 'E' || matrix[y+1][x] == 'E'|| matrix[y-1][x] == 'E'|| matrix[y][x+1] == 'E' || matrix[y][x-1] == 'E')
  if(matrix[y][x] == 'E')
    return true;
  else
    return false;
}

bool valid_move(string *matrix, int x, int y, direction d)
{
  //cerr << "Above if ladder" << endl;
  if(d == 0)
  {
    //cerr << "Matrix at [y-1][x]";
    //cout << matrix[y-1][x] << endl;
    if(matrix[y-1][x] == ' ' || matrix[y-1][x] == 'E')
      return true;
    else
      return false;
  }
  else if(d == 1)
  {
    //cerr << "Inside d=1" << endl;
    if(matrix[y+1][x] == ' ' || matrix[y+1][x] == 'E')
      return true;
    else
      return false;
  }
  else if(d == 2)
  {
    //cerr << "Matrix at [y][x+1]";
    //cout << matrix[y][x+1] << endl;
    if(matrix[y][x+1] == ' ' || matrix[y][x+1] == 'E')
      return true;
    else
      return false;
  }
  else if(d == 3)
  {
    if(matrix[y][x-1] == ' ' || matrix[y][x-1] == 'E')
      return true;
    else
      return false;
  }
}

