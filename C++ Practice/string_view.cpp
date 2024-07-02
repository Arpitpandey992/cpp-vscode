#include <algorithm>
#include <chrono>
#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <string_view>
#include <thread>

using namespace std;
int flag = 0;

void printStringAfterDelay(std::string_view strView) {
    while (flag==0) {}
    std::cout << "Printing after delay: " << strView << std::endl;
}

void printElements(std::ranges::input_range auto&& range) {
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "Printing range after delay: " << range << std::endl;
}

void append_(string& s, mutex m) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 3; i++) {
        s = s + s;
    }
    flag = 1;
}

int main() {
    std::string s = "Hello, world!";
    printStringAfterDelay(std::string_view(s));
    printElements(std::ranges::ref_view(s));
    thread t(append_, s);
    std::cout << std::endl;
    std::cout << s << std::endl;

    return 0;
}
