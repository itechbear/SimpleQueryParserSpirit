#include <fstream>

#include "driver.h"


int main(int argc, char *argv[]) {
  //typedef std::string::iterator base_iterator_type;
  //
  //typedef boost::spirit::lex::lexertl::token<base_iterator_type, boost::mpl::vector<unsigned int, std::string>> token_type;
  //typedef boost::spirit::lex::lexertl::lexer<token_type> lexer_type;
  //typedef query_rewriter::query_parser::QueryLexer<lexer_type> QueryLexer;
  //typedef QueryLexer::iterator_type iterator_type;
  //typedef query_rewriter::query_parser::QueryParser<iterator_type, QueryLexer::lexer_def> QueryParser;
  //
  //QueryLexer query_lexer;                         // Our lexer
  //query_rewriter::query_parser::AstNode *root = nullptr;
  //QueryParser query_parser(query_lexer);                  // Our parser
  //
  //std::string str (argv[1]);
  //
  //std::string::iterator it = str.begin();
  //iterator_type iter = query_lexer.begin(it, str.end());
  //iterator_type end = query_lexer.end();
  //
  //bool r = boost::spirit::qi::phrase_parse(iter, end, query_parser, boost::spirit::qi::in_state("WS")[query_lexer.self], root);

  query_rewriter::query_parser::Driver driver;
  query_rewriter::query_parser::AstNode *node = nullptr;

  if (driver.Parse("NOT that", &node) && nullptr != node) {
    std::cout << "-------------------------\n";
    std::cout << "Parsing succeeded\n";
    std::cout << "-------------------------\n";
    delete node;
  } else {
    std::cout << "-------------------------\n";
    std::cout << "Parsing failed\n";
    std::cout << "-------------------------\n";
  }

  std::cout << "Bye... :-) \n\n";

  return 0;
}