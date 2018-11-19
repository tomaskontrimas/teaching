#include <iostream>
#include <type_traits>

class A
{
public:
    double get_A_value() const {
        return 42.3;
    }
};

class B
{
public:
    int get_B_value() const {
        return 42;
    }
};


// Using enable_if<> via the return type of a function template.
template <typename T>
typename std::enable_if<std::is_same<T,A>::value, double>::type
implementation(const T &a)
{
    return a.get_A_value();
}

template <typename T>
typename std::enable_if<std::is_same<T,B>::value, int>::type
implementation(const T &b)
{
    return b.get_B_value();
}


int main()
{
    A a;
    std::cout << "a: " << implementation(a) << std::endl;

    B b;
    std::cout << "b: " << implementation(b) << std::endl;
}
