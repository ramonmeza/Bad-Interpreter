#ifndef TOKEN_HPP
#define TOKEN_HPP
#pragma once

#include <iostream>

// Different types of tokens
enum TokenType
{
	INTEGER,
	PLUS,
	EXPR,
	END,
	ERROR
};

// A token
struct Token
{
	TokenType type;
	char value;

	Token(TokenType t, char v)
	{
		type = t;
		value = v;
	}

	void Print()
	{
		std::string val;

		switch (type)
		{
		case TokenType::INTEGER:
			val = "INTEGER";
			break;
		case TokenType::PLUS:
			val = "PLUS";
			break;
		case TokenType::EXPR:
			val = "EXPR";
			break;
		case TokenType::END:
			val = "END";
			break;
		default:
			val = "ERROR";
			break;
		}

		std::cout << "Token(" << val <<  ", " << value << ")" << std::endl;
	}
};

#endif