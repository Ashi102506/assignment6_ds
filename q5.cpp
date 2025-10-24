#include <iostream>
using namespace std;

struct N { int data; N* next; };
N* h = NULL;

void ins(int v) {
    N* n = new N{v, NULL};
    if (!h) { h = n; return; }
    N* t = h;
    while (t->next) t = t->next;
    t->next = n;
}

void makeCirc() {
    if (!h) return;
    N* t = h;
    while (t->next) t = t->next;
    t->next = h;
}

bool isCirc() {
    if (!h) return false;
    N* t = h->next;
    while (t && t != h) t = t->next;
    return (t == h);
}

int main() {
    ins(2); ins(4); ins(6); ins(7); ins(5);
    makeCirc();
    cout << (isCirc() ? "True" : "False") << endl;
    return 0;
}
