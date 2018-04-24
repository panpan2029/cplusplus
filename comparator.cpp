#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo> //for class type information

#include "../yuanFun.h"

using namespace std;

//about set, unordered_set, function in the template

//https://stackoverflow.com/questions/20826078/priority-queue-comparison

//1. define operator <, then less<Object> use it by default, eg. 
// sort(v.begin(), v.end());
// priority_queue<Edge> pq;

//https://stackoverflow.com/questions/3810519/how-to-use-a-lambda-expression-as-a-template-parameter
struct Edge
{
    int from, to, weight;
    friend bool operator<(Edge a, Edge b)
    {
        return a.weight > b.weight;
    }
};


//2. define a customer comparision function, eg
// sort(data.begin(), data.end(), cmp);
bool CaseInsensitiveCompare(string s1, string s2) {  
	if(!s1.size()) return true;
	if(!s2.size()) return false;

	if(tolower(s1[0]) < tolower(s2[0]))
		return true;
	else if(tolower(s1[0]) > tolower(s2[0]))
		return false;
	else
		return CaseInsensitiveCompare(s1.substr(1), s2.substr(1));
}
bool intCmp(int a , int b) {return a < b;}

// 3. define operator()()
// set<int, cmp> s;
// priority_queue<int, vector<int>, cmp> pq;
// sort(data.begin(), data.end(), greater<int>()); 
struct myLess
{
	bool operator()(const int a, const int b) const {return a < b ;}
};

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs); //min heap
    else return (lhs<rhs);
  }
};

int main(){
	//set
	string str1 = "abc";
	string str2 = "aBy";
	cout << ( str1 > str2) << endl;
	// set<string, CaseInsensitiveCompare> strSet;
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	bool(*fn_pt)(string, string) = CaseInsensitiveCompare;
	set<string,bool(*)(string, string)> strSet (fn_pt);; // user-defined function
	strSet.insert(str1);
	strSet.insert(str2);
	cout << "set, use function CaseInsensitiveCompare, increasing order ...\n";
	for(auto & s : strSet)
		cout << s << ' ';
	cout << endl;

	//array
	int arr[] = {3,7,9,1,5,0};
	int len = 6; 
	cout << "use greater<int>() ...\n";
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	sort(arr, arr+6, greater<int>()); //default less<Object>, default comparison (operator <); () instatiate an obj
	printArrary(arr, len);
	
	cout << "use lambda, increasing order ...\n";
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	sort(arr, arr + len, [](int a, int b){return a < b;}); // lambda
	printArrary(arr, len);
	cout << "use function, increasing order ...\n";
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	sort(arr, arr + len, intCmp); // using function as comp, if it's a class member function, it has to be static member function, or else we need to instantiate an object for that.
	printArrary(arr, len);
	cout << "use function object(from struct operator), increasing order ...\n";
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	sort(arr, arr + len, myLess()); // using object as comp; or instatiate an object after the struct
	printArrary(arr, len);

	//from cplusplus website
	// priority queue, similar to set
	int myints[]= {10,60,50,20};
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// std::priority_queue<int,std::vector<int>,mycomparison> mypq(begin, end, mycomparison(true))
	typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;
	mypq_type mypq(myints, myints + 4, mycomparison(true));
	cout << "use function object, min heap\n";
	while(!mypq.empty()){
		cout << mypq.top() << ' ';
		mypq.pop();
	}
	
}