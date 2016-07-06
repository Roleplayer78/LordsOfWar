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
 * File:   main_loop.hpp
 * Author: broken
 *
 * Created on 07 June 2016, 22:33
 */

#ifndef MAIN_LOOP_HPP
#define MAIN_LOOP_HPP

#include "ui/ui.hpp"

class MainLoop
{
public:
    MainLoop(sf::RenderWindow *render, sfg::SFGUI * sfgui) :
        m_render(NULL), m_desktop(), m_sfgui(NULL)
    {
        m_render = render;
        m_sfgui = sfgui;
        m_desktop = std::make_shared<sfg::Desktop>();

        m_UserInterface = new UI(m_desktop, render->getSize());
    };

    // Start the game main loop
    int Run();
    void InitGameEngine();

private:

    void CreateLayout();

    sf::RenderWindow * m_render;
    std::shared_ptr<sfg::Desktop> m_desktop;
    sfg::SFGUI * m_sfgui;

    UI *m_UserInterface;

};

#endif /* MAIN_LOOP_HPP */

