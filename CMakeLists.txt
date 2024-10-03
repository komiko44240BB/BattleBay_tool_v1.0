cmake_minimum_required(VERSION 3.25.1)
project(BattleBay_tool C)

set(CMAKE_C_STANDARD 11)

add_executable(BattleBay_tool
        main.c
        menu.c
        objects.c
        perks.c
        readobjects.c
        ships.c
        readtraining.c
        clear_input.c
)
