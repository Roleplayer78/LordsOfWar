#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

// SFML includes
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>

// Project includes
#include "tlow_defs.hpp"
#include "tlow.hpp"
#include "main_loop.hpp"



int main (int argc, char *argv[])
{
    MainWindow window;
    
    
    if (window.Init(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE) != NULL)
    {
        MainLoop ml(window.GetRender(), window.GetWindow(), window.GetGui());
        ml.Run();
    }

    exit (tlow::SUCCESS);
}

sf::RenderWindow * MainWindow::Init(const int screen_width, const int screen_height,
                                             const char *title)
{

    if (m_render == NULL)
    {
        try
        {
            m_screen_height = screen_height;
            m_screen_width = screen_width;
            m_title = new std::string(title);

            CreateWindow();
        }
        catch( ... )
        {
            std::cerr << "%s: aborted - can't create main window." << TITLE << std::endl;
        }

    }
    
    return m_render;
}

void MainWindow::CreateWindow()                       
{
    // Create SFML's window.
    if ((m_render = new sf::RenderWindow( sf::VideoMode( m_screen_width, m_screen_height ), *m_title,
                                      sf::Style::Titlebar | sf::Style::Close )) != NULL)
    {
	// We have to do this because we don't use SFML to draw.
	m_render->resetGLStates();

	// Create an SFGUI. This is required before doing anything with SFGUI.
	m_sfgui = new sfg::SFGUI;

	// Create our main SFGUI window

	// Almost everything in SFGUI is handled through smart pointers
	// for automatic resource management purposes. You create them
	// and they will automatically be destroyed when the time comes.

	// Creation of widgets is always done with it's Create() method
	// which will return a smart pointer owning the new widget.
	m_window = sfg::Window::Create(sfg::Window::BACKGROUND);

	// Here we can set the window's title bar text.
	m_window->SetTitle( "A really really really really long title" );
    }
}
