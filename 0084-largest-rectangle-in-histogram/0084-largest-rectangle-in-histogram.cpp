class Solution {
private:
    vector<int> nextsmallest(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevsmallest(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        vector<int>prev(n);
        next=nextsmallest(heights);
        prev=prevsmallest(heights);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }
};