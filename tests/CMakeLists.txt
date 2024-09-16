# tests/CMakeLists.txt
# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(StackTests test_stack.cc)

# Link the test executable with the StackLib and GTest libraries
target_link_libraries(StackTests StackLib ${GTEST_LIBRARIES} pthread)

# Optionally, add a test to CTest
add_test(NAME StackTests COMMAND StackTests)


add_executable(ListTests test_list.cc)
target_link_libraries(ListTests ListLib ${GTEST_LIBRARIES} pthread)
add_test(NAME ListTests COMMAND ListTests)