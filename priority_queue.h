#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T>
class PriorityQueue {
public:
    void push(const T& item, int priority);
    T pop();

private:
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<>> queue;
};

template <typename T>
void PriorityQueue<T>::push(const T& item, int priority) {
    queue.emplace(priority, item);
}

template <typename T>
T PriorityQueue<T>::pop() {
    if (queue.empty()) {
        throw std::runtime_error("Queue is empty");
    }
    T item = queue.top().second;
    queue.pop();
    return item;
}

#endif // PRIORITY_QUEUE_H
