#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>


using namespace std;

//Internal mini games.
//class game, mathgame, and ecounter are a form of inheretenc
class Game {
public:
    virtual void play() = 0; // Pure virtual function for playing the game
    virtual ~Game() {} // Virtual destructor
};

class MathGame : public Game { //Virtual function (play) being overridden
public:
    void play() override {
        // Implement the math game logic here
        int num1 = rand() % 10;
        int num2 = rand() % 10;

        cout << "Math Game: A homeless man offers you a deal. Answer these riddles and theres a chance you might go free. If a man has " << num2 << " grams of crack on Tuesday and " << num1 << " grams of crack on Wednesday, how much doid he have on Monday? ";
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == (num2 - num1) + num2) {
            cout << "Correct! Heres some blow!" << endl;
        }
        else {
            cout << "Incorrect! Gimme your wallet." << endl;
        }
    }
};

class Encounter : public Game {
public:
    void play() override { // Virutal function overriding
        // Implement the encounter logic here
        cout << "You encountered a wild animal! What will you do?" << endl;
        cout << "1. Try to run away\n";
        cout << "2. Stand your ground\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You managed to escape the encounter." << endl;
        }
        else {
            cout << "The wild animal attacks you! You lose 20% health." << endl;
            // Update player's health or take other relevant actions
        }
    }
};




// Main Game code   /////////////////////////////////////////////////////////////////////////////////////////////////////
class Traveler {
public:
    string name;
    int health;
    int money;
    int distance;
    int food;
    int days;

    Traveler(string n) : name(n), health(100), money(300), distance(0), food(80), days(0) {}
};

class City {
public:
    string name;
    int distance;
    int foodPrice;
    int medicinePrice;
    int wagonPartPrice;
};

vector<City> cities = {
    {"Cincinnati", 0, 5, 30, 50},
    {"Columbus", 100, 5, 28, 48},
    {"Cleveland", 200, 5, 25, 45}
};

