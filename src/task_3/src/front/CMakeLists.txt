set(LIBNAME front)

add_library(${LIBNAME}
        userInterface.hpp
        userIntarface.cpp)
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_HOME_DIRECTORY}/src/back)
target_link_libraries(${LIBNAME} back)