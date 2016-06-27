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

eResultType Dice::SkillRoll(eDiceType die, std::uint16_t num_dice, eSkills skill, Creature & creature)
{
	eResultType rc = eResultType::UNKNOWN_RESULT;
	std::uint16_t roll = 0;
	std::uint16_t sml = 0;
	
	roll = Roll(die, num_dice);
	sml = creature.GetSkill(skill);

	// Medium Success
	if (roll < sml)
	{
		if ((roll % CRITICAL_ROLL) == 0)
		{
			rc = eResultType::CS_RESULT;
		}
		else
		{
			rc = eResultType::MS_RESULT;
		}
	}
	else // Medium Failure
	{
		if ((roll % CRITICAL_ROLL) == 0)
		{
			rc = eResultType::CF_RESULT;
		}
		else
		{
			rc = eResultType::MF_RESULT;
		}
	}

	return rc;
}

eResultType Dice::StatRoll(eDiceType dice, std::uint16_t num_dice, Creature & creature)
{
	eResultType rc = eResultType::UNKNOWN_RESULT;

	return rc;
}

std::uint16_t Dice::Roll(eDiceType die, std::uint16_t num_dice)
{
	std::uint16_t rc = 0;

	for (int i = 0; i < num_dice; i++)
	{
		rc += rand() % die;
	}

	return rc;
}
