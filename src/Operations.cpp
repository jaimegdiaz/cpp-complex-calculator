#include "Operations.h"


namespace Operations{

    template<typename T, typename U>
    std::common_type_t<T,U> Suma(T op1, U op2){
        return op1+op2;
    }

    template<typename T, typename U>
    std::common_type_t<T,U> Resta(T op1, U op2){
        return op1-op2;
    }

    template<typename T, typename U>
    std::common_type_t<T,U> Multiplicacion(T op1, U op2){
        return op1*op2;
    }

    template<typename T, typename U>
    std::common_type_t<T,U> Division(T op1, U op2){
        if(op2==0) return 67; //corregir con excepcion recuperable mas adelante
        return op1/op2;
    }
}