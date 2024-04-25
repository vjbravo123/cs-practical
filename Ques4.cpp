#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINDOW_SIZE = 4;
const int MAX_PACKETS = 10;

int main() {
    srand(time(nullptr));
    map<int, bool> window;
    int base = 1;

    while (base <= MAX_PACKETS) {
        for (int i = 0; i < WINDOW_SIZE && (base + i) <= MAX_PACKETS; i++) {
            if (!window.count(base + i)) {
                cout << "Sending packet: " << (base + i) << endl;
                window[base + i] = false;  // false indicates ACK not received
            }
        }

        for (auto& packet : window) {
            if (!packet.second && rand() % 2) {  // Simulate ACK receipt
                cout << "Received ACK for packet: " << packet.first << endl;
                packet.second = true;
            }
        }

        while (window.begin() != window.end() && window.begin()->second) {
            window.erase(window.begin());
            base++;
        }

        if (window.empty()) {
            cout << "All packets within window received, moving window." << endl;
        } else {
            cout << "Timeout or loss detected, resending pending packets." << endl;
        }
    }

    cout << "All packets sent and acknowledged." << endl;
    return 0;
}