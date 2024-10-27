#include "option.hpp"

namespace quant
{
    Option::Option(double strike, double timeToExpiry, OptionType type)
        : strike_(validateStrike(strike)),
          timeToExpiry_(validateTimeToExpiry(timeToExpiry)),
          type_(type) {}

    double Option::validateStrike(double strike)
    {
        if (std::isnan(strike) || std::isinf(strike))
        {
            throw ValidationError("Strike price must be a valid number");
        }
        if (strike <= EPSILON)
        {
            throw ValidationError("Strike price must be positive. Just like you.");
        }
        return strike;
    }

    double Option::validateTimeToExpiry(double timeToExpiry)
    {
        if (std::isnan(timeToExpiry) || std::isinf(timeToExpiry))
        {
            throw ValidationError("Time to Expiry must be a valid number");
        }

        if (timeToExpiry < 0.0)
        {
            throw ValidationError("Time to expiry cannot be negative. You believe in time travel, right?");
        }
        return timeToExpiry;
    }

    bool Option::isExpired() const noexcept
    {
        return timeToExpiry_ <= EPSILON;
    }

    int Option::daysToExpiry() const noexcept
    {
        return static_cast<int>(timeToExpiry_ * TRADING_DAY_PER_YEAR);
    }

    std::string Option::toString() const
    {
        std::ostringstream oss;
        oss << " Option {Strike = " << strike_
            << ", Time to Expiry = " << timeToExpiry_
            << ", Type = \033" << (type_ == OptionType::CALL ? "[32mCALL" : "[31mPUT") << "\033[0m"
            << ", Days to Expiry = " << daysToExpiry() << "}";
        return oss.str();
    }
    bool Option::operator==(const Option &other) const noexcept
    {
        return std::abs(strike_ - other.strike_) < EPSILON &&
               std::abs(timeToExpiry_ - other.timeToExpiry_) < EPSILON &&
               type_ == other.type_;
    }

    std::string to_string(const Option &option)
    {
        return option.toString();
    }
}