add_executable(day01 main.cpp)
target_link_libraries(day01 PRIVATE aocpp)

add_custom_command(
  TARGET day01 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day01>/input.txt
)
