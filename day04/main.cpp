#include <input.hpp>
#include <iostream>
#include <string>
#include <geo/strgrid.hpp>
#include "diagram.hpp"

int main() {
  const aoc::strgrid grid{aoc::read_lines("input.txt")};
  const diagram diag{grid};
  std::cout << diag.count_accessible() << '\n';         // 13
  std::cout << diag.count_accessible_repeat() << '\n';  // 43
  return 0;
}
