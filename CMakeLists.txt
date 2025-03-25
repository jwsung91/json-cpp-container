cmake_minimum_required(VERSION 3.10)
project(class_example)

file(GLOB SOURCES "src/*.cc" "include/*.h")
add_executable(class_example ${SOURCES})

target_link_libraries(class_example jsoncpp)
target_include_directories(class_example PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/jsoncpp    
)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(message_test tests/message_test.cc
    src/request_message.cc
    src/response_message.cc
)

target_include_directories(message_test PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/jsoncpp
)

target_link_libraries(message_test
    jsoncpp
    GTest::GTest
    GTest::Main
)

gtest_discover_tests(message_test)