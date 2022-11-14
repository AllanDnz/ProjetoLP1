#include "Funcionario.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Presidente.h" 

#pragma once


class GerenciarFuncionario
{
public:
    GerenciarFuncionario();
    ~GerenciarFuncionario();


    int adicionarNovoFuncionario();
    int editarRegistroDeUmFuncionario();
    int excluirRegistroDeFuncionario();

    void exibirListaDeFuncionarios();
    void exibirListaDeFuncionariosPorTipo();
    void exibirRegistroDeUmFuncionario();

    vector<Funcionario*> getListaFuncionarios;


protected:
    vector<Funcionario*> listaFuncionarios;

};

