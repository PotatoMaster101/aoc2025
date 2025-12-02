#ifndef AOC2025_NUM_RANGE_HPP
#define AOC2025_NUM_RANGE_HPP
#include <ext/strext.hpp>
#include <string>

struct num_range {
  long long first;
  long long last;

  explicit num_range(const std::string& input) {
    const std::vector splits{aoc::str_split(input, "-")};
    first = std::stoll(splits[0]);
    last = std::stoll(splits[1]);
  }

  num_range(const long long first, const long long last)
    : first{first}, last{last} {}

  [[nodiscard]] bool contains(const long long num) const noexcept {
    return num >= first && num <= last;
  }

  [[nodiscard]] long long count() const noexcept {
    return last - first + 1;
  }
};

#endif
