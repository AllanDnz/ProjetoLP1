#include "GerenciarFuncionario.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

GerenciarFuncionario::GerenciarFuncionario()
{
}

GerenciarFuncionario::~GerenciarFuncionario()
{
}

void GerenciarFuncionario::adicionarNovoFuncionario(int codigo, string nome, string endereco, string telefone, Data dataDeIngresso, string designacao, string areaDeSupervisao, string areaDeFormacao, string formacaoAcademicaMax, float salario)
{
    Funcionario *funcionario = new Funcionario(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, areaDeSupervisao, formacaoAcademicaMax, salario);

    funcionarios.push_back(funcionario); // adiciona um funcionario na ultima casa do vetor funcionarios
}

void GerenciarFuncionario::exibirListaDeFuncionarios()
{ // exibe cada funcionario da lista de funcionarios
    for (int i = 0; i < funcionarios.size(); i++)
    {
        cout << funcionarios[i]->toString() << endl;
    }
    cout << "\n";
}

void GerenciarFuncionario::exibirListaDeFuncionariosPorTipo()
{
    string designacao;
    int certo = 0;
    cout << "Digite a designação(Operador, Gerente, Diretor ou Presidente) com a primeira letra maiúscula ou minúscula" << endl;
    cin >> designacao;
    getchar();
    while (certo == 0)
    {
        for (int i = 0; i < funcionarios.size(); i++)
        {
            if (designacao == funcionarios[i]->getDesignacao())
            {
                cout << funcionarios[i]->toString() << endl; // retorna todos os dados dos funcionarios de determinada designação
                certo = 1;
            }
            else
            {
                cout << "Digite corretamente a designação" << endl;
            }

            cout << "\n";
        }
    }
}

void GerenciarFuncionario::exibirRegistroDeUmFuncionario()
{
    int codigo;
    int correto = 0;
    cin >> codigo;
    getchar();
    while (correto == 0)
    {
        for (int i = 0; i < funcionarios.size(); i++)
        {
            if (codigo == funcionarios[i]->getCodigo()) // encontra a posição no vetor que tem o funcionario com determinado codigo
            {

                cout << funcionarios[i]->toString() << endl;
                correto = 1;
            }
            else
            {
                cout << "Código não encontrado, digite novamente" << endl;
            }
        }
    }
}

