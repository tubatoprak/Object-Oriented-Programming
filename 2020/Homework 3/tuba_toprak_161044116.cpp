#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
using namespace std;
class ImageEditor
{
	public:
		
		ImageEditor()     //Constructors
		{
			size = 0;        //I can't reserve space for my arrays here because 
			width = 0;      //I don't know the size of the file, so when I read the file, I reserve it
			height = 0;
		}

		ImageEditor(const ImageEditor& object)  //Copy Constructors
		{
			file_type = object.file_type;    //to copy the datas
			size = object.size;
			width = object.width;
			height = object.height;
			max_value = object.max_value;
			image  = new float[size+1];
			img  = new string[size+1];
			for (int i = 0; i < size; ++i)
			{
				image[i] = object.image[i];
				img[i] = object.img[i];
			}
		}

		~ImageEditor()  //Destructor
		{
			delete [] image;  
			delete [] tempimage;
			delete [] img;
			image = nullptr;
			tempimage = nullptr;
			img = nullptr;
		}
		
		int menu();
		void open_an_image();      //function to open file
		void save_image_data();   //function to save a file
		int Scripts();           //function  to make grayscale 
		
		string  get_Filename() // to get filename 
		{
			return filename;
		}
		
		ImageEditor operator + ( const ImageEditor& object)const
		{
			ImageEditor tempObje;   //to create object with the collected datas
			tempObje.image  = new float[size+1]; //To allocate memory
			tempObje.img  = new string[size+1];	 //To allocate memory
			
			for (int i = 0; i <size; ++i)  //loop to collect data 
			{
				tempObje.image[i] = image[i] + object.image[i];
				if(tempObje.image[i] > 255)
					tempObje.image[i] = 255;
				tempimage[i] = tempObje.image[i];  //to copy the data
			}
			return tempObje; 
		} 

		ImageEditor& operator = (const ImageEditor& object); //assigment operator
		
	private:   
		string file_type;
		float * tempimage;
		float * image; 					  //to save and process colors 
		string* img;					 //to save the entire file
		int max_value;   			    //	max_value the image
		int width;       			   // width of the image
		int height;      			  // heigt of the image
		int size;	     			 // size of file
		string savefilename;        // to save a file
		ifstream file;		       // to save a file
		string filename;		  //  to take a file name
		string str;				 //  to read file 
};

ImageEditor& ImageEditor::operator = (const ImageEditor& object)
{
	file_type = object.file_type;   //Operations for the assignment operator
	size = object.size;
	width = object.width;
	height = object.height;
	max_value = object.max_value;
	
	for (int i = 0; i < size; ++i)  //to array
	{
		image[i] = object.image[i];
		img[i] =  object.img[i];
	}
	return *this;
}

int  ImageEditor::menu()
{
	int choiceMenu,choice; //to operate in the menus
	int loop = 0;         //to loop
	int temp = 0;        //to loop
	ImageEditor color2;
	ImageEditor color3;
	
	while(loop == 0)  // the menu is displayed until the user wishes to exit
	{

		cout<<"MAIN MENU"<<endl;
		cout<<"0 - Exit"<<endl;
		cout<<"1 - Open An Image(D)"<<endl;
		cout<<"2 - Save Image Data(D)"<<endl;
		cout<<"3 - Scripts(D)"<<endl;
		cout<<"4 - Addition "<<endl;
		cin>>choiceMenu;
		
		switch(choiceMenu) 
		{
			case 0: 
				loop = 1;
				exit(0); //to return to the previous menu
			break;
			case 1: 
				temp = 0; // to loop
				while  (temp == 0) // the menu is displayed until the user wishes to the previous menu
				{

					cout<<"OPEN AN IMAGE MENU"<<endl;
					cout<<"0 - Up"<<endl;
					cout<<"1 - Enter The Name Of The Image File"<<endl;
					cout<<"2 - Enter The Name Of The Second File "<<endl;
					cin>>choice;
					if(choice == 1)
					{
						open_an_image();
					}
					else if(choice == 2)
					{
						color2.open_an_image();
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
					cout<<"1 -  Choose File"<<endl;
					cin>>choice;
					if(choice == 1)
					{
						int temploop = 0;
						while(temploop == 0)
						{
							cout<<"CHOOSE FILE MENU"<<endl;
							cout<<"0 - Up"<<endl;
							cout<<"1 - Save the "<<get_Filename() <<endl;
							cout<<"2 - Save the "<< color2.get_Filename() <<endl;
							cout<<"3 - Save the  New File"<<endl;
							cin>>choice;
							if(choice == 1)
							{
								cout<<"Enter A File Name  "<<endl;
								save_image_data();
							}
							else if(choice == 2)
							{
								cout<<"Enter A File Name  "<<endl;
								color2.save_image_data();
							}
							else if (choice == 3)
							{
								cout<<"Enter A File Name "<<endl;
								color3.save_image_data();
							}
							else if (choice == 0)
								temploop = 1;   //to return to the previous menu
							else 
								exit(0);
						}
					}
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
							cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels in "<<filename<<endl;
							cout<<"2 - Enter Coefficients For RED GREEN And BLUE Channels in "<<color2.filename<<endl;
							cout<<"3 - Enter Coefficients For RED GREEN And BLUE Channels in new object "<<endl;
							cin>>choice;
							
							if(choice == 1)
								Scripts();
							if(choice == 2)
								color2.Scripts();
							if(choice == 3)
								color3.Scripts();
							
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
			case 4:
					color3.image  = new float[size+1];  //allocate memory for a new object
					color3.img  = new string[size+1];  //allocate memory for a new object
					color3 = *this + color2;          //operator +() 
					color3.size = size;              //other transactions not collected
					color3.file_type =file_type;
					color3.width = width;
					color3.height = height;
					color3.max_value = max_value;
					color3.filename = "newfile.ppm";
					for (int i = 0; i <size; ++i)     //returning to string to save
					{
						color3.image[i] = tempimage[i];
						color3.img[i] = to_string(color3.image[i]); 
					}
					cout<<"OPERATOR +() MENU"<<endl;
					cout<<"Process Completed"<<endl;					

			break;
			default :
				exit(0);
		}
	}	
}
void ImageEditor::open_an_image()
{
	cin>>filename;  
	ifstream file(filename.c_str());  //to open the file
	
	if(file.is_open())
	{	
		file >> file_type;     //file read (p3)
		file >>  height;	  //file read (4)
		file >> width;		 //file read (4)
		file >> max_value;	//file read (255)
		size = width * height * 3; // find size of file  
		image  = new float[size+1];  //To allocate memory
		img  = new string[size+1];	//To allocate memory
		tempimage =  new float[size+1];//To allocate memory
		int t = 0;
		while(!file.eof())    
		{
			file >>str;
			img[t] = str; // saves the file in string
			t++;
		}


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
	output.open(savefilename.c_str());  //opening file
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