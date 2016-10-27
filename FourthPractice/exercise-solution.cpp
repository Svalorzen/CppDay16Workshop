/* SINTASSI
 *
 * pattern ...
 */

#include <iostream>
#include <tuple>

void print() {}

template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
    // print all arguments separated by '\n';
    std::cout << t << '\n';
    print(args...);
}

template <int...> struct IdPack {};

template <typename... Args, int... Ids>
void print_tuple_elements(std::tuple<Args...> t, IdPack<Ids...> ids) {
    // call print() with the tuple elements specified in ids
    print(std::get<Ids>(t)...);
}

int main() {
    // Prints all
    print("a", 1, "b", 0.5, 7, 'c', true);
    // Prints 1, 0.5, 7
    print_tuple_elements(std::make_tuple("a", 1, "b", 0.5, 7, 'c', true),
                         IdPack<1,3,4>());

    return 0;
}
