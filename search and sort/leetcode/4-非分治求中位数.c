/*************************************************************************
	> File Name: 4-非分治求中位数.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 19:24:15 2018
 ************************************************************************/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
　　int s[nums1Size+nums2Size];
　　int i,L=0,R=0;
　　int j=nums1Size+nums2Size;
　　for(i=0;i<=(j/2);)　　
　　{
　　　　if(L==nums1Size)    //排序数组 nums1已经放置完了 
　　　　{
　　　　　　while(i<=(j/2)) //直接放 nums2数组
　　　　　　s[i++]=nums2[R++];    
　　　　}
　　　　else if(R==nums2Size) //排序数组 nums2已经放置完了 
　　　　{
　　　　　　while(i<=(j/2)) //直接放 nums1数组
　　　　　　s[i++]=nums1[L++];    
　　　　} 
　　　　else
　　　　{ 
　　　　　　if(nums1[L]<nums2[R])
　　　　　　　　s[i++]=nums1[L++];
　　　　　　else
　　　　　　　　s[i++]=nums2[R++];
　　　　}  
　}


　　if(j%2==1)    //奇数个,则只要最中间值 
　　{
　　　　return s[i-1] ;
　　}
　　else
　　{
　　　　return (s[i-2]+s[i-1 ])/2.0;
　　}
}
 

 
