add_executable(day06 main.cpp)
target_link_libraries(day06 PRIVATE aocpp)

add_custom_command(
  TARGET day06 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day06>/input.txt
)
