using B_ll = __int128_t;

template<bool cond,
         typename Then,
         typename Else>
struct IF;

template<typename Then,
         typename Else>
struct IF<true, Then, Else> {
    typedef Then Result;
};

template<typename Then,
         typename Else>
struct IF<false, Then, Else> {
    typedef Else Result;
};

template<bool cond, 
         typename Body>
struct WhileLoop;

template<typename Body>
struct WhileLoop<true, Body> {
    typedef typename WhileLoop<
                Body::cond_value,
                typename Body::next_type>::type
                type;
};

template<typename Body>
struct WhileLoop<false, Body> {
    typedef
    typename Body::res_type type;
};