# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.20)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

# Set target definition variables required by the toolchain file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/target.cmake)

# Set the toolchain file for cross-compilation
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/gcc-arm-none-eabi.cmake)

# Project definition
project(NUCLEO-H7S3L8)

# Enable CMake support for ASM and C/CPP languages
enable_language(C CXX ASM)

set(PROJECT_NAME NUCLEO-H7S3L8)

# Create an executable object type
add_executable(${PROJECT_NAME})

# Include additional CMake files for flags, components, and files
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/flags.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/components.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/files.cmake)

# Add sources to executable/library
target_sources(${PROJECT_NAME} PRIVATE
  Drivers/Efls/hal/Efls.c
  Drivers/Efls/drv/Efls_Drv.c
  Drivers/Efls/reg/Efls_Reg.c
  Drivers/Delay/hal/Delay.c
  Drivers/Delay/drv/Delay_Drv.c
  Drivers/Mcu/hal/Mcu.c
  Drivers/Mcu/drv/Mcu_Drv.c
  Drivers/Mcu/drv/Mcu_System.c
  Drivers/Gpio/Gpio_Pins.c
  Drivers/Port/hal/Port.c
  Drivers/Port/drv/Port_Drv.c
  Drivers/Dio/hal/Dio.c
  Drivers/Dio/drv/Dio_Drv.c
)

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  Inc
  Drivers/Gpio
  Drivers/Efls/hal
  Drivers/Efls/drv
  Drivers/Efls/reg
  Drivers/Delay/hal
  Drivers/Delay/drv
  Drivers/Delay/reg
  Drivers/Mcu/hal
  Drivers/Mcu/drv
  Drivers/Mcu/reg
  Drivers/Gpio/reg
  Drivers/Port/hal
  Drivers/Port/drv
  Drivers/Dio/hal
  Drivers/Dio/drv
)

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
  # User defined compiler options
)

# Add additional defined symbols
target_compile_definitions(${PROJECT_NAME} PRIVATE
  # Add additional defined symbols here
)

# Linker options
target_link_options(${PROJECT_NAME} PRIVATE 
  # User defined linker options
)

# Add additional linker search directories
target_link_directories(${PROJECT_NAME} PRIVATE
  # Add additional linker search directories here
)

# Add additional linker libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
  # Add additional linker libraries here
)
