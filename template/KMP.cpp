void KMP_build(int* f, string s) {
    f[0] = -1;
    int p = -1;
    for (int i = 1; i < s.size(); ++i) {
        while (p != -1 && s[p+1] != s[i]) {
            p = f[p];
        }
        if (s[p+1] == s[i]) {
            ++p;
        }
        f[i] = p;
    }
}
vector<int> KMP_match(string s, int* f, string t) {
    vector<int> ans;
    int p = -1;
    for (int i = 0; i < t.size(); ++i) {
        while (p != -1 && s[p+1] != t[i]) {
            p = f[p];
        }
        if (s[p+1] == t[i]) {
            ++p;
        }
        if (p+1 == s.size()) {
            ans.push_back(i-p);
            p = f[p];
        }
    }
    return ans;
}
