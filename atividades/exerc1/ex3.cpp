#include <iostream>

using namespace std;

int main(){
    class retangulo{
        public:
            void setLargura(float _largura){
                largura = _largura;
            }
            void setAltura(float _altura){
                altura = _altura;
            }
            float perimetro(){
                return 2 * (largura + altura);
            }
            float area(){
                return largura * altura;
            }
        private:
            float largura;
            float altura;

    };

    retangulo r;
    float x,y;
    cout << "Digite a largura do retangulo: ";
    cin >> x;
    r.setLargura(x);
    cout << "Digite a altura do retangulo: ";
    cin >> y;
    r.setAltura(y);
    cout << "Perimetro: " << r.perimetro() << endl;
    cout << "Area: " << r.area() << endl;
}