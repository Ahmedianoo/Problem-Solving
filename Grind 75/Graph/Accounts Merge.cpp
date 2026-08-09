#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    UnionFind uf = UnionFind(accounts.size());
    unordered_map<string, int> emailToAcc;

    for(int i = 0; i < accounts.size(); i++){
        vector<string> &acc = accounts[i];

        for(int e = 1; e < acc.size(); e++){
            if(emailToAcc.count(acc[e])){
                uf.unite(emailToAcc[acc[e]], i);
            }else{
                emailToAcc[acc[e]] = i;
            }
        }
    }

    unordered_map<int, vector<string>> emailGroup;

    for(auto& [email, accountIndex] : emailToAcc){
        int leader = uf.find(accountIndex);
        emailGroup[leader].push_back(email);
    }

    vector<vector<string>> result;

    for(auto& [accountIndex, emails] : emailGroup){
        string name = accounts[accountIndex][0];

        sort(emails.begin(), emails.end());

        vector<string> account;
        account.push_back(name);
        account.insert(account.end(), emails.begin(), emails.end());

        result.push_back(account);
    }

    return result;
}