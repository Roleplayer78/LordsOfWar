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

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

#include <SFML/Graphics.hpp>

#include "ui.hpp"

    
UI::UI(std::shared_ptr<sfg::Desktop> desktop, const sf::Vector2u & render_size) :
    m_render_size(0,0), m_root_box(NULL), m_window1(NULL), m_window2(NULL),
    m_window3(NULL), m_pstats_notebook(NULL), 
    m_action_table(NULL), m_dice_table(NULL), m_desktop(NULL)
{
    m_render_size.x = render_size.x;
    m_render_size.y = render_size.y;
    
    m_desktop = desktop;
    
    m_root_box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 20.f);
    m_root_box->SetId("RootBox");
    
    m_desktop->SetProperties(
            ".Window {"
            "	BackgroundColor: #BBBB0055;"
            "   BorderColor: #000000FF;"
            "   FontName: ../data/font.otf;"
            "   BorderWidth: 1.0f;"
            "ShadowAlpha: 30.0f;"
            "ShadowAlpha: 2.0f;"
            "}"
            ".tlow {"
            "	FontName: ../data/font.otf;"
            "}"
            "#pstats {"
            "   BackgroundColor: #0000aa22;"
            "}"
            "#action > label{"
            "   background-color: #aa0000;"
            "}"
            "#dice > label {"
            "   background-color: #00aa00;"
            "}"
    );
    
    m_window1 = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
    m_window1->SetClass("Window");
    m_window1->SetTitle("Player Stats");
    m_window1->SetPosition(sf::Vector2f(.0f, .0f));
    m_window1->SetRequisition(sf::Vector2f(m_render_size.x * PSTATS_W, m_render_size.y * PSTATS_H));
    
    m_window2 = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
    m_window2->SetClass("Window");
    m_window2->SetTitle("Combat");
    m_window2->SetPosition(sf::Vector2f(m_render_size.x * PSTATS_W, .0f));
    m_window2->SetRequisition(sf::Vector2f(m_render_size.x * ACTION_W, m_render_size.y * ACTION_H));
    
    m_window3 = sfg::Window::Create(sfg::Window::Style::TITLEBAR | sfg::Window::Style::BACKGROUND);
    m_window3->SetClass("Window");
    m_window3->SetTitle("Dice Roller");
    m_window3->SetPosition(sf::Vector2f(m_render_size.x * PSTATS_W, m_render_size.y * ACTION_H));
    m_window3->SetRequisition(sf::Vector2f(m_render_size.x * DICE_W, m_render_size.y * DICE_H));

    m_desktop->Add( m_window1 );
    m_desktop->Add( m_window2 );
    m_desktop->Add( m_window3 );
}

void UI::CreateStatsSection()
{
    
    m_pstats_notebook = sfg::Notebook::Create();
    m_pstats_notebook->SetClass("tlow");
    m_pstats_notebook->SetId("pstats");

    m_pstats_notebook->AppendPage( sfg::Label::Create(), sfg::Label::Create( "Stats" ) );
    m_pstats_notebook->AppendPage( sfg::Label::Create(), sfg::Label::Create( "Skills" ) );
    m_pstats_notebook->AppendPage( sfg::Label::Create(), sfg::Label::Create( "Armour" ) );
    m_pstats_notebook->AppendPage( sfg::Label::Create(), sfg::Label::Create( "Equipment" ) );
    m_pstats_notebook->AppendPage( sfg::Label::Create(), sfg::Label::Create( "Physical status" ) );

    m_pstats_notebook->SetScrollable( true );
    m_pstats_notebook->SetPosition(sf::Vector2f(.0f, .0f));
    
    auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
    box->Pack(m_pstats_notebook, true, true);
    m_window1->Add(box);
}

void UI::CreateActionSection()
{
    m_action_table = sfg::Table::Create();
    m_action_table->SetClass("tlow");
    m_action_table->SetId("action");

    auto box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
    box->Pack(m_action_table, true, true);
    m_window2->Add(box);
}

void UI::CreateDiceSection()
{
    m_dice_table = sfg::Table::Create();
    m_dice_table->SetClass("tlow");
    m_dice_table->SetId("dice");
    m_dice_table->SetPosition(sf::Vector2f(m_render_size.x * DICE_W, m_render_size.y * DICE_H));
    
    auto box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
    box->Pack(m_dice_table, true, true);
    m_window3->Add(box);
    
}