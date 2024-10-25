#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void print_puzzle(int puzzle[][9],int size); //for print puzzle
void mix_puzzle(int puzzle[][9],int temp[],int size); //for taking random number in board.
void move_l(int puzzle[][9],int size); 
void move_r(int puzzle[][9],int size); 
void move_u(int puzzle[][9],int size); 
void move_d(int puzzle[][9],int size); 
void move_s(int puzzle[][9],int size,int size1); 

void move_i(int puzzle[][9],int correct_puzzle[][9],int size,int size1);
int find_distance(int puzzle[][9],int correct_puzzle[][9],int size,int size1); //to find distance  between series number board and random number board. 
void move_v(int puzzle[][9],int correct_puzzle[][9],int size,int size1);
void initial_correctpuzzle(int correct_puzzle[][9],int size); //placed to correct board. 
int finishcontrol(int puzzle[][9],int correct_puzzle[][9],int size1, int size2);

void string_move_r(string * puzzle1,int total,int row);
void string_move_l(string * puzzle1,int total,int row);
void string_move_d(string * puzzle1,int total,int row,int column);
void string_move_u(string * puzzle1,int total,int row);
void string_move_s(string * puzzle1,string *correctpuzzle1,int row,int column,int total);
void string_move_i(string * puzzle1,string *correctpuzzle1,int row,int column,int total);
void string_move_v(string * puzzle1,string *correctpuzzle1,int row,int column,int total);
void initial_correctstring(string * puzzle1,string * correctpuzzle1,int total);
void print(string * puzzle1,int column,int row);
int find_distance_string(string * puzzle1,string * correctpuzzle1,int total);
int finishcontrol_string(string * puzzle1,string *correctpuzzle1,int total);

