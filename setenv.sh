#!/bin/bash

###############################################################################
## Set building environment
## Lords of War - SFML
###############################################################################

export PROJECT_ROOT=$PWD
export SFML_ROOT=$PROJECT_ROOT/SFML
export SFGUI_ROOT=$PROJECT_ROOT/SFGUI
export LUA_ROOT=$PROJECT_ROOT/lua
export TILED_ROOT=$PROJECT_ROOT/tiled
export DATA_ROOT=$PROJECT_ROOT/data

case $1 in
    examples)
        cd $SFML_ROOT/examples
        cmake -G "Unix Makefiles"
        make

        cd $SFGUI_ROOT/examples
        make
        ;;
    clean)
        # This command will clean the Projects and bring it to a pushable
        # state: remove even generated Makefiles etc.
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
        qmake
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
        cd $PROJECT_ROOT
        if [ ! -h ./lua ]; then
            ln -s lua* lua
        fi
        cd $LUA_ROOT
        make linux
      
        cd $DATA_ROOT
        ./setdata.sh
        ;;
esac


