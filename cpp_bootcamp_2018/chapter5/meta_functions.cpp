#include <type_traits>
#include <iostream>

template <typename T>
struct is_int
  : std::false_type
{};

template <>
struct is_int<int>
  : std::true_type
{};

template <typename T>
struct is_float
  : std::false_type
{};

template <>
struct is_float<float>
  : std::true_type
{};

template <bool is_int, bool is_float>
struct type_info
{};

template <>
struct type_info<false, false>
{
    static void print()
    {
        std::cout << "The type is neither int nor float." << std::endl;
    }
};

template <>
struct type_info<true, false>
{
    static void print()
    {
        std::cout << "The type is int and not float." << std::endl;
    }
};

template <>
struct type_info<false, true>
{
    static void print()
    {
        std::cout << "The type is not int, but float." << std::endl;
    }
};

int main()
{
    using type_to_test_1 = bool;
    type_info<is_int<type_to_test_1>::value, is_float<type_to_test_1>::value>::print();

    using type_to_test_2 = int;
    type_info<is_int<type_to_test_2>::value, is_float<type_to_test_2>::value>::print();

    using type_to_test_3 = float;
    type_info<is_int<type_to_test_3>::value, is_float<type_to_test_3>::value>::print();
}
