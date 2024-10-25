#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

#include "boardvector.h"

using std::cout;
using std::cin;

namespace NPuzzle
{	
	
	BoardVector::BoardVector(): AbstractBoard()
	{
		numberofboardss++;
		cout<<endl<<numberofboardss<<". VECTOR BOARD CREATED!!!"<<endl<<endl;
	}
	string BoardVector::operator ()(int x,int y)
	{
		return puzzlevector[x*y+y];
	}
	void BoardVector::readFromFile(string takefile)
	{
		filename = takefile;
	 	int i,t;
	 	string rowto;
	 	string temppuzzle[1000];	
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
			t=0;
			file.clear();
			file.seekg( 0, std::ios::beg);			

			while(file>>str)
			{
				temppuzzle[t] = str;
				t++;
			}
			t=0;
			string key;
			
			for (int i = 0; i < column; ++i)
			{
				for (int j = 0; j < row; ++j)
				{
					key = temppuzzle[t];
					puzzlevector.push_back(key);
					t++;
				}
			}
		}	
		cout <<endl;
	}
	void BoardVector::print()
	{
		int counter = 0;
		cout<<"---------------------------"<<endl;	
		for (int j = 0; j < column ; ++j) 
		{	
			for (int i = 0; i < row ; ++i)
			{
				cout <<puzzlevector[counter]<<" ";
				counter++;
			}
			cout<<endl;
		}
	}
		void BoardVector::setSize(int x ,int y)
	{
		cout<<"WORKING SETSIZE VECTOR FUNCTION.."<<endl;	
		
		int key =1;
		
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if(i ==(x-1) && j==(y-1))
					puzzlesize.push_back(0);
				else
				puzzlesize.push_back(key);
				/*cout<<puzzlesize[key]<<"  ";
				if(key<10)
					cout<<" ";*/
				key++;			
			}
		}
		key=0;
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				if (puzzlesize[key] ==0 )
				{
					cout<<"  ";
				}
				else
					cout<<puzzlesize[key]<<"  ";
				key++;
				if(key<10)
					cout<<" ";

			}
			cout<<endl;
		}

	}
	void BoardVector::reset_correct()
	{
		int sayac = 0;
		
		string  temppuzzle1[1000],correctpuzzle[1000];
		for (int i = 0; i < total; ++i)
		{
			if(puzzlevector[i] != "00" && puzzlevector[i] != "bb")
			{
				temppuzzle1[sayac] = puzzlevector[i];
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
			if (puzzlevector[i] == "00")
			{
				correctpuzzle[i]=puzzlevector[i];
			}
			else
			{
				correctpuzzle[i] = temppuzzle1[sayac];
				sayac++;
			}
		}
		correctpuzzle[total-1]= "bb";
		string key;
		
		for (int i = 0; i < total; ++i)
		{
			key = correctpuzzle[i];
			correctpuzzlevector.push_back(key);
		}
	}
	void BoardVector::reset()
	{
		reset_correct();
		for (int i = 0; i < total; ++i)
		{
			puzzlevector[i] = correctpuzzlevector[i];
		}
	}
	void BoardVector::move(char movee)
	{
		lastmovee = movee;
		
		switch(movee)
		{
			case 'R':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzlevector[i]=="bb")
						{
							if(puzzlevector[i+1]!= "00"  && (i+1)%row != 0)
							{
								puzzlevector[i] = puzzlevector[i+1];
								puzzlevector[i+1] ="bb";
								i=total; 
								totalmovesV++;
							}
							else
								cout<<"this move (R) can not be made"<<endl;
						}
					}
			break;
			case 'L':
					
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzlevector[i]=="bb")
						{
							if(puzzlevector[i-1]!= "00"  && i%row != 0)
							{
								puzzlevector[i] = puzzlevector[i-1];
								puzzlevector[i-1] ="bb";
								i=total;
								totalmovesV++;
							}
							else
								cout<<"this move (L) can not be made"<<endl;
						}
					}
			break;
			case 'U':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzlevector[i]=="bb")
						{
							if(puzzlevector[i-row]!= "00"  && i>row)
							{
								puzzlevector[i] = puzzlevector[i-row];
								puzzlevector[i-row] ="bb";
								i=total;
								totalmovesV++; 
							}
							else
								cout<<"this move (U) can not be made"<<endl;
						}
					}
			break;
			case 'D':
					for (int i = 0; i < total-1; ++i)
					{
						if(puzzlevector[i]=="bb")
						{
							if(puzzlevector[i+row]!= "00"  && i<(row*(column-1)))
							{
								puzzlevector[i] = puzzlevector[i+row];
								puzzlevector[i+row] ="bb";
								i=total;
								totalmovesV++; 
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
	bool BoardVector::isSolved()
	{
		int finish;
		
		for (int i = 0; i < total; ++i)
		{
			if(puzzlevector[i] == correctpuzzlevector[i])
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
	int BoardVector::numberOfMoves()
	{
		return totalmovesV;
	}
	char BoardVector::lastMove()
	{
		return lastmovee;
	}
	void BoardVector::writeToFile(string takefile)
	{
		savefilename = takefile;
		savef.open(savefilename.c_str());
		int temp =0;
		for (int i = 0; i <column; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				savef << puzzlevector[temp];
				savef << " ";
				temp++;
			}
			savef << endl;
		}
		savef.close();
		cout<<endl<<"The game has been saved."<<endl;
	}
}