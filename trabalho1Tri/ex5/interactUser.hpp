#include <iostream>
#include <vector>
#include "classes/admin.hpp"
#include "classes/usuario.hpp"
#include "classes/livro.hpp"
#include "classes/chamada.hpp"
#include "classes/classFunc.hpp"

using namespace std;

int loginAdmin(vector<admin> &admins);

admin createAdmin();

// funções de criação
    void createUser(vector<usuario> &usuarios, admin &admin);

    int loginUser(vector<usuario> &usuarios);

    void createBook(vector<livro> &livros, admin &admin);

    void createChamada(vector<chamada> &chamadas,vector<usuario> &usuarios, vector<livro> &livros, admin &admin);
// Fim das funções de criação

// Funções de listagem
    void listarUsuarios(vector<usuario> &usuarios);

    void listarAtributosUser(usuario user, vector<chamada> &chamadas);

    void listarAdmins(vector<admin> &admins);

    void listarLivros(vector<livro> &livros);

    void listarAtributosLivro(livro book);

    void listarChamadas(vector<chamada> &chamadas, vector<usuario> &usuarios, vector<livro> &livros);

    void listarAtributosChamada(chamada call, vector<usuario> &usuarios, vector<livro> &livros);
// Fim das funções de listagem

// Funções de ação

    void pagamento(usuario &user, vector<chamada> &chamadas);

    void devolucao(usuario &user, vector<livro> &livros, vector<chamada> &chamadas);

    void mudarAtributosUser(usuario &user);

    void retirarExemplar(livro &book);

    void checarMulta(vector<chamada> &chamadas, usuario &user);

    void userActions(vector<usuario> &usuarios, vector<livro> &livros, vector<chamada> &chamadas);