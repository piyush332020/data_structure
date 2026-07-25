class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n!=0){
            int digit=n%10;
            ans.push_back(digit);
            n=n/10;
        }
        int maxi=0;
        for(int i=0;i<ans.size();i++){
            for(int j=i+1;j<ans.size();j++){
                maxi=max(maxi,ans[j]*ans[i]);
            }
        }
        return maxi;
    }
};