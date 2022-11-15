#include "Gerente.h"
#include "Funcionario.h"
#include <iostream>

using namespace std;

Gerente::~Gerente(){

}

Gerente::Gerente()
{
    areaDeSupervisao = "";
}

Gerente::Gerente(string areaDeSupervisao)
{
    setAreaDeSupervisao(areaDeSupervisao);
}

string Gerente::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}

void Gerente::setAreaDeSupervisao(string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}
