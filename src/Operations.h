#pragma once

#include <type_traits>
#include <concepts>
#include <exception>
#include "UI.h"
namespace Operations{

    template <typename T> 
    concept Arithmetic = std::integral<T> || std::floating_point<T>;

    template<Arithmetic T, Arithmetic U>
    auto Suma(T op1, U op2){
        return op1+op2;
    }

    template<Arithmetic T, Arithmetic U>
    auto Resta(T op1, U op2){
        return op1-op2;
    }

    template<Arithmetic T, Arithmetic U>
    auto Multiplicacion(T op1, U op2){
        return op1*op2;
    }

    template<Arithmetic T, Arithmetic U>
    auto Division(T op1, U op2){
        if(op2==0) {
            UI::showMathError();
            return -1.0; 
        }; //corregir con excepcion recuperable mas adelante
        return op1/op2;
    }
}