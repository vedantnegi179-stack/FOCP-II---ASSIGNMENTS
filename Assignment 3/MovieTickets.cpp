#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;
    unordered_map<int, int> available;

public:
    bool book(int X, int Y) {
        // Initialize movie if not present
        if (available.find(Y) == available.end()) {
            available[Y] = 100;
        }

        // Check conditions
        if (bookings[Y].count(X) || available[Y] == 0) {
            return false;
        }

        bookings[Y].insert(X);
        available[Y]--;
        return true;
    }

    bool cancel(int X, int Y) {
        if (bookings[Y].count(X) == 0) {
            return false;
        }

        bookings[Y].erase(X);
        available[Y]++;
        return true;
    }

    bool isBooked(int X, int Y) {
        return bookings[Y].count(X) > 0;
    }

    int availableTickets(int Y) {
        if (available.find(Y) == available.end()) {
            return 100;
        }
        return available[Y];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    MovieTicket mt;

    while (Q--) {
        string query;
        getline(cin, query);

        stringstream ss(query);
        string type;
        ss >> type;

        if (type == "BOOK") {
            int X, Y;
            ss >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;

        } else if (type == "CANCEL") {
            int X, Y;
            ss >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;

        } else if (type == "IS_BOOKED") {
            int X, Y;
            ss >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;

        } else if (type == "AVAILABLE_TICKETS") {
            int Y;
            ss >> Y;
            cout << mt.availableTickets(Y) << endl;
        }
    }

    return 0;
}