vector<string> events = {
    "You found a new job along the way. Earn $50.", // (0)
    "You encountered a rare Ohioan who shared some food with you. Gain 10 lbs of food.", // (1)
    "An escaped gorilla from the zoo attacked you, and you lost some food supplies. Lose 50 lbs of food.", // (2)
    "You had to pay for repairs to your wagon. Spend $100.", // (3)
    "Your health improved after a good night's sleep. Gain 20 health", // (4)
    "You found a dead man and his wallet! Gain $100.", // (5)
    "You found an abandoned wagon, covered in blood, with supplies. Gain 20 lbs of food and $50.", // (6)
    "You encountered a bear while hunting. Gain 30 lbs of food but lose 10% health in the process.", // (7)
    "Your wagon broke down, and you had to leave some of your supplies behind. Lose 30 lbs of food and $75.", // (8)
    "You succumbed to a lady of the night. Lose $100, 20% health, and all your dignity.", // (9)
    "Your food supplies were infested with insects. Lose 40 lbs of food.", // (10)
    "You were ambushed by the Bloods. Lose $150 and 25% health.", // (11)
    "Your wagon axle snapped, and you had to walk for miles. Lose $50 and 10% health.", // (12)
    "You contracted AIDS. Lose 50% health and $200 for treatment.", // (13)
    "You encountered a drought. Lose 60 lbs of food and 25% health from dehydration.", // (14)
    "A thief stole some of your food supplies. Lose 20 lbs of food.", // (15)
    "You gambled and lost money at a shady roadside casino. Lose $50.", // (16)
    "You encountered a wild animal while hunting and got injured. Lose 15% health and 10 lbs of food.", // (17)
    "You fell into a hidden pit trap, injuring yourself. Lose 10% health and $30 for medical supplies.", // (18)
    "You got caught in a rainstorm, and your food supplies got soaked and spoiled. Lose 40 lbs of food.", // (19)
    "You tried to take a shortcut through dense woods but got lost for days. Lose 30 lbs of food and 15% health.", // (20)
    "You encountered a group of hostile travelers who demanded a toll. Lose $75.", // (21)
    "You accidentally spilled a can of food while cooking. Lose 20 lbs of food.", // (22)
    "You invested in a shady business opportunity and lost a significant amount of money. Lose $100.", // (23)
    "You encountered a swarm of aggressive bees. Lose 10% health and 10 lbs of food.", // (24)
    "You fell into a river while crossing and lost some of your supplies. Lose $50 and 20 lbs of food.", // (25)
    "You tripped and twisted your ankle. Lose 10% health and $40 for medical supplies.", // (26)
    "You tried to trade with a dubious merchant who overcharged you. Lose $60.", // (27)
    "You ate some questionable berries and suffered food poisoning. Lose 15% health and 20 lbs of food.", // (28)
    "You impulse purchased some sick looking rims for your wagon. Lose $150.", // (29)
    "You accidentally left your food out, and it was engulfed by a wildfire caused by a gender reveal. Lose 30 lbs of food.", // (30)
    "You walked by a trainwreck, and your health and food suffered from toxic chemical exposure. Lose 20% health and 20 lbs of food.", // (31)
    "You misplaced your cartoon looking money bag with a big \"$\" on it. Lose $75.", // (32)
    "You encountered a pack of wolves while traveling. Lose 10% health and 15 lbs of food.", // (33)
    "You got caught in a sharknado, which damaged your wagon and supplies. Lose $50 and 20 lbs of food.", // (34)
    "You lose your EZ Pass and have to pay a fine for skipping the toll. Lose $80.", // (35)
    "A Man... no... a HORRIFIC Man closes in on you in the night. As he approaches you notice his lanky features, his dark hair, his bulging moustache.... ITS DAVID HALL!! He lunges and latches on to your hair. Your stuck. Trapped. He whispers calmly in your ear ''Young man Tell me the thermal and propulsive efficieny of this Ramjet engine. If you succeed Ill give you a big wet kiss on the cheek. If you fail...'' He stops talking. David then gets right infront of you. You can feel his breath and more than that his stare, his contempt, his disgust. He hands you a paper and a pencil. You look at him confused and lost and he says to you ''If you dont have the equations memorized, then what are you doing here?'' Shaking, you look back down at the paper. On the paper it says:" // (36)
};
// Dr. Hall Mini Game of Doom. Chances of survival are slim to none. God speed./////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This is a form of static function (also high level math)
static void solveAerospaceProblem(Traveler& traveler) {
    // Generate random values for aerospace variables
    double gamma = 1.0 + static_cast<double>(rand()) / RAND_MAX * 0.7; // Random value between 1 and 1.7
    double Ta = 200.0 + static_cast<double>(rand()) / RAND_MAX * 100.0; // Random value between 200 and 300
    double To4 = 2000.0 + static_cast<double>(rand()) / RAND_MAX * 1000.0; // Random value between 2000 and 3000
    double M = 0.8 + static_cast<double>(rand()) / RAND_MAX * 4.2; // Random value between 0.8 and 5

    // Calculate the correct values for nth and np
    double To2 = Ta * (1 + ((gamma - 1) / 2) * pow(M, 2));
    double Te = To4 / (1 + ((gamma - 1) / 2) * pow(M, 2));
    double correctNth = ((To4 - Te) - (To2 - Ta)) / (To4 - To2);
    double correctNp = 2 / (1 + sqrt((To4 - Te) / (To2 - Ta)));

    // Display the prompt to the user
    cout << "Given values: gamma = " << gamma << ", Ta = " << Ta << " K, To4 = " << To4 << " K, M = " << M << endl;
    cout << "Use these values to calculate thermal efficiency (nth) and propulsion efficiency (np)." << endl;

    // Get user input
    double userNth, userNp;
    cout << "Enter your calculated value for nth: ";
    cin >> userNth;
    cout << "Enter your calculated value for np: ";
    cin >> userNp;

    // Check the correctness of the user's input
    double tolerance = 0.01; // Tolerance of 1% for correctness
    if (fabs(userNth - correctNth) < tolerance && fabs(userNp - correctNp) < tolerance) {
        // Correct input, gain money
        cout << "Congratulations! (Smooch) Your calculations are correct! You really are an Aerospace Engineer! Cherio! Dr Hall then leaves, but you will never be the same. Forever changed by his presence. The PTSD of this ecounter will be felt three generations down the line. I am so sorry." << endl;
        traveler.money += 52000;
        traveler.health += 10;
    }
    else {
        // Incorrect input, lose money and health
        cout << "Incorrect! Dr. Hall unhinges his jaw like an Anaconda and swollows you whole." << endl;
        traveler.health = 0;
        traveler.money -= 52000;
    }
}
// End of Dr. Hall Mini Game of Doom. Thank god.///////////////////////////////////////////////////////////??????


