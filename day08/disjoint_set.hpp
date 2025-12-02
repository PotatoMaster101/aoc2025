#ifndef AOC2025_DISJOINT_SET_HPP
#define AOC2025_DISJOINT_SET_HPP
#include <numeric>
#include <vector>

struct disjoint_set {
  std::vector<std::size_t> parents;

  explicit disjoint_set(const std::size_t n) : parents(n) {
    std::iota(parents.begin(), parents.end(), 0);
  }

  std::size_t find(const std::size_t i) {
    return parents[i] == i ? i : parents[i] = find(parents[i]);
  }

  void merge(const std::size_t i, const std::size_t j) {
    parents[find(i)] = find(j);
  }

  std::vector<std::size_t> get_sizes() {
    std::vector<std::size_t> sizes(parents.size());
    for (std::size_t i{0}; i < parents.size(); i++)
      sizes[find(i)]++;
    return sizes;
  }
};

#endif
