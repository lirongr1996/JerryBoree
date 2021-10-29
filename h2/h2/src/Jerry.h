#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "Defs.h"

typedef struct Planet_t{
	char *nameP;
	double x,y,z;
} Planet;

typedef struct Origin_t{
	Planet p;
	char *nameO;
} Origin;

typedef struct PhysicalCharacteristics_t{
	char *nameChar;
	double valueChar;
}PhysicalCharacteristics;

typedef struct Jerry_t{
	char *jerryID;
	int happiness;
	Origin jerryOrigin;
	PhysicalCharacteristics *jerryChar;
	int numOfChar;
}Jerry;


Jerry createJerry (char *ID,int happiness, Origin or);

void createPlanet (char name [], double x,double y, double z);

void createPhysicalCharacteristics (char *name,double value);

void createOrigin (Planet p,char* name);

Jerry addChar (Jerry j, PhysicalCharacteristics character);

status removeChar (Jerry *j , char* character);

void printJerry (Jerry j);

status printPlanet(Planet p);

void planetsDestroy ();

void originsDestroy ();

void characterDestroy();

void jerryDestroy();

Jerry CopyOfJerry (Jerry j );


void removeJerry(Jerry j);

Planet *planets;
PhysicalCharacteristics * character;
Origin * origins;
int countPlanets;
int countCaracter;
int countOrigins;

