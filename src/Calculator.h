//Calculator.h
#include <cstdint>
#include "Cache.h"
#include "Operations.h"
namespace Calculator{
    
    enum class Operacion : std::int8_t{
        suma = 1,
        resta = 2,
        multiplicacion = 3,
        division = 4
    };

    template <typename T, typename U>
    auto realizarOperacion(Operacion eleccion, T op1, U op2){    
        switch(eleccion){
            case Operacion::suma: {
                auto res = Operations::Suma(op1, op2);
                Cache::addElementToCache(static_cast<int>(eleccion), op1, op2, res);
                return res;
            }
                
            case Operacion::resta:{
                auto res = Operations::Resta(op1, op2);
                Cache::addElementToCache(static_cast<int>(eleccion), op1, op2, res);
                return res;
            }

            case Operacion::multiplicacion:{
                auto res = Operations::Multiplicacion(op1, op2);
                Cache::addElementToCache(static_cast<int>(eleccion), op1, op2, res);
                return res;
            }

            case Operacion::division:{
                auto res = Operations::Division(op1, op2);
                Cache::addElementToCache(static_cast<int>(eleccion), op1, op2, res);
                return res;
            }

            default:{
                return std::common_type_t<T, U>{0};
            }    
        }
    }
}