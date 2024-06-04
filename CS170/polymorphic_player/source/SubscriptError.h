#pragma once

#include <exception>

namespace HLP2
{

    class SubscriptError : public std::exception
    {
    public:
        static constexpr const char* ERROR_MESSAGE = "array out of bounds exception";

        explicit SubscriptError(int the_subscript) : subscript(the_subscript) {}

        const char* what() const noexcept override {
            return ERROR_MESSAGE;
        }

        int GetSubscript() const {
            return subscript;
        }

    private:
        int subscript;
    };

}