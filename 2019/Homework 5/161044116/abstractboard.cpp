#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

#include "abstractboard.h"

namespace NPuzzle
{
	AbstractBoard::AbstractBoard()
	{
		total = 0;
		numberofboardss++;
	}	
	void AbstractBoard::set_row_column(int r_temp,int c_temp)
	{
		row = r_temp;
		column = c_temp;
	}
	int NumberOfBoards()
	{
		return numberofboardss;
	}
	
	/*bool AbstractBoard::operator==(const AbstractBoard& obje)
	{
		int temp;
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (this->operator()(i,j) == (obje)(i,j))
				{
					temp++;
				}
			}
		}
		if (temp ==(row*column))
			return true;
		else 
			return false;
	}*/
}