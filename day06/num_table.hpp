#ifndef AOC2025_NUM_TABLE_HPP
#define AOC2025_NUM_TABLE_HPP
#include <cctype>
#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

struct idx_range {
  std::size_t first;
  std::size_t last;
};

struct num_table {
  std::vector<std::string> lines;

  explicit num_table(const std::vector<std::string>& lines) : lines{lines} { }

  [[nodiscard]] std::vector<idx_range> get_num_indexes() const {
    std::vector<idx_range> results;
    std::size_t start_idx{0};
    const std::string operators{lines[lines.size() - 1]};
    for (std::size_t i{1}; i < operators.length(); i++) {
      if (operators[i] == '+' || operators[i] == '*') {
        results.push_back({start_idx, i - 1});
        start_idx = i;
      }
    }
    results.push_back({start_idx, operators.length() - 1});
    return results;
  }

  [[nodiscard]] long long calc_columns() const {
    const std::vector ranges{get_num_indexes()};
    long long result{0};
    for (const auto& [first, last] : ranges) {
      const char op{lines[lines.size() - 1][first]};
      long long acc{op == '*' ? 1 : 0};

      for (std::size_t l{0}; l < lines.size() - 1; l++) {
        const std::string_view num_str{lines[l].data() + first, last - first + 1};
        const int num{std::stoi(aoc::str_trim(num_str))};
        acc = op == '*' ? acc * num : acc + num;
      }
      result += acc;
    }
    return result;
  }

  [[nodiscard]] std::vector<int> get_cephalopod_column(const idx_range& id) const {
    std::vector<int> result;
    for (std::size_t x{id.last + 1}; x > id.first; x--) {   // +1 to avoid >=0 check for std::size_t
      int num{0};
      for (std::size_t y{0}; y < lines.size() - 1; y++) {
        if (std::isdigit(lines[y][x - 1]))
          num = num * 10 + lines[y][x - 1] - '0';
      }
      if (num != 0)
        result.push_back(num);
    }
    return result;
  }

  [[nodiscard]] long long calc_cephalopod() const {
    const std::vector ranges{get_num_indexes()};
    long long result{0};
    for (std::size_t i{ranges.size()}; i > 0; i--) {
      const char op{lines[lines.size() - 1][ranges[i - 1].first]};
      long long acc{op == '*' ? 1 : 0};
      for (const int num : get_cephalopod_column(ranges[i - 1]))
        acc = op == '*' ? acc * num : acc + num;
      result += acc;
    }
    return result;
  }
};

#endif
