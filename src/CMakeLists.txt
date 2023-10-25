
add_library(grid_generator grid_generator.c)
target_link_libraries(grid_generator m)
target_include_directories(grid_generator PUBLIC .)

add_executable(main main.c)
target_link_libraries(main grid_generator)