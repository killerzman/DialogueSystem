#pragma once

#include "dsyspch.h"

#include "Core.h"

enum WriterDelay
{
	_FASTEST = 0,
	_FASTER = 1,
	_FAST = 2,
	_NORMAL = 3,
	_SLOW = 4,
	_SLOWER = 5,
	_SLOWEST = 6
};

namespace RegexFilters
{
	inline std::regex _regArr[] = {
		std::regex("(\\$?\\(S[0-9]+\\)){1}"),
		std::regex("(\\$?\\(\\\\n\\)){1}") 
	};

	inline std::string _regStr[] = {
		"DELAY",
		"NEWLINE" 
	};
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
	std::unordered_map<std::string, std::regex> m_RegexFilters;
	void regexFiltersInit();
};

