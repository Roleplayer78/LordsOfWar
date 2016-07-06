/*
 * Copyright (c) 2016, broken
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * File:   creature_stats.hpp
 * Author: broken
 *
 * Created on 15 June 2016, 11:04
 */

#ifndef CREATURE_STATS_HPP
#define CREATURE_STATS_HPP

#include <string>
#include <vector>

/**
 * Creature physical and mental attributes (statistics)
 */
typedef enum _eStats{

    // Combat Skill
    STRENGTH_STAT = 0,
    STAMINA_STAT,
    DEXTERITY_STAT,
    AGILITY_STAT,
    INTELLIGENCE_STAT,
    AURA_STAT,
    WILLPOWER_STAT,
    EYESIGHT_STAT,
    HEARING_STAT,
    SMELL_STAT,
    VOICE_STAT,
    COMELINESS_STAT,
    MORALITY_STAT,
    PIETY_STAT,
    UNKNOWN_STAT
} eStats;

typedef struct {
    std::string     name;   // Name of the stat
    std::uint16_t   value;  // Current, base value of the stat
    std::string     path;   // Path to icon
} sStat;



/**
 * Creature physical and mental skills (trainable or innate)
 */
typedef enum _eSkills{
    // Combat skills
    INITIATIVE_SKILL = 0,
    DODGE_SKILL,
    UNARMED_KILL,
    RIDING_SKILL,
    AXE_SKILL,
    BLOWGUN_SKILL,
    BOW_SKILL,
    CLUB_SKILL,
    DAGGER_SKILL,
    FLAIL_SKILL,
    NET_SKILL,
    POLEARM_SKILL,
    SHIELD_SKIL,
    SLING_SKIL,
    SPEAR_SKILL,
    SWORD_SKILL,
    WHIP_SKILL,
    CROSSBOW_SKILL,
    ENDURANCE_SKILL,    // Derived - This is only used for SB
    MOVEMENT_SKILL,     // Derived - This is only used for SB
    // Physical Skills
    CLIMBING_SKILL,
    JUMPING_SKILL,
    STEALTH_SKILL,
    THROWING_SKILL,
    ACROBATICS_SKILL,
    DANCING_SKILL,
    LEGERDMAIN_SKILL,
    SKIING_SKILL,
    SWIMMING_SKILL,

    // COMMUNICATION SKILL
    AWARENESS_SKILL,
    INTRIGUE_SKILL,
    ORATORY_SKILL,
    RHETORIC_SKILL,
    SINGING_SKILL,
    ACTING_SKILL,
    LOVECRAFT_SKILL,
    MENTAL_CONFLICT_SKILL,
    MUSICIAN_SKILL,

    // LORE/CRAFT SKILL
    AGRICOLTURE_SKILL,
    ALCHEMY_SKILL,
    ANIMALCRAFT_SKILL,
    ASTROLOGY_SKILL,
    BREWING_SKILL,
    CERAMICS_SKILL,
    COOKERY_SKILL,
    DRAWING_SKILL,
    EMBALMING_SKILL,
    ENGINEERING_SKILL,
    FISHING_SKILL,
    FLETCHING_SKILL,
    FOLKLORE_SKILL,
    FORAGING_SKILL,
    GLASSWORK_SKILL,
    HERALDRY_SKILL,
    HERBLORE_SKILL,
    HIDEWORK_SKILL,
    JEWELCRAFT_SKILL,
    LAW_SKILL,
    LOCKCRAFT_SKILL,
    MASONRY_SKILL,
    MATHEMATICS_SKILL,
    METALCRAFT_SKILL,
    MILLING_SKILL,
    MINING_SKILL,
    PERFUMERY_SKILL,
    PHYSICIAN_SKILL,
    PILOTING_SKILL,
    RUNECRAFT_SKILL,
    SEAMANSHIP_SKILL,
    SHIPWRIGHT_SKILL,
    SURVIVAL_SKILL,
    TAROTRY_SKILL,
    TEXTILCRAFT_SKILL,
    TIMBERCRAFT_SKILL,
    TRACKING_SKILL,
    TRAPPING_SKILL,
    WEAPONCRAFT_SKILL,
    WEATHERLORE_SKILL,
    WOODCRAFT_SKILL,

    // TODO ?? Psionic skills....

    // TODO ?? Religious skill...

    // TODO ?????? Magic skills .....
    UNKNOWN_SKILL
} eSkills;

