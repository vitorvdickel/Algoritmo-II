#include <iostream>

using namespace std;

int main(){
    system ("chcp 1252 > nul");
    int m [3] [3] = {
        {1,2,3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int *p = &m [0][0];
    int *cont = new int (0);

    for (int i = 0; i < 9; i++){
        if (*cont == 3){
            cout << endl;
            *cont = 0;
        }
        cout << *p << " ";
        p++;
        (*cont)++;
    }
}