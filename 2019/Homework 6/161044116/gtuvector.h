#ifndef GTUVECTOR_H
#define GTUVECTOR_H
#include <iostream>
#include <utility>
#include <memory.h>
#include "gtucontainer.h"

namespace hw6
{
	template<class T>
	class GTUVector: public GTUContainer<T>
	{
	public: 
		GTUVector();
		GTUVector(int value);
		const GTUIterator<T> begin() const;
		const GTUIterator<T> end() const;
		bool empty() ;		
		int size1() ;	
		int maxsize();
		void insert(const T &val) throw(invalid_argument);
		T& operator[](const T& value);
		void erase(const T obj);
		void clear();
	};
}
#endif