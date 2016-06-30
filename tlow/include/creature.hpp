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
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <list>
#include <string>
#include <unordered_map>
#include <vector>

#include "creature_stats.hpp"
#include "effect.hpp"
#include "entity.hpp"


    
class Creature : Entity {

public:

	typedef struct _sSkill {
		_sSkill(std::uint16_t ml)
		{
			mastery = ml;
		}
		std::uint16_t 	mastery;	// Mastery level of the skill (05%-100+%)
		std::uint16_t	learn_rool;	// Learn roll gained and still unused
	} sSkill;
	
    Creature (const std::string name);

    std::uint16_t GetSkill(eSkills skill);
    
private:
    std::string m_name; // Name of the creature
    // 1st = eStat enum , 2nd Stat value
    std::unordered_map<std::uint16_t, std::uint16_t> stats;
    // 1st = eSkill enum , 2nd sSkills structure
    std::unordered_map<std::uint16_t, sSkill> skills;
    
    std::vector<sWound> wounds;
    std::vector<std::uint16_t> fatigue; // Fatigue levels (1, 2, 3, ecc)
    
    
    
};

#endif // CREATURE_HPP
