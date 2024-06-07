#include <iostream>
#include <vector>
#include "chamada.hpp"
#include "livro.hpp"
#include "usuario.hpp"
#include "classFunc.hpp"

using namespace std;

usuario::usuario(string _nome, string _senha, int _dtaNascimento[3], string _email, string _telefone)
{
    nome = _nome;
    senha = _senha;
    dtaNascimento[0] = _dtaNascimento[0];
    dtaNascimento[1] = _dtaNascimento[1];
    dtaNascimento[2] = _dtaNascimento[2];
    email = _email;
    telefone = _telefone;
    multa = 0;
    status = true;
}

void usuario::setNome(string _nome)
{
    nome = _nome;
}

string usuario::getSenha()
{
    return senha;
}

void usuario::setSenha(string _senha)
{
    senha = _senha;
}

int* usuario::getDtaNascimento()
{
    return dtaNascimento;
}

void usuario::setDtaNascimento(int _dtaNascimento[3])
{
    dtaNascimento[0] = _dtaNascimento[0];
    dtaNascimento[1] = _dtaNascimento[1];
    dtaNascimento[2] = _dtaNascimento[2];
}

string usuario::getEmail()
{
    return email;
}

void usuario::setEmail(string _email)
{
    email = _email;
}

string usuario::getTelefone()
{
    return telefone;
}

void usuario::setTelefone(string _telefone)
{
    telefone = _telefone;
}

float usuario::getMulta(vector<chamada> &chamadas)
{
    checarMulta(chamadas);
    return multa;
}

bool usuario::getStatus()
{
    usuario::checarStatus();
    return status;
}

void usuario::checarStatus()
{
    if (multa > 50)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}

void usuario::setId(vector<usuario> &usuarios)
{
    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios.at(i).getEmail() == email)
        {
            id = i;
        }
    }
}

int usuario::getId()
{
    return id;
}

int usuario::getEmprestimos()
{
    return emprestimos;
}

void usuario::addEmprestimo()
{
    emprestimos++;
}

void usuario::checarMulta(vector<chamada> &chamadas)
{
    int dtaAtual[3];
    int timesRan = 0;
    cout << "Digite o dia atual: ";
    cin >> dtaAtual[0];
    cout << "Digite o mes atual: ";
    cin >> dtaAtual[1];
    cout << "Digite o ano atual: ";
    cin >> dtaAtual[2];
    while (timesRan < emprestimos)
    {
        for (int i = 0; i < chamadas.size(); i++)
        {
            if (chamadas.at(i).getIdUsuario() == id)
            {
                if (chamadas.at(i).getAtrasado())
                {
                    int dias = diasAte(chamadas.at(i).getDtaVenc(), dtaAtual);

                    if (dias > 0)
                    {
                        multa += dias * 2;
                        chamadas.at(i).setAtrasado();
                    }
                }
                timesRan++;
            }
        }
    }
}

void usuario::pagarMulta(float valor, vector<chamada> &chamadas)
{
    checarMulta(chamadas);
    multa -= valor;
}

void usuario::devolverLivro(vector<chamada> &chamadas, vector<livro> &livros)
{
    string titulo;
    int diaAtual[3];
    int idLivro;
    int op;
    cout << "Digite o dia atual: ";
    cin >> diaAtual[0];
    cout << "Digite o mes atual: ";
    cin >> diaAtual[1];
    cout << "Digite o ano atual: ";
    cin >> diaAtual[2];
    cout << "Digite o titulo do livro que deseja devolver: ";
    cin >> titulo;
    for (int i = 0; i < livros.size(); i++)
    {
        if (livros.at(i).titulo == titulo)
        {
            idLivro = i;
            break;
        }
    }
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente?(1 - sim 0 - nao)" << endl;
    cin >> op;
    if (op == 1)
    {
        devolverLivro(chamadas, livros);
        return;
    }

    for (int i = 0; i < chamadas.size(); i++)
    {
        if (chamadas.at(i).getIdUsuario() == id and chamadas.at(i).getIdLivro() == idLivro)
        {
            chamadas.at(i).setStatus();
            int dias = diasAte(chamadas.at(i).getDtaVenc(), diaAtual);
            if (dias > 0 and chamadas.at(i).getAtrasado() == false)
            {
                multa += dias * 2;
                chamadas.at(i).setAtrasado();
            }
            livros.at(idLivro).novoExemplar();
            cout << "Livro devolvido com sucesso!" << endl;
            return;
        }
    }
}