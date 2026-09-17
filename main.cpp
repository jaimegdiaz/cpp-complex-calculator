/*El primer acercamiento sera una calculadora basica, operaciones aritmeticas simples*/


#include <iostream>
#include <cstdint>
#include "Operations.h"
#include "UI.h"
/*
* PRIMERA MODIFICACION: HACERLO GENERICO DENTRO DE TIPOS NUMERICOS, NO SOLO INT Y EN CUANTO SE PUEDA 
*/

enum Operacion : std::int8_t{
    suma = 1,
    resta = 2,
    multiplicacion = 3,
    division = 4
};

int realizarOperacion(Operacion eleccion, int op1, int op2){
    
    switch(eleccion){
        case Operacion::suma:
            return Operations::Suma(op1, op2);
        case Operacion::resta:
            return Operations::Resta(op1, op2);
        case Operacion::multiplicacion:
            return Operations::Multiplicacion(op1, op2);
        case Operacion::division:
            return Operations::Division(op1, op2);
        default:
            return 0;
    }
}

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
    int res{realizarOperacion(static_cast<Operacion>(eleccion), op1, op2)};
    std::cout<<res;
}

int main(){
    ejecutar();
    return 0;
}