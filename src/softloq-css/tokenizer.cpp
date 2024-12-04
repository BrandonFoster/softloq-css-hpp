#include "softloq-css/tokenizer.hpp"

namespace Softloq::CSS
{
    SOFTLOQ_CSS_API const bool Tokenizer::consumeTokens(const std::string &css_text, TokenList &tokens)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return false;
        Token *token;
        while (token == consumeCommentToken())
            tokens.push_back(std::unique_ptr<Token>(token));

        return false;
    }
    SOFTLOQ_CSS_API Token *Tokenizer::consumeToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API CommentToken *Tokenizer::consumeCommentToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API WhitespaceToken *Tokenizer::consumeWhitespaceToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API StringToken *Tokenizer::consumeStringToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API Token *Tokenizer::consumeNumericToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API NumberToken *Tokenizer::consumeNumberToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API PercentageToken *Tokenizer::consumePercentageToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API DimensionToken *Tokenizer::consumeDimensionToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API Token *Tokenizer::consumeIdentLikeToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API IdentToken *Tokenizer::consumeIdentToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API FunctionToken *Tokenizer::consumeFunctionToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API URLToken *Tokenizer::consumeURLToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API BadURLToken *Tokenizer::consumeBadURLToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API AtKeywordToken *Tokenizer::consumeAtKeywordToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API HashToken *Tokenizer::consumeHashToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API LParenToken *Tokenizer::consumeLeftParenToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API RParenToken *Tokenizer::consumeRightParenToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API CommaToken *Tokenizer::consumeCommaToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API CDOToken *Tokenizer::consumeCDOToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API CDCToken *Tokenizer::consumeCDCToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API SemicolonToken *Tokenizer::consumeSemicolonToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API ColonToken *Tokenizer::consumeColonToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API LSquareToken *Tokenizer::consumeLeftSquareBracketToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API RSquareToken *Tokenizer::consumeRightSquareBracketToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API LCurlyToken *Tokenizer::consumeLeftCurlyBracketToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API RCurlyToken *Tokenizer::consumeRightCurlyBracketToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API EOFToken *Tokenizer::consumeEOFToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }
    SOFTLOQ_CSS_API DelimToken *Tokenizer::consumeDelimToken(const std::string &css_text)
    {
        if (!(codepoints = Unicode::convertStringToUTF8CodepointVector(css_text)).size())
            return nullptr;
        return nullptr;
    }

    SOFTLOQ_CSS_API CommentToken *Tokenizer::consumeCommentToken()
    {
        const auto base_index = codepoints_index;

        // Next two input code point are U+002F SOLIDUS (/) followed by a U+002A ASTERISK (*)
        if (codepoints.size() - codepoints_index < 2 || !(codepoints[codepoints_index] == '/' && codepoints[codepoints_index + 1] == '*'))
            return nullptr;
        codepoints_index += 2;

        bool found_comment_end = false;
        std::string comment_text;
        while (codepoints.size() - codepoints_index >= 1)
        {
            const char32_t codepoint = codepoints[codepoints_index];

            // EOF code point found.
            if (!codepoint)
            {
                // Parse error.
                codepoints_index = base_index;
                return nullptr;
            }

            // Found U+002A ASTERISK (*) followed by a U+002F SOLIDUS (/)
            if (codepoints.size() - codepoints_index >= 2 && codepoints[codepoints_index] == '*' && codepoints[codepoints_index + 1] == '/')
            {
                found_comment_end = true;
                break;
            }
            Unicode::convertCodepointToUTF8(codepoint, comment_text);
            codepoints_index++;
        }
        codepoints_index += 2;
        return new CommentToken(comment_text);
    }

    SOFTLOQ_CSS_API WhitespaceToken *Tokenizer::consumeWhitespaceToken()
    {
    }
}