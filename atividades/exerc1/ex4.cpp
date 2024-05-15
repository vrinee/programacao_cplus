#include <iostream>

using namespace std;

int main(){
    class aluno{
        public:
            string nome;
            int matricula;

            void setNota1(float _nota1){
                nota1 = _nota1;
            }
            void setNota2(float _nota2){
                nota2 = _nota2;
            }
            void setNota3(float _nota3){
                nota3 = _nota3;
            }
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
        private:
            float nota1;
            float nota2;
            float nota3;

    };
    aluno a;
    float x,y,z;
    cout << "Digite o nome do aluno: ";
    cin >> a.nome;
    cout << "Digite a matricula do aluno: ";
    cin >> a.matricula;
    cout << "Digite a primeira nota: ";
    cin >> x;
    cout << "Digite a segunda nota: ";
    cin >> y;
    cout << "Digite a terceira nota: ";
    cin >> z;
    a.setNota1(x);
    a.setNota2(y);
    a.setNota3(z);
    cout << "Media: " << a.media() << endl;
    a.situacao();    
}