
//função usada para ler um número inteiro, recebe o texto a ser exibido por
//parâmetro
int ler_inteiro (char texto[])
{
    int n;
    cout << texto;
    cin >> n;
    return n;
}

//função que recebe dois números inteiros e retorna a soma destes valores
int somar(int n1, int n2)
{
    return n1 + n2;
}

//função que gera elementos para preencher um vetor de inteiros
//necessita incluir no arquivo a biblioteca ctime
//recebe por parâmetro o endereço inicial do vetor e a dimensão
void gera_vetor(int v[], int x)
{
    srand(time(NULL));
    for(int i = 0; i < x; i++)
        v[i] = rand() % 50;
}

void gera_vetor_2(int v[], int x, int maior, int menor)
{
    //srand(time(NULL));
    for(int i = 0; i < x; i++)
        v[i] = rand() % (maior - menor) + menor;
}

//função que exibe na tela um vetor de inteiros
//recebe por parâmetro o endereço inicial do vetor e a dimensão
void mostra_vetor(int v[], int x)
{
    for(int i = 0; i < x; i++)
        cout << v[i] << ", ";
}


//gera uma matriz com a ordem até 50 com valores de 0 a 99
void gera_matriz(int m[][50], int ordem)
{
    srand(time(NULL));
    for(int l = 0; l < ordem; l++)
    {
        for(int c = 0; c < ordem; c++)
        {
            m[l][c] = rand() % 100;
        }
    }
}

//mostra uma matriz com a ordem até 50
void mostra_matriz(int m[][50], int ordem)
{
    for (int l = 0; l < ordem; l++)
    {
        for (int c = 0; c < ordem; c++)
            cout << m[l][c] << "\t ";
        cout << "\n";
    }
}


