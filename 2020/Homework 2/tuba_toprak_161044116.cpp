#include<iostream>
#include<string.h>
#include<fstream>
#include <stdlib.h>

using namespace std;
class ImageEditor
{
	public:
		
		ImageEditor()            //Constructor
		{
			width = 0;
			height = 0;
			size = 0;
		}
		int menu();
		void open_an_image();      //function to open file 
		void save_image_data();   //function to save a file
		int Scripts();           //function  to make grayscale 
		
	private:
		
		float image[100000];      //to save and process colors  
		string img[100000];	    //to save the entire file
		string file_type;
		

		int max_value;   			    //	max_value the image
		int width;       			   // width of the image
		int height;      			  // heigt of the image
		int size;	     			 // size of file
		string savefilename;        // to save a file
		ifstream file;		       // to save a file
		string filename;		  //  to take a file name
		string str;				 //  to read file 
};
int  ImageEditor::menu()
{
	int choiceMenu,choice; //to operate in the menus
	int loop = 0;  //top loop
	int temp = 0; //to loop
	
	while(loop == 0)  // the menu is displayed until the user wishes to exit
	{
		cout<<"MAIN MENU"<<endl;
		cout<<"0 - Exit"<<endl;
		cout<<"1 - Open An Image(D)"<<endl;
		cout<<"2 - Save Image Data(D)"<<endl;
		cout<<"3 - Scripts(D)"<<endl;
		cin>>choiceMenu;
		
		switch(choiceMenu) 
		{
			case 0: 
				loop = 1; //to return to the previous menu
			break;
			case 1: 
				temp = 0; // to loop
				while  (temp == 0) // the menu is displayed until the user wishes to the previous menu
				{
					cout<<"OPEN AN IMAGE MENU"<<endl;
					cout<<"0 - Up"<<endl;
					cout<<"1 -  Enter The Name Of The Image File"<<endl;
					cin>>choice;
					if(choice == 1)
					{
						open_an_image();
					}	
					else if (choice == 0)
						temp = 1;        //to return to the previous menu
					else 
						exit(0);
				}
			break;
			case 2: 
				temp = 0;
				while  (temp == 0)  // the menu is displayed until the user wishes to the previous menu
				{
					cout<<"SAVE IMAGE DATA MENU"<<endl;
					cout<<"0 - Up"<<endl;
					cout<<"1 -  Enter A File Name"<<endl;
					cin>>choice;
					if(choice == 1)
						save_image_data();
					else if (choice == 0)
					{
						temp = 1;     //to return to the previous menu
					}
					else 
						exit(0);
				}
			break;
			case 3:
				temp = 0;
				while(temp == 0) // the menu is displayed until the user wishes to the previous menu
				{
					cout<<"SCRIPTS MENU"<<endl;
					cout<<"0 - Up"<<endl;
					cout<<"1 - Convert To Grayscale(D)"<<endl;
					cin>>choice;
					if(choice == 1)
					{
						int temploop = 0; 
						while(temploop == 0)
						{
							cout<<"CONVERT TO GRAYSCALE MENU"<<endl;
							cout<<"0 - Up"<<endl;
							cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels"<<endl;
							cin>>choice;
							if(choice == 1)
								Scripts();
							else if (choice == 0)
								temploop = 1;   //to return to the previous menu
							else 
								exit(0);
						}
					}
					else if (choice == 0)
						temp = 1;           //to return to the previous menu
					else 
						exit(0);
				}	
			break;
			default :
				exit(0);
		}
	}	
}
void ImageEditor::open_an_image()
{
	cin>>filename;  
	file.open(filename);  //to open the file
	
	if(file.is_open())
	{	
		file >> file_type;     //file read (p3)
		file >>  height;	  //file read (4)
		file >> width;		 //file read (4)
		file >> max_value;	//file read (255)
		int t = 0;
		while(!file.eof())    
		{
			file >>str;
			img[t] = str; // saves the file in string
			t++;
		}
	    size = width*height*3; // find size of file  

		for (int i = 0; i < size; ++i)  
		{
			image[i] = stof(img[i]);  //stored in integer array to make color operations in the file
		}
	}
	else 
		exit(0);
	file.close();  
}

void ImageEditor::save_image_data()  //save file 
{
	cin>>savefilename;
	ofstream output;
	output.open(savefilename);  //opening file

	output<< file_type <<endl;     //saving  in file
	output<<width<<" "<<height<<endl;
	output<< max_value <<endl;

	for(int i = 0; i < size; i++)  // for loop to save the whole file
	{
		output << img[i] << " ";  //saving  in file
		if(size%3 == 2)	     //to the bottom line
		{
			output << endl;
		}
	}	
}	
int  ImageEditor::Scripts()
{
	int g;
	float c_r,c_g,c_b;    //to get  colors value from user 
	float red,green,blue;
	cin>>c_r >> c_g >> c_b;

	if(0 < c_r && c_r <=1 && 0 < c_g && c_g <=1 && 0 < c_b && c_b <=1)  //interval check
	{
		for (int i = 0; i < size; ++i)
		{	
			if(i % 3 == 0)    //to  every pixel is a byte
			{
				red   = (c_r * image[i]) + (c_g * image[i+1]) + (c_b * image[i+2]);
				green = (c_r * image[i]) + (c_g * image[i+1]) + (c_b * image[i+2]);
				blue  = (c_r * image[i]) + (c_g * image[i+1]) + (c_b * image[i+2]);
				
				if (red < 255 )  //for the condition written in pdf
				{
					red = 255;
				}
				if (green < 255 )
				{
					green = 255;
				}
				if (blue < 255 )
				{
					blue = 255;
				}

				image[i]   = red;  // values are changed
				image[i+1] = green;
				image[i+2] = blue;
			}
		}
		for (int i = 0; i < size; ++i)   //The operations were done in integer array. 
		{                               //To save the changed values in the file, saved in  the string
			img[i] = to_string(image[i]); 
		}
	}
	else 
		exit(0);
}

int main(int argc, char const *argv[])
{

	ImageEditor color;
	color.menu();
	
	return 0;
}