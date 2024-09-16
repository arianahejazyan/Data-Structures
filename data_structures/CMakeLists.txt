# data_structures/CMakeLists.txt
# Define an interface library for templates
add_library(StackLib INTERFACE)

# Specify the include directory for the interface library
target_include_directories(StackLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ListLib INTERFACE)
target_include_directories(ListLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})