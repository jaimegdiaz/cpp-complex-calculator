/*El primer acercamiento sera una calculadora basica, operaciones aritmeticas simples*/


#include <iostream>

/*
* PRIMERA MODIFICACION: HACERLO GENERICO DENTRO DE TIPOS NUMERICOS, NO SOLO INT Y EN CUANTO SE PUEDA 
QUITAR EL SWITCH CASE POR ALGO MAS EFICAZ.
CREAR UN ENUM? PARA QUE SEA MENOS AMBIGUO
*/
int realizarOperacion(int eleccion, int op1, int op2){
    
    switch(eleccion){
        case 1:
            return op1+op2;
        case 2:
            return op1-op2;
        case 3:
            return op1*op2;
        default:
            return 0;
    }
}


int main(){
    std::cout << "Que operacion quieres realizar"<<'\n';
    std::cout <<"============================"<<'\n';
    std::cout << "[1] Sumar     [2] Restar      [3] Multiplicar"<<'\n';
    std::cout << "Elige una opcion: ";
    int eleccion{};
    std::cin >> eleccion;
    std::cout<<"Escoge los dos operandos: "<<'\n';
    int op1{};
    int op2{};
    std::cout<<"op1: ";
    std::cin>>op1;
    std::cout<<'\n'<<"op2: ";
    std::cin>>op2;
    int res{realizarOperacion(eleccion, op1, op2)};
    std::cout<<res;
    return 0;
}