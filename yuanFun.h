#include "yuanHeadAll.h"

using namespace std;

// from in yuanLib_lc.h

/******************* PRINT ********************/
// for std, except the tree and etc which do not exit in stl


/******************* Array *******************/
template< typename T >
void printArrary(const T* const array, int cnt) // array name is a constant address for T type 
{
	cout << "Start to print the Array...\n";
	for(int i = 0 ; i < cnt; ++i)
		cout << array[i] << ' ';
	cout << "\n";
}