#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
    system ("chcp 1252 > null");

    int n1, n2, *pn1 = &n1, *p2n = &n2, i, *pi = &i;
    cout << "Digite o valor 1: " << endl;
    cin >> *pn1;
    cout << "Digite o valor 2: " << endl;
    cin >> *pn2;

    if (*pn1 == *pn2){
        cout << "Os valores são iguais";
    } else {
        *pi = *pn1;
        *pn1 = *pn2;
        *pn2 = *pi;
    }
    if (*pn1 + 1 == *pn2){
        cout << "Os valores são sequenciais";
    } else {
        *pi = *pn1 + 1;
        while (*pi < *pn2){
            cout << *pi << ", ";
            *pi = *pi + 1;
        }
    }
}