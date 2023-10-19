#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000000

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<std::vector<int> > dp;
    std::vector<int> temp_vec;
    std::vector<int> size;

    // Inicjalizacja dp i = 0
    temp_vec.push_back(0);
    dp.push_back(temp_vec);
    size.push_back(temp_vec.size());
    
    // Inicjalizacja dp i = 1
    temp_vec.clear();
    for (int j = 0; j <= k; j++) {
        temp_vec.push_back(j);
    }
    dp.push_back(temp_vec);
    size.push_back(temp_vec.size());
    temp_vec.clear();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < size[i-1]; j++) {
            temp_vec.push_back(dp[i - 1][j]);
            if (dp[i - 1][j] > 0) temp_vec.push_back(dp[i - 1][j]-1);
            if (dp[i - 1][j] < k) temp_vec.push_back(dp[i - 1][j]+1);
            
        }
        dp.push_back(temp_vec);
        size.push_back(temp_vec.size());
        temp_vec.clear();
    }


    // Wyświetlenie wyniku
    for (int i = 0; i < n; i++) {
        std::cout << size[d[i]]%MOD << " ";
    }
    std::cout << std::endl;

    return 0;
}
