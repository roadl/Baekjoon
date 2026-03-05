    #include <iostream>
    #include <vector>
    #include <algorithm>

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
            cin >> gems[i].second >> gems[i].first;

        for (int i = 0; i < K; i++)
            cin >> bags[i];

        sort(gems.rbegin(), gems.rend());
        sort(bags.begin(), bags.end());

        unsigned long long result = 0;

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < gems.size(); j++) {
                if (gems[j].second <= bags[i]) {
                    result += gems[j].first;
                    gems.erase(gems.begin() + j);
                    break;
                }
            }
        }

        cout << result << endl;
    }