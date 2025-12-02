#include <algorithm>
#include <ext/strext.hpp>
#include <geo/area.hpp>
#include <geo/pos.hpp>
#include <input.hpp>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

std::vector<aoc::pos<>> get_input(const std::string& filename = "input.txt") {
  const auto p = aoc::read_lines(filename) | std::views::transform([](const std::string& s) {
    const std::vector splits{aoc::str_split(s, ",")};
    return aoc::pos{std::stoull(splits[0]), std::stoull(splits[1])};
  });
  return {std::ranges::begin(p), std::ranges::end(p)};
}

std::size_t part_1(const std::vector<aoc::pos<>>& input) {
  std::vector<aoc::area<>> areas;
  for (std::size_t i{0}; i < input.size(); i++)
    for (std::size_t j{i + 1}; j < input.size(); j++)
      areas.emplace_back(input[i], input[j]);
  return std::ranges::max_element(areas)->size();
}

std::size_t part_2(const std::vector<aoc::pos<>>& input) {
  // TODO
  return 0;
}

int main() {
  const std::vector input{get_input()};
  std::cout << part_1(input) << '\n'; // 50
  std::cout << part_2(input) << '\n'; // 24
  return 0;
}
