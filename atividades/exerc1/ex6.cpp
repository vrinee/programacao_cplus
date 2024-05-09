#include <iostream>

using namespace std;

int main(){

    class funcionario{
        public:
            string nome;
            float salario;
            float addAumento(double valor){
                return salario + valor;
            }
            float ganhoAnual(){
                return salario * 12;
            }
            void exibeDados(){
                cout << "Nome: " << nome << endl;
                cout << "Salario: " << salario << endl;
                cout << "Salario anual: " << ganhoAnual() << endl;
            }
    };

    class assistente : public funcionario{
        public:
            string matricula;
            void exibeDados(){
                cout << "Nome: " << nome << endl;
                cout << "Matricula: " << matricula << endl;
                cout << "Salario: " << salario << endl;
                cout << "Salario anual: " << ganhoAnual() << endl;
            }
    };

    class tecnico : public assistente{
        public:
            float bonus;
            float ganhoAnual(){
                return salario + bonus * 12;
            }
    };

    class administrativo : public assistente{
        public:
            string turno;
            float bonus;
            float adicionalNoturno(){
                if (turno == "noturno"){
                    return salario * bonus;
                } else {
                    return 0;
                }
            }
            float ganhoAnual(){
                return salario * 12 + adicionalNoturno() * 12;
            }
    };
}