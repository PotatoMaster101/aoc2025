#ifndef AOC2025_HELPER_HPP
#define AOC2025_HELPER_HPP
#include <cstddef>
#include <ranges>
#include <string>
#include <string_view>

template <std::ranges::range Rng>
std::string press_button(const std::string_view indicator, Rng&& buttons) {
  std::string result{indicator};
  for (const std::size_t button : buttons)
    if (button < result.size())
      result[button] = result[button] == '.' ? '#' : '.';
  return result;
}

#endif
