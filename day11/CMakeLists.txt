add_executable(day11 main.cpp)
target_link_libraries(day11 PRIVATE aocpp)

add_custom_command(
  TARGET day11 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day11>/input.txt
)
