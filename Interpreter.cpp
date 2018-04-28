#include "Interpreter.hpp"

Interpreter::Interpreter()
{
}

Interpreter::~Interpreter()
{
}

void Interpreter::Interpret(std::string input)
{
	// Lex the input
	lex.Lex(input);

	// Get the tokens
	auto tokens = lex.GetTokens();

	// Go through the tokens
	for (auto itr = tokens.begin(); itr != tokens.end(); itr++)
	{
		if ((*itr)->type != TokenType::END)
		{
			// Get a single expression
			std::vector<Token*> expr;
			while ((*itr)->type != TokenType::EXPR)
			{
				expr.push_back((*itr));
				itr++;
			}

			// Handle expression
			auto e = expr.begin();

			TokenType OP;
			int LHS = 0, RHS = 0;

			// Get LHS
			while ((*e)->type != TokenType::PLUS &&
				(*e)->type != TokenType::SUB &&
				(*e)->type != TokenType::MULT)
			{
				LHS *= 10;
				LHS += (*e)->value - '0';

				e++;
			}

			OP = (*e)->type;
			e++;

			// Get RHS
			while (e != expr.end())
			{
				RHS *= 10;
				RHS += (*e)->value - '0';

				e++;
			}

			// Print result
			int result = 0;
			switch (OP)
			{
			case TokenType::PLUS:
				result = LHS + RHS;
				break;
			case TokenType::SUB:
				result = LHS - RHS;
				break;
			case TokenType::MULT:
				result = LHS * RHS;
				break;
			default:
				std::cout << "Error..." << std::endl;
				break;
			}

			std::cout << result << std::endl;
		}
	}
}