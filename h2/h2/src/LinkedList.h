/*
 * LinkedList.h
 *
 *  Created on: Nov 27, 2020
 *      Author: ise
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "Defs.h"

typedef struct Node_t* Node;


Node createLinkedList(FreeFunction freeDelete ,CopyFunction copyFunction, PrintFunction printFunction, EqualFunction equalFunction);

void destroyList (Node node);

void appendNode (Node node, Element elem);

status deleteNode (Node node, Element elem);

void displayList (Node node);

Element getDataByIndex (Node node, int index);

int getLengthList (Node node);

Element searchByKeyInList (Node node, Element elem);
Node getLastNode (Node node);

void addToExictedNode (Node node,Element elem);

Element getDataByNode (Node node);
Node getNodeByIndex (Node node, int index);

#endif /* LINKEDLIST_H_ */

