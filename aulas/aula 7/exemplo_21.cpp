#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

main(){
    system ("chcp 1252 > null");

    int x, *px;

    px = &x;

    x = 5;

    cout << "Endereço da variável X: " << &x << endl;
    cout << "Valor contido em X: " << x << endl;
    cout << "Endereço do ponteiros PX " << &px << endl;
    cout << "Valor contido no endereço de PX " << &px << endl;
    cout << "Valor do ponteiro px " << px;
}