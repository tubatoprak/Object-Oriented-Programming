#include <iostream>
#include <memory.h>

#include "gtucontainer.h"

using std::cout;
using std::cin;	
namespace hw6 
{
	template<class T>
	GTUContainer<T>::GTUContainer()
	{
		size = 0;
		capacity =100;
		ptr = nullptr;
	}
	
	template<class T>
	GTUContainer<T>::GTUContainer(int data)
	{
		size = data;
		T * temp = new T(size);
		shared_ptr<T> tempptr(temp);
		ptr = tempptr;
	}
}