#include <chrono>

namespace Estadisticas{
    std::chrono::time_point getTiempoActual();

    auto getDuracion(std::chrono::system_clock::time_point tInicial, std::chrono::system_clock::time_point tFinal);
}