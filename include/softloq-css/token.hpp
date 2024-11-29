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
        Ident,
        Function,
        AtKeyword,
        Hash,
        String,
        URL,
        Number,
        Dimension,
        Percentage,
        CDO,
        CDC
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
        inline const std::string toString() const override { return std::string("/*") + text + "*/"; }

        SOFTLOQ_CSS_API CommentToken();
        SOFTLOQ_CSS_API CommentToken(const std::string &text);

        inline void setText(const std::string &text) { this->text = text; }
        inline const std::string &getText() const { return text; }

    private:
        std::string text;
    };

    class WhitespaceToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Whitespace; }
        inline const std::string toString() const override { return " "; }
    };

    class IdentToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Ident; }
        inline const std::string toString() const override { return identifier; }

        SOFTLOQ_CSS_API IdentToken();
        SOFTLOQ_CSS_API IdentToken(const std::string &identifier);

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

    private:
        std::string identifier;
    };

    class FunctionToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Function; }
        inline const std::string toString() const override { return identifier + '(' + parameter_list + ')'; }

        SOFTLOQ_CSS_API FunctionToken();
        SOFTLOQ_CSS_API FunctionToken(const std::string &identifier, const std::string &parameter_list);

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

        inline void setParameterList(const std::string &parameter_list) { this->parameter_list = parameter_list; }
        inline const std::string &getParameterList() const { return parameter_list; }

    private:
        std::string identifier, parameter_list;
    };

    class AtKeywordToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::AtKeyword; }
        inline const std::string toString() const override { return std::string("@") + identifier; }

        SOFTLOQ_CSS_API AtKeywordToken();
        SOFTLOQ_CSS_API AtKeywordToken(const std::string &identifier);

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

    private:
        std::string identifier;
    };

    class HashToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Hash; }
        inline const std::string toString() const override { return std::string("#") + hash; }

        SOFTLOQ_CSS_API HashToken();
        SOFTLOQ_CSS_API HashToken(const std::string &hash);

        inline void setHash(const std::string &hash) { this->hash = hash; }
        inline const std::string &getHash() const { return hash; }

    private:
        std::string hash;
    };

    class StringToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::String; }
        inline const std::string toString() const override { return std::string("\"") + text + '"'; }

        SOFTLOQ_CSS_API StringToken();
        SOFTLOQ_CSS_API StringToken(const std::string &text);

        inline void setString(const std::string &text) { this->text = text; }
        inline const std::string &getString() const { return text; }

    private:
        std::string text;
    };

    class URLToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::URL; }
        inline const std::string toString() const override { return std::string("url(") + link + ')'; }

        SOFTLOQ_CSS_API URLToken();
        SOFTLOQ_CSS_API URLToken(const std::string &link);

        inline void setLink(const std::string &link) { this->link = link; }
        inline const std::string &getLink() const { return link; }

    private:
        std::string link;
    };

    class NumberToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Number; }
        inline const std::string toString() const override { return std::to_string(number); }

        SOFTLOQ_CSS_API NumberToken();
        SOFTLOQ_CSS_API NumberToken(const float number);

        inline void setNumber(const float number) { this->number = number; }
        inline const float getNumber() const { return number; }

    private:
        float number;
    };

    class DimensionToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Dimension; }
        inline const std::string toString() const override { return std::to_string(number) + identifier; }

        SOFTLOQ_CSS_API DimensionToken();
        SOFTLOQ_CSS_API DimensionToken(const float number, const std::string &identifier);

        inline void setNumber(const float number) { this->number = number; }
        inline const float getNumber() const { return number; }

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

    private:
        float number;
        std::string identifier;
    };

    class PercentageToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Percentage; }
        inline const std::string toString() const override { return std::to_string(number) + '%'; }

        SOFTLOQ_CSS_API PercentageToken();
        SOFTLOQ_CSS_API PercentageToken(const float number);

        inline void setNumber(const float number) { this->number = number; }
        inline const float getNumber() const { return number; }

    private:
        float number;
    };

    class CDOToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::CDO; }
        inline const std::string toString() const override { return "<!--"; }
    };

    class CDCToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::CDC; }
        inline const std::string toString() const override { return "-->"; }
    };
}

#endif