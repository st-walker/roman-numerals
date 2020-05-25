#include "roman_numerals.hpp"
#include <map>

namespace roman_numerals {

std::string convert(unsigned int arabic) {

  const auto arabicToRomanConversions = {
      std::make_pair(1000u, "M"), std::make_pair(900u, "CM"),
      std::make_pair(500u, "D"),  std::make_pair(400u, "CD"),
      std::make_pair(100u, "C"),  std::make_pair(90u, "XC"),
      std::make_pair(50u, "L"),   std::make_pair(40u, "XL"),
      std::make_pair(10u, "X"),   std::make_pair(9u, "IX"),
      std::make_pair(5u, "V"),    std::make_pair(4u, "IV"),
      std::make_pair(1u, "I"),
  };

  std::string roman{""};
  for (auto arabicToRoman : arabicToRomanConversions) {
    while (arabic >= arabicToRoman.first) {
      roman += arabicToRoman.second;
      arabic -= arabicToRoman.first;
    }
  }

  return roman;
}

unsigned int convert(std::string const &roman) {

  static const std::map<char, unsigned int> romanToArabic = {
      {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}};

  auto arabic = 0u;
  auto largestSeenDigit = romanToArabic.at(roman.back());
  for (auto letter = roman.crbegin(); letter != roman.crend(); letter++) {
    auto thisInteger = romanToArabic.at(*letter);
    if (thisInteger < largestSeenDigit) arabic -= thisInteger;
    else arabic += thisInteger;
  }
  return arabic;
}

} // namespace roman_numerals
