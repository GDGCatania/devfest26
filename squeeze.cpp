#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using Event = std::pair<int, long long>;

std::pair<int, int> longest_window(const std::vector<Event>& events, int limit, long long budget) {
    std::unordered_map<int, int> counts;
    int left = 0;
    long long total = 0, best_cost = 0;
    std::pair<int, int> best{0, 0};

    for (int right = 0; right < static_cast<int>(events.size()); ++right) {
        const auto [category, cost] = events[right];
        ++counts[category];
        total += cost;
        if (static_cast<int>(counts.size()) > limit || total > budget) {
            const auto [old_category, old_cost] = events[left++];
            --counts[old_category];
            total -= old_cost;
        }

        const int length = right - left + 1;
        if (length > best.second - best.first ||
            (length == best.second - best.first && total <= best_cost)) {
            best = {left, right + 1};
            best_cost = total;
        }
    }
    return best;
}

int main() {
    int count, limit;
    long long budget;
    std::cin >> count >> limit >> budget;
    std::vector<Event> events(count);
    for (auto& [category, cost] : events) {
        std::cin >> category >> cost;
    }

    auto [start, end] = longest_window(events, limit, budget);
    std::cout << start << " " << end << "\n";
}
