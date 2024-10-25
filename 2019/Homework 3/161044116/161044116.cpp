#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class NPuzzle
{
	public:
		void print()
		{
			reach.print();
		}
		void printReport()
		{
			reach.printReport();
		}
		void readFromFile()
		{
			reach.readFromFile();
		}
		void writeToFile()
		{
			reach.writeToFile();
		}
		void shuffle()
		{
			reach.move_shuffle();
		}
		void reset()
		{
			reach.reset();
		}
		void setsize()
		{
			reach.setsize();
		}
		void moveRandom()
		{
			reach.moveRandom();
		}
		void moveIntelligent()
		{
			reach.moveIntelligent();
		}
		void move()
		{
			int stop=0;
			while(stop != 1)
			{
				cout<<"Your move : ";	
				cin>>movee;
				if (movee == 'Q')
				{
					stop = 1;
				}
				else
				{
					reach.move(movee);
					print();
				}
				int finish = reach.IsSolved();
				if(finish == 0)
				{
					stop = 1;
				}
			}
		}
		void solvePuzzle()
		{
			reach.Solvedpuzzle();
		}
		void takefilename(string takefile)
		{
			reach.takefilename(takefile);
		}
		void resetvariable()
		{
			reach.resetvariable();
		}
	private:
		char movee;
		class Board
		{
			public:
				void print();
				void printReport();
				void readFromFile();
				void writeToFile();
				void moveIntelligent();
				void reset();
				void setsize();
				void move(char movee);
				void move_shuffle();
				int IsSolved();
				void Solvedpuzzle();
				void moveRandom();
				void takefilename(string takefile);
				void resetvariable();
				
			private:
				
				int puzzle[9][9];
				int correctpuzzle[9][9];
				int size;
				
				string puzzle1[100];
				string correctpuzzle1[100];
				
				int row ;
				int column;
				int flag;
				int total;
				ofstream savef;
				string savefilename;
				ifstream file;
				string filename;
				string line,str;
				int totalmoves;
		};
	Board reach;	
};

void move_l(int puzzle[][9],int size);
void move_r(int puzzle[][9],int size);
void move_u(int puzzle[][9],int size);
void move_d(int puzzle[][9],int size);
void move_s(int puzzle[][9],int size,int size1);
void move_i(int puzzle[][9],int correct_puzzle[][9],int size,int size1);
int find_distance(int puzzle[][9],int correct_puzzle[][9],int size,int size1);
void move_v(int puzzle[][9],int correct_puzzle[][9],int size,int size1);

void string_move_r(string * puzzle1,int total,int row);
void string_move_l(string * puzzle1,int total,int row);
void string_move_d(string * puzzle1,int total,int row,int column);
void string_move_u(string * puzzle1,int total,int row);
void string_move_s(string * puzzle1,string *correctpuzzle1,int row,int column,int total,int loop);
void string_move_i(string * puzzle1,string *correctpuzzle1,int row,int column,int total);
void string_move_v(string * puzzle1,string *correctpuzzle1,int row,int column,int total);
int find_distance_string(string * puzzle1,string * correctpuzzle1,int total);

void NPuzzle::Board::resetvariable()
{
	row =0;
	column = 0;
	flag = 0;
	total = 0;
	totalmoves = 0;
}

