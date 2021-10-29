/*
 * MultiValueHashTable.h
 *
 *  Created on: Dec 1, 2020
 *      Author: ise
 */

#ifndef MULTIVALUEHASHTABLE_H_
#define MULTIVALUEHASHTABLE_H_

#include "LinkedList.h"
#include "KeyValuePair.h"
#include "HashTable.h"

typedef struct multiHashTable_s *multiHashTable;

multiHashTable createMultiValueHashTable(FreeFunction freeValueInList, PrintFunction printList, EqualFunction equalValue,CopyFunction copyHash,CopyFunction copyPair,CopyFunction copyKey, FreeFunction freeKey, PrintFunction printKey, CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue, EqualFunction equalKey, TransformIntoNumberFunction transformIntoNumber, int hashNumber);
void destroyMultiValueHashTable(multiHashTable multi);
void addToMultiValueHashTable(multiHashTable multi, Element key, Element value);
Node lookupInMultiValueHashTable(multiHashTable multi, Element key);
status removeFromMultiValueHashTable (multiHashTable multi, Element key, Element value);
void displayMultiValueHashElementsByKey(multiHashTable multi, Element key);


#endif /* MULTIVALUEHASHTABLE_H_ */
