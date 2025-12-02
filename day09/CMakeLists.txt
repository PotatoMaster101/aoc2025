add_executable(day09 main.cpp)
target_link_libraries(day09 PRIVATE aocpp)

add_custom_command(
  TARGET day09 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day09>/input.txt
)
