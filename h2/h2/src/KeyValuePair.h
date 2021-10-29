/*
 * KeyValuePair.h
 *
 *  Created on: Nov 27, 2020
 *      Author: ise
 */

#ifndef KEYVALUEPAIR_H_
#define KEYVALUEPAIR_H_

#include <stdio.h>
#include <stdlib.h>

#include "Defs.h"

typedef struct keyAndValue* Pair;

Pair createKeyValuePair (Element key, Element value,CopyFunction copyKey, FreeFunction freeKey,
		PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue,
		PrintFunction printValue, EqualFunction equalKey);

void destroyKeyValuePair(Pair pair);

void displayValue(Pair pair);

void displayKey (Pair pair);

Element getValue (Pair pair);

Element getKey (Pair pair);

bool isEqualKey (Pair pair, Element key);



#endif /* KEYVALUEPAIR_H_ */
