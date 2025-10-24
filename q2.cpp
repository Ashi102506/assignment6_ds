#include <iostream>
using namespace std;

struct N { int data; N* next; };
N* h = NULL;

void ins(int v) {
    N* n = new N{v, NULL};
    if (!h) { h = n; n->next = h; return; }
    N* t = h;
    while (t->next != h) t = t->next;
    t->next = n; n->next = h;
}

void disp() {
    if (!h) return;
    N* t = h;
    do { cout << t->data << " "; t = t->next; } while (t != h);
    cout << h->data << endl;
}

int main() {
    ins(20); ins(100); ins(40); ins(80); ins(60);
    cout << "Output: ";
    disp();
    return 0;
}
