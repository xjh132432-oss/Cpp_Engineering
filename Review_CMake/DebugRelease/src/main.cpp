#include <iostream>

int main()
{
#ifdef NDEBUG
    std::cout << "Release build" << '\n';
#else
    std::cout << "Debug build" << '\n';
#endif

    return 0;
}