//
// Created by hudong on 7/1/15.
//

#ifndef SPIRIT_DRIVER_H_
#define SPIRIT_DRIVER_H_

#include <string>

#include "query_parser.h"

namespace query_rewriter {
namespace query_parser {

class Driver {
 public:
  Driver();

  ~Driver();

  // Intentionally make a copy of input.
  bool Parse(std::string input, AstNode **root) const;

  typedef std::string::iterator base_iterator_type;

  typedef boost::spirit::lex::lexertl::token<base_iterator_type, boost::mpl::vector<unsigned int, std::string>> token_type;
  typedef boost::spirit::lex::lexertl::lexer<token_type> lexer_type;
  typedef query_rewriter::query_parser::QueryLexer<lexer_type> QueryLexer;
  typedef QueryLexer::iterator_type iterator_type;
  typedef query_rewriter::query_parser::QueryParser<iterator_type, QueryLexer::lexer_def> QueryParser;

 private:
  QueryLexer query_lexer_;
  QueryParser query_parser_;
};

}  // namespace query_parser
}  // query_rewriter

#endif  // SPIRIT_DRIVER_H_
