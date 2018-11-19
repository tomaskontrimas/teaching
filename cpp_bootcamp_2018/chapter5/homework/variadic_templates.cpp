#include <string>
#include <tuple>
#include <iostream>
#include <functional>

template <
    class F
  , class ...Args
>
struct function_exposer
{
    function_exposer(
        std::string name
      , F f
      , Args const & ...args
    )
      : m_name(name)
      , m_f(f)
      , m_a(std::make_tuple(std::reference_wrapper<Args const>(args)...))
    {}

    std::string m_name;
    F m_f;
    std::tuple<Args const & ...> m_a;
};

int main()
{
    double f = 1.1;
    int a1 = 4;
    float a2 = 5.6;
    function_exposer<double, int, float> fe("FE", f, a1, a2);
    std::cout << fe.m_name << std::endl;
    std::cout << fe.m_f << std::endl;
    int const & a0_ = std::get<0>(fe.m_a);
    float const & a1_ = std::get<1>(fe.m_a);
    std::cout << a0_ << std::endl;
    std::cout << a1_ << std::endl;

    return 0;
}
