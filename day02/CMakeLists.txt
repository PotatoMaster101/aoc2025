add_executable(day02 main.cpp)
target_link_libraries(day02 PRIVATE aocpp)

add_custom_command(
  TARGET day02 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day02>/input.txt
)