void GerenciarFuncionario::editarRegistroDeUmFuncionario()
{
    int edit;
    int codigo;
    cin >> codigo;
    getchar();
    int right;

    string nome;
    string endereco;
    string telefone;
    Data dataDeIngresso;
    string designacao;
    float salario;

    Data ingresso = Data();
    string dia, mes, ano;

    Gerente gerente = Gerente();
    string areaDeSupervisao;

    Diretor diretor = Diretor();
    string areaDeFormacao;

    Presidente presidente = Presidente();
    string formacaoAcademicaMax;

    while (right == 0)
    {
        for (int i = 0; i < funcionarios.size(); i++)
        {
            if (codigo == funcionarios[i]->getCodigo())
            {

                cout << "Editar o registo do funcionário" << codigo << endl;
                cout << "Digite o que deseja editar:" << endl;
                cout << "/t1 - Codigo" << endl;
                cout << "/t2 - Nome" << endl;
                cout << "/t3 - Endereco" << endl;
                cout << "/t4 - Telefone" << endl;
                cout << "/t5 - Data de ingresso" << endl;
                cout << "/t6 - Designacao" << endl;
                cout << "/t7 - Area de Supervisao" << endl;
                cout << "/t8 - Area de Formacao" << endl;
                cout << "/t9 - Formacao Academica Maxima" << endl;
                cout << "/t0 - Salario" << endl;
                cout << "/t11 - Sair" << endl;
                cin >> edit;
                cin.ignore();

                switch (edit)
                {
                case 1:
                    cout << "Digite o código do funcionário" << endl;
                    cin >> codigo;
                    cin.ignore();
                    funcionarios[i]->setCodigo(codigo);
                    break;
                case 2:
                    cout << "Digite o novo nome do funcionário" << endl;
                    getline(cin, nome);
                    funcionarios[i]->setNome(nome);
                    break;
                case 3:
                    cout << "Digite o novo endereço do funcionário" << endl;
                    getline(cin, endereco);
                    funcionarios[i]->setEndereco(endereco);
                    break;
                case 4:
                    cout << "Digite o novo telefone do funcionário" << endl;
                    getline(cin, telefone);
                    funcionarios[i]->setTelefone(telefone);
                    break;
                case 5:
                    cout << "Digite a nova data de ingresso do funcionário" << endl;
                    getline(cin, dia);
                    getline(cin, mes);
                    getline(cin, ano);

                    ingresso.setDia(dia);
                    ingresso.setMes(mes);
                    ingresso.setAno(ano);
                    break;
                case 6:
                    cout << "Digite a nova designação do funcionário (Operador, Gerente, Diretor ou Presidente):" << endl;
                    getline(cin, designacao);
                    if ((designacao == "gerente") || (designacao == "Gerente"))
                    {
                        cout << "Digite a nova area de supervisao" << endl;
                        getline(cin, areaDeSupervisao);
                        gerente.setAreaDeSupervisao(areaDeSupervisao);
                    }
                    else if ((designacao == "diretor") || (designacao == "Diretor"))
                    {
                        cout << "Digite a nova área de supervisão" << endl;
                        getline(cin, areaDeSupervisao);
                        diretor.setAreaDeSupervisao(areaDeSupervisao);
                        cout << "Digite a nova área de formação" << endl;
                        getline(cin, areaDeFormacao);
                        diretor.setAreaDeFormacao(areaDeSupervisao);
                    }
                    else if ((designacao == "presidente") || (designacao == "Presidente"))
                    {
                        cout << "Digite a nova área de formação" << endl;
                        getline(cin, areaDeFormacao);
                        presidente.setAreaDeFormacao(areaDeSupervisao);
                        cout << "Digite a nova formação máxima" << endl;
                        getline(cin, areaDeFormacao);
                        presidente.setFormacaoAcademicaMax(formacaoAcademicaMax);
                    }
                    else if ((designacao == "operador") || (designacao == "Operador"))
                    {
                        continue;
                    }
                    break;
                case 7:
                    cout << "Digite a designação do funcionário (Gerente ou Diretor):" << endl;
                    getline(cin, designacao);
                    if ((designacao == "gerente") || (designacao == "Gerente"))
                    {
                        cout << "Digite a nova area de supervisao" << endl;
                        getline(cin, areaDeSupervisao);
                        gerente.setAreaDeSupervisao(areaDeSupervisao);
                    }
                    else if ((designacao == "diretor") || (designacao == "Diretor"))
                    {
                        cout << "Digite a nova área de supervisão" << endl;
                        getline(cin, areaDeSupervisao);
                        diretor.setAreaDeSupervisao(areaDeSupervisao);
                    }
                    break;
                case 8:
                    if ((designacao == "diretor") || (designacao == "Diretor"))
                    {
                        cout << "Digite a nova área de formação" << endl;
                        getline(cin, areaDeFormacao);
                        diretor.setAreaDeFormacao(areaDeSupervisao);
                    }
                    else if ((designacao == "presidente") || (designacao == "Presidente"))
                    {
                        cout << "Digite a nova área de formação" << endl;
                        getline(cin, areaDeFormacao);
                        presidente.setAreaDeFormacao(areaDeSupervisao);
                    }
                    break;
                case 9:
                    // se precisa verificar se o codigo é de um funcionario com cargo de presidente
                    cout << "Digite a nova formação máxima" << endl;
                    getline(cin, areaDeFormacao);
                    presidente.setFormacaoAcademicaMax(formacaoAcademicaMax);
                    break;
                case 0:
                    cout << "Digite o novo salário do funcionário" << endl;
                    cin >> salario;
                    cin.ignore();
                    break;
                default:
                    break;
                }

                /* cout << "Digite a nova designação do funcionário (Operador, Gerente, Diretor ou Presidente):" << endl;
                getline(cin, designacao);
                if ((designacao == "gerente") || (designacao == "Gerente"))
                {
                    cout << "Digite a nova area de supervisao" << endl;
                    getline(cin, areaDeSupervisao);
                    gerente.setAreaDeSupervisao(areaDeSupervisao);
                }
                else if ((designacao == "diretor") || (designacao == "Diretor"))
                {
                    cout << "Digite a nova área de supervisão" << endl;
                    getline(cin, areaDeSupervisao);
                    diretor.setAreaDeSupervisao(areaDeSupervisao);
                    cout << "Digite a nova área de formação" << endl;
                    getline(cin, areaDeFormacao);
                    diretor.setAreaDeFormacao(areaDeSupervisao);
                }
                else if ((designacao == "presidente") || (designacao == "Presidente"))
                {
                    cout << "Digite a nova área de formação" << endl;
                    getline(cin, areaDeFormacao);
                    presidente.setAreaDeFormacao(areaDeSupervisao);
                    cout << "Digite a nova formação máxima" << endl;
                    getline(cin, areaDeFormacao);
                    presidente.setFormacaoAcademicaMax(formacaoAcademicaMax);
                }
                else if ((designacao == "operador") || (designacao == "Operador"))
                {
                    continue;
                }

                cout << "Digite o novo salário do funcionário" << endl;
                cin >> salario;
                cin.ignore();*/

                right = 1;
            }
            else
            {
                cout << "Código não encontrado, digite novamente" << endl;
            }
        }
    }
}

