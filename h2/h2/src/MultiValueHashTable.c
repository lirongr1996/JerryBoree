/*
 * MultiValueHashTable.c
 *
 *  Created on: Dec 1, 2020
 *      Author: ise
 */


#include "MultiValueHashTable.h"

struct multiHashTable_s
{
	int hashNumber;
	hashTable hashList;
	CopyFunction copyKey;
	FreeFunction freeKey;
	EqualFunction equalKey;
	PrintFunction printKey;
	CopyFunction copyValue;
	FreeFunction freeValue;
	PrintFunction printValue;
	CopyFunction copyPair;
	CopyFunction copyHash;
	EqualFunction equalValue;
	PrintFunction printList;
	FreeFunction freeValueInList;
	TransformIntoNumberFunction transformIntoNumber;
};


multiHashTable createMultiValueHashTable(FreeFunction freeValueInList,PrintFunction printList,EqualFunction equalValue,CopyFunction copyHash,CopyFunction copyPair, CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue, EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber)
{
	if (equalValue==NULL || copyKey==NULL || freeKey==NULL || printKey==NULL || copyValue==NULL ||freeValue==NULL ||printValue==NULL ||equalKey==NULL || transformIntoNumber==NULL)
		return NULL;
	if (hashNumber<=0)
		return NULL;
	multiHashTable multi=(multiHashTable)malloc(sizeof(struct multiHashTable_s));
	if (multi==NULL)
	{
		printf("Memory Problem \n");
		return NULL;
	}
	multi->hashList=createHashTable(copyKey, freeKey, printKey, copyHash, freeValue, printValue, equalKey, transformIntoNumber, hashNumber);
	if (multi->hashList==NULL)
		return NULL;
	multi->printList=printList;
	multi->equalValue=equalValue;
	multi->copyHash=copyHash;
	multi->copyPair=copyPair;
	multi->hashNumber=hashNumber;
	multi->copyKey=copyKey;
	multi->copyValue=copyValue;
	multi->equalKey=equalKey;
	multi->freeKey=freeKey;
	multi->freeValue=freeValue;
	multi->printKey=printKey;
	multi->printValue=printValue;
	multi->transformIntoNumber=transformIntoNumber;
	multi->freeValueInList=freeValueInList;
	return multi;
}

void destroyMultiValueHashTable(multiHashTable multi)
{
	if (multi==NULL)
			return;
		if (multi==NULL)
			return;
		destroyHashTable(multi->hashList);
		free(multi);
		return;
}

void addToMultiValueHashTable(multiHashTable multi, Element key, Element value)
{
	if (multi==NULL || key==NULL || value == NULL)
		return;
	int beforeAdd,afterAdd;
	Node n;
	Node node = lookupInMultiValueHashTable(multi, key);
	if(node==NULL)
	{
		n=createLinkedList(multi->freeValueInList,multi->copyPair, multi->printList, multi->equalValue);
		if (n==NULL)
		{
			destroyMultiValueHashTable(multi);
		}
		appendNode(n, value);
		if (getLengthList(n)==0)
			destroyMultiValueHashTable(multi);
		addToHashTable(multi->hashList, key, (Element)&n);
	}
	else
	{
		beforeAdd = getLengthList(node);
		appendNode(node, value);
		afterAdd = getLengthList(node);
		if (beforeAdd == afterAdd)
			destroyMultiValueHashTable(multi);
	}
}

Node lookupInMultiValueHashTable(multiHashTable multi, Element key)
{
	if (multi==NULL || key== NULL)
		return NULL;
	Element elem=lookupInHashTable(multi->hashList, key);
	if (elem==NULL)
		return NULL;
	Pair p=(Pair)elem;
	return (Node)getValue(p);
}

status removeFromMultiValueHashTable (multiHashTable multi, Element key, Element value)
{
	int len=0;
	if (multi==NULL || key==NULL || value == NULL)
		return failure;
	Node node=lookupInMultiValueHashTable(multi, key);
	if (node==NULL)
		return failure;
	len=getLengthList(node);
	if (deleteNode(node, value)==failure)
		return failure;
	if (len==1)
	{
		if(removeFromHashTable(multi->hashList, key)==failure)
			return failure;
	}
	return success;
}

void displayMultiValueHashElementsByKey(multiHashTable multi, Element key)
{
	if (multi==NULL||key==NULL)
		return;
	Node node=lookupInMultiValueHashTable(multi, key);
	multi->printKey(key);
	displayList(node);
}
