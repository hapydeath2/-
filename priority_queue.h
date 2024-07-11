#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class PriorityQueue {
public:
    void push(const T& item, int priority);
    T pop();
    bool empty() const;

private:
    vector<pair<int, T>> elements;
};

template <typename T>
void PriorityQueue<T>::push(const T& item, int priority) {
    elements.push_back(make_pair(priority, item));
}

template <typename T>
T PriorityQueue<T>::pop() {
    if (elements.empty()) {
        cout << "Queue is empty" << endl;
        return T();
    }
    int minIndex = 0;
    for (size_t i = 1; i < elements.size(); ++i) {
        if (elements[i].first < elements[minIndex].first) {
            minIndex = i;
        }
    }
    T item = elements[minIndex].second;
    elements.erase(elements.begin() + minIndex);
    return item;
}

template <typename T>
bool PriorityQueue<T>::empty() const {
    return elements.empty();
}
#endif