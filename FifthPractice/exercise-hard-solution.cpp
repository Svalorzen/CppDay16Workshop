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

#include <tuple>

template <int M, typename T, typename U>
struct TuplesAreEqualUpToImpl;

template <int M, typename... Args1>
struct TuplesAreEqualUpToImpl<M, std::tuple<Args1...>, std::tuple<>> {
    static constexpr int N = M;
};

template <int M, typename... Args2>
struct TuplesAreEqualUpToImpl<M, std::tuple<>, std::tuple<Args2...>> {
    static constexpr int N = M;
};

template <int M, typename... Args1, typename... Args2>
struct TuplesAreEqualUpToImpl<M, std::tuple<Args1...>, std::tuple<Args2...>> {
    static constexpr int N = M;
};

template <int M, typename T, typename... Args1, typename... Args2>
struct TuplesAreEqualUpToImpl<M, std::tuple<T, Args1...>, std::tuple<T, Args2...>> {
    static constexpr int N = TuplesAreEqualUpToImpl<M+1, std::tuple<Args1...>, std::tuple<Args2...>>::N;
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
