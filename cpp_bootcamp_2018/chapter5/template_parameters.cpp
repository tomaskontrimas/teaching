#include <type_traits>
#include <iostream>

template <typename T>
void
func(int i, typename std::enable_if<std::is_same<T, int>::value, bool>::type t=true)
{
    std::cout << "T was of type int. Argument i = "<< i << "." << std::endl;
}

// template <typename T>
// void
// func(int i, typename std::enable_if<std::is_same<T, bool>::value, bool>::type t=true)
// {
//     std::cout << "T was of type bool. Argument i = "<< i << "." << std::endl;
// }

int main()
{
    func<int>(42);
    func<bool>(50); // Compile error! No instantation candidate.
    return 0;
}
