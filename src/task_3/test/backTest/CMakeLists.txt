add_executable(backTest backTest.cpp)

target_link_libraries(backTest gtest back)
target_include_directories(backTest PUBLIC ${CMAKE_HOME_DIRECTORY}/src/back)

add_test(NAME backTest
        COMMAND backTest)