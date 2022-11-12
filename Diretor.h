#pragma once

#include <iostream>
#include "Funcionario.h"

using namespace std;

class Diretor : public Funcionario
{

    public:
        Diretor();
        Diretor(string areaDeSupervisao, string areaDeformacao);
        ~Diretor();
        string getAreaDeSupervisao();
        string getAreaDeFormacao();
        void setAreaDeFormacao(string areaDeFormacao);
        void setAreaDeSupervisao(string areaDeSupervisao);

    protected:
        string areaDeSupervisao;
        string areaDeFormacao;



};

