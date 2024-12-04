#ifndef SOFTLOQ_CSS_TOKEN_HPP
#define SOFTLOQ_CSS_TOKEN_HPP

/**
 * @author Brandon Foster
 * @file token.hpp
 * @version 1.0.0
 * @brief CSS Tokens are based on https://www.w3.org/TR/css-syntax-3/
 */

#include "softloq-css/error.hpp"
#include <softloq-unicode/unicode.hpp>

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
        BadURL,
        Number,
        Dimension,
        Percentage,
        LeftParenthesis,
        RightParenthesis,
        Comma,
        CDO,
        CDC,
        Semicolon,
        Colon,
        LeftSquareBracket,
        RightSquareBracket,
        LeftCurlyBracket,
        RightCurlyBracket,
        EndOfFile,
        Delim
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
        inline const std::string toString() const override { return std::string("/* ") + text + " */"; }

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

        SOFTLOQ_CSS_API AtKeywordToken(const std::string &identifier);

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

    private:
        std::string identifier;
    };

    class HashToken : public Token
    {
    public:
        enum class Type
        {
            ID,
            Unrestricted
        };

        inline const TokenType getTokenType() const override
        {
            return TokenType::Hash;
        }
        inline const std::string toString() const override { return std::string("#") + hash; }

        SOFTLOQ_CSS_API HashToken(const std::string &hash);
        SOFTLOQ_CSS_API HashToken(const std::string &hash, const Type type);

        inline void setHash(const std::string &hash) { this->hash = hash; }
        inline const std::string &getHash() const { return hash; }

        inline void setType(const Type type) { this->type = type; }
        inline const Type getType() const { return type; }

    private:
        std::string hash;
        Type type;
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

        SOFTLOQ_CSS_API URLToken(const std::string &link);

        inline void setLink(const std::string &link) { this->link = link; }
        inline const std::string &getLink() const { return link; }

    private:
        std::string link;
    };

    class BadURLToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::BadURL; }
        inline const std::string toString() const override { return std::string("url(") + bad_link + ')'; }

        SOFTLOQ_CSS_API BadURLToken(const std::string &bad_link);

        inline void setLink(const std::string &bad_link) { this->bad_link = bad_link; }
        inline const std::string &getLink() const { return bad_link; }

    private:
        std::string bad_link;
    };

    class NumericFlagToken : public Token
    {
    private:
        union NumberValue
        {
            int integer;
            float number;
        };

    public:
        enum class Type
        {
            Integer,
            Number
        };

        SOFTLOQ_CSS_API explicit NumericFlagToken(const int integer);
        SOFTLOQ_CSS_API NumericFlagToken(const float number);
        SOFTLOQ_CSS_API virtual ~NumericFlagToken() = 0;

        inline void setNumber(const float number)
        {
            this->value.number = number;
            flag = Type::Number;
        }
        inline const float getNumber() const { return value.number; }

        inline void setInteger(const int integer)
        {
            this->value.integer = integer;
            flag = Type::Integer;
        }
        inline const int getInteger() const { return value.integer; }

        inline const Type getFlagType() const { return flag; }

    private:
        NumberValue value;
        Type flag;
    };

    class NumberToken : public NumericFlagToken
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Number; }
        inline const std::string toString() const override { return getFlagType() == Type::Number ? std::to_string(getNumber()) : std::to_string(getInteger()); }

        SOFTLOQ_CSS_API explicit NumberToken(const int integer);
        SOFTLOQ_CSS_API NumberToken(const float number);
    };

    class DimensionToken : public NumericFlagToken
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Dimension; }
        inline const std::string toString() const override { return (getFlagType() == Type::Number ? std::to_string(getNumber()) : std::to_string(getInteger())) + identifier; }

        SOFTLOQ_CSS_API explicit DimensionToken(const int integer, const std::string &identifier);
        SOFTLOQ_CSS_API DimensionToken(const float number, const std::string &identifier);

        inline void setIdentifier(const std::string &identifier) { this->identifier = identifier; }
        inline const std::string &getIdentifier() const { return identifier; }

    private:
        std::string identifier;
    };

    class PercentageToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Percentage; }
        inline const std::string toString() const override { return std::to_string(number) + '%'; }

        SOFTLOQ_CSS_API PercentageToken(const float number);

        inline void setNumber(const float number) { this->number = number; }
        inline const float getNumber() const { return number; }

    private:
        float number;
    };

    class LParenToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::LeftParenthesis; }
        inline const std::string toString() const override { return "("; }
    };

    class RParenToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::RightParenthesis; }
        inline const std::string toString() const override { return ")"; }
    };

    class CommaToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Comma; }
        inline const std::string toString() const override { return ","; }
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

    class SemicolonToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Semicolon; }
        inline const std::string toString() const override { return ";"; }
    };

    class ColonToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Colon; }
        inline const std::string toString() const override { return ":"; }
    };

    class LSquareToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::LeftSquareBracket; }
        inline const std::string toString() const override { return "["; }
    };

    class RSquareToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::RightSquareBracket; }
        inline const std::string toString() const override { return "]"; }
    };

    class LCurlyToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::LeftCurlyBracket; }
        inline const std::string toString() const override { return "{"; }
    };

    class RCurlyToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::RightCurlyBracket; }
        inline const std::string toString() const override { return "}"; }
    };

    class EOFToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::EndOfFile; }
        inline const std::string toString() const override { return ""; }
    };

    class DelimToken : public Token
    {
    public:
        inline const TokenType getTokenType() const override { return TokenType::Delim; }
        inline const std::string toString() const override
        {
            std::string utf8;
            Unicode::convertCodepointToUTF8(codepoint, utf8);
            return utf8;
        }

        SOFTLOQ_CSS_API DelimToken(const char32_t codepoint);

        inline void setCodepoint(const char32_t codepoint) { this->codepoint = codepoint; }
        inline const char32_t getCodepoint() const { return codepoint; }

    private:
        char32_t codepoint;
    };
}

#endif