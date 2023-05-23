#include <iostream>
using namespace std;

#define MAX 4000
#define MIN 5

typedef bool (*Condition)(int);

class Player {
  public: 
    struct Node {
    int data;
    Node* next;
    Node* prev;
    };
    Node* head;
    Node* last;
    int wallet;
    Condition condition;

    void setCondition(Condition cond) {
      condition = cond;
    }

    void init() {
      head = nullptr;
      last = nullptr;
      wallet = 0;
    };

    void start() {
      insert(1);
      insert(2);
      insert(3);
      insert(4);
    }

    void insert(int data) {
      // Creates a node an push it to the end of the list. O(1)
      Node* newNode = new Node;
      newNode->data = data;
      newNode->next = nullptr;

      if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        last = newNode;
      } 
      else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
      }
    };

    void deleteHead() {
      // Deletes the first element of the list. O(1)
      if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) { head->prev = nullptr; } else { last = nullptr; }
        delete temp;
      }
    };

    void deleteLast() {
      // Deletes the last element of the list. O(1)
      if (last == nullptr) {
        return;
      }

      if (head == last) {
        delete last;
        head = nullptr;
        last = nullptr;
      } 
      else {
        Node* prevNode = last->prev;
        prevNode->next = nullptr;
        delete last;
        last = prevNode;
      }
    };

    void clear() {
      // Clear the list. O(n)
      Node* current = head;
      while (current != nullptr) {
      Node* nextNode = current->next;
      delete current;
      current = nextNode;
      }
      head = nullptr;
      last = nullptr;
    };

    void won(int amount) {
      insert(amount);
    };

    void loss() {
      deleteHead();
      deleteLast();
      };


    int checkBet() {
      int bet;
      if (head != nullptr) {
        if (head->next == nullptr) { bet = head->data;}
        else { bet = head->data + last->data;}
        if (bet < MIN or bet > MAX) {
        cout << "Bet not supported by the table, return to initial bet" << endl;
        clear();
        start();
        print();
        return head->data + last->data;
        }
        return bet;
      }
      else {
        cout << "No bet available, return to initial bet" << endl;
        start();
        print();
        return head->data + last->data;
      }
    };

    void bet(int number, int amount) {
      if (condition(number)) {
        wallet += amount;
        won(amount);
      } else {
        wallet -= amount;
        loss();
      }
    };

    void print() {
      cout << "[ ";
      Node* current = head;
      while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
      }
      cout << "]" << endl;
    };
};
