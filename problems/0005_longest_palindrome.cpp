#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {

#define BRUTE_FORCE 0 


#if BRUTE_FORCE

  std::string max_palindrome = "";
  int max_length = 0;

  const auto is_palindrome = [](const std::string& s) {
    
    if (s.empty()) return s;

    int i = s.size() / 2 - 1; 
    int j = (s.size() + 1) / 2 ;
    bool is_palindrome = true;
//    if (s == "racecar")  std::cout << "here" << "\n";
    while (i >= 0 && j < s.size()) {
      if (s[i] != s[j]) {
        is_palindrome = false; break;
      }
      i--; j++;
    }
    return is_palindrome ? s : ""; 
  };
  
  for (int i = 0; i < s.size(); ++i) {
    for (int j = s.size() - 1; j >= i; --j) {
      //std::cout << "test: " << s.substr(i, j - i + 1) << "\n";
      std::string result = is_palindrome(s.substr(i, j - i + 1));
      if (result.size() > max_length) {
        max_length = result.size();
        max_palindrome = result;
      }
    }
  }
  return max_palindrome;
#else
  int best_len = 0, best_len_start = 0;
  auto expand = [&](int l, int r) {
  
    while (l >= 0 && r < s.size() && s[l] == s[r]) { l--; r++; }

    // incremented past actual length
    if ((r - l - 1) > best_len) { best_len = r - l - 1; best_len_start = l + 1; }
  };
  for (size_t c = 0; c < s.size(); ++c) {
    expand(c, c);
    expand(c, c+1);
  }

  return s.substr(best_len_start, best_len);
#endif
}

int main() {
  std::cout << longestPalindrome("bb") << "\n";
  std::cout << longestPalindrome("babad") << "\n";
  std::cout << longestPalindrome("cbbd") << "\n";
  std::cout << longestPalindrome("c") << "\n";
  std::cout << longestPalindrome("lasdjfkasdfjlksdjfaracecarlasjdf") << "\n";
}
