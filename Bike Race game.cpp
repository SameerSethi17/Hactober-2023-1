#include <iostream>
#include <ctime>
#include <cstdlib>

class Bike {
public:
    int position;
    int speed;

    Bike() : position(0), speed(0) {}

    void accelerate() {
        speed += rand() % 3 + 1; // Accelerate by a random value (1-3)
    }

    void move() {
        position += speed;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0));

    Bike playerBike;
    Bike opponentBike;

    int raceDistance = 100; // Define the race distance

    std::cout << "Welcome to the Bike Race Game!" << std::endl;

    while (playerBike.position < raceDistance && opponentBike.position < raceDistance) {
        // Player's turn
        std::cout << "Your turn! Press 'A' to accelerate: ";
        char choice;
        std::cin >> choice;

        if (choice == 'A' || choice == 'a') {
            playerBike.accelerate();
        }

        // Opponent's turn
        opponentBike.accelerate();

        // Move both bikes
        playerBike.move();
        opponentBike.move();

        // Display the race
        std::cout << "Player: " << std::string(playerBike.position, '-') << "P" << std::endl;
        std::cout << "Opponent: " << std::string(opponentBike.position, '-') << "O" << std::endl;
    }

    // Determine the winner
    if (playerBike.position >= raceDistance && opponentBike.position >= raceDistance) {
        std::cout << "It's a tie!" << std::endl;
    } else if (playerBike.position >= raceDistance) {
        std::cout << "Congratulations! You won!" << std::endl;
    } else {
        std::cout << "Opponent won. Better luck next time!" << std::endl;
    }

    return 0;
}