// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        int one = 0, two = 0;
        
        for (auto& i : A) {
            int new_one, new_two;
            new_one = (~i & one) | (i & ~one & ~two);
            new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }
        
        return one;
    }
};
