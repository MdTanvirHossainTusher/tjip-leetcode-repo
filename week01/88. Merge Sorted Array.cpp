// TC = O(N)
// MC = O(1)
class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

        int i = m - 1, j = n - 1, k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] <= nums2[j]){
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];
            }
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};

/************************************************/
// TC = O(N)
// MC = O(N)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> aux(m+n);

        while(i<m && j<n){
            if(nums1[i]>nums2[j]){
                aux[k] = nums2[j];
                j++;
                k++;
            }
            else{
                aux[k] = nums1[i];
                i++;k++;
            }
        }
        while(i<m){
            aux[k] = nums1[i];
            i++;k++;
        }
        while(j<n){
            aux[k] = nums2[j];
            j++;k++;
        }
        for(int i = 0; i < m + n; i++){
            nums1[i] = aux[i];
        }
    }
};
