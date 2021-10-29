/*
 * HashTable.c
 *
 *  Created on: Nov 27, 2020
 *      Author: ise
 */

#include "HashTable.h"
#include "LinkedList.h"
#include "KeyValuePair.h"

struct hashTable_s{
	int hashNumber;
	Node hashList;
	CopyFunction copyKey;
	FreeFunction freeKey;
	EqualFunction equalKey;
	PrintFunction printKey;
	CopyFunction copyValue;
	FreeFunction freeValue;
	PrintFunction printValue;
	TransformIntoNumberFunction transformIntoNumber;
};

static int hash (hashTable hashtable,Element elem)
{
	int i=hashtable[0].transformIntoNumber(elem);
	return i%hashtable->hashNumber;
}

hashTable createHashTable(CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue,
		PrintFunction printValue, EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber)
{
	if (copyKey==NULL || freeKey==NULL || printKey==NULL || copyValue==NULL ||freeValue==NULL ||printValue==NULL ||equalKey==NULL || transformIntoNumber==NULL)
		return NULL;
	int i;
	if (hashNumber<=0)
		return NULL;
	hashTable hashtable=(hashTable)malloc(sizeof(struct hashTable_s)*hashNumber);
	if (hashtable==NULL)
	{
		printf("Memory Problem \n");
		return NULL;
	}

	for(i=0;i<hashNumber;i++)
	{
	hashtable[i].hashList=createLinkedList(freeValue, copyValue, printValue, equalKey);
	if (hashtable[i].hashList==NULL)
	   destroyHashTable(hashtable);
	hashtable[i].hashNumber=hashNumber;
	hashtable[i].copyKey=copyKey;
	hashtable[i].copyValue=copyValue;
	hashtable[i].equalKey=equalKey;
	hashtable[i].freeKey=freeKey;
	hashtable[i].freeValue=freeValue;
	hashtable[i].printKey=printKey;
	hashtable[i].printValue=printValue;
	hashtable[i].transformIntoNumber=transformIntoNumber;
	}
	return hashtable;
}

status destroyHashTable(hashTable hashtable)
{
	if (hashtable==NULL)
		return failure;
	int i=0;
	for (;i<hashtable->hashNumber;i++)
	{
		destroyList(hashtable[i].hashList);
	}
	free(hashtable);
	return success;
}


status addToHashTable(hashTable hashtable, Element key,Element value)
{
	if (hashtable==NULL || key==NULL || value==NULL)
			return failure;
	int i=hash(hashtable, key);
	Pair p=createKeyValuePair(hashtable[i].copyKey(key), hashtable[i].copyValue(value), hashtable[i].copyKey, hashtable[i].freeKey, hashtable[i].printKey, hashtable[i].copyValue, hashtable[i].freeValue, hashtable[i].printValue, hashtable[i].equalKey);
	if (p==NULL)
	{
		destroyHashTable(hashtable);
		return failure;
	}

	appendNode(hashtable[i].hashList, (Element)&p);
	return success;
}

Element lookupInHashTable(hashTable hashtable, Element key)
{
	if (hashtable ==NULL || key==NULL)
		return NULL;
	int i=hash(hashtable, key);
	if (getLengthList(hashtable[i].hashList)==0)
		return NULL;
	return searchByKeyInList(hashtable[i].hashList, key);
}

status removeFromHashTable(hashTable hashtable, Element key)
{
	if (hashtable ==NULL || key==NULL)
			return failure;
	int i=hash(hashtable, key);
	Element elem=searchByKeyInList(hashtable[i].hashList, key);
	return deleteNode(hashtable[i].hashList, key);
}


status displayHashElements(hashTable hashtable)
{
	if (hashtable ==NULL)
		return failure;
	int i=0;
	for (;i<hashtable[i].hashNumber;i++)
	{
		if (getLengthList(hashtable[i].hashList)!=0)
			displayList(hashtable[i].hashList);
	}
	return success;
}
