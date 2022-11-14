#include "Funcionario.h"
#include "data.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(){
    codigo = 0;
    nome = "";
    endereco = "";
    designacao = "";
    telefone = "";
    salario = 0;
}

Funcionario::Funcionario(int tipo){
    
}


Funcionario::Funcionario(int codigo, string nome, string endereco, string designacao,
Data dataDeIngresso, string telefone, float salario){

    SetCodigo(codigo);
    setNome(nome);
    setEndereco(endereco);
    setDesignacao(designacao);
    setDataDeIngresso(dataDeIngresso);
    setTelefone(telefone);
    setSalario(salario);
}


string Funcionario::getNome(){
    return nome;
}

int Funcionario::getCodigo(){
    return codigo;
}

Data Funcionario::getDataDeIngresso(){
    return dataDeIngresso; 
}

string Funcionario::getDesignacao(){
    return designacao;
} 

string Funcionario::getEndereco(){
    return endereco;
}


string Funcionario::getTelefone(){
    return telefone;
}

float Funcionario::getSalario(){
    return salario;
}


void Funcionario::setNome(string nome){
    this->nome = nome;
}

void Funcionario::setEndereco(string endereco){
    this->endereco = endereco;
}

void Funcionario::setTelefone(string telefone){
    this->telefone = telefone;
}

void Funcionario::setDataDeIngresso(Data dataDeIngresso){
    this->dataDeIngresso = dataDeIngresso;
}

void Funcionario::setDesignacao(string designacao){
    this->designacao = designacao;
}

void Funcionario::setSalario(float salario){
    this->salario = salario;
}

void Funcionario::SetCodigo(int codigo){
    this->codigo = codigo;
}

string Funcionario::toString(){
    return this->codigo + "\n" + this->nome + "\n" + this->endereco + "\n" + this->telefone + "\n" + this->dataDeIngresso.getData() + "\n" + this->designacao + "\n" + to_string(this->salario);
}
