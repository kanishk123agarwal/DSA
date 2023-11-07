https://leetcode.com/problems/find-k-closest-elements/
658: find k closest element 
two method to solve 
class Solution {
public:
    // t.c - o(n)  s.c o(1)
    vector<int> twoPtrMethod(vector<int>& arr, int k, int x) {
        int l=0,h=arr.size()-1;
        while(h-l>=k){
            if(x-arr[l] > arr[h]-x) l++;
            else h--;
        }
        vector<int> ans;
        for(int i=l;i<=h;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
    case1: [1,2,3,4,5] k=4 x=-1
    case2: [1,2,3,4,5] k=4 x=6 
    case3: [1,2,3,4,5] k=4 x=3
    case4: [3,5,8,10] k=2 x=15
    int lowerBound(vector<int>& arr,int x){
        int s=0,e=arr.size()-1;
        int ans=e; //edge case for 3,5,8 10 k=2 x=15 //case4
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=x){  //case1 case3 case4 
                ans=mid;
                e=mid-1;
            }
            if(x>arr[mid]) s=mid+1;  //case2 case 3 case 4
            else e=mid-1; //case3 case4
        }
        return ans;
    }
    vector<int> BS(vector<int> & arr,int k,int x){ //o(logn)
        int h=lowerBound(arr,x);
        int l=h-1;
        while(k--){
            if(l<0)h++;  //edge case case1
            else if(h>=arr.size())l--; //edge case case 2
            else if(x-arr[l]>arr[h]-x)h++; //case 3
            else l--;
        }
        return vector<int>(arr.begin()+l+1,arr.begin()+h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return twoPtrMethod(arr,k,x);
        return BS(arr,k,x);
    }
};


// exponential search 
// Application : unbounded search : find the element in an infinity array 
// better than BS when x is beginning in array 
// T.C o(logn)
// algo:
// 1) first we found the range where the target value is find so the binary search is in the range and we don't search in long array 
// 2) apply binary search 

int BS(vector<int>& arr,int s,int e,int x){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x)return mid;
        else if(x>arr[mid]) s=mid+1;
        else e=mid-1;
    }
    return -1;
}

int exponentialSearch(vector<int> arr,int x){
    if(arr[0]==x)return 0;
    int i=1;
    while(i<arr.size() && arr[i]<=x){
        i=i*2;
    }
    return BS(arr,i/2,min(i,n-1),x);
}

// iiska 2nd part hai find the element in the infinity array 
// so here we can't apply binary search bcz we don't know where the last index come so we do exponential search 
// 1) first i found the range and then apply binary search
int unboundedSearch(vector<int>arr,int x){
    int i=0,j=1;
    while(arr[j]<=x){
        i=j;
        j=j*2;
    }
    return BS(arr,i,j,x);
}

// very very important question
https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Allocate minimum no of pages -- book allocation problem
// In this we use search space from 0 to the sum of all array element 
class Solution 
{
    public:
    
    bool isPossibleSol(int A[],int N ,int M,int sol){
        int pageSum=0; //to calculate the sum of allocated book and it's page
        int c=1; // it refers to the no of student or track the student
        for(int i=0;i<N;i++){
            if(A[i]>sol)return false; //if any number is greater than current sol then return false 
            if(pageSum+A[i]>sol){ //if we take that A[i] and it's increase the sol then we assign the book to the next person
                c++;
                pageSum=A[i]; //assign the book that is increased the solution
                if(c>M){ // if c is increased from the no of student and we can't assign the book so it also return false
                    return false;
                }
            }
            else{
                pageSum+=A[i]; //it sum the pages of book 
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        // edge case
        if(M>N)return -1;
        
        // defines search space
        int start=0;
        int end=accumulate(A,A+N,0);  // it give sum of all the element in the array
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossibleSol(A,N,M,mid)){  //if possible answer occur so it goes to left side
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};