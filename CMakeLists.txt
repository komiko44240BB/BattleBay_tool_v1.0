cmake_minimum_required(VERSION 3.25.1)
project(BattleBay_tool C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
find_library(XLSXWRITER xlsxwriter)

include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${XLSXWRITER_INCLUDE_DIRS})


link_directories(${GTK3_LIBRARY_DIRS})
link_directories(${XLSXWRITER_LIBRARY_DIRS})



add_executable(BattleBay_tool
        main.c
        menu.c
        objects.c
        perks.c
        readobjects.c
        ships.c
        readtraining.c
        clear_input.c
        #scriptspy/perks_.c
)

include_directories("/usr/local/include/xlsxio")

link_directories("/usr/local/lib")

target_link_libraries(BattleBay_tool ${GTK3_LIBRARIES} /usr/local/lib/libxlsxio_write.so /usr/local/lib/libxlsxio_read.so)