// Nome: Kauã de Souza Ferreira.

#include <iostream>
#include <cmath> // Utilização do PI //

using namespace std;

// ========== Classe (Volume do Cubo) ========== //

class Cubo{
    public:
        double a;
        double volume;

        Cubo(double aresta){ // Declaração do construtor. //
            a = aresta;
        }

        ~Cubo(){ // Declaração do destrutor. //
            // cout << "Informações salvas!" << endl; //
        }

        virtual void Volume(){ // Cálculo do volume (virtual, pois pode ser modificada.) //
            volume = a*a*a;
        }

        double getVolume(){ 
            return volume;
        }
};

// ========== Classe (Volume da Esfera) ========== //

// Classe base: Cubo - Classe filha: Esfera //
class Esfera: public Cubo{
    public:
        double r;

        Esfera(double raio): Cubo(raio){ // Declaração do construtor. //
            r = raio;
        }

        ~Esfera(){ // Declaração do destrutor. //
            // cout << "Informações salvas!" << endl; //
        }

        virtual void Volume() override{ // Cálculo do volume (virtual, pois pode ser modificada.) //
            volume = (4.0/3.0)*M_PI*pow(r, 3);  
        }
};

// ========== Classe (Volume do Cone) ========== //

// Classe base: Esfera - Classe filha: Cone //
class Cone: public Esfera{
    public:
        double h;

        Cone(double altura, double r): Esfera(r){ // Declaração do construtor. //
            h = altura;
        }

        ~Cone(){ // Declaração do destrutor. //
            // cout << "Informações salvas!" << endl; //
        }

        virtual void Volume() override{ // Cálculo do volume (virtual, pois pode ser modificada.) //
            volume = (1.0/3.0)*M_PI*pow(r, 2)*h;
        }
};

int main(){
    Cubo volumeCubo(10); // a (aresta) = 10 cm //
    volumeCubo.Volume();
    cout << "\nVolume do Cubo: " << volumeCubo.getVolume() << " cm^3" << endl;

    Esfera volumeEsfera(10); // r (raio) = 10 cm //
    volumeEsfera.Volume();
    cout << "Volume da Esfera: " << volumeEsfera.getVolume() << " cm^3" << endl;

    Cone volumeCone(10, 50); // h (altura) = 10 cm - r (raio) = 50 cm //
    volumeCone.Volume();
    cout << "Volume do Cone: " << volumeCone.getVolume() << " cm^3\n" << endl;

    return 0;
}
