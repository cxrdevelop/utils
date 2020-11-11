#include <iostream>
#include "bit_cast.hpp"
#include "bit_cast14.hpp"
#include <string>


int main()
{
    std::string str;
    std::string str2;
    char c{};
    unsigned char uc{};
    signed char sc{};

    auto c_b = utils::bit_cast<char>(uc);
    //auto c_str = utils::bit_cast<std::string>(str2);

    {
        char x = 15;
        //int y = utils14::bit_cast<int>(x);
    }

    {
        char arr[sizeof(std::string)] = {0};
        //bstd::string x = utils14::bit_cast<std::string>(arr);
    }

    return 0;
}
