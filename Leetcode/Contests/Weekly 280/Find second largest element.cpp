class Solution
{
   public:
    int print2largest(int arr[], int arr_size)
    {
        int first=-1;
        int second=-1;
        for(int i=0;i<arr_size;i++)
        {
            if(arr[i]>first)
            {
                second=first;
                first=arr[i];
            }
             if(arr[i]>second and arr[i]<first)
            {
                second=arr[i];
            }
        }
        return second;
    }
};
