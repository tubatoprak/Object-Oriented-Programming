#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <memory>
using namespace std;

namespace hw6
{
	template <class T>
	class GTUIteratorConst
	{
	public:
		GTUIteratorConst();
		GTUIteratorConst(T * data);
		GTUIteratorConst & operator + (int value);
		GTUIteratorConst & operator = (const GTUIteratorConst & obj);
		T operator * () const;
		GTUIteratorConst & operator ++ ();
		GTUIteratorConst & operator -- ();
		bool operator == (const GTUIteratorConst & obj) const;
		bool operator != (const GTUIteratorConst & obj) const;
		T * operator ->() const;
	private:
		T * point;
	};
}

#endif