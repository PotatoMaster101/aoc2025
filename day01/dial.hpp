#ifndef AOC2025_DIAL_HPP
#define AOC2025_DIAL_HPP
#include <cstdlib>

struct dial {
  const int max{100};
  int value{50};

  /// Turns the dial by a specific amount.
  void turn(const int turns) noexcept {
    value = (value + turns) % max;
    if (value < 0)
      value += max;
  }

  /// Turns the dial by a specific amount and count how many times it passed zero.
  int turn_count_zero(const int turns) noexcept {
    const auto [quot, rem] = std::div(turns, turns < 0 ? -max : max);
    int count{quot};
    if ((turns < 0 && value != 0 && value + rem <= 0) || (turns > 0 && value + rem >= max)) {
      count++;
    }

    turn(turns);
    return count;
  }
};

#endif
