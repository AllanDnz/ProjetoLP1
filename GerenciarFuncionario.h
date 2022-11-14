#include "Funcionario.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Presidente.h" 
#include <vector>
#pragma once


class GerenciarFuncionario
{
public:
    GerenciarFuncionario();
    ~GerenciarFuncionario();


    void adicionarNovoFuncionario(int codigo, string nome, string endereco, string telefone, Data dataDeIngresso, string designacao, float salario);
    void editarRegistroDeUmFuncionario();
    void excluirRegistroDeFuncionario();

    void exibirListaDeFuncionarios();
    void exibirListaDeFuncionariosPorTipo();
    void exibirRegistroDeUmFuncionario();

    vector<Funcionario*> getListaFuncionarios();


protected:
    vector<Funcionario*> funcionarios;
    

};

