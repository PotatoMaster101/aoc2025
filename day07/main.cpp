#include <input.hpp>
#include <iostream>
#include <geo/strgrid.hpp>
#include "manifold.hpp"

int main() {
  const aoc::strgrid grid{aoc::read_lines("input.txt")};
  const manifold man{grid};
  std::cout << man.count_splits() << '\n';    // 21
  std::cout << man.count_timelines() << '\n'; // 40
  return 0;
}
