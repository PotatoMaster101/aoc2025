add_executable(day07 main.cpp)
target_link_libraries(day07 PRIVATE aocpp)

add_custom_command(
  TARGET day07 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day07>/input.txt
)
