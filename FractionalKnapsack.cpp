#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int value;
    int weight;
    
    // Constructor for easier initialization
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool cmp(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item>& items, int n) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), cmp);
    
    double totalValue = 0.0;  // Total value in the knapsack
    int currentWeight = 0;  // Current weight of the knapsack
    
    // Loop through each item
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            // If the item can be taken completely, take it
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the item that fits in the remaining capacity
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;  // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n, W;
    
    // Ask user for the number of items and the capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items;

    // Ask user to input the value and weight of each item
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> value;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weight;
        items.push_back(Item(value, weight));  // Directly push back Item with value and weight
    }

    // Call fractionalKnapsack function to compute the maximum value
    double maxValue = fractionalKnapsack(W, items, n);

    // Output the result
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}

