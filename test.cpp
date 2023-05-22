#include <iostream>
#include <set>
#include "Player.hpp"
using namespace std;


bool lower(int number) {
  return 1 <= number and number <= 18;
}

int main() {
  int number = 10;
  Player playerA;
  playerA.init();
  playerA.setCondition(lower);
  playerA.insert(4000);
  playerA.print();
  playerA.bet(19);
  playerA.print();
  cout << "Wallet = " << playerA.wallet << endl;
  
  return 0;
}