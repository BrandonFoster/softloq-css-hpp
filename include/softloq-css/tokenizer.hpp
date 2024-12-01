#ifndef SOFTLOQ_CSS_TOKENIZER_HPP
#define SOFTLOQ_CSS_TOKENIZER_HPP

#include "softloq-css/token.hpp"

#include <list>
#include <memory>

namespace Softloq::CSS
{
    using TokenList = std::list<std::unique_ptr<Token>>;
    class Tokenizer
    {
    public:
        SOFTLOQ_CSS_API const bool consumeTokens(const std::string &css_text, TokenList &tokens);
        SOFTLOQ_CSS_API Token *consumeToken(const std::string &css_text);
        SOFTLOQ_CSS_API CommentToken *consumeCommentToken(const std::string &css_text);
        SOFTLOQ_CSS_API WhitespaceToken *consumeWhitespaceToken(const std::string &css_text);
        SOFTLOQ_CSS_API StringToken *consumeStringToken(const std::string &css_text);
        SOFTLOQ_CSS_API Token *consumeNumericToken(const std::string &css_text);
        SOFTLOQ_CSS_API NumberToken *consumeNumberToken(const std::string &css_text);
        SOFTLOQ_CSS_API PercentageToken *consumePercentageToken(const std::string &css_text);
        SOFTLOQ_CSS_API DimensionToken *consumeDimensionToken(const std::string &css_text);
        SOFTLOQ_CSS_API Token *consumeIdentLikeToken(const std::string &css_text);
        SOFTLOQ_CSS_API IdentToken *consumeIdentToken(const std::string &css_text);
        SOFTLOQ_CSS_API FunctionToken *consumeFunctionToken(const std::string &css_text);
        SOFTLOQ_CSS_API URLToken *consumeURLToken(const std::string &css_text);
        SOFTLOQ_CSS_API BadURLToken *consumeBadURLToken(const std::string &css_text);
        SOFTLOQ_CSS_API AtKeywordToken *consumeAtKeywordToken(const std::string &css_text);
        SOFTLOQ_CSS_API HashToken *consumeHashToken(const std::string &css_text);
        SOFTLOQ_CSS_API LParenToken *consumeLeftParenToken(const std::string &css_text);
        SOFTLOQ_CSS_API RParenToken *consumeRightParenToken(const std::string &css_text);
        SOFTLOQ_CSS_API CommaToken *consumeCommaToken(const std::string &css_text);
        SOFTLOQ_CSS_API CDOToken *consumeCDOToken(const std::string &css_text);
        SOFTLOQ_CSS_API CDCToken *consumeCDCToken(const std::string &css_text);
        SOFTLOQ_CSS_API SemicolonToken *consumeSemicolonToken(const std::string &css_text);
        SOFTLOQ_CSS_API ColonToken *consumeColonToken(const std::string &css_text);
        SOFTLOQ_CSS_API LSquareToken *consumeLeftSquareBracketToken(const std::string &css_text);
        SOFTLOQ_CSS_API RSquareToken *consumeRightSquareBracketToken(const std::string &css_text);
        SOFTLOQ_CSS_API LCurlyToken *consumeLeftCurlyBracketToken(const std::string &css_text);
        SOFTLOQ_CSS_API RCurlyToken *consumeRightCurlyBracketToken(const std::string &css_text);
        SOFTLOQ_CSS_API EOFToken *consumeEOFToken(const std::string &css_text);
        SOFTLOQ_CSS_API DelimToken *consumeDelimToken(const std::string &css_text);

    private:
        Error err;
    };
}

#endif