void NPuzzle::Board::Solvedpuzzle()
{
	int finish = 1;
	int temp = 0;
	while(finish != 0)
	{
		reset();
		moveRandom();
		move('I');
		finish = IsSolved(); //checks whether it is correct.
		temp++;
		//totalmoves++;
	}
	totalmoves++;
	cout<<"The total movement of the 'v' move: "<<temp<<endl;
}
void NPuzzle::Board::print()
{
	int counter = 0;
	
	if(flag == 1)
	{	
		cout<<"---------------------------"<<endl;		
		for (int j = 0; j < column ; ++j) 
		{	
			for (int i = 0; i < row ; ++i)
			{
				cout << puzzle1[counter]<<" ";
				counter++;
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"----------------"<<endl;
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
}
void NPuzzle::Board::readFromFile()
{
	
	int i,t;
	//cout<<"Enter dosya adı:"<<endl;
	//cin>>filename;
	cout<<"starting game.."<<endl;	
	file.open(filename.c_str());
	if(file.is_open())
	{
		while(getline(file,line))
		{
			column++;
		}								
		file.clear();
		file.seekg( 0, std::ios::beg);			
		
		t=0;
		while(!file.eof() && total < 100)
		{
			file >>str;
			puzzle1[t] = str;
			t++;
			total++;
		}
	}
	row = total/column;
	cout <<endl;
}
void NPuzzle::Board::takefilename(string takefile)
{
	filename = takefile;
}
void NPuzzle::Board::writeToFile()
{
	cout<<"Enter File Name :";
	cin>>savefilename;
	savef.open(savefilename.c_str());
	
	for (int i = 0; i <size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(puzzle[i][j] ==0)
				savef << "   ";
			else
			{
				savef << puzzle[i][j];
				if (puzzle[i][j]<10)
				{
					savef << "  ";
				}
				else if (puzzle[i][j]>=10)
				{
					savef << " ";
				}
			}
			savef << " ";
		}
		savef << endl;
	}
	savef.close();
	cout<<endl<<"The game has been saved."<<endl;
}
void NPuzzle::Board::setsize()
{
	cout << "Please enter the problem size: ";
	cin >> size;
}

void NPuzzle::Board::reset()
{
	if(flag == 0)
	{
		int counter =1;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				puzzle[i][j] = counter;
				correctpuzzle[i][j] = counter;
				counter++;
			}
		}
		puzzle[size-1][size-1] = 0;
		correctpuzzle[size-1][size-1] = 0;
	}
	else  //doğru string
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
}
void NPuzzle::Board::move(char movee)
{
	switch(movee)
	{
		case 'R':
				if(flag == 0)
					move_r(puzzle,size);
				else
					string_move_r(puzzle1,total,row);
				totalmoves++;
		break;
		case 'L':
				if(flag == 0)
					move_l(puzzle,size);
				else
					string_move_l(puzzle1,total,row);
				totalmoves++;
		break;
		case 'U':
				if(flag == 0)
					move_u(puzzle,size);
				else
					string_move_u(puzzle1,total,row);
				totalmoves++;
		break;
		case 'D':
				if(flag == 0)
					move_d(puzzle,size);
				else
					string_move_d(puzzle1,total,row,column);
				totalmoves++;
		break;
		case 'I':
				moveIntelligent();
				totalmoves++;
		break;
		case 'S':
				reset();
				move_shuffle();
				totalmoves++;
		break;
		case 'T':
				printReport();
		break;
		case 'V':
				//moveRandom();
				Solvedpuzzle();
		break;
		case 'O':
				readFromFile();
				flag = 1;
				totalmoves = 0;
				reset();
		break;
		case 'E':
				writeToFile();
		break;
		default:
				cout<<"INVALID CHOICE.."<<endl;
	}
}

void NPuzzle::Board::move_shuffle()
{
	if(flag == 0)
		move_s(puzzle,size,size);
	else
		string_move_s(puzzle1,correctpuzzle1,row,column,total,10);
}
void NPuzzle::Board::moveIntelligent()
{
	if(flag == 0)
		move_i(puzzle,correctpuzzle,size,size);
	else
		string_move_i(puzzle1,correctpuzzle1,row,column,total);
}

int NPuzzle::Board::IsSolved()
{
	int finish = 0;
	
	if(flag == 0)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j <size; ++j)
			{
				if(puzzle[i][j] == correctpuzzle[i][j])
				{
					finish = 0;
				}
				else
				{ 
					finish = -1;
					j = i = size;
				}
			}
		}
		return finish;
	}
	else
	{
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
}

void NPuzzle::Board::moveRandom()
{
	if(flag == 0)
		move_s(puzzle,size,2);
	else
	string_move_s(puzzle1,correctpuzzle1,row,column,total,3);	
}

void NPuzzle::Board::printReport()
{
	int finish =1;
	finish = IsSolved(); 
	if(finish == 0)
	{
		cout<<endl<<"Problem Solved.."<<endl;
		cout<<"Total Moves : "<<totalmoves<<endl; 
	}
	else
	{
		cout<<"Problem Not Solved..."<<endl;
		cout<<"Total Moves : "<<totalmoves<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int stop = 0;
	srand(time(NULL));
	string takefile;
	NPuzzle game;
	game.resetvariable();
	if (argc == 2)
	{
		takefile =argv[1];
		game.takefilename(takefile);
	}
	game.setsize();
	game.reset();
	game.shuffle();
	game.print();
	game.move();
	game.printReport();
	return 0;
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
	int tempS = 0;
	
	while(tempS < size1*size1)  //size*size random move doing.
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
void string_move_s(string * puzzle1,string *correctpuzzle1,int row,int column,int total,int loop)
{
	
	for (int i = 0; i < total; ++i)
	{
		puzzle1[i] = correctpuzzle1[i];
	}
	int temps = 0;
	
	while(temps < loop)
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
