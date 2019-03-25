#include <iostream>
#include <string>
#include <vector>
#include "PlayerClass.h"
#include "Player.h"
#pragma once

using namespace std;

class ClassManager
{
public:
	ClassManager();
	void GenerateClasses();
	void Promote(Player);
	vector<PlayerClass> AllClasses = vector<PlayerClass>(27);
	enum BaseType {
		NonClass = 0,
		Knight,
		Wizard,
		Archer,
		Lancer,
		Brawler,
		Fighter,
		Rogue,
		Mage,
		Clergy
	};
};
ClassManager::ClassManager()
{
	GenerateClasses();
}
void ClassManager::GenerateClasses()
{
	AllClasses[0] = PlayerClass("Knight", NonClass, Knight);
	AllClasses[0].Desc1 = "A versatile class that uses simple weapons";
	AllClasses[0].Desc2 = "Weapon Proficiency: Simple";
	AllClasses[0].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[0].AbilityDesc = "Ability - Swordsman: Gives + 2 Damage to Swords.";
	AllClasses[1] = PlayerClass("Wizard", NonClass, Wizard);
	AllClasses[1].Desc1 = "A magic-casting class that uses basic magic";
	AllClasses[1].Desc2 = "Weapon Proficiency: Magic";
	AllClasses[1].Desc3 = "Armour Proficiency: Light";
	AllClasses[1].AbilityDesc = "Ability - Spellweaver: Gives +2 Damage to Wands.";
	AllClasses[2] = PlayerClass("Archer", NonClass, Archer);
	AllClasses[2].Desc1 = "A dexterous class that specializes in ranged combat.";
	AllClasses[2].Desc2 = "Weapon Proficiency: Ranged";
	AllClasses[2].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[2].AbilityDesc = "Ability - Bowslinger: Gives +2 Damage to Bows.";
	AllClasses[3] = PlayerClass("Lancer", NonClass, Lancer);
	AllClasses[3].Desc1 = "A defensive class that uses martial weapons";
	AllClasses[3].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[3].Desc3 = "Armour Proficiency: Light, Medium, Heavy";
	AllClasses[3].AbilityDesc = "Ability - Polearm Master: Gives +2 Damage to Lances.";
	AllClasses[4] = PlayerClass("Fighter", NonClass, Fighter);
	AllClasses[4].Desc1 = "A strength-based class that uses strong weapons";
	AllClasses[4].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[4].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[4].AbilityDesc = "Ability - Headsplitter: Gives +2 Damage to Axes.";
	AllClasses[5] = PlayerClass("Brawler", NonClass, Brawler);
	AllClasses[5].Desc1 = "A sturdy class that fights with their fists.";
	AllClasses[5].Desc2 = "Weapon Proficiency: Simple";
	AllClasses[5].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[5].AbilityDesc = "Ability - Iron Fist: Gives +2 Damage to Fists.";
	AllClasses[6] = PlayerClass("Rogue", NonClass, Rogue);
	AllClasses[6].Desc1 = "An agile class that specializes in both melee and range.";
	AllClasses[6].Desc2 = "Weapon Proficiency: Simple, Ranged";
	AllClasses[6].Desc3 = "Armour Proficiency: Light";
	AllClasses[6].AbilityDesc = "Ability - Dagger Adept: Gives +2 Damage to Daggers.";
	AllClasses[7] = PlayerClass("Mage", NonClass, Mage);
	AllClasses[7].Desc1 = "A magical class more geared towards combat";
	AllClasses[7].Desc2 = "Weapon Proficiency: Magic";
	AllClasses[7].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[7].AbilityDesc = "Ability - Arcanist: Gives +2 Damage to Tomes.";
	AllClasses[8] = PlayerClass("Clergy", NonClass, Clergy);
	AllClasses[8].Desc1 = "A dedicated healing class, capable of wielding staves";
	AllClasses[8].Desc2 = "Weapon Proficiency: Staff";
	AllClasses[8].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[8].AbilityDesc = "Ability - Serene Grace: Gives +2 Healing to Staves.";
	// PROMOTION ---------------------------------------------------------------------------------
	AllClasses[9] = PlayerClass("Myrmidon", Knight);
	AllClasses[9].Desc1 = "A Knight that forgoes defense for the sake of strength";
	AllClasses[9].Desc2 = "Weapon Proficiency: Simple";
	AllClasses[9].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[9].AbilityDesc = "Ability - Parry: Allows access to the 'Parry' action in combat.";
	AllClasses[10] = PlayerClass("Paladin", Knight);
	AllClasses[10].Desc1 = "A Knight that has mastered the art of mounted combat.";
	AllClasses[10].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[10].Desc3 = "Armour Proficiency: Light, Medium, Heavy";
	AllClasses[10].AbilityDesc = "Ability - Pieous: Grants resistance to Light damage.";
	AllClasses[11] = PlayerClass("Sage", Wizard);
	AllClasses[11].Desc1 = "A Wizard who has learned the ways of the divine.";
	AllClasses[11].Desc2 = "Weapon Proficiency: Magic, Staff";
	AllClasses[11].Desc3 = "Armour Proficiency: Light";
	AllClasses[11].AbilityDesc = "Ability - Pieous: Grants resistance to Light damage.";
	AllClasses[12] = PlayerClass("Scholar", Wizard);
	AllClasses[12].Desc1 = "A Wizard who has become wise through study.";
	AllClasses[12].Desc2 = "Weapon Proficiency: Magic";
	AllClasses[12].Desc3 = "Armour Proficiency: Light";
	AllClasses[12].AbilityDesc = "Ability - Swordsman: Gives + 2 Damage to Swords.";
	AllClasses[13] = PlayerClass("Sniper", Archer);
	AllClasses[13].Desc1 = "An Archer dedicated to the art of ranged combat.";
	AllClasses[13].Desc2 = "Weapon Proficiency: Ranged";
	AllClasses[13].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[13].AbilityDesc = "Ability - Deathstrike: Increases chance of critical hits.";
	AllClasses[14] = PlayerClass("Hunter", Archer);
	AllClasses[14].Desc1 = "An Archer that has become adept in hand-to-hand combat.";
	AllClasses[14].Desc2 = "Weapon Proficiency: Simple, Ranged";
	AllClasses[14].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[14].AbilityDesc = "Ability - Gatherer: Increased drop rates from monsters.";
	AllClasses[15] = PlayerClass("Cavalier", Lancer);
	AllClasses[15].Desc1 = "A Lancer that has mastered the art of mounted combat.";
	AllClasses[15].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[15].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[15].AbilityDesc = "Ability - Horseman: Grants resistance to basic damage.";
	AllClasses[16] = PlayerClass("Guardian", Lancer);
	AllClasses[16].Desc1 = "A Lancer that wields the heaviest of armour with ease.";
	AllClasses[16].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[16].Desc3 = "Armour Proficiency: Light, Medium, Heavy";
	AllClasses[16].AbilityDesc = "Ability - Anchor: Forces enemies to target the user.";
	AllClasses[17] = PlayerClass("Monk", Brawler);
	AllClasses[17].Desc1 = "A Brawler who has obtained magical strength through concentration.";
	AllClasses[17].Desc2 = "Weapon Proficiency: Simple";
	AllClasses[17].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[17].AbilityDesc = "Ability - Ki: Fist weapons with no magic will deal Entrophic damage.";
	AllClasses[18] = PlayerClass("Grandmaster", Brawler);
	AllClasses[18].Desc1 = "A Brawler who has mastered the art of combat through training.";
	AllClasses[18].Desc2 = "Weapon Proficiency: Simple";
	AllClasses[18].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[18].AbilityDesc = "Ability - Parry: Allows access to the 'Parry' command.";
	AllClasses[19] = PlayerClass("Barbarian", Fighter);
	AllClasses[19].Desc1 = "A Fighter who has learned the ways of combat through experience.";
	AllClasses[19].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[19].Desc3 = "Armour Proficiency: Light, Medium, Heavy";
	AllClasses[19].AbilityDesc = "Ability - Pillage: Increased drop rates from monsters.";
	AllClasses[20] = PlayerClass("Berzerker", Fighter);
	AllClasses[20].Desc1 = "A Fighter who draws strength from their inner rage.";
	AllClasses[20].Desc2 = "Weapon Proficiency: Simple, Martial";
	AllClasses[20].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[20].AbilityDesc = "Ability - Rage: Deals extra damage when health is low.";
	AllClasses[21] = PlayerClass("Assassin", Rogue);
	AllClasses[21].Desc1 = "A Rogue who has mastered the art of killing.";
	AllClasses[21].Desc2 = "Weapon Proficiency: Simple, Ranged";
	AllClasses[21].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[21].AbilityDesc = "Ability - Deathstrike: Increased chance of critical hits.";
	AllClasses[22] = PlayerClass("Warlock", Rogue);
	AllClasses[22].Desc1 = "A Rogue who has strengthened their powers through the study of magic.";
	AllClasses[22].Desc2 = "Weapon Proficiency: Simple, Ranged, Magic";
	AllClasses[22].Desc3 = "Armour Proficiency: Light";
	AllClasses[22].AbilityDesc = "Ability - Arcane Trickster: Simple weapons with no magic will deal Entrophic damage.";
	AllClasses[23] = PlayerClass("Spellsword", Mage);
	AllClasses[23].Desc1 = "A Mage who has taken up the sword to enchance their powers.";
	AllClasses[23].Desc2 = "Weapon Proficiency: Simple, Magic";
	AllClasses[23].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[23].AbilityDesc = "Ability - Tactician: Allows the user to cast spells from their simple weapon.";
	AllClasses[24] = PlayerClass("Sorcerer", Mage);
	AllClasses[24].Desc1 = "A Mage who has strengthened their magic by dabbling in the dark arts.";
	AllClasses[24].Desc2 = "Weapon Proficiency: Magic";
	AllClasses[24].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[24].AbilityDesc = "Ability - Demonkin: Grants resistance to Dark damage.";
	AllClasses[25] = PlayerClass("Bishop", Clergy);
	AllClasses[25].Desc1 = "A Clergy who has obtained wisdom through worship and dedication.";
	AllClasses[25].Desc2 = "Weapon Proficiency: Magic, Staff";
	AllClasses[25].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[25].AbilityDesc = "Ability - Pieous: Grants resistance to Light damage.";
	AllClasses[26] = PlayerClass("War Cleric", Clergy);
	AllClasses[26].Desc1 = "A Clergy whose strength comes from discipline.";
	AllClasses[26].Desc2 = "Weapon Proficiency: Simple, Martial, Staff";
	AllClasses[26].Desc3 = "Armour Proficiency: Light, Medium";
	AllClasses[26].AbilityDesc = "Ability - Righteous: Increases damage when health is low.";
}
void ClassManager::Promote(Player self)
{
	vector<PlayerClass> Choices;
	for (size_t i = 0; i < AllClasses.size(); i++)
	{
		if (AllClasses[i].Prerequisite == self.Job.Current)
		{
			Choices.push_back(AllClasses[i]);
		}
	}
}