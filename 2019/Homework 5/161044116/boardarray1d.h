#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H
#include <iostream>
#include <string>
#include <fstream>

#include "abstractboard.h"

namespace NPuzzle
{
	class BoardArray1D: public AbstractBoard
	{
		public:	
				
			void print();
			BoardArray1D();
			~BoardArray1D();
			void setSize(int x,int y);
			string operator ()(int x ,int y );
			void readFromFile(string takefile);
			void writeToFile(string takefile);
			void reset();
			void reset_variable();
			void reset_correct();
			void move(char movee);
			bool  isSolved();
			char lastMove();
			int numberOfMoves();
		protected:
			string* puzzle1;
			//string * temppuzzle1;
			string * correctpuzzle1;
			int totalmoves1D;	
			char lastmovee;
	};
}
#endif