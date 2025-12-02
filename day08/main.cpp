#include <functional>
#include <input.hpp>
#include <iostream>
#include <utility>
#include <ranges>
#include <string>
#include <vector>
#include "coord.hpp"
#include "disjoint_set.hpp"

std::vector<coord> get_coords(const std::string& filename = "input.txt") {
  const auto lines = aoc::read_lines(filename) | std::views::transform([](const std::string& s) {
    return coord{s};
  });
  return {std::ranges::begin(lines), std::ranges::end(lines)};
}

std::vector<std::pair<std::size_t, std::size_t>> get_sorted_by_dist(const std::vector<coord>& coords) {
  std::vector<std::pair<std::size_t, std::size_t>> result;
  for (std::size_t i{0}; i < coords.size(); i++)
    for (std::size_t j{i + 1}; j < coords.size(); j++)
      result.emplace_back(i, j);

  std::ranges::sort(result, [&coords](const std::pair<std::size_t, std::size_t>& a, const std::pair<std::size_t, std::size_t>& b) {
    const double a_dist{coords[a.first].distance(coords[a.second])};
    const double b_dist{coords[b.first].distance(coords[b.second])};
    return a_dist < b_dist;
  });
  return result;
}

std::size_t part_1(const std::vector<coord>& coords, const std::vector<std::pair<std::size_t, std::size_t>>& sorted, const std::size_t count) {
  disjoint_set ds{coords.size()};
  for (std::size_t i{0}; i < count; i++)
    ds.merge(sorted[i].first, sorted[i].second);

  std::vector sizes{ds.get_sizes()};
  std::ranges::sort(sizes, std::greater{});
  return sizes[0] * sizes[1] * sizes[2];
}

std::size_t part_2(const std::vector<coord>& coords, const std::vector<std::pair<std::size_t, std::size_t>>& sorted) {
  std::size_t circuits{coords.size()};
  disjoint_set ds{coords.size()};
  for (const auto&[first, second] : sorted) {
    if (ds.find(first) == ds.find(second))
      continue;

    ds.merge(first, second);
    circuits--;
    if (circuits == 1)
      return coords[first].x * coords[second].x;
  }
  return 0;
}

int main() {
  const std::vector coords{get_coords()};
  const std::vector sorted{get_sorted_by_dist(coords)};
  std::cout << part_1(coords, sorted, coords.size() >= 1000 ? 1000 : 10) << '\n';   // 40
  std::cout << part_2(coords, sorted) << '\n';                                      // 25272
  return 0;
}
