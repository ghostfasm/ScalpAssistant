cmake_minimum_required(VERSION 3.0.0)
project(ScalpAssistant VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# include(CTest)
# enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

link_directories(
    "${PROJECT_SOURCE_DIR}/lib"
    "${PROJECT_SOURCE_DIR}/"
)

add_library(
    TransaqConnector
    TransaqConnector.hpp
    TransaqConnector.cpp 
)

add_library(
    Application
    Application.hpp
    Application.cpp 
)

set(SOURCE_FILES main.cpp)
 
# set_target_properties(TRANSAQ PROPERTIES LINKER_LANGUAGE C)

add_executable(app ${SOURCE_FILES})

target_link_libraries(app txmlconnector64.dll TransaqConnector Application) 


