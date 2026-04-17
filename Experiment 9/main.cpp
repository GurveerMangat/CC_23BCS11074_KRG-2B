class Solution {
    public String shortestCommonSupersequence(String s, String t) {
        int n=s.length();
        int m=t.length();
        int[][] dp=new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s.charAt(i-1)==t.charAt(j-1)){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        StringBuilder sb=new StringBuilder();
        while(n>0 && m>0){
            if(s.charAt(n-1)==t.charAt(m-1)){
                sb.append(s.charAt(n-1));
                n--;
                m--;
            }
            else if(dp[n-1][m]>=dp[n][m-1]){
                sb.append(s.charAt(n-1));
                n--;
            }
            else{
                sb.append(t.charAt(m-1));
                m--;
            }
        }
        for(int i=n;i>0;i--){
            sb.append(s.charAt(i-1));
        }
        for(int i=m;i>0;i--){
            sb.append(t.charAt(i-1));
        }
        return sb.reverse().toString();
    }
}
