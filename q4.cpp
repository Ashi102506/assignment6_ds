#include <iostream>
using namespace std;

struct N { char data; N *next, *prev; };
N* h = NULL;

void ins(char v) {
    N* n = new N{v, NULL, NULL};
    if (!h) { h = n; return; }
    N* t = h;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

bool isPal() {
    if (!h) return true;
    N *l = h, *r = h;
    while (r->next) r = r->next;
    while (l != r && l->prev != r) {
        if (l->data != r->data) return false;
        l = l->next; r = r->prev;
    }
    return true;
}

int main() {
    ins('L'); ins('E'); ins('V'); ins('E'); ins('L');
    cout << (isPal() ? "True" : "False") << endl;
    return 0;
}
