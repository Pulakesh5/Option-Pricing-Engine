cmake_minimum_required(VERSION 3.10)

#Project Name
project(OptionPricingEngine)

# Set Cpp standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Add source files
set(
    SOURCES 
    src/pricing-engine/option.cpp
    main.cpp
)

#add_executable
add_executable(engine ${SOURCES})

#include directories
target_include_directories(engine PRIVATE src/pricing-engine)