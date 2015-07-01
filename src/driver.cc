//
// Created by hudong on 7/1/15.
//

#include "driver.h"

namespace query_rewriter {
namespace query_parser {

Driver::Driver()
    : query_lexer_(), query_parser_(query_lexer_) {
}

Driver::~Driver() {
}

bool Driver::Parse(std::string input, AstNode **root) const {
  std::string::iterator it = input.begin();
  iterator_type iter = query_lexer_.begin(it, input.end());
  iterator_type end = query_lexer_.end();

  bool result = boost::spirit::qi::phrase_parse(iter,
                                                end,
                                                query_parser_,
                                                boost::spirit::qi::in_state("WS")[query_lexer_.self], *root);

  return result && (iter == end);
}

}  // namespace query_parser
}  // query_rewriter