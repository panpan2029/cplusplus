#ifndef HEADERALL_H
#define HEADERALL_H

#include <iostream>     // std::cout
#include <iomanip> 
#include <fstream>
//setw(int cnt), ignore(int cnt), 
//fixed, setprecision(2)
#include <sstream> //istringstream, ostringstream, stringstream
#include <string>
#include <cstring>
#include <cmath> //sqrt(), pow()

#include <cstdlib>      // std::rand, std::srand
#include <cstddef> // for NULL
#include <stdexcept> 
//throw invalide_argument(" ");
//try{}catch(invalide_argument/out_of_range &ex){ex.what}

#include <typeinfo> //for class type information
//typeid(var).name(), typeid() return a reference to the obj of class "type_info", containing the information about the type of var, including the name, name() return the name of the type


#include <vector>
#include <iterator> //ostream_iterator and istream_iterator
#include <list>
#include <deque>
#include <set>
#include <unordered_set> //219
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>

#include <algorithm> //copy alg, swap, std::random_shuffle

#include <ctime>        // std::time
#include "time.h"
#include <assert.h> 

#endif