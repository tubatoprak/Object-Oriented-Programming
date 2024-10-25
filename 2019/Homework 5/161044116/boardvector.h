#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "abstractboard.h"

namespace NPuzzle
{
	class BoardVector: public AbstractBoard
	{
		public:
			
			void print();
			string operator ()(int x ,int y );
			BoardVector();	
			~BoardVector(){}
			void setSize(int x,int y);
			void readFromFile(string takefile);
			void writeToFile(string takefile);
			void reset_correct();
			void reset();
			void move(char movee);
			bool  isSolved();
			char lastMove();
			int numberOfMoves();
		
		protected:
			vector<int> puzzlesize;
			vector<string> puzzlevector;
			vector<string> correctpuzzlevector;
			char lastmovee;
			int totalmovesV;
	};
}
#endif