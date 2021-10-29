/*
 ============================================================================
 Name        : h2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Jerry.h"
#include "HashTable.h"
#include "MultiValueHashTable.h"
#include "LinkedList.h"
#include "KeyValuePair.h"
#include "Defs.h"


Element copyJerry (Element elem)
{
		if (elem==NULL)
			return NULL;
		Jerry *j=(Jerry*)malloc(sizeof(Jerry));
		char *c = (char*)malloc(sizeof(char)*(strlen((*(Jerry*)elem).jerryID)+1));
		if (j==NULL || c==NULL)
			return NULL;
		strcpy(c, (*(Jerry*)elem).jerryID);
		(*j).happiness=(*(Jerry*)elem).happiness;
		(*j).jerryID=c;
		(*j).jerryOrigin=(*(Jerry*)elem).jerryOrigin;
		(*j).numOfChar=(*(Jerry*)elem).numOfChar;
		(*j).jerryChar=(*(Jerry*)elem).jerryChar;


		if (j==NULL)
			return NULL;
		return j;
}

status freeJerryID (Element elem)
{
	if (elem==NULL)
		return failure;
	free((char**)elem);
	return success;
}

status freeJerry (Element elem)
{
	if (elem==NULL)
		return failure;
	Jerry *j=(Jerry*)elem;
	removeJerry(*j);
	free(j);
	return success;
}

status freePair (Element elem)
{
	if (elem==NULL)
		return failure;
	Pair p=(Pair)elem;
	destroyList((Node)getValue(p));
	destroyKeyValuePair(p);
	return success;
}

status printJerryID (Element elem)
{
	if (elem==NULL)
		return failure;
	printf("%s ",(char*)elem);
	return success;
}
status printJerryFromHash (Element elem)
{
	if (elem==NULL)
			return failure;
		Pair p=(Pair)elem;
		Jerry *j;
		Node n =(Node)getValue(p);
		j = (Jerry*)getDataByNode(n);
		if (j==NULL)
			return failure;
		printJerry(*j);
		return success;
}

int TransformIntoNumberFunctionChar(Element elem)
{
	if (elem==NULL)
		return 0;
	int sum=0;
	char *id=*(char**)elem;
	if (id==NULL)
			return 0;
	char *w=id;
	while ((*w)!='\0')
	{
		sum+=*w;
		w+=1;
	}
	//free(id);
	return sum;
}


Element copyChar (Element elem)
{
	if (elem==NULL)
		return NULL;
	char *c=(char*)malloc(sizeof(char)*(strlen(*(char**)elem)+1));
	if (c==NULL)
			return NULL;
	char *h=*(char**)elem;
	strcpy(c,h);
	if (c==NULL)
		return NULL;
	return c;
}

status printChar (Element elem)
{

	char* c=*(char**)elem;
	printf("%s : \n",c);
	return success;
}

bool equalChar(Element elem1, Element elem2)
{
	if (elem1==NULL ||elem2==NULL)
		return false;
	Pair p=(Pair)elem1;
	char *c1=(char*)getKey(p);
	char *c2=*(char**)elem2;
	if (c1==NULL ||c2==NULL)
			return false;
	if(strcmp(c1,c2)==0)
	{
		return true;
	}
	return false;
}

bool equalValue (Element elem1,Element elem2)
{
	if (elem1==NULL ||elem2==NULL)
		return false;

	Node n1=(Node)elem1;
	Jerry j1=*(Jerry*)getDataByNode(n1);
	Jerry j2=*(Jerry*)elem2;
	if(strcmp(j1.jerryID,j2.jerryID)==0)
	{
		return true;
	}
	return false;

}

Element copyList (Element elem)
{
	if (elem==NULL)
		return NULL;
	Jerry *j;
	Element e=getDataByIndex((Node)elem, 1);
	j=(Jerry*)e;
	if (j==NULL)
		return NULL;
	return j;
}

Element copyNode (Element elem)
{
	if (elem==NULL)
		return NULL;
	Node *n;
	n=(Node*)elem;
	if (n==NULL)
	   return NULL;
	return (*n);
}



status freeNode (Element elem)
{
	if (elem==NULL)
		return failure;
	Pair p = (Pair)elem;
	destroyKeyValuePair(p);
	return success;
}
status freeNodeInMulti (Element elem)
{
	if (elem==NULL)
		return failure;
	return success;
}


status printNode (Element elem)
{
	if (elem==NULL)
		return failure;
	Pair p=((Pair)elem);
	Jerry *j=(Jerry*)malloc(sizeof(Jerry));
	if (j==NULL)
		return failure;
	Node n=(Node)getValue(p);
	int count=1;
	while (count<=getLengthList(n))
	{
		(*j).jerryID=(*(Jerry*)getDataByIndex(n, count)).jerryID;
		printJerry(*j);
		count++;
	}


	free(j);
	return success;
}

status printJerryFromMulti(Element elem)
{
	if (elem==NULL)
		return failure;
	Node n=(Node)elem;
	printJerry(*(Jerry*)getDataByNode(n));
	return success;
}

status printJerryFromList(Element elem)
{
	if (elem==NULL)
		return failure;
	printJerry(*(Jerry*)elem);
	return success;
}


Element copyPointerToJerry (Element elem)
{
	Node p = *(Node*)elem;
	return p;
}

bool equalJerry(Element elem1, Element elem2)
{
	if (elem1==NULL ||elem2==NULL)
		return false;
	Jerry t1=*(Jerry*)elem1;
	Jerry t2=*(Jerry*)elem2;
	if(strcmp(t1.jerryID,t2.jerryID)==0)
	{
		return true;
	}
	return false;
}

int primeNumber(int num)
{
	int counter;
	int q=2,x=num;
	int prime=0;
	while(!prime)
	{
		q=2;
		counter=0;
		while (q < x / 2)
		{
			if (x%q == 0)
				counter++;
			q++;
		}
			if (counter == 0)
			{
				prime=1;
				break;
			}
		x++;
	}
	return x;
}



int main(int argc, char *argv[]) {
	int c=0;
	int numOfPlanets, ok=0, j=0,i=0,k=0,v=0,happiness=0,count=0,len=0;
	char p[300],xc[300],yc[300],zc[300],ID[300],or[300],happy[300],ch[300],val[300],plan[300];
	char nameAnswer[301], characterAnswer[301], namePlanet[301],choise[300], choise2[300],*id ,*chName;
	double xp=0,yp=0,zp=0,valu=0,valueAnswer=0;
	Element elem1,elem2;
	hashTable JerriesHashTable;
	multiHashTable multiHash;
	FILE * file=fopen(argv[2],"r"); //read the file
	sscanf (argv[1],"%d",&numOfPlanets);


	countCaracter=0;
	countOrigins=0;
	countPlanets=0;

	Node JerryList = createLinkedList(freeJerry, copyJerry, printJerryFromList, equalJerry);
	if (JerryList==NULL)
		exit(1);

	if (file==NULL)
			printf("can't open the file");
		else
		{
			ok=fscanf(file,"%100[^\n]%*c",p);
			for (;j<numOfPlanets;j++) //read the plantes from the file and create them
			{
				ok=fscanf(file,"%300[^,]%*c%300[^,]%*c%300[^,]%*c%300[^\n]%*c",p,xc,yc,zc);
				sscanf(xc,"%lf",&xp);
				sscanf(yc,"%lf",&yp);
				sscanf(zc,"%lf",&zp);
				createPlanet(p, xp, yp, zp);
			}


			ok=fscanf(file,"%300[^\n]%*c",p);
			ok=fscanf(file,"%300[^\n]%*c",p);
			j=0;
			while(ok!=-1)//read the Jerries from the file and create them
			{
				k=0;
				while(p[k]!=',')
				{
					ID[k]=p[k];
					k++;
				}
				ID[k]='\0';
				v=0;
				k++;
				while(p[k]!=',')
				{
					or[v]=p[k];
					k++;
					v++;
				}
				or[v]='\0';
				v=0;
				k++;
				while(p[k]!=',')
				{
					plan[v]=p[k];
					k++;
					v++;
				}
				plan[v]='\0';
				v=0;
				k++;
				while(p[k]!='\0')
				{
					happy[v]=p[k];
					k++;
					v++;
				}
				happy[v]='\0';
				sscanf(happy,"%d",&happiness);
				for (i=0;i<countPlanets;i++) //find the planet to create an origin to Jerry
					if(strcmp(planets[i].nameP,plan)==0)
						break;
				createOrigin(planets[i], or);
				Jerry jerry=createJerry(ID, happiness, origins[countOrigins-1]);
				appendNode(JerryList, (Element)&jerry);
				removeJerry(jerry);
				Node pointer = getLastNode(JerryList);

				count++;
				ok=fscanf(file,"%300[^\n]%*c",p);
				if (count==getLengthList(JerryList))
				{
				while(ok==1 && p[0]=='\t') //create createPhysical Character
				{
					k=1;
					v=0;
					while(p[k]!=':')
					{
						ch[v]=p[k];
						k++;
						v++;
					}
					ch[v]='\0';
					k++;
					v=0;
					while(p[k]!='\0')
					{
						val[v]=p[k];
						v++;
						k++;
					}
					val[v]='\0';
					sscanf(val,"%lf",&valu);
					createPhysicalCharacteristics(ch, valu);
					Jerry newJ=addChar(*(Jerry*)(getDataByNode(pointer)), character[countCaracter-1]);
					addToExictedNode(JerryList,(Element)&newJ);
					free(newJ.jerryID);
					ok=fscanf(file,"%300[^\n]%*c",p);
					}
				}
				else{
					while(ok==1 && p[0]=='\t')
					{
						ok=fscanf(file,"%300[^\n]%*c",p);
					}
					count--;
				}
				j++;
			}
		}

	fclose(file);

	len=getLengthList(JerryList);
	JerriesHashTable=createHashTable(copyChar, freeJerryID, printJerryID, copyPointerToJerry, freeNode, printJerryFromHash, equalChar, TransformIntoNumberFunctionChar,primeNumber(len));
	if (JerriesHashTable==NULL)
		exit(1);

	multiHash=createMultiValueHashTable(freeNodeInMulti,printJerryFromMulti,equalValue,copyNode,copyPointerToJerry, copyChar, freeJerryID, printChar, copyList, freePair, printNode, equalChar, TransformIntoNumberFunctionChar, primeNumber(countCaracter));
	if (multiHash==NULL)
		exit(1);

	c=1;
	Node findNode;
	Jerry findJer;
	while(c<=len)
	{
		findNode=getNodeByIndex(JerryList, c);
		findJer=*((Jerry*)getDataByNode(findNode));
		addToHashTable(JerriesHashTable, (Element)&findJer.jerryID, (Element)&findNode);
		for(k=0;k<findJer.numOfChar;k++)
		{
			addToMultiValueHashTable(multiHash, (Element)&findJer.jerryChar[k].nameChar, (Element)&findNode);
		}
		c++;
	}


	do
	{
		printf("Welcome Rick, what are your Jerry's needs today ? \n");
		printf("1 : Take this Jerry away from me \n");
		printf("2 : I think I remember something about my Jerry \n");
		printf("3 : Oh wait. That can't be right \n");
		printf("4 : I guess I will take back my Jerry now \n");
		printf("5 : I can't find my Jerry. Just give me a similar one \n");
		printf("6 : I lost a bet. Give me your saddest Jerry \n");
		printf("7 : Show me what you got \n");
		printf("8 : Let the Jerries play \n");
		printf("9 : I had enough. Close this place \n");
		gets(choise);
		if (choise[1]=='\0')
			c=choise[0];
		else
			c=0;
		switch(c)
		{
		case 49: //case 1
			printf("What is your Jerry's ID ? \n");
			gets(ID);
			id=(char*)malloc(sizeof(char)*(strlen(ID)+1));
			strcpy(id,ID);
			if (lookupInHashTable(JerriesHashTable, (Element)&id)==NULL)
			{
				printf("What planet is your Jerry from ? \n");
				gets(plan);
				for (i=0;i<countPlanets;i++)
					if (strcmp(plan,planets[i].nameP)==0)
						break;
				if (i==countPlanets)
				{
					printf("%s is not a known planet ! \n",plan);
				}
				else
				{
					printf("What is your Jerry's dimension ? \n");
					gets(or);
					printf("How happy is your Jerry now ? \n");
					gets(happy);
					sscanf(happy,"%d",&happiness);
					createOrigin(planets[i], or);
					Jerry jerry=createJerry(ID, happiness, origins[countOrigins-1]);
					appendNode(JerryList, (Element)&jerry);
					printJerry(jerry);
					removeJerry(jerry);
					Node pointer = getLastNode(JerryList);
					addToHashTable(JerriesHashTable, (Element)&id, (Element)&pointer);

				}
			}
			else
				printf("Rick did you forgot ? you already left him here ! \n");
			free(id);
			break;
		case 50: //case 2
			printf ("What is your Jerry's ID ? \n");
			gets(ID);
			id=(char*)malloc(sizeof(char)*(strlen(ID)+1));
			strcpy(id,ID);
			elem1=lookupInHashTable(JerriesHashTable, (Element)&id);
			if (elem1==NULL)
			{
				printf("Rick this Jerry is not in the daycare ! \n");
			}
			else
			{
				printf("What physical characteristic can you add to Jerry - %s ? \n",ID);
				gets(ch);
				chName=(char*)malloc(sizeof(char)*(strlen(ch)+1));
				strcpy(chName,ch);
				Pair jerryP=(Pair)elem1;
				Node jerryN=(Node)getValue(jerryP);
				Jerry jer=*(Jerry*)getDataByNode(jerryN);
				for (j=0;j<jer.numOfChar;j++)
					if (strcmp(ch,jer.jerryChar[j].nameChar)==0)
						break;
				if (j==jer.numOfChar)
				{
					printf("What is the value of his %s ? \n",ch);
					gets(val);
					sscanf(val,"%lf",&valu);
					createPhysicalCharacteristics(ch, valu);
					Jerry newJ=addChar(jer, character[countCaracter-1]);
					addToExictedNode(JerryList,(Element)&newJ);
					free(newJ.jerryID);
					addToMultiValueHashTable(multiHash, (Element)&chName, (Element)&jerryN);
					displayMultiValueHashElementsByKey(multiHash, (Element)&chName);
				}
				else
				{
					printf("The information about his %s already available to the daycare ! \n",ch);
				}
				free(chName);
			}
			free(id);
			break;
		case 51: //case 3
			printf ("What is your Jerry's ID ? \n");
			gets(ID);
			id=(char*)malloc(sizeof(char)*(strlen(ID)+1));
			strcpy(id,ID);
			elem1=lookupInHashTable(JerriesHashTable, (Element)&id);
			if (elem1==NULL)
				printf("Rick this Jerry is not in the daycare ! \n");
			else
			{
				printf("What physical characteristic do you want to remove from Jerry - %s ? \n",ID);
				gets(ch);
				chName=(char*)malloc(sizeof(char)*(strlen(ch)+1));
				strcpy(chName,ch);
				Pair jerryP=(Pair)elem1;
				Node jerryN=(Node)getValue(jerryP);
				Jerry jer=*(Jerry*)getDataByNode(jerryN);
				for (j=0;j<jer.numOfChar;j++)
					if (strcmp(ch,jer.jerryChar[j].nameChar)==0)
						break;
				if (j==jer.numOfChar)
				{
					printf("The information about his %s not available to the daycare ! \n",ch);
				}
				else
				{
					removeFromMultiValueHashTable(multiHash, (Element)&chName, (Element)&jer);
					jer=CopyOfJerry(jer);
					removeChar(&jer, ch);
					addToExictedNode(JerryList,(Element)&jer);
					printJerry(jer);
					free(jer.jerryID);
				}
				free(chName);
			}
			free(id);
			break;
		case 52: //case 4
			printf("What is your Jerry's ID ? \n");
			gets(ID);
			id=(char*)malloc(sizeof(char)*(strlen(ID)+1));
			strcpy(id,ID);
			elem1=lookupInHashTable(JerriesHashTable, (Element)&id);
			if (elem1==NULL)
				printf("Rick this Jerry is not in the daycare ! \n");
			else
			{
				Pair jerryP=(Pair)elem1;
				Node jerryN=(Node)getValue(jerryP);
				Jerry jer=*(Jerry*)getDataByNode(jerryN);
				status s1;
				for (j=0;j<jer.numOfChar;j++)
					s1=removeFromMultiValueHashTable(multiHash, (Element)&jer.jerryChar[j].nameChar, (Element)&jer);
				status s2=removeFromHashTable(JerriesHashTable, (Element)&jer.jerryID);
				deleteNode(JerryList, (Element)&jer);
				if (s1==success && s2 == success)
					printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
			}
			free(id);
			break;
		case 53: //case 5
			printf("What do you remember about your Jerry ? \n");
			gets(ch);
			chName=(char*)malloc(sizeof(char)*(strlen(ch)+1));
			strcpy(chName,ch);
			int min;
			Jerry foundJerry;
			Node nList=lookupInMultiValueHashTable(multiHash, (Element)&chName);
			if (nList==NULL)
				printf("Rick we can not help you - we do not know any Jerry's %s ! \n", ch);
			else
			{
				printf("What do you remember about the value of his %s ? \n",ch);
				gets(val);
				sscanf(val,"%lf",&valu);
				count=1;
				Node jerryN=getDataByIndex(nList, count);
				Jerry jer=*(Jerry*)getDataByNode(jerryN);
				for (j=0;j<jer.numOfChar;j++)
						if (strcmp(ch,jer.jerryChar[j].nameChar)==0)
						{
							min=abs(jer.jerryChar[j].valueChar-valu);
							foundJerry=jer;
							break;
						}
				count++;
				while (count<=getLengthList(nList))
				{
					jerryN=getDataByIndex(nList, count);
					jer=*(Jerry*)getDataByNode(jerryN);
					for (j=0;j<jer.numOfChar;j++)
						if (strcmp(ch,jer.jerryChar[j].nameChar)==0)
						{
							if (abs(jer.jerryChar[j].valueChar-valu)<min)
							{
								min=abs(jer.jerryChar[j].valueChar-valu);
								foundJerry=jer;
							}
							break;
						}
					count++;
				}
				printf("Rick this is the most suitable Jerry we found : \n");
				printJerry(foundJerry);
				status s1=success;
				for (j=0;j<jer.numOfChar;j++)
					s1=removeFromMultiValueHashTable(multiHash, (Element)&foundJerry.jerryChar[j].nameChar, (Element)&foundJerry);
				status s2=removeFromHashTable(JerriesHashTable, (Element)&foundJerry.jerryID);
				deleteNode(JerryList, (Element)&foundJerry);
				if (s1==success && s2 == success)
					printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
			}
			free(chName);
			break;
		case 54: //case 6
			len=getLengthList(JerryList);
			if (len==0)
				printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
			else
			{
				Jerry jer=*(Jerry*)getDataByIndex(JerryList, 1);
				int saddest=jer.happiness;
				Jerry foundJerry=jer;
				for (i=2;i<=len;i++)
				{
					jer=*(Jerry*)getDataByIndex(JerryList, i);

					if(jer.happiness<saddest)
					{
						saddest=jer.happiness;
						foundJerry=jer;
					}
				}
				printf("Rick this is the most suitable Jerry we found : \n");
				printJerry(foundJerry);

				status s1=success;
				for (j=0;j<foundJerry.numOfChar;j++)
					s1=removeFromMultiValueHashTable(multiHash, (Element)&foundJerry.jerryChar[j].nameChar, (Element)&foundJerry);

				status s2=removeFromHashTable(JerriesHashTable, (Element)&foundJerry.jerryID);
				deleteNode(JerryList, (Element)&foundJerry);
				if (s1==success && s2 == success)
					printf("Rick thank you for using our daycare service ! Your Jerry awaits ! \n");
			}
			break;
		case 55://case 7
			printf("What information do you want to know ? \n");
			printf("1 : All Jerries \n");
			printf("2 : All Jerries by physical characteristics \n");
			printf("3 : All known planets \n");
			gets(choise2);
			if (choise2[1]=='\0')
				k=choise2[0];
			else
				k=0;
			switch (k)
			{
			case 49: //print all the jerries
				len=getLengthList(JerryList);
				if (len==0)
					printf ("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
				else
					displayList(JerryList);
				break;
			case 50: //All Jerries by physical characteristics
					printf("What physical characteristics ? \n");
					gets(ch);
					chName=(char*)malloc(sizeof(char)*(strlen(ch)+1));
					strcpy(chName,ch);
					Node n=lookupInMultiValueHashTable(multiHash, (Element)&chName);
					if(n==NULL)
						printf("Rick we can not help you - we do not know any Jerry's %s ! \n",ch);
					else
					{
						displayMultiValueHashElementsByKey(multiHash, (Element)&chName);
					}
					free(chName);
				break;
			case 51://All known planets
				for (i=0;i<countPlanets;i++)
					printPlanet(planets[i]);
				break;
			default:
				printf("Rick this option is not known to the daycare! \n");
			}
			break;
		case 56: //case 8
			printf("What activity do you want the Jerries to partake in ? \n");
			printf("1 : Interact with fake Beth \n");
			printf("2 : Play golf \n");
			printf("3 : Adjust the picture settings on the TV \n");
			if(count==0)
				printf("Rick we can not help you - we currently have no Jerries in the daycare ! \n");
			else
			{
				gets(choise2);
				if (choise2[1]=='\0')
					k=choise2[0];
				else
					k=0;
				len=getLengthList(JerryList);
				Jerry jer;
				switch (k)
				{
				case 49:// Interact with fake Beth
					for (i=1;i<=len;i++)
					{
						jer=*(Jerry*)getDataByIndex(JerryList, i);
						if(jer.happiness>=20)
						{
							jer.happiness+=15;
							if (jer.happiness>100)
								jer.happiness=100;
						}
						else
						{
							jer.happiness-=5;
							if (jer.happiness<0)
								jer.happiness=0;
						}
						jer=CopyOfJerry(jer);
						addToExictedNode(JerryList, (Element)&jer);
						free(jer.jerryID);
					}
					printf("The activity is now over ! \n");
					displayList(JerryList);
					break;
				case 50:// Play golf
					for (i=1;i<=len;i++)
					{
						jer=*(Jerry*)getDataByIndex(JerryList, i);
						if(jer.happiness>=50)
						{
							jer.happiness+=10;
							if (jer.happiness>100)
								jer.happiness=100;
						}
						else
						{
							jer.happiness-=10;
							if (jer.happiness<0)
								jer.happiness=0;
						}
						jer=CopyOfJerry(jer);
						addToExictedNode(JerryList, (Element)&jer);
						free(jer.jerryID);
					}
					printf("The activity is now over ! \n");
					displayList(JerryList);
					break;
				case 51: //Adjust the picture settings on the TV
					for (i=1;i<=len;i++)
					{
						jer=*(Jerry*)getDataByIndex(JerryList, i);
						jer.happiness+=20;
						if (jer.happiness>100)
							jer.happiness=100;
						jer=CopyOfJerry(jer);
						addToExictedNode(JerryList, (Element)&jer);
						free(jer.jerryID);
					}
					printf("The activity is now over ! \n");
					displayList(JerryList);
					break;
				default:
					printf("Rick this option is not known to the daycare ! \n");
				}
			}
			break;
		case 57://case 9
			destroyMultiValueHashTable(multiHash);
			destroyHashTable(JerriesHashTable);
			destroyList(JerryList);
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			printf("The daycare is now clean and close !");
			break;
		default:
			printf("Rick this option is not known to the daycare ! \n");
		}

	}while(c!=57);




	return EXIT_SUCCESS;
}
