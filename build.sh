#!/bin/bash

g++ main.cpp Player.cpp Enemy.cpp Math.cpp FrameRate.cpp\
  -I/opt/sfml2/include \
  -L/opt/sfml2/lib \
  -Wl,-rpath,/opt/sfml2/lib \
  -lsfml-graphics \
  -lsfml-window \
  -lsfml-system \
  -o main

