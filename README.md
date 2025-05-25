# 🧮 0/1 Knapsack Problem – Dynamic Programming Solution

This program solves the classic **0/1 Knapsack Problem** using dynamic programming. It calculates the maximum value that can be carried in a knapsack of given capacity and lists the items included in the optimal solution.

## 📌 Problem Statement

Given `n` items, each with a weight and a value, and a knapsack with a maximum weight capacity `W`, determine the maximum total value that can be carried in the knapsack without exceeding the weight limit. Each item can either be included **once** or not at all.

## 🛠 Features

- Accepts user input for item weights, values, and knapsack capacity.
- Uses dynamic programming to fill a DP table.
- Backtracks through the table to identify the selected items.
- Outputs the total value and the items chosen.

## 🧾 Input Format

1. Number of items (`n`)
2. List of `n` item weights
3. List of `n` item values
4. Knapsack capacity (`W`)

### 📥 Example Input

```
Enter number of items: 4  
Enter weights of items:  
2 3 4 5  
Enter values of items:  
3 4 5 6  
Enter knapsack capacity: 5  
```

### 📤 Example Output

```
Value = 7  
Weights selected : 2 3  
Values of selected weights : 3 4  
```

## 🧠 How It Works

1. **DP Table Construction**  
   A 2D array `dp[i][w]` holds the maximum value for the first `i` items and capacity `w`.

2. **Transition Formula**  
   - If the current item's weight ≤ capacity:  
     `dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w - weight[i-1]])`
   - Else:  
     `dp[i][w] = dp[i-1][w]`

3. **Backtracking**  
   Starting from `dp[n][W]`, trace back to find which items were included.

## 🧑‍💻 How to Run

### Compile:
```bash
g++ 01Knapsack.cpp -o 01Knapsack
```

### Run:
```bash
./01Knapsack
```

## 📄 File Structure

```
01Knapsack.cpp     # Main program file
README.md        # This file
```

## 📚 Concepts Used

- Dynamic Programming
- 2D Table Construction
- Backtracking for solution reconstruction

## ✍️ Author

Written in C++ by Aishna
