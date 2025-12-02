#include <ext/strext.hpp>
#include <input.hpp>
#include <iostream>
#include <numeric>
#include <ranges>
#include "id_range.hpp"

template <std::ranges::range Rng> requires std::same_as<std::ranges::range_value_t<Rng>, id_range>
long long count_invalid(const Rng& rng, const bool full) {
  return std::accumulate(std::ranges::begin(rng), std::ranges::end(rng), 0LL, [full](const long long acc, const id_range& id) {
    return acc + (full ? id.count_full_invalid() : id.count_half_invalid());
  });
}

int main() {
  const std::vector input{aoc::read_lines("input.txt")};
  const auto ranges = aoc::str_split(input[0], ",") | std::views::transform([](const std::string& s) {
    return id_range{s};
  });

  std::cout << count_invalid(ranges, false) << '\n';  // 1227775554
  std::cout << count_invalid(ranges, true) << '\n';   // 4174379265
  return 0;
}
