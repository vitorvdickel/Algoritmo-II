/*23 - Crie um arquivo de repositório de funções, neste arquivo implemente as funções descritas a
seguir:
Função 1: função que recebe um número real e devolve este número formatado com 2 casas
decimais, protótipo da função: float formata(float n);
Função 2: função que recebe um vetor de inteiros e dois números inteiros representando,
respectivamente, o menor e o maior elemento do vetor, a função deverá gerar valores
pseudoaleatórios para preencher o vetor, sem valores repetidos, obedecendo o intervalo dos
valores mínimo e máximo recebido por parâmetro. Protótipo da função: void gera_vetor(int v[],
int menor, int maior);
Função 3: função que recebe um vetor de inteiros e um char indicando o tipo de ordenação (c –
crescente, d - decrescente) e ordena os elementos do vetor conforme a ordem recebida, protótipo
da função: void ordena_vetor(int v[], char ordem);
Função 4: função que recebe um número inteiro e retorna true se o número for um número primo
e false caso não for. Protótipo da função: bool primo (int n);
Função 5: função que recebe um número inteiro e retorna true se o número for um número
perfeito e false caso não for. Protótipo da função: bool perfeito (int n);
Crie um arquivo com um menu de opções, para possibilitar os testes das funções criadas*/

#include <iostream>
#include <iomanip>

using namespace std;

void formata(float n);

int main(){
    float numero;
    cout << "Digite um numero real: ";
    cin >> numero;
    cout << "Numero formatado: " << endl;
    formata(numero);
    return 0;
}

//formatar um numero real com 2 casas decimais
void formata(float n){
    cout << fixed << setprecision(2) << n;
}

void gera_vetor(int v[], int menor, int maior){
    // Implementação da função para gerar vetor
}