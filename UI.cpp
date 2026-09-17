#include "UI.h"
#include <iostream>
namespace UI{
    void showMenu(){
        std::cout << "Que operacion quieres realizar"<<'\n';
        std::cout <<"============================"<<'\n';
        std::cout << "[1] Sumar     [2] Restar      [3] Multiplicar"<<'\n';
        std::cout << "Elige una opcion: ";
    }
}

