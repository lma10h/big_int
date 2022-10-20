# big_int
header only C++ BigInt

# usage example
int main()
{
    int N=0;
    cin >> N;
    
    vector<vector<int>> t;
    t.push_back({4,6});
    t.push_back({6,8});
    t.push_back({7,9});
    t.push_back({4,8});
    t.push_back({3,9,0});
    t.push_back({});
    t.push_back({1,7,0});
    t.push_back({2,6});
    t.push_back({1,3});
    t.push_back({2,4});
    
    const int L=9;
    vector<vector<BigInt>> dp(N+1, vector<BigInt>(L+1, BigInt(0)));

    dp[1] = vector<BigInt>(L+1, BigInt(1));
    dp[1][0] = BigInt(0);
    dp[1][8] = BigInt(0);
    
    for (int n=2; n<=N; ++n) {
        for (int l=0; l<=L; ++l) {
            const auto &v = t[l];
            for (const auto& k : v) {
                dp[n][l] = dp[n][l] + dp[n-1][k];
            }
        }
    }

    accumulate(dp[N].begin(), dp[N].end(), BigInt(0)).print();

    return 0;
}
