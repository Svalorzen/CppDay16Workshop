/*
 * SINTASSI
 *
 * template<typename T, typename Check = some type >
 * struct S;
 *
 * template<typename T>
 * struct S<T, decltype(something)>;
 */

#include <iostream>

struct A {
    int foo();
};

struct B {
    void foo();
};

struct C {};

template <typename T, typename Check = void>
struct FooChecker {
    void operator()() const {
        std::cout << "UNFOO'd\n";
    }
};

template <typename T>
struct FooChecker<T, decltype(T().foo(), void())> {
    void operator()() const {
        std::cout << "ALL FOO!\n";
    }
};

int main() {
    FooChecker<A>()();
    FooChecker<B>()();
    FooChecker<C>()();

    return 0;
}
