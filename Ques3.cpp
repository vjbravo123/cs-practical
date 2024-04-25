#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINDOW_SIZE = 4;
const int MAX_PACKETS = 10;

int main() {
    srand(time(nullptr));
    int base = 1;
    int nextSeqNum = 1;
    vector<int> window;

    while (base < MAX_PACKETS) {
        while (nextSeqNum < base + WINDOW_SIZE && nextSeqNum <= MAX_PACKETS) {
            cout << "Sending packet: " << nextSeqNum << endl;
            window.push_back(nextSeqNum);
            nextSeqNum++;
        }

        // Simulate ACK receipt with potential loss
        if (!window.empty() && rand() % 2) {
            cout << "Received ACK for packet: " << window.front() << endl;
            base = window.front() + 1;
            window.erase(window.begin());
        } else {
            cout << "Timeout, resending from packet: " << base << endl;
            nextSeqNum = base;  // Go back to base
            window.clear();
        }
    }

    cout << "All packets sent successfully." << endl;
    return 0;
}