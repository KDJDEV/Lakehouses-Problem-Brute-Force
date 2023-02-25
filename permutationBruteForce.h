#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#pragma once

using namespace std;

class PermutationBruteForcer {
    vector<int> nums;
    vector<int> combination;

    bool testCombination(const vector<int>& combination) {
        //check for differences 1-13
        for (int x = 1; x <= 13;x++) {
            bool foundDifference = false;
            for (int num : combination) {
                for (int compareNum : combination) {
                    if (abs(num - compareNum) == x || abs(num - compareNum) == 27 - x) { //the difference can be on either side, so also check for difference of x as well as 23-x
                        foundDifference = true;
                        break;
                    }
                }
                if (foundDifference) break;
            }
            if (!foundDifference) return false;
        }

        for (int i = 0; i < combination.size() - 1; ++i) {
            if (combination[i + 1] - combination[i] < 1) { //make sure we don't have negative relative values
                return false;
            }
        }
        return true;
    }

    void prettyPrint(const vector<int>& v) {
        cout << "[ ";
        for (int i = 0; i < v.size(); ++i) { cout << v[i]; if (i != v.size() - 1) { cout << ","; } cout << " "; }
        cout << "] " << endl;
    }
    vector<int> convertToRelativeDistances(const vector<int>& combination) { //basically a discrete derivative but where we add on a value that loops us back around at the end
        vector<int> newCombination;
        for (int i = 0; i < combination.size() - 1; ++i) {
            newCombination.push_back(combination[i + 1] - combination[i]);
        }
        newCombination.push_back(27 + combination[0] - combination[combination.size() - 1]);
        return newCombination;
    }

    set<vector<int>> relativeVectorList;

    //generates all combinations recursively
    void go() {
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                for (int k = 0; k <= 26; k++) {
                    for (int l = 0; l <= 26; l++) {
                        for (int m = 0; m <= 26; m++) {
                            for (int n = 0; n <= 26; n++) {
                                vector<int> combinationCopy = { i, j, k, l, m, n };
                                bool works = testCombination(combinationCopy);
                                if (works == true) {
                                    relativeVectorList.insert(convertToRelativeDistances(combinationCopy));
                                }
                            }
                        }
                    }
                }
            }
            std::cout << (i / 26.0f) * 100 << "% complete \n";
        }
        return;
    }
    bool compareVectors(const std::vector<int>& a, const std::vector<int>& b) {
        return a < b;
    }
public:
    void run() {

        int n = 26, k = 6; //n=26 because we are starting at position index 0

        for (int i = 0; i <= n; ++i) { nums.push_back(i); }
        go();

        int count = 0;
        for (vector<int> relativeVec : relativeVectorList) {
            cout << "combination no " << (++count) << ":";

            prettyPrint(relativeVec);
        }
    }
};