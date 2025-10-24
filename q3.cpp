#include <iostream>
using namespace std;

struct NC { int data; NC* next; };
struct ND { int data; ND *next, *prev; };

NC* hc = NULL;
ND* hd = NULL;

void insC(int v) {
    NC* n = new NC{v, NULL};
    if (!hc) { hc = n; n->next = hc; return; }
    NC* t = hc;
    while (t->next != hc) t = t->next;
    t->next = n; n->next = hc;
}

void insD(int v) {
    ND* n = new ND{v, NULL, NULL};
    if (!hd) { hd = n; return; }
    ND* t = hd;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

int sizeD() {
    int c = 0; ND* t = hd;
    while (t) { c++; t = t->next; }
    return c;
}

int sizeC() {
    if (!hc) return 0;
    int c = 0; NC* t = hc;
    do { c++; t = t->next; } while (t != hc);
    return c;
}

int main() {
    insD(10); insD(20); insD(30); insD(40);
    insC(5); insC(15); insC(25);
    
    cout << "Doubly Linked List size: " << sizeD() << endl;
    cout << "Circular Linked List size: " << sizeC() << endl;
    return 0;
}
