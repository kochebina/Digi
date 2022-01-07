cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulaion)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headres ${PROJECT_SOURCE_DIR}/*.hh)

file(GLOB MACRO_FILES
  "*.mac"
  )

file(COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})

add_executable(test test.cc ${sources} ${headres})

target_link_libraries(test ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS test)
