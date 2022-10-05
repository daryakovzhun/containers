#include "../map/s21_map.h"
#include "../queue/s21_queue.h"
#include "../list/s21_list.h"

template <class... Args>
iterator emplace(const_iterator pos, Args&&... args);

template <class... Args>
void emplace_back(Args&&... args);

template <class... Args>
void emplace_front(Args&&... args);

template <class... Args>
vector<std::pair<iterator,bool>> emplace(Args&&... args);
