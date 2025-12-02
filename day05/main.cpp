#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include "num_range.hpp"

std::vector<num_range> get_ranges(std::ifstream& fs) {
  std::vector<num_range> result;
  std::string line;
  while (std::getline(fs, line)) {
    if (line.empty())
      break;

    result.emplace_back(line);
  }
  return result;
}

std::vector<long long> get_ids(std::ifstream& fs) {
  std::vector<long long> result;
  std::string line;
  while (std::getline(fs, line))
    result.push_back(std::stoll(line));
  return result;
}

int part_1(const std::vector<num_range>& ranges, const std::vector<long long>& ids) {
  int count{0};
  for (const long long id: ids) {
    for (const num_range& rng : ranges) {
      if (rng.contains(id)) {
        count++;
        break;
      }
    }
  }
  return count;
}

long long part_2(const std::vector<num_range>& ranges) {
  std::vector sorted{ranges};
  std::ranges::sort(sorted, [](const num_range& a, const num_range& b) { return a.first < b.first; });
  std::vector<num_range> unique;
  long long first{sorted[0].first}, last{sorted[0].last};
  for (const num_range& rng : sorted) {
    if (rng.first >= first && rng.first <= last) {
      last = std::max(last, rng.last);
    } else {
      unique.emplace_back(first, last);
      first = rng.first;
      last = rng.last;
    }
  }
  unique.emplace_back(first, last);
  return std::accumulate(unique.begin(), unique.end(), 0LL, [](const long long acc, const num_range& rng) {
    return acc + rng.count();
  });
}

int main() {
  std::ifstream f{"input.txt"};
  const std::vector ranges{get_ranges(f)};
  const std::vector ids{get_ids(f)};
  std::cout << part_1(ranges, ids) << '\n'; // 3
  std::cout << part_2(ranges) << '\n';      // 14
  return 0;
}
