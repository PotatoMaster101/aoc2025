#include <ext/strext.hpp>
#include <regex>
#include "parser.hpp"

std::string parse_indicator(const std::string_view input) {
  std::cmatch match;
  return std::regex_search(input.begin(), input.end(), match, std::regex{R"(\[(.*?)\])"}) ? match[1] : std::string{};
}

std::vector<std::vector<std::size_t>> parse_buttons(std::string_view input) {
  std::cmatch match;
  std::vector<std::vector<std::size_t>> result;
  while (std::regex_search(input.begin(), input.end(), match, std::regex{R"(\(([^)]*)\))"})) {
    const std::vector splits{aoc::str_split(std::string_view{match[1].first, match[1].second}, ",")};
    const auto nums{aoc::str_rng_to_size_t(splits)};
    result.emplace_back(nums.begin(), nums.end());
    input = std::string_view{match.suffix().first, input.end()};
  }
  return result;
}

std::vector<std::size_t> parse_jolts(const std::string_view input) {
  std::vector<std::size_t> result;
  if (std::cmatch match; std::regex_search(input.begin(), input.end(), match, std::regex{R"(\{([^}]*)\})"})) {
    const std::vector splits{aoc::str_split(std::string_view{match[1].first, match[1].second}, ",")};
    for (const std::string_view s : splits)
      result.emplace_back(std::stoul(std::string{s}));
  }
  return result;
}
