#include <vector>
#include "creature_stats.hpp"

//~ std::string     name;       // Name of the skill
//~ std::uint16_t   oml;        // Opening Mastery Level of the skill
//~ eStats          stat1;      // 1st stat for computing SB
//~ eStats          stat2;      // 2nd stat for computing SB
//~ eStats          stat3;      // 3rd stat for computing SB
//~ std::string     path;       // Path to icon
//~ ePenaltyType    penalty;    // What penalty influence the skill

std::vector<sSkillDefinition> skill_table(UNKNOWN_SKILL);

void InitializeSkillTable()
{
    /**
     *  Combat Skills initialization
     */
    skill_table[INITIATIVE_SKILL]   = {"Initiative", 4, AGILITY_STAT, WILLPOWER_STAT, WILLPOWER_STAT, "", PHYSICAL_PENALTY};
    skill_table[DODGE_SKILL]        = {"Dodge", 5, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[UNARMED_KILL]       = {"Unarmed", 4, STRENGTH_STAT, DEXTERITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[RIDING_SKILL]       = {"Riding", 1, DEXTERITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[AXE_SKILL]          = {"Axe", 3, STRENGTH_STAT, STRENGTH_STAT, DEXTERITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[BLOWGUN_SKILL]      = {"Blowgun", 4, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY};
    skill_table[BOW_SKILL]          = {"Bow", 2, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[CLUB_SKILL]         = {"Club", 4, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[DAGGER_SKILL]       = {"Dagger", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[FLAIL_SKILL]        = {"Flail", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[NET_SKILL]          = {"Net", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[POLEARM_SKILL]      = {"Poelarm", 2, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[SHIELD_SKIL]        = {"Shield", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[SLING_SKIL]         = {"Sling", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[SPEAR_SKILL]        = {"Spear", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[SWORD_SKILL]        = {"Sword", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[WHIP_SKILL]         = {"Whip", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY};
    skill_table[CROSSBOW_SKILL]     = {"Crossbow", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY};
    // Derived combat traits
    skill_table[ENDURANCE_SKILL]    = {"Endurance", 1, STRENGTH_STAT, STAMINA_STAT, WILLPOWER_STAT, "", PHYSICAL_PENALTY};
    skill_table[MOVEMENT_SKILL]     = {"Movement", 1, AGILITY_STAT, UNKNOWN_STAT, UNKNOWN_STAT, "", PHYSICAL_PENALTY};

    /**
     *  Combat Skills initialization
     */
}
