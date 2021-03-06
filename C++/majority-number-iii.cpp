// Time:  O(n)
// Space: O(k)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        
        for (auto& i : nums) {
            ++hash[i];
            // Detecting k items in hash, at least one of them must have exactly
            // one in it. We will discard those k items by one for each.
            // This action keeps the same mojority numbers in the remaining numbers.
            // Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.
            if (hash.size() == k) {
                auto it = hash.begin();
                while (it != hash.end()) {
                    if (--(it->second) == 0) {
                        hash.erase(it++);
                    } else {
                        ++it;
                    }
                }
            }
        }
        
        // Resets hash for the following counting.
        for (auto& it : hash) {
            it.second = 0;
        }
        
        // Counts the occurrence of each candidate integer.
        for (auto& i : nums) {
            auto it = hash.find(i);
            if (it != hash.end()) {
                ++it->second;
            }
        }
        
        // Selects the integer which occurs > n / k times.
        vector<int> ret;
        for (const pair<int, int>& it : hash) {
            if (it.second > static_cast<double>(n) / k) {
                ret.emplace_back(it.first);
            }
        }
        
        return ret[0];
    }
};

