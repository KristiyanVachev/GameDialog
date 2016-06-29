#include "DialogTree.h"

int main() 
{
	DialogTree tree;
	string filename = "test.txt";

	tree.Load(filename);
	
	tree.PerformDialog();
	
	return 0;
}