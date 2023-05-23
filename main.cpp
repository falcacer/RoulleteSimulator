#include <iostream>
#include <cstdlib>
#include <set>
#include "Player.hpp"

using namespace std;

#define ROULLET 37
#define ITER 10000

// define the types of bets

bool red(int number) {
  set <int> red = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
  return red.count(number);
}

bool black(int number) {
  set <int> black = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
  return black.count(number);
}

bool lower(int number) {
  return 1 <= number and number <= 18;
}

bool higher(int number) {
  return 19 <= number and number <= 36;
}

bool even(int number) {
  return number % 2 == 0 and number != 0;
}

bool odd(int number) {
  return number % 2 != 0;
}

int main() {
  int balance;
  unsigned seed = time(0);
  srand(seed);

  // Initialize all the players and their bet types
  Player playerA, playerB, playerC, playerD, playerE, playerF;
  playerA.init();
  playerA.start();
  playerA.setCondition(red);

  playerB.init();
  playerB.start();
  playerB.setCondition(black);

  playerC.init();
  playerC.start();
  playerC.setCondition(higher);

  playerD.init();
  playerD.start();
  playerD.setCondition(lower);

  playerE.init();
  playerE.start();
  playerE.setCondition(even);

  playerF.init();
  playerF.start();
  playerF.setCondition(odd);
  
  
  for (int i = 0; i < ITER ; i++) {

    int number = rand() % ROULLET;
    cout << "Salio el numero: " << number << endl;
    cout << "Player A: "; playerA.print();
    playerA.bet(number);
    playerA.print();
    cout << "Wallet = " << playerA.wallet << endl;

    cout << "Player B: "; playerB.print();
    playerB.bet(number);
    playerB.print();
    cout << "Wallet = " << playerB.wallet << endl;

    cout << "Player C: "; playerC.print();
    playerC.bet(number);
    playerC.print();
    cout << "Wallet = " << playerC.wallet << endl;

    cout << "Player D: "; playerD.print();
    playerD.bet(number);
    playerD.print();
    cout << "Wallet = " << playerD.wallet << endl;

    cout << "Player E: "; playerE.print();
    playerE.bet(number);
    playerE.print();
    cout << "Wallet = " << playerE.wallet << endl;

    cout << "Player F: "; playerF.print();
    playerF.bet(number);
    playerF.print();  
    cout << "Wallet = " << playerF.wallet << endl;  
  }

  balance = playerA.wallet + playerB.wallet + playerC.wallet +
            playerD.wallet + playerE.wallet + playerF.wallet;
   
  cout << "el balance total es de " << balance << endl;

  playerA.clear();
  playerB.clear();
  playerC.clear();
  playerD.clear();
  playerE.clear();
  playerF.clear();

  return 0;
}