#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include "Lexer.hpp"

class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	void Interpret(const std::string& input);

private:
	Lexer lex;
};

#endif