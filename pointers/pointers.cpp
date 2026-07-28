// Nome: Kauã de Souza Ferreira.

#include <iostream>

using namespace std;

class EnsaioExperimental{
private:
    int tamanho;
    double* dados;
    double* dadosOrdenados;

public:
    EnsaioExperimental(int tam){
        if (tam <= 0) { // Medida de segurança.
            cout << "O tamanho deve ser positivo." << endl;

            tamanho = 0;
            dados = nullptr; // Ponteiro nulo, pois a entrada foi inválida.
            dadosOrdenados = nullptr;

            return;
        }

        tamanho = tam;
        dados = new double[tamanho]; // 'new double[tamanho]' cria um vetor de tamanho flexível.
        dadosOrdenados = new double[tamanho];
    }

    ~EnsaioExperimental(){ // Criação do destrutor.
        delete[] dados;
        delete[] dadosOrdenados;
        
        cout << "\nObjeto destruido." << endl;
    }

    void inserirDados(){
        for (int i = 0; i < tamanho; i++){
            cout << "Insira a medida [" << i << "]: ";
            cin >> dados[i];
        }

        cout << "Dados inseridos com sucesso." << endl;
    }

    // Sugestão de colega: ao invés de criar duas funções (uma para os dados originais e uma para os dados ordenados), foi feito o método a seguir.
    // Quando 'imprimirDados()' é false, imprimi o vetor 'dados'. Já, quando for true, imprimi o vetor 'dadosOrdenados'. 
    void imprimirDados(bool ordenados = false) const{
        if (tamanho == 0) return; // Para não ser impresso em casos do vetor ter tamanho zero.

        double* ptr = dados;
        string tipo = "vetor original";

        if (ordenados){
            ptr = dadosOrdenados;
            tipo = "vetor ordenado (bubble sort)";
        }

        cout << "\nDados do " << tipo << ": " << endl;
        cout << "[ ";
        for (int i = 0; i < tamanho; i++){
            cout << ptr[i] << (i == tamanho - 1 ? " " : ", ");
        }

        cout << "]" << endl;
    }

    void busca_valor(double n) const{
        if (tamanho == 0) return;

        bool encontrado = false; // Cria uma 'flag' que, inicialmente, é false (não encontrado) e se, posteriormente, encontrar o valor de 'n', será mudado para true (valor encontrado).
        
        cout << "\nBuscando o valor " << n << " no vetor." << endl;

        for (int i = 0; i < tamanho; i++){
            if (dados[i] == n){
                cout << "\n-> Valor " << n << " encontrado na posição " << i << endl;
                encontrado = true; // A 'flag' foi mudada para true, pois o valor foi encontrado.
            }
        }

        if (!encontrado){ // Se a 'flag' não foi mudada para true, ela continua false, ou seja, nada foi encontrado.
            cout << "\n-> Valor " << n << " não encontrado no vetor." << endl;
        }
    }

    void busca_com_parada(double n) const{
        if (tamanho == 0) return;
        
        cout << "\nBuscando a primeira ocorrência de " << n << "." << endl;

        for (int i = 0; i < tamanho; i++){
            if (dados[i] == n){
                cout << "\n-> Valor " << n << " encontrado na posição: " << i << endl;
                
                return;
            }
        }

        cout << "\n-> Valor " << n << " não encontrado no vetor." << endl;
    }

    void max_min() const{
        if (tamanho == 0){
            cout << "\nNo vetor vazio não há máximo e mínimo." << endl;
            
            return;
        }

        double max_val = dados[0];
        double min_val = dados[0];

        for (int i = 1; i < tamanho; i++){
            if (dados[i] > max_val){
                max_val = dados[i];
            }

            if (dados[i] < min_val){
                min_val = dados[i];
            }
        }

        cout << "\nValor máximo do vetor original: " << max_val << endl;
        cout << "Valor mínimo do vetor original: " << min_val << endl;
    }

    void moda() const{
        if (tamanho == 0){
            cout << "\nNão há moda em vetor vazio." << endl;

            return;
        }

        int quantidade = 0;
        double valorModa = dados[0];

        for (int i = 0; i < tamanho; i++){
            int contagem = 0;

            for (int j = 0; j < tamanho; j++){
                if (dados[j] == dados[i]){
                    contagem++;
                }
            }

            if (contagem > quantidade){
                quantidade = contagem;
                valorModa = dados[i];
            }
        }

        cout << "\nO valor " << valorModa << " apareceu " << quantidade << " vezes no vetor." << endl;
    }

    void bubble_sort(){
        if (tamanho == 0) return;

        for (int i = 0; i < tamanho; i++){
            dadosOrdenados[i] = dados[i]; // Cópia do vetor original para o vetor ordenado.
        }

        for (int i = 0; i < tamanho - 1; i++){
            for (int j = 0; j < tamanho - 1 - i; j++){
                if (dadosOrdenados[j] > dadosOrdenados[j + 1]){
                    double temp = dadosOrdenados[j]; // Variável temporária criada para guardar um dos valores para que a troca possa ser feita sem que nenhum valor seja 'perdido'.
                    dadosOrdenados[j] = dadosOrdenados[j + 1];
                    dadosOrdenados[j + 1] = temp;
                }
            }
        }
    }
};

int main(){
    int tam;

    cout << "Insira o tamanho do vetor de medidas: ";
    cin >> tam;

    EnsaioExperimental ensaio(tam);

    ensaio.inserirDados();
    ensaio.imprimirDados(false);

    ensaio.busca_valor(7); // Busca o valor 7 no vetor original.
    ensaio.busca_com_parada(5); // Busca o valor 5 na primeira ocorrência do vetor original.
    ensaio.max_min(); // Informa quais são os valores máximos e mínimos digitados no vetor original.
    ensaio.moda(); // Busca o valor do vetor original que apareceu com mais frequência.
    ensaio.bubble_sort(); // Ordena o vetor original.

    ensaio.imprimirDados(true);

    return 0;
}