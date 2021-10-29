/*
 * Jerry.c
 *
 *  Created on: Nov 13, 2020
 *      Author: ise
 */

#include "Jerry.h"


void planetsDestroy () //destroy all the planets
{
	int i=0;
	if (planets==NULL)
		return;
	for(i=countPlanets-1;i>=0;i--)
			free(planets[i].nameP);
		free(planets);
}
void originsDestroy () //destroy all the origins
{
	int i=0;
	if (origins==NULL)
		return;
	for (i=countOrigins-1;i>=0;i--)
			free(origins[i].nameO);
		free(origins);
}
void characterDestroy() //destroy all the character
{
	free(character);
}


void removeJerry(Jerry j)
{
	if(j.jerryID==NULL)
		return;
	int k=0;
	if (j.numOfChar!=0)
	{
	for (;k<j.numOfChar;k++)
		free(j.jerryChar[k].nameChar);
	free(j.jerryChar);
	}
	free(j.jerryID);
}


void createPlanet (char name [], double x,double y, double z){ //The function create planet
		int i=0;
		if (name==NULL)
		{
			return;
		}
		for (i=0;i<countPlanets;i++) //check if the name is already exist
		{
			if (strcmp(planets[i].nameP,name)==0)
				return;
		}
		Planet p;

		p.nameP=(char *)malloc(sizeof(char)*(strlen(name)+1));
		if (p.nameP==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
		strcpy(p.nameP,name);
		p.x=x;
		p.y=y;
		p.z=z;

		if (planets==NULL)
		{
			planets=(Planet*)malloc(sizeof(Planet));
			if (planets==NULL)
			{
				printf("Memory Problem \n");
				characterDestroy();
				originsDestroy();
				planetsDestroy();
				exit(1);
			}
		}
		else
		{
			planets=(Planet*)realloc(planets,(countPlanets+1)*sizeof(Planet));
			if (planets==NULL)
			{
				printf("Memory Problem \n");
				characterDestroy();
				originsDestroy();
				planetsDestroy();
				exit(1);
			}
		}
		planets[countPlanets]=p;
		countPlanets++;
}


void createPhysicalCharacteristics (char name[],double value) //The function create the physical character
{
	PhysicalCharacteristics c;
	if (name==NULL)
		return;
	c.nameChar=(char *)malloc(sizeof(char)*(strlen(name)+1));
	if (c.nameChar==NULL)
	{
		printf("Memory Problem \n");
		characterDestroy();
		originsDestroy();
		planetsDestroy();
		exit(1);
	}
	strcpy(c.nameChar,name);
	c.valueChar=value;

	if (character==NULL)
	{
		character=(PhysicalCharacteristics*)malloc(sizeof(PhysicalCharacteristics));
		if (character==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	else
	{
		character=(PhysicalCharacteristics*)realloc(character,(countCaracter+1)*sizeof(PhysicalCharacteristics));
		if (character==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	character[countCaracter]=c;
	countCaracter++;
}

void createOrigin (Planet p,char* name) //The function create origin
{
	Origin o;
	if (name==NULL)
		return;
	o.nameO=(char *)malloc(sizeof(char)*(strlen(name)+1));
	if (o.nameO==NULL)
	{
		printf("Memory Problem \n");
		characterDestroy();
		originsDestroy();
		planetsDestroy();
		exit(1);
	}
	strcpy(o.nameO,name);
	o.p=p;

	if (origins==NULL)
	{
		origins=(Origin*)malloc(sizeof(Origin));
		if (origins==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	else
	{
		origins=(Origin*)realloc(origins,(countOrigins+1)*sizeof(Origin));
		if (origins==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	origins[countOrigins]=o;
	countOrigins++;
}

Jerry createJerry (char *ID,int happiness, Origin or) //The function create Jerry
{
	Jerry j;
	j.jerryID=(char *)malloc(sizeof(char)*(strlen(ID)+1));
	if (j.jerryID==NULL)
	{
		printf("Memory Problem \n");
		characterDestroy();
		originsDestroy();
		planetsDestroy();
		exit(1);
	}
	strcpy(j.jerryID,ID);
	j.happiness=happiness;
	j.jerryOrigin=or;
	j.numOfChar=0;

	return j;
}

Jerry addChar (Jerry j, PhysicalCharacteristics c){ //The function add character to Jerry
	if(j.jerryID==NULL)
		return j;
	int i=0;
	Jerry copyJ=createJerry(j.jerryID, j.happiness, j.jerryOrigin);
	copyJ.numOfChar = j.numOfChar;

	if (copyJ.numOfChar==0)
	{
		copyJ.jerryChar=(PhysicalCharacteristics*)malloc(sizeof(PhysicalCharacteristics));
		if (copyJ.jerryChar==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	else
	{
		copyJ.jerryChar=(PhysicalCharacteristics*)malloc(sizeof(PhysicalCharacteristics)*(j.numOfChar));
			if (copyJ.jerryChar==NULL)
				{
					printf("Memory Problem \n");
					characterDestroy();
					originsDestroy();
					planetsDestroy();
					exit(1);
				}
			for (;i<j.numOfChar;i++)
			{
				copyJ.jerryChar[i].valueChar = j.jerryChar[i].valueChar;
				copyJ.jerryChar[i].nameChar=(char*)malloc(sizeof(char)*strlen(j.jerryChar[i].nameChar)+1);
				if (copyJ.jerryChar==NULL)
					{
						printf("Memory Problem \n");
						characterDestroy();
						originsDestroy();
						planetsDestroy();
						exit(1);
					}
				strcpy(copyJ.jerryChar[i].nameChar,j.jerryChar[i].nameChar);

		   }
			copyJ.jerryChar=(PhysicalCharacteristics*)realloc(copyJ.jerryChar,(copyJ.numOfChar+1)*sizeof(PhysicalCharacteristics));
		if (copyJ.jerryChar==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	}
	copyJ.jerryChar[copyJ.numOfChar]=c;
	copyJ.numOfChar++;
	return copyJ;
}


status removeChar (Jerry *j , char* c) //The function remove character from Jerry
{
	int k=0;
	if (c==NULL)
		return failure;

	PhysicalCharacteristics temp;
	for (;k<(*j).numOfChar;k++) //find character in the Jerry
	{
		if (strcmp((*j).jerryChar[k].nameChar,c)==0)
			break;
	}
	if (k==(*j).numOfChar)
		return failure;

	temp=(*j).jerryChar[k];
	free(temp.nameChar);  //destroy the character we want to remove
	for (;k<(*j).numOfChar-1;k++) //move all the character backwards in the array
	{
		(*j).jerryChar[k]=(*j).jerryChar[k+1];
	}
	if ((*j).numOfChar!=1)
	{
		(*j).jerryChar=(PhysicalCharacteristics*)realloc((*j).jerryChar,((*j).numOfChar-1)*sizeof(PhysicalCharacteristics));
	if ((*j).jerryChar==NULL)
	{
		printf("Memory Problem \n");
		characterDestroy();
		originsDestroy();
		planetsDestroy();
		exit(1);
	}

	(*j).numOfChar--;
	}
	else // if the character array is empty, we destroy the array
	{
		(*j).numOfChar=0;
	}
	return success;
}


void printJerry (Jerry j){ //The function print Jerry
	int k=0;
	printf("Jerry , ID - %s : \n",j.jerryID);
	printf("Happiness level : %d \n",j.happiness);
	printf("Origin : %s \n",j.jerryOrigin.nameO);
	printf("Planet : %s (%.2f,%.2f,%.2f) \n",j.jerryOrigin.p.nameP,j.jerryOrigin.p.x,j.jerryOrigin.p.y,j.jerryOrigin.p.z);
	if (j.numOfChar!=0)
	{
		printf("Jerry's physical Characteristics available : \n");
		printf("\t");
		for (;k<j.numOfChar;k++)
		{
			if (k==0)
				printf("%s : %.2f ",j.jerryChar[k].nameChar,j.jerryChar[k].valueChar);
			else
				printf(", %s : %.2f ",j.jerryChar[k].nameChar,j.jerryChar[k].valueChar);
		}
		printf("\n");
	}
}

status printPlanet(Planet p){ //The function print a planet
	int i=0;
	for (;i<countPlanets;i++)
		if (strcmp(planets[i].nameP,p.nameP)==0)
		{
			printf("Planet : %s (%.2f,%.2f,%.2f) \n",p.nameP,p.x,p.y,p.z);
			return success;
		}
	return failure;
}
Jerry CopyOfJerry (Jerry j )
{
	int i=0;
	Jerry copyJ=createJerry(j.jerryID, j.happiness, j.jerryOrigin);
	if(copyJ.jerryID==NULL || j.jerryID==NULL)
		return copyJ;
	copyJ.numOfChar = j.numOfChar;
	if (j.numOfChar==0)
		return copyJ;
	copyJ.jerryChar=(PhysicalCharacteristics*)malloc(sizeof(PhysicalCharacteristics)*(j.numOfChar));
	if (copyJ.jerryChar==NULL)
		{
			printf("Memory Problem \n");
			characterDestroy();
			originsDestroy();
			planetsDestroy();
			exit(1);
		}
	for (;i<j.numOfChar;i++)
	{
		copyJ.jerryChar[i].valueChar = j.jerryChar[i].valueChar;
		copyJ.jerryChar[i].nameChar=(char*)malloc(sizeof(char)*strlen(j.jerryChar[i].nameChar)+1);
		if (copyJ.jerryChar==NULL)
			{
				printf("Memory Problem \n");
				characterDestroy();
				originsDestroy();
				planetsDestroy();
				exit(1);
			}
		strcpy(copyJ.jerryChar[i].nameChar,j.jerryChar[i].nameChar);

   }
	return copyJ;
}
