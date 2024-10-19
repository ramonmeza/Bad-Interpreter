#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer
{
public:
	Lexer();
	~Lexer();

	void Lex(const std::string& in);	// Starts the lexer

	void ShowTokens();	// Prints out all tokens
	std::vector<Token*>& GetTokens() { return tokens; }	// Returns a reference to the tokens

private:
	std::string input;	// Contains the code to parse/tokenize
	int parseIndex;		// The current index to parse from the input
	
	Token* GetNextToken();		// Gets the next token in the input
	std::vector<Token*> tokens;	// Stores all of the tokens

	// Helper functions
	bool isInt(char in);
	bool isPlus(char in);
	bool isSub(char in);
	bool isMult(char in);
	bool isExpr(char in);
	bool isEND(char in);
};

#endif