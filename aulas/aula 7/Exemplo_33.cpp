#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
    system("chcp 1252 > nul");

    int n1, n2, *pn1 = &n1, *pn2 = &n2, i, *pi = &i;

    cout << "Informe o valor 1: ";
    cin >> *pn1;

    cout << "Informe o valor 2: ";
    cin >> *pn2;

    if(*pn1 == *pn2)
    {
        cout << "Os valores são iguais, não existem números entre eles." << endl;
    }
    else if(*pn1 > *pn2)
    {
        *pi = *pn1;
        *pn1 = *pn2;
        *pn2 = *pi;
    }

    if(*pn1 + 1 == *pn2)
    {
        cout << "Os valores são sequenciais, não existem números entre eles." << endl;
    }
    else
    {
        *pi = *pn1 + 1;
        while(*pi < *pn2)
        {
            cout << *pi << ", ";
            *pi = *pi + 1; //(*pi)++
        }
    }


}


