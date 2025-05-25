#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; ++i) cin >> values[i];

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Step 1: Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Step 2: Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Step 3: Backtrack to find selected items
    int w = W;
    vector<int> selectedWeights, selectedValues;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedWeights.push_back(weights[i - 1]);
            selectedValues.push_back(values[i - 1]);
            w -= weights[i - 1];
        }
    }

    // Step 4: Output
    cout << "Value = " << dp[n][W] << endl;
    cout << "Weights selected : ";
    for (int i = selectedWeights.size() - 1; i >= 0; --i)
        cout << selectedWeights[i] << " ";
    cout << endl;

    cout << "Values of selected weights : ";
    for (int i = selectedValues.size() - 1; i >= 0; --i)
        cout << selectedValues[i] << " ";
    cout << endl;

    return 0;
}
