#pragma once

#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Funcionario
{

    public:
        Funcionario();
        Funcionario(int codigo, string nome, string endereco, string designacao,
        Data dataDeIngresso, string telefone, float salario);
        Funcionario(int tipo);
        
        ~Funcionario();
        
        int getCodigo();
        string getNome();
        string getEndereco();
        string getTelefone();
        Data getDataDeIngresso(); 
        string getDesignacao();
        float getSalario();
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataDeIngresso(Data dataDeIngresso); 
        void setDesignacao(string designacao);
        void setSalario(float salario);
        void SetCodigo(int codigo);

    protected:
        int codigo;
        float salario;
        string nome;
        string endereco;
        string telefone;
        Data dataDeIngresso;
        string designacao;
        


};