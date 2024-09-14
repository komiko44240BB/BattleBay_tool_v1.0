cmake_minimum_required(VERSION 3.25.1)
project(BattleBay_tool C)

set(CMAKE_C_STANDARD 11)

add_executable(BattleBay_tool main.c
        objects.h
        ships.h
        readobjects.h
        readtraining.h
        perks.h
        menu.h
        objects.c
        ships.c
        readobjects.c
        readtraining.c
        perks.c
        menu.c
)