void displayMap(const Traveler& player) {
    cout << "\n===== Ohio Trail Map =====" << endl;
    cout << "Cities: ";
    for (const City& city : cities) {
        cout << city.name << " (" << city.distance << " miles) ";
    }
    cout << endl;
    cout << "Your Location: " << cities[player.distance / 100].name << endl;
    cout << "Distance to Destination: " << 200 - player.distance << " miles" << endl;
    cout << "======================================" << endl;
    auto now = chrono::system_clock::now(); // Grabs the current date and time
    time_t currentTime = chrono::system_clock::to_time_t(now);


    tm localTime; // Converts time to local time
#if defined(_MSC_VER)
    localtime_s(&localTime, &currentTime);
#else
    localtime_r(&currentTime, &localTime);
#endif

    // Formats and displays time for each turn 
    char timeStr[100];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &localTime);
    cout << "Current Date and Time: " << timeStr << endl;
    cout << "======================================\n" << endl;

}



void simulateEvent(Traveler& traveler, int& lastEventIndex) {
    int eventIndex;
    do {
        eventIndex = rand() % events.size();
    } while (eventIndex == lastEventIndex);

    lastEventIndex = eventIndex; //prevents same event twice in a row

    cout << "Day " << traveler.days << ": " << events[eventIndex] << endl;
    traveler.days++;

    // Update food, health, and money based on the event
    if (eventIndex == 0) {
        traveler.money += 50;
    }
    else if (eventIndex == 1) {
        traveler.food += 10;
    }
    else if (eventIndex == 2) {
        traveler.food -= 50;
    }
    else if (eventIndex == 3) {
        traveler.money -= 100;
    }
    else if (eventIndex == 4) {
        traveler.health += 20;
    }
    else if (eventIndex == 5) {
        traveler.money += 100;
    }
    else if (eventIndex == 6) {
        traveler.food += 20;
        traveler.money += 50;
    }
    else if (eventIndex == 7) {
        traveler.food += 30;
        traveler.health -= 10;
    }
    else if (eventIndex == 8) {
        traveler.food -= 30;
        traveler.money -= 75;
    }
    else if (eventIndex == 9) {
        traveler.money -= 100;
        traveler.health -= 20;
    }
    else if (eventIndex == 10) {
        traveler.food -= 40;
    }
    else if (eventIndex == 11) {
        traveler.money -= 150;
        traveler.health -= 25;
    }
    else if (eventIndex == 12) {
        traveler.money -= 50;
        traveler.health -= 10;
    }
    else if (eventIndex == 13) {
        traveler.health -= 50;
        traveler.money -= 200;
    }
    else if (eventIndex == 14) {
        traveler.food -= 60;
        traveler.health -= 25;
    }
    else if (eventIndex == 15) {
        traveler.food -= 20;
    }
    else if (eventIndex == 16) {
        traveler.money -= 50;
    }
    else if (eventIndex == 17) {
        traveler.food -= 10;
        traveler.health -= 15;
    }
    else if (eventIndex == 18) {
        traveler.money -= 30;
    }
    else if (eventIndex == 19) {
        traveler.food -= 40;
    }
    else if (eventIndex == 20) {
        traveler.food -= 30;
        traveler.health -= 15;
    }
    else if (eventIndex == 21) {
        traveler.money -= 75;
    }
    else if (eventIndex == 22) {
        traveler.food -= 20;
    }
    else if (eventIndex == 23) {
        traveler.money -= 100;
    }
    else if (eventIndex == 24) {
        traveler.food -= 10;
        traveler.health -= 10;
    }
    else if (eventIndex == 25) {
        traveler.money -= 50;
        traveler.food -= 20;
    }
    else if (eventIndex == 26) {
        traveler.money -= 40;
        traveler.health -= 10;
    }
    else if (eventIndex == 27) {
        traveler.money -= 60;
    }
    else if (eventIndex == 28) {
        traveler.food -= 20;
        traveler.health -= 15;
    }
    else if (eventIndex == 29) {
        traveler.money -= 150;
    }
    else if (eventIndex == 30) {
        traveler.food -= 30;
    }
    else if (eventIndex == 31) {
        traveler.food -= 20;
        traveler.health -= 20;
    }
    else if (eventIndex == 32) {
        traveler.money -= 75;
    }
    else if (eventIndex == 33) {
        traveler.food -= 15;
        traveler.health -= 10;
    }
    else if (eventIndex == 34) {
        traveler.money -= 50;
        traveler.food -= 20;
    }
    else if (eventIndex == 35) {
        traveler.money -= 80;
    }
    else if (eventIndex == 36) {
        solveAerospaceProblem(traveler);
    }
}







