class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int i = 0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(dist[j][i] == 100000000 || dist[i][k] == 100000000){
                        continue;
                    }
                    int a = dist[j][i] + dist[i][k];
                    if(dist[j][k] > a){
                        dist[j][k] = a;
                    }
                }
            }
        }
    }
};
