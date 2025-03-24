#include "Game.h"
#include <iostream>
using namespace std;

void battle(Player& player, Enemy& enemy) {
    cout << "A " << enemy.getName() << " appears!" << endl;
    while (player.isAlive() && enemy.isAlive()) {
        player.attackTarget(enemy);
        if (enemy.isAlive()) {
            enemy.attackTarget(player);
        }
        if (player.isAlive()) {
            cout << "Do you want to use an item? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y') {
                player.useItem();
            }
        }
    }
    if (player.isAlive()) {
        cout << "You defeated the " << enemy.getName() << "!" << endl;
    } else {
        cout << "You were defeated... Game Over!" << endl;
    }
}
