#include "DialogTree.h"
#include <iostream>
using namespace std;


DialogTree::DialogTree()
{

}

DialogTree::DialogTree(vector<DialogNode> nodes)
{
	m_nodes = nodes;
}


DialogTree::~DialogTree()
{
}

vector<DialogNode> DialogTree::GetNodes() 
{
	return m_nodes;
}

void DialogTree::Load(string filename)
{
	ifstream infile(filename);
	string line;

	bool inNewNode = true; //if false, we are in an option.

	vector<DialogOption> currentOptions; //vector to keep the options of the nodes while reading
	int optionId = 0;
	string currentNodeText;
	int currNodeIndex;

	vector<DialogNode> nodes; //vector in which to keep the nodes while reading the file

	bool nodeAdded = false;

	while (getline(infile, line))
	{
		//Rules of the text file:
		//Each node must be separated by a new line (empty string).		
		//Index of the node text and and the text itself must be separated by a ':'
		//Every option of the node and the pointed index must be separated by a "=>"

		//write data
		if (inNewNode)
		{
			int separator = line.find(':') + 2;
			int lenght = line.size() - (separator);

			currentNodeText = line.substr(separator, lenght);
			
			currNodeIndex = stoi(line.substr(0, separator - 2));

			nodeAdded = false;
			inNewNode = false;
		}
		else //in an option
		{
			if (!line.empty())
			{
				int separator = line.find("=>");
				int lenght = line.size() - (separator);

				//get the option text
				string optiontext = line.substr(0, separator);
				
				//get the node to which it corresponds
				int toIndex = stoi(line.substr(separator + 3, lenght));
				
				optionId++;
				DialogOption newOption(optionId, optiontext, toIndex);
				currentOptions.push_back(newOption);
			}
			else
			{
				//if the line is empty, skip it and start working with nodes
				DialogNode newNode(currNodeIndex, currentNodeText, currentOptions);
				m_nodes.push_back(newNode);
				nodeAdded = true;

				currentOptions.clear();
				optionId = 0;
				inNewNode = true;
			}
		}
	}

	if (!nodeAdded)
	{
		DialogNode newNode(currNodeIndex, currentNodeText, currentOptions);
		m_nodes.push_back(newNode);
	}
	infile.close();

}

void DialogTree::PerformDialog() 
{
	int optionNumber;
	int nodeIndex = 1;
	//while answers lead to another node. will end when -1
	while (nodeIndex >= 0)
	{
		cout << m_nodes.at(nodeIndex - 1).getText() << endl; //print node text
		int optionsCount = m_nodes.at(nodeIndex - 1).getOptions().size(); //count of the possible answers
		for (int i = 0; i < optionsCount; i++) //for each answer print option and answer text
		{
			cout << m_nodes.at(nodeIndex - 1).getOptions().at(i).getId() << ". "
				<< m_nodes.at(nodeIndex - 1).getOptions().at(i).getOptionText()
				<< endl;
		}

		cin >> optionNumber;
		if (optionNumber <= 0 || optionNumber > optionsCount) // validation
		{
			cout << "Invalid input. Write the number before the desired answer." << endl;
			while (optionNumber <= 0 || optionNumber > optionsCount)
			{
				cin >> optionNumber;
			}
		}
	
		//get the index of the next node
		nodeIndex = m_nodes.at(nodeIndex - 1).getOptions().at(optionNumber - 1).getOptionToId();
		
	}
}