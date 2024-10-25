#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <memory>

#include "boardarray2d.h"

using std::cout;
using std::cin;

namespace NPuzzle
{	
	BoardArray2D:: BoardArray2D(): AbstractBoard(){
		numberofboardss++;
		set_row_column( 3,3);
		reset_variable();
		cout<<endl<<numberofboardss<<". 2D BOARD CREATED!!!"<<endl<<endl;
	}
	string BoardArray2D::operator ()(int x,int y)
	{
		return puzzle2[x][y];
	}
	BoardArray2D::~BoardArray2D()
	{
		for(int i = 0; i < column; ++i){

			  delete [] puzzle2[i];
		}
		delete []puzzle2;

		for(int i = 0; i < column; ++i){

			  delete [] correctpuzzle2[i];
		}
		delete []correctpuzzle2;
	}
	void BoardArray2D::reset_variable()
	{
		puzzle2 = new string*[column];
		correctpuzzle2 = new string*[column];
		for (int i = 0; i < column; ++i)
		{
			puzzle2[i] = new string[row];
			correctpuzzle2[i] = new string[row];
		}
	}
	void BoardArray2D::setSize(int x ,int y)
	{
		puzzlesize = new int*[x*y];
		cout<<"WORKING SETSIZE  2D FUNCTION.."<<endl;
		for (int i = 0; i < x; ++i)
		{
			puzzlesize[i] = new int[y];
		}	
		int key =1;
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if(i==(x-1) && j ==(y-1))
					puzzlesize[x-1][y-1] = 0;
				else
				{
					puzzlesize[i][j] = key;
					cout<<puzzlesize[i][j]<<"  ";		
				}
				if(key<10)
					cout<<" ";
				key++;			
			}
			cout<<endl;
		}
	}
	void BoardArray2D::readFromFile(string takefile)
	{

		filename = takefile;
	 	int i,t;
	 	string rowto;
	 	string  temppuzzle[1000];	
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
				temppuzzle[t] = str;
				t++;
			}




			t = 0;
			string key;
			
			for (int i = 0; i < column; ++i)
			{
				for (int j = 0; j < row; ++j)
				{
					key = temppuzzle[t];
					puzzle2[i][j] = key;
					t++;
				}
			}
		}	
		cout <<endl;
		return;
	}
	void BoardArray2D::writeToFile(string takefile)
	{
		savefilename = takefile;
		savef.open(savefilename.c_str());
		int temp =0;
		for (int i = 0; i <column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				savef << puzzle2[i][j];
				savef << " ";
				temp++;
			}
			savef << endl;
		}
		savef.close();
		cout<<endl<<"The game has been saved."<<endl;
	}
	void BoardArray2D::print()
	{
		cout<<"---------------------------"<<endl;	
		for (int j = 0; j < column ; ++j) 
		{	
			for (int i = 0; i < row ; ++i)
			{
				cout <<puzzle2[j][i]<<" ";
			}
			cout<<endl;
		}
	}
	void BoardArray2D::reset_correct()
	{
		int sayac = 0;
		
		string * temppuzzle2;
		temppuzzle2 = new string[row*column];
		
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if(puzzle2[i][j]!= "00" && puzzle2[i][j]!= "bb")
				{
					temppuzzle2[sayac] = puzzle2[i][j];
					sayac++;
				}
			}
		}
		for (int i = 0; i < sayac; ++i)
		{
			int j;
			string key;
			key = temppuzzle2[i];
			j = i-1;
			while(j>=0 && temppuzzle2[j] > key)
			{
				temppuzzle2[j+1] = temppuzzle2[j];
				j=j-1;
			}
			temppuzzle2[j+1]=key;
		}

		sayac = 0;
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (puzzle2[i][j] == "00")
				{
					correctpuzzle2[i][j] = puzzle2[i][j];
				}
				else
				{
					correctpuzzle2[i][j] = temppuzzle2[sayac];
					sayac++;
				}
			}
			
		}
		correctpuzzle2[column-1][row-1]= "bb";
	}
	void BoardArray2D::reset()
	{
		reset_correct();
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				puzzle2[i][j] =correctpuzzle2[i][j];
			}
		}
	}
	bool BoardArray2D::isSolved()
	{
		int finish;
		
		for (int i = 0; i < column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if(puzzle2[i][j] == correctpuzzle2[i][j])
				{
					finish = 0;
				}
				else
				{ 
					finish = -1;
					i = total;
				}
			}
			
		}
		if (finish == 0)
			return true;
		else
			return false;
	}
	void BoardArray2D::move(char movee)
	{
		lastmovee = movee;
		string temp;
		switch(movee)
		{
			case 'R':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j]=="bb")
							{
								if(puzzle2[i][j+1]!= "00"  && j!=row-1)
								{
									puzzle2[i][j] = puzzle2[i][j+1];
									puzzle2[i][j+1] = "bb";
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									cout<<"this move (R) can not be made"<<endl;
							}
						}
					}
			break;
			case 'L':
					
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j]=="bb")
							{
								if(puzzle2[i][j-1]!= "00"  && j!=0)
								{
									temp;
					                temp = puzzle2[i][j-1];
					                puzzle2[i][j-1] = puzzle2[i][j];
					                puzzle2[i][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									cout<<"this move (L) can not be made"<<endl;
							}
						}
					}
			break;
			case 'U':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j]=="bb")
							{
								if(puzzle2[i-1][j]!= "00"  && i!=0)
								{
									cout<<"ceee";
									temp = puzzle2[i-1][j];
									puzzle2[i-1][j] = puzzle2[i][j];
									puzzle2[i][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									cout<<"this move (U) can not be made"<<endl;
							}
						}
					}
			break;
			case 'D':
					for (int i = 0; i < column; ++i)
					{
						for(int j= 0; j < row ; ++j)
						{
							if(puzzle2[i][j]=="bb")
							{
								if(puzzle2[i+1][j] != "00"  && i!=column-1)
								{
									temp = puzzle2[i][j];
									puzzle2[i][j] = puzzle2[i+1][j];
									puzzle2[i+1][j] = temp;
									i=column;
									j=row;
									totalmoves2D++;
								}
								else
									cout<<"this move (D) can not be made"<<endl;
							}
						}
					}
			break;
			default:
					cout<<"INVALID CHOICE.."<<endl;
		}
	}
	char BoardArray2D::lastMove()
	{
		return lastmovee;
	}
	int BoardArray2D::numberOfMoves()
	{
		return totalmoves2D;
	}
}