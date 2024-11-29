#include "softloq-css/token.hpp"

namespace Softloq::CSS
{
    SOFTLOQ_CSS_API CommentToken::CommentToken() {}
    SOFTLOQ_CSS_API CommentToken::CommentToken(const std::string &text) : text(text) {}

    SOFTLOQ_CSS_API IdentToken::IdentToken(const std::string &identifier) : identifier(identifier) {}

    SOFTLOQ_CSS_API FunctionToken::FunctionToken(const std::string &identifier, const std::string &parameter_list) : identifier(identifier), parameter_list(parameter_list) {}

    SOFTLOQ_CSS_API AtKeywordToken::AtKeywordToken(const std::string &identifier) : identifier(identifier) {}

    SOFTLOQ_CSS_API HashToken::HashToken(const std::string &hash) : hash(hash), type(Type::Unrestricted) {}
    SOFTLOQ_CSS_API HashToken::HashToken(const std::string &hash, const Type type) : hash(hash), type(type) {}

    SOFTLOQ_CSS_API StringToken::StringToken() {}
    SOFTLOQ_CSS_API StringToken::StringToken(const std::string &text) : text(text) {}

    SOFTLOQ_CSS_API URLToken::URLToken(const std::string &link) : link(link) {}

    SOFTLOQ_CSS_API NumericFlagToken::NumericFlagToken(const int integer)
    {
        value.integer = integer;
        flag = Type::Integer;
    }
    SOFTLOQ_CSS_API NumericFlagToken::NumericFlagToken(const float number)
    {
        value.number = number;
        flag = Type::Number;
    }
    SOFTLOQ_CSS_API NumericFlagToken::~NumericFlagToken() {}

    SOFTLOQ_CSS_API NumberToken::NumberToken(const int integer) : NumericFlagToken(integer) {}
    SOFTLOQ_CSS_API NumberToken::NumberToken(const float number) : NumericFlagToken(number) {}

    SOFTLOQ_CSS_API DimensionToken::DimensionToken(const int integer, const std::string &identifier) : NumericFlagToken(integer), identifier(identifier) {}
    SOFTLOQ_CSS_API DimensionToken::DimensionToken(const float number, const std::string &identifier) : NumericFlagToken(number), identifier(identifier) {}

    SOFTLOQ_CSS_API PercentageToken::PercentageToken(const float number) : number(number) {}

    SOFTLOQ_CSS_API DelimToken::DelimToken(const char32_t codepoint) : codepoint(codepoint) {}
}