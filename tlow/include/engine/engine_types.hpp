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
 * File:   entity_stats.hpp
 * Author: broken
 *
 * Created on 15 June 2016, 11:04
 */

#ifndef ENGINE_TYPES_HPP
#define ENGINE_TYPES_HPP

#include <cinttypes>
#include <stdlib.h>

/*
 * Base game engine definition
 * This should be changed ONLY if you know what you are doing.
 *
 * Changing only 1 of them means that probably you are breaking the
 * game system for good.
 */

typedef enum
{
    D2 = 2,
    D3 = 3,
    D4 = 4,
    D6 = 6,
    D8 = 8,
    D10 = 10,
    D12 = 12,
    D20 = 20,
    D30 = 30,
    D100= 100,
    D_NONE
} eDiceType;

typedef enum
{
    CF_RESULT = 0,  // Critical Failure
    MF_RESULT,      // Medium Failure
    MS_RESULT,      // Medium Success
    CS_RESULT,      // Critical Success
    UNKNOWN_RESULT
} eRollResult;

const std::uint16_t STAT_LEVEL = 1; // This injuries and fatigue levels when rolling a stat on 3d6
const std::uint16_t SKILL_LEVEL = 5;    // Each level of Injury / Fatigue is multiplied by this - 5%
                            // This must be in accordance to the SKILL DIE 1d100

const std::uint16_t MAX_SKILL = 100; // Max skill is SB + MAX_SKILL. This is computed runtime

const std::uint16_t CRITICAL_ROLL = 5;  // This means tha every roll divisible
                                        // by this number is a critical: 5, 10, 15, ecc
                                        // If => to SML is a critical success
                                        // if <= to SML is a critical failure

// This simple function will check if the roll is a critical success or not:
// If the roll is divisible by CRITICAL_ROLL is critical (success/failure) otherwise not
inline const bool is_critical (std::uint16_t roll) { if ( !(roll % CRITICAL_ROLL)) return true; else return false; }

inline const std::uint16_t roll(eDiceType die) { return (rand() % die); }

typedef enum
{
    // Normal attack (multi table)
    MELEE_ATTACK = 0,
    DISARM_ATTACK,
    PRESS_ATTACK,
    GRAPPLE_ATTACK,
    MISSILE_ATTACK,
    // Special, single table, attack
    JOUSTING_ATTACK,
    MENTAL_ATTACK,
    INITIATIVE_ATACK,   // Determine first-engagment initiative
    UNKNOWN_ATTACK
} eAttackType;

typedef enum
{
    /* A = Attacker
     * D = Defender
     * B = Both
     * 1,2,3,4,5 = Dice rolled
     */

    // Attacker Strikes (damage)
    ASK_1D_CS = 0,
    ASK_2D_CS,
    ASK_3D_CS,
    ASK_4D_CS,
    // Defender Strikes (damage)
    DSK_1D_CS,
    DSK_2D_CS,
    DSK_3D_CS,
    DSK_4D_CS,
    // Both Strikes (damage)
    BSK_1D_CS,
    BSK_2D_CS,
    BSK_3D_CS,
    // Attacker Fumble (drop weapon/object)
    AF_1D_CS,
    AF_2D_CS,
    AF_3D_CS,
    AF_4D_CS,
    AF_5D_CS,
    // Defender Fumble (drop weapon/object)
    DF_1D_CS,
    DF_2D_CS,
    DF_3D_CS,
    DF_4D_CS,
    DF_5D_CS,
    DF_6D_CS,
    // Both Fumble (drop weapon/object)
    BF_1D_CS,
    BF_2D_CS,
    BF_3D_CS,
    BF_4D_CS,
    BF_5D_CS,
    // Attacker Stumble (fall down)
    AS_1D_CS,
    AS_2D_CS,
    AS_3D_CS,
    AS_4D_CS,
    AS_5D_CS,
    // Defender Stumble (fall down)
    DS_1D_CS,
    DS_2D_CS,
    DS_3D_CS,
    DS_4D_CS,
    DS_5D_CS,
    // Both Stumble (fall down)
    BS_1D_CS,
    BS_2D_CS,
    BS_3D_CS,
    BS_4D_CS,
    BS_5D_CS,
    PARRY_CS,  // Weapon quality roll (-2) / less chance of damage
    BLOCK_CS,  // Weapon damage roll
    DTA_CS,    // Defender tactical advantage (gain a new action)
    AHOLD_CS,  // Attacker obtain hold of defender (Grip)
    DHOLD_CS,  // Defender obtain hold of attacker (Grip)
    NHOLD_CS,  // Both obtain hold (locked in wrestling)
    // Missile strike (damage)
    M_1D_CS,
    M_2D_CS,
    M_3D_CS,
    WILD_CS,   // Random hit (nearby creature) or Weapon quality roll
    MISS_CS,   // Standoff / Miss
    // Steed strike (strike to steed, if not specifically targeted)
    S_1D_CS,
    S_2D_CS,
    S_3D_CS,
    S_4D_CS,
    S_5D_CS,
    UNKNOWN_CS  // Unknown Combat Result
} eCombatResult;

typedef enum
{
    SHIELD_2W_BLOCK_MD = 0,
    WEAPON_PARRY_MD,
    COUNTERSTRIKE_MD,
    DODGE_MD,
    GRAPPLE_MD,
    DISARM_MD,
    IGNORE_MD,
    UNKOWN_MD
} eMeleeDefence;

typedef enum
{
    SHIELD_BLOCK_DD = 0,
    WEAPON_PARRY_DD,
    COUNTERSTRIKE_DD,
    DISARM_DD,
    IGNORE_DD,
    UNKOWN_DD
} eDisarmDefence;

typedef enum
{
    COUNTERPRESS_PD = 0,
    COUNTERSTRIKE_PD,
    DODGE_PD,
    IGNORE_PD,
    UNKOWN_PD
} ePressDefence;

typedef enum
{
    COUNTERSTRIKE_GD = 0,
    DODGE_GD,
    GRAPPLE_GD,
    IGNORE_GD,
    UNKOWN_GD
} eGrappleDefence;

typedef enum
{
    DODGE_MSD = 0,
    BLOCK_MSD,
    IGNORE_MSD,
    UNKOWN_MSD
} eMissileDefence;

typedef enum
{
    INITIATIVE_ID = 0,
    UNKOWN_ID
} eInitiativeDefence;

typedef enum
{
    JPUSTING_JD = 0,
    UNKOWN_JD
} eJoustingDefence;

typedef enum
{
    MENTAL_CONFLICT_MED = 0,
    UNKOWN_MED
} eMentalDefence;

#endif // ENGINE_TYPES_HPP
