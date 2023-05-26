#include <iostream>
#include <cstdlib>
#include <set>
#include "Player.hpp"

using namespace std;

// define the types of bets in the roullete
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

  const int ITER = 10000; // numbers in the roullete
  const int ROULLETTE = 37; // number of simulations

  int balance, amountA, amountB, amountC, amountD, amountE, amountF;
  unsigned seed = time(0);
  srand(seed);

  // Initialize all the players and their bet types
  Player playerA, playerB, playerC, playerD, playerE, playerF;
  playerA.init();
  playerA.start();
  playerA.setBet(red);

  playerB.init();
  playerB.start();
  playerB.setBet(black);

  playerC.init();
  playerC.start();
  playerC.setBet(higher);

  playerD.init();
  playerD.start();
  playerD.setBet(lower);

  playerE.init();
  playerE.start();
  playerE.setBet(even);

  playerF.init();
  playerF.start();
  playerF.setBet(odd);
  
  
  for (int i = 0; i < ITER ; i++) {

    // Here we analyze the bets of each player to check that they are ok
    cout << "Player A:" << endl;
    playerA.print();
    amountA = playerA.checkBet();
    cout << "Player B:" << endl;
    playerB.print();
    amountB = playerB.checkBet();
    cout << "Player C:" << endl;
    playerC.print();
    amountC = playerC.checkBet();
    cout << "Player D:" << endl;
    playerD.print();
    amountD = playerD.checkBet();
    cout << "Player E:" << endl;
    playerE.print();
    amountE = playerE.checkBet();
    cout << "Player F:" << endl;
    playerF.print();
    amountF = playerF.checkBet();

    // The roullette gives the number
    int number = rand() % ROULLETTE;
    cout << "Number : * " << number << " *" << endl;

    // Here the casino settle the bets
    playerA.settle(number, amountA);
    playerB.settle(number, amountB);
    playerC.settle(number, amountC);
    playerD.settle(number, amountD);
    playerE.settle(number, amountE);
    playerF.settle(number, amountF);

    // Here we print the bets of each player after the settle
    cout << "Player A:" << endl;
    playerA.print();
    cout << "PlayerA Wallet = " << playerA.wallet << endl;
    cout << "Player B:" << endl;
    playerB.print();
    cout << "PlayerB Wallet = " << playerB.wallet << endl;
    cout << "Player C:" << endl;
    playerC.print();
    cout << "PlayerC Wallet = " << playerC.wallet << endl;
    cout << "Player D:" << endl;
    playerD.print();
    cout << "PlayerD Wallet = " << playerD.wallet << endl;
    cout << "Player E:" << endl;
    playerE.print();
    cout << "PlayerE Wallet = " << playerE.wallet << endl;
    cout << "Player F:" << endl;
    playerF.print();
    cout << "PlayerF Wallet = " << playerF.wallet << endl;
    cout << "-------------------" << endl;
  }

  balance = playerA.wallet + playerB.wallet + playerC.wallet +
            playerD.wallet + playerE.wallet + playerF.wallet;

  cout << "The total balance is " << balance << endl;

  // Here we clear the bets in memory
  playerA.clear();
  playerB.clear();
  playerC.clear();
  playerD.clear();
  playerE.clear();
  playerF.clear();

  return 0;
}