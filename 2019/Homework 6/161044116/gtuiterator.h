#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include <memory>
using namespace std;

namespace hw6
{
	template <class T>
	class GTUIterator
	{
	public:
		GTUIterator();
		GTUIterator(T * data);
		GTUIterator & operator + (int value);
		GTUIterator & operator = (const GTUIterator & obj);
		T operator * () const;
		GTUIterator & operator ++ ();
		GTUIterator & operator -- ();
		bool operator == (const GTUIterator & obj) const;
		bool operator != (const GTUIterator & obj) const;
		T * operator ->() const;
	private:
		T * point;
	};
}

#endif