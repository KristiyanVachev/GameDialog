#pragma once
#include <string>
using namespace std;

class DialogOption
{

private:
	int m_id;
	string m_text;
	int m_toId;
public:
	DialogOption(int, string, int);
	~DialogOption();

	int getId();
	string getOptionText();
	int getOptionToId();
};

