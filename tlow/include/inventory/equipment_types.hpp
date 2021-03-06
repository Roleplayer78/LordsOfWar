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
 * File:   equipment_types.hpp
 * Author: broken
 *
 * Created on 07 June 2016, 22:32
 */

#include "tlow.hpp"
#include "creature/creature_stats.hpp"

#ifndef _EQUIPMENT_TYPES_HPP
#define _EQUIPMENT_TYPES_HPP

typedef enum _eArmourType {
    NO_ARMOUR = 0,
    CLOTH_ARMOUR,
    PADDED_ARMOUR,
    LEATHER_ARMOUR,
    BOILED_LEATHER_ARMOUR,
    RING_ARMOUR,
    CHAINMAIL_ARMOUR,
    IMPROVED_CHAINMAIL_ARMOUR,
    SCALE_ARMOUR,
    LAMELLAR_ARMOUR,
    PLATE_ARMOUR,
    UNKNOWN_ARMOUR
}eArmourType;

typedef struct _sArmour {
    std::array<eLocation, ALL_LOC> coverage;
    eArmourType type;
    std::array<_eDamageType, UNKNOWN_DAMAGE_TYPE> protection;
    std::uint16_t   weight;
} sArmour;


#endif // _EQUIPMENT_TYPES_HPP
