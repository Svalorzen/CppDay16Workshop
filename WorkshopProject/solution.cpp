#include <tuple>
#include <iostream>

// Function arguments extractor

template <typename T>
struct getFunctionArguments;

template <typename R, typename... Args>
struct getFunctionArguments<R(*)(Args...)> {
    using args = std::tuple<Args...>;
};

// Id pack utility type

template <int... IDs> struct IdPack {};

// Type matcher between two tuples

template <int N, typename T, typename U, int... IDs>
struct Matcher;

template <int N, typename... B, int... IDs>
struct Matcher<N, std::tuple<>, std::tuple<B...>, IDs...> {
    using type = IdPack<IDs...>;
};

template <int N, typename F, typename... A, typename... B, int... IDs>
struct Matcher<N, std::tuple<F, A...>, std::tuple<F, B...>, IDs...> {
    using type = typename Matcher<N+1, std::tuple<A...>, std::tuple<B...>, IDs..., N>::type;
};

template <int N, typename FA, typename... A, typename FB, typename... B, int... IDs>
struct Matcher<N, std::tuple<FA, A...>, std::tuple<FB, B...>, IDs...> {
    using type = typename Matcher<N+1, std::tuple<FA, A...>, std::tuple<B...>, IDs...>::type;
};

// Function pointer caller with specific tuple elements

template <typename F, typename... Args, int... IDs>
void caller(F f, const std::tuple<Args...> & args, IdPack<IDs...>) {
    f(std::get<IDs>(args)...);
}

// Main entry point

template <typename F, typename... Args>
void callFunction(F f, Args&& ...args) {
    using FArgs = typename getFunctionArguments<F>::args;
    using IdList = typename Matcher<0, FArgs, std::tuple<Args...>>::type;

    caller(f, std::make_tuple(args...), IdList());
}

// Function to test

void foo(char c, int x) {
    std::cout << c << ' ' << x << '\n';
}

int main()
{
    callFunction(foo, 0.2, 'c', "string", 99u, 7);

    return 0;
}
