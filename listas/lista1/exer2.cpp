/*2 – Escreva um programa que manipule um vetor VET[20] de números float, os valores para
preencher o vetor devem ser gerados randomicamente, mostre o vetor gerado na tela, exibindo
5 valores em cada linha e separando cada valor com uma vírgula, a seguir mostre o vetor com
valores arredondados para cima, para baixo e seguindo o critério da primeira casa decimal, após
truncar (considerar somente a parte inteira) todos os valores do vetor e apresentar a soma dos
valores truncados.*/

#include <iostream>
#include <cstdlib>
#include <cmath>   // Mantida para o floor() e round()
#include <iomanip>

using namespace std;

int main() {
    float VET[20];
    float soma_truncados = 0;

    // 1. Preenchendo o vetor com números float pseudoaleatórios (de 0.0 a 100.0)
    for (int i = 0; i < 20; i++) {
        VET[i] = ((float)rand() / RAND_MAX) * 100.0f;
    }

    // 2. Exibindo o vetor original (5 por linha, separados por vírgula)
    cout << "--- Vetor Original ---" << endl;
    for (int i = 0; i < 20; i++) {
        cout << fixed << setprecision(2) << VET[i];
        if ((i + 1) % 5 == 0) cout << endl;
        else cout << ", ";
    }
    cout << endl;

    // 3. Vetor arredondado para CIMA (Lógica feita "na mão", sem ceil)
    cout << "--- Arredondado para Cima (Sem ceil) ---" << endl;
    for (int i = 0; i < 20; i++) {
        int parte_inteira = (int)VET[i];
        int arredondado_cima = parte_inteira;
        
        // Se o valor float for maior que a parte inteira (ex: 5.2 > 5), sobe 1.
        if (VET[i] > parte_inteira) {
            arredondado_cima = parte_inteira + 1;
        }
        
        cout << arredondado_cima;
        if ((i + 1) % 5 == 0) cout << endl;
        else cout << ", ";
    }
    cout << endl;

    // 4. Vetor arredondado para BAIXO usando floor()
    cout << "--- Arredondado para Baixo (floor) ---" << endl;
    for (int i = 0; i < 20; i++) {
        cout << fixed << setprecision(0) << floor(VET[i]);
        if ((i + 1) % 5 == 0) cout << endl;
        else cout << ", ";
    }
    cout << endl;

    // 5. Vetor arredondado pelo critério da primeira casa decimal usando round()
    cout << "--- Arredondamento Padrao (round) ---" << endl;
    for (int i = 0; i < 20; i++) {
        cout << fixed << setprecision(0) << round(VET[i]);
        if ((i + 1) % 5 == 0) cout << endl;
        else cout << ", ";
    }
    cout << endl;

    // 6. Truncando (considerando só a parte inteira) e somando
    cout << "--- Valores Truncados ---" << endl;
    for (int i = 0; i < 20; i++) {
        int valor_truncado = (int)VET[i]; 
        soma_truncados = soma_truncados + valor_truncado;

        cout << valor_truncado;
        if ((i + 1) % 5 == 0) cout << endl;
        else cout << ", ";
    }

    // 7. Apresentando a soma final
    cout << "\nSoma dos valores truncados: " << soma_truncados << endl;

    return 0;
}