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

// SFML includes
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>

// Project includes
#include "tlow_defs.hpp"
#include "engine/main_loop.hpp"
#include "engine/game_engine_tables.hpp"
#include "ui/ui.hpp"

void MainLoop::CreateLayout()
{
    m_UserInterface->CreateStatsSection();
    m_UserInterface->CreateActionSection();
    m_UserInterface->CreateDiceSection();
}

void MainLoop::InitGameEngine()
{
    InitializeSkillTable();
    InitializeCombatTables();

}

int MainLoop::Run()
{
    // Setting up user interface
    CreateLayout();

    // Start the game loop
    while ( m_render->isOpen() ) {
            // Process events
            sf::Event event;

            while ( m_render->pollEvent( event ) ) {
                    // Every frame we have to send SFML events to the window
                    // to enable user interactivity. Without doing this your
                    // GUI is nothing but a big colorful picture ;)
                    m_desktop->HandleEvent( event );

                    // Close window : exit
                    if ( event.type == sf::Event::Closed ) {
                            m_render->close();
                    }
            }

            // Update the GUI, note that you shouldn't normally
            // pass 0 seconds to the update method.
            m_desktop->Update( 0.01f );

            // Clear screen
            m_render->clear();

            // After drawing the rest of your game, you have to let the GUI
            // render itself. If you don't do this you will never be able
            // to see it ;)
            m_sfgui->Display( *m_render );

            // NOTICE
            // Because the window doesn't have any children it will shrink to
            // it's minimum size of (0,0) resulting in you not seeing anything
            // except the title bar text ;) Don't worry, in the Label example
            // you'll get to see more.

            // Update the window
            m_render->display();
    }

    return STATUS_EXIT;
}
