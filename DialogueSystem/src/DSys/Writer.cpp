#include "Writer.h"

Writer::Writer(std::string text, WriterDelay delay)
{
	m_Text = text;
	m_Delay = delay;
}

Writer::Writer(std::string text)
{
	m_Text = text;
	m_Delay = WriterDelay::_NORMAL;
}


Writer::~Writer()
{
}

void Writer::Write()
{
	for (auto chr : m_Text)
	{
		_OUTPUT_WRITE(chr);
		std::this_thread::sleep_for(std::chrono::milliseconds(int((m_DelayFactor * BIT(m_Delay)) * 1000)));
	}

	/*std::smatch m;
	if (std::regex_search(text, m, RegexMatches::_DELAY))
	{
		for (int i = m.position(0) + m.length(0); i < text.length(); i++)
		{
			std::cout << text[i];
		}
	}*/
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