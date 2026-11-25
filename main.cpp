#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "produto.h"
#include "estoque.h"
using namespace std;
void exibirMenu() {
    cout << "\n========================================" << endl;
    cout << "   GERENCIAMENTO DE ESTOQUE" << endl;
    cout << "========================================" << endl;
    cout << "1 - Cadastrar produto" << endl;
    cout << "2 - Listar produtos" << endl;
    cout << "3 - Consultar produto pelo codigo" << endl;
    cout << "4 - Atualizar quantidade em estoque" << endl;
    cout << "5 - Excluir produto\n";
    cout << "6 - Calcular valor total do estoque" << endl;
    cout << "0 - Encerrar aplicacao" << endl;
    cout << "========================================" << endl;
}
int main(){
   int capacidade = 0;
   int quantidade = 0;
   int opcao;
   Produto *estoque;
   cout << "=== SISTEMA DE CONTROLE DE ESTOQUE ===" << endl;
   do{
    cout << "Informe a capacidade maxima de produtos: ";
    cin >> capacidade;
    if(capacidade <= 0){
        cout << "A Capacidade deve ser maior que zero." << endl;
    }
   }while(capacidade <=0);
    *estoque = (Produto *) malloc(capacidade * sizeof(Produto));
    if (estoque == NULL){
        cout << "Falha ao alocar memoria." << endl;
        return 1;
    }
    do{
        exibirMenu(;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        switch (opcao){
        case 1:
            cadastrarProduto(estoque, &quantidade, capacidade);
            break;
        case 2:
            listarProdutos(estoque, quantidade);
            break;
        case 3:
            consultarProduto(estoque, quantidade);
            break;
        case 4:
            atualizarQuantidade(estoque, quantidade);
            break;
        case 5:
            excluirProduto(estoque, &quantidade);
            break;
        case 6: {
            float total = calcularValorTotal(estoque, quantidade);
            cout << "Valor total em estoque: RS " << total << endl;
            break;

        }
        case 0:
            cout << "\nEncerrando a aplicacao e liberando memoria..." << endl;
            break;
        default:
            cout << "ERRO! opcao invalida! escolha entre 0 e 6." << endl;
            break;
        }
    }while (opcao != 0);
    free(estoque);
    estoque = NULL;
    cout << "Memoria liberada com sucesso. Ate mais!" << endl;
    return 0;
}
