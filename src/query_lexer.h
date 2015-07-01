//
// Created by hudong on 7/1/15.
//

#ifndef SPIRIT_QUERY_LEXER_H_
#define SPIRIT_QUERY_LEXER_H_

#include <boost/spirit/include/lex_lexertl.hpp>

namespace query_rewriter {
namespace query_parser {

template<typename Lexer>
class QueryLexer
    : public boost::spirit::lex::lexer<Lexer> {
 public:
  QueryLexer() {
    phrase_ = "[^ \\t\\n\\r()]+";
    and_ = "AND";
    or_ = "OR";
    not_ = "NOT";

    this->self = boost::spirit::lex::token_def<>('(') | ')' | and_ | or_ | not_ | phrase_;

    this->self("WS") = boost::spirit::lex::token_def<>("[ \\t\\n\\r]+");
  }

  boost::spirit::lex::token_def<> and_;
  boost::spirit::lex::token_def<> or_;
  boost::spirit::lex::token_def<> not_;
  boost::spirit::lex::token_def<std::string> phrase_;
};

}  // namespace query_parser
}  // query_rewriter

#endif  // SPIRIT_QUERY_LEXER_H_
