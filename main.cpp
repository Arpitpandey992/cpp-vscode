#include <iostream>

using namespace std;
template <typename T>
T sum(T x) {
    return x;
}

template <typename T, typename... Args>
T sum(T start, Args... args) {
    return start + sum(args...);
}

int main() {
    size_t n = 4;
    size_t y = n - 1;
    cout << y << endl;
}