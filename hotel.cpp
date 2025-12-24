#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ROOMS = 100;

struct Room {
    int roomNumber;
    char guestName[50];
    bool isOccupied;
};

class Hotel {
private:
    Room rooms[MAX_ROOMS];

public:
    Hotel() {
        for (int i = 0; i < MAX_ROOMS; ++i) {
            rooms[i].roomNumber = i + 1;
            rooms[i].isOccupied = false;
            strcpy(rooms[i].guestName, "");
        }
    }

    void displayMenu() {
        cout << "Hotel Management System\n";
        cout << "1. Display All Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Check Out\n";
        cout << "4. Search Room\n";
        cout << "5. Exit\n";
    }

    void displayAllRooms() {
        cout << "Room Number\tGuest Name\tOccupied\n";
        for (int i = 0; i < MAX_ROOMS; ++i) {
            cout << rooms[i].roomNumber << "\t\t" << rooms[i].guestName << "\t\t" << (rooms[i].isOccupied ? "Yes" : "No") << endl;
        }
    }

    void bookRoom() {
        int roomNumber;
        cout << "Enter room number to book: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
            cout << "Invalid room number\n";
            return;
        }

        if (rooms[roomNumber - 1].isOccupied) {
            cout << "Room is already occupied\n";
        } else {
            cout << "Enter guest name: ";
            cin.ignore(); // Clear the buffer
            cin.getline(rooms[roomNumber - 1].guestName, 50);
            rooms[roomNumber - 1].isOccupied = true;
            cout << "Room booked successfully\n";
        }
    }

    void checkOut() {
        int roomNumber;
        cout << "Enter room number to check out: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
            cout << "Invalid room number\n";
            return;
        }

        if (rooms[roomNumber - 1].isOccupied) {
            rooms[roomNumber - 1].isOccupied = false;
            strcpy(rooms[roomNumber - 1].guestName, "");
            cout << "Check out successful\n";
        } else {
            cout << "Room is not occupied\n";
        }
    }

    void searchRoom() {
        int roomNumber;
        cout << "Enter room number to search: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
            cout << "Invalid room number\n";
            return;
        }

        cout << "Room Number\tGuest Name\tOccupied\n";
        cout << rooms[roomNumber - 1].roomNumber << "\t\t" << rooms[roomNumber - 1].guestName << "\t\t"
             << (rooms[roomNumber - 1].isOccupied ? "Yes" : "No") << endl;
    }
};

int main() {
    Hotel hotel;
    int choice;

    do {
        hotel.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAllRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.checkOut();
                break;
            case 4:
                hotel.searchRoom();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

