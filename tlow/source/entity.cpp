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

#include "tlow.hpp"
#include "engine/entity.hpp"

Entity::Entity() :
    m_type(EntityType::TERRAIN_ENT),
    m_canBeDamaged(false),
    m_canBeDestroied(false),
    m_canMove(false),
    m_isPassable(true),
    m_isVisible(false),
    m_isActive(true),
    m_posX(0),
    m_posY(0),
    m_posZ(0),
    m_IconPath(NULL),
    m_weight(0)
{
    UNUSED_VAR(m_type)
    UNUSED_VAR(m_canBeDamaged)
    UNUSED_VAR(m_canBeDestroied)
    UNUSED_VAR(m_canMove)
    UNUSED_VAR(m_isPassable)
    UNUSED_VAR(m_isVisible)
    UNUSED_VAR(m_isActive)
    UNUSED_VAR(m_posX)
    UNUSED_VAR(m_posY)
    UNUSED_VAR(m_posZ)
    UNUSED_VAR(m_IconPath)
    UNUSED_VAR(m_weight)
}
