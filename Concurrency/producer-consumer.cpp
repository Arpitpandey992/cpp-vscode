#include <deque>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <vector>
using namespace std;

class Buffer {
    deque<int> buf;
    int capacity;
    Buffer(int capacity) : capacity(capacity) {
    }
    bool isBufferFull() {
        return buf.size() == capacity;
    }
    bool isEmpty() {
        return buf.empty();
    }
};

class Producer {
    shared_ptr<Buffer> buffer;
    Producer(shared_ptr<Buffer> buffer) : buffer(buffer) {
    }
};

class Consumer {
    shared_ptr<Buffer> buffer;
    int secondsToConsume, consumerId;
    mutex consumerLock;

   public:
    Consumer(shared_ptr<Buffer> buffer, int &secondsToConsume, int consumerId) : buffer(buffer), secondsToConsume(secondsToConsume), consumerId(consumerId) {
    }

    void consume() {
        lock_guard<mutex> lock(this->consumerLock);
        sleep(this->secondsToConsume);
        cout << consumerId << " Consumed!\n";
    }
};

int main() {
}