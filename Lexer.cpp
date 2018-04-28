#include "Lexer.hpp"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
	tokens.clear();
}

void Lexer::ShowTokens()
{
	for (auto itr = tokens.begin(); itr != tokens.end(); itr++)
	{
		(*itr)->Print();
	}
}

void Lexer::Lex(std::string in)
{
	input = in;

	Token* tok;

	do
	{
		tok = GetNextToken();
		tokens.push_back(tok);
	} while (tok->type != TokenType::END);
}

Token* Lexer::GetNextToken()
{
	// Create new token
	Token* tok;

	// Decypher input into a token
	if (isInt(input[parseIndex]))
	{
		tok = new Token(TokenType::INTEGER, input[parseIndex]);
	}
	else if (isPlus(input[parseIndex]))
	{
		tok = new Token(TokenType::PLUS, input[parseIndex]);
	}
	else if (isSub(input[parseIndex]))
	{
		tok = new Token(TokenType::SUB, input[parseIndex]);
	}
	else if (isMult(input[parseIndex]))
	{
		tok = new Token(TokenType::MULT, input[parseIndex]);
	}
	else if (isExpr(input[parseIndex]))
	{
		tok = new Token(TokenType::EXPR, '\0');
	}
	else
	{
		// syntax error
		tok = new Token(TokenType::ERROR, '\0');
	}
	
	if (isEND(input[parseIndex]))
	{
		tok = new Token(TokenType::END, '\0');
	}

	// Increment the index
	parseIndex++;

	// Return the token
	return tok;
}

bool Lexer::isInt(char in)
{
	if (in == '0' || in == '1' || in == '2' || in == '3' ||
		in == '4' || in == '5' || in == '6' || in == '7' ||
		in == '8' || in == '9')
		return true;

	return false;
}

bool Lexer::isPlus(char in)
{
	if (in == '+')
		return true;

	return false;
}

bool Lexer::isSub(char in)
{
	if (in == '-')
		return true;

	return false;
}

bool Lexer::isMult(char in)
{
	if (in == '*')
		return true;

	return false;
}

bool Lexer::isExpr(char in)
{
	if (in == ';' || in == '\n')
		return true;

	return false;
}

bool Lexer::isEND(char in)
{
	if (in == EOF || in == '\0')
		return true;

	return false;
}