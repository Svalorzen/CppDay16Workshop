/* SINTASSI
 *
 * pattern ...
 */

// Completa prima la funzione 'print' in modo che possa
// stampare argomenti qualsiasi. A quel punto sviluppa
// 'print_tuple_elements' in modo da passare solo gli
// elementi che si desidera della tupla alla funzione 'print'

template </* ???? */>
void print(/* ???? */) {
    // print all arguments separated by '\n';
}

template <int...> struct IdPack {};

template </* ???? */>
void print_tuple_elements(std::tuple</* ???? */>, IdPack</* ???? */> ids) {
    // call print() with the tuple elements specified in ids
}

int main() {
    // Prints all
    print("a", 1, "b", 0.5, 7, 'c', true);
    // Prints 1, 0.5, 7
    print_tuple_elements(std::make_tuple("a", 1, "b", 0.5, 7, 'c', true),
                         IdPack<1,3,4>());

    return 0;
}
