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

// Replica il comportamento di questo programma
// attraverso la Partial Specialization!

#include <iostream>

int main() {
    int i = 0;

    if (i == 0)
        std::cout << "\"i\" is equal to zero.\n";
    else
        std::cout << "\"i\" is not equal to zero.\n";

    return 0;
}
