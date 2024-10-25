#include <iostream>

#include "gtuiterator.h" 

using namespace std;

namespace hw6
{
	template <class T>
	GTUIterator<T>::GTUIterator()
	{
		point = nullptr;
	}

	template <class T>
	GTUIterator<T>::GTUIterator(T * data)	
	{
		point = data;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator = (const GTUIterator & obj)
	{
		if(this == &obj)	
			return *this;
		else
		{
			point =obj.point;
			return *this;
		}
	}

	template <class T>
	T GTUIterator<T>::operator * () const
	{
		return *point;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator ++ ()
	{
		++point;
		return *this;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator -- ()
	{	
		--point;
		return *this;
	}
	
	template <class T>
	bool GTUIterator<T>::operator == (const GTUIterator & obj) const
	{	
		return(point == obj.point);
	}

	template <class T>
	bool GTUIterator<T>::operator != (const GTUIterator & obj) const
	{	
		return(point != obj.point);
	}

	template <class T>
	T* GTUIterator<T>::operator -> () const
	{
		return point;
	}

}
