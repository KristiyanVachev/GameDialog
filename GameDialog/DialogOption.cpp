#include "DialogOption.h"



DialogOption::DialogOption(int id, string text, int toId)
{
	m_id = id;
	m_text = text;
	m_toId = toId;
}


DialogOption::~DialogOption()
{
}

int DialogOption::getId()
{
	return m_id;
}

string DialogOption::getOptionText()
{
	return m_text;
}

int DialogOption::getOptionToId()
{
	return m_toId;
}
