#include "src/pricing-engine/option.hpp"
#include <iostream>

int main()
{
    try
    {
        // create a 6 month ATM call option with strike 100
        quant::Option Option_CE(100.0, 0.5, quant::OptionType::PUT);
        std::cout << Option_CE.toString() << std::endl;

        // check exception
        quant::Option Option_CE_error(-100.0, 0.5, quant::OptionType::CALL);
    }
    catch (const quant::Option::ValidationError &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
