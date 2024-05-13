#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T>
struct PriorityQueueItem {
    int priority;  
    T value;       

    
    bool operator<(const PriorityQueueItem<T>& other) const {
        return priority < other.priority;
    }
};


template<typename T>
class PriorityQueue {
public:
    
    vector<PriorityQueueItem<T>> queue;

    
    void insert(int priority, T value) {
        PriorityQueueItem<T> item{ priority, value };
        auto it = std::lower_bound(queue.begin(), queue.end(), item);  
        queue.insert(it, item);  
    }

    
    T pop() {
        if (queue.empty()) {
            throw out_of_range("Queue is empty");  
        }

        PriorityQueueItem<T> item = queue.back();  
        queue.pop_back();  
        return item.value;  
    }

    
    bool isEmpty() const {
        return queue.empty();
    }

    
    friend ostream& operator<<(ostream& os, const PriorityQueue<T>& pq) {  
        for (const auto& item : pq.queue) {  
            os << "(Priority: " << item.priority << ", Value: " << item.value << ") "<<endl;  
        }
        return os;  
    }
};
