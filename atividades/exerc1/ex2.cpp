#include <iostream>

using namespace std;

int main (){
    class contaBancaria{
        public:
            int conta;
            string nome;
            float saldo;
            void deposito(float valor){
                saldo += valor;
            }
            void saque(float valor){
                saldo -= valor;
            }
    };
    float deposito;
    float saque;

    contaBancaria n1;
    
    cout << "Digite o numero da conta: ";
    cin >> n1.conta;
    cout << "Digite o nome do titular: ";
    cin >> n1.nome;
    cout << "Digite o saldo inicial: ";
    cin >> n1.saldo;
    cout << "Digite o valor do deposito: ";
    
    cin >> deposito;
    n1.deposito(deposito);
    cout << "Digite o valor do saque: ";

    cin >> saque;
    n1.saque(saque);
    cout << "Saldo final: " << n1.saldo << endl;

}