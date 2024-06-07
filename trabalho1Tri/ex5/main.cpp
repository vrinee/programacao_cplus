#include <iostream>
#include <vector>
#include "classes/admin.hpp"
#include "classes/usuario.hpp"
#include "classes/livro.hpp"
#include "classes/chamada.hpp"
#include "classes/classFunc.hpp"
#include "interactUser.hpp"


using namespace std;


int main(){
    vector<admin> admins;
    vector<usuario> usuarios;
    vector<livro> livros;
    vector<chamada> chamadas;
    bool running = true;
    int adminIndex = -1;

    admins.push_back(createAdmin());

    while(running){
        if (adminIndex == -1){
            adminIndex = loginAdmin(admins);
        }
        if (adminIndex != -1){
            int op;
            int op2;
            string email;
            string nome;
            string titulo;
            string emailUser;
            string nomeUser;
            string tituloBook;
            int userIndex = -1;
            int chamadaIndex = -1;
            int bookIndex = -1;
            cout << "1 - Cadastrar usuario" << endl;
            cout << "2 - Cadastrar livro" << endl;
            cout << "3 - Cadastrar chamada" << endl;
            cout << "4 - Listar usuarios" << endl;
            cout << "5 - Listar livros" << endl;
            cout << "6 - Listar chamadas" << endl;
            cout << "7 - Listar admins" << endl;
            cout << "8 - Listar atributos de um usuario" << endl;
            cout << "9 - Listar atributos de um livro" << endl;
            cout << "10 - Listar atributos de uma chamada" << endl;
            cout << "11 - Deletar exemplar de um livro" << endl;
            cout << "12 - Deletar usuario" << endl;
            cout << "13 - Deletar livro" << endl;
            cout << "14 - Ações de usuario" << endl;
            cout << "15 - Sair" << endl;
            cin >> op;
            switch(op){
                case 1:
                    createUser(usuarios, admins[adminIndex]);
                    break;
                case 2:
                    createBook(livros, admins[adminIndex]);
                    break;
                case 3:
                    createChamada(chamadas, usuarios, livros, admins[adminIndex]);
                    break;
                case 4:
                    listarUsuarios(usuarios);
                    break;
                case 5:
                    listarLivros(livros);
                    break;
                case 6:
                    listarChamadas(chamadas, usuarios, livros);
                    break;
                case 7:
                    listarAdmins(admins);
                    break;
                case 8:
                    cout << "Digite o email do usuario: ";
                    cin >> email;
                    cout << "Digite o nome do usuario: ";
                    cin >> nome;
                    for(int i = 0; i < usuarios.size(); i++){
                        if (usuarios[i].getEmail() == email && usuarios[i].nome == nome){
                            userIndex = i;
                            break;
                        }
                    }
                    if (userIndex != -1){
                        listarAtributosUser(usuarios[userIndex], chamadas);
                    } else {
                        cout << "Usuario não encontrado" << endl;
                    }

                    break;
                case 9:
                    cout << "Digite o titulo do livro: ";
                    cin >> titulo;
                    for(int i = 0; i < livros.size(); i++){
                        if (livros[i].titulo == titulo){
                            bookIndex = i;
                            break;
                        }
                    }
                    if (bookIndex != -1){
                        listarAtributosLivro(livros[bookIndex]);
                    } else {
                        cout << "Livro não encontrado" << endl;
                    }
                    
                    break;
                case 10:
                    cout << "Digite o email do usuario: ";
                    cin >> emailUser;
                    cout << "Digite o nome do usuario: ";
                    cin >> nomeUser;
                    cout << "Digite o titulo do livro: ";
                    cin >> tituloBook;

                    for(int i = 0; i < usuarios.size(); i++){
                        if (usuarios[i].getEmail() == emailUser && usuarios[i].nome == nomeUser){
                            userIndex = i;
                            break;
                        }
                    }

                    for(int i = 0; i < livros.size(); i++){
                        if (livros[i].titulo == tituloBook){
                            bookIndex = i;
                            break;
                        }
                    }

                    if (userIndex != -1 && bookIndex != -1){
                        for(int i = 0; i < chamadas.size(); i++){
                            if (chamadas[i].getIdUsuario() == usuarios[userIndex].getId() && chamadas[i].getIdLivro() == livros[bookIndex].getId()){
                                chamadaIndex = i;
                                break;
                            }
                        }
                        if (chamadaIndex != -1){
                            listarAtributosChamada(chamadas[chamadaIndex], usuarios, livros);
                        } else {
                            cout << "Chamada não encontrada" << endl;
                        }
                    } else {
                        cout << "Usuario ou livro não encontrado" << endl;
                    }

                    break;
                case 11:
                    cout << "Digite o titulo do livro: ";
                    cin >> tituloBook;
                    for(int i = 0; i < livros.size(); i++){
                        if (livros[i].titulo == tituloBook){
                            bookIndex = i;
                            break;
                        }
                    }
                    if (bookIndex != -1){
                        retirarExemplar(livros[bookIndex]);
                    } else {
                        cout << "Livro não encontrado" << endl;
                    }
                    
                    break;
                case 12:
                    admins[adminIndex].deletarUsuario(usuarios);
                    break;
                case 13:
                    admins[adminIndex].deletarLivro(livros);
                    break;
                case 14:
                    userActions(usuarios, livros, chamadas);
                    break;
                case 15:
                    cout << "Deseja sair ou fazer outro login?(1 - sair 0 - fazer outro login)" << endl;
                    cin >> op2;
                    if (op2 == 1){
                        running = false;
                    } else {
                        adminIndex = -1;
                    }
                    break;
                default:
                    cout << "Opção invalida" << endl;
                    break;
            }
        }
        
    }
}