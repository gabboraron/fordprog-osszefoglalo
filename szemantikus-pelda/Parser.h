#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "Parserbase.h"


#undef Parser
class Parser: public ParserBase
{
        
    public:
        int parse();

    private:
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
};

inline void Parser::error(char const *msg)
{
    std::cerr << d_loc__.first_line << ": Szintaktikus hiba." << std::endl;
}

// $insert lex

inline void Parser::print()      // use d_token, d_loc
{}


#endif
