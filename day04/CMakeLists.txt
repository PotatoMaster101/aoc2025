add_executable(day04 main.cpp)
target_link_libraries(day04 PRIVATE aocpp)

add_custom_command(
  TARGET day04 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.txt $<TARGET_FILE_DIR:day04>/input.txt
)
