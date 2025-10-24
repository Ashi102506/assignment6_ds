#include <iostream>
using namespace std;

struct NC { int data; NC* next; };
struct ND { int data; ND *next, *prev; };

NC* hc = NULL;
ND* hd = NULL;

void insFirstC(int v) {
    NC* n = new NC{v, hc};
    if (!hc) { hc = n; n->next = hc; return; }
    NC* t = hc;
    while (t->next != hc) t = t->next;
    t->next = n; n->next = hc; hc = n;
}

void insLastC(int v) {
    NC* n = new NC{v, NULL};
    if (!hc) { hc = n; n->next = hc; return; }
    NC* t = hc;
    while (t->next != hc) t = t->next;
    t->next = n; n->next = hc;
}

void delC(int v) {
    if (!hc) return;
    if (hc->data == v) {
        NC* t = hc;
        while (t->next != hc) t = t->next;
        if (hc == t) { delete hc; hc = NULL; return; }
        t->next = hc->next; delete hc; hc = t->next;
        return;
    }
    NC* t = hc;
    while (t->next != hc && t->next->data != v) t = t->next;
    if (t->next->data == v) { NC* d = t->next; t->next = d->next; delete d; }
}

void searchC(int v) {
    if (!hc) return;
    NC* t = hc; int p = 1;
    do {
        if (t->data == v) { cout << "Found at " << p << endl; return; }
        t = t->next; p++;
    } while (t != hc);
    cout << "Not found\n";
}

void dispC() {
    if (!hc) return;
    NC* t = hc;
    do { cout << t->data << " "; t = t->next; } while (t != hc);
    cout << endl;
}

void insFirstD(int v) {
    ND* n = new ND{v, hd, NULL};
    if (hd) hd->prev = n;
    hd = n;
}

void insLastD(int v) {
    ND* n = new ND{v, NULL, NULL};
    if (!hd) { hd = n; return; }
    ND* t = hd;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

void delD(int v) {
    ND* t = hd;
    while (t && t->data != v) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next; else hd = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

void searchD(int v) {
    ND* t = hd; int p = 1;
    while (t) {
        if (t->data == v) { cout << "Found at " << p << endl; return; }
        t = t->next; p++;
    }
    cout << "Not found\n";
}

void dispD() {
    ND* t = hd;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;
}

int main() {
    int c, t, v;
    while (1) {
        cout << "\n1.Circular 2.Doubly 3.Exit: "; cin >> t;
        if (t == 3) break;
        cout << "1.InsFirst 2.InsLast 3.Delete 4.Search 5.Display: "; cin >> c;
        if (c <= 2) { cout << "Value: "; cin >> v; }
        else if (c == 3 || c == 4) { cout << "Value: "; cin >> v; }
        
        if (t == 1) {
            if (c == 1) insFirstC(v);
            else if (c == 2) insLastC(v);
            else if (c == 3) delC(v);
            else if (c == 4) searchC(v);
            else if (c == 5) dispC();
        } else {
            if (c == 1) insFirstD(v);
            else if (c == 2) insLastD(v);
            else if (c == 3) delD(v);
            else if (c == 4) searchD(v);
            else if (c == 5) dispD();
        }
    }
    return 0;
}
