#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct Player {
  std::string name;
  std::string team;

  Player(std::string p_name, std::string p_team)
      : name(std::move(p_name)), team(std::move(p_team)) {
    std::cout << "I am being constructed.\n";
  }

  Player(Player&& other) : name(std::move(other.name)), team(std::move(other.team)) {
    std::cout << "I am being moved.\n";
  }

  Player& operator=(const Player& other) = default;
};

int main() {
  std::vector<Player> players;
  std::cout << "emplace_back:\n";
  auto& ref = players.emplace_back("Albert Pujols", "Cardinals");
  assert("use a reference to the created object (C++17)");

  std::vector<Player> new_players;
  std::cout << "\npush_back:\n";
  new_players.push_back(Player("Shawn Green", "Dodgers"));

  for (Player const& player : players)
    std::cout << player.name << " played for the " << player.team << "\n";

  for (Player const& player : new_players)
    std::cout << player.name << " played for the " << player.team << "\n";

  return 0;
}
