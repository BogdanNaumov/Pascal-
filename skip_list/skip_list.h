#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class SkipListNode {
public:
    T value;
    vector<SkipListNode<T>*> next;
    int level;

    SkipListNode(T val, int level)
        : value(val), next(level, nullptr) {}
};

template <typename T>
class SkipList {
private:
    SkipListNode<T>* head;  
    int maxLevel;  
    int currentLevel;  
    float probability;  

    
    int randomLevel() {
        int level = 1;
        while ((rand() % 100) < (probability * 100) && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    
    SkipList(int max_lvl, float prob)
        : maxLevel(max_lvl), currentLevel(1), probability(prob) {
        head = new SkipListNode<T>(T(), maxLevel);  
        srand(time(nullptr));  
    }

    void insert(T value)
    {
        vector<SkipListNode<T>*> update(maxLevel, nullptr);
        SkipListNode<T>* current = head;

        for (int i = currentLevel - 1; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->value < value) {
                current = current->next[i];
            }
            update[i] = current;  
        }

        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int i = currentLevel; i < newLevel; ++i) {
                update[i] = head;  
            }
            currentLevel = newLevel;  
        }

        
        SkipListNode<T>* newNode = new SkipListNode<T>(value, newLevel);
        for (int i = 0; i < newLevel; ++i) {
            newNode->next[i] = update[i]->next[i];  
            update[i]->next[i] = newNode;  
        }
    }

    void remove(T value)
    {
        vector<SkipListNode<T>*> update(maxLevel, nullptr);
        SkipListNode<T>* current = head; 

        for (int i = currentLevel - 1; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->value < value) { 
                current = current->next[i];
            }
            update[i] = current; 
        }

        current = current->next[0];

        
        if (current != nullptr && current->value == value) {
            for (int i = 0; i < currentLevel; ++i) {
                if (update[i]->next[i] != current) break; 
                update[i]->next[i] = current->next[i]; 
            }

            delete current;

            
            while (currentLevel > 1 && head->next[currentLevel - 1] == nullptr) {
                currentLevel--;
            }
        }
    }


    bool search(T value)
    {
        SkipListNode<T>* current = head;

        for (int i = currentLevel - 1; i >= 0; --i) {
            while (current->next[i] != nullptr && current->next[i]->value < value) {
                current = current->next[i];
            }
        }

        current = current->next[0];

        return current != nullptr && current->value == value;
    }

    void printList()
    {
        for (int i = 0; i < currentLevel; ++i) {
            SkipListNode<T>* current = head->next[i];
            cout << "Level " << i << ": ";
            while (current != nullptr) {
                cout << current->value << " ";
                current = current->next[i];
            }
            cout << endl;
        }
    }
};
