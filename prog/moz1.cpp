/*
Rozwiązanie wzorcowe do zadania MOZ (Mozaika)
Autor: Marcin Wierzbiński
Data: 17.10.2022
Opis: Dynamik w czasie O(n*k)
*/

#include <iostream>
#include <vector>


int main() {
    int n, k;
    int q = 1e9;
    std::cin >> n >> k;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<int> dp(k + 1, 0);
    std::vector<int> dp_prev(k + 1, 0);
    std::vector<int> wynik(n, 0);

    // Inicjalizacja dp
    for (int i = 0; i <= k; i++) {
        dp_prev[i] = 1;
    }
    wynik[1] = k+1;



    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[j] = dp_prev[j];
            if (j > 0) dp[j] += dp_prev[j - 1];
            dp[j] %= q;
            if (j < k) dp[j] += dp_prev[j + 1];
            dp[j] %= q;
        }
        // policz i zapisz wynik dla danej dlugosci i
        int sum = 0;
        for(int j = 0; j <= k; j++){
            sum += dp[j];
            sum %= q;
        }
        wynik[i] = sum;

        // Przesun aktualny wektor na poprzedni
        for(int j = 0; j <= k; j++){
            dp_prev[j] = dp[j];
        }
    }

    // Wyświetlenie wyniku
    for (int i = 0; i < n; i++) {
        std::cout << wynik[d[i]] << " ";
    }
    std::cout << std::endl;

    return 0;
}
