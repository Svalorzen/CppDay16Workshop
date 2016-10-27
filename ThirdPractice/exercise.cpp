/* // Puntatore a funzione
 * ReturnType (*)(Arg1, Arg2, Arg3, ...)
 *
 * // Variadic typename
 * typename... Args
 *
 * // Pack expansion
 * Args...
 */

// Completa lo stub di getFunctionArguments in modo
// da riuscire a compilare il programma!

template </* ???? */>
struct getFunctionArguments;

template </* ???? */>
struct getFunctionArguments</* ???? */> {
    using args = /* ???? */ ;
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
