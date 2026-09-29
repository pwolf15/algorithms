#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <limits>

int myAtoi(const std::string& s) {

  std::vector<int8_t> digits;

  enum ParseState {

    TRIM_LEADING_WHITESPACE=0,
    PROCESS_DIGITS=1
  };

  bool is_positive = true;
  ParseState parse_state = ParseState::TRIM_LEADING_WHITESPACE;
  int cur_num = 0;
  std::cout << "\n";
  for (const auto& c: s) {
   
//    std::cout << "state: " << parse_state << ": " << c << "\n"; 
    if (parse_state == ParseState::TRIM_LEADING_WHITESPACE) 
    {
      switch (c) {
        case ' ':
          continue;
        case '+':
          is_positive = true;
          parse_state = ParseState::PROCESS_DIGITS;
          continue;
        case '-':
          is_positive = false;
          parse_state = ParseState::PROCESS_DIGITS;
          continue; 
        default:
          break;
      }
 //     std::cout << "checking digit: " << c << isdigit(c) << "\n";
      if (!isdigit(c)) return 0;
      else {
        parse_state = ParseState::PROCESS_DIGITS;
        digits.push_back((c - '0'));
      }
    }
    else if (parse_state == ParseState::PROCESS_DIGITS && !isdigit(c)) {
      break;
    }
    else if (parse_state == ParseState::PROCESS_DIGITS && isdigit(c)) {
      digits.push_back((c - '0'));
    }
  }
  
  //std::cout << "digits: ";
  for (const auto& digit: digits) {
    //std::cout << (int)digit;
  }

  int result = 0;
  int decimal = 1;

  std::vector<int8_t> temp;
  bool has_seen_nonzero = false;
  for (int i = 0; i < digits.size(); ++i)
  {
    if (digits[i] == 0 && !has_seen_nonzero) continue;
    has_seen_nonzero = true;
    temp.push_back(digits[i]);
  }

  std::swap(temp, digits);

  for (int i = digits.size() - 1; i >= 0; i--) {
    
     
    if (is_positive) {
      uint64_t long_result = (uint64_t)(result) + (uint64_t)(digits[i]) * decimal;
      if (long_result >= std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
      else { result = (int32_t)long_result; }
    }
    else if (!is_positive) {
      int64_t long_result = (int64_t)(result) - (int64_t)(digits[i]) *  decimal;
      if (long_result <= std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();
      else { result = (int32_t)long_result;  } 
    }
 
    // increment decimal
    if (i > 0 && ((uint64_t)decimal * 10) > std::numeric_limits<int>::max()) {
      return is_positive ? std::numeric_limits<int>::max(): std::numeric_limits<int>::min(); 
    }
    if (i > 0) {
      decimal *= 10;
    }
  }
//  std::cout << " -> ";
  return result;
}

int run_my_atoi() {

  std::vector<std::string> test_strs = {
    "42",
    " -042",
    "1337c0d3",
    "0-1",
    "words and 987",
    "-91283472332",
    "  0000000000012345678",
    "010",
    "2147483646",
    "2147483648",
    "-6147483648"
  };

  for (const auto& test_str: test_strs) {
    std::cout << test_str << " -> " << myAtoi(test_str) << "\n";
  }
  return 0;
}
