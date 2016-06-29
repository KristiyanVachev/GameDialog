#pragma once
#include "DialogNode.h"
#include <fstream>

class DialogTree
{
private: 
	vector<DialogNode> m_nodes;
public:
	DialogTree();
	DialogTree(vector<DialogNode>);
	~DialogTree();

	vector<DialogNode> GetNodes();

	void Load(string name);
	void PerformDialog();

};

