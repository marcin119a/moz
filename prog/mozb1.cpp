/*
Rozwiązanie błedne do zadania MOZ (Mozaika)
Data: 17.10.2022
*/

#include <iostream>
#include <vector>
#define MOD 1000000000

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
    std::vector<int> wynik(n, 0);

    // Inicjalizacja dp
    for (int j = 0; j <= k; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            if (j < k) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    // Obliczenia wyniku
    for (int i = 0; i < n; i++) {
        wynik[i] = 0;
        for (int j = 0; j <= k; j++) {
            wynik[i] += dp[d[i]][j];
            // wynik[i] %= MOD;
        }
    }

    // Wyświetlenie wyniku
    for (int i = 0; i < n; i++) {
        std::cout << wynik[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
