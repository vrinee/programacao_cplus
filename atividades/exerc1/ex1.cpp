#include <iostream>
#define PI 3.14159

using namespace std;

class Circulo{
    public:
        float perimetro() const{
            return 2 * PI * raio;
        }
        float area() const{
            return PI * raio * raio;
        }
        void setRaio(float _raio){
            raio = _raio;
        }        
    private:
        float raio;
};

int main(){
    Circulo c;
    float x;
    cout << "Digite o raio do circulo: ";
    cin >> x;
    c.setRaio(x); 
    cout << "Perimetro: " << c.perimetro() << endl;
    cout << "Area: " << c.area() << endl;
}