int main(int argc, char *argv[])
{
	string filename; // to read from file 
	string fileEE;
	ifstream fileName;
	ofstream fileE;
	
	string str;
	string puzzle1[81],correctpuzzle1[81];
	string line;
	int size = 0;
	char move;
	int hw_control = 0;
	cout << "Please enter the problem size: ";
	cin >> size;
	while (2 >= size || size >1000)
	{
		cout<<"Please enter valid size."<<endl;
		cout << "Please enter the problem size: ";
		cin >> size;
	}
	int puzzle[size][9],goalstatepuzzle[size][9];
	int i,k,j,y,z;  //for loops  
	int totalmoves = 0,totalmovesstring = 0;
	int temp[size*size];
	int stop=0,stops=0; 
	int tempS=0;
	srand(time(NULL));
	int finish = 0;
	int column = 0,temps1,rand2,sayac=0;
	int row;
	char move_string;
	int total = 0;
	int stop_string=0;
	int sayac1=0;
	while(stops!=1)
	{               						 //Loop for a new game when the game is over.
		cout<<"Your initial random board is "<<endl;
		mix_puzzle(puzzle,temp,size);  //firstly,the puzzle gives a random number.
		initial_correctpuzzle(goalstatepuzzle,size);
		initial_correctpuzzle(puzzle,size);
		move_s(puzzle,size,(size+3));
		finish = tempS = totalmoves =0;
		stop=0;
		while(stop!=1) // a loop for the progress of the game - for move 
		{
			print_puzzle(puzzle,size); 
			cout<<"Your move : ";	
			cin>>move;			//this game move character is 0.but 0 does not appear. clearance will appear
			switch(move)
			{
				case 'L' :
						move_l(puzzle,size);
						totalmoves++;
					break;
				case 'R':
						move_r(puzzle,size);
						totalmoves++;
					break;	
				case 'D':
						move_d(puzzle,size);
						totalmoves++;
					break;
				case 'U':
						move_u(puzzle,size);
						totalmoves++;
					break;
				case 'S':
						initial_correctpuzzle(puzzle,size);
						move_s(puzzle,size,size);
						totalmoves++;
					break;
				case 'Q':
						stop = 1;
						stops = 1;
					break;
				case 'I':
						move_i(puzzle,goalstatepuzzle,size,size);
						totalmoves++;
					break;
				case 'V' :
						move_v(puzzle,goalstatepuzzle,size,size);
						totalmoves++;
					break;
				case 'Y':			
						if(argc==2)	
						{
							filename = argv[1];
							hw_control = 1;
						}
							if(hw_control)
							{
								cout<<"starting game.."<<endl;	
								fileName.open(filename.c_str());
									if(fileName.is_open())
									{
										while(getline(fileName,line))
										{
											column++;
										}								
										fileName.clear();
										fileName.seekg( 0, std::ios::beg);			
										while(!fileName.eof() && total < 100)
										{
											fileName >>str;
											puzzle1[i] = str;
											i++;
											total++;
										}
									}
									row = total/column;
									cout <<endl;
									int temp=0;
								print(puzzle1,column,row);
								while(stop_string!=1)
								{
									cout<<"enter move: ";
									cin >>move_string;
									switch(move_string)
									{
										case 'R':
												string_move_r(puzzle1,total,row);
												totalmovesstring++;
											break;
										case 'L':
												string_move_l(puzzle1,total,row);
												totalmovesstring++;
											break;
										case 'U':
												string_move_u(puzzle1,total,row);
												totalmovesstring++;
											break;
										case 'D':
												string_move_d(puzzle1,total,row,column);
												totalmovesstring++;
											break;
										case 'S':
												string_move_s(puzzle1,correctpuzzle1,row,column,total);
												totalmovesstring++;
											break;
										case 'Q':
												stop_string=1;
											break;
										case 'I':
												string_move_i(puzzle1,correctpuzzle1,row,column,total);
												totalmovesstring++;
											break;
										case 'V':
												string_move_v(puzzle1,correctpuzzle1,row,column,total);
												totalmovesstring++;
											break;
										case 'E':
												cout<<"Enter File Name :";
												cin>>fileEE;
												fileE.open(fileEE.c_str());
												temp=0;
												for (int j = 0; j < column ; ++j) 
												{	
													for (int i = 0; i < row ; ++i)
													{
														fileE << puzzle1[temp]<<" ";
														temp++;
													}
													fileE<<endl;
												}
												cout<<endl<<"The game has been saved."<<endl;
											break;	
										case 'T':
												cout<<"problem not solved"<<endl;
												cout<<"Total numbers of moves: "<<totalmovesstring<<endl;
											break;
										default:
												cout<<"Invalid choice.."<<endl;
											break;
									}
									int finish_string;
									
									finish_string = finishcontrol_string(puzzle1,correctpuzzle1,total);
									if (finish_string == 0)
									{
										print(puzzle1,column,row);
										cout<<endl<<"problem solved.."<<endl;
										stop_string = 1;
										stop = 1;
									}
									else
									print(puzzle1,column,row);
								}
								fileName.close();
							} 
					break;
				case 'E':
						cout<<"Enter File Name :";
						cin>>fileEE;
						fileE.open(fileEE.c_str());
						
						for (int i = 0; i <size; ++i)
						{
							for (int j = 0; j < size; ++j)
							{
								if(puzzle[i][j] ==0)
									fileE << "   ";
								else
								{
									fileE << puzzle[i][j];
									if (puzzle[i][j]<10)
									{
										fileE << "  ";
									}
									else if (puzzle[i][j]>=10)
									{
										fileE << " ";
									}
								}
								fileE << " ";
							}
							fileE << endl;
						}
						fileE.close();
						cout<<endl<<"The game has been saved."<<endl;
					break;
				case 'T':
						finish = finishcontrol(puzzle,goalstatepuzzle,size,size); //checks whether it is correct.
						if(finish == 0)
						{
							cout<<endl<<"problem solved.."<<endl;
							cout<<"Total numbers of moves: "<<totalmoves<<endl;
							stop = 1;
						}
						else
							cout<<"problem not solved"<<endl;
							cout<<"Total numbers of moves: "<<totalmoves<<endl;
					break;
				default:
						cout<<endl<<"Invalid choice !!"<<endl;
					break;
			}

			finish = finishcontrol(puzzle,goalstatepuzzle,size,size); //checks whether it is correct.
			if(finish == 0)
			{
				print_puzzle(puzzle,size);
				cout<<endl<<"problem solved.."<<endl;
				cout<<"Total numbers of moves: "<<totalmoves<<endl;
				cout<<"NEW GAME STARTING..."<<endl;
				stop = 1;
			}
		}
	}

	return 0 ;
}

