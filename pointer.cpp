#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <typeinfo> //for class type information

// #include "../yuanFun.h"

using namespace std;

// xcrun clang++ -o con -std=c++11 -stdlib=libc++ tmp.cpp
void pointer_prac(){
    /* pointer modify 
    * https://denniskubes.com/2012/08/17/basics-of-memory-addresses-in-c/
    */
    // printInfo();
    unsigned int i = 1, a[4] = {1,2,3,4};
    char * p = (char*) a + i * 4;
    cout << "a loc:\t" << a << "\na[1] loc:\t" << &a[1] << endl;
    // cout << "p loc:\t" << (char *)p << endl;
    cout << "p loc:\t" << (void *)p << endl;
    cout << "p loc:\t" << (int *)p << endl;
    *p = *p + 10;
    cout << (char)(*p )<< " done" << endl;
}


int G = 0;
int main(int argc, char const *argv[])
{
	static int s;
	int a;
	int *p;
	p = new int();
	printf("&G   = %p\n", (void *) &G);
	printf("&s   = %p\n", (void *) &s);
	printf("&a   = %p\n", (void *) &a);
	printf("&p   = %p\n", (void *) &p);
	printf("p   = %p\n", (void *) p);
	printf("main = %p\n", (void *) main);

	free(p);
	return 0;
}
