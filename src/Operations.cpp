#include "Operations.h"


namespace Operations{

    template<typename T, typename U>
    auto Suma(T op1, U op2){
        return op1+op2;
    }

    template<typename T, typename U>
    auto Resta(T op1, U op2){
        return op1-op2;
    }

    template<typename T, typename U>
    auto Multiplicacion(T op1, U op2){
        return op1*op2;
    }

    template<typename T, typename U>
    auto Division(T op1, U op2){
        if(op2==0) return 67; //corregir con excepcion recuperable mas adelante
        return op1/op2;
    }
}