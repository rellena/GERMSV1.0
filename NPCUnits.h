#pragma once
#include "gameinclude.h"


class NPCUnits: public unit
{

public:
	NPCUnits();
	NPCUnits(float,float,float,float,float,float,string,string);
	void setWhiteBloodCell(float hp,float armor,float damage,float speed,float range,string charClass);



private:
	string unitSpecialAbilityName;
	unit npc;
	//white blood cell special ability
	float damageMultiplier;
	
	

};

