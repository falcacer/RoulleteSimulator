#include <iostream>
#include <cstdlib>
#include <set>
#include "Player.hpp"

using namespace std;

#define ROULLETE 37
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
  int balance, amountA, amountB, amountC, amountD, amountE, amountF;
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

    int number = rand() % ROULLETE;

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
    cout << "Number : * " << number << " *" << endl;
    playerA.bet(number, amountA);
    playerB.bet(number, amountB);
    playerC.bet(number, amountC);
    playerD.bet(number, amountD);
    playerE.bet(number, amountE);
    playerF.bet(number, amountF);
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

  cout << "el balance total es de " << balance << endl;

  playerA.clear();
  playerB.clear();
  playerC.clear();
  playerD.clear();
  playerE.clear();
  playerF.clear();

  return 0;
}