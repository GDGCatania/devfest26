#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using Interval = std::pair<long long, long long>;

std::vector<Interval> free_slots(long long duration, std::vector<Interval> busy) {
    std::sort(busy.begin(), busy.end());
    std::vector<Interval> gaps;
    long long cursor = 0;
    for (auto [start, end] : busy) {
        if (start > cursor) gaps.emplace_back(cursor, start);
        cursor = end;
    }
    if (cursor < duration) gaps.emplace_back(cursor, duration);
    return gaps;
}

int main() {
    long long duration;
    int count;
    std::cin >> duration >> count;
    std::vector<Interval> busy(count);
    for (auto& [start, end] : busy) std::cin >> start >> end;
    auto gaps = free_slots(duration, busy);
    if (gaps.empty()) std::cout << "-\n";
    for (auto [start, end] : gaps) std::cout << start << " " << end << "\n";
}
