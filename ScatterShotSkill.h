#include "gameinclude.h"
//note this is a influenza skill ability


class ScatterShotSkill
{
public:
	//default constructor
	ScatterShotSkill();
	ScatterShotSkill(int skillLevel, float damage, float energyCost);
	//when the skill hits a target
	void collisionDamage();
	
private:
	//everything has to start somewhere
	float baseDamage;
	float baseEnergyCost;
	//the idea is this is the special ability you start out with
	int startingSkillLevel = 1;

};