#pragma once
#include <unordered_map>
#include "UI.h"



namespace Cache{
    //TODO SOLUCIONAR PARA QUE SEA GENERICO
    inline int capacity{};
    enum PoliticaExpulsion{
        LRU = 0
        //Ir añadiendo
    };

    template<typename T, typename U>
    std::unordered_map<std::tuple<int, T, U>, std::common_type_t<T,U>> cache;

    template<typename T, typename U>
    void addElementToCache(int operacion, T op1, U op2, std::common_type_t<T,U> res){
        if(cache<T,U>.size()<capacity){
            cache<T,U>[{operacion,op1,op2}]=res;
        } else{
            //ESTO SE CAMBIARA POR LA POLITICA DE EXPULSION ADECUADA
            //ejectElementFromCache() y luego se añade el nuevo elemento
            cache<T,U>[{operacion,op1,op2}]=res;
        }   
    }

    template<typename T, typename U>
    void ejectElementFromCache(int operacion, T op1, U op2){
        
    }

    template<typename T, typename U>
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