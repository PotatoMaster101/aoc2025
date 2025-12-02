#ifndef AOC2025_COORD_HPP
#define AOC2025_COORD_HPP
#include <cmath>
#include <ext/strext.hpp>
#include <string_view>
#include <vector>

struct coord {
  int x;
  int y;
  int z;

  explicit coord(const std::string_view sv) {
    const std::vector nums{aoc::str_split(sv)};
    x = std::stoi(nums[0]);
    y = std::stoi(nums[1]);
    z = std::stoi(nums[2]);
  }

  auto operator<=>(const coord&) const = default;
  [[nodiscard]] double distance(const coord& other) const { return std::hypot(x - other.x, y - other.y, z - other.z); }
};

#endif
