/*
 * // SINTASSI
 * template <typename T>
 * struct TupleUnpack;
 *
 * template <>
 * struct TupleUnpack<std::tuple<>>; // Final case
 *
 * template <typename T, typename... Args>
 * struct TupleUnpack<std::tuple<T, Args...>>; // Unpacking
 */

// Seguendo una logica simile alla precedente, costruisci
// un oggetto TuplesAreEqualUpToImpl che analizza in parallelo
// le due coppie ed esporta l'ID dove per la prima volta non
// sono uguali!

template <int M/* , ???? */>
struct TuplesAreEqualUpToImpl;

template <int M/* , ???? */>
struct TuplesAreEqualUpToImpl</* ???? */> {
    static constexpr int N = /* ???? */;
};

template <typename T, typename U>
struct TuplesAreEqualUpTo {
    static constexpr int N = TuplesAreEqualUpToImpl<0, T, U>::N;
};

int main() {
    static_assert(TuplesAreEqualUpTo<std::tuple<int, double>, 
                                     std::tuple<int, char>>::N == 1, "Error!");

    return 0;
}

