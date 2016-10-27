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

#include <iostream>
#include <tuple>

template <typename T, typename U>
struct AreTupleTypesEqual;

template <>
struct AreTupleTypesEqual<std::tuple<>, std::tuple<>> {
    enum { value = true };
};

template <typename... Args1, typename... Args2>
struct AreTupleTypesEqual<std::tuple<Args1...>, std::tuple<Args2...>> {
    enum { value = false };
};

template <typename T, typename... Args1, typename... Args2>
struct AreTupleTypesEqual<std::tuple<T, Args1...>, std::tuple<T, Args2...>> {
    enum { value = AreTupleTypesEqual<std::tuple<Args1...>, std::tuple<Args2...>>::value };
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
