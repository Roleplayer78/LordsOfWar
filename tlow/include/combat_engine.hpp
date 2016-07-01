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

#ifndef COMBAT_ENGINE_HPP
#define COMBAT_ENGINE_HPP

#include "engine_defs.hpp"
#include "dice.hpp"


/**
 *  CombatEngine
 *
 *  This singleton class is responsible for carry on all the combat
 *  needs
 */
class CombatEngine {

public:

    static CombatEngine * getCombatEngine()
    {
        if (m_this == NULL)
        {
            m_this = new CombatEngine();
        }

        return m_this;
    }

    // Melee attack
    eCombatResult ResolveAttack(Creature &attacker, Creature &defender,
            eAttackType attack, eMeleeDefence defence,
            std::uint16_t attacker_num, Effect &effect);

    // Disarm attack
    eCombatResult ResolveAttack(Creature &attacker, Creature &defender,
            eAttackType attack, eDisarmDefence defence,
            std::uint16_t attacker_num, Effect &effect);

    // Press attack
    eCombatResult ResolveAttack(Creature &attacker, Creature &defender,
            eAttackType attack, ePressDefence defence,
            std::uint16_t attacker_num, Effect &effect);

    // Grapple attack
    eCombatResult ResolveAttack(Creature &attacker, Creature &defender,
            eAttackType attack, eGrappleDefence defence,
            std::uint16_t attacker_num, Effect &effect);

    // Missile attack
    eCombatResult ResolveAttack(Creature &attacker, Creature &defender,
            eAttackType attack, eMissileDefence defence,
            std::uint16_t attacker_num, Effect &effect);


    // Special attacks
    // Jousting
    eCombatResult JoustingAttack(Creature &attacker, Creature &defender,
            std::uint16_t attacker_num, Effect &effect);

    // Mental conflict
    eCombatResult MentalAttack(Creature &attacker, Creature &defender,
            std::uint16_t attacker_num, Effect &effect);

    // Initiative - first engagment
    eCombatResult InitiativeAttack(Creature &attacker, Creature &defender,
            std::uint16_t attacker_num, Effect &effect);


private:
    // Private construtor: the CombatEngine is never directly instantiated
    CombatEngine();

    // Singleton pointer
    static CombatEngine *m_this;
};

#endif // COMBAT_ENGINE_HPP
