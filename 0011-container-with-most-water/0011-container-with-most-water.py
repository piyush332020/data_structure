class Solution:
    def maxArea(self, height: List[int]) -> int:
        n=len(height)
        left=0
        right=n-1
        ans=0
        while left<=right:
            area=min(height[left],height[right])*(right-left)
            ans=max(area,ans)
            if height[right]<=height[left]:
                right-=1
            else:
                left+=1
        return ans