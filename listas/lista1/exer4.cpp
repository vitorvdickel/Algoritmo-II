/*Na papelaria “Livro e Cia” a volta as aulas é um momento de realizar promoções, os itens
descritos abaixo estão com o respectivo desconto e percentual

Descrição Código Valor R$ Desconto %
Folha branca A4 com 500 1 28.00 7%
Caneta Bic ponta fina 2 6.30 5%
Caderno 10 matérias 3 22.00 5%
Caneta marca texto 4 17.80 6%
Cola bastão 5 5.50 7%
Corretor ortográfico 6 11.00 10%
Lápis preto 7 4.50 2%
Mochila com repartimento 8 138.00 7%
Caderno de desenho 9 8.00 5%

Escreva um programa que auxilie o dono da papelaria a realizar as compras dos clientes, o
programa deve possibilitar que o atendente informe o código do item e a quantidade solicitada,
sendo possível incluir vários itens na mesma compra, para tanto a cada item solicitado o
sistema deverá apresentar as seguintes possibilidades:
1 – Incluir mais um item
2 – Encerrar a compra
Se a opção for incluir mais um item (1) permite informar o código e a quantidade do próximo
item, caso a opção seja encerrar a compra (2) deverá exibir os itens da compra, com as
respectivas quantidades, o valor do item e ao final o valor total da compra, como no exemplo:
Descrição QTD Valor do Item Desconto Total Item
Folha branca A4 com 500 1 28.00 1.96 26.04
Caderno 10 matérias 2 44.00 2.20 41.80
Cola bastão 1 5.50 0.38 5.12
Total da compra:.....................................................................................................72.96
OBS:
- Validar para aceitar somente itens pertencentes à lista apresentada.
- Exibir a compra com os alinhamentos e os valores numéricos formatados conforme no
exemplo.
- Aplicar o desconto em cada item, conforme a tabela de promoções*/

#include <iostream>
#include <iomanip> // Apenas para o setprecision(2) e fixed
#include <cstring> // Para o strlen()

using namespace std;

int main() {
    char descricoes[10][35] = {
        "", // Posição 0 vazia
        "Folha branca A4 com 500",
        "Caneta Bic ponta fina",
        "Caderno 10 materias",
        "Caneta marca texto",
        "Cola bastao",
        "Corretor ortografico",
        "Lapis preto",
        "Mochila com repartimento",
        "Caderno de desenho"
    };
    
    float precos[10] = {0.0, 28.00, 6.30, 22.00, 17.80, 5.50, 11.00, 4.50, 138.00, 8.00};
    float descontos_perc[10] = {0.0, 0.07, 0.05, 0.05, 0.06, 0.07, 0.10, 0.02, 0.07, 0.05};

    int carrinho_codigos[100];
    int carrinho_qtds[100];
    int total_itens_comprados = 0;
    int opcao;

    cout << "--- SISTEMA DE CAIXA: LIVRO E CIA ---" << endl;
    do {
        int codigo, qtd;

        cout << "\nInforme o codigo do item (1 a 9): ";
        cin >> codigo;
        while (codigo < 1 || codigo > 9) {
            cout << "Codigo invalido! Informe um codigo existente (1 a 9): ";
            cin >> codigo;
        }

        cout << "Informe a quantidade: ";
        cin >> qtd;
        while (qtd <= 0) {
            cout << "Quantidade invalida! Informe um valor maior que zero: ";
            cin >> qtd;
        }

        carrinho_codigos[total_itens_comprados] = codigo;
        carrinho_qtds[total_itens_comprados] = qtd;
        total_itens_comprados++;

        cout << "\n1 - Incluir mais um item" << endl;
        cout << "2 - Encerrar a compra" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        
        while (opcao != 1 && opcao != 2) {
            cout << "Opcao invalida! Digite 1 ou 2: ";
            cin >> opcao;
        }

    } while (opcao != 2);


    cout << "\n===============================================================================\n";
    
    // Cabeçalho impresso com espaçamentos fixos e diretos
    cout << "Descricao                   "; // 28 caracteres
    cout << "  QTD"; // 5 caracteres
    cout << "    Valor do Item"; // 17 caracteres
    cout << "     Desconto"; // 13 caracteres
    cout << "    Total Item" << endl; // 14 caracteres

    float valor_total_compra = 0.0;

    for (int i = 0; i < total_itens_comprados; i++) {
        int cod = carrinho_codigos[i];
        int q = carrinho_qtds[i];

        float valor_bruto = precos[cod] * q;
        float valor_desconto = valor_bruto * descontos_perc[cod];
        float valor_liquido = valor_bruto - valor_desconto;

        valor_total_compra = valor_total_compra + valor_liquido;

        // 1. Alinhando a Descrição à esquerda (imprime o texto, depois preenche com espaços)
        cout << descricoes[cod];
        int espacos_desc = 28 - strlen(descricoes[cod]);
        for(int j = 0; j < espacos_desc; j++) cout << " ";

        // 2. Alinhando QTD à direita (calcula os dígitos, imprime espaços ANTES, depois o número)
        int dig_q = 1;
        if (q >= 10) dig_q = 2;
        if (q >= 100) dig_q = 3;
        for(int j = 0; j < 5 - dig_q; j++) cout << " ";
        cout << q;

        // 3. Alinhando Valor Bruto à direita
        int int_bruto = (int)valor_bruto;
        int dig_bruto = 1;
        if (int_bruto >= 10) dig_bruto = 2;
        if (int_bruto >= 100) dig_bruto = 3;
        if (int_bruto >= 1000) dig_bruto = 4;
        if (int_bruto >= 10000) dig_bruto = 5;
        // Subtraímos os dígitos inteiros + 3 (referente ao ponto decimal e as 2 casas: .xx)
        for(int j = 0; j < 17 - (dig_bruto + 3); j++) cout << " ";
        cout << fixed << setprecision(2) << valor_bruto;

        // 4. Alinhando Desconto à direita
        int int_desc = (int)valor_desconto;
        int dig_desc = 1;
        if (int_desc >= 10) dig_desc = 2;
        if (int_desc >= 100) dig_desc = 3;
        for(int j = 0; j < 13 - (dig_desc + 3); j++) cout << " ";
        cout << fixed << setprecision(2) << valor_desconto;

        // 5. Alinhando Valor Líquido à direita
        int int_liq = (int)valor_liquido;
        int dig_liq = 1;
        if (int_liq >= 10) dig_liq = 2;
        if (int_liq >= 100) dig_liq = 3;
        if (int_liq >= 1000) dig_liq = 4;
        if (int_liq >= 10000) dig_liq = 5;
        for(int j = 0; j < 14 - (dig_liq + 3); j++) cout << " ";
        cout << fixed << setprecision(2) << valor_liquido << endl;
    }

    // Linha pontilhada final (59 pontinhos + os caracteres do valor_total)
    cout << "\nTotal da compra:";
    for(int i = 0; i < 59; i++) {
        cout << ".";
    }
    cout << fixed << setprecision(2) << valor_total_compra << endl;

    cout << "===============================================================================\n";

    return 0;
}