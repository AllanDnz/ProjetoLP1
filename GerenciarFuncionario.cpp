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

//void GerenciarFuncionario::adicionarNovoFuncionario(int codigo, string nome, string endereco, string telefone, Data dataDeIngresso, string designacao, string areaDeSupervisao, string areaDeFormacao, string formacaoAcademicaMax, float salario)
//{
    //Funcionario *funcionario = new Funcionario(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, areaDeSupervisao, formacaoAcademicaMax, salario);

    //funcionarios.push_back(funcionario); // adiciona um funcionario na ultima casa do vetor funcionarios

  //  if(designacao == "presidente" || designacao == "Presidente"){
  //      funcionarios.push_back(new Presidente(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, formacaoAcademicaMax, salario));
  //  }

//}
void GerenciarFuncionario::adicionarNovoFuncionario(Funcionario *func)
{
    funcionarios.push_back(func);
}


void GerenciarFuncionario::exibirListaDeFuncionarios()
{ // exibe cada funcionario da lista de funcionarios
    for (int i = 0; i < funcionarios.size(); i++)
    {
        cout << funcionarios[i]->toString() << endl;
    }
    cout << "\n";
    system("pause");
    system("cls");
}

void GerenciarFuncionario::exibirListaDeFuncionariosPorTipo()
{
    string designacao;
    int certo = 0;
    cout << "Digite a designação(Operador, Gerente, Diretor ou Presidente) com a primeira letra maiúscula" << endl;
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
            system("pause");
            system("cls");
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
    system("pause");
    system("cls");
}

void GerenciarFuncionario::editarRegistroDeUmFuncionario()
{
    int edit;
    int codigo;

    cout << "Digite o código do funcionárion que você deseja editar" << endl;
    cin >> codigo;
    getchar();
    int right = 0;

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
                system("cls");
                cout << "Editar o registo do funcionário" << codigo << endl;
                cout << "Digite o que deseja editar:" << endl;
                cout << "\t1 - Codigo" << endl;
                cout << "\t2 - Nome" << endl;
                cout << "\t3 - Endereco" << endl;
                cout << "\t4 - Telefone" << endl;
                cout << "\t5 - Data de ingresso" << endl;
                cout << "\t6 - Designacao" << endl;
                cout << "\t7 - Salario" << endl;
                cout << "\t8 - Sair" << endl;
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

                    dataDeIngresso.setDia(dia);
                    dataDeIngresso.setMes(mes);
                    dataDeIngresso.setAno(ano);
                    funcionarios[i]->setDataDeIngresso(dataDeIngresso);
                    break;
                case 6:{
                    int codigo = funcionarios[i]->getCodigo();
                    float salario = funcionarios[i]->getSalario();
                    string nome = funcionarios[i]->getNome();
                    string endereco = funcionarios[i]->getEndereco();
                    string telefone = funcionarios[i]->getTelefone();
                    Data dataDeIngresso = funcionarios[i]->getDataDeIngresso();
                    string designacao = funcionarios[i]->getDesignacao();
                    string areaDeSupervisao;
                    string areaDeFormacao;
                    string formacaoAcademicaMax;
                    cout << "Digite a nova designação do funcionário (Operador, Gerente, Diretor ou Presidente):" << endl;
                    string antiga = funcionarios[i]->getDesignacao();
                    getline(cin, designacao);
                    //cout<<"To aqui "<<antiga<<" Nova "<<designacao;
                    if(antiga == designacao){
                        cout<<"hello";
                    }
                    if(antiga != designacao){

                        if(designacao == "Gerente"){
                            cout<<"\nDigite a area de supervisao\n";
                            getline(cin, areaDeSupervisao);
                            funcionarios.erase(funcionarios.begin() + i);
                            funcionarios.push_back(new Gerente(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeSupervisao, salario));
                        }else if(designacao == "Diretor"){
                            cout<<"\nDigite a area de supervisao\n";
                            getline(cin, areaDeSupervisao);
                            cout<<"\nDigite a area de Formação\n";
                            getline(cin, areaDeFormacao);
                            funcionarios.erase(funcionarios.begin() + i);
                            funcionarios.push_back(new Diretor(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeSupervisao, areaDeFormacao, salario));
                        }else if(designacao == "Presidente"){
                            cout<<"\nDigite a area de formação\n";
                            getline(cin, areaDeFormacao);
                            cout<<"\nDigite a area de formação maxima\n";
                            getline(cin, formacaoAcademicaMax);
                            funcionarios.erase(funcionarios.begin() + i);
                            funcionarios.push_back(new Presidente(codigo, nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, formacaoAcademicaMax, salario));
                        }
                    }
                    break;}

                case 7:
                    cout << "Digite o novo salário do funcionário" << endl;
                    cin >> salario;
                    cin.ignore();
                    break;
                default:
                    break;
                }

                right = 1;
            }

        }
    }
    system("pause");
    system("cls");
}

