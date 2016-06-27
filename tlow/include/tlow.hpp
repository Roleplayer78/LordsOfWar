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
