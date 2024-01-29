class Solution{
	public:
	/* **Rescursion** 
	int solve(int index,int sum,string &str)
	{
	    if(index == str.size()) return 1;
	    
	    int currentSum = 0;
	    int ans = 0;
	    for(int i = index;i<str.size();i++)
	    {
	        currentSum += str[i]-'0';
	        if(currentSum >= sum)
	        ans += solve(i+1,currentSum,str);
	    }
	    return ans;
	}*/
	
	
	/* **Memoization** 
	int solve(int index,int sum,string &str,vector<vector<int>>&dp)
	{
	    if(index == str.size()) return 1;
	    
	    if(dp[index][sum] != -1) return dp[index][sum];
	    int currentSum = 0;
	    int ans = 0;
	    for(int i = index;i<str.size();i++)
	    {
	        currentSum += str[i]-'0';
	        if(currentSum >= sum)
	        ans += solve(i+1,currentSum,str,dp);
	    }
	    return dp[index][sum] = ans;
	}
	int TotalCount(string str){
	    int sum = 0;
	    for(auto i : str)
	    {
	        sum += i-'0';
	    }
	    vector<vector<int>>dp(str.size()+1,vector<int>(sum+1,-1));
	    return solve(0,0,str,dp);
	}*/
	
	
	//Tabulation
	int TotalCount(string str){
	    int n = str.size();
	    int sum = 0;
	    for(auto i : str)
	    {
	        sum += i-'0';
	    }
	    vector<vector<int>>dp(str.size()+1,vector<int>(sum+1,0));
	    for(int i = n-1;i>=0;i--)
	    {
	        for(int j = 0;j<=sum;j++)
	        {
	            int currentSum = 0;
        	    int ans = 0;
        	    for(int k = i;k<str.size();k++)
        	    {
        	        currentSum += str[k]-'0';
        	        if(currentSum >= j){
        	            if(k+1>= str.size()) ans++;
        	            else
        	            ans += dp[k+1][currentSum];
        	        }
        	        
        	    }
        	    dp[i][j] = ans;
	        }
	    }
	    return dp[0][0];
	}
};
