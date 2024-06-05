#include <iostream>
#include <vector>
#include "livro.hpp"

using namespace std;

livro::livro(string _titulo, string _autor, string _editora, string _publicacao, string _isbn){
    titulo = _titulo;
    autor = _autor;
    editora = _editora;
    publicacao = _publicacao;
    isbn = _isbn;
    exemplares = 1;
    id = -1;
}

string livro::getPublicacao(){
    return publicacao;
}

string livro::getIsbn(){
    return isbn;
}

void livro::novoExemplar(){
    exemplares++;
}

int livro::getExemplares(){
    return exemplares;
}

void livro::deletarExemplar(){
    exemplares--;
}

bool livro::checarDisponibilidade(){
    if(exemplares > 0){
        return true;
    }else{
        return false;
    }
}

void livro::setId(vector<livro> &livros){
    for (int i = 0; i < livros.size(); i++){
        if(livros.at(i).getIsbn() == isbn){
            id = i;
        }
    }
}
        
int livro::getId(){
    return id;
}