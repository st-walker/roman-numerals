#ifndef roman_numerals_header_included
#define roman_numerals_header_included
#include <string>

namespace roman_numerals {

  std::string convert(unsigned int arabic);
  unsigned int convert(std::string const &roman);
}

#endif 	// roman_numerals_header_included
