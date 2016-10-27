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

template <int N>
struct Printer {
    void operator()() const {
        std::cout << "\"N\" is not equal to zero.\n";
    }
};

template <>
struct Printer<0> {
    void operator()() const {
        std::cout << "\"N\" is equal to zero.\n";
    }
};

int main() {
    Printer<0>()();

    return 0;
}
