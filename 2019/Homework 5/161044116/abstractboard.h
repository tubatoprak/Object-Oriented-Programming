
#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace NPuzzle
{
	class AbstractBoard
	{
		public:
			AbstractBoard();
			virtual string operator ()(int x ,int y ) = 0;
			//virtual bool operator ==(AbstractBoard& obje) = 0;
			void set_row_column(int r_temp,int c_temp);
			void setSize(int x,int y);
			virtual void print() = 0;
			virtual void writeToFile(string takefile) = 0;
			virtual int numberOfMoves() = 0;
			virtual char lastMove() = 0;
			virtual bool  isSolved() = 0;
			virtual void reset() = 0;
			virtual void reset_correct() = 0;
			virtual void readFromFile(string takefile)=0;
			virtual void move(char movee) = 0;
			int NumberOfBoards();
			


		protected:
			int row;
			int column;
			int total;
			int size;
			ofstream savef;
			string savefilename;
			ifstream file;
			string filename;
			string line,str;
			int r_temp,c_temp;
			
			int totalmoves;
	};

static int numberofboardss = 0;
}
#endif