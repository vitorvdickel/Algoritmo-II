#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Definindo o nome do arquivo. 
    // Crie um arquivo com esse nome e coloque os dados de teste dentro.
    ifstream arquivo_entrada("dados28.txt");

    if (!arquivo_entrada.is_open()) {
        cout << "Erro ao abrir o arquivo texto!" << endl;
        return 1;
    }

    int D, T;
    // Lê a primeira linha: D (disciplinas/linhas) e T (turmas/colunas)
    arquivo_entrada >> D >> T;

    // Criando um vetor dinâmico para guardar o maior valor de cada turma (coluna)
    int* max_por_turma = new int[T];

    // Inicializando o vetor com zero
    for (int i = 0; i < T; i++) {
        max_por_turma[i] = 0;
    }

    // Lendo a matriz de dados
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < T; j++) {
            int alunos_que_gostam;
            arquivo_entrada >> alunos_que_gostam;

            // Se o valor lido agora for maior que o máximo já registrado para essa turma (j)
            // nós atualizamos o valor máximo dela.
            if (alunos_que_gostam > max_por_turma[j]) {
                max_por_turma[j] = alunos_que_gostam;
            }
        }
    }

    // Agora basta somar os valores máximos de todas as turmas
    int total_minimo_alunos = 0;
    for (int i = 0; i < T; i++) {
        total_minimo_alunos = total_minimo_alunos + max_por_turma[i];
    }

    // Exibindo a saída conforme o exemplo
    cout << total_minimo_alunos << endl;

    // Liberando a memória do vetor dinâmico e fechando o arquivo
    delete[] max_por_turma;
    arquivo_entrada.close();

    return 0;
}