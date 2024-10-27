#pragma once

#include <chrono>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cmath>

namespace quant
{
    enum class OptionType
    {
        CALL,
        PUT
    };

    class Option;
    std::string to_string(const Option &option);

    class Option
    {
    public:
        class ValidationError : public std::runtime_error
        {
            using std::runtime_error::runtime_error;
        };
        static constexpr double EPSILON = 1e-10;
        static constexpr int TRADING_DAY_PER_YEAR = 252;

        Option(double strike, double timeToExpiry, OptionType type);

        // getter methods
        [[nodiscard]] double getStrike() const noexcept
        {
            return strike_;
        }
        [[nodiscard]] double getTimeToExpiry() const noexcept
        {
            return timeToExpiry_;
        }
        [[nodiscard]] OptionType getType() const noexcept
        {
            return type_;
        }
        // utility methods
        [[nodiscard]] bool isExpired() const noexcept;
        [[nodiscard]] int daysToExpiry() const noexcept;
        [[nodiscard]] std::string toString() const;

        // comparison operations
        bool operator==(const Option &other) const noexcept;
        bool operator!=(const Option &other) const noexcept
        {
            return !(*this == other);
        }

    private:
        // validation methods
        static double validateStrike(double strike);
        static double validateTimeToExpiry(double timeTotExpiry);

        // member variables
        const double strike_;
        const double timeToExpiry_;
        const OptionType type_;
    };
};
