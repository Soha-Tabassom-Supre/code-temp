#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ============= PREFIX-SUFFIX TEMPLATES =============

// Template 1: Prefix SUM (for numeric arrays)
vector<ll> buildPrefixSum(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}

// Template 2: Suffix SUM (for numeric arrays)
vector<ll> buildSuffixSum(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> suffix(n);
    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] + arr[i];
    }
    return suffix;
}

// Template 3: Prefix DISTINCT COUNT (for strings/arrays)
vector<int> buildPrefixDistinct(string& s) {
    int n = s.size();
    vector<int> prefix(n);
    set<char> seen;
    for(int i = 0; i < n; i++) {
        seen.insert(s[i]);
        prefix[i] = seen.size();
    }
    return prefix;
}

// Template 4: Suffix DISTINCT COUNT (for strings/arrays)
vector<int> buildSuffixDistinct(string& s) {
    int n = s.size();
    vector<int> suffix(n);
    set<char> seen;
    for(int i = n-1; i >= 0; i--) {
        seen.insert(s[i]);
        suffix[i] = seen.size();
    }
    return suffix;
}

// Template 5: Prefix MAX
vector<ll> buildPrefixMax(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }
    return prefix;
}

// Template 6: Suffix MAX
vector<ll> buildSuffixMax(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> suffix(n);
    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    return suffix;
}

// Template 7: Prefix MIN
vector<ll> buildPrefixMin(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = min(prefix[i-1], arr[i]);
    }
    return prefix;
}

// Template 8: Suffix MIN
vector<ll> buildSuffixMin(vector<ll>& arr) {
    int n = arr.size();
    vector<ll> suffix(n);
    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = min(suffix[i+1], arr[i]);
    }
    return suffix;
}

// ============= USAGE EXAMPLES =============

// Example 1: Split string problem (like we just solved)
void exampleSplitString() {
    string s = "abcabcd";
    int n = s.size();
    
    vector<int> prefix = buildPrefixDistinct(s);
    vector<int> suffix = buildSuffixDistinct(s);
    
    int maxSum = 0;
    for(int i = 0; i < n-1; i++) {
        // Split: s[0..i] and s[i+1..n-1]
        int leftDistinct = prefix[i];
        int rightDistinct = suffix[i+1];
        maxSum = max(maxSum, leftDistinct + rightDistinct);
    }
    
    cout << "Max sum: " << maxSum << endl;
}

// Example 2: Range sum query
void exampleRangeSum() {
    vector<ll> arr = {3, 1, 4, 1, 5, 9, 2};
    vector<ll> prefix = buildPrefixSum(arr);
    
    // Query: sum from index L to R
    int L = 2, R = 5;
    ll rangeSum;
    if(L == 0) rangeSum = prefix[R];
    else rangeSum = prefix[R] - prefix[L-1];
    
    cout << "Sum from " << L << " to " << R << ": " << rangeSum << endl;
}

// Example 3: Maximum element in left part + Maximum in right part
void exampleMaxLeftRight() {
    vector<ll> arr = {3, 1, 4, 1, 5, 9, 2};
    int n = arr.size();
    
    vector<ll> prefixMax = buildPrefixMax(arr);
    vector<ll> suffixMax = buildSuffixMax(arr);
    
    ll maxSum = 0;
    for(int i = 0; i < n-1; i++) {
        // Split at i: max in left + max in right
        ll leftMax = prefixMax[i];
        ll rightMax = suffixMax[i+1];
        maxSum = max(maxSum, leftMax + rightMax);
    }
    
    cout << "Max sum of maximums: " << maxSum << endl;
}

// ============= QUICK REFERENCE =============
/*

WHEN TO USE:
- Need to try all split positions
- Need to query ranges multiple times
- Calculating same thing repeatedly

PREFIX ARRAY:
prefix[i] = property of s[0..i]
Build: left to right (i = 0 to n-1)

SUFFIX ARRAY:
suffix[i] = property of s[i..n-1]
Build: right to left (i = n-1 to 0)

SPLITTING AT POSITION i:
- Left part:  s[0..i]     → use prefix[i]
- Right part: s[i+1..n-1] → use suffix[i+1]
- Loop: for(i = 0; i < n-1; i++)

RANGE QUERY [L, R]:
- If L == 0: answer = prefix[R]
- Else: answer = prefix[R] - prefix[L-1]

TIME COMPLEXITY:
- Build: O(n)
- Query: O(1)
- Total: O(n) instead of O(n²)

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Run examples
    exampleSplitString();
    exampleRangeSum();
    exampleMaxLeftRight();
    
    return 0;
}