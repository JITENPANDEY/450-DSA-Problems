string findReplaceString(string S, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> sorted;
    for (int i = 0 ; i < indices.size(); i++)
        sorted.push_back({indices[i], i});
    sort(sorted.begin(), sorted.end(), greater<pair<int, int>>());
    for (auto ind : sorted) {
        int i = ind.first; //starting point of substring in S
        string s = sources[ind.second], t = targets[ind.second];
        if (S.substr(i, s.length()) == s)
            S = S.substr(0, i) + t + S.substr(i + s.length());
    }
    return S;
}