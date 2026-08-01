// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// PART A - Print the First N Terms
// PART B - Check if a Number Belongs to the Sequence
//
// =============================================================================

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
void printFibonacci(int n) {
    int a = 0, b = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";

        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
bool isFibonacci(int num) {
    if (num < 0) {
        return false;
    }

    int a = 0, b = 1;

    // Special case: 0 is always the first Fibonacci number
    if (num == a) {
        return true;
    }

    // Generate terms until we reach or pass num
    while (b < num) {
        int next = a + b;
        a = b;
        b = next;
    }

    return (b == num);
}

// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------
int main() {
    // ---------------- PART A ----------------
    int n;

    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    printFibonacci(n);

    // ---------------- PART B ----------------
    int num;

    cout << "\nEnter a number to check: ";
    cin >> num;

    if (isFibonacci(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}