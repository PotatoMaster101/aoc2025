add_executable(day03 main.cpp)
target_link_libraries(day03 PRIVATE aocpp)

add_custom_command(
  TARGET day03 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day03>/input.txt
)
