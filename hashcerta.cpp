#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define TABLE_SIZE 13

typedef struct item {
    int chave;
    int valor;
} item;

item tabela_hash[TABLE_SIZE];

int modulo(int chave) {
    return chave % TABLE_SIZE;
}

void inserir_na_hash(int chave, int valor) {
    int referencia = modulo(chave);
    int colisao=0;
    string colisao_string;
    int tamanho_string;
    string nova_string;
    int nova_chave;
    int multiplicação=100;
    bool conseguiu = false;
    int nova_referencia = 0;

    if (tabela_hash[referencia].chave == -1) {
        tabela_hash[referencia].chave = chave;
        tabela_hash[referencia].valor = valor;

        cout << endl << "referencia: " << referencia << endl;
        cout << "chave: " << tabela_hash[referencia].chave << endl;
        cout << "valor" << tabela_hash[referencia].valor << endl;
    }
    else {
        do {
            cout << endl << "colisao" << endl;
            
            colisao = (chave*multiplicação)*(chave*multiplicação);
            cout << endl << "colisao: " << colisao << endl;
            
            colisao_string = to_string(colisao);
            tamanho_string = colisao_string.size();
            
            nova_string = colisao_string.substr(tamanho_string/2, 2);
            cout << endl << "nova string: " << nova_string << endl;
            
            nova_chave = stoi(nova_string);
            
            nova_referencia = modulo(nova_chave);

            if (tabela_hash[nova_referencia].chave == -1) {
                cout << endl << "nova referencia: " << referencia << endl;
                tabela_hash[nova_referencia].chave = chave;
                tabela_hash[nova_referencia].valor = valor; 
                cout << "chave: " << tabela_hash[nova_referencia].chave << endl;
                cout << "valor: " << tabela_hash[nova_referencia].valor << endl;
                conseguiu = true;
                break;
            }
            else {
                cout << endl << "mesmo lugar" << endl;
                multiplicação = multiplicação +1;
            }
        }while(conseguiu == false);
    }
    conseguiu = false;
}

int main() {
    item item;
    int ask = 0;

    for (int i=0; i<TABLE_SIZE;i++) {        
        tabela_hash[i].chave = -1;
        tabela_hash[i].valor = 0;
    }

    do {
        cout << endl << "chave: ";
        cin >> item.chave;
        cout << endl << "valor: ";
        cin >> item.valor;
        inserir_na_hash(item.chave, item.valor);

        for (int i=0; i<TABLE_SIZE;i++) {
            cout << "posicao [" << i << "] = chave: " << tabela_hash[i].chave << " | valor: " << tabela_hash[i].valor << endl;
        }

        item.chave = 0;
        item.valor = 0;

        cout << endl << "continue?(1=nao)(0=sim):  ";
        cin >> ask;
    } while(ask == 0);
}