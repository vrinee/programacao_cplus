#include <iostream>

using namespace std;

int main(){
    class aluno{
        public:
            string nome;
            int matricula;
            float nota1;
            float nota2;
            float nota3;
            float media(){
                return (nota1 + nota2 + nota3) / 3;
            }
            void situacao(){
                if (media() >= 7){
                    cout << "Aprovado" << endl;
                } else {
                    cout << "Reprovado" << endl;
                }
            }
    };
    aluno a;
    cout << "Digite o nome do aluno: ";
    cin >> a.nome;
    cout << "Digite a matricula do aluno: ";
    cin >> a.matricula;
    cout << "Digite a primeira nota: ";
    cin >> a.nota1;
    cout << "Digite a segunda nota: ";
    cin >> a.nota2;
    cout << "Digite a terceira nota: ";
    cin >> a.nota3;
    cout << "Media: " << a.media() << endl;
    a.situacao();    
}