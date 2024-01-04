#include <iostream>
#include <functional>

// Original function
void originalFunction(int a, double b, const std::string& c) {
    std::cout << "Original function called with arguments: " << a << ", " << b << ", " << c << std::endl;
}

// Wrapper function for non-void return types
template<typename Func, typename... Args>
auto wrapperFunction(Func func, Args&&... args) {
    return [func, args...](auto&&... wrapperArgs) -> decltype(auto) {
        // Code to be executed before calling the original function
        std::cout << "Wrapper function: Before calling original function." << std::endl;

        // Call the original function with the passed arguments and the arguments passed to the wrapper function
        auto&& result = func(std::forward<decltype(args)>(args)..., std::forward<decltype(wrapperArgs)>(wrapperArgs)...);

        // Code to be executed after calling the original function
        std::cout << "Wrapper function: After calling original function." << std::endl;

        return std::forward<decltype(result)>(result);
    };
}

// Wrapper function for void return type
// template<typename Func, typename... Args>
// auto wrapperFunction(Func func, Args&&... args) {
//     return [func, args...](auto&&... wrapperArgs) {
//         // Code to be executed before calling the original function
//         std::cout << "Wrapper function: Before calling original function." << std::endl;

//         // Call the original function with the passed arguments and the arguments passed to the wrapper function
//         func(std::forward<decltype(args)>(args)..., std::forward<decltype(wrapperArgs)>(wrapperArgs)...);

//         // Code to be executed after calling the original function
//         std::cout << "Wrapper function: After calling original function." << std::endl;
//     };
// }

int main() {
    // Replace the original function with the wrapper function
    auto wrappedFunction = wrapperFunction(originalFunction, 42, 3.14, "Hello");
    
    // Call the wrapped function
    wrappedFunction(10, 2.71, "World");

    return 0;
}
