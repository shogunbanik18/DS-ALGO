// First and last occurrences of x 
// using a vector 
// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5. 

vector<int> find(int arr[], int n , int x )
{
    int i=0;
    int j=n-1;
    vector<int> v;
    while(i<=j){
        if(arr[i]!=x){
            i++;
        }
        if(arr[j]!=x){
            j--;
        }
        if(arr[i]==x && arr[j]==x){
            v.push_back(i);
            v.push_back(j);
            break;
        }
    }
    if(i>j){
        v.push_back(-1);
        v.push_back(-1);
    }
    return v;
}
