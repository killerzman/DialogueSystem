#pragma once

#include "dsyspch.h"

#include "Core.h"

namespace RegexMatches
{
	//const std::regex _DELAY("\\$(\\s+|\\S+)?\\(S[0-9]+\\)");
	//const std::regex _NEWLINE("\\\\n");
}

class Writer
{
public:
	Writer(std::string, WriterDelay);
	Writer(std::string);
	~Writer();
	void Write();
	std::string getText();
	void setText(std::string);
	WriterDelay getDelay();
	void setDelay(WriterDelay);
private:
	std::string m_Text;
	WriterDelay m_Delay;
	const float m_DelayFactor = 0.01f;
};

