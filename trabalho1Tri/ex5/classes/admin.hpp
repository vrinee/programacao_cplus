#ifndef ADMIN_HPP
#define ADMIN_HPP


#include <iostream>
#include <vector>
#include "usuario.hpp"
#include "livro.hpp"
#include "chamada.hpp"
#include "classFunc.hpp"

using namespace std;


class admin{
    public:
        string nome;

        admin(string _nome, string _senha);

        string getSenha();

        usuario cadastrarUsuario();

        void deletarUsuario(vector<usuario> &usuarios);

        livro novoLivro();

        void deletarLivro(vector<livro> &livros);

        chamada novoEmprestimo(vector<livro> &livros, vector<usuario> &usuarios);

    private:
        string senha;
};

#endif