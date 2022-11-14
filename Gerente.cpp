#include "Gerente.h"
#include "Funcionario.h"
#include <iostream>

using namespace std;

Gerente::Gerente() : Funcionario(1){
    areaDeSupervisao = "";
}

Gerente::Gerente(string areaDeSupervisao){
    setAreaDeSupervisao(areaDeSupervisao);
}

string Gerente::getAreaDeSupervisao(){
    return areaDeSupervisao;
}

void Gerente::setAreaDeSupervisao(string areaDeSupervisao){
    this->areaDeSupervisao = areaDeSupervisao;
}

