#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP
#pragma once

#include <string>
#include "Lexer.hpp"

class Interpreter
{
public:
	Interpreter();
	~Interpreter();

	void Interpret(std::string input);

private:
	Lexer lex;
};

#endif