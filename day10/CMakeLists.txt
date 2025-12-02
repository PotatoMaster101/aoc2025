add_executable(day10 main.cpp parser/parser.cpp)
target_link_libraries(day10 PRIVATE aocpp)

add_custom_command(
  TARGET day10 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day10>/input.txt
)
