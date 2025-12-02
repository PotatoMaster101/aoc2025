#ifndef AOC2025_MANIFOLD_HPP
#define AOC2025_MANIFOLD_HPP
#include <geo/area.hpp>
#include <geo/pos.hpp>
#include <geo/strgrid.hpp>
#include <map>
#include <vector>

class manifold {
public:
  explicit manifold(const aoc::strgrid& grid) : grid_{grid}, bounds_{grid.bounds()} {}

  [[nodiscard]] std::size_t count_splits() const {
    std::size_t result{0};
    for (const aoc::pos<>& splitter : grid_.find_all('^')) {
      for (std::size_t y{splitter.y}; y > 0; y--) {
        const aoc::pos current{splitter.x, y - 1};
        const aoc::pos left{splitter.x - 1, y};
        const aoc::pos right{splitter.x + 1, y};
        if (bounds_.has(current) && grid_[current] == '^')
          break;

        if ((bounds_.has(current) && grid_[current] == 'S') || (bounds_.has(left) && grid_[left] == '^') || (bounds_.has(right) && grid_[right] == '^')) {
          result++;
          break;
        }
      }
    }
    return result;
  }

  [[nodiscard]] std::size_t count_timelines() const {
    const std::optional start{grid_.find('S')};
    if (!start)
      return 0;

    std::map<aoc::pos<>, std::size_t> cache;
    return count_timeline_recurse(cache, *start);
  }

private:
  aoc::strgrid grid_;
  aoc::area<> bounds_;

  [[nodiscard]] std::size_t count_timeline_recurse(std::map<aoc::pos<>, std::size_t>& cache, const aoc::pos<>& p) const {
    if (!bounds_.has_y(p.y))
      return 1;
    if (!bounds_.has_x(p.x))
      return 0;
    if (const auto it = cache.find(p); it != cache.end())
      return it->second;

    std::size_t result{0};
    if (grid_[p] == 'S' || grid_[p] == '.')
      result = count_timeline_recurse(cache, p + aoc::unit_y<>);
    else
      result = count_timeline_recurse(cache, p - aoc::unit_x<>) + count_timeline_recurse(cache, p + aoc::unit_x<>);

    cache[p] = result;
    return result;
  }
};

#endif
