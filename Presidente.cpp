#include "Funcionario.h"
#include "Presidente.h"
#include <iostream>

using namespace std;

Presidente::Presidente(){

}

string Presidente::getAreaDeFormacao(){
    return areaDeFormacao;
}

string Presidente::getFormacaoAcademicaMax(){
    return formacaoAcademicaMax;
}

void Presidente::setAreaDeFormacao(string areaDeFromacao){
    this->areaDeFormacao = areaDeFormacao;
}

void Presidente::setFormacaoAcademicaMax(string formacaoAcademicaMax){
    this->formacaoAcademicaMax = formacaoAcademicaMax;
}