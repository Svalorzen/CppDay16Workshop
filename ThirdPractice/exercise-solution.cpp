/* // Puntatore a funzione
 * ReturnType (*)(Arg1, Arg2, Arg3, ...)
 *
 * // Variadic typename
 * typename... Args
 *
 * // Pack expansion
 * Args...
 */

#include <tuple>

template <typename T>
struct getFunctionArguments;

template <typename R, typename... Args>
struct getFunctionArguments<R (*)(Args...)> {
    using args = std::tuple<Args...>;
};

// ...

void foo(char, int);

int main() {
    static_assert(std::is_same<
        std::tuple<char, int>,
        getFunctionArguments<decltype(&foo)>::args
    >::value, "I parametri della tupla e gli argomenti della funzione non corrispondono!");

    return 0;
}
