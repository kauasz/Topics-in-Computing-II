// name: Kauã de Souza Ferreira.

#include <iostream>

using namespace std;

struct Elemento {
    int linha;
    int coluna;
    int valor;
    Elemento* proximo;
};

class MatrizEsparsa {
private:
    Elemento* inicio;

public:
    MatrizEsparsa() {
     inicio = NULL;
    }

    void inserir(int l, int c, int v) {
        if (v == 0) return;

        Elemento* novoElemento = new Elemento();
        novoElemento -> linha = l;
        novoElemento -> coluna = c;
        novoElemento -> valor = v;
        novoElemento -> proximo = NULL;

        if (inicio == NULL) {
         inicio = novoElemento;
        } else {
            Elemento* atual = inicio;
            while (atual -> proximo != NULL) {
                atual = atual -> proximo;
            }
            atual -> proximo = novoElemento;
        }
    }

    void mostrarListaEncadeada() {
        Elemento* atual = inicio;
        cout << "Lista encadeada: \n" << endl;
        
        if (atual == NULL) {
            cout << "Lista vazia." << endl;
            return;
        }

        while (atual != NULL) {
            cout << "[" << atual -> linha << ", " << atual -> coluna << "] = " << atual -> valor;
            if (atual -> proximo != NULL) cout << "\n";
            atual = atual -> proximo;
        }
        cout << "\n" << endl;
    }

    void reconstruirMatriz(int totalLinhas, int totalColunas) {
        cout << "\nMatriz reconstruida (processo inverso): \n" << endl;
        
        for (int i = 0; i < totalLinhas; i++) {
            for (int j = 0; j < totalColunas; j++) {
                int valorParaImprimir = 0;
                
                Elemento* atual = inicio;
                while (atual != NULL) {
                    if (atual -> linha == i && atual -> coluna == j) {
                        valorParaImprimir = atual -> valor;
                        break;
                    }
                    atual = atual -> proximo;
                }
                
                cout << valorParaImprimir << "\t";
            }
            cout << endl;
        }
    }
    
    ~MatrizEsparsa() {
        Elemento* atual = inicio;
        while (atual != NULL) {
            Elemento* prox = atual -> proximo;
            delete atual;
            atual = prox;
        }
    }
};

int main() {
    MatrizEsparsa matriz;
    int linhas, colunas;

    cout << "Informe o numero de linhas da matriz: ";
    cin >> linhas;
    cout << "Informe o numero de colunas da matriz: ";
    cin >> colunas;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int valor;
            cout << "Valor da posicao [" << i << "][" << j << "]: ";
            cin >> valor;
            
            matriz.inserir(i, j, valor);
        }
    }

    cout << endl;
    
    matriz.mostrarListaEncadeada();

    matriz.reconstruirMatriz(linhas, colunas);

    cout << endl;

    return 0;
}