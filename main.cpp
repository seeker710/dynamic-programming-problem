#include <bits/stdc++.h>
using namespace std;

vector<string> lcsFind(string a, string b, int m, int n, auto& lcsTable) {
    if(m==0 || n==0)
        return {""};

    if(a[m-1]==b[n-1]) {
        vector<string> lcs = lcsFind(a, b, m-1, n-1, lcsTable);
        for(string &str:lcs)
            str.push_back(a[m-1]);
        return lcs;
    }

    if (lcsTable[m - 1][n] > lcsTable[m][n - 1])
        return lcsFind(a, b, m - 1, n, lcsTable);

    if (lcsTable[m][n - 1] > lcsTable[m - 1][n])
        return lcsFind(a, b, m, n - 1, lcsTable);

    vector<string> top = lcsFind(a, b, m - 1, n, lcsTable);
    vector<string> left = lcsFind(a, b, m, n - 1, lcsTable);
    top.insert(top.end(), left.begin(), left.end());

    return top;
}

void tableFill(string a, string b, int m, int n, auto& lcsTable) {
    for(int i=1; i<m+1; ++i) {
        for(int j=1; j<n+1; ++j) {
            if(a[i-1]==b[j-1])
                lcsTable[i][j] = lcsTable[i-1][j-1] + 1;
            else 
                lcsTable[i][j] = max(lcsTable[i-1][j], lcsTable[i][j-1]);
        }
    }
}

pair<int, int> LCS(string a, string b) {
    int m=a.size(), n=b.size();
    vector<vector<int>> lcsTable(m+1, vector<int>(n+1));
    tableFill(a, b, m, n, lcsTable);
    vector<string> V = lcsFind(a, b, m, n, lcsTable);
    set<string> lcs(make_move_iterator(V.begin()), make_move_iterator(V.end()));
    return make_pair(lcsTable[m][n], lcs.size());
}

int main() {
    string a="abcdgh", b="aedfhr";
    pair<int, int> ans = LCS(a, b);
    int x = ans.first, y = ans.second;
    cout<<"X+5Y = "<<x+5*y;
    return 0;
}