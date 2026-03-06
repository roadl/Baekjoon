    #include <iostream>
    #include <map>
    #include <vector>
    #include <algorithm>
    #include <queue>

    using namespace std;

    int N, K;

    vector<pair<int, int>> gems;
    vector<int> bags;

    int main()
    {
        cin >> N >> K;

        gems.resize(N);
        bags.resize(K);

        for (int i = 0; i < N; i++)
            cin >> gems[i].first >> gems[i].second;

        for (int i = 0; i < K; i++)
            cin >> bags[i];

        sort(gems.begin(), gems.end());   // weight
        sort(bags.begin(), bags.end());

        priority_queue<int> pq;

        unsigned long long result = 0;
        int idx = 0;

        for (int i = 0; i < K; i++) {
            while (idx < N && gems[idx].first <= bags[i]) {
                pq.push(gems[idx].second);
                idx++;
            }
            if (!pq.empty()) {
                result += pq.top();
                pq.pop();
            }
        }

        cout << result << endl;
    }