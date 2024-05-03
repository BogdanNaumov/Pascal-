file(GLOB srcs "*.cpp")
add_executable(${TEST} ${srcs} ${hdrs}) 
target_link_libraries(${TEST} ${gtest})