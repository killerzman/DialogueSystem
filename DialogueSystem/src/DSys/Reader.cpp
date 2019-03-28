#include "Reader.h"

namespace DS {

	Reader::Reader(ReaderType rType, const std::string& buf)
	{
		if (rType == DS::ReaderType::_FILE)
		{
			std::ifstream file(buf);
			if (file.is_open())
			{
				m_Path = buf;
				std::stringstream stream;
				stream << file.rdbuf();
				m_Text = stream.str();
				m_RType = rType;
				file.close();
			}
			else
			{
				_OUTPUT_ERROR_PATH(buf);
			}
		}

		else if (rType == DS::ReaderType::_TEXT)
		{
			if (buf.size())
			{
				m_Path = "**NOT_A_FILE**";
				m_Text = buf;
				m_RType = rType;
			}
			else
			{
				_OUTPUT_ERROR_EMPTY_TEXT(buf);
			}
		}
	}

	std::string Reader::getPath()
	{
		return m_Path;
	}

	std::string Reader::getText()
	{
		return m_Text;
	}

	ReaderType Reader::getRType()
	{
		return m_RType;
	}

	Reader::~Reader()
	{
	}
}
