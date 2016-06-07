#!/bin/bash

###############################################################################
## Set building environment
## Lords of War - SFML
###############################################################################

export PROJECT_ROOT=$PWD
export SFML_ROOT=$PROJECT_ROOT/SFML
export SFGUI_ROOT=$PROJECT_ROOT/SFGUI
export LUA_ROOT=$PROJECT_ROOT/`ls -d lua*`
export TILED_ROOT=$PROJECT_ROOT/tiled

case $1 in
    examples)
        cd $SFML_ROOT/examples
        cmake -G "Unix Makefiles"
        make
        cd $SFGUI_ROOT/examples
        make
        ;;
    clean)
        cd $SFML_ROOT
        git clean -xdf

        cd $SFGUI_ROOT
        git clean -xdf

        cd $LUA_ROOT
        make clean

        cd $TILED_ROOT
        git clean -xdf
        ;;
    tiled)
        cd $TILED_ROOT
        make
        ;;
    *)
        # Configure and build SFML
        echo "Configuring and building SFML library - Linux"
        cd $SFML_ROOT
        cmake -G "Unix Makefiles"
        make

        # Configure and build SFGUI
        cd $SFGUI_ROOT
        cmake -G "Unix Makefiles"
        make

        # Compile LUA
        cd $LUA_ROOT
        make linux
      
        ;;
esac


