#pragma once

#include <iostream>
#include "Funcionario.h"

using namespace std;

class Presidente : public Funcionario{

    public:
        Presidente();
        ~Presidente();
        string getAreaDeFormacao();
        string getFormacaoAcademicaMax();
        void setAreaDeFormacao(string areaDeFromacao);
        void setFormacaoAcademicaMax(string formacaoAcademicaMax);

    protected:
        string areaDeFormacao;
        string formacaoAcademicaMax;
};