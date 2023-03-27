scanf("%d%d",&n,&p);
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    //long long ans = 0; 
    for(int i = 1; i <= n; i++) dp[i][1] = a[i] + dp[i - 1][1]; 
    for(int k = 2; k <= p; k++){
        for(int i = 1; i <= n; i++){
             for(int j = 1; j < i; j++){
                for(int bit = 0; bit < 51; bit++){      
                    if((dp[i][1] - dp[j][1]) & (1ll << bit) == 0) continue;
                    if(dp[j][k - 1] & (1ll << bit) == 0) continue;
                    dp[i][k] = max(dp[i][k], (long long) (dp[i][1] - dp[j][1]) & dp[j][k - 1]); 
                 }
             }
         }
    }
    cout << dp[n][p] << endl; 
    return 0; 
