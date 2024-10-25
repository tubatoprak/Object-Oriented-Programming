#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include <iostream>
#include <memory.h>
#include <exception>
#include "gtuiterator.h"

namespace hw6
{
	template<class T>
	class GTUContainer
	{
	public:
		GTUContainer();
		GTUContainer(int data);	
		typedef GTUIterator<T> it;
		virtual bool empty() = 0;
		virtual int size1 () = 0;
		virtual int maxsize() = 0;
		virtual void insert(const T &obj) throw(invalid_argument) = 0;
		virtual void erase (const T obj) = 0;
		virtual void clear () = 0;
		virtual const GTUIterator<T> begin() const = 0;
		virtual const GTUIterator<T> end() const = 0;
	protected:
		int capacity;
		int size;
		shared_ptr<T> ptr;
	};
}
#endif
