#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

#include "boardarray1d.h"

using std::cout;
using std::cin;

namespace NPuzzle
{	
	BoardArray1D:: BoardArray1D(): AbstractBoard()
	{
		numberofboardss++;
		totalmoves1D = 0;
		cout<<endl<<numberofboardss<<". 1D BOARD CREATED!!!"<<endl<<endl;
	}
	string BoardArray1D::operator ()(int x ,int y)
	{
		return puzzle1[x*y+y];
	}
	
	void BoardArray1D::reset_variable()
	{
		//delete[] puzzle1;
		//delete[] correctpuzzle1;
		puzzle1 = new string[row*column];
		correctpuzzle1 = new string[row*column];
		totalmoves1D = 0;
	}
	void BoardArray1D::setSize(int x ,int y)
	{
		int * puzzlesize;
		puzzlesize = new int[x*y];
		
		cout<<"WORKING SETSIZE 1D FUNCTION.."<<endl;	
		int key =1;
		
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				puzzlesize[key] = key;
				cout<<puzzlesize[key]<<"  ";
				if(key<10)
					cout<<" ";
				key++;			
			}
			cout<<endl;
		}
	}
	BoardArray1D::~BoardArray1D()
	{
		delete [] puzzle1;
		delete [] correctpuzzle1;
	}
	void BoardArray1D::readFromFile(string takefile)
	{
		filename = takefile;
	 	int i,t;
	 	string rowto;	
		file.open(filename.c_str());
		if(file.is_open())
		{
			while(getline(file,line))
			{
				c_temp++;
			}								
			file.clear();
			file.seekg( 0, std::ios::beg);			
		
			while(!file.eof())
			{
				file >> rowto;
				total++;
			}
			total--;
			r_temp = total/c_temp;
			set_row_column(r_temp,c_temp);
			reset_variable();
			t=0;
			file.clear();
			file.seekg( 0, std::ios::beg);			

			while(file>>str)
			{
				puzzle1[t] = str;
				t++;
			}
		}	
		cout <<endl;
	}
	void BoardArray1D::writeToFile(string takefile)
	{
		savefilename = takefile;
		savef.open(savefilename.c_str());
		int temp =0;
		for (int i = 0; i <column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				savef << puzzle1[temp];
				savef << " ";
				temp++;
			}
			savef << endl;
		}
		savef.close();
		cout<<endl<<"The game has been saved."<<endl;
	}
	void BoardArray1D::reset_correct()
	{
		int sayac = 0;
		
		string * temppuzzle1;
		temppuzzle1 = new string[row*column];
		for (int i = 0; i < total; ++i)
		{
			if(puzzle1[i] != "00" && puzzle1[i] != "bb")
			{
				temppuzzle1[sayac] = puzzle1[i];
				sayac++;
			}
		}
		
		for (int i = 0; i < sayac; ++i)
		{
			int j;
			string key;
			key = temppuzzle1[i];
			j = i-1;
			while(j>=0 && temppuzzle1[j] > key)
			{
				temppuzzle1[j+1] = temppuzzle1[j];
				j=j-1;
			}
			temppuzzle1[j+1]=key;
		}
		sayac = 0;
		for (int i = 0; i < total; ++i)
		{
			if (puzzle1[i] == "00")
			{
				correctpuzzle1[i]=puzzle1[i];
			}
			else
			{
				correctpuzzle1[i] = temppuzzle1[sayac];
				sayac++;
			}
		}
		correctpuzzle1[total-1]= "bb";
	}
	void BoardArray1D::reset()
	{
		reset_correct();
		for (int i = 0; i < total; ++i)
		{
			puzzle1[i] = correctpuzzle1[i];
		}				
	}	
	void BoardArray1D::move(char movee)
	{
		lastmovee = movee;
		
		switch(movee)
		{
			case 'R':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i]=="bb")
						{
							if(puzzle1[i+1]!= "00"  && (i+1)%row != 0)
							{
								puzzle1[i] = puzzle1[i+1];
								puzzle1[i+1] ="bb";
								i=total; 
								totalmoves1D++;
							}
							else
								cout<<"this move (R) can not be made"<<endl;
						}
					}
			break;
			case 'L':
					
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i]=="bb")
						{
							if(puzzle1[i-1]!= "00"  && i%row != 0)
							{
								puzzle1[i] = puzzle1[i-1];
								puzzle1[i-1] ="bb";
								i=total;
								totalmoves1D++;
							}
							else
								cout<<"this move (L) can not be made"<<endl;
						}
					}
			break;
			case 'U':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i]=="bb")
						{
							if(puzzle1[i-row]!= "00"  && i>row)
							{
								puzzle1[i] = puzzle1[i-row];
								puzzle1[i-row] ="bb";
								i=total;
								totalmoves1D++; 
							}
							else
								cout<<"this move (U) can not be made"<<endl;
						}
					}
			break;
			case 'D':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzle1[i]=="bb")
						{
							if(puzzle1[i+row]!= "00"  && i<(row*(column-1)))
							{
								puzzle1[i] = puzzle1[i+row];
								puzzle1[i+row] ="bb";
								i=total;
								totalmoves1D++; 
							}
							else
								cout<<"this move (D) can not be made"<<endl;
						}
					}
			break;
			default:
					cout<<"INVALID CHOICE.."<<endl;
		}
	}	
	bool BoardArray1D::isSolved()
	{
		int finish;
		
		for (int i = 0; i < total; ++i)
		{
			if(puzzle1[i] == correctpuzzle1[i])
				{
					finish = 0;
				}
				else
				{ 
					finish = -1;
					i = total;
				}
		}
		if (finish == 0)
			return true;
		else
			return false;
	}
	void BoardArray1D::print()
	{
		int counter = 0;
		cout<<"---------------------------"<<endl;	
		for (int j = 0; j < column ; ++j) 
		{	
			for (int i = 0; i < row ; ++i)
			{
				cout <<puzzle1[counter]<<" ";
				counter++;
			}
			cout<<endl;
		}
	}
	char BoardArray1D::lastMove()
	{
		return lastmovee;
	}
	int BoardArray1D::numberOfMoves()
	{
		return totalmoves1D;
	}
}
