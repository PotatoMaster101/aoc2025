#ifndef AOC2025_BANK_HPP
#define AOC2025_BANK_HPP
#include <algorithm>
#include <cmath>
#include <math.hpp>
#include <string>
#include <string_view>

struct bank {
  std::string value;

  [[nodiscard]] long long get_jolts(const int digits) const {
    std::vector<char> max_nums;
    max_nums.reserve(digits);

    std::size_t start_idx{0};
    while (max_nums.size() < digits) {
      const std::size_t reserve{digits - max_nums.size() - 1};
      const std::string_view vw{&value[start_idx], value.length() - start_idx - reserve};
      const auto max{std::ranges::max_element(vw)};
      start_idx += std::distance(vw.begin(), max) + 1;
      max_nums.push_back(*max);
    }

    long long result{0};
    for (int i{0}; i < digits; i++)
      result += (max_nums[i] - '0') * aoc::llpow(10, digits - i - 1);
    return result;
  }
};

#endif
