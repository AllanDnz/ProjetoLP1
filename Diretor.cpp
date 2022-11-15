#include "Diretor.h"
#include "Funcionario.h"
#include <iostream>

using namespace std;

Diretor::~Diretor(){


}

Diretor::Diretor()
{
    areaDeSupervisao = "";
    areaDeFormacao = "";
}

Diretor::Diretor(string areaDeSupervisao, string areaDeformacao)
{
    setAreaDeSupervisao(areaDeSupervisao);
    setAreaDeFormacao(areaDeFormacao);
}

string Diretor::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}
string Diretor::getAreaDeFormacao()
{
    return areaDeFormacao;
}

void Diretor::setAreaDeFormacao(string areaDeFormacao)
{
    this->areaDeFormacao = areaDeFormacao;
}

void Diretor::setAreaDeSupervisao(string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}