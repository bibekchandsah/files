#ifndef CMM_H38382
#define CMM_H38382

#include <string>
#include <initializer_list>
#include <functional>
#include <map>
#include <iostream>
using std::cout, std::endl, std::string,
      std::initializer_list, std::ostream,
      std::map, std::function, std::pair;
#define ref const let&
#define GET_MACRO2(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16, NAME,...) NAME
#define $(...) GET_MACRO2(__VA_ARGS__, ARG16, ARG15, ARG14, ARG13, ARG12, ARG11, ARG10, ARG9, ARG8, ARG7, ARG6, ARG5, ARG4, ARG3, ARG2, ARG1)(__VA_ARGS__)
#define ARG1(X) [&](ref X)->let
#define ARG2(X, Y) [&](ref X, ref Y)->let
#define ARG3(X, Y, Z) [&](ref X, ref Y, ref Z)->let
#define ARG4(X, Y, Z, T) [&](ref X, ref Y, ref Z, ref T)->let
#define ARG5(X, Y, Z, T, U) [&](ref X, ref Y, ref Z, ref T, ref U)->let
#define ARG6(X, Y, Z, T, U, V) [&](ref X, ref Y, ref Z, ref T, ref U, ref V)->let
#define ARG7(X, Y, Z, T, U, V, W) [&](ref X, ref Y, ref Z, ref T, ref U, ref V, ref W)->let
#define ARG8(X, Y, Z, T, U, V, W, S) [&](ref X, ref Y, ref Z, ref T, ref U, ref V, ref W, ref S)->let
#define ARG9(X1, X2, X3, X4, X5, X6, X7, X8, X9) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9)->let
#define ARG10(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10)->let
#define ARG11(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11)->let
#define ARG12(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11, ref X12)->let
#define ARG13(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11, ref X12, ref X13)->let
#define ARG14(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11, ref X12, ref X13, ref X14)->let
#define ARG15(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11, ref X12, ref X13, ref X14, ref X15)->let
#define ARG16(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16) [&](ref X1, ref X2, ref X3, ref X4, ref X5, ref X6, ref X7, ref X8, ref X9, ref X10, ref X11, ref X12, ref X13, ref X14, ref X15, ref X16)->let

#define _ auto
#define c_ const auto&
#define NOPRINT "\u0080"
#define inf let(2147483647) //1073741823
#define pi let(3.14159265358979323846)
#define yield return null

string _h(string);

// For generic types that are functors, delegate to its 'operator()'
template <typename T>
struct function_traits
    : public function_traits<decltype(&T::operator())>
{};
// for pointers to member function
template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const> {
    //enum { arity = sizeof...(Args) };
    typedef function<ReturnType (Args...)> f_type;
};
template <typename L>
typename function_traits<L>::f_type make_function(L l){
  return (typename function_traits<L>::f_type)(l);
}

