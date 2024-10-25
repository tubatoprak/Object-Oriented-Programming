#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <fstream>

#include "abstractboard.h"
#include "boardvector.h"
#include "boardarray1d.h"
#include "boardarray2d.h"

using namespace NPuzzle;

using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
	int stop = 0;
	int r,c;
	srand(time(NULL));
	string takefile,savefile;
	if (argc == 2)
	{
		takefile =argv[1];
	}
	else
	{
		cout<<"Enter File Name:"<<endl;
		cin>>takefile;
	}
	BoardVector vec;
	BoardArray1D oneD;
	BoardArray2D twoD;
    
	vec.setSize(3,4);
	oneD.setSize(3,4);
	twoD.setSize(3,4);

	vec.readFromFile(takefile);
	oneD.readFromFile(takefile);
	twoD.readFromFile(takefile);
	
	int a =0;
	char movee ='S',lastmoves;
	
	cout<<"*****Vector Print*****"<<endl;
	vec.print();
	string deger;
	cout<<"starting Vector "<<endl;
	vec.move('R');
	vec.print();
	vec.move('L');
	vec.print();
	vec.move('U');
	vec.print();
	vec.move('D');;
	cout<<"number of moves: "<<vec.numberOfMoves()<<endl;
	cout<<"last move: "<<vec.lastMove()<<endl;
	cout<<"Operator(1,1): "<<vec(1,1)<<endl;
	cout<<"reset"<<endl;
	vec.reset();
	vec.print();
	savefile ="write.txt";
	vec.writeToFile(savefile);

	//**** 1D boyutlu denemek için açın.******

/*	cout<<"*****1D Print*****"<<endl;
	oneD.print();
	cout<<"starting 1D "<<endl;
	oneD.move('R');
	oneD.print();
	oneD.move('L');
	oneD.print();
	oneD.move('D');
	oneD.print();
	oneD.move('U');;
	cout<<"number of moves: "<<oneD.numberOfMoves()<<endl;
	cout<<"last move: "<<oneD.lastMove()<<endl;
	cout<<"Operator(1,1): "<<oneD(1,1)<<endl;
	cout<<"reset"<<endl;
	oneD.reset();
	oneD.print();
	savefile ="write.txt";
	oneD.writeToFile(savefile);

*/
	//****2  boyutlu denemek için açın.******

/*	cout<<"*****2D print****"<<endl;
	twoD.print();
	cout<<"starting 2D "<<endl;
	twoD.move('R');
	twoD.print();
	twoD.move('L');
	twoD.print();
	twoD.move('D');
	twoD.print();
	twoD.move('U');;
	cout<<"number of moves: "<<twoD.numberOfMoves()<<endl;
	cout<<"last move: "<<twoD.lastMove()<<endl;
	cout<<"Operator(1,1): "<<twoD(1,1)<<endl;
	cout<<"reset"<<endl;
	twoD.reset();
	twoD.print();
	savefile ="write.txt";
	twoD.writeToFile(savefile);
*/	

	return 0;
}

