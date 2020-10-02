#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}


int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(1,1e5);
    printf("%d\n", n);
    for(int i = 0; i < n; ++i) {
        int s,e,p;
        s = rand(1,1e9);
        e = rand(1,1e9);
        p = rand(1,1e9);
        if (s > e) swap(s,e);
        printf("%d %d %d\n",s,e,p);
    }
    puts("");
}
