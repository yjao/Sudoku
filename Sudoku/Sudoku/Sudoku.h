#ifndef SUDOKU
#define SUDOKU

#include <vector>
#include <random>
#include <iostream>
#include <math.h>
#include "Square.h"
class Sudoku
{
public:
	Sudoku(int width);
	Sudoku(std::vector<int>& reqs);
	Sudoku(std::vector<int>& reqs, std::vector<std::vector<Square*>> sudoku);
	~Sudoku();
	void build();
	void printByBoxes();
	void printByColumns();
	void print();
	
	void fillSudoku(std::vector<int> sudoku);
	void buildRow(int num, int col);
	
	bool checkRow(int num);
	bool checkCol(int num);

	void resetRow(int num);
	void resetSudoku();

	std::vector<int> remainingValuesPossible(int rowNum, int colNum);

private:
	double number;
	int size;
	int boxW;
	int boxH;
	bool restarted=false;
	std::vector<int> domain;

	void buildSquaresAndLists();

	std::vector<std::vector<Square*>> listOfRows;
	std::vector<std::vector<Square*>> listOfColumns;
	std::vector<std::vector<Square*>> listOfBoxes; 
	std::vector<Square*> listOfAllSquares;
	
	std::random_device rd;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;
};

#endif