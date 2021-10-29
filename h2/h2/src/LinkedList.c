/*
 * LinkedList.c
 *
 *  Created on: Nov 27, 2020
 *      Author: ise
 */

#include "LinkedList.h"

struct Node_t{
	Element value;
	struct Node_t *next;
	CopyFunction CopyFunction;
	FreeFunction freeNode;
	EqualFunction EqualFunction;
	PrintFunction PrintFunction;
};

Node createLinkedList(FreeFunction freeNode ,CopyFunction copyFunction,
		PrintFunction printFunction, EqualFunction equalFunction)
{
	if (freeNode==NULL || copyFunction==NULL || printFunction==NULL || equalFunction==NULL)
		return NULL;
	Node node=(Node)malloc(sizeof(struct Node_t));
	if (node == NULL)
	{
		printf("Memory Problem \n");
		return NULL;
	}
	node->next=NULL;
	node->value=NULL;
	node->EqualFunction=equalFunction;
	node->CopyFunction=copyFunction;
	node->freeNode=freeNode;
	node->PrintFunction=printFunction;
	return node;
}

void destroyList (Node node)
{
	if (node==NULL)
		return;
	Node n=node->next;
	Node temp;
	if (node->next==NULL)
	{
		free(node);
		return;
	}
	while (n!=NULL)
	{
		temp=n->next;
		n->freeNode(n->value);
		free(n);
		n=temp;
	}
	free(node);
}

void appendNode (Node node, Element elem)
{
	if (node==NULL || elem ==NULL)
		return;
	Node newNode;



//	if (getLengthList(node)==0 || node->value==NULL)
//	{
//		node->value=node->CopyFunction(elem);
//		node->next=NULL;
//	}
//	else
//	{
		newNode=createLinkedList (node->freeNode,node->CopyFunction, node->PrintFunction, node->EqualFunction);
		if(newNode==NULL)
			return;
		newNode->value=node->CopyFunction(elem);
		newNode->next=NULL;
		Node n=node;
		while (n->next!=NULL)
			n=n->next;
		n->next=newNode;
	//}
}

status deleteNode (Node node, Element elem)
{
	if (node==NULL || elem ==NULL)
			return failure;
	Node n=node->next;
	Node temp=node->next;
	if (temp->EqualFunction(temp->value,elem)==true)
	{
		if (getLengthList(node)>1)
		{
			(temp)->freeNode((temp)->value);
			node->next->value=node->next->next->value;
			temp=node->next;
			node->next=node->next->next;
			free(temp);
		}
		else
		{
			node->next->freeNode(node->next->value);
			//free(temp);
			node->next->value=NULL;
			node->next->next=NULL;
		}
		return success;
	}
	while (n!=NULL)
	{
		if (n->EqualFunction(n->next->value,elem)==true)
			break;
		n=n->next;
	}
	if (n==NULL)
		return failure;
	(temp)=n->next;
	n->next=n->next->next;
	(temp)->freeNode((temp)->value);
	free(temp);
	return success;
}

void displayList (Node node)
{
	if (node==NULL)
			return;
	Node n=node->next;
	if (getLengthList(n)==1)
		n->PrintFunction(n->value);
	else
	{
		while (n!=NULL)
		{
			n->PrintFunction(n->value);
			n=n->next;
		}
	}
}

Element getDataByIndex (Node node, int index)
{
	if (node==NULL)
		return NULL;
	int i=1;
	if (getLengthList(node)<index || index<1)
		return NULL;
	Node n=node->next;
	while (i!=index)
	{
		i++;
		n=n->next;
	}
	return n->value;
}

int getLengthList (Node node)
{
	if (node==NULL)
		return 0;
	Node n=node->next;
	if (n==NULL)
		return 0;
	int count=1;
	while (n->next!=NULL)
	{
		n=n->next;
		count++;
	}
	return count;
}

Element searchByKeyInList (Node node, Element elem)
{
	if (node==NULL || elem==NULL)
			return NULL;
	Node n=node->next;
	while (n!=NULL)
	{
		if (n->EqualFunction(n->value,elem)==true)
			return n->value;
		n=n->next;
	}
	return NULL;
}
Node getLastNode (Node node)
{
	if (node==NULL)
	  return NULL;
	Node temp = node->next;
	if (temp->value ==NULL)
		return NULL;
	while (temp->next !=NULL)
	{
		temp = temp->next;
	}
	return temp;
}
void addToExictedNode (Node node,Element elem)
{
    if (node==NULL || elem ==NULL)
		return;
	Node newNode=node->next;
	if (node->next->EqualFunction(node->next->value,elem)==true)
	{
		node->next->freeNode(node->next->value);
		node->next->value=node->next->CopyFunction(elem);
		return;
	}

	else
	{

	newNode=newNode->next;
	while (newNode->EqualFunction(newNode->value,elem)!=true)
		newNode=newNode->next;
	newNode->freeNode(newNode->value);
	newNode->value=node->next->CopyFunction(elem);

    }
}

Element getDataByNode (Node node)
{
	return node->value;
}



Node getNodeByIndex (Node node, int index)
{
	if (node==NULL)
		return NULL;
	int i=1;
	if (getLengthList(node)<index || index<1)
		return NULL;
	Node n=node->next;
	while (i!=index)
	{
		i++;
		n=n->next;
	}
	return n;
}
