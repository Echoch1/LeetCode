#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(2, 0);
        for (int i = 0; i < nums1.size(); i++) {
            res[0] += find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end();
        }
        for (int i = 0; i < nums2.size(); i++) {
            res[1] += find(nums1.begin(), nums1.end(), nums2[i]) != nums1.end();
        }
        return res;
    }
};