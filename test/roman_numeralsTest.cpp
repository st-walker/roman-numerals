#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "roman_numerals.hpp"

using namespace ::testing;
using namespace roman_numerals;

TEST(RomanConverter, CanConvertPositiveDigits) {
  EXPECT_THAT(convert(1), Eq("I"));
  EXPECT_THAT(convert(2), Eq("II"));
  EXPECT_THAT(convert(3), Eq("III"));
  EXPECT_THAT(convert(4), Eq("IV"));
  EXPECT_THAT(convert(5), Eq("V"));
  EXPECT_THAT(convert(10), Eq("X"));
  EXPECT_THAT(convert(11), Eq("XI"));
  EXPECT_THAT(convert(20), Eq("XX"));
  EXPECT_THAT(convert(50), Eq("L"));
  EXPECT_THAT(convert(100), Eq("C"));
  EXPECT_THAT(convert(500), Eq("D"));
  EXPECT_THAT(convert(1000), Eq("M"));

  EXPECT_THAT(convert(362), Eq("CCCLXII"));
  EXPECT_THAT(convert(3999), Eq("MMMCMXCIX"));
}

TEST(ArabicConverter, CanConvertRomanNumerals) {
  EXPECT_THAT(convert("I"), 1);
  EXPECT_THAT(convert("II"), 2);
  EXPECT_THAT(convert("III"), 3);
  EXPECT_THAT(convert("IV"), 4);  
  EXPECT_THAT(convert("V"), 5);  
  EXPECT_THAT(convert("IX"), 9);  
  EXPECT_THAT(convert("X"), 10);
  EXPECT_THAT(convert("XI"), 11);
  EXPECT_THAT(convert("LXI"), 61);
  EXPECT_THAT(convert("M"), 1000);  
}
