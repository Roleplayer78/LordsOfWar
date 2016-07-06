#include <vector>
#include <algorithm>
#include "engine/engine_types.hpp"
#include "engine/game_engine_tables.hpp"

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
std::vector<std::vector<std::vector<eCombatResult>>> attack_matrices((UNKOWN_MD + UNKOWN_DD + UNKOWN_PD + UNKOWN_GD + UNKOWN_MSD + UNKOWN_ID + UNKOWN_JD + UNKOWN_MED), // Size the arry of matrices
                                                                  std::vector<std::vector<eCombatResult>>(UNKNOWN_RESULT,   // Size the combat matrices
                                                                  std::vector<eCombatResult>(UNKNOWN_RESULT)));

void InitializeSkillTable()
{
    /**
     *  Combat Skills initialization
     */
                                        //~ name    oml    stat1    stat2    stat3    path    penalty   can_increase
    skill_table[INITIATIVE_SKILL]   = {"Initiative", 4, AGILITY_STAT, WILLPOWER_STAT, WILLPOWER_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[DODGE_SKILL]        = {"Dodge", 5, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[UNARMED_KILL]       = {"Unarmed", 4, STRENGTH_STAT, DEXTERITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[RIDING_SKILL]       = {"Riding", 1, DEXTERITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[AXE_SKILL]          = {"Axe", 3, STRENGTH_STAT, STRENGTH_STAT, DEXTERITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[BLOWGUN_SKILL]      = {"Blowgun", 4, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[BOW_SKILL]          = {"Bow", 2, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[CLUB_SKILL]         = {"Club", 4, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[DAGGER_SKILL]       = {"Dagger", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[FLAIL_SKILL]        = {"Flail", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[NET_SKILL]          = {"Net", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[POLEARM_SKILL]      = {"Poelarm", 2, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SHIELD_SKIL]        = {"Shield", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SLING_SKIL]         = {"Sling", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SPEAR_SKILL]        = {"Spear", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SWORD_SKILL]        = {"Sword", 3, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[WHIP_SKILL]         = {"Whip", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[CROSSBOW_SKILL]     = {"Crossbow", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    // Derived combat traits
    skill_table[ENDURANCE_SKILL]    = {"Endurance", 1, STRENGTH_STAT, STAMINA_STAT, WILLPOWER_STAT, "", PHYSICAL_PENALTY, false};
    skill_table[MOVEMENT_SKILL]     = {"Movement", 1, AGILITY_STAT, AGILITY_STAT, AGILITY_STAT, "", PHYSICAL_PENALTY, false};

    /**
     *  Physical Skills initialization
     */
                                        //~ name    oml    stat1    stat2    stat3    path    penalty   can_increase
    skill_table[CLIMBING_SKILL]     = {"Climbing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[JUMPING_SKILL]     = {"Jumpinh", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[STEALTH_SKILL]     = {"Stealth", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[THROWING_SKILL]     = {"Throwing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ACROBATICS_SKILL]     = {"Acrobatics", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[DANCING_SKILL]     = {"Dancing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[LEGERDMAIN_SKILL]     = {"Legerdmain", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SKIING_SKILL]     = {"Skiing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SWIMMING_SKILL]     = {"Swimming", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};

    /**
     *  Communication Skills initialization
     */
                                        //~ name    oml    stat1    stat2    stat3    path    penalty   can_increase
    skill_table[AWARENESS_SKILL]     = {"Awareness", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[INTRIGUE_SKILL]     = {"Intrigue", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ORATORY_SKILL]     = {"oratory", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[RHETORIC_SKILL]     = {"Rhetoric", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SINGING_SKILL]     = {"Singing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ACTING_SKILL]     = {"Acting", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[LOVECRAFT_SKILL]     = {"Lovecraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MENTAL_CONFLICT_SKILL]     = {"Mental conflict", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MUSICIAN_SKILL]     = {"Musician", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};

    /**
     *  Lore/Craft Skills initialization
     */
                                        //~ name    oml    stat1    stat2    stat3    path    penalty   can_increase
    skill_table[AGRICOLTURE_SKILL]     = {"Agricolture", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ALCHEMY_SKILL]     = {"Alchemy", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ANIMALCRAFT_SKILL]     = {"Animalcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ASTROLOGY_SKILL]     = {"Astrology", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[BREWING_SKILL]     = {"Brewing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[CERAMICS_SKILL]     = {"Ceramics", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[COOKERY_SKILL]     = {"Cookery", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[DRAWING_SKILL]     = {"Drawing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[EMBALMING_SKILL]     = {"Embalming", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[ENGINEERING_SKILL]     = {"Engineeering", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[FISHING_SKILL]     = {"Fishing", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[FLETCHING_SKILL]     = {"Fletching", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[FOLKLORE_SKILL]     = {"Folklore", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[FORAGING_SKILL]     = {"Foraging", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[GLASSWORK_SKILL]     = {"Glasswork", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[HERALDRY_SKILL]     = {"Heraldry", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[HERBLORE_SKILL]     = {"Herblore", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[HIDEWORK_SKILL]     = {"Hidework", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[JEWELCRAFT_SKILL]     = {"Jewelcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[LAW_SKILL]     = {"Law", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[LOCKCRAFT_SKILL]     = {"Lockcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MASONRY_SKILL]     = {"Masonry", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MATHEMATICS_SKILL]     = {"Mathematics", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[METALCRAFT_SKILL]     = {"Metalcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MILLING_SKILL]     = {"Milling", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[MINING_SKILL]     = {"Mining", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[PERFUMERY_SKILL]     = {"Perfumery", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[PHYSICIAN_SKILL]     = {"Physician", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[PILOTING_SKILL]     = {"Piloting", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[RUNECRAFT_SKILL]     = {"Runecraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SEAMANSHIP_SKILL]     = {"Seamanship", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SHIPWRIGHT_SKILL]     = {"Shipwright", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[SURVIVAL_SKILL]     = {"Survival", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[TAROTRY_SKILL]     = {"Tarotry", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[TEXTILCRAFT_SKILL]     = {"Textilcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[TIMBERCRAFT_SKILL]     = {"Timbercraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[TRACKING_SKILL]     = {"Tracking", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[TRAPPING_SKILL]     = {"Trapping", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[WEAPONCRAFT_SKILL]     = {"Weaponcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[WEATHERLORE_SKILL]     = {"Weatherlore", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
    skill_table[WOODCRAFT_SKILL]     = {"Woodcraft", 3, STRENGTH_STAT, DEXTERITY_STAT, EYESIGHT_STAT, "", PHYSICAL_PENALTY, true};
}

void InitializeCombatTables()
{
    /**
     *  Melee Attack tables
     */
    // Shield Block / 2W Block
    // Attacker CF
    attack_matrices[SHIELD_2W_BLOCK_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[SHIELD_2W_BLOCK_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[SHIELD_2W_BLOCK_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[SHIELD_2W_BLOCK_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[SHIELD_2W_BLOCK_MD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Weapon Parry
    // Attacker CF
    attack_matrices[WEAPON_PARRY_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_MD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_MD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[WEAPON_PARRY_MD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[WEAPON_PARRY_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_MD][MF_RESULT][MF_RESULT] = PARRY_CS;
    attack_matrices[WEAPON_PARRY_MD][MF_RESULT][MS_RESULT] = PARRY_CS;
    attack_matrices[WEAPON_PARRY_MD][MF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MS
    attack_matrices[WEAPON_PARRY_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    attack_matrices[WEAPON_PARRY_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    attack_matrices[WEAPON_PARRY_MD][MS_RESULT][MS_RESULT] = PARRY_CS;
    attack_matrices[WEAPON_PARRY_MD][MS_RESULT][CS_RESULT] = PARRY_CS;
    // Attacker CS
    attack_matrices[WEAPON_PARRY_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[WEAPON_PARRY_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[WEAPON_PARRY_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[WEAPON_PARRY_MD][CS_RESULT][CS_RESULT] = PARRY_CS;

    // Counterstrike
    // Attacker CF
    attack_matrices[COUNTERSTRIKE_MD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CF_RESULT][MS_RESULT] = DSK_2D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CF_RESULT][CS_RESULT] = DSK_3D_CS;
    // Attacker MF
    attack_matrices[COUNTERSTRIKE_MD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_MD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERSTRIKE_MD][MF_RESULT][MS_RESULT] = DSK_1D_CS;
    attack_matrices[COUNTERSTRIKE_MD][MF_RESULT][CS_RESULT] = DSK_2D_CS;
    // Attacker MS
    attack_matrices[COUNTERSTRIKE_MD][MS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[COUNTERSTRIKE_MD][MS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[COUNTERSTRIKE_MD][MS_RESULT][MS_RESULT] = BSK_1D_CS;
    attack_matrices[COUNTERSTRIKE_MD][MS_RESULT][CS_RESULT] = DSK_1D_CS;
    // Attacker CS
    attack_matrices[COUNTERSTRIKE_MD][CS_RESULT][CF_RESULT] = ASK_4D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CS_RESULT][MF_RESULT] = ASK_3D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CS_RESULT][MS_RESULT] = ASK_2D_CS;
    attack_matrices[COUNTERSTRIKE_MD][CS_RESULT][CS_RESULT] = BSK_1D_CS;

    // Dodge
    // Attacker CF
    attack_matrices[DODGE_MD][CF_RESULT][CF_RESULT] = BS_3D_CS;
    attack_matrices[DODGE_MD][CF_RESULT][MF_RESULT] = AS_3D_CS;
    attack_matrices[DODGE_MD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[DODGE_MD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[DODGE_MD][MF_RESULT][CF_RESULT] = DS_3D_CS;
    attack_matrices[DODGE_MD][MF_RESULT][MF_RESULT] = MISS_CS;
    attack_matrices[DODGE_MD][MF_RESULT][MS_RESULT] = MISS_CS;
    attack_matrices[DODGE_MD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[DODGE_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    attack_matrices[DODGE_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    attack_matrices[DODGE_MD][MS_RESULT][MS_RESULT] = MISS_CS;
    attack_matrices[DODGE_MD][MS_RESULT][CS_RESULT] = MISS_CS;
    // Attacker CS
    attack_matrices[DODGE_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[DODGE_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[DODGE_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[DODGE_MD][CS_RESULT][CS_RESULT] = MISS_CS;

    // Grapple
    // Attacker CF
    attack_matrices[GRAPPLE_MD][CF_RESULT][CF_RESULT] = BS_3D_CS;
    attack_matrices[GRAPPLE_MD][CF_RESULT][MF_RESULT] = DTA_CS;
    attack_matrices[GRAPPLE_MD][CF_RESULT][MS_RESULT] = DHOLD_CS;
    attack_matrices[GRAPPLE_MD][CF_RESULT][CS_RESULT] = DHOLD_CS;
    // Attacker MF
    attack_matrices[GRAPPLE_MD][MF_RESULT][CF_RESULT] = DS_3D_CS;
    attack_matrices[GRAPPLE_MD][MF_RESULT][MF_RESULT] = BS_3D_CS;
    attack_matrices[GRAPPLE_MD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[GRAPPLE_MD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[GRAPPLE_MD][MS_RESULT][CF_RESULT] = ASK_2D_CS;
    attack_matrices[GRAPPLE_MD][MS_RESULT][MF_RESULT] = ASK_1D_CS;
    attack_matrices[GRAPPLE_MD][MS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[GRAPPLE_MD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[GRAPPLE_MD][CS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[GRAPPLE_MD][CS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[GRAPPLE_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[GRAPPLE_MD][CS_RESULT][CS_RESULT] = MISS_CS;

    // Disarm
    // Attacker CF
    attack_matrices[DISARM_MD][CF_RESULT][CF_RESULT] = BS_3D_CS;
    attack_matrices[DISARM_MD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[DISARM_MD][CF_RESULT][MS_RESULT] = AF_4D_CS;
    attack_matrices[DISARM_MD][CF_RESULT][CS_RESULT] = AF_5D_CS;
    // Attacker MF
    attack_matrices[DISARM_MD][MF_RESULT][CF_RESULT] = ASK_1D_CS;
    attack_matrices[DISARM_MD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[DISARM_MD][MF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[DISARM_MD][MF_RESULT][CS_RESULT] = AF_4D_CS;
    // Attacker MS
    attack_matrices[DISARM_MD][MS_RESULT][CF_RESULT] = ASK_3D_CS;
    attack_matrices[DISARM_MD][MS_RESULT][MF_RESULT] = ASK_2D_CS;
    attack_matrices[DISARM_MD][MS_RESULT][MS_RESULT] = MISS_CS;
    attack_matrices[DISARM_MD][MS_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker CS
    attack_matrices[DISARM_MD][CS_RESULT][CF_RESULT] = ASK_4D_CS;
    attack_matrices[DISARM_MD][CS_RESULT][MF_RESULT] = ASK_3D_CS;
    attack_matrices[DISARM_MD][CS_RESULT][MS_RESULT] = ASK_1D_CS;
    attack_matrices[DISARM_MD][CS_RESULT][CS_RESULT] = MISS_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        attack_matrices[IGNORE_MD][CF_RESULT][i] = DTA_CS;
        attack_matrices[IGNORE_MD][MF_RESULT][i] = ASK_1D_CS;
        attack_matrices[IGNORE_MD][MS_RESULT][i] = ASK_3D_CS;
        attack_matrices[IGNORE_MD][CS_RESULT][i] = ASK_4D_CS;
    }


    /**
     *  Disarm Attack tables
     */
    // Shield Block
    // Attacker CF
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Weapon Parry
    // Attacker CF
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MF
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Weapon Parry
    // Attacker CF
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MF
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Counterstrike
    // Attacker CF
    attack_matrices[COUNTERSTRIKE_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CF_RESULT][MS_RESULT] = DSK_2D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CF_RESULT][CS_RESULT] = DSK_3D_CS;
    // Attacker MF
    attack_matrices[COUNTERSTRIKE_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERSTRIKE_DD][MF_RESULT][MS_RESULT] = DSK_1D_CS;
    attack_matrices[COUNTERSTRIKE_DD][MF_RESULT][CS_RESULT] = DSK_2D_CS;
    // Attacker MS
    attack_matrices[COUNTERSTRIKE_DD][MS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERSTRIKE_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][MS_RESULT][CS_RESULT] = DSK_1D_CS;
    // Attacker CS
    attack_matrices[COUNTERSTRIKE_DD][CS_RESULT][CF_RESULT] = DF_6D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CS_RESULT][MF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_DD][CS_RESULT][CS_RESULT] = BF_1D_CS;

    // Disarm
    // Attacker CF
    attack_matrices[DISARM_DD][CF_RESULT][CF_RESULT] = BS_3D_CS;
    attack_matrices[DISARM_DD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[DISARM_DD][CF_RESULT][MS_RESULT] = AF_4D_CS;
    attack_matrices[DISARM_DD][CF_RESULT][CS_RESULT] = AF_5D_CS;
    // Attacker MF
    attack_matrices[DISARM_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[DISARM_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[DISARM_DD][MF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[DISARM_DD][MF_RESULT][CS_RESULT] = AF_4D_CS;
    // Attacker MS
    attack_matrices[DISARM_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[DISARM_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[DISARM_DD][MS_RESULT][MS_RESULT] = BF_4D_CS;
    attack_matrices[DISARM_DD][MS_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker CS
    attack_matrices[DISARM_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[DISARM_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[DISARM_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[DISARM_DD][CS_RESULT][CS_RESULT] = BF_5D_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        attack_matrices[IGNORE_DD][CF_RESULT][i] = DTA_CS;
        attack_matrices[IGNORE_DD][MF_RESULT][i] = DF_3D_CS;
        attack_matrices[IGNORE_DD][MS_RESULT][i] = DF_5D_CS;
        attack_matrices[IGNORE_DD][CS_RESULT][i] = DF_6D_CS;
    }


    /**
     *  Press Attack tables // TODO
     */
    // Counterpress
    // Attacker CF
    attack_matrices[COUNTERPRESS_PD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERPRESS_PD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[COUNTERPRESS_PD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[COUNTERPRESS_PD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[COUNTERPRESS_PD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERPRESS_PD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERPRESS_PD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[COUNTERPRESS_PD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[COUNTERPRESS_PD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[COUNTERPRESS_PD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERPRESS_PD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERPRESS_PD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[COUNTERPRESS_PD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERPRESS_PD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[COUNTERPRESS_PD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERPRESS_PD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Counterstrike
    // Attacker CF
    attack_matrices[COUNTERSTRIKE_PD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CF_RESULT][MS_RESULT] = DSK_2D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CF_RESULT][CS_RESULT] = DSK_3D_CS;
    // Attacker MF
    attack_matrices[COUNTERSTRIKE_PD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERSTRIKE_PD][MF_RESULT][MS_RESULT] = DSK_1D_CS;
    attack_matrices[COUNTERSTRIKE_PD][MF_RESULT][CS_RESULT] = DSK_2D_CS;
    // Attacker MS
    attack_matrices[COUNTERSTRIKE_PD][MS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERSTRIKE_PD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][MS_RESULT][CS_RESULT] = DSK_1D_CS;
    // Attacker CS
    attack_matrices[COUNTERSTRIKE_PD][CS_RESULT][CF_RESULT] = DF_6D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CS_RESULT][MF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_PD][CS_RESULT][CS_RESULT] = BF_1D_CS;

    // Dodge
    // Attacker CF
    attack_matrices[DODGE_PD][CF_RESULT][CF_RESULT] = BS_3D_CS;
    attack_matrices[DODGE_PD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[DODGE_PD][CF_RESULT][MS_RESULT] = AF_4D_CS;
    attack_matrices[DODGE_PD][CF_RESULT][CS_RESULT] = AF_5D_CS;
    // Attacker MF
    attack_matrices[DODGE_PD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_PD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[DODGE_PD][MF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[DODGE_PD][MF_RESULT][CS_RESULT] = AF_4D_CS;
    // Attacker MS
    attack_matrices[DODGE_PD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[DODGE_PD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_PD][MS_RESULT][MS_RESULT] = BF_4D_CS;
    attack_matrices[DODGE_PD][MS_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker CS
    attack_matrices[DODGE_PD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[DODGE_PD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[DODGE_PD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_PD][CS_RESULT][CS_RESULT] = BF_5D_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        attack_matrices[IGNORE_PD][CF_RESULT][i] = DTA_CS;
        attack_matrices[IGNORE_PD][MF_RESULT][i] = DS_3D_CS;
        attack_matrices[IGNORE_PD][MS_RESULT][i] = DS_4D_CS;
        attack_matrices[IGNORE_PD][CS_RESULT][i] = DS_5D_CS;
    }



    /**
     *  Grapple Attack tables // TODO
     */
    // Counterstrike
    // Attacker CF
    attack_matrices[COUNTERSTRIKE_GD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[COUNTERSTRIKE_GD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[COUNTERSTRIKE_GD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[COUNTERSTRIKE_GD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[COUNTERSTRIKE_GD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_GD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERSTRIKE_GD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[COUNTERSTRIKE_GD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[COUNTERSTRIKE_GD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[COUNTERSTRIKE_GD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_GD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[COUNTERSTRIKE_GD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[COUNTERSTRIKE_GD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[COUNTERSTRIKE_GD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[COUNTERSTRIKE_GD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[COUNTERSTRIKE_GD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Dodge
    // Attacker CF
    attack_matrices[DODGE_GD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[DODGE_GD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    attack_matrices[DODGE_GD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[DODGE_GD][CF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MF
    attack_matrices[DODGE_GD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_GD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[DODGE_GD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[DODGE_GD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[DODGE_GD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[DODGE_GD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_GD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[DODGE_GD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[DODGE_GD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[DODGE_GD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[DODGE_GD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[DODGE_GD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Grapple
    // Attacker CF
    attack_matrices[GRAPPLE_GD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[GRAPPLE_GD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[GRAPPLE_GD][CF_RESULT][MS_RESULT] = DSK_2D_CS;
    attack_matrices[GRAPPLE_GD][CF_RESULT][CS_RESULT] = DSK_3D_CS;
    // Attacker MF
    attack_matrices[GRAPPLE_GD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[GRAPPLE_GD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[GRAPPLE_GD][MF_RESULT][MS_RESULT] = DSK_1D_CS;
    attack_matrices[GRAPPLE_GD][MF_RESULT][CS_RESULT] = DSK_2D_CS;
    // Attacker MS
    attack_matrices[GRAPPLE_GD][MS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[GRAPPLE_GD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[GRAPPLE_GD][MS_RESULT][MS_RESULT] = BF_3D_CS;
    attack_matrices[GRAPPLE_GD][MS_RESULT][CS_RESULT] = DSK_1D_CS;
    // Attacker CS
    attack_matrices[GRAPPLE_GD][CS_RESULT][CF_RESULT] = DF_6D_CS;
    attack_matrices[GRAPPLE_GD][CS_RESULT][MF_RESULT] = DF_5D_CS;
    attack_matrices[GRAPPLE_GD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[GRAPPLE_GD][CS_RESULT][CS_RESULT] = BF_1D_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        attack_matrices[IGNORE_GD][CF_RESULT][i] = DTA_CS;
        attack_matrices[IGNORE_GD][MF_RESULT][i] = DS_3D_CS;
        attack_matrices[IGNORE_GD][MS_RESULT][i] = DS_4D_CS;
        attack_matrices[IGNORE_GD][CS_RESULT][i] = DS_5D_CS;
    }

    /**
     *  Missile Attack tables // TODO
     */
    // Block
    // Attacker CF
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_BLOCK_DD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[SHIELD_BLOCK_DD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[SHIELD_BLOCK_DD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[SHIELD_BLOCK_DD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    // Dodge
    // Attacker CF
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MF_RESULT] = BF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][MS_RESULT] = AF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CF_RESULT][CS_RESULT] = AF_3D_CS;
    // Attacker MF
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[WEAPON_PARRY_DD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[WEAPON_PARRY_DD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[WEAPON_PARRY_DD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    //Ignore
    for (int i = 0; i <  UNKNOWN_RESULT; i++)
    {
        // Attacker Result rool - Defender ignore, no result required/ignored
        attack_matrices[IGNORE_DD][CF_RESULT][i] = DTA_CS;
        attack_matrices[IGNORE_DD][MF_RESULT][i] = DS_3D_CS;
        attack_matrices[IGNORE_DD][MS_RESULT][i] = DS_4D_CS;
        attack_matrices[IGNORE_DD][CS_RESULT][i] = DS_5D_CS;
    }

    /**
     *  Engage Initiative table// TODO
     */
    // Block
    // Attacker CF
    attack_matrices[INITIATIVE_ID][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[INITIATIVE_ID][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[INITIATIVE_ID][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[INITIATIVE_ID][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[INITIATIVE_ID][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[INITIATIVE_ID][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[INITIATIVE_ID][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[INITIATIVE_ID][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[INITIATIVE_ID][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[INITIATIVE_ID][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[INITIATIVE_ID][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[INITIATIVE_ID][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[INITIATIVE_ID][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[INITIATIVE_ID][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[INITIATIVE_ID][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[INITIATIVE_ID][CS_RESULT][CS_RESULT] = BLOCK_CS;

    /**
     *  Jousting table// TODO
     */
    // Block
    // Attacker CF
    attack_matrices[JPUSTING_JD][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[JPUSTING_JD][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[JPUSTING_JD][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[JPUSTING_JD][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[JPUSTING_JD][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[JPUSTING_JD][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[JPUSTING_JD][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[JPUSTING_JD][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[JPUSTING_JD][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[JPUSTING_JD][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[JPUSTING_JD][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[JPUSTING_JD][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[JPUSTING_JD][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[JPUSTING_JD][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[JPUSTING_JD][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[JPUSTING_JD][CS_RESULT][CS_RESULT] = BLOCK_CS;

    /**
     *  Mental conflict table// TODO
     */
    // Block
    // Attacker CF
    attack_matrices[MENTAL_CONFLICT_MED][CF_RESULT][CF_RESULT] = BF_3D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CF_RESULT][MF_RESULT] = AF_3D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MF
    attack_matrices[MENTAL_CONFLICT_MED][MF_RESULT][CF_RESULT] = DF_3D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MF_RESULT][MF_RESULT] = BLOCK_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MF_RESULT][MS_RESULT] = DTA_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MF_RESULT][CS_RESULT] = DTA_CS;
    // Attacker MS
    attack_matrices[MENTAL_CONFLICT_MED][MS_RESULT][CF_RESULT] = DF_4D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MS_RESULT][MF_RESULT] = DF_3D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MS_RESULT][MS_RESULT] = BLOCK_CS;
    attack_matrices[MENTAL_CONFLICT_MED][MS_RESULT][CS_RESULT] = DTA_CS;
    // Attacker CS
    attack_matrices[MENTAL_CONFLICT_MED][CS_RESULT][CF_RESULT] = DF_5D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CS_RESULT][MF_RESULT] = DF_4D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CS_RESULT][MS_RESULT] = DF_3D_CS;
    attack_matrices[MENTAL_CONFLICT_MED][CS_RESULT][CS_RESULT] = BLOCK_CS;
}
