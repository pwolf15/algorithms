#include <iostream>
#include <unordered_map>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine) {

#if SOL1  
  std::unordered_map<char, int> letter_counts;
  
  // store counts of each letter in magazine
  for (const auto& letter: magazine) {
    letter_counts[letter]++;
  }

  // iterate ransomNote; exit if letter not found or count is 0
  for (const auto& letter: ransomNote) {
    if (letter_counts.find(letter) == letter_counts.end() || letter_counts[letter] == 0) return false;
    else {
      letter_counts[letter]--;
    }
  }  
#else

    int counts[26] = {};
    for (char c : magazine) ++counts[c - 'a'];
    for (char c : ransomNote)
        if (--counts[c - 'a'] < 0) return false;
    return true;

#endif

  return true;
}

int main() {
  std::cout << canConstruct("a", "b") << "\n";
  std::cout << canConstruct("aa", "ab") << "\n";
  std::cout << canConstruct("aa", "aab") << "\n";  
}
