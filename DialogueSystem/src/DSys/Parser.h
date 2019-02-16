#pragma once

#include "dsyspch.h"

#include "Core.h"

namespace RegexMatches
{
	const std::regex _DELAY("\\$(\\s+|\\S+)?\\(S[0-9]+\\)");
	const std::regex _NEWLINE("\\\\n");
}

class Parser
{
public:
	Parser(std::string text);
	~Parser();
};

