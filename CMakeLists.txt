cmake_minimum_required(VERSION 2.6)

project(SeaBattle)

message(STATUS "SYSTEM INFO:\n\t OS - ${CMAKE_SYSTEM}\n\t COMPILER - ${CMAKE_CXX_COMPILER}\n\t PROJECT - ${PROJECT_NAME}\n\t CMAKE - ${CMAKE_VERSION} CMAKE - ${CMAKE_VERSION}")

if(UNIX)
    message(STATUS "BEGIN")

    set(CMAKE_C_FLAGS "-g")
    set(CMAKE_CXX_FLAGS "-g")

    include_directories("${PROJECT_SOURCE_DIR}/include")
    file(GLOB SRC_SEABATTLE "${PROJECT_SOURCE_DIR}/src/*.cpp")
    add_executable(seabattle ${SRC_SEABATTLE})
    set_target_properties(seabattle PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
    set_target_properties(seabattle PROPERTIES RUNTIME_OUTPUT_NAME      "seabattle")

    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        message(STATUS "${DOXYGEN_EXECUTABLE}")
    endif(DOXYGEN_FOUND)
    #check_include_file_cxx(".h" _H)
    #set (VAR 16)
    #configure_file(config.h.in config.h)
# add a target to generate API documentation with Doxygen
#find_package (Doxygen)
#IF (DOXYGEN_FOUND)
#configure_file (${CMAKE_CURRENT_SOURCE_DIR}/doxydoc/DoxygenConfig.in ${CMAKE_CURRENT_BINARY_DIR}/doxydoc/DoxygenConfig @ONLY)
#add_custom_target (doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxydoc/DoxygenConfig
#WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxydoc COMMENT "Generating API documentation with Doxygen"
#VERBATIM )
#ENDIF (DOXYGEN_FOUND)



    message(STATUS "END")
else(UNIX)
    message(ERROR " IT'S NOT UNIX")
endif(UNIX)
