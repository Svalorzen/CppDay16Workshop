/*
 * // SINTASSI
 * template <typename T>
 * struct TupleUnpack;
 *
 * template <>
 * struct TupleUnpack<std::tuple<>>; // Final case
 *
 * template <typename T, typename... Args>
 * struct TupleUnpack<std::tuple<T, Args...>>; // Unpacking
 */

// Completa la classe 'AreTupleTypesEqual' e aggiungi tutte
// le specializzazioni parziali necessarie per far passare
// i test!

template </* ???? */>
struct AreTupleTypesEqual;

template </* ???? */>
struct AreTupleTypesEqual</* ???? */> {
    enum { value = /* ???? */ };
};

int main() {
    // Prints 0
    std::cout << AreTupleTypesEqual<std::tuple<int, char>,
                                    std::tuple<char>>::value << '\n';
    // Prints 1
    std::cout << AreTupleTypesEqual<std::tuple<int, char>,
                                    std::tuple<int, char>>::value << '\n';

    return 0;
}
