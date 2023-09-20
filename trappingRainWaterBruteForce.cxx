#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 2, 4, 2, 3, 4, 2, 1 };
    int len = sizeof(arr)/sizeof(arr[0]);

    int leftBigger[len];
    int rightBigger[len];

    for ( int i = 0; i < len; i++ )
    {
        int maxNum = -1;
        for ( int j = 0; j <= i; j++ )
        {
            maxNum = max( maxNum, arr[j] );
            leftBigger[i] = maxNum;
        }
    }

    for ( int i = len-1 ; i >= 0; i-- )
    {
        int maxNum = -1;
        for ( int j = len-1; j >= i; j-- )
        {
            maxNum = max( maxNum, arr[j] );
            rightBigger[i] = maxNum;
        }
    }
    
    int ans = 0;

    for ( int i = 0; i < len; i++ )
    {
        ans += ( min( leftBigger[i], rightBigger[i] ) - arr[i] );
    }

    cout<<ans;
}