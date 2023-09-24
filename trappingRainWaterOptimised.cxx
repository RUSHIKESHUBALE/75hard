// given an array of heights of buildings and we need to find how much 
// water can be stored in them 
// e.g.  2, 4, 2, 3 ,4 ,2 , 1 are heights of buildings 
// ans is 3


#include<bits/stdc++.h>
using namespace std;
#define ITK_ok 1

int getLeftBigger( int arr[], vector<int> &leftBigger, int len )
{
    stack<int> st;

    for ( int i = 0; i < len; i++ )
    {
        while( !st.empty() && arr[i] >= st.top() )
        {
            st.pop();
        }
        if ( st.empty() )
        {
            st.push( arr[i] );
        }
        
        leftBigger[i] = st.top();
    }

    return ITK_ok;
}

int getRightBigger( int arr[], vector<int> &rightBigger, int len )
{
     stack<int> st;

    for ( int i = len - 1; i >= 0; i-- )
    {
        while( !st.empty() && arr[i] >= st.top() )
        {
            st.pop();
        }
        if ( st.empty() )
        {
            st.push( arr[i] );
        }
        
        rightBigger[i] = st.top();
    }

    return ITK_ok;
}

int main()
{
    int arr[] = { 2, 4, 2, 3 ,4 ,2 , 1 };
    int len = sizeof(arr)/sizeof(arr[0]);

    vector<int> rightBigger(len);
    vector<int> leftBigger(len);

    int rStat;

    rStat = getLeftBigger( arr, leftBigger, len );
    rStat = getRightBigger( arr, rightBigger, len );

    int ans = 0;

    for ( int i = 0; i < len; i++ )
    {
        ans += min( leftBigger[i], rightBigger[i] ) - arr[i];
        // cout<<rightBigger[i]<<" ";
        // cout<<leftBigger[i]<<" ";
    }

    cout<<ans<<" ";
}