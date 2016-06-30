#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../SFML/lib:../SFGUI/lib

if [ "$1" = "mem" ]; then
    valgrind -v ./tlow
else
   ./tlow
fi
