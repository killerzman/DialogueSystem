#include "Writer.h"

namespace DS {

	Writer::Writer(std::string text, DS::WriterDelay delay, float delayFactor)
	{
		m_Text = text;
		m_Delay = delay;
		m_DelayFactor = delayFactor;
		regexFiltersInit();
	}

	Writer::Writer(std::string text, unsigned int delay, float delayFactor)
	{
		m_Text = text;
		m_Delay = static_cast<DS::WriterDelay>(delay);
		m_DelayFactor = delayFactor;
		regexFiltersInit();
	}


	Writer::Writer(std::string text, DS::WriterDelay delay)
	{
		m_Text = text;
		m_Delay = delay;
		regexFiltersInit();
	}

	Writer::Writer(std::string text, unsigned int delay)
	{
		m_Text = text;
		m_Delay = static_cast<DS::WriterDelay>(delay);
		regexFiltersInit();
	}

	Writer::Writer(std::string text, float delayFactor)
	{
		m_Text = text;
		m_DelayFactor = delayFactor;
		m_Delay = WriterDelay::_NORMAL;
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
		int _size = sizeof(DS::RegexFilters::_regStr) / sizeof(DS::RegexFilters::_regStr[0]);
		for (int i = 0; i < _size; i++)
		{
			m_RegexFilters[DS::RegexFilters::_regStr[i]] = DS::RegexFilters::_regArr[i];
		}
	}

	void Writer::Write()
	{
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
						m_Delay = static_cast<DS::WriterDelay>(delayNumber);
					}
					else if (firstFilterString == "NEWLINE")
					{
						_OUTPUT_WRITE("\n");
					}
					else if (firstFilterString == "PAUSE")
					{
						int pauseNumber = subText[firstFilterPosition + firstFilterMatch.length(0) - 2] - '0';
						int _idx = 0;
						float pauseInSeconds = 1;
						for (const auto& pauseItem : PauseDelay)
						{
							if (_idx == pauseNumber)
							{
								pauseInSeconds = pauseItem.second;
								break;
							}
							else
							{
								_idx++;
							}
						}
						std::this_thread::sleep_for(std::chrono::milliseconds(int(pauseInSeconds * 1000)));
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
}
