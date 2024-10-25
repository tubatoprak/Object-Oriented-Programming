#ifndef __ADMINISTRATOR_H__
#define __ADMINISTRATOR_H__
#include <string>
using namespace std;
class Administrator
{  
public:      
	Administrator();     
	Administrator(string name, string password);    
	bool Login(); 
private:      
	string name;  
	string password;
};
#endif