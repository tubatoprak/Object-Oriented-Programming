#include <iostream>
#include <memory.h>
#include <exception>

#include "gtuset.h" 

using namespace std;

namespace hw6
{
	template<class T>
	GTUSet<T>::GTUSet() : GTUContainer<T>::GTUContainer()	
	{
	}

	template<class T>
	GTUSet<T>::GTUSet(int value) : GTUContainer<T>::GTUContainer(value)
	{
	}
	template<class T>
	bool GTUSet<T>::empty()
	{
		if(this->size == 0)
			return true;
		else
			return false;
	}
	
	template<class T>
	int GTUSet<T>::size1()
	{	
		return(this->size);
	}

	template<class T>
	int GTUSet<T>::maxsize()
	{	
		return this->capacity;
	}

	template<class T>
	void GTUSet<T>::clear()
	{	
		this->ptr = nullptr;
		this->size = 0;
		this->capacity = 0;
	}

	template<class T>
	const GTUIterator<T> GTUSet<T>::begin() const
	{
		T *temp = this->ptr.get();
		return  GTUIterator<T>(temp);
	}

	template<class T>
	const GTUIterator<T> GTUSet<T>::end() const
	{	
		T *temp = this->ptr.get();
		return  GTUIterator<T>(temp + this->size);
	}
	
	template<class T>
	void GTUSet<T>::insert(const T &obj) throw(invalid_argument)
	{
		for(int i = 0;i< this->size;++i)
		{
			if(this->ptr.get()[i] == obj)
			{
				throw(invalid_argument("This element is already in the set!"));
			}
		}

		shared_ptr<T> tempdata = this->ptr;
		shared_ptr <T> temp(new T[++this->size],default_delete<T[]>());
		this->ptr = temp;
		for (int i = 0; i < (this->size - 1); ++i)
		{
	        	this->ptr.get()[i] = tempdata.get()[i];  
		}
	    
	    this->ptr.get()[this->size-1] = obj;
	}

	template<class T>
    void GTUSet<T>::erase(const T obj)
    {	
		int tempsize=0;
		
		T * temp(new T [this->size]);
		int k = 0;
		
		for(int i = 0; i < this->size ; ++i)
		{
			if(obj != this->ptr.get()[i])
			{
				tempsize++;
				temp[k] = this->ptr.get()[i];
				

			}
			else
				k--;
			k++;
		}

		shared_ptr<T> tempptr (new T [tempsize],default_delete<T[]>());

		this->ptr = tempptr;

		for(int i=0 ; i < tempsize ; ++i)
		{
			this->ptr.get()[i] = temp[i];
		}

		this->size = tempsize;
	}

}