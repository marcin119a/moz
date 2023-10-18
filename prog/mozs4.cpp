/*
 * Rozwiązanie brutalne
 * Autor: Marcin Wierzbiński
 */
#include <iostream>
#include <vector>

int l;

bool is_valid_sequence(const std::vector<int>& sequence, int k) {
    for (int i = 1; i < sequence.size(); ++i) {
        if (abs(sequence[i] - sequence[i - 1]) > 1 || sequence[i] > k) {
            return false;
        }
    }
    return true;
}

int count_valid_sequences(int n, int k) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    std::vector<int> sequence(n, 0);
    while (sequence[0] <= k) {
        if (is_valid_sequence(sequence, k)) {
            count++;
        }
        int i = n - 1;
        while (i >= 0 && sequence[i] == k) {
            i--;
        }
        if (i < 0) {
            break;
        }
        sequence[i]++;
        for (int j = i + 1; j < n; j++) {
            sequence[j] = 0;
        }
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n >> k >> l;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    for (int i = 0; i < n; i++) {
        int result = count_valid_sequences(d[i], k) % l;
        std::cout << result << " ";
    }

    return 0;
}
