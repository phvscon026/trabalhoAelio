#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <cstring>
#include "produto.h"
using namespace std;

    int buscarPorCodigo(const Produto *estoque, int n, int cod){
        for (int i = 0; i < n; i++){
            if (*(estoque + i).codigo == cod){
            return i;
            }
        }
        return -1;
    }
    void cadastrarProduto(Produto *estoque, int *qtd, int capacidade){
        int cod;
        char name[100];
        int quant;
        float price;
        if (*qtd >= capacidade){
            cout << "\nESTOQUE CHEIO!" << endl;
            cout << "Exclua um produto antes de cadastrar um novo" << endl;
            return;
        }do{
            cout << "Codigo do produto: ";
            cin >> cod;
            if (cod <= 0){
                cout << "O codigo deve ser maior que zero (0)"<<endl;
            } else if (buscarPorCodigoE,stoque, *qtd, cod) != -1){
                cout << "Já existe um produto com esse codigo ->" << cod << endl;
                cod = -1;
                }
        }while (cod <= 0);
        do{
            cout << "Nome do Produto: ";
            cin.getline(name, 100);
            if (strlen(name) == 0){
                cout << "Digite um nome valido!"<< endl;
            }
        }while (strlen(name) == 0);
        do{
            cout << "Quantidade em estoque: ";
            cin >> quant;
            if (quant < 0){
                cout << "Digite uma quantidade maior que zero (0)." << endl;
            }while (quant < 0);
        }do {
            cout << "Preco Unitario (RS): ";
            cin >> price;
            if (preco < 0.0){
                cout << "Digite um preco valido."
            }
        }while (preco < 0.0);

        Produto *novo = estoque + (*qtd);
        (*novo).codigo = cod;
        strcpy((*novo).nome, name);
        (*novo).quantidade = quant;
        (*novo).preco = price;
        (*qtd)++;
        cout << "\nPRODUTO CADASTRADO COM SUCESSO! (" << *qtd << "|" << capacidade << " posicoes ocupadas)" << endl;
    }
    void listarProdutos (const Produto *estoque, int qtd){
        if (qtd == 0){
            cout << "\nNenhum produto cadastrado no estoque." << endl;
            return;
        }
        cout << "\n=== LISTA DE PRODUTOS CADASTRADOS ===" << endl;
            for (int i = 0; i < qtd; i++) {
                const Produto *p = (estoque + i);
                cout << "Codigo: " << (*p).codigo << endl;
                cout << "Nome: " << (*p).nome << endl;
                cout << "Quantidade: " << (*p).quantidade << endl;
                cout << "Preco: R$ " << (*p).preco << endl;
                cout << "========================================="<< endl;
            }
    }
    void consultarProduto(const Produto *estoque, int qtd){
        int cod, indice;
        const Produto *p;
        if (qtd == 0) {
            cout << "\nNenhum produto cadastrado para consulta." << endl;
            return;
        }
        cout << "Informe o codigo do produto para a consulta: ";
        cin >> cod;
        indice = buscarPorCodigo(estoque, qtd, cod);
        if (indice == -1){
            cout << "Produto com codigo nao encontrado" << endl;
            reutrn;
        }
        *p = estoque + indice;
        cout << fixed << setprecision(2);
        cout  << "\n--- Dados do Produto ---" << endl;
        cout << "Codigo: " << (*p).codigo << endl;
        cout << "Nome: " << (*p).nome << endl;
        cout << "Quantidade: " << (*p).quantidade << endl;
        cout << "Preco p/unidade: R$ " << (*p).preco << endl;
    }
    void atualizarQuantidade(Produto *estoque, int qtd){
        int cod;
        if (qtd == 0) {
            cout << "\nNenhum produto cadastrado para atualizar." << endl;
            return;
        }
        cout << "Informe o codigo do produto: ";
        cin >> cod;

        int indice = buscarPorCodigo(estoque, qtd, codigo);
        if (indice == -1) {
            cout << "\n Produtp com codigo " << cod << " nao encontrado." << endl;
            return;
        }
    Produto *p = estoque + indice;
    cout << "Produto encontrado : " << (*p).nome << endl;
    cout << "Quantidade Atual: " << (*p).quantidade << endl;

    int novaQtd;
        do{
            cout << "Informe a nova Quantidade em estoque: ";
            cin >> novaQtd;
            if (novaQtd < 0){
                cout << "A QUANTIDADE NAO PODE SER NEGATIVA!" << endl;
            }while (novaQtd < 0);
            (*p).quantidade = novaQtd;
            cout << "\nQuantidade Atualizada para " << (*p).quantidade << "unidades." << endl;
        }
    void excluirProduto (Produto *estoque, int *qtd){
        Produto *p;
        Produto *ultimo;
        int cod;
        int indice;
        if (*qtd == 0){
            cout << "\nNenhum produto Cadastrado para excluir." << endl;
            return;
        }
        cout << "Informe o codigo do produto para excluir: ";
        cin >> cod;
        indice + buscarPorCodigo(estoque, *qtd, cod);
        if (indice == -1){
            cout << "Produto com Codigo " << cod << "nao encontrado";
            return;
        }
        while (p < ultimo){
            *p = *(p + 1);
            p++;
        }
        (*qtd)--;
        cout << "\Produto Removido Com Sucesso. Vetor organizado e sem lacunas" << endl;
    }
    float calcularValorTotal(const Produto *estoque, int qtd){
        float total = 0.0;
        for (int i = 0; i < qtd; i++){
            const Produto *p = estoque + i;
            total += (*p)quantidade * (*(p).preco);
        }
        return total; git bash
    }
#endif
