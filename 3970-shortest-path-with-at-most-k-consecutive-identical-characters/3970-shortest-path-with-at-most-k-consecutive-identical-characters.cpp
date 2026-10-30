class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        unordered_map<int, vector<pair<int,int>>> graph;
        for (const vector<int>& edge : edges)
            graph[edge[0]].push_back({edge[1], edge[2]});

        auto comparer = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b)
        {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(comparer)> pq;
        vector<vector<int>> minWeights(k+1, vector<int>(n, INT_MAX));
        vector<int> counts(n, INT_MAX);
        minWeights[0][0] = 0;
        pq.push({0, 1, 0});
        while (!pq.empty())
        {
            auto [index, count, weight] = pq.top();
            pq.pop();

            if (index == n-1)
                return weight;

//            if (minWeights[count][index] < weight)
//                continue;

            for (auto [neighborIndex, edgeWeight] : graph[index])
            {
                const int newCount = (labels[index]==labels[neighborIndex])? count+1:1;
                if (newCount <= k)
                {
                    const int newWeight = weight + edgeWeight;

                    if (minWeights[newCount][neighborIndex] > newWeight)
                    {
                        minWeights[newCount][neighborIndex] = newWeight;
                        pq.push({neighborIndex, newCount, newWeight});
                    }
                }
            }
        }

        return -1;
    }
};