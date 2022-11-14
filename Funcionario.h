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
        
        int getCodigo(); //Retorna o valor do código de um funcionario
        string getNome(); //Retorna o nome de um funcionario
        string getEndereco(); //Retorna o endereço de um funcionario
        string getTelefone(); //Retorna o telefone de um funcionario
        Data getDataDeIngresso(); //Retorna a data de ingresso dd/mm/yyyy de um funcionario
        string getDesignacao(); //Retorna a função no trabalho de um funcionario
        float getSalario(); //Retorna o salario de um funcionario
        void setNome(string nome); //Define o nome de um funcionario
        void setEndereco(string endereco); //Define o endereço de um funcionario
        void setTelefone(string telefone); //Define o telefone de um funcionario
        void setDataDeIngresso(Data dataDeIngresso); //Define a data de ingresso dd/mm/yyyy de um funcionario 
        void setDesignacao(string designacao); //Define a designação(operador, diretor,gerente,presidente)
        void setSalario(float salario); //Define o salario do funcionario 
        void SetCodigo(int codigo); //Define o codigo do funcionario
        string toString(); //Retorna todas as informações do funcionario como string 

    protected:
        int codigo;
        float salario;
        string nome;
        string endereco;
        string telefone;
        Data dataDeIngresso;
        string designacao;
        


};