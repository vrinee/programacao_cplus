#include <iostream>

using namespace std;

int main(){
    class funcionario{
        public:
            string nome;
            string cargo;
            float salario;
            float desconto(){
                int desct;
                cout << "Digite a porcentagem de desconto: ";
                cin >> desct;
                return salario * (1 - desct / 100);
            }
    };
    funcionario f;
    cout << "Digite o nome do funcionario: ";
    cin >> f.nome;
    cout << "Digite o cargo do funcionario: ";
    cin >> f.cargo;
    cout << "Digite o salario do funcionario: ";
    cin >> f.salario;
    cout << "Salario liquido: " << f.desconto() << endl;
}