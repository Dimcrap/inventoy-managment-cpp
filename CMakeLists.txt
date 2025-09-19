cmake_minimum_required(VERSION 3.12)
project(TMobileInventory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check if we have SQLite source files
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/datas/sqlite3.c" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/datas/sqlite3.h")
    message(STATUS "Using bundled SQLite3 from project files")
    
    # Compile SQLite as C code first
    add_library(sqlite3_lib STATIC datas/sqlite3.c)
    target_include_directories(sqlite3_lib PUBLIC datas)
    
    # Set C compiler flags for SQLite
    set_target_properties(sqlite3_lib PROPERTIES
        C_STANDARD 99
        C_EXTENSIONS OFF
    )
    
    add_executable(TMobileInventory
        main.cpp
        datas/DatabaseHandler.cpp
    )
    
    target_include_directories(TMobileInventory PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/datas
    )
    
    # Link against our SQLite library
    target_link_libraries(TMobileInventory PRIVATE sqlite3_lib)
    
else()
    message(FATAL_ERROR "SQLite3 source files not found")
endif()

# Copy database file
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/datas/alldatas.db
    ${CMAKE_CURRENT_BINARY_DIR}/datas/alldatas.db
    COPYONLY
)

# Set output directory
set_target_properties(TMobileInventory PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# Suppress warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TMobileInventory PRIVATE -Wno-reorder -Wno-unused-parameter)
endif()

message(STATUS "Project configured with bundled SQLite3")