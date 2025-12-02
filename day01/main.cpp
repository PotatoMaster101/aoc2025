#include <input.hpp>
#include <iostream>
#include <numeric>
#include <ranges>
#include "dial.hpp"

int parse_line(const std::string& line) {
  return line[0] == 'L' ? -std::stoi(line.substr(1)) : std::stoi(line.substr(1));
}

int part_1(const std::ranges::range auto& input) {
  dial dial;
  int count{0};
  for (const std::string& line : input) {
    const int num{parse_line(line)};
    dial.turn(num);
    if (dial.value == 0)
      count++;
  }
  return count;
}

int part_2(const std::ranges::range auto& input) {
  dial dial;
  return std::accumulate(std::ranges::begin(input), std::ranges::end(input), 0, [&dial](const int acc, const std::string& line) {
    const int num{parse_line(line)};
    return acc + dial.turn_count_zero(num);
  });
}

int main() {
  const std::vector input{aoc::read_lines("input.txt")};
  std::cout << part_1(input) << '\n';   // 3
  std::cout << part_2(input) << '\n';   // 6
  return 0;
}
