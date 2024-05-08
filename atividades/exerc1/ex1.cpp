#include <iostream>

using namespace std;

int main(){
    class circulo{
        public:
            float raio;
            float perimetro(){
                return 2 * 3.14 * raio;
            }
            float area(){
                return 3.14 * raio * raio;
            }
    };
    circulo c;
    cout << "Digite o raio do circulo: ";
    cin >> c.raio;
    cout << "Perimetro: " << c.perimetro() << endl;
    cout << "Area: " << c.area() << endl;
}

