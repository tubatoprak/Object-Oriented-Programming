#include <iostream>

#include "gtuiteratorconst.h" 

using namespace std;

namespace hw6
{
	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst()
	{
		point = nullptr;
	}

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(T * data)	
	{
		point = data;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator = (const GTUIteratorConst & obj)
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
	T GTUIteratorConst<T>::operator * () const
	{
		return *point;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator ++ ()
	{
		++point;
		return *this;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator -- ()
	{	
		--point;
		return *this;
	}
	
	template <class T>
	bool GTUIteratorConst<T>::operator == (const GTUIteratorConst & obj) const
	{	
		return(point == obj.point);
	}

	template <class T>
	bool GTUIteratorConst<T>::operator != (const GTUIteratorConst & obj) const
	{	
		return(point != obj.point);
	}

	template <class T>
	T* GTUIteratorConst<T>::operator -> () const
	{
		return point;
	}

}
