// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<bits/stdc++.h>
#include<iostream>

using namespace std;


int merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    int cnt = 0;
    vector<int> temp;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right] ) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            cnt += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high ;i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int left, int right) {
    int cnt = 0;
    if(left >= right) return 0;
    int mid = (left + right) / 2;
    cnt += mergeSort(arr, left, mid);
    cnt += mergeSort(arr, mid + 1, right);
    cnt += merge(arr, left, mid, right);

    return cnt;
}

void print(vector<int>& arr) {
    cout << "ARRAY: " << endl;
    for(auto it: arr) cout << it << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        vector<int> temp;
        int n;
        cin >> n;

        for(int i=0 ;i<n ;i++) {
            int arr;
            cin >> arr;
            temp.push_back(arr);
        }

        // print(temp);
        
        cout << mergeSort(temp, 0, n-1) << endl;

        string blanklin;
        if(t > 0) cin.ignore();
    }

    return 0;
}