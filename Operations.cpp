#include "operations.h"

namespace Operations{
    int Suma(int op1, int op2){
        return op1+op2;
    }
    
    int Resta(int op1, int op2){
        return op1-op2;
    }

    int Multiplicacion(int op1, int op2){
        return op1*op2;
    }

    int Division(int op1, int op2){
        if(op2==0) return 67; //corregir con excepcion recuperable mas adelante
        return op1/op2;
    }
}