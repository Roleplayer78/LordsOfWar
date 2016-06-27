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

#ifndef ENGINE_DEFS_HPP
#define ENGINE_DEFS_HPP

/* Base game engine definition
 * This should be changed ONLY if you know what you are doing.
 *
 * Changing only 1 of them means that probably you are breaking the
 * game system for good.
 */

const std::uint16_t STAT_LEVEL = 1; // This injuries and fatigue levels when rolling a stat on 3d6
const std::uint16_t SKILL_LEVEL = 5; 	// Each level of Injury / Fatigue is multiplied by this - 5%
							// This must be in accordance to the SKILL DIE 1d100

const std::uint16_t MAX_SKILL = 100; // Max skill is SB + MAX_SKILL. This is computed runtime

const std::uint16_t CRITICAL_ROLL = 5;	// This means tha every roll divisible
										// by this number is a critical: 5, 10, 15, ecc
										// If => to SML is a critical success
										// if <= to SML is a critical failure

// This simple function will check if the roll is a critical success or not:
// If the roll is divisible by CRITICAL_ROLL is critical (success/failure) otherwise not
const inline bool is_critical (std::uint16_t roll) { if ( !(roll % CRITICAL_ROLL)) return true; else return false; }

typedef enum
{
	D2,
	D3,
	D4,
	D6,
	D8,
	D10,
	D12,
	D20,
	D30,
	D100,
	D_NONE
} eDiceType;

typedef enum
{
	CF_RESULT = 0,	// Critical Failure
	MF_RESULT,		// Medium Failure
	MS_RESULT,		// Medium Success
	CS_RESULT,		// Critical Success
	UNKNOWN_RESULT
} eResultType;

#endif // ENGINE_DEFS_HPP
