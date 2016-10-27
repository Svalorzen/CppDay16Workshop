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
    char x = 'c', y = 'd';

    if (x == 'a')
        std::cout << "\"x\" is equal to 'a'.\n";
    else if (x == 'b' && y == 'd')
        std::cout << "\"x\" is 'b' and \"y\" is 'd'.\n";
    else
        std::cout << "Values unknown.\n";

    return 0;
}
