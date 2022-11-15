#pragma once

#include <iostream>
#include "Funcionario.h"

using namespace std;

class Diretor : public Funcionario{

    public:
        Diretor(); 
        Diretor(string areaDeSupervisao, string areaDeformacao); //construtor que define as informações do funcionário
        ~Diretor();

        string getAreaDeSupervisao(); //funções get
        string getAreaDeFormacao();
    
        void setAreaDeFormacao(string areaDeFormacao); //funções set
        void setAreaDeSupervisao(string areaDeSupervisao);

    protected:
        string areaDeSupervisao;
        string areaDeFormacao;



};

