#include <iostream>
#include <unistd.h>

int number;
int guess;
int tries;
int max = 10;
int min = 1;

bool game = true;

void setup() {
    std::cin >> min;
    std::cin >> max;
    std::cout << "Done." << std::endl;
    usleep(10000);
}

void SleepnClear() {
    usleep(250000);
    system("clear");
}

void RandomNumber() {
    srand(time(NULL));
    int number = rand() % max + 1;

    system("clear");

    while(guess != number) {

        std::cout << min << "-" << max << std::endl;
        std::cin >> guess;
        
        if (guess > number) {
            std::cout << "lower" << std::endl;
            SleepnClear();
            tries++;
        }
        else if (guess < number) {
            std::cout << "higher" << std::endl;
            SleepnClear();
            tries++;
        }
        else if(guess == number) {
            std::cout << "correct" << std::endl;
            SleepnClear();
            tries++;
        }
    }
    system("clear");
    std::cout << "number: " << number << std::endl;
    std::cout << "guess's: " << tries << std::endl;
}

int main() {
    setup();
    while(game == true) {
        RandomNumber();

        guess = 0;
        tries = 0;

        usleep(3000000);
    }   
}