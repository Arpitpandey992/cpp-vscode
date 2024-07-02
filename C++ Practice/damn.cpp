#include <algorithm>
#include <chrono>
#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

using namespace std;
using namespace chrono;

void printElements(std::ranges::input_range auto&& range) {
    std::ranges::for_each(range, [](const auto& e) { int x = rand(); });
}
void print(string&& s) {
    for (auto& x : s) {
        int xx = rand();
    }
}

void printStringView(std::string_view& s) {
    for (auto& x : s) {
        int xx = rand();
    }
}

int main() {
    const int siz = 1e7;
    const int factor = 10;

    string s(siz, 'a');
    auto start = high_resolution_clock::now();
    for (int i = 0; i < factor; i++)
        print(std::move(s));
    auto end = high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by basic print: " << duration.count() << " seconds" << std::endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < factor; i++)
        printElements(s | std::ranges::views::take(siz / 2));
    end = high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by cool  print: " << duration.count() << " seconds" << std::endl;

    std::string_view sv(s.data(), siz / 2);
    start = high_resolution_clock::now();
    for (int i = 0; i < factor; i++)
        printStringView(sv);
    end = high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by sv    print: " << duration.count() << " seconds" << std::endl;
}