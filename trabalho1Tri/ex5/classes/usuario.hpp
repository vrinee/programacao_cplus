#include <iostream>
#include <vector>
#include "chamada.hpp"
#include "livro.hpp"

using namespace std;

class usuario{
    public:
        string nome;
        
        usuario(string _nome, string _senha, int _dtaNascimento[3], string _email, string _telefone);

        void setNome(string _nome);

        string getSenha();

        void setSenha(string _senha);

        int *getDtaNascimento();

        void setDtaNascimento(int _dtaNascimento[3]);

        string getEmail();

        void setEmail(string _email);

        string getTelefone();

        void setTelefone(string _telefone);

        float getMulta(vector<chamada> &chamadas);

        bool getStatus();

        void checarStatus();

        void setId(vector<usuario> &usuarios);

        int getId();

        int getEmprestimos();

        void addEmprestimo();

        void checarMulta(vector<chamada> &chamadas);

        void pagarMulta(float valor, vector<chamada> &chamadas);
        void devolverLivro(vector<chamada> &chamadas, vector<livro> &livros);

    private:
        string senha;
        int dtaNascimento[3];
        string email;
        string telefone;
        float multa;
        bool status;
        int id;
        int emprestimos = 0;

};