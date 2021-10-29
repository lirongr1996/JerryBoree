/*
 * KeyValuePair.c
 *
 *  Created on: Nov 27, 2020
 *      Author: ise
 */


#include "KeyValuePair.h"

struct keyAndValue{
	Element key;
	Element value;
	CopyFunction copyKey;
	FreeFunction freeKey;
	EqualFunction equalKey;
	PrintFunction printKey;
	CopyFunction copyValue;
	FreeFunction freeValue;
	PrintFunction printValue;
};


Pair createKeyValuePair (Element key, Element value,CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue,
		PrintFunction printValue, EqualFunction equalKey)
{
	if (key == NULL || value== NULL ||copyKey==NULL || freeKey==NULL || printKey==NULL || copyValue==NULL ||freeValue==NULL ||printValue==NULL ||equalKey==NULL)
		return NULL;
	Pair pair=(Pair)malloc(sizeof(struct keyAndValue));
	if (pair ==NULL)
	{
		printf("Memory Problem \n");
		return NULL;
	}

	pair->key=key;
	pair->value=value;
	pair->copyKey=copyKey;
	pair->copyValue=copyValue;
	pair->equalKey=equalKey;
	pair->freeKey=freeKey;
	pair->freeValue=freeValue;
	pair->printKey=printKey;
	pair->printValue=printValue;

	return pair;
}

void destroyKeyValuePair(Pair pair)
{
	if (pair ==NULL)
		return;
	pair->freeKey(pair->key);
	free(pair);
}

void displayValue(Pair pair)
{
	if (pair ==NULL)
			return;
	pair->printValue(pair->value);
}

void displayKey (Pair pair)
{
	if (pair ==NULL)
			return;
	pair->printKey(pair->key);
}

Element getValue (Pair pair)
{
	if (pair ==NULL)
			return NULL;
	return pair->value;
}

Element getKey (Pair pair)
{
	if (pair ==NULL)
			return NULL;
	return pair->key;
}

bool isEqualKey (Pair pair, Element key)
{
	if (pair ==NULL || key==NULL)
			return false;
	if (pair->equalKey(pair->key,key)==true)
		return true;
	return false;
}
