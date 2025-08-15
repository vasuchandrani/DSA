#include<bits/stdc++.h>
using namespace std;
/*
        root 
        /  \ 
       /    \
    0-mid  mid+1-n       

*/

/*
array = {1, 2, 7, 9, 10, 46, 2};
         0  1  2  3  4   5   6

segment Tree array = {77 19 58 3 16 56 2 1 2 7 9  10 46 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0};
                      0  1  2  3 4  5  6 7 8 9 10 11 12 

Tree
		      77(0,6)
		     /       \ 
	    (0,3)19      58(4,6)
		   /  \       /  \	
		  3   16     56   2
		 /\   /\    / \   / \
 	 	1  2 7  9  10 46  0  0
*/
// storage for segment tree:
// vector<int> segTree;
void buildSegTree(int idx, int l, int r, vector<int>& a, vector<int>& segTree) {

    // base-case 
    if (l == r) {
        segTree[idx] = a[l];
        return;
    }

    int mid = (l + r) /2;
    // go to left
    buildSegTree(2*idx +1, l, mid, a, segTree);
    // go to right
    buildSegTree(2*idx +2, mid +1, r, a, segTree);

    segTree[idx] = segTree[2*idx +1] + segTree[2*idx +2];
    //curr-Node    //left-Child        //right-Child
}      

int main () {
    vector<int> arr = {1, 2, 7, 9, 10, 46, 2};
    int n = arr.size();
    cout<<"Size of arry "<<n<<endl;

    cout<<"Array"<<endl;
    for (int i : arr) {
        cout<<i<<" ";
    }cout<<endl;

    vector<int> segTree(4*n);

    buildSegTree(0, 0, n-1, arr, segTree);

    cout<<"Segment tree array: "<<endl;
    for (int i : segTree) {
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}
