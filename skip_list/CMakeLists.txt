file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")
add_executable(${skip_list} ${srcs} ${hdrs}) 

