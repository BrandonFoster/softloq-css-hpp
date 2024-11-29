#ifndef SOFTLOQ_CSS_ERROR_HPP
#define SOFTLOQ_CSS_ERROR_HPP

/**
 * @author Brandon Foster
 * @file error.hpp
 * @version 1.0.0
 * @brief Holds an error that occurs in a CSS function.
 */

#include "softloq-css/macros.hpp"
#include <string>

namespace Softloq::CSS
{
    /** @brief CSS error handle. */
    struct Error
    {
        /** @brief The error message. */
        std::string message;
    };
}

#endif