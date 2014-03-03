#include "NPCUnits.h"

NPCUnits::NPCUnits()
{
	
}


void NPCUnits::setWhiteBloodCell(float hp,float armor,float damage,float speed,float range,string charClass)
{
	//testing out vector
	//note unique_ptr is not supported by VS 2008, has to be 2011 or beyond
	//vector<std::unique_ptr<unit> > testUnits();
	
	
	//set the WBC stats
	npc.setHealth(hp);
	npc.setArmor(armor);
	npc.setDamage(damage);
	npc.setSpeed(speed);
	npc.setRange(range);
	npc.setCharName("White Blood Cell");
	npc.setCharClass(charClass);

}