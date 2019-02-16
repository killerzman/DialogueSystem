#pragma once

#include "dsyspch.h"

#include "Core.h"

class Reader
{
public:
	Reader(ReaderType, const std::string&);
	std::string getPath();
	std::string getText();
	ReaderType getRType();
	~Reader();
private:
	std::string m_Path;
	std::string m_Text;
	ReaderType m_RType;
};

