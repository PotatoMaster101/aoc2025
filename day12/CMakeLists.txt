add_executable(day12 main.cpp)
target_link_libraries(day12 PRIVATE aocpp)

add_custom_command(
  TARGET day12 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day12>/input.txt
)
