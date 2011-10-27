cmake_minimum_required(VERSION 2.6)

project(SeaBattle)

message(STATUS "[SYSTEM INFO]\n\t OS - ${CMAKE_SYSTEM}\n\t COMPILER - ${CMAKE_CXX_COMPILER}\n\t PROJECT - ${PROJECT_NAME}\n\t CMAKE - ${CMAKE_VERSION} CMAKE - ${CMAKE_VERSION}")

if(UNIX)
    message(STATUS "[BEGIN]")

    set(CMAKE_C_FLAGS   "-g")
    set(CMAKE_CXX_FLAGS "-g")

    include_directories("${PROJECT_SOURCE_DIR}/include")
    file(GLOB SRC_SEABATTLE "${PROJECT_SOURCE_DIR}/src/*.cpp")
    add_executable(seabattle ${SRC_SEABATTLE})
    set_target_properties(seabattle PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")
    set_target_properties(seabattle PROPERTIES RUNTIME_OUTPUT_NAME      "seabattle")

    # add target to generate documentation with doxygen
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        if(DOXYGEN_DOT_FOUND)
            set(DOXYGEN_SKIP_DOT "NO")
            set(HAVE_DOT "YES")
            message(STATUS "[DOXYGEN DOT] Was found")
        else(DOXYGEN_DOT_FOUND)
            set(DOXYGEN_SKIP_DOT "YES")
            set(HAVE_DOT "NO")
            message(STATUS "[DOXYGEN DOT] Was not found. Skip it")
        endif(DOXYGEN_DOT_FOUND)
        configure_file (${PROJECT_SOURCE_DIR}/documentation/doxygenConfig.in ${PROJECT_BINARY_DIR}/documentation/doxygenConfig @ONLY)
        add_custom_target (doc ALL ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/documentation/doxygenConfig WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/documentation COMMENT "[DOXYGEN] Generating of doumentation")
    endif(DOXYGEN_FOUND)

    message(STATUS "[END]")
else(UNIX)
    message(ERROR " IT'S NOT UNIX")
endif(UNIX)
