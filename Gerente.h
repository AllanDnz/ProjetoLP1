#pragma once

#include "Funcionario.h"
#include <iostream>

using namespace std;

class Gerente : public Funcionario
{

    public:
        Gerente();
        Gerente(string areaDeSupervisao);
        ~Gerente();
        string getAreaDeSupervisao();
        void setAreaDeSupervisao(string areaDeSupervisao);

    private:
       string areaDeSupervisao;

};