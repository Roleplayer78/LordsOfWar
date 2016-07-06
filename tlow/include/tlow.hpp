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
 * File:   tlow.hpp
 * Author: broken
 *
 * Created on 07 June 2016, 22:32
 */

#ifndef _TLOW_HPP
#define _TLOW_HPP

#include <SFGUI/SFGUI.hpp>

// TODO make all this parameters
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 768;
const char TITLE[] = "The Lords of War: The medieval fighting simulator";

#define UNUSED_VAR(x) (void)x;

class MainWindow
{

public:

    MainWindow(): m_title(NULL), m_screen_width(0), m_screen_height(0),
                  m_render(NULL), m_sfgui(NULL) {};

    // Allocate the main window and renderer - singleton
    sf::RenderWindow * Init(const int screen_width, const int screen_height,
                                             const char *title);

    sf::RenderWindow *  GetRender() { return m_render; }
    sfg::SFGUI *  GetGui()    { return m_sfgui; }

private:

    // Allocate render context, main window and start game loop
    void CreateWindow();

    std::string *m_title;
    int m_screen_width;
    int m_screen_height;

    sf::RenderWindow * m_render;
    sfg::SFGUI * m_sfgui;

};


#endif
