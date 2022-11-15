#pragma once

#include <iostream>
#include "Funcionario.h"

using namespace std;

class Presidente : public Funcionario
{

public:
    Presidente();
    Presidente(string areaDeFormacao, string FormacaoAcademicaMax);
    ~Presidente();
    string getAreaDeFormacao();
    string getFormacaoAcademicaMax();
    void setAreaDeFormacao(string areaDeFormacao);
    void setFormacaoAcademicaMax(string formacaoAcademicaMax);

protected:
    string areaDeFormacao;
    string formacaoAcademicaMax;
};