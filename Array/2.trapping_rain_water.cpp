class Solution {
public:
    int trap(vector<int>& height) {
        int lmax[height.size()],rmax[height.size()],i,n=height.size(),twater=0;
        lmax[0]=height[0];
        for(i=1;i<n;i++)
            lmax[i] = max(height[i],lmax[i-1]);
        rmax[n-1]=height[n-1];
        for(i=n-2;i>=0;i--)
            rmax[i] = max(height[i],rmax[i+1]);
        
        for(i=1;i<n-1;i++)
            twater+=min(lmax[i],rmax[i])-height[i];
        
        return twater;
    }
};