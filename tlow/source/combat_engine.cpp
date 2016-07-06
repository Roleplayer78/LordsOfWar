
#include "tlow_defs.hpp"
#include "creature/creature.hpp"
#include "creature/player.hpp"
#include "engine/engine_types.hpp"
#include "engine/combat_engine.hpp"


// Initialize singleton pointer
CombatEngine * CombatEngine::m_this = NULL;

// Melee attack
eCombatResult CombatEngine::ResolveAttack(Creature &attacker, Creature &defender,
        eAttackType attack, eMeleeDefence defence,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Disarm attack
eCombatResult CombatEngine::ResolveAttack(Creature &attacker, Creature &defender,
        eAttackType attack, eDisarmDefence defence,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Press attack
eCombatResult CombatEngine::ResolveAttack(Creature &attacker, Creature &defender,
        eAttackType attack, ePressDefence defence,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Grapple attack
eCombatResult CombatEngine::ResolveAttack(Creature &attacker, Creature &defender,
        eAttackType attack, eGrappleDefence defence,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Missile attack
eCombatResult CombatEngine::ResolveAttack(Creature &attacker, Creature &defender,
        eAttackType attack, eMissileDefence defence,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}


// Special attacks
// Jousting
eCombatResult CombatEngine::JoustingAttack(Creature &attacker, Creature &defender,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Mental conflict
eCombatResult CombatEngine::MentalAttack(Creature &attacker, Creature &defender,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}

// Initiative - first engagment
eCombatResult CombatEngine::InitiativeAttack(Creature &attacker, Creature &defender,
        std::uint16_t attacker_num, Effect &effect)
{
    eCombatResult cr = UNKNOWN_CS;

    return cr;
}
