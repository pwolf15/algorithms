#include <gmock/gmock.h>

#include <list>
#include <unordered_map>

namespace p0146 {
class LRUCache {
  public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto index_it = index_.find(key);

    // if not found, return -1
    if (index_it == index_.end()) return -1;

    // if found, move it to front (MRU)
    auto order_it = index_it->second;
    order_.splice(order_.begin(), order_, order_it);

    return order_it->second;
  }

  void put(int key, int value) {
    // if present, update value + splice
    auto index_it = index_.find(key);
    if (index_it != index_.end()) {
      auto order_it = index_it->second;
      order_.splice(order_.begin(), order_, order_it);
      order_it->second = value;
    } else {
      // not present
      // if full, erase LRU and pop back
      if (index_.size() == capacity_) {
        auto order_last_it = order_.rbegin();
        index_.erase(order_last_it->first);
        order_.pop_back();
      }

      // add to front
      order_.push_front({key, value});
      index_[key] = order_.begin();
    }
  }

  private:
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> index_;
  std::list<std::pair<int, int>> order_;
  int capacity_;
};
}  // namespace p0146

TEST(P0146, Basic) {
  p0146::LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 1);
  cache.put(3, 3);
  EXPECT_EQ(cache.get(2), -1);
  cache.put(4, 4);
  EXPECT_EQ(cache.get(3), 3);
  EXPECT_EQ(cache.get(4), 4);

  p0146::LRUCache cache2(2);
  EXPECT_EQ(cache2.get(2), -1);
  cache2.put(2, 6);
  EXPECT_EQ(cache2.get(1), -1);
  cache2.put(1, 5);
  cache2.put(1, 2);
  EXPECT_EQ(cache2.get(1), 2);
  EXPECT_EQ(cache2.get(2), 6);

  p0146::LRUCache cache3(3);
  cache3.put(1, 1);
  cache3.put(2, 2);
  cache3.put(3, 3);
  cache3.put(4, 4);
  EXPECT_EQ(cache3.get(4), 4);
  EXPECT_EQ(cache3.get(3), 3);
  EXPECT_EQ(cache3.get(2), 2);
  EXPECT_EQ(cache3.get(1), -1);
  cache3.put(5, 5);
  EXPECT_EQ(cache3.get(1), -1);
  EXPECT_EQ(cache3.get(2), 2);
  EXPECT_EQ(cache3.get(3), 3);
  EXPECT_EQ(cache3.get(4), -1);
  EXPECT_EQ(cache3.get(5), 5);
}
