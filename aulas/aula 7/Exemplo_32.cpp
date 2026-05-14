#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
    system("chcp 1252 > nul");

    int x, *px;

    px = &x;

    x = 5;

    cout << "Endereço da variável X: " << &x << endl;
    cout << "Valor contido em X: " << x << endl;
    cout << "Endereço do ponteiro PX: " << &px << endl;
    cout << "Valor do ponteiro PX: " << px << endl;
    cout << "Valor contido no endereço do PX: " << *px << endl;

}


