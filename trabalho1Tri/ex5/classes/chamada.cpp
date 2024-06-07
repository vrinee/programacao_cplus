#include <iostream>
#include <vector>
#include "chamada.hpp"
#include "classFunc.hpp"


chamada::chamada(int _dtaEmprestimo[3], int _idLivro, int _idUsuario){
    dtaEmprestimo[0] = _dtaEmprestimo[0];
    dtaEmprestimo[1] = _dtaEmprestimo[1];
    dtaEmprestimo[2] = _dtaEmprestimo[2];
    adicionarDias(dtaEmprestimo, 15, &dtaVenc);
    idLivro = _idLivro;
    idUsuario = _idUsuario;
    status = true;
    atrasado = false;
}

int* chamada::getDtaVenc(){
    return dtaVenc;
}

void chamada::setDtaVenc(int &_dtaVenc){
    *dtaVenc = _dtaVenc;
}

int* chamada::getDtaEmprestimo(){
    return dtaEmprestimo;
}

int chamada::getIdLivro(){
    return idLivro;
}

int chamada::getIdUsuario(){
    return idUsuario;
}

bool chamada::getStatus(){
    return status;
}

void chamada::setStatus(){
    if (status)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}

bool chamada::getAtrasado(){
    return atrasado;
}

void chamada::setAtrasado(){
    if (atrasado)
    {
        atrasado = false;
    }
    else
    {
        atrasado = true;
    }
}

int chamada::getId(){
    return id;
}

void chamada::setId(vector<chamada> &chamadas){
    for (int i = 0; i < chamadas.size(); i++)
    {
        if (chamadas.at(i).getIdLivro() == idLivro and chamadas.at(i).getIdUsuario() == idUsuario and dtaEmprestimo == chamadas.at(i).getDtaEmprestimo())
        {
            id = i;
        }
    }
}
