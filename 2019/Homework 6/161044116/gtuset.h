#ifndef GTUSET_H
#define GTUSET_H
#include <iostream>
#include <memory.h>
#include <exception>
#include "gtucontainer.h"

namespace hw6
{
	template<class T>
	class GTUSet: public GTUContainer<T>
	{
	public:
		GTUSet();
		GTUSet(int value);
		const GTUIterator<T> begin() const;
		const GTUIterator<T> end() const;
		bool empty() ;		
		int size1() ;	
		int maxsize();
		void insert(const T &val) throw(invalid_argument);	
		void erase(const T obj);
		void clear();	
	};
}
#endif