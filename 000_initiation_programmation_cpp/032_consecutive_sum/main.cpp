//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <vector>

using namespace std;

int somme_consecutifs_max(const vector<int> &v);

vector<size_t> lignes_max(const vector<vector<int>> &v);

vector<vector<int>> tranches_max(const vector<vector<int>> &v);

int main() {
    cout << somme_consecutifs_max({0, 2, 2, 0}) << endl;
    {

        vector<vector<int>> arr{
                {2, 1, 0, 2,},
                {0, 1, 0, 3,},
                {1, 3, 0, 0,},
                {0, 2, 2, 0,},
        };
        tranches_max(arr);
    }

    {
        vector<vector<int>> arr = {
                {2, 1, 0, 2, 0, 3, 2},
                {0, 1, 0, 7, 0},
                {1, 0, 1, 3, 2, 0, 3, 0, 4,},
                {5, 0, 5,},
                {1, 1, 1, 1, 1, 1, 1,},
        };
        tranches_max(arr);
    }
    return 0;
}

int somme_consecutifs_max(const vector<int> &v) {
    int sum(0), best(INT_MIN);
    for (const int e: v) {
        sum = (e == 0) ? 0 : sum + e;
        if (sum > best) {
            best = sum;
        }
    }
    return best;
}

vector<size_t> lignes_max(const vector<vector<int>> &v) {
    vector<size_t> res;
    int best(INT_MIN);
    for (size_t i(0); i < v.size(); ++i) {
        const int max = somme_consecutifs_max(v[i]);
        if (max > best) {
            res = {i};
            best = max;
        } else if (max == best) {
            res.push_back(i);
        }
    }
    return res;
}

vector<vector<int>> tranches_max(const vector<vector<int>> &v) {
    vector<vector<int>> res;
    const vector<size_t> indexes = lignes_max(v);
    for (auto i: indexes) {
        res.push_back(v[i]);
    }
    return res;
}