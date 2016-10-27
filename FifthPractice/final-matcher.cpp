// Caso base che dia errore nel caso usiamo male l'API
template <int N, typename T, typename U, int... IDs>
struct Matcher;

// Caso finale, che ritorna tutti gli ID matchati quando
// la prima tupla (che dev'essere più piccola) è stata
// completamente matchata.
template <int N, typename... B, int... IDs>
struct Matcher<N, std::tuple<>, std::tuple<B...>, IDs...> {
    using type = IdPack<IDs...>;
};

// Caso di match di elemento: se alla stessa posizione N entrambe
// le tuple hanno un elemento di tipo F, allora proseguiamo ma 
// aggiungiamo N alla lista di IDs.
template <int N, typename F, typename... A, typename... B, int... IDs>
struct Matcher<N, std::tuple<F, A...>, std::tuple<F, B...>, IDs...> {
    using type = typename Matcher<N+1, std::tuple<A...>, 
                                       std::tuple<B...>, IDs..., N>::type;
};

// Caso di non-match di elemento: se alla stessa posizione N le 
// due tuple NON corrispondono, continuiamo, ma questa volta
// non aggiungiamo N agli IDs che abbiamo già trovato.
template <int N, typename FA, typename... A, 
                 typename FB, typename... B, int... IDs>
struct Matcher<N, std::tuple<FA, A...>, std::tuple<FB, B...>, IDs...> {
    using type = typename Matcher<N+1, std::tuple<FA, A...>, 
                                       std::tuple<B...>, IDs...>::type;
};
