#pragma once
#include "DialogOption.h"
#include <vector>

class DialogNode
{
	int m_id;
	string m_text;
	vector<DialogOption> m_options;
public:
	DialogNode(int, string, vector<DialogOption>);
	~DialogNode();

	string getText();
	vector<DialogOption> getOptions();
};

