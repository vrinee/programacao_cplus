#include <iostream>
#include <vector>
#include "admin.hpp"
#include "usuario.hpp"
#include "livro.hpp"
#include "chamada.hpp"
#include "classFunc.hpp"

using namespace std;

admin::admin(string _nome, string _senha)
{
    nome = _nome;
    senha = _senha;
}

string admin::getSenha()
{
    return senha;
}

usuario admin::cadastrarUsuario()
{
    string nome;
    string senha;
    int dtaNascimento[3];
    string email;
    string telefone;
    cout << "Digite o nome do usuario: ";
    cin >> nome;
    cout << "Digite a senha do usuario: ";
    cin >> senha;
    cout << "Digite o dia de nascimento do usuario: ";
    cin >> dtaNascimento[0];
    cout << "Digite o mes de nascimento do usuario: ";
    cin >> dtaNascimento[1];
    cout << "Digite o ano de nascimento do usuario: ";
    cin >> dtaNascimento[2];
    cout << "Digite o email do usuario: ";
    cin >> email;
    cout << "Digite o telefone do usuario: ";
    cin >> telefone;
    usuario user(nome, senha, dtaNascimento, email, telefone);
    return user;
}

void admin::deletarUsuario(vector<usuario> &usuarios)
{
    string nome;
    int op;
    cout << "Digite o nome do usuario que deseja deletar: ";
    cin >> nome;
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios.at(i).nome == nome)
        {
            usuarios.erase(usuarios.begin() + i);
            cout << "Usuario deletado com sucesso!" << endl;
            return;
        }
    }
    cout << "Usuario nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    if (op == 1)
    {
        deletarUsuario(usuarios);
    }
}

livro admin::novoLivro()
{
    string titulo;
    string autor;
    string editora;
    string publicacao;
    string isbn;
    cout << "Digite o titulo do livro: ";
    cin >> titulo;
    cout << "Digite o autor do livro: ";
    cin >> autor;
    cout << "Digite a editora do livro: ";
    cin >> editora;
    cout << "Digite a data de publicacao do livro: ";
    cin >> publicacao;
    cout << "Digite o ISBN do livro: ";
    cin >> isbn;
    livro book(titulo, autor, editora, publicacao, isbn);
    return book;
}

void admin::deletarLivro(vector<livro> &livros)
{
    string titulo;
    int op;
    cout << "Digite o titulo do livro que deseja deletar: ";
    cin >> titulo;
    for (int i = 0; i < livros.size(); i++)
    {
        if (livros.at(i).titulo == titulo)
        {
            livros.erase(livros.begin() + i);
            cout << "Livro deletado com sucesso!" << endl;
            return;
        }
    }
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    if (op == 1)
    {
        deletarLivro(livros);
    }
}

chamada admin::novoEmprestimo(vector<livro> &livros, vector<usuario> &usuarios)
{
    string titulo;
    string nome;
    int op;
    int dtaEmprestimo[3];
    cout << "Digite o titulo do livro que deseja emprestar: ";
    cin >> titulo;
    cout << "Digite o nome do usuario que deseja emprestar o livro: ";
    cin >> nome;
    for (int i = 0; i < livros.size(); i++)
    {
        if (livros.at(i).titulo == titulo)
        {
            for (int j = 0; j < usuarios.size(); j++)
            {
                if (usuarios.at(j).nome == nome)
                {
                    if (livros.at(i).checarDisponibilidade())
                    {
                        cout << "Livro disponivel!" << endl;
                        cout << "Digite o dia de emprestimo: " << endl;
                        cin >> dtaEmprestimo[0];
                        cout << "Digite o mes de emprestimo: " << endl;
                        cin >> dtaEmprestimo[1];
                        cout << "Digite o ano de emprestimo: " << endl;
                        cin >> dtaEmprestimo[2];
                        livros.at(i).deletarExemplar();
                        chamada call(dtaEmprestimo, i, j);
                        usuarios.at(j).addEmprestimo();
                        return call;
                    }
                    else
                    {
                        cout << "Livro nao disponivel!" << endl;
                        return;
                    }
                }
            }
            cout << "Usuario nao encontrado!" << endl;
            cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
            cin >> op;
            if (op == 1)
            {
                novoEmprestimo(livros, usuarios);
            }
            return;
        }
    }
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    if (op == 1)
    {
        novoEmprestimo(livros, usuarios);
    }
}