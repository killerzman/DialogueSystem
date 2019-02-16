#pragma once

#include "dsyspch.h"

#include "Core.h"

class Writer
{
public:
	Writer(std::string, WriterDelay);
	Writer(std::string);
	~Writer();
	void Write();

	std::string m_Text;
	WriterDelay m_Delay;
	const float m_DelayFactor = 0.01f;
};

