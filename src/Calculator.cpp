#include <cstdint>

#include "Cache.h"
#include "Operations.h"
#include "Calculator.h"

namespace Calculator{

    enum Operacion : std::int8_t{
        suma = 1,
        resta = 2,
        multiplicacion = 3,
        division = 4
    };

    template <typename T, typename U>
    auto realizarOperacion(Operacion eleccion, T op1, U op2){
        
        switch(eleccion){
            case Operacion::suma:
                auto res = Operations::Suma(op1, op2);
                Cache::addElementToCache(eleccion, op1, op2, res);
                return res;
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
}