#include <iterator>
#include <vector>
#include "../yuanFun.h"

using namespace std;

//iterator, advance(), prev(), next()
//http://www.cplusplus.com/reference/iterator/prev/

//random_access_iterator_tag
int main(){
 	vector<int> v;
 	for(int i = 0; i < 100; i++)
 		v.push_back(i * 10);
 	cout << v;
	
	vector<int>::iterator itr = v.begin();
	vector<int>::iterator itr_e = v.end();
	cout << *itr << endl;
	advance(itr,2); // return void error: cout << *(advance(itr,2)) << endl;
	cout << *itr << endl;
	cout << (distance(itr,itr_e)) << endl;
	cout << *(prev(itr)) << endl;
	cout << *(next(itr)) << endl;

}