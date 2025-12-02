#ifndef AOC2025_ID_HPP
#define AOC2025_ID_HPP
#include <ext/strext.hpp>
#include <string>

struct id_range {
  long long first_id;
  long long last_id;

  explicit id_range(const std::string& input) {
    const std::vector splits{aoc::str_split(input, "-")};
    first_id = std::stoll(splits[0]);
    last_id = std::stoll(splits[1]);
  }

  [[nodiscard]] long long count_half_invalid() const {
    long long result{0};
    for (long long id{first_id}; id <= last_id; id++) {
      const std::string str{std::to_string(id)};
      if (str.length() % 2 != 0)
        continue;
      if (const std::size_t mid{str.length() / 2}; str.substr(0, mid) == str.substr(mid))
        result += id;
    }
    return result;
  }

  [[nodiscard]] long long count_full_invalid() const {
    long long result{0};
    for (long long id{first_id}; id <= last_id; id++) {
      const std::string str{std::to_string(id)};
      if (const std::string extended{str + str}; extended.substr(1, extended.length() - 2).find(str) != std::string::npos)
        result += id;
    }
    return result;
  }
};

#endif
