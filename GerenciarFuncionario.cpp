#include "GerenciarFuncionario.h"
#include <fstream> 

GerenciarFuncionario::GerenciarFuncionario()
{

}

GerenciarFuncionario::~GerenciarFuncionario()
{

}




void GerenciarFuncionario::adicionarNovoFuncionario(int codigo, string nome, string endereco, string telefone, Data dataDeIngresso, string designacao, float salario){
    Funcionario* funcionario = new Funcionario(codigo, nome, endereco, telefone, dataDeIngresso, designacao, salario); 
    
    funcionarios.push_back(funcionario); //adiciona um funcionario na ultima casa do vetor funcionarios




    /* std::ofstream arquivo("data.txt", std::ios::app);
    
    if(!arquivo.is_open()){
        return;
    }

    arquivo << "-Dados do funcionário-" << "Código:" << codigo << "Nome:" << nome << "Endereço:" << endereco << "Telefone:" << telefone << "Data de ingresso:" << dataDeIngresso.getData() << "Designação:" << designacao << "Salário:" << salario << endl; 
    
    arquivo.close();
    */ //Para salvar no arquivo
}

void GerenciarFuncionario::exibirListaDeFuncionarios(){ // exibe cada funcionario da lista de funcionarios
    for (int i = 0; i < funcionarios.size(); i++){
        cout << funcionarios[i]->toString() << endl;
    }
    cout << "\n";
}



vector<Funcionario*> GerenciarFuncionario::getListaFuncionarios(){ 
    return funcionarios;
}






void GerenciarFuncionario::excluirRegistroDeFuncionario(){
    string codigo;
    string confirmacao;
    int indice, achado = 0; // variaveis para busca de um funcionario válido

    if(Tratar.VerificaFuncionario(Funcionarios.size())){ //chamada de função para verificar se existem funcionarios na empresa, caso o resultado seja falso, o programa retorna ao menu

    }

    cout << "______MENU DE EXCLUSAO DE FUNCIONARIOS______" << endl <<
            "Há um total de: " << listaFuncionarios.size() << " funcionarios na empresa" << endl << endl; // mostrar numero de funcionarios cadastrados na empresa
    cout << "Digite o código do funcionário que você deseja excluir:" << endl;
    cout << "Digite 0 para voltar ao menu" << endl;
    cout << "-> ";

    while(1){

        getline(cin, codigo); //le o codigo do usuario a ser editado

        if(codigo == "0"){ // caso o usuario queria voltar ao menu
            system("cls");
        }

        for (int i = 0; i < listaFuncionarios.size(); i++){ //procura o codigo entre os usuarios cadastrados
            if(listaFuncionarios.at(i)->getCodigo() == codigo){
                indice = i; // salva o indice
                achado++; // indica que encontrou um funcionario
            }
        }
        if (achado==0){
            cout << "codigo invalido, insira outro: " << endl;
            cout << "-> ";
        }else
            break;
    }

    for (int i = 0; i < listaFuncionarios.size(); i++){ //procura na lsita de funcionarios cadastrados o codigo lido
        if (listaFuncionarios.at(i)->getCodigo() == codigo){
            if (listaFuncionarios.at(i)->getTipo() == 3 || listaFuncionarios.at(i)->getTipo() == 4){ //se o funcionario achado for um diretor ou presidente é impossivel deletar
                cout << "\nGerentes e presidentes não podem ser excluidos" << endl;
                system("pause");
                system("cls");
            }else{
                cout << "Voce deseja excluir o funcionaro de codigo: " << listaFuncionarios.at(i)->getCodigo() << " e nome: " << listaFuncionarios.at(i)->getNome() << ":(y/n) " << endl; //mensagem de confirmação de deleção
                getline(cin,confirmacao);
            }
            if(confirmacao == "y"){
                listaFuncionarios.erase(listaFuncionarios.begin()+i); //deletando o funcionario
                cout << "Funcionario apagado com sucesso" << endl;
                system("pause");
                system("cls");
            }else if(confirmacao == "n"){
                cout << "Exclusão de funcionario cancelada" << endl;
                system("pause");
                system("cls");
            }
            else{
                cout << "Entrada Invalida\nRetornando ao menu...\n";
            }
        }
    }
}