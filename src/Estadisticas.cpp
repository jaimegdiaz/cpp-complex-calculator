#include "Estadisticas.h"

namespace Estadisticas{
    auto getTiempoActual(){
        return std::chrono::system_clock::now;
    }

    auto getDuracion(std::chrono::system_clock::time_point tInicial, std::chrono::system_clock::time_point tFinal){
        auto res = tFinal-tInicial;
        return std::chrono::duration_cast<std::chrono::milliseconds>(res);
    }
}