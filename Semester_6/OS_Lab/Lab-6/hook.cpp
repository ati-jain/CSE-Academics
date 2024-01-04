#include <iostream>

// Original function
int originalFunction(int i)
{
    std::cout << "Original function called." << std::endl;
    return i;
}

// Wrapper function for non-void return types
template <typename Func, typename = typename std::enable_if<!std::is_void<decltype(std::declval<Func>()())>::value>::type>
auto wrapperFunction(Func func)
{
    return [func](auto &&...args) -> decltype(auto)
    {
        // Code to be executed before calling the original function
        std::cout << "Wrapper function: Before calling original function." << std::endl;

        // Call the original function
        auto &&result = func(std::forward<decltype(args)>(args)...);

        // Code to be executed after calling the original function
        std::cout << "Wrapper function: After calling original function." << std::endl;

        return std::forward<decltype(result)>(result);
    };
}

// Specialization for void return type
// template<typename Func, typename = typename std::enable_if<std::is_void<decltype(std::declval<Func>()())>::value>::type>
// auto wrapperFunction(Func func) {
//     return [func](auto&&... args) {
//         // Code to be executed before calling the original function
//         std::cout << "Wrapper function: Before calling original function." << std::endl;

//         // Call the original function
//         func(std::forward<decltype(args)>(args)...);

//         // Code to be executed after calling the original function
//         std::cout << "Wrapper function: After calling original function." << std::endl;
//     };
// }

int main()
{
    // Replace the original function with the wrapper function
    auto wrappedFunction = wrapperFunction(originalFunction, 1);
    std::cout << wrappedFunction(1);

    return 0;
}
