add_executable(day08 main.cpp)
target_link_libraries(day08 PRIVATE aocpp)

add_custom_command(
  TARGET day08 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day08>/input.txt
)
