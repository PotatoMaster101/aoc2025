#include <ext/strext.hpp>
#include <input.hpp>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include "num_table.hpp"

[[nodiscard]] num_table parse_file(const std::string& filename = "input.txt") {
  std::vector lines{aoc::read_lines(filename)};

  // pad lines incase the IDE strips whitespace
  const std::size_t max_size{std::ranges::max(lines, std::less{}, &std::string::size).size()};
  for (std::string& line : lines)
    line.resize(max_size, ' ');
  return num_table{lines};
}

int main() {
  const num_table table{parse_file()};
  const auto idxes = table.get_num_indexes();
  std::cout << table.calc_columns() << '\n';    // 4277556
  std::cout << table.calc_cephalopod() << '\n'; // 3263827
  return 0;
}
