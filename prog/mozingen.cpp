#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#include "oi.h"
using namespace oi;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

#define ZAD "moz"

const int N = 1000;
const int MAXV = 1000000000;

Random RG;

char test_name[100];

struct Test {
    int n, k, l;
    vector<int> vals;

    Test() {}

    Test(int _n, int _k, int _l) : n(_n), k(_k), l(_l) {}

    void print(const char *name) {
        freopen(name, "w", stdout);
        fprintf(stderr, "Generating %s\n", name);

        RG.randomShuffle(vals.begin(), vals.end());

        printf("%d %d %d\n", n, k, l);
        for (int i=0; i<(int)vals.size() - 1; i++)
            printf("%d ", vals[i]);
        printf("%d\n", vals.back());
    }
};


int rand_range(int p, int k) {
    return p + RG.rand() % (k - p + 1);
}

Test full_random(int min_n, int max_n, int min_v, int max_v, int seed) {
    RG.setSeed(seed);
    Test t;

    t.n = rand_range(min_n, max_n);
    t.k = rand_range(0, max_v - min_v + 1);
    t.l = rand_range(0, max_v - min_v + 1);

    for (int i=0; i<t.n; i++)
        t.vals.push_back(rand_range(min_v, max_v));

    return t;
}

Test random_vals(int n, int k, int l, int min_v, int max_v, int seed) {
    RG.setSeed(seed);
    Test t;

    t.n = n;
    t.k = k;
    t.l = l;

    for (int i=0; i<t.n; i++)
        t.vals.push_back(rand_range(min_v, max_v));

    return t;
}

Test repeats(int n, int k, int l, int min_v, int max_v, int val_cnt, int seed) {
    RG.setSeed(seed);
    Test t;

    t.n = n;
    t.k = k;
    t.l = l;

    vector<int> vals;
    for (int i=0; i<val_cnt; i++)
        vals.push_back(rand_range(min_v, max_v));

    for (int i=0; i<t.n; i++)
        t.vals.push_back(vals[rand_range(0, vals.size() - 1)]);

    return t;
}

Test groups(int n, int k, int l, int min_v, int max_v, int n_centers, int range, int seed) {
    RG.setSeed(seed);
    Test t;

    t.n = n;
    t.k = k;
    t.l = l;

    vector<int> centers;
    for (int i=0; i<n_centers; i++)
        centers.push_back(rand_range(min_v, max_v));

    for (int i=0; i<t.n; i++) {
        int c = centers[rand_range(0, centers.size() - 1)];
        int v = rand_range(max(min_v, c - range), min(max_v, c + range));
        t.vals.push_back(v);
    }

    return t;
}

Test divisible() {
    // Wynik jest podzielny przez 10^9+7
    Test t;
    const int X = 1000;
    t.k = 10;
    t.l = 21;

    for (size_t i = 1; i < 11; i++)
        t.vals.push_back(i);
    for (size_t i = 0; i < X; i++)
        t.vals.push_back(11);
    for (size_t i = 12; i < 32; i++)
        t.vals.push_back(i);
    for (size_t i = 0; i < X; i++)
        t.vals.push_back(32);
    for (size_t i = 33; i < 53; i++)
        t.vals.push_back(i);
    for (size_t i = 0; i < X; i++)
        t.vals.push_back(53);
    for (size_t i = 54; i < 57; i++)
        t.vals.push_back(i);
    t.vals.push_back(1000000);

    t.n = t.vals.size();

    return t;
}

int main() {
    std::vector<std::vector<Test>> tests = {
            {
                    // n <= 20
                    random_vals(1, 10, 20, 5, 5, 647326),
                    random_vals(5, 8, 3, 12, 12, 234892),
                    full_random(2, 20, 0, 10, 91723),
                    full_random(2, 20, 0, 10, 82374),
                    full_random(2, 20, 0, 10, 98234),
                    full_random(2, 20, 0, 10, 89734),
                    full_random(2, 20, 0, 20, 34763),
                    full_random(2, 20, 0, 20, 37438),
                    full_random(2, 20, 0, 20, 77234),
                    full_random(2, 20, 0, 20, 35656),
            },
            {
                    // n <= 1000
                    random_vals(1000, 10, 4, 0, 10000, 987434),
                    random_vals(1000, 100, 13, 0, 10000, 3458745),
                    random_vals(1000, 50, 30, 0, 10000, 64475),
                    random_vals(1000, 8, 3, 0, 1000, 457459),
                    random_vals(1000, 20, 5, MAXV - 10000, MAXV, 77346),
                    groups(1000, 40, 8, 0, 20000, 40, 50, 876876),
                    groups(1000, 107, 300, 0, MAXV, 7, 50, 98243793),
            },
            {
                    // n <= N
                    random_vals(N, 100, 53, 0, N, 4684783),
                    random_vals(N, 10000, 512, 0, N, 3438973),
                    random_vals(N, 100000, 4321, 0, N, 79348579),
                    random_vals(N, 20, 5, 0, 10*N, 4234877),
                    random_vals(N, 1000, 316, 0, MAXV, 892374),
                    random_vals(N, 10000, 72, 0, MAXV, 8374444),
                    random_vals(N, 100000, 2048, 0, MAXV, 7738473),
                    random_vals(N, MAXV, 1024, 0, MAXV/2, 774858),
                    random_vals(N, 5, 1, 0, 100, 299394),
                    random_vals(N, 216, 7, 0, N, 8899564),
// 			random_vals(N, 1000, 1990, 0, 10*N, 323343),
// 			random_vals(N, 10'000, 19'985, 0, 15*N, 368848),
// 			random_vals(N, 10'000, 20'127, 0, 2*N, 23478932),
                    groups(N, 10000, 543, 0, MAXV, 1000, 20000, 457934),
                    groups(N, 234560, 600000, 0, MAXV, 37, 100000, 3353675),
            },
            {
                    // n <= N
                    random_vals(N, 100, 53, 0, N, 456578),
                    random_vals(N, 10000, 428, 0, N, 683465),
                    random_vals(N, 100000, 23775, 0, N, 1349045),
                    random_vals(N, 20, 5, 0, 10*N, 284566),
                    random_vals(N, 1000, 316, 0, MAXV, 640335),
                    random_vals(N, 10000, 72, 0, MAXV, 17477836),
                    random_vals(N, 100000, 2048, 0, MAXV, 8468764),
                    random_vals(N, MAXV, 1024, 0, MAXV/2, 384678),
                    random_vals(N, 5, 1, 0, 100, 8328932),
                    random_vals(N, 216, 7, 0, N, 25889),
// 			random_vals(N, 79, 150, 0, 10*N, 3589),
                    random_vals(N, 100000, 199985, MAXV - 15*N, MAXV, 3457444),
                    random_vals(N, 175000, 350005, 120*N, 125*N, 7747748),
                    groups(N, 2500, 248, 0, 4*N, 1000, 1000, 364534),
                    groups(N, 2004560, 4600000, 0, MAXV, 10, 20000, 76754768),
                    divisible(),
            },
    };

    for (int p_id=0; p_id<(int)tests.size(); p_id++) {
        for (int t_id=0; t_id<(int)tests[p_id].size(); t_id++) {
            sprintf(test_name, "%s%d%c.in", ZAD, p_id+1, 'a'+t_id);
            tests[p_id][t_id].print(test_name);
        }
    }

    return 0;
}
