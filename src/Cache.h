#include <variant>

namespace Cache{
    using Number = std::variant<int,double,float>;

    void addElementToCache(int operacion, Number op1, Number op2, Number res);

    void ejectElementFromCache(int operacion, Number op1, Number op2);
}