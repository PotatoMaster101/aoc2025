#include <input.hpp>
#include <iostream>
#include "parser/parser.hpp"

std::size_t part_1(const std::vector<std::string>& input) {
  for (const std::string& line : input) {
    const std::string indicator{parse_indicator(line)};
    const std::vector buttons{parse_buttons(line)};
    // TODO
  }
  return 0;
}

std::size_t part_2(const std::vector<std::string>& input) {
  for (const std::string& line : input) {
    const std::string indicator{parse_indicator(line)};
    const std::vector buttons{parse_buttons(line)};
    const std::vector jolts{parse_jolts(line)};
    // TODO
  }
  return 0;
}

int main() {
  const std::vector input{aoc::read_lines("input.txt")};
  std::cout << part_1(input) << '\n';   // 7
  std::cout << part_2(input) << '\n';
  return 0;
}
