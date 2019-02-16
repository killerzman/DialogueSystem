#include "Parser.h"

Parser::Parser(std::string text)
{
	std::smatch m;
	if (std::regex_search(text, m, RegexMatches::_DELAY))
	{
		for (int i = m.position(0) + m.length(0); i < text.length(); i++)
		{
			std::cout << text[i];
		}
	}
}


Parser::~Parser()
{
}
