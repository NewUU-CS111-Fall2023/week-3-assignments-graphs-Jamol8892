#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int a, int b) {
    if (a > b) {
        return false;
    }

    while (a < b) {
        if (b % 2 == 0) {
            b /= 2;
        } else {
            b = b * 10 + 1;
        }

        if (a == b) {
            return true;
        }
    }

    return false;
}

vector<int> findTransformationSequence(int a, int b) {
    vector<int> sequence;

    while (a < b) {
        if (b % 2 == 0) {
            sequence.push_back(b / 2);
            b /= 2;
        } else {
            sequence.push_back(b - 1);
            b = b * 10 + 1;
        }
    }

    sequence.push_back(a);
    reverse(sequence.begin(), sequence.end());

    return sequence;
}

