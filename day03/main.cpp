#include <input.hpp>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
#include "bank.hpp"

std::vector<bank> read_banks(const std::string& filename = "input.txt") {
  const auto input = aoc::read_lines(filename) | std::views::transform([](const std::string& s) {
    return bank{s};
  });
  return {std::ranges::begin(input), std::ranges::end(input)};
}

long long get_jolt(const std::ranges::range auto& banks, int digits) {
  return std::accumulate(banks.begin(), banks.end(), 0LL, [digits](const long long acc, const bank& bank) {
    return acc + bank.get_jolts(digits);
  });
}

int main() {
  const std::vector banks{read_banks()};
  std::cout << get_jolt(banks, 2) << '\n';  // 357
  std::cout << get_jolt(banks, 12) << '\n'; // 3121910778619
  return 0;
}
