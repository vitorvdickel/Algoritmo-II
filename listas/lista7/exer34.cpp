#include <iostream>
#include <iomanip>

using namespace std;

void calcularRestante(float *p_peso, float *p_racao, float *p_restante) {
    *p_restante = *p_peso - ((*p_racao * 2.0 * 5.0) / 1000.0);
}

int main() {
    float dados[3]; 

    cout << "Digite o peso do saco de racao (em kg): ";
    cin >> *(dados); 

    cout << "Digite a quantidade diaria de racao fornecida para cada gato (em gramas): ";
    cin >> *(dados + 1); 

    calcularRestante(dados, (dados + 1), (dados + 2));

    cout << fixed << setprecision(2);
    
    if (*(dados + 2) < 0) {
        cout << "\nA racao nao sera suficiente para os 5 dias. Faltarao " << (*(dados + 2) * -1.0) << " kg." << endl;
    } else {
        cout << "\nApos cinco dias, restarao " << *(dados + 2) << " kg de racao no saco." << endl;
    }

    return 0;
}