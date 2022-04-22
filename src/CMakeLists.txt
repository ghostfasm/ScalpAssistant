cmake_minimum_required(VERSION 3.0.0)
project(ScalpAssistant VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

# include(CTest)
# enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

link_directories(
    "${PROJECT_SOURCE_DIR}/lib/finam"
    "${PROJECT_SOURCE_DIR}/"
)

add_library(TransaqFunctions INTERFACE)
target_include_directories(TransaqFunctions INTERFACE "${SOURCE_FILES}/lib/finam")

add_library(
    System
    System.hpp
    System.cpp 
)

add_library(
    Exchange
    Exchange.hpp
    Exchange.cpp
)

add_library(
    TransaqConnector
    TransaqConnector.hpp
    TransaqConnector.cpp 
)


# target_sources(TransaqFunctions INTERFACE Functions.hpp)

add_library(
    Application
    Application.hpp
    Application.cpp 
)

set(SOURCE_FILES main.cpp)
 
# set_target_properties(TRANSAQ PROPERTIES LINKER_LANGUAGE C)

add_executable(app ${SOURCE_FILES})

target_link_libraries(app txmlconnector64.dll Exchange TransaqConnector Application) 


