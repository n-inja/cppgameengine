@echo off
cd /d %~dp0
IF exist main.cpp (
  g++ main.cpp -Wall -lfreeglut -lopengl32 -lwinmm -lgdi32 -mwindows -std=c++11 -o Game.exe
  Game.exe
)
