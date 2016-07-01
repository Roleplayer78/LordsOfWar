#include <stdlib.h>
#include <time.h>
#include "creature.hpp"
#include "engine_defs.hpp"
#include "dice.hpp"


Dice::Dice ()
{
    // Initialize random seed
    srand(time(NULL));
}

eRollResult Dice::SkillRoll(eDiceType die, std::uint16_t num_dice, eSkills skill, Creature & creature)
{
    eRollResult rc = UNKNOWN_RESULT;
    std::uint16_t roll = 0;
    std::uint16_t sml = 0;

    roll = Roll(die, num_dice);
    sml = creature.GetSkill(skill);

    // Success
    if (roll < sml)
    {
        if (is_critical(roll))
        {
            rc = CS_RESULT;
        }
        else
        {
            rc = MS_RESULT;
        }
    }
    else // Failure
    {
        if (is_critical(roll))
        {
            rc = CF_RESULT;
        }
        else
        {
            rc = MF_RESULT;
        }
    }

    return rc;
}

eRollResult Dice::StatRoll(eDiceType dice, std::uint16_t num_dice, Creature & creature)
{
    eRollResult rc = UNKNOWN_RESULT;

    return rc;
}

std::uint16_t Dice::Roll(eDiceType die, std::uint16_t num_dice)
{
    std::uint16_t rc = 0;

    for (int i = 0; i < num_dice; i++)
    {
        rc += roll(die);
    }

    return rc;
}
