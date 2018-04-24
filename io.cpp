#include <iostream>     // std::cout
#include <iomanip> 
#include <string>

#include "../yuanFunc.h"
using namespace std;

void printPrompt(){
    cout << "please input : ";
}
int main(){
    printPrompt();
    string strinput; 
    int x; 
    getline(cin, strinput);
    cout << ">> " << strinput << "-end" << endl;
    cout << typeid((stringstream(strinput) >> x)).name() << endl; // if not int type, 0
    cout << ">> " << x * x << "-end" << endl;

    return 0;

    cin >> strinput ; /*cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being extracted, and thus extracting a string means to always extract a single word, not a phrase or an entire sentence.*/
    cout << ">> " << strinput << "-end" << endl;
    

    return 0;
}