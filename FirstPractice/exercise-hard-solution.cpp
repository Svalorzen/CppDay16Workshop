/* SINTASSI:
 *
 * template<typename T>
 * struct A {};
 *
 * template <>
 * struct A<int> {};
 *
 * ...
 *
 * template <int N>
 * struct A {};
 *
 * template <>
 * struct A<100> {};
 */

#include <iostream>

template <char X, char Y>
struct Printer {
    void operator()() const {
        std::cout << "Values unknown.\n";
    }
};

template <char Y>
struct Printer<'a', Y> {
    void operator()() const {
        std::cout << "\"x\" is equal to 'a'.\n";
    }
};

template <>
struct Printer<'b', 'd'> {
    void operator()() const {
        std::cout << "\"x\" is 'b' and \"y\" is 'd'.\n";
    }
};
int main() {
    Printer<'c', 'd'>()();

    return 0;
}
