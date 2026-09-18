#include <unordered_map>
#include <variant>
#include "UI.h"
#include "Cache.h"
#include <string>


namespace Cache{

    enum PoliticaExpulsion{
        LRU = 0
        //Ir añadiendo
    };

    //TODO SOLUCIONAR PARA QUE SEA GENERICO


    std::unordered_map<std::tuple<int, T, U>, Number> cache;

    //TODO
    void addElementToCache(int operacion, Number op1, Number op2, Number res){
        if(cache.size()<10){
            cache.at({operacion,op1,op2})=res;
        } else{
            //ESTO SE CAMBIARA POR LA POLITICA DE EXPULSION ADECUADA
            //ejectElementFromCache() y luego se añade el nuevo elemento
            cache.at({operacion,op1,op2})=res;
        }   
    }

    void ejectElementFromCache(int operacion, Number op1, Number op2){
        
    }

    void flushCache(){
        if(cache.size()==0){
            UI::showCacheIsAlreadyEmpty();
        } else{
            cache.clear();
        }
    }
}