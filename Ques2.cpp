#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool sendPacket(int packet) {
    cout << "Sending packet: " << packet << endl;
    return rand() % 2;  // Simulate packet loss
}

bool receiveAck(int packet) {
    cout << "Receiving ACK for packet: " << packet << endl;
    return rand() % 2;  // Simulate ACK loss
}

int main() {
    srand(time(nullptr));
    int packet = 1;
    bool ackReceived = false;
    
    while (!ackReceived) {
        if (sendPacket(packet)) {
            ackReceived = receiveAck(packet);
        }
    }

    cout << "Packet sent successfully and ACK received." << endl;
    return 0;
}