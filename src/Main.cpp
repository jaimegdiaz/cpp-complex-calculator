/*El primer acercamiento sera una calculadora basica, operaciones aritmeticas simples*/


#include <iostream>
#include "Cache.h"
#include "Calculator.h"
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
    auto res{Calculator::realizarOperacion(static_cast<Calculator::Operacion>(eleccion), op1, op2)};
    std::cout<<res;
}

int main(){
    ejecutar();
    return 0;
}