void GerenciarFuncionario::excluirRegistroDeFuncionario()
{
    int codigo;
    string confirmacao;
    int indice, achado = 0; // variaveis para busca de um funcionario válido

    cout << "______MENU DE EXCLUSAO DE FUNCIONARIOS______" << endl
         << "Há um total de: " << funcionarios.size() << " funcionarios na empresa" << endl
         << endl; // mostrar numero de funcionarios cadastrados na empresa
    cout << "Digite o código do funcionário que você deseja excluir:" << endl;

    while (1)
    {

        cin >> codigo; // le o codigo do usuario a ser editado
        cin.ignore();

        for (int i = 0; i < funcionarios.size(); i++)
        { // procura o codigo entre os usuarios cadastrados
            if (funcionarios.at(i)->getCodigo() == codigo)
            {
                indice = i; // salva o indice
                achado++;   // indica que encontrou um funcionario
            }
        }

        if (achado == 0)
        {
            cout << "codigo invalido, insira outro: " << endl;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < funcionarios.size(); i++)
    { // procura na lista de funcionarios cadastrados o codigo lido
        if (funcionarios.at(i)->getCodigo() == codigo)
        {
            if (funcionarios.at(i)->getDesignacao() == "Diretor" || funcionarios.at(i)->getDesignacao() == "Presidente" || funcionarios.at(i)->getDesignacao() == "presidente" || funcionarios.at(i)->getDesignacao() == "diretor")
            {

                // se o funcionario achado for um diretor ou presidente é impossivel deletar
                cout << "\n Diretores e presidentes não podem ser excluidos" << endl;
                break;
            }

            cout << "Voce deseja excluir o funcionario de codigo: " << funcionarios.at(i)->getCodigo() << " e nome: " << funcionarios.at(i)->getNome() << ":(s/n) " << endl;
            getline(cin, confirmacao);

            if (confirmacao == "s")
            {
                delete funcionarios.at(i);                    // liberando a memoria dinamica ocupada pelo funcionario naquele indice
                funcionarios.erase(funcionarios.begin() + i); // No inésimo elemento vai deletar o funcionario que estava lá
                cout << "Funcionario apagado com sucesso" << endl;
            }
            else if (confirmacao == "n")
            {
                cout << "Exclusão de funcionario cancelada" << endl;
            }
            break;
        }
    }
}

// função para salvar no arquivo os funcionários criados
void GerenciarFuncionario::salvarNoArquivo()
{
    std::ofstream arquivo("data.csv", std::ios::app);

    if (!arquivo.is_open())
    {
        return;
    }
    for (Funcionario *funcionario : funcionarios)
    {
        arquivo << funcionario->getCodigo() << "," << funcionario->getNome() << "," << funcionario->getEndereco() << "," << funcionario->getTelefone() << "," << funcionario->getDataDeIngresso().getDia() << "," << funcionario->getDataDeIngresso().getMes() << "," << funcionario->getDataDeIngresso().getAno() << "," << funcionario->getDesignacao() << "," << funcionario->getAreaDeSupervisao() << "," << funcionario->getAreaDeFormacao() << "," << funcionario->getFormacaoAcademicaMax() << "," << funcionario->getSalario() << endl;
    }

    arquivo.close();
}

void GerenciarFuncionario::lerNoArquivo() // Codigo para ler no arquivo os funcionários salvos pela função salvar no arquivo
{
    std::ifstream arquivo("data.csv");

    while (1)
    {
        Funcionario *funcionario;

        string codigo;
        string nome;
        string endereco;
        string telefone;
        string dia;
        string mes;
        string ano;
        string designacao;
        string areaDeSupervisao;
        string areaDeFormacao;
        string formacaoAcademicaMax;
        string salario;

        getline(arquivo, codigo, ',');
        getline(arquivo, nome, ',');
        getline(arquivo, endereco, ',');
        getline(arquivo, telefone, ',');
        getline(arquivo, dia, ',');
        getline(arquivo, mes, ',');
        getline(arquivo, ano, ',');
        getline(arquivo, designacao, ',');
        getline(arquivo, areaDeSupervisao, ',');
        getline(arquivo, areaDeFormacao, ',');
        getline(arquivo, formacaoAcademicaMax, ',');
        getline(arquivo, salario, ',');

        Data dataDeIngresso;
        dataDeIngresso.setDia(dia);
        dataDeIngresso.setDia(mes);
        dataDeIngresso.setDia(ano);

        adicionarNovoFuncionario(stoi(codigo), nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, areaDeSupervisao, formacaoAcademicaMax, stof(salario));

        if (arquivo.eof())
        {
            break;
        }
    }
    arquivo.close();
}
