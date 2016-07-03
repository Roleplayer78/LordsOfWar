#include <vector>
#include <algorithm>
#include "engine_defs.hpp"
#include "game_engine_tables.hpp"

//~ std::string     name;       // Name of the skill
//~ std::uint16_t   oml;        // Opening Mastery Level of the skill
//~ eStats          stat1;      // 1st stat for computing SB
//~ eStats          stat2;      // 2nd stat for computing SB
//~ eStats          stat3;      // 3rd stat for computing SB
//~ std::string     path;       // Path to icon
//~ ePenaltyType    penalty;    // What penalty influence the skill

std::vector<sSkillDefinition> skill_table(UNKNOWN_SKILL);

// This is a vector of 2D tables. Essentially a 3D vector.
//    ,-------,
//   /___/__ / |
//  /   /   /| |
// ,---/---/ |/|
// |___|___|/|/
// |   |   | /
// `-------'`
// 3d dimension = Type of attack, table is "Attaccker roll vs Defender roll"
// Personal frustration note: c++ syntax and STL are a total, useless, wasteful mess.
std::vector<std::vector<std::vector<eCombatResult>>> melee_tables((UNKOWN_MD + UNKOWN_DD + UNKOWN_PD + UNKOWN_GD + UNKOWN_MSD), // Size the arry of matrices
                                                                  std::vector<std::vector<eCombatResult>>(UNKNOWN_RESULT,   // Size the combat matrices
                                                                  std::vector<eCombatResult>(UNKNOWN_RESULT)));

void InitializeSkillTable()
{
    /**
     *  Combat Skills initialization
     */
                                        //~ name    oml    stat1    stat2    stat3    path    penalty
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

void InitializeCombatTables()
{
    /**
     *  Melee tables
     */
    // Shield Block / 2W Block
    // Attacker CF
    melee_tables[SHIELD_2W_BLOCK_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CF_RESULT][MS_RESULT] = DTA_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    melee_tables[SHIELD_2W_BLOCK_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MF_RESULT][MS_RESULT] = DTA_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    melee_tables[SHIELD_2W_BLOCK_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    melee_tables[SHIELD_2W_BLOCK_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    melee_tables[SHIELD_2W_BLOCK_MD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Weapon Parry
    // Attacker CF
    melee_tables[WEAPON_PARRY_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[WEAPON_PARRY_MD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[WEAPON_PARRY_MD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    melee_tables[WEAPON_PARRY_MD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    melee_tables[WEAPON_PARRY_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    melee_tables[WEAPON_PARRY_MD][MF_RESULT][MF_RESULT] = PARRY_CS;
    melee_tables[WEAPON_PARRY_MD][MF_RESULT][MS_RESULT] = PARRY_CS;
    melee_tables[WEAPON_PARRY_MD][MF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MS
    melee_tables[WEAPON_PARRY_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    melee_tables[WEAPON_PARRY_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    melee_tables[WEAPON_PARRY_MD][MS_RESULT][MS_RESULT] = PARRY_CS;
    melee_tables[WEAPON_PARRY_MD][MS_RESULT][CS_RESULT] = PARRY_CS;
    // Attacker CS
    melee_tables[WEAPON_PARRY_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    melee_tables[WEAPON_PARRY_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    melee_tables[WEAPON_PARRY_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    melee_tables[WEAPON_PARRY_MD][CS_RESULT][CS_RESULT] = PARRY_CS;

    // Counterstrike
    // Attacker CF
    melee_tables[COUNTERSTRIKE_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[COUNTERSTRIKE_MD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    melee_tables[COUNTERSTRIKE_MD][CF_RESULT][MS_RESULT] = DSK_2D_CS;
    melee_tables[COUNTERSTRIKE_MD][CF_RESULT][CS_RESULT] = DSK_3D_CS;
    // Attacker MF
    melee_tables[COUNTERSTRIKE_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    melee_tables[COUNTERSTRIKE_MD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    melee_tables[COUNTERSTRIKE_MD][MF_RESULT][MS_RESULT] = DSK_1D_CS;
    melee_tables[COUNTERSTRIKE_MD][MF_RESULT][CS_RESULT] = DSK_2D_CS;
    // Attacker MS
    melee_tables[COUNTERSTRIKE_MD][MS_RESULT][CF_RESULT] = ASK_3D_CS;
    melee_tables[COUNTERSTRIKE_MD][MS_RESULT][MF_RESULT] = ASK_2D_CS;
    melee_tables[COUNTERSTRIKE_MD][MS_RESULT][MS_RESULT] = BSK_1D_CS;
    melee_tables[COUNTERSTRIKE_MD][MS_RESULT][CS_RESULT] = DSK_1D_CS;
    // Attacker CS
    melee_tables[COUNTERSTRIKE_MD][CS_RESULT][CF_RESULT] = ASK_4D_CS;
    melee_tables[COUNTERSTRIKE_MD][CS_RESULT][MF_RESULT] = ASK_3D_CS;
    melee_tables[COUNTERSTRIKE_MD][CS_RESULT][MS_RESULT] = ASK_2D_CS;
    melee_tables[COUNTERSTRIKE_MD][CS_RESULT][CS_RESULT] = BSK_1D_CS;

    // Dodge
    // Attacker CF
    melee_tables[DODGE_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MF
    melee_tables[DODGE_MD][MF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MS
    melee_tables[DODGE_MD][MS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][MS_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker CS
    melee_tables[DODGE_MD][CS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DODGE_MD][CS_RESULT][CS_RESULT] = BF_3D_CS;

    // Grapple
    // Attacker CF
    melee_tables[GRAPPLE_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MF
    melee_tables[GRAPPLE_MD][MF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MS
    melee_tables[GRAPPLE_MD][MS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][MS_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker CS
    melee_tables[GRAPPLE_MD][CS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[GRAPPLE_MD][CS_RESULT][CS_RESULT] = BF_3D_CS;

    // Disarm
    // Attacker CF
    melee_tables[DISARM_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MF
    melee_tables[DISARM_MD][MF_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MF_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MF_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MF_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker MS
    melee_tables[DISARM_MD][MS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][MS_RESULT][CS_RESULT] = BF_3D_CS;
    // Attacker CS
    melee_tables[DISARM_MD][CS_RESULT][CF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CS_RESULT][MF_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CS_RESULT][MS_RESULT] = BF_3D_CS;
    melee_tables[DISARM_MD][CS_RESULT][CS_RESULT] = BF_3D_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        melee_tables[IGNORE_MD][CF_RESULT][i] = DTA_CS;
        melee_tables[IGNORE_MD][MF_RESULT][i] = ASK_1D_CS;
        melee_tables[IGNORE_MD][MS_RESULT][i] = ASK_3D_CS;
        melee_tables[IGNORE_MD][CS_RESULT][i] = ASK_4D_CS;
    }
}
