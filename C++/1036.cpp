#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K;
vector<string> strs;

void add(vector<int>& a, const vector<int>& b) {
    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i == a.size()) a.push_back(0);
        int x = a[i] + carry + (i < b.size() ? b[i] : 0);
        carry = x / 36;
        a[i] = x % 36;
    }
}

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int to_num(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char to_char(int x) {
    if (x < 10) return '0' + x;
    return 'A' + (x - 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    strs.resize(N);

    vector<vector<int>> diff(36);

    for (int i = 0; i < N; i++) {
        cin >> strs[i];
        int len = strs[i].size();

        for (int j = 0; j < len; j++) {
            int cur = to_num(strs[i][j]);
            int gain = 35 - cur;

            if (gain == 0) continue;

            vector<int> val(len - j, 0);
            val[len - j - 1] = gain;
            add(diff[cur], val);
        }
    }

    cin >> K;

    vector<pair<vector<int>, int>> v;
    for (int i = 0; i < 36; i++)
        v.push_back({diff[i], i});

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return cmp(b.first, a.first);
    });

    vector<bool> used(36, false);
    for (int i = 0; i < K; i++)
        used[v[i].second] = true;

    vector<int> result;

    for (const auto& s : strs) {
        int len = s.size();
        for (int j = 0; j < len; j++) {
            int x = to_num(s[j]);
            if (used[x]) x = 35;

            vector<int> val(len - j, 0);
            val[len - j - 1] = x;
            add(result, val);
        }
    }

    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    for (int i = result.size() - 1; i >= 0; i--)
        cout << to_char(result[i]);

    cout << '\n';
    return 0;
}