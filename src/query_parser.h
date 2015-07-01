//
// Created by hudong on 7/1/15.
//

#ifndef SPIRIT_QUERY_PARSER_H_
#define SPIRIT_QUERY_PARSER_H_

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/home/phoenix/object/new.hpp>

#include "ast_phrase_node.h"
#include "ast_and_node.h"
#include "ast_or_node.h"
#include "ast_not_node.h"
#include "query_lexer.h"

namespace query_rewriter {
namespace query_parser {

template<typename Iterator, typename Lexer>
class QueryParser
    : public boost::spirit::qi::grammar<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer> > {
 public:
  template<typename Token>
  QueryParser(const Token &token)
      : QueryParser::base_type(root_) {
    root_
        = (query_ >> root_)                      [ boost::spirit::_val = boost::phoenix::new_<AstAndNode>(boost::spirit::_1, boost::spirit::_2) ]
          | query_                               [ boost::spirit::_val = boost::spirit::_1 ]
        ;

    query_
        = (expression_ >> and_logic_)            [ boost::spirit::_val = boost::phoenix::new_<AstAndNode>(boost::spirit::_1, boost::spirit::_2) ]
          | (token.not_ >> query_ >> and_logic_) [ boost::spirit::_val = boost::phoenix::new_<AstAndNode>(boost::phoenix::new_<AstNotNode>(boost::spirit::_2), boost::spirit::_2) ]
          | ('(' >> query_ >> ')' >> and_logic_) [ boost::spirit::_val = boost::phoenix::new_<AstAndNode>(boost::spirit::_1, boost::spirit::_2) ]
          | (expression_ >> or_logic_)           [ boost::spirit::_val = boost::phoenix::new_<AstOrNode>(boost::spirit::_1, boost::spirit::_2) ]
          | (token.not_ >> query_ >> or_logic_)  [ boost::spirit::_val = boost::phoenix::new_<AstOrNode>(boost::phoenix::new_<AstNotNode>(boost::spirit::_2), boost::spirit::_2) ]
          | ('(' >> query_ >> ')' >> or_logic_)  [ boost::spirit::_val = boost::phoenix::new_<AstOrNode>(boost::spirit::_1, boost::spirit::_2) ]
          | (token.not_ >> query_)               [ boost::spirit::_val = boost::phoenix::new_<AstNotNode>(boost::spirit::_2) ]
          | ('(' >> query_ >> ')')               [ boost::spirit::_val = boost::spirit::_1 ]
          | (expression_)                        [ boost::spirit::_val = boost::spirit::_1 ]
        ;

    and_logic_
        = (token.and_ >> query_)                 [ boost::spirit::_val = boost::spirit::_2 ]
        ;

    or_logic_
        = (token.or_ >> query_)                  [ boost::spirit::_val = boost::spirit::_2 ]
        ;

    expression_
        = token.phrase_                          [ boost::spirit::_val = boost::phoenix::new_<AstPhraseNode>(boost::spirit::_1) ]
        ;
  }

  boost::spirit::qi::rule<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer>> expression_;
  boost::spirit::qi::rule<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer>> root_;
  boost::spirit::qi::rule<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer>> query_;
  boost::spirit::qi::rule<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer>> and_logic_;
  boost::spirit::qi::rule<Iterator, AstNode *(), boost::spirit::qi::in_state_skipper<Lexer>> or_logic_;
};

}  // namespace query_parser
}  // query_rewriter

#endif  // SPIRIT_QUERY_PARSER_H_
