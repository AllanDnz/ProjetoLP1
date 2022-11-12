#include <iostream>
#include <string>
#include <fstream> 
#include <vector>



using namespace std;

int getOption();
void CheckData(fstream &data);

int main(){

    fstream data;
    
    
    
    
    CheckData(data);

    int options = getOption();

    enum options{CREATE = 1, READ, UPDATE, DELETE, EXIT};

    while(options != EXIT){
        
        switch (options)
        {
        case CREATE:
            // COLOCAR AQUI TODOS OS METODOS QUE SERÃO USADOS 
          
            break;
        case READ:
            // COLOCAR AQUI TODOS OS METODOS QUE SERÃO USADOS 

            break;
        case UPDATE:
            // COLOCAR AQUI TODOS OS METODOS QUE SERÃO USADOS 
           
            break;
        case DELETE:
            // COLOCAR AQUI TODOS OS METODOS QUE SERÃO USADOS 
            
            break;        
        default:
            // COLOCAR AQUI TODOS OS METODOS QUE SERÃO USADOS 
            break;
        }
        
        data.close(); //FIM DO WHILE
    }

    
}


void CheckData(fstream &data){
    data.open("data.txt", fstream::in | fstream::out | fstream::app); //INICIA O ARQUIVO DATA.TXT

    if(data.is_open()){
        cout << "File Exist and Started!" << endl;
    }else{
        cout << "File does not exist, but the file was created!" << endl;
        data.close(); //fecha o arquivo txt
        data.open("data.txt");
    }
}


int getOption(){
    int in;

    cout << "Welcome to Employee Data Control" << endl; 
    cout << "----------------------------------------------" << endl;
    cout << "1 - Add a New Employee" << endl;
    cout << "2 - See the list of employees" << endl;
    cout << "3 - Update an employee" << endl;
    cout << "4 - Remove an employee" << endl;
    cout << "5 - Exit" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Select an option [1-5]:" << endl;
    cin >> in;
    
    return in;
}





