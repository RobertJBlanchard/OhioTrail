#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

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
    "You found an abandoned wagon with supplies. Gain 20 lbs of food and $50.", // (6)
    "You encountered a bear while hunting. Gain 30 lbs of food but lose 10% health in the process.", // (7)
    "Your wagon broke down, and you had to leave some of your supplies behind. Lose 30 lbs of food and $75.", // (8)
    "You succumbed to a lady of the night. Lose $100, 20% health, and all your dignity.", // (9)
    "Your food supplies were infested with insects. Lose 40 lbs of food.", // (10)
    "You were ambushed by the Bloods. Lose $150 and 25% health.", // (11)
    "Your wagon axle snapped, and you had to walk for miles. Lose $50 and 10% health.", // (12)
    "You contracted AIDS. Lose 50% health and $200 for treatment, if available.", // (13)
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
    "You accidentally left your food out, and it was engulfed by wildlife from a gender reveal. Lose 30 lbs of food.", // (30)
    "You walked by a trainwreck, and your health and food suffered from toxic chemical exposure. Lose 20% health and 20 lbs of food.", // (31)
    "You misplaced your cartoon looking money bag with a big \"$\" on it. Lose $75.", // (32)
    "You encountered a pack of wolves while traveling. Lose 10% health and 15 lbs of food.", // (33)
    "You got caught in a sharknado, which damaged your wagon and supplies. Lose $50 and 20 lbs of food." // (34)
    "You lose your EZ Pass and have to pay a fine for skipping the toll. Lose $80." // (35)
};

void simulateEvent(Traveler& traveler, int& lastEventIndex) {
    int eventIndex;
    do {
        eventIndex = rand() % events.size();
    } while (eventIndex == lastEventIndex);

    lastEventIndex = eventIndex;

    cout << "Day " << traveler.days << ": " << events[eventIndex] << endl;
    traveler.days++;

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
}

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
}

int main() {
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

        cout << "Health: " << player.health << "%" << endl;
        cout << "Money: $" << player.money << endl;
        cout << "Food: " << player.food << " lbs" << endl;

        simulateEvent(player, lastEventIndex);

        player.distance += 20;
        player.food -= 5;

        if (player.food < 0 || player.health <= 0 || player.money < 0) {
            cout << "Game Over! " << player.name << " couldn't make it to Cleveland, Ohio. You suck :)" << endl;
            break;
        }

        int choice;
        cout << "\nOptions:\n";
        cout << "1. Buy Food\n";
        cout << "2. Rest\n";
        cout << "3. Continue\n";
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
