#ifndef AOC2025_DIAGRAM_HPP
#define AOC2025_DIAGRAM_HPP
#include <geo/area.hpp>
#include <geo/pos.hpp>
#include <geo/strgrid.hpp>
#include <set>

struct diagram {
  aoc::strgrid grid;

  [[nodiscard]] std::size_t count_accessible() const {
    return get_accessible({}).size();
  }

  [[nodiscard]] std::size_t count_accessible_repeat() const {
    std::size_t prev_count{0};
    std::set removed{get_accessible({})};
    while (removed.size() != prev_count) {
      prev_count = removed.size();
      removed = get_accessible(removed);
    }
    return removed.size();
  }

  [[nodiscard]] std::set<aoc::pos<>> get_accessible(const std::set<aoc::pos<>>& removed) const {
    std::set<aoc::pos<>> results;
    for (std::size_t y{0}; y < grid.rows(); y++) {
      for (std::size_t x{0}; x < grid.cols(); x++) {
        if (const aoc::pos p{x, y}; (grid[p] == '@' || removed.contains(p)) && count_adj(p, removed) < 4)
          results.insert(p);
      }
    }
    return results;
  }

  [[nodiscard]] int count_adj(const aoc::pos<>& p, const std::set<aoc::pos<>>& removed) const {
    const aoc::area bounds{grid.bounds()};
    int count{0};
    for (const aoc::pos<>& n : p.neighbours(aoc::adj_dir<>)) {
      if (bounds.has(n) && grid[n] == '@' && !removed.contains(n))
        count++;
    }
    return count;
  }
};

#endif
