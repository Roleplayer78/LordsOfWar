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
 * File:   ui.hpp
 * Author: broken
 *
 * Created on 07 June 2016, 18:06
 */

/***
 * General screen layout
 * For Action are and Dice area, The enemy section has been made part of a
 * bigger one to make it easier to hide/show it based on game status and
 * situations (there could be no fighting).
+----+----+----+----+--------------------------------+------+-----+----+----+
|    |    |    |    |                                |      |     |    |    |
|    |    |    |    |                  General Combat|Area  | 20% |    |    |
|  20|    |    |    | Player                         +------+-----+----+----+
+----+----+----+----+                                |  Enemies             |
|                   | * Weapon selections            |                      |
| Tabbed area:      | * Weapon status                |  * Weapon selection  |
| * Stats           | * Manoeuvre selection          |  * Weapon status     |
| * Skills          | * Action outcomes              |    (new/damaged/ecc) |
| * Armours         |                                |  * Manouvre selection|
| * Equipment       |                                |  * Action outcomes   |
| * Physical status |                                |                      |
|                   |                                |                      |
|                   |                                |                      |
|                   |                                |                      |
| Name: PStats      | Name (father): Action          |                      |
|                   | Name (player):PActtion         | Name (enemy): EAction|
|                   | Size: 40% / 70%                | Size: 30% / 70%      |
|                   +--------------------------------+----------------------+
|                   | Dice area: roll dice and  dice |outcome               |
|                   | Name (father): Dice            |                      |
|                   | Name (Player): PDice           | Name (Enemy): EDice  |
|Size: 30% / 80%    | Size: 40% / 30%                | Size: 30% / 30%      |
+-------------------+--------------------------------+----------------------+
*/

#ifndef UI_HPP
#define UI_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFGUI/Box.hpp>
#include <SFGUI/Notebook.hpp>
#include <SFGUI/Desktop.hpp>
#include <SFGUI/Table.hpp>

const int TAB_H = 15.0f; // Height of tabs. Generic

// Stats section
const float PSTATS_W = .30f;
const float PSTATS_H = 1.f;


// Action section
const float ACTION_W = .70f;
const float ACTION_H = .70f;
const float PACTION_W = .40f;
const float PACTION_H = .30f;
const float EACTION_W = .30f;
const float EACTION_H = .70f;

// Dice section
const float DICE_W = .70f;
const float DICE_H = .30f;
const float PDICE_W = .40f;
const float PDICE_H = .30f;
const float EDICE_W = .30f;
const float EDICE_H = .30f;

class UI
{
public:
    UI(std::shared_ptr<sfg::Desktop> desktop, const sf::Vector2u & render_size);
    
    void CreateStatsSection();
    void CreateActionSection();
    void CreateDiceSection();
    
private:
    sf::Vector2u m_render_size;
    sfg::Box::Ptr m_root_box;
    
    sfg::Window::Ptr m_window1;
    sfg::Window::Ptr m_window2;
    sfg::Window::Ptr m_window3;
    
    sfg::Notebook::Ptr m_pstats_notebook; // Player STATS area
    
    sfg::Table::Ptr m_action_table;
    sfg::Table::Ptr m_dice_table;
   
    std::shared_ptr<sfg::Desktop> m_desktop;
};



#endif /* UI_HPP */

