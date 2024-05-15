#include <iostream>

using namespace std;

int main (){
    class contaBancaria{
        public:
            int conta;
            string nome;
            
            void setSaldo(float _saldo){
                saldo = _saldo;
            }

            void getSaldo(){
                cout << "Saldo: " << saldo << endl;
            }

            void deposito(float valor){
                saldo += valor;
            }
            void saque(float valor){
                saldo -= valor;
            }
        private:
            float saldo;
    };
    float deposito;
    float saque;
    float x;

    contaBancaria n1;
    
    cout << "Digite o numero da conta: ";
    cin >> n1.conta;
    cout << "Digite o nome do titular: ";
    cin >> n1.nome;
    cout << "Digite o saldo inicial: ";
    cin >> x;
    n1.setSaldo(x);
    cout << "Digite o valor do deposito: ";
    
    cin >> deposito;
    n1.deposito(deposito);
    cout << "Digite o valor do saque: ";

    cin >> saque;
    n1.saque(saque);
    n1.getSaldo();

}