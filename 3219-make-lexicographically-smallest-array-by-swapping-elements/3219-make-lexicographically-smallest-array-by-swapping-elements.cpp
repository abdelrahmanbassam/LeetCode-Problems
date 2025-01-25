class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        vector<pair<int, int>> pairedArr;
        int size = arr.size();

        for (int i = 0; i < size; ++i)
            pairedArr.push_back(make_pair(arr[i], i));

        sort(pairedArr.begin(), pairedArr.end());

        vector<vector<pair<int, int>>> groups = {{pairedArr[0]}};

        for (int i = 1; i < size; ++i) {
            if (pairedArr[i].first - pairedArr[i - 1].first <= limit)
                groups.back().push_back(pairedArr[i]);
            else
                groups.push_back({pairedArr[i]});
        }

        for (const auto& group : groups) {
            vector<int> indices;
            for (const auto& element : group)
                indices.push_back(element.second);
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); ++i)
                arr[indices[i]] = group[i].first;
        }
        return arr;
    }
};