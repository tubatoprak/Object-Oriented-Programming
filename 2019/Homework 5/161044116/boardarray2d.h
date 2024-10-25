#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H
#include <iostream>
#include <string>
#include <fstream>

#include "abstractboard.h"

namespace NPuzzle
{
	class BoardArray2D: public AbstractBoard
	{
		public:		
			BoardArray2D();
			~BoardArray2D();
			void print();
			void reset_variable();
			void reset();
			void setSize(int x,int y);
			string operator ()(int x ,int y );
			void readFromFile(string takefile);
			void writeToFile(string takefile);
			void reset_correct();
			bool  isSolved();
			void move(char movee);
			char lastMove();
			int numberOfMoves();
		
		protected:

			int ** puzzlesize;
			string ** puzzle2;
			string ** correctpuzzle2;
			int totalmoves2D;	
			char lastmovee;

	};
}
#endif