void GerenciarFuncionario::excluirRegistroDeFuncionario()
{
    int codigo;
    string confirmacao;
    int indice, achado = 0; // variaveis para busca de um funcionario válido

    cout << "___MENU DE EXCLUSAO DE FUNCIONARIOS___" << endl
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
    system("pause");
    system("cls");
}

// função para salvar no arquivo os funcionários criados
void GerenciarFuncionario::salvarNoArquivo()
{
    std::ofstream arquivo("data.csv");

    if (!arquivo.is_open())
    {
        return;
    }

    for (int i = 0; i < funcionarios.size(); i++)
    {
        Funcionario *funcionario = funcionarios[i];
        int codigo = funcionario->getCodigo();
        string nome = funcionario->getNome();
        string endereco = funcionario->getEndereco();
        string telefone = funcionario->getTelefone();
        string dia = funcionario->getDataDeIngresso().getDia();
        string mes = funcionario->getDataDeIngresso().getMes();
        string ano = funcionario->getDataDeIngresso().getAno();
        string designacao = funcionario->getDesignacao();
        float salario = funcionario->getSalario();

        arquivo << funcionarios[i]->salvarNoArquivo();

        if (i != (funcionarios.size() - 1))
        {
            arquivo << "\n";
        }
    }

    arquivo.close();
}

void GerenciarFuncionario::lerNoArquivo() // Codigo para ler no arquivo os funcionários salvos pela função salvar no arquivo
{
    std::ifstream arquivo("data.csv");

    if (!arquivo.is_open())
    {
        return;
    }
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
        getline(arquivo, dia, '/');
        getline(arquivo, mes, '/');
        getline(arquivo, ano, ',');
        getline(arquivo, designacao, ',');
        getline(arquivo, salario, ',');

        Data dataDeIngresso;
        dataDeIngresso.setDia(dia);
        dataDeIngresso.setMes(mes);
        dataDeIngresso.setAno(ano);

        //adicionarNovoFuncionario(stoi(codigo), nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, areaDeSupervisao, formacaoAcademicaMax, stof(salario));
        if ((designacao == "operador") || (designacao == "Operador")){
                getline(arquivo, areaDeSupervisao, '\n');
                //Funcionario func = new Funcionario();
                //func.setAtributos(stoi(codigo), stof(salario), nome, endereco, telefone, dataDeIngresso, designacao);
                adicionarNovoFuncionario(new Funcionario(stoi(codigo), nome, endereco, telefone, dataDeIngresso, designacao, stof(salario)));

            } else if((designacao == "gerente") || (designacao == "Gerente"))
            {

                getline(arquivo, areaDeSupervisao, '\n');
               // gerente.setAreaDeSupervisao(areaDeSupervisao);
                adicionarNovoFuncionario(new Gerente(stoi(codigo),nome,endereco,telefone,dataDeIngresso,designacao,areaDeSupervisao,stof(salario)));
            }
            else if ((designacao == "diretor") || (designacao == "Diretor"))
            {

                getline(arquivo, areaDeSupervisao, ',');
               // diretor.setAreaDeSupervisao(areaDeSupervisao);

                getline(arquivo, areaDeFormacao, '\n');
               // diretor.setAreaDeFormacao(areaDeFormacao);
                adicionarNovoFuncionario(new Diretor(stoi(codigo),nome,endereco, telefone, dataDeIngresso, designacao, areaDeSupervisao,areaDeFormacao,stof(salario)));
            }
            else if ((designacao == "presidente") || (designacao == "Presidente"))
            {
                getline(arquivo, areaDeFormacao, ',');
              //  presidente.setAreaDeFormacao(areaDeSupervisao);

                getline(arquivo, formacaoAcademicaMax, '\n');
                //presidente.setFormacaoAcademicaMax(formacaoAcademicaMax);
                adicionarNovoFuncionario(new Presidente(stoi(codigo), nome, endereco, telefone, dataDeIngresso, designacao, areaDeFormacao, formacaoAcademicaMax, stof(salario)));
            }
        if (arquivo.eof())
        {
            break;
        }
    }
    arquivo.close();
}
