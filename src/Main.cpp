/*El primer acercamiento sera una calculadora basica, operaciones aritmeticas simples*/


#include <iostream>

#include "Calculator.h"
#include "Operations.h"
#include "UI.h"
/*
* PRIMERA MODIFICACION: HACERLO GENERICO DENTRO DE TIPOS NUMERICOS, NO SOLO INT Y EN CUANTO SE PUEDA 
*/



void ejecutar(){
    UI::showMenu();
    int eleccion{};
    std::cin >> eleccion;
    std::cout<<"Escoge los dos operandos: "<<'\n';
    int op1{};
    int op2{};
    std::cout<<"op1: ";
    std::cin>>op1;
    std::cout<<'\n'<<"op2: ";
    std::cin>>op2;
    //int res{realizarOperacion(static_cast<Operacion>(eleccion), op1, op2)};
    //std::cout<<res;
}

int main(){
    ejecutar();
    return 0;
}