int main() { // MAIN

    srand(time(0));

    cout << "  _____ _           ___  _    _       _____         _ _ " << endl;
    cout << " |_   _| |_  ___   / _ \\| |_ (_)___  |_   _| _ __ _(_) |" << endl;
    cout << "   | | | ' \\/ -_) | (_) | ' \\  / _ \\   | || '_/ _` | | |" << endl;
    cout << "   |_| |_||_\\___|  \\___/|_||_|_\\___/   |_||_| \\__,_|_|_|" << endl;
    cout << "                                                        " << endl;

    cout << "Your journey starts in Cincinnati, Ohio." << endl;
    cout << "You need to travel to Cleveland, Ohio." << endl;

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Traveler player(playerName);

    int lastEventIndex = -1;  // Initialize to an invalid value

    while (player.distance < 200) {
        displayMap(player);


        simulateEvent(player, lastEventIndex);

        player.distance += 20;
        player.food -= 5;


        cout << "Health: " << player.health << "%" << endl;
        cout << "Money: $" << player.money << endl;
        cout << "Food: " << player.food << " lbs" << endl;
        cout << endl;



        if (player.food < 0 || player.health <= 0 || player.money < 0) {
            cout << "Game Over! " << player.name << " couldn't cut it in Ohio. You suck :)" << endl;
            break;
        }

        int choice;
        cout << "\nOptions:\n";
        cout << "1. Buy Food\n";
        cout << "2. Rest\n";
        cout << "3. Continue\n";
        // Check if the encounter option should be available
        if (lastEventIndex == 2) { // Change this condition to match the specific event index
            cout << "4. Encounter\n"; // New option
        }
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Food is available for $" << cities[player.distance / 100].foodPrice << " per pound." << endl;
            int buyFoodAmount;
            cout << "Enter the amount of food (in pounds) you want to buy: ";
            cin >> buyFoodAmount;
            if (buyFoodAmount * cities[player.distance / 100].foodPrice <= player.money) {
                player.food += buyFoodAmount;
                player.money -= buyFoodAmount * cities[player.distance / 100].foodPrice;
                cout << "You bought " << buyFoodAmount << " pounds of food." << endl;
            }
            else {
                cout << "You don't have enough money to buy that much food." << endl;
            }
            break;

        case 2:
            int restDays;
            cout << "Enter the number of days you want to rest: ";
            cin >> restDays;
            player.days += restDays;
            player.health += restDays * 5;
            if (player.health > 100) {
                player.health = 100;
            }
            break;

        case 3:
            break;


        case 4:
            // Play the Encounter only when the specific event occurs
            if (lastEventIndex == 2) { // Change this condition to match the specific event index
                Encounter wildAnimalEncounter;
                wildAnimalEncounter.play();
            }
            else {
                cout << "No encounter available at the moment." << endl;
            }
            break;

        default:
            cout << "Invalid choice. Please choose a valid option." << endl;

        }

        cout << "\nPress Enter to continue...";
        cin.get();
        cin.ignore();

    }

    if (player.distance >= 200) {
        cout << "\nCongratulations! " << player.name << " made it to Cleveland, Ohio!" << endl;
        cout << "You completed The Ohio Trail in " << player.days << " days." << endl;
        cout << "Unfortunately, you were mauled to death by a bear upon your arrival." << endl;
        cout << "Your final stats:" << endl;
        cout << "Health: " << player.health << "%" << endl;
        cout << "Money: $" << player.money << endl;
        cout << "Food: " << player.food << " lbs" << endl;
    }

    return 0;
}
