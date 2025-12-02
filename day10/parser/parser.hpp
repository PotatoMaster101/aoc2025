#ifndef AOC2025_PARSER_HPP
#define AOC2025_PARSER_HPP
#include <string>
#include <string_view>
#include <vector>

std::string parse_indicator(std::string_view input);
std::vector<std::vector<std::size_t>> parse_buttons(std::string_view input);
std::vector<std::size_t> parse_jolts(std::string_view input);

#endif