void move_l(int puzzle[][9],int size)
{
	for ( int i = 0; i < size; ++i)
	{
	    for ( int j = 0; j < size; ++j)
	    {
	        if (puzzle[i][j] == 0) 	
	        {
	            if (j == 0)   
	                cout<<"This move(L) cannot be made."<<endl;
	            else
	            {					
	                int temp;
	                temp = puzzle[i][j-1];
	                puzzle[i][j-1] = puzzle[i][j];
	                puzzle[i][j] = temp;
	                //totalmoves++;  
	            }   
	        }
	    }
	}
}
void move_r(int puzzle[][9],int size)
{
	for ( int i = 0 ; i < size; ++i)
	{
		for ( int j = 0; j < size; ++j)
		{
			if (puzzle[i][j]==0)
			{
				if (j==size-1)
					cout<<"This move(R) cannot be made."<<endl;
				else
				{
					puzzle[i][j] = puzzle[i][j+1];
					puzzle[i][j+1] = 0;
					//totalmoves++;
				}
				i=j=size;	
			}
		}
	}
}
void move_d(int puzzle[][9],int size)
{
	for ( int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (puzzle[i][j] == 0)
			{	
				if (i == size-1)
					cout<<"This move(D) cannot be made."<<endl;
				else
				{
					int temp=0;
					temp = puzzle[i][j];
					puzzle[i][j] = puzzle[i+1][j];
					puzzle[i+1][j] = temp;
					//totalmoves++;
				}
				i = j = size;
			}
		}
	}
}
void move_u(int puzzle[][9],int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (puzzle[i][j] == 0)
			{ 
				if (i == 0)
					cout<<"This move(U) cannot be made."<<endl;
				else
				{
					int temp;
					temp = puzzle[i-1][j];
					puzzle[i-1][j] = puzzle[i][j];
					puzzle[i][j] = temp;
					//totalmoves++;
				}	
			}
		}
	}
}
void move_s(int puzzle[][9],int size,int size1)
{
	initial_correctpuzzle(puzzle,size);
	int tempS=0;
	while(tempS<size*size1)  //size*size random move doing.
	{	
		for ( int i = 0; i < size; ++i)
		{
			for ( int k = 0; k < size; ++k)
			{
				if(puzzle[i][k] == 0)  //It records the movements it can make and assigns them into the array.
				{
					char hamle[4];
					
					if(i != 0){
						hamle[0]='U';
					}
					else{
						hamle[0]='Z';
					}
					if(i != size-1){
						hamle[1]='D';
					}
					else{
						hamle[1]='Z';
					}
					if(k != 0){
						hamle[2]='L';
					}
					else{
						hamle[2]='Z';
					}
					if( k != size-1){
						hamle[3]='R';
					}
					else{
						hamle[3]='Z';
					}
					int rand2=rand()%4;
					
					while(hamle[rand2]=='Z')
					{
						rand2=rand()%4;
					}
					if(rand2==0)
					{
						move_u(puzzle,size);
					}
					if(rand2==1)
					{
						move_d(puzzle,size);
					}
					if(rand2==2)
					{
						move_l(puzzle,size);
					}
					if(rand2==3)
					{
						move_r(puzzle,size);		
					}
				}
			}
		}
		tempS++;
	}
}
int find_distance(int puzzle[][9],int correct_puzzle[][9],int size,int size1)
{
	int distance=0,l; 
	for (int  k= 0 ; k < size ; k++)
	{
		for (int  l = 0; l < size ; ++l)
		{
			if (correct_puzzle[k][l] != puzzle[k][l])
			{
				
				for (int a = 0 ; a <size ; ++a)
				{
					for (int b = 0 ; b <size ; ++b)
					{
						if (correct_puzzle[k][l] >= puzzle[a][b])
						{
							distance += abs(k-a)+ abs(l-b);
							a = b = size;
						}
					}
				}
			}
		}
	}
	return distance;
}
void move_i(int puzzle[][9],int correct_puzzle[][9],int size,int size1)
{	
	int distance[4],temp=0;	
	for (int i = 0; i < 4; ++i)
		distance[i]=0;
	for (int i = 0; i < size; ++i)
	{
		for (int k = 0; k < size; ++k)
		{
			if( puzzle[i][k] == 0)
			{
				if(i != 0)
				{
					move_u(puzzle,size);
					distance[1]= find_distance(puzzle,correct_puzzle,size,size);
					move_d(puzzle,size);
				}
				else
					distance[1] = 81;
				
				if(k != 0)
				{	
					move_l(puzzle,size);
					distance[0] = find_distance(puzzle,correct_puzzle,size,size);
					move_r(puzzle,size);
				}
				else
					distance[0] = 81;
				
				if (k != size-1)
				{
					move_r(puzzle,size);
					distance[2] = find_distance(puzzle,correct_puzzle,size,size);
					move_l(puzzle,size);
				}
				else
					distance[2] = 81;
				
				if (i != size-1)
				{
					move_d(puzzle,size);
					distance[3] = find_distance(puzzle,correct_puzzle,size,size);
					move_u(puzzle,size);
				}
				else
					distance[3] = 81;
				k = i = size;
			}					
		}
	}	
	temp = distance[0];
	
	for (int i = 0; i < 4; ++i)	
		if(temp > distance[i])
			temp = distance[i];	
	
	if(temp == distance[0] && temp == distance[1] && temp == distance[2] && temp == distance[3] )
	{

	}	
	if(temp == distance[0])
		move_l(puzzle,size);
	else if(temp == distance[1])
		move_u(puzzle,size);
	else if(temp == distance[2])
		move_r(puzzle,size);
	else 
		move_d(puzzle,size);	
}
void move_v(int puzzle[][9],int correct_puzzle[][9],int size,int size1)
{
	int finish = 1;
	
	while(finish !=0)
	{
		move_s(puzzle,size,1);
		move_i(puzzle,correct_puzzle,size,size);
		finish = finishcontrol(puzzle,correct_puzzle,size,size); //checks whether it is correct.
	}
}
void print_puzzle(int puzzle[][9],int size)
{
	for (int i = 0; i <size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(puzzle[i][j] ==0)
					cout << "   ";
				else
				{
					cout << puzzle[i][j];
					if (puzzle[i][j]<10)
					{
						cout << "  ";
					}
					else if (puzzle[i][j]>=10)
					{
						cout << " ";
					}
				}
				cout << " ";
			}
			cout << endl;
		}
}
void mix_puzzle(int puzzle[][9],int temp[],int size)
{	
	int i,j,m=0,temp1; 
	
	for(i = 0 ; i < size*size ; i++)
         temp[i] = i;

    for(i = 0 ; i < size*size ; i++)
    {
         j = i + rand()/(RAND_MAX/(size*size-i) + 1);
         temp1 = temp[j];
         temp[j] = temp[i];
         temp[i] = temp1;
    }

    for(i = 0 ; i < size ; i++)
    {
        for(j = 0; j < size ; j++)
        {
            puzzle[i][j] = temp[m++];
        }
    }
}
int finishcontrol(int puzzle[][9],int correct_puzzle[][9],int size1,int size2)
{
	int finish = 0;
	
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j <size2; ++j)
		{
			if(puzzle[i][j] == correct_puzzle[i][j])
			{
				finish = 0;
			}
			else
			{ 
				finish = -1;
				j = i = size1;
			}
		}
	}
	return finish;
}
void initial_correctpuzzle(int correct_puzzle[][9],int size)
{
	int i,j, goal = 1;
    for ( i = 0; i < size; ++i)
    {
    	for ( j = 0 ; j < size; ++j)
    	{
    		correct_puzzle[i][j] = goal;
    		goal++;
    	}
    }
    correct_puzzle[size-1][size-1] = 0;
}
void print(string * puzzle1,int column,int row)
{	
		int temp=0;
		for (int j = 0; j < column ; ++j) 
		{	
			for (int i = 0; i < row ; ++i)
			{
				cout << puzzle1[temp]<<" ";
				temp++;
			}
			cout<<endl;
		}
}
void initial_correctstring(string * puzzle1,string *correctpuzzle1,int total)
{
	int sayac = 0;
	string temppuzzle1[81];
	
	for (int i = 0; i < total; ++i)
	{
		if(puzzle1[i] != "00" && puzzle1[i] != "bb")
		{
			temppuzzle1[sayac] = puzzle1[i];
			sayac++;
		}
	}
	
	for (int i = 0; i < sayac-1; ++i)
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
	correctpuzzle1[total-2]= "bb";
}