/**
 * Level of wounds
 */
typedef enum _eWound{
    NO_WOUND = 0,
    MINOR_1_WOUND,
    MODERATE_2_WOUND,
    SERIOUS_3_WOUND,
    GRIEVOUS_4_WOUND,
    KILLING_WOUND,
    UNKNOWN_WOUND
} eWound;

/**
 * Wound Healing rate
 */
typedef enum _eHealingRate{
    R0_HR = 0,
    R1_HR,
    R2_HR,
    R3_HR,
    R4_HR,
    R5_HR,
    R6_HR,
    UNKNOW_HR
} eHealingRate;

/**
 * Types of wounds
 */
typedef enum _eDamageType{
    BLUNT_DAMAGE_TYPE = 0,
    EDGE_DAMAGE_TYPE,
    PUNCTURE_DAMAGE_TYPE,
    FIRE_DAMAGE_TYPE,
    UNKNOWN_DAMAGE_TYPE
} eDamageType;

typedef uint8_t     wound_days; // Days the wound is being healing
typedef bool        infected;   // If the wound is infected

/**
 * Body locations
 */
typedef enum _eLocation{
    NO_LOC = -1,
    SKULL_LOC = 0,
    FACE_LOC,
    NECK_LOC,
    SHOULDER_SX_LOC,
    SHOULDER_DX_LOC,
    UPPER_ARM_SX_LOC,
    UPPER_ARM_DX_LOC,
    ELBOW_SX_LOC,
    ELBOW_DX_LOC,
    FOREARM_SX_LOC,
    FOREARM_DX_LOC,
    HAND_SX_LOC,
    HAND_DX_LOC,
    THORAX_LOC,
    THORAX_BACK_LOC,
    ABDOMEN_LOC,
    ABDOMEN_BACK_LOC,
    HIP_LOC,
    HIP_BACK_LOC,
    GROIN_LOC,
    THIGH_SX_LOC,
    THIGH_DX_LOC,
    KNEE_SX_LOC,
    KNEE_DX_LOC,
    CALF_SX_LOC,
    CALF_DX_LOC,
    FOOT_SX_LOC,
    FOOT_DX_LOC,
    ALL_LOC,
} eLocation;

/**
 *  Penalties types: skills/stats/derivate are affected by different
 *                   types
 *  Universal : Wounds / fatigue
 *  Physical : Wounds / Fatigue / Encumbrance
 */
typedef enum {
    UNIVERSA_PENALTY = 0,   // Default - affect everything
    PHYSICAL_PENALTY,
    UNKOWN_PENALTY
} ePenaltyType;

typedef struct _sSkillDefinition{
    std::string     name;       // Name of the skill
    std::uint16_t   oml;        // Opening Mastery Level of the skill
    eStats          stat1;      // 1st stat for computing SB
    eStats          stat2;      // 2nd stat for computing SB
    eStats          stat3;      // 3rd stat for computing SB
    std::string     path;       // Path to icon
    ePenaltyType    penalty;    // What penalty influence the skill
    bool            can_increase;   // The skill can be increased through training
} sSkillDefinition;

typedef struct {
    eDamageType  type;       // Wound type B/E/P/F
    eWound      level;      // Wound severity
    wound_days  days;       // Days the wound has been treated
    eHealingRate hr;        // Healing rate
    infected    infection;  // Is this wound actually an infection
    eLocation   location;   // Location of the injury
    bool        bleeding;   // If wound is bleeding
} sWound;

#endif /* CREATURE_STATS_HPP */

