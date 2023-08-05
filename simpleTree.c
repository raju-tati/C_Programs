#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	int data;
	struct treeNode *leftNode;
	struct treeNode *rightNode;
};

static struct treeNode treeNodes[7];

struct treeNode*
tSearch (struct treeNode* root, int v)
{
	while (root)
	{
		printf
		(
			"looking for %d, looking at %d",
			v,
			root->data
		);
		
		if (root->data == v)
		{
			return(root);
		}
		
		if (root->data > v)
		{
			printf(" at left node of the tree\n");
			root = root->leftNode;
		}
		
		else
		{
			printf(" at right node of the tree\n");
			root = root->rightNode;
		}
	}
	
	return(0);
}

int
main(void)
{
	struct treeNode *temporaryNode, *rootNode;
	int counter;
	
	for(counter = 0; counter < 7; counter++)
	{
		int increment;
		increment = counter + 1;
		
		treeNodes[counter].data = increment;
		if (increment == 2 || increment == 6)
		{
			treeNodes[counter].leftNode  = &treeNodes[counter - 1];
			treeNodes[counter].rightNode = &treeNodes[counter + 1];
		}
	}
	
	rootNode = &treeNodes[3];
	rootNode->leftNode  = &treeNodes[1];
	rootNode->rightNode = &treeNodes[5];
	
	temporaryNode = tSearch(rootNode, 9);
	if(temporaryNode)
	{
		printf("found at position %d\n", temporaryNode);
	}
	
	else
	{
		printf("value not found\n");
	}
	
	exit(EXIT_SUCCESS);
}

