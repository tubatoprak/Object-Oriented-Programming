#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>

using namespace std;

void print_puzzle(int puzzle[][9],int size);
void mix_puzzle(int puzzle[][9],int temp[],int size);
void initial_correctpuzzle(int correct_puzzle[][9],int size);
int finishcontrol(int puzzle[][9],int correct_puzzle[][9],int size1, int size2);

int main()
{
	int size = 0;
	char move;
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
	int totalmoves=0;
	int temp[size*size];
	int stop=0,stops=0; 
	int tempS=0;
	srand(time(NULL));
	int finish = 0;

	while(stops!=1)
	{               						 //Loop for a new game when the game is over.
		cout<<"Your initial random board is "<<endl;
		mix_puzzle(puzzle,temp,size);  //firstly,the puzzle gives a random number.
		initial_correctpuzzle(goalstatepuzzle,size); // for correct puzzle   
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
						for ( i = 0; i < size; ++i)
						{
						    for ( j = 0; j < size; ++j)
						    {
						        if (puzzle[i][j] == 0) 	//move is finding its place.
						        {
						            if (j == 0)   //L checks if the movement is appropriate
						                cout<<"This move cannot be made."<<endl;
						            else
						            {					//swap doing
						                int temp;
						                temp = puzzle[i][j-1];
						                puzzle[i][j-1] = puzzle[i][j];
						                puzzle[i][j] = temp;
						                totalmoves++; // for print total moves in final 
						            }   
						        }
						    }
						}
					break;
				case 'R':
						for (  i = 0 ; i < size; ++i)
						{
							for (  j = 0; j < size; ++j)
							{
								if (puzzle[i][j]==0)
								{
									if (j==size-1)
										cout<<"This move cannot be made."<<endl;
									else
									{
										puzzle[i][j] = puzzle[i][j+1];
										puzzle[i][j+1] = 0;
										totalmoves++;
									}
									i=j=size;	
								}
							}
						}
						
					break;	
				case 'D':
						for ( i = 0; i < size; ++i)
						{
							for ( j = 0; j < size; ++j)
							{
								if (puzzle[i][j] == 0)
								{	
									if (i == size-1)
										cout<<"This move cannot be made."<<endl;
									else
									{
										int temp=0;
										temp = puzzle[i][j];
										puzzle[i][j] = puzzle[i+1][j];
										puzzle[i+1][j] = temp;
										totalmoves++;
									}
									i = j = size;
								}
							}
						}
					
					break;
				case 'U':
						for ( i = 0; i < size; ++i)
						{
							for ( j = 0; j < size; ++j)
							{
								if (puzzle[i][j] == 0)
								{ 
									if (i == 0)
										cout<<"This move cannot be made."<<endl;
									else
									{
										int temp;
										temp = puzzle[i-1][j];
										puzzle[i-1][j] = puzzle[i][j];
										puzzle[i][j] = temp;
										totalmoves++;
									}	
								}
							}
						}
					break;
				case 'S':

						for ( y = 0; y < size; ++y) //takes the board to the final solution,
						{
							for ( z = 0; z < size; ++z)
							{
								if(y == size-1 && z == size-1)
								{
									puzzle[y][z]=0;
								}
								else{
									puzzle[y][z]=size*y+z+1;
								}
							}
						}
						tempS=0;
						while(tempS<size*size)  //size*size random move doing.
						{	
							for ( i = 0; i < size; ++i)
							{
								for ( k = 0; k < size; ++k)
								{
									if(puzzle[i][k]==0)  //It records the movements it can make and assigns them into the array.
									{
										char hamle[4];
										if(i-1>=0){
											hamle[0]='U';
										}
										else{
											hamle[0]='Z';
										}
										if(i+1<size){
											hamle[1]='D';
										}
										else{
											hamle[1]='Z';
										}
										if(j-1>=0){
											hamle[2]='L';
										}
										else{
											hamle[2]='Z';
										}
										if(j+1<size){
											hamle[3]='R';
										}
										else{
											hamle[3]='Z';
										}
										int rand2=rand()%4;
										
										while(hamle[rand2]=='Z'){
											rand2=rand()%4;
										}
										if(rand2==0)
										{
											for ( i = 0; i < size; ++i)
											{
												for ( j = 0; j < size; ++j)
												{
													if (puzzle[i][j] == 0)
													{ 
														if (i != 0)
														{
															int temp;
															temp = puzzle[i-1][j];
															puzzle[i-1][j] = puzzle[i][j];
															puzzle[i][j] = temp;
														}	
													}
												}
											}
										}
										if(rand2==1)
										{
											for ( i = 0; i < size; ++i)
											{
												for ( j = 0; j < size; ++j)
												{
													if (puzzle[i][j] == 0)
													{	
														if (i != size-1)
														{
															int temp=0;
															temp = puzzle[i][j];
															puzzle[i][j] = puzzle[i+1][j];
															puzzle[i+1][j] = temp;
														}
														i = j = size;
													}
												}
											}
										}
										if(rand2==2)
										{
											for ( i = 0; i < size; ++i)
											{
												for ( j = 0; j < size; ++j)
												{
													if (puzzle[i][j]==0)
													{
														if (j!=0)
														{
															int temp;
															temp = puzzle[i][j-1];
															puzzle[i][j-1] = puzzle[i][j];
															puzzle[i][j] = temp;
														}	
													}
												}
											}
										}
										if(rand2==3)
										{
											for (int i = 0; i < size; ++i)
	                                        {
	                                            for (int j = 0; j < size; ++j)
	                                            {
	                                                if (puzzle[i][j]!=0)
	                                                {
	                                                    if (j==size-1)
	                                                    {
	                                                        puzzle[i][j] = puzzle[i][j+1];
	                                                        puzzle[i][j+1] = 0;
	                                                    }
	                                                    i=j=size;   
	                                                }
	                                            }
	                                        }
										}				
									}
								}
							}
							tempS++;
						}
						totalmoves++;
					break;
				case 'Q':
						stop = 1;
						stops = 1;
					break;
				case 'I':
						/*for (int i = 0; i < size; ++i)
						{
							for (int k = 0; k < size; ++k)
							{
								if(puzzle[i][k] = 0)
								{
									if( puzzle[0][0] = 0  && puzzle[0][size-1] = 0)
									{

									}
								}
							}
						}*/
					break;
				default:
						cout<<endl<<"In valid choice !!"<<endl;
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




















