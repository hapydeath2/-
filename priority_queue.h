#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class PriorityQueue {
public:
    void push(const T& item, int priority);
    T* pop();  // Измененный метод

private:
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<>> queue;
};

template <typename T>
void PriorityQueue<T>::push(const T& item, int priority) {
    queue.emplace(priority, item);
}

template <typename T>
T* PriorityQueue<T>::pop() {
    if (queue.empty()) {
        return nullptr; // Возвращаем nullptr, если очередь пуста
    }
    T item = queue.top().second;
    queue.pop();
    return new T(item); // Возвращаем объект, созданный в куче
}

#endif // PRIORITY_QUEUE_H