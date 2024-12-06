#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
struct Node {
    shared_ptr<Node> next, prev;
    T val;
    Node() : val(T()), next(nullptr), prev(nullptr) {
    }
    Node(const T &val) : val(val), next(nullptr), prev(nullptr) {
    }
    T get() {
        return val;
    }
};

template <typename T>
class DoublyLinkedList {
    shared_ptr<Node> head, tail;

   public:
    DoublyLinkedList() : head(make_shared<Node>()), tail(make_shared<Node>()) {
        head->next = tail;
        tail->prev = head;
    }

    shared_ptr<Node> getHead() {
        if (isEmpty())
            return nullptr;
        return head->next;
    }
    shared_ptr<Node> getTail() {
        if (isEmpty())
            return nullptr;
        return tail->prev;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    shared_ptr<Node> pushBack(T val) {
        shared_ptr<Node> newNode = make_shared<Node>(val);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
    }

    static void deleteNode(shared_ptr<Node> node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
    }
};

template <typename K, typename V>
class Cache {
    virtual pair<bool, V> get(K key) const = 0;
    virtual void set(const K &key, const V &val) const = 0;
};

template <typename K, typename V>
class LFUCache : public Cache {
    // one dll for every frequency
    // one dll for keeping per frequency DLLs tied together
    // one map for mapping key with value
    // one map for mapping key with it's node in the dll
    int capacity;
    unordered_map<K, V> keyValueMap;
    unordered_map<K, Node<K>> keyNodeMap;
    unordered_map<Node<K>, shared_ptr<DoublyLinkedList<K>>> nodeFrequencyListMap;

    // head will always contain the least frequently used elements
    DoublyLinkedList<DoublyLinkedList<K>> frequencyList;

   public:
    LFUCache(const int &capacity) : capacity(capacity) {
    }

    pair<bool, V> get(K key) const {
        if (!keyValueMap.contains(key)) {
            return {false, V()};
        }
        keyAccessed(key);
        return keyValueMap[key];
    }
    void set(const K &key, const V &val) const {
        if (keyValueMap.contains(key)) {
        } else {
            removeLeastFrequentlyUsedKeyIfFull();
            addKeyValue(key, val);
        }
    }

   private:
    void removeLeastFrequentlyUsedKeyIfFull() {
        if (!isFull())
            return;
        shared_ptr<DoublyLinkedList<Node<K>>> lfuList = frequencyList.getHead();
        if (!lfuList)
            return;
        shared_ptr<Node<K>> lfuKeyNode = lfuList.getHead();
        if (!lfuKeyNode)
            return;
        removeKey(lfuKeyNode->get());
    }

    void keyAccessed(const K &key) {
        auto node = keyNodeMap[key];
        auto currentFrequencyList = nodeFrequencyListMap[node];
        DoublyLinkedList::deleteNode(node);
        }

    void removeKey(const K &key) {
    }

    void addKeyValue(const K &key, const V &val) {
        shared_ptr<DoublyLinkedList<Node<K>>> lfuList;
        if (frequencyList.isEmpty()) {
            lfuList = frequencyList.pushBack(make_shared<DoublyLinkedList<Node<K>>>());
        } else {
            lfuList = frequencyList.getHead();
        }
        auto nodeAdded = lfuList->pushBack(key);

        keyValueMap[key] = val;
        keyNodeMap[key] = nodeAdded;
        nodeFrequencyListMap[nodeAdded] = frequencyList;
    }

    void updateKeyValue(const K &key, const V &val) {
        keyValueMap[key] = val;
        keyAccessed(key);
    }

    bool isFull() {
        return keyValueMap.size() == capacity;
    }
};
