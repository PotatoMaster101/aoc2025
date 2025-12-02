add_executable(day05 main.cpp)
target_link_libraries(day05 PRIVATE aocpp)

add_custom_command(
  TARGET day05 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day05>/input.txt
)
