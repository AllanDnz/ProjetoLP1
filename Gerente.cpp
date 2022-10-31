#include "Gerente.h"
#include "Funcionario.h"
#include <iostream>

using namespace std;

Gerente::Gerente(){

}

string Gerente::getAreaDeSupervisao(){
    return areaDeSupervisao;
}
void Gerente::setAreaDeSupervisao(string areaDeSupervisao){
    this->areaDeSupervisao = areaDeSupervisao;
}
