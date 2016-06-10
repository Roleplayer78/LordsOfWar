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
 * File:   entity.hpp
 * Author: broken
 *
 * Created on 10 June 2016, 19:38
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
/**
 * Template class entity
 * 
 * This class will hold all the basic operation that an entity can have.
 * All entity will share some basic parameters, be creatures, objects, environments
 * etc.
 * 
 */

template <typename T>
class Entity
{
    public:
        Entity();

        void SetDamageStatus(bool status) { m_canBeDamaged = status; }
        bool GetDamageStatus() { return m_canBeDamaged; }
        
        void SetDestroyStatus(bool status) { m_canBeDamaged = status; }
        bool GetDestroyStatus() { return m_canBeDamaged; }
        
        void SetMoveStatus(bool status) { m_canBeDamaged = status; }
        bool GetMoveStatus() { return m_canBeDamaged; }
        
        void SetPassableStatus(bool status) { m_canBeDamaged = status; }
        bool GetPassableStatus() { return m_canBeDamaged; }
        
        void SetVisibleStatus(bool status) { m_canBeDamaged = status; }
        bool GetVisibleStatus() { return m_canBeDamaged; }
        
        void SetPosX(bool status) { m_canBeDamaged = status; }
        bool GetPosX() { return m_canBeDamaged; }
        
        void SetPosY(bool status) { m_canBeDamaged = status; }
        bool GetPosY() { return m_canBeDamaged; }
        
        void SetPosZ(bool status) { m_canBeDamaged = status; }
        bool GetPosZ() { return m_canBeDamaged; }
        
        void SetIconPath(char * path) 
        { 
            m_IconPath = path;
        }
        void GetIconPath(std::string & path) { path = m_IconPath; }
        
    private:
        bool m_canBeDamaged;
        bool m_canBeDestroied;
        bool m_canMove;
        bool m_isPassable;
        bool m_isVisible;
        unsigned int posX;  // 0,0 is the origin
        unsigned int posY; // 0,0 is the origin
        int posZ; // negative is below ground
        std::string  m_IconPath; // Path to graphical resource
            
};

#endif /* ENTITY_HPP */

