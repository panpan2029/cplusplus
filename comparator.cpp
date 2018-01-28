#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo> //for class type information

#include "../yuanFun.h"

using namespace std;



//1. define operator <, then less<Object> use it by default, eg. 
// sort(v.begin(), v.end());
// priority_queue<Edge> pq;
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



int main(){
	string str1 = "abc";
	string str2 = "aBy";
	cout << ( str1 > str2) << endl;
	// set<string, CaseInsensitiveCompare> strSet;
	bool(*fn_pt)(string, string) = CaseInsensitiveCompare;
	set<string,bool(*)(string, string)> strSet (fn_pt);; // user-defined function
	strSet.insert(str1);
	strSet.insert(str2);
	for(auto & s : strSet)
		cout << s << ' ';
	cout << endl;

	int arr[] = {3,7,9,1,5,0};
	int len = 6; 
	sort(arr, arr+6, greater<int>()); //default less<Object>, default comparison (operator <); () instatiate an obj
	printArrary(arr, len);
	

	sort(arr, arr + len, [](int a, int b){return a < b;}); // lambda
	printArrary(arr, len);
	sort(arr, arr + len, intCmp); // using function as comp
	printArrary(arr, len);
	sort(arr, arr + len, myLess()); // using object as comp; or instatiate an object after the struct
	printArrary(arr, len);

	
}