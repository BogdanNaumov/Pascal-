file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")
add_executable(${priority_queue} ${srcs} ${hdrs}) 