class let {
  public:
    unsigned char info[8];
    union {
      double * d;
      string * s;
      map<let, let> * m;
      const function<let(ref)> * f1;
      const function<let(ref, ref)> * f2;
      const function<let(ref, ref, ref)> * f3;
      const function<let(ref, ref, ref, ref)> * f4;
      const function<let(ref, ref, ref, ref, ref)> * f5;
      const function<let(ref, ref, ref,
        ref, ref, ref)> * f6;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref)> * f7;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref)> * f8;
      const function<let(ref, ref, ref, ref,
        ref,
                ref, ref, ref, ref)> * f9;
      const function<let(ref, ref, ref, ref,
        ref, ref,
                ref, ref, ref, ref)> * f10;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref,
                ref, ref, ref, ref)> * f11;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref,
                ref, ref, ref, ref)> * f12;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref, ref,
                ref, ref, ref, ref)> * f13;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref, ref, ref,
                ref, ref, ref, ref)> * f14;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref, ref, ref, ref,
                ref, ref, ref, ref)> * f15;
      const function<let(ref, ref, ref, ref,
        ref, ref, ref, ref, ref, ref, ref, ref,
                ref, ref, ref, ref)> * f16;
    };

    bool isnum() const;
    bool isstr() const;
    bool ismap() const;
    bool isfun() const;
    int getfunid() const;
    bool islist() const;
    bool isheap() const;
    bool ishash() const;
    bool isset() const;

    void setnum();
    void setstr();
    void setfun(int);
    void setlist();
    void setheap();
    void sethash();
    void setset();

  ~let();
  let();
  let(const double&);
  let(const int&);
  let(const char *);
  let(const string&);
  let(const initializer_list<let>&);
  let(const function<let(ref)>&);
  let(const function<let(ref, ref)>&);
  let(const function<let(ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const function<let(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref)>&);
  let(const bool b): let(double(b)) {}
  template<typename T> let(T _f): let(make_function(_f)) {}
  let(ref);
  let& operator[](ref);
  ref operator[](ref) const;
  map<let, let>::iterator begin();
  map<let, let>::iterator end();
  map<let, let>::const_iterator begin() const;
  map<let, let>::const_iterator end() const;

  bool operator!=(ref) const;
  bool operator<(ref) const;
  bool operator<=(ref) const;
  bool operator==(ref) const;
  bool operator>(ref) const;
  bool operator>=(ref) const;
  explicit operator double() const;
  explicit operator int() const;
  let operator%(ref) const;
  let operator& (ref) const;
  let operator&&(ref) const;
  let operator()(ref) const;
  let operator()(ref, ref) const;
  let operator()(ref, ref, ref) const;
  let operator()(ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator()(ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref, ref) const;
  let operator*(ref) const;
  let operator+(ref) const;
  let operator-() const;
  let operator-(ref) const;
  let operator--();
  let operator--(int);
  let operator/(ref) const;
  let operator<< (ref) const;
  let operator>> (ref) const;
  let operator^ (ref) const;
  let operator|(ref) const;
  let operator||(ref) const;
  let& operator%=(ref);
  let& operator&= (ref);
  let& operator*();
  let& operator*=(ref);
  let& operator++();
  let& operator++(int);
  let& operator+=(ref);
  let& operator-= (ref);
  let& operator/=(ref);
  let& operator<<= (ref);
  let& operator=(ref);
  let& operator>>= (ref);
  let& operator^= (ref);
  let& operator|= (ref);
  bool has(ref) const;
  let charAt(ref) const;
  let find(ref) const;
  let& heapUpdate(ref, ref);
  let& _heapAdd(ref, ref);
  let& setDiff(ref);
  let codeAt(ref) const;
  string toStr() const;
  string toStr(ref) const;
  string toStr(ref, ref) const;

  /////////////////////////////
  // bool operator!() const;
  // let index(ref = 0) const;
};

ostream& operator<<(ostream&, ref);
let operator*(const char*, ref);
template <typename T> let operator*(T, ref);
template <typename T> let operator+(T, ref);
template <typename T> let operator/(T, ref);
template <typename T> let operator%(T, ref);
template <typename T> let operator-(T, ref);
template <typename T> bool operator<(T, ref);

// let hash(const initializer_list<pair<let, let> >& = {});
let hash(ref = {});
// let heap(const initializer_list<pair<let,let> >& = {});
let heap(ref = {});
let set(const initializer_list<let>& = {});
let set(ref);
let len(ref);
let fromCode(ref);
let range(ref, ref={}, ref={});
void help();

void myprint1(ref obj=NOPRINT);

template<typename ...Args>
void myprint1(ref obj=NOPRINT, Args... remaining) {
  if(!obj.isstr() || (*obj.s)!=NOPRINT) {
    cout << obj << " ";
  }
  myprint1(remaining...);
}

template<typename ...Args>
void print(Args... objects) {
  myprint1(objects...);
  cout << endl;
}

let get(ref, ref={});
let get(let&, ref={});
let $$(ref, ref, ref, ref);

template <std::size_t N>
struct _$_ {
    let &vec;
    template <std::size_t I> let& get();
};

namespace std {
    template<std::size_t N> struct tuple_size<_$_<N>> : std::integral_constant<std::size_t, N> { };
    template<std::size_t I, std::size_t N> struct tuple_element<I, _$_<N>> { using type = let; };
}

template <std::size_t N>
_$_<N> __(let&);

_$_<2> _2(let&);
_$_<3> _3(let&);
_$_<4> _4(let&);
_$_<5> _5(let&);
_$_<6> _6(let&);
_$_<7> _7(let&);
_$_<8> _8(let&);
_$_<9> _9(let&);
_$_<10> _10(let&);
_$_<11> _11(let&);
_$_<12> _12(let&);
_$_<13> _13(let&);
_$_<14> _14(let&);
_$_<15> _15(let&);
_$_<16> _16(let&);

template <std::size_t N>
struct _$$_ {
    let vec;
    template <std::size_t I> let get() const;
};

namespace std {
    template<std::size_t N> struct tuple_size<_$$_<N>> : std::integral_constant<std::size_t, N> { };
    template<std::size_t I, std::size_t N> struct tuple_element<I, _$$_<N>> { using type = let; };
}

template <std::size_t N>
_$$_<N> __(const let&);

_$$_<2> _2(const let&);
_$$_<3> _3(const let&);
_$$_<4> _4(const let&);
_$$_<5> _5(const let&);
_$$_<6> _6(const let&);
_$$_<7> _7(const let&);
_$$_<8> _8(const let&);
_$$_<9> _9(const let&);
_$$_<10> _10(const let&);
_$$_<11> _11(const let&);
_$$_<12> _12(const let&);
_$$_<13> _13(const let&);
_$$_<14> _14(const let&);
_$$_<15> _15(const let&);
_$$_<16> _16(const let&);

// ###############  helper.H #####################

//#define $ $
//#define エ $$
//#define ꝏ  inf
const let eps="", null;
//const let ø = null, ε = eps;

const let genGraph = [](ref nv, ref ne, ref W, ref req) {
  let edges;
  if(req=="connected") {
    let frame = {0}, all = range(1, nv);
    while(len(all)>0) {
      _ v = get(all);
      edges <<= {get((ref)frame), v};
      frame <<= v;
    }
  } else {
    bool directed = req=="directed";
    for(let i=0; i<nv; ++i)
      for(let j=0; j<nv; ++j)
        if((directed && i!=j) || (!directed && i<j))
          edges <<= {i, j};
    while(len(edges)>0 && ne<len(edges)) get(edges);
  }

  _ g = range(nv)|$(x){return hash();};
  edges | $(u, v) {
    _ w = get(range(1, W+1));
    g[u] <<= {v, w};
    if(req!="directed") g[v] <<= {u, w};
    yield;
  };
  return g;
};

const let reduce = [](ref v, ref f, ref a) {
  _ ans = a;
  v | $(x) { ans = f(x, ans); yield; };
  return ans;
};

const let _minflux = [](ref x, ref a) { return x<a? x: a; };
const let _maxflux = [](ref x, ref a) { return x>a? x: a; };
const let _sumflux = [](ref x, ref a) { return x+a; };
const let _mulflux = [](ref x, ref a) { return x*a; };

const let min = [](ref v) { return reduce(v, _minflux, inf); };
const let max = [](ref v) { return reduce(v, _maxflux, -inf); };
const let sum = [](ref v) { return reduce(v, _sumflux, 0); };
const let prod = [](ref v) { return reduce(v, _mulflux, 1); };

let _sprint(ref s, ref n);
const let yes = _sprint(" yes", 0);
const let no = _sprint(" no", -1);

#endif
