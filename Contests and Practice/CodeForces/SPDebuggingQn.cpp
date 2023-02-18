#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Order {
    bool is_buy = false;
    int qty = 0;
    double price = 0.0;
};

ostream& operator<<(ostream& os, const Order& order) {
    return os << (order.is_buy ? "buy " : "sell ")
              << order.qty << "@$" << setprecision(1)
              << fixed << order.price;
}

bool operator<(const Order& a, const Order& b) {
    return a.price < b.price;
};

class OrderBook {
   public:
    OrderBook() = default;

    // formats and prints the orders as the test cases expect.
    ~OrderBook() {
        auto itr = splitIntoBuyAndSellOrders();
        std::sort(begin(orders), itr);
        std::sort(itr, end(orders));
        print();
    }

    // checks the opposing side's available orders.
    // for a buy order, look at existing sell orders, and vice versa.
    // if a trade is possible, update the order book accordingly.
    // otherwise, insert the order into the book.
    void add(Order order);

    // print the order book
    // IMPORTANT: the test cases depend on this method.
    // please make sure this is the ONLY ouput that gets printed to stdout.
    void print();

   private:
    // returns an iterator to the best "match" for a given order.
    // for buy orders, this would be the lowest sell price.
    // for sell orders, the highest buy price.
    // if no orders meet the criteria, return orders.end()
    vector<Order>::iterator findTrade(const Order& order);

    // split orders into buy and sell orders.
    // return an iterator to the first sell order.
    // all orders before the iterator are buy orders.
    // all orders after are sell orders.
    vector<Order>::iterator splitIntoBuyAndSellOrders();

    vector<Order> orders;
};

vector<Order>::iterator OrderBook::splitIntoBuyAndSellOrders() {
    return stable_partition(begin(orders),
                            end(orders),
                            [](const Order& order) { return order.is_buy; });
}

void OrderBook::print() {
    for (const auto& order : orders)
        cout << order << endl;
}

void OrderBook::add(Order order) {
    while (order.qty > 0) {
        auto other = findTrade(order);
        if (other == end(orders)) {
            orders.push_back(order);
            break;
        } else {
            auto take = min(other->qty, order.qty);
            if (take == other->qty) {
                orders.erase(other);
            } else {
                other->qty -= take;
            }
            order.qty -= take;
        }
    }
}

vector<Order>::iterator OrderBook::findTrade(const Order& order) {
    auto ret = end(orders);

    size_t i = 0;
    while (i < orders.size()) {
        if (order.is_buy != orders[i].is_buy) {
            if (order.is_buy && orders[i].price <= order.price) {
                // i am buying and the ith index is selling at cost less than my asking price
                if (ret == end(orders) || ret->price > orders[i].price) {
                    // seller price should be as low as possible -> best match
                    ret = begin(orders) + i;
                }
            } else if (!order.is_buy && orders[i].price >= order.price) {
                // i am selling and ith index is a buyer buying at cost more than my asking price
                if (ret == end(orders) || ret->price < orders[i].price) {
                    // buyer price should be as high as possible
                    ret = begin(orders) + i;
                }
            }
        }
        i++;
    }
    return ret;
}

void parse(OrderBook book) {
    string word;
    while (true) {
        cin >> word;
        if (word == "end")
            break;

        Order* order = new Order;
        order->is_buy = word == "buy";
        cin >> order->qty;
        cin >> order->price;
        book.add(*order);
    }
}
int main() {
    OrderBook book;
    parse(book);
    Order order = {true, 10, 11.0};
    book.add(order);
}
/*
buy 150 30
buy 100 40
sell 200 28
sell 150 35
buy 4 36
*/