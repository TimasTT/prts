SET(SERVICENAME task_3)

add_executable(${SERVICENAME} main.cpp)

target_include_directories(${SERVICENAME} PUBLIC ${CMAKE_HOME_DIRECTORY}/src/back
        ${CMAKE_HOME_DIRECTORY}/src/front)
target_link_libraries(${SERVICENAME} front back)