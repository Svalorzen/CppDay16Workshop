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
    void foo();
};

struct B {

};

template <typename T, typename Check = void>
struct FooChecker {
    void operator()() const {
        std::cout << "UNFOO'd\n";
    }
};

template <typename T>
struct FooChecker<T, decltype(T().foo())> {
    void operator()() const {
        std::cout << "FOO!\n";
    }
};

int main() {
    FooChecker<A>()();
    FooChecker<B>()();

    return 0;
}
