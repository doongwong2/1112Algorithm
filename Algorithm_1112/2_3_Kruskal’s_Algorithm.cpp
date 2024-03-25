#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<algorithm>  
using namespace std;

typedef struct vertex* nptr;
struct vertex {
    int head, end, value;
};

typedef struct edge* edgepointer;
struct edge {
    int val;
    edgepointer next;
};
edgepointer arr[40000];
int parent[40000];
int R[40000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void findingParent(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (R[rootX] < R[rootY]) {
        parent[rootX] = rootY;
    }
    else if (R[rootX] > R[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        R[rootX]++;
    }
}

int compare(const void* a, const void* b) {
    nptr val1 = (nptr)a;
    nptr val2 = (nptr)b;
    return val1->value - val2->value;
}

void push(int a, int b) {
    edgepointer end = new struct edge;
    edgepointer foo = new struct edge;
    foo->val = b;
    foo->next = NULL;
    if (arr[a] == NULL) {
        arr[a] = foo;
    }
    else {
        end = arr[a];
        while (end->next != NULL) end = end->next;
        end->next = foo;
    }
    end = new struct edge;
    foo = new struct edge;
    foo->val = a;
    foo->next = NULL;
    if (arr[b] == NULL) {
        arr[b] = foo;
    }
    else {
        end = arr[b];
        while (end->next != NULL) end = end->next;
        end->next = foo;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int idx = 0, uplimit = 0;
    struct vertex adj[40000];
    while (cin >> adj[idx].head >> adj[idx].end >> adj[idx].value) {
        uplimit = max(max(uplimit, adj[idx].head), adj[idx].end);
        idx++;
    }

    for (int i = 0; i < idx; i++) {
        push(adj[i].head, adj[i].end);

        parent[i] = i;
        R[i] = 0;
    }
    cout << "Adjacency list:" << endl;
    edgepointer end;
    for (int i = 0; i <= uplimit; i++) {
        if (arr[i]) {
            cout << i << ": ";
            end = arr[i];
            while (end != NULL) {
                cout << end->val;
                end = end->next;
                if (!end) cout << " -> end";
                else cout << " -> ";
            }
            cout << endl;
        }
    }

    qsort(adj, idx, sizeof(struct vertex), compare);
    cout << "\nminimum spanning tree:\n";
    int count = 1, min = 0;
    for (int i = 0; i < idx; i++) {
        int x = find(adj[i].head), y = find(adj[i].end);
        if (x != y) {
            findingParent(x, y);
            min += adj[i].value;
            cout << count++ << ": <" << adj[i].head << "," << adj[i].end << ">\n";
        }
    }
    cout << "\nThe cost of minimum spanning tree: " << min << endl;

    return 0;
}