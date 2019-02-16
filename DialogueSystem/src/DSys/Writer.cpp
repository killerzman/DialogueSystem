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
}
