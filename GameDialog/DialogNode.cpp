#include "DialogNode.h"



DialogNode::DialogNode(int id, string text, vector<DialogOption> options)
{
	m_id = id;
	m_text = text;
	m_options = options;
}


DialogNode::~DialogNode()
{
}

string DialogNode::getText() 
{
	return m_text;
}

vector<DialogOption> DialogNode::getOptions()
{
	return m_options;
}


