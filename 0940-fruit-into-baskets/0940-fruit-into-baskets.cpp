class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hashmap;

        int left = 0, ans = 0;

        for (int right = 0; right < fruits.size(); right++) {
            hashmap[fruits[right]]++;

            while (hashmap.size() > 2) {
                hashmap[fruits[left]]--;

                if (hashmap[fruits[left]] == 0) {
                    hashmap.erase(fruits[left]);
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};