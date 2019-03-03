#include "Writer.h"

Writer::Writer(std::string text, WriterDelay delay)
{
	m_Text = text;
	m_Delay = delay;
	regexFiltersInit();
}

Writer::Writer(std::string text)
{
	m_Text = text;
	m_Delay = WriterDelay::_NORMAL;
	regexFiltersInit();
}


Writer::~Writer()
{
}

void Writer::regexFiltersInit()
{
	int _size = sizeof(RegexFilters::_regStr) / sizeof(RegexFilters::_regStr[0]);
	for (int i = 0; i < _size; i++)
	{
		m_RegexFilters[RegexFilters::_regStr[i]] = RegexFilters::_regArr[i];
	}
}

void Writer::Write()
{
	/*for (auto chr : m_Text)
	{
		_OUTPUT_WRITE(chr);
		std::this_thread::sleep_for(std::chrono::milliseconds(int((m_DelayFactor * BIT(m_Delay)) * 1000)));
	}*/

	/*std::smatch m;
	if (std::regex_search(text, m, RegexMatches::_DELAY))
	{
		for (int i = m.position(0) + m.length(0); i < text.length(); i++)
		{
			std::cout << text[i];
		}
	}*/

	/*for (auto rf : m_RegexFilters)
	{
		_OUTPUT_WRITE(rf.first);
	}*/

	bool reachedEndOfText = false;

	for (int i = 0; i < m_Text.length(); i++)
	{
		if (reachedEndOfText == false)
		{
			std::smatch m;
			std::string subText = m_Text.substr(i);
			std::string firstFilterString;
			int firstFilterPosition = subText.length() + 1;
			std::smatch firstFilterMatch;
			for (auto rf : m_RegexFilters)
			{
				if (std::regex_search(subText, m, rf.second))
				{
					if (m.position(0) < firstFilterPosition)
					{
						firstFilterPosition = m.position(0);
						firstFilterMatch = m;
						firstFilterString = rf.first;
					}
				}
			}
			if (firstFilterPosition == subText.length() + 1)
			{
				for (int j = 0; j < subText.length(); j++)
				{
					_OUTPUT_WRITE(subText[j]);
					std::this_thread::sleep_for(std::chrono::milliseconds(int((m_DelayFactor * BIT(m_Delay)) * 1000)));
				}

				reachedEndOfText = true;
			}
			else
			{
				if (firstFilterPosition != i)
				{
					for (int j = 0; j < firstFilterPosition; j++)
					{
						_OUTPUT_WRITE(subText[j]);
						std::this_thread::sleep_for(std::chrono::milliseconds(int((m_DelayFactor * BIT(m_Delay)) * 1000)));
						i++;
					}
				}

				if (firstFilterString == "DELAY")
				{
					int delayNumber = subText[firstFilterPosition + firstFilterMatch.length(0) - 2] - '0';
					m_Delay = static_cast<WriterDelay>(delayNumber);
				}
				else if (firstFilterString == "NEWLINE")
				{
					_OUTPUT_WRITE("\n");
				}
				
				i += (firstFilterMatch.length(0) - 1);

			}
		}
	}
}

std::string Writer::getText()
{
	return m_Text;
}

void Writer::setText(std::string text)
{
	m_Text = text;
}

WriterDelay Writer::getDelay()
{
	return m_Delay;
}

void Writer::setDelay(WriterDelay delay)
{
	m_Delay = delay;
}