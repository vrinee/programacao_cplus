#include <iostream>

using namespace std;

int main(){
    class retangulo{
        public:
            float largura;
            float altura;
            float perimetro(){
                return 2 * (largura + altura);
            }
            float area(){
                return largura * altura;
            }
    };

    retangulo r;

    cout << "Digite a largura do retangulo: ";
    cin >> r.largura;
    cout << "Digite a altura do retangulo: ";
    cin >> r.altura;
    cout << "Perimetro: " << r.perimetro() << endl;
    cout << "Area: " << r.area() << endl;
}