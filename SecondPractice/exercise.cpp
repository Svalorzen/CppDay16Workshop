/*
 * SINTASSI
 *
 * template<typename T, typename Check = some type >
 * struct S;
 *
 * template<typename T>
 * struct S<T, decltype(something)>;
 */

// Usa SFINAE per determinare quale dei due struct ha foo()!

struct A {
    void foo();
};

struct B {

};

// Se il tipo ha un metodo foo() 
// che ritorna void, stampa "FOO!"

// Altrimenti stampa "UNFOO'd!"
