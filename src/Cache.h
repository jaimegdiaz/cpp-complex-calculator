#pragma once
#include <unordered_map>
#include "UI.h"
#include "Operations.h"

/**
 * 
 * 
 * 
 * 
 * TODO: CAMBIAR LA CLAVE DE LA CACHE DE UNA TUPLA A UN STRING
 * FORMATOSTRING: "Operacion_Operando1_Operando2"
 * ES QUE NO SE HACER FUNCIONES HASH EN C++
* 
 * 

 */

namespace Cache{
    //TODO SOLUCIONAR PARA QUE SEA GENERICO
    inline int capacity{};
    enum PoliticaExpulsion{
        LRU = 0
        //Ir añadiendo
    };

    // Función auxiliar para combinar hashes (algoritmo similar al de Boost)
    inline void hash_combine(std::size_t& seed, auto const& val) {
        seed ^= std::hash<std::decay_t<decltype(val)>>{}(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    // Struct con el operador hash para cualquier std::tuple
    struct TupleHash {
        template <typename... Args>
        std::size_t operator()(const std::tuple<Args...>& t) const {
            std::size_t seed = 0;
            // std::apply itera sobre los elementos de la tupla aplicando hash_combine
            std::apply([&seed](const auto&... args) {
                (hash_combine(seed, args), ...); // Fold expression de C++17/20
            }, t);
            return seed;
        }
    };

    template <Operations::Arithmetic T, Operations::Arithmetic U>
    std::unordered_map<std::tuple<int, T, U>, std::common_type_t<T,U>, TupleHash> cache;

    template <Operations::Arithmetic T, Operations::Arithmetic U>
    void addElementToCache(int operacion, T op1, U op2, std::common_type_t<T,U> res){
        
        if(cache<T,U>.size()<capacity){
            cache<T,U>[{operacion,op1,op2}]=res;
        } else{
            //ESTO SE CAMBIARA POR LA POLITICA DE EXPULSION ADECUADA
            //ejectElementFromCache() y luego se añade el nuevo elemento
            cache<T,U>[{operacion,op1,op2}]=res;
        }   
    }

    template <Operations::Arithmetic T, Operations::Arithmetic U>
    void ejectElementFromCache(int operacion, T op1, U op2){
        
    }

    template <Operations::Arithmetic T, Operations::Arithmetic U>
    void flushCache(){
        if(cache<T,U>.empty()){
            UI::showCacheIsAlreadyEmpty();
        } else{
            cache<T,U>.clear();
        }
    }

    inline void changeCapacity(int newCapacity){
        capacity=newCapacity;
    }
}