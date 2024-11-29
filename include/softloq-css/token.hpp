#ifndef SOFTLOQ_CSS_TOKEN_HPP
#define SOFTLOQ_CSS_TOKEN_HPP

/**
 * @author Brandon Foster
 * @file token.hpp
 * @version 1.0.0
 * @brief CSS Tokens are based on https://www.w3.org/TR/css-syntax-3/
 */

#include "softloq-css/error.hpp"

namespace Softloq::CSS
{
    /** @brief CSS Token Types are based on https://www.w3.org/TR/css-syntax-3/ */
    enum class TokenType
    {
        Comment,
        Whitespace,
        String,
        Number,
        Bool,
        Null
    };

    /** @brief Abstract class of a CSS Token object. */
    class Token
    {
    public:
        /** @brief Get the Token Type of the CSS Token object. */
        virtual const TokenType getTokenType() const = 0;

        /** @brief Provides the CSS Token object in its corresponding Token text form. */
        virtual const std::string toString() const = 0;

        /** @brief Clean way of type casting token when the type is known. If the type is not known, please use getTokenType(). */
        template <class TOKEN_TYPE>
        TOKEN_TYPE *const as() { return dynamic_cast<TOKEN_TYPE *>(this); }
    };

    class CommentToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Comment; }
        inline const std::string toString() const override { return std::string("\"") + value + '"'; }

        SOFTLOQ_CSS_API CommentToken();
        SOFTLOQ_CSS_API CommentToken(const std::string &value);

        inline void setText(const std::string &value) { this->value = value; }
        inline const std::string &getText() const { return value; }

    private:
        std::string value;
    };

    class WhitespaceToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Whitespace; }
        inline const std::string toString() const override { return " "; }

        SOFTLOQ_CSS_API WhitespaceToken();
    };

    class IdentToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Comment; }
        inline const std::string toString() const override { return std::string("\"") + value + '"'; }

        SOFTLOQ_CSS_API IdentToken();
        SOFTLOQ_CSS_API IdentToken(const std::string &value);

        inline void setIdentifier(const std::string &value) { this->value = value; }
        inline const std::string &getIdentifier() const { return value; }

    private:
        std::string value;
    };
}

#endif