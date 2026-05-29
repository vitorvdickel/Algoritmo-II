/*22 - Escrever um programa, que através de funções realize as seguintes ações:
- Função para gerar um vetor V[20] com valores no intervalo de 0 a 100 sem números repetidos.
- Função para mostrar os valores gerados na tela separados por uma vírgula.
- Função que escreva os valores do vetor em um arquivo texto chamado “exer_22.txt”, separando
cada elemento por um espaço em branco.
- Função para ler posições do vetor (validar para aceitar 0 a 19).
Após o programa deverá ler duas posições do vetor e trocar os elementos destas posições e mostrar
o vetor após a troca e escrever o vetor atualizado no arquivo texto.*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int gerarVetor(int vetor[20]);
int mostrarVetor(int vetor[20]);
int escreverVetor(int vetor[20]);
int lerPosicao(int &pos);

int main(){
    int vetor[20];
    gerarVetor(vetor);
    mostrarVetor(vetor);
    escreverVetor(vetor);

    // Ler as posições para troca
    int pos1, pos2;
    lerPosicao(pos1);
    lerPosicao(pos2);

    // Trocar os elementos das posições
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
    mostrarVetor(vetor);
    escreverVetor(vetor);

    return 0;
}

//gera um vetor com 20 numeros aleatorios entre 0 e 100 sem repeticao
int gerarVetor(int vetor[20]){
    srand(time(0)); // Inicializa a semente para geração de números aleatórios
    for(int i = 0; i < 20; i++){
        int num;
        bool repetido;
        do {
            num = rand() % 101; // Gera um número entre 0 e 100
            repetido = false;
            for(int j = 0; j < i; j++){
                if(vetor[j] == num){
                    repetido = true;
                    break;
                }
            }
        } while(repetido);
        vetor[i] = num;
    }
    return 0;
}

//mostra o vetor na tela
int mostrarVetor(int vetor[20]){
    for(int i = 0; i < 20; i++){
        cout << vetor[i];
        if(i < 19){
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}

//escreve o vetor em um arquivo texto separando por espaço
int escreverVetor(int vetor[20]){
    ofstream arquivo("exer_22.txt");
    if(arquivo.is_open()){
        for(int i = 0; i < 20; i++){
            arquivo << vetor[i] << " ";
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
    return 0;
}

int lerPosicao(int &pos){
    while(pos < 0 || pos > 19){
        cout << "Posicao invalida, digite uma posicao entre 0 e 19: ";
        cin >> pos;

    }
    return pos;
}