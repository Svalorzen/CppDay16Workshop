/*
 * SINTASSI
 *
 * template<typename T, typename Check = some type >
 * struct S;
 *
 * template<typename T>
 * struct S<T, decltype(something)>;
 */

// Usa SFINAE per determinare quale dei due struct ha int foo()!

struct A {
    int foo();
};

struct B {
    void foo();
};

struct C {};

// Se il tipo ha un metodo foo() *INDIPENDENTEMENTE
// DAL VALORE DI RITORNO*, allora stampa "ALL FOO!"

// Altrimenti stampa "UNFOO'd!"
