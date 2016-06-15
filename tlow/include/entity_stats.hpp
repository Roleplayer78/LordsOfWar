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

#ifndef ENTITY_STATS_HPP
#define ENTITY_STATS_HPP


/**
 * Creature physical and mental attributes (statistics)
 */
typedef enum {
    COMELINESS_STAT = 0,
    STRENGTH_STAT,
    STAMINA_STAT,
    DEXTERITY_STAT,
    AGILITY_STAT,
    EYESIGHT_STAT,
    HEARING_STAT,
    SMELL_STAT,
    VOICE_STAT,
    INTELLIGENCE_STAT,
    AURA_STAT,
    WILL_STAT,
    MORALITY_STAT,
    PIETY_STAT,
    INVALID_STAT
} eStats;

/**
 * Creature physical and mental skills (trainable or innate)
 */
typedef enum {
    // Combat skills
    INITIATIVE_SKILL = 0,
    SWORD_SKILL,
    UNARMED_SKILL,
    INVALID_SKILL        
} eSkills;

/**
 * Type and level of wounds
 */
typedef enum {
    NO_WOUND = 0,
    MINOR_1_WOUND,
    MODERATE_2_WOUND,
    SERIOUS_3_WOUND,
    GRIEVOUS_4_WOUND,
    KILLING_WOUND
} eWound;

typedef uint8_t     wound_days; // Days the wound is being healing
typedef bool        infected;   // If the wound is infected

typedef struct {
    eWound      severity;   // Wound severity
    wound_days  days;       // Days the wound has been treated
    infected    infection;  // Is this wound actually an infection
} sWound;



#endif /* ENTITY_STATS_HPP */

