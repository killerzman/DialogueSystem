#pragma once

#include "dsyspch.h"

#include "Core.h"

namespace DS {

	enum WriterDelay
	{
		_FASTEST = 0,
		_FASTER,
		_FAST,
		_NORMAL,
		_SLOW,
		_SLOWER,
		_SLOWEST
	};

	inline std::unordered_map<std::string, float> PauseDelay = {
		{"_1QUARTERSECOND", 1 / 4},
		{"_1HALFSECOND", 1 / 2},
		{"_1SECOND", 1},
		{"_2SECONDS", 2},
		{"_3SECONDS", 3},
		{"_4SECONDS", 4},
		{"_5SECONDS", 5}
	};

	namespace RegexFilters
	{
		inline std::regex _regArr[] = {
			std::regex("(\\$?\\(S[0-9]+\\)){1}"),
			std::regex("(\\$?\\(\\\\n\\)){1}"),
			std::regex("(\\$?\\(P[0-9]+\\)){1}")
		};

		inline std::string _regStr[] = {
			"DELAY",
			"NEWLINE",
			"PAUSE"
		};
	}

	class Writer
	{
	public:
		Writer(std::string, WriterDelay, float);
		Writer(std::string, unsigned int, float);
		Writer(std::string, WriterDelay);
		Writer(std::string, unsigned int);
		Writer(std::string, float);
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
		float m_DelayFactor = 0.01f;
		std::unordered_map<std::string, std::regex> m_RegexFilters;
		void regexFiltersInit();
	};

}