int finishcontrol_string(string * puzzle1,string *correctpuzzle1,int total)
{
	int finish = 0;
	
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
	return finish;
}
void string_move_r(string * puzzle1,int total,int row)
{
		for (int i = 0; i < total-1; ++i)
		{
			if(puzzle1[i]=="bb")
			{
				if(puzzle1[i+1]!= "00"  && (i+1)%row != 0)
				{
					puzzle1[i] = puzzle1[i+1];
					puzzle1[i+1] ="bb";
					i=total; 
				}
				else
					cout<<"this move (R) can not be made"<<endl;
			}
		}
}
void string_move_l(string * puzzle1,int total,int row)
{
	for (int i = 0; i < total-1; ++i)
	{
		if(puzzle1[i]=="bb")
		{
			if(puzzle1[i-1]!= "00"  && i%row != 0)
			{
				puzzle1[i] = puzzle1[i-1];
				puzzle1[i-1] ="bb";
				i=total; 
			}
			else
				cout<<"this move (L) can not be made"<<endl;
		}
	}
}
void string_move_u(string * puzzle1,int total,int row)
{
	for (int i = 0; i < total-1; ++i)
	{
		if(puzzle1[i]=="bb")
		{
			if(puzzle1[i-row]!= "00"  && i>row)
			{
				puzzle1[i] = puzzle1[i-row];
				puzzle1[i-row] ="bb";
				i=total; 
			}
			else
				cout<<"this move (U) can not be made"<<endl;
		}
	}
}
void string_move_d(string * puzzle1,int total,int row,int column)
{
	for (int i = 0; i < total-1; ++i)
	{
		if(puzzle1[i]=="bb")
		{
			if(puzzle1[i+row]!= "00"  && i<(row*(column-1)))
			{
				puzzle1[i] = puzzle1[i+row];
				puzzle1[i+row] ="bb";
				i=total; 
			}
			else
				cout<<"this move (D) can not be made"<<endl;
		}
	}
}
void string_move_s(string * puzzle1,string *correctpuzzle1,int row,int column,int total)
{
	initial_correctstring(puzzle1,correctpuzzle1,total);
	for (int i = 0; i < total; ++i)
	{
		puzzle1[i] = correctpuzzle1[i];
	}
	int temps = 0;
	
	while(temps <9)
	{
		for (int i = 0; i < total; ++i)
		{
			if(puzzle1[i] =="bb")
			{
				char hamle[4];
				
				if(puzzle1[i+1]!= "00"  && (i+1)%row != 0)
				{
					hamle[0]='R';
				}
				else
					hamle[0]='Z';
				if (puzzle1[i-1]!= "00"  && i%row != 0)
				{
					hamle[1] = 'L';
				}else
					hamle[1]='Z';
				if (puzzle1[i-row]!= "00"  && i>row)
				{
					hamle[2] = 'U';
				}else
					hamle[2]='Z';
				if (puzzle1[i+row]!= "00"  && i<(row*(column-1)))
				{
					hamle[3] = 'D';
				}
				else
					hamle[3]='Z';
				int rand2=rand()%4;

				while(hamle[rand2]=='Z')
				{
					rand2=rand()%4;
				}
				if (rand2 == 0)
				{
					string_move_r(puzzle1,total,row);
				}
				if (rand2 == 1)
				{
					string_move_l(puzzle1,total,row);
				}
				if(rand2 == 2)
				{
					string_move_u(puzzle1,total,row);
				}
				if (rand2 == 3)
				{
					string_move_d(puzzle1,total,row,column);
				}
			}
		}
		temps++;
	}
}
int find_distance_string(string * puzzle1,string * correctpuzzle1,int total)
{
	int distance = 0;
	
	for (int i = 0; i < total; ++i)
	{
		if (puzzle1[i] != correctpuzzle1[i])
		{
			for (int a = 0; a < total; ++a)
			{
				if (puzzle1[i] == correctpuzzle1[a])
				{
					distance += abs(i-a);
					a=total;
				}
			}
		}
	}
	return distance;
}
void string_move_i(string * puzzle1,string *correctpuzzle1,int row,int column,int total)
{
	int distance[4],temp=0;	
	
	for (int i = 0; i < 4; ++i)
		distance[i]=0;
	
	for (int i = 0; i < total; ++i)
	{
		if(puzzle1[i] =="bb")
		{	
			if(puzzle1[i+1]!= "00"  && (i+1)%row != 0)
			{
				string_move_r(puzzle1,total,row);
				distance[0] = find_distance_string(puzzle1,correctpuzzle1,total);
				string_move_l(puzzle1,total,row);
			}
			else
				distance[0] = 200;
			
			if (puzzle1[i-1]!= "00"  && i%row != 0)
			{
				string_move_u(puzzle1,total,row);
				distance[1] = find_distance_string(puzzle1,correctpuzzle1,total);
				string_move_d(puzzle1,total,row,column);
			}
			else
				distance[1] = 200;

			if (puzzle1[i-row]!= "00"  && i>row)
			{
				string_move_l(puzzle1,total,row);
				distance[2] = find_distance_string(puzzle1,correctpuzzle1,total);
				string_move_r(puzzle1,total,row);
			}
			else
				distance[2] = 200;

			if (puzzle1[i+row]!= "00"  && i<(row*(column-1)))
			{
				string_move_d(puzzle1,total,row,column);
				distance[3] = find_distance_string(puzzle1,correctpuzzle1,total);
				string_move_u(puzzle1,total,row);
			}
			else
				distance[3]=200;	
		}
	}
	temp = distance[0];
	/*for (int i = 0; i < 4; ++i)
	{
		cout<<"***"<<distance[i];
	}*/
	for (int i = 0; i < 4; ++i)	
		if(temp > distance[i])
			temp = distance[i];	
	
	if(temp == distance[0] && temp == distance[1] && temp == distance[2] && temp == distance[3] )
	{

	}	
	if(temp == distance[0])
		string_move_r(puzzle1,total,row);
	else if(temp == distance[1])
		string_move_u(puzzle1,total,row);
	else if(temp == distance[2])
		string_move_l(puzzle1,total,row);
	else if (temp == distance[3])
		string_move_d(puzzle1,total,row,column);
}
void string_move_v(string * puzzle1,string *correctpuzzle1,int row,int column,int total)
{
	int finish = 1;
	int counter=0;
	while(finish !=0)
	{
		//string_move_i(puzzle1,correctpuzzle1,row,column,total);
		string_move_s(puzzle1,correctpuzzle1,row,column,total);
		counter +=3;
		finish = finishcontrol_string(puzzle1,correctpuzzle1,total);
		 counter +=3;
	}
	cout<<"Game solved. Number of moves made : "<<counter;
}















