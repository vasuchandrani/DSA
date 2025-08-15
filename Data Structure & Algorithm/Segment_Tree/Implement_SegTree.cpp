// Range Sum query 

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

// build Tree
void buildSegTree(int node, int l, int r, vector<int>& a, vector<int>& segTree) {

    // base-case 
    if (l == r) {
        segTree[node] = a[l];
        return;
    }

    int mid = (l + r) /2;
    // go to left
    buildSegTree(2*node +1, l, mid, a, segTree);
    // go to right
    buildSegTree(2*node +2, mid +1, r, a, segTree);

    segTree[node] = segTree[2*node +1] + segTree[2*node +2];
    //curr-Node    //left-Child        //right-Child
}      

// update Tree 
// change or assign the value =val to index =i in array
void update(int node, int i, int val, int l, int r, vector<int>& a, vector<int>& segTree) {

    if (l == r) {
        // if (l == node) {
            a[i] = val;
            segTree[node] = val;
            return;
        // }
    }

    int mid = (l + r)/2;

    if (i <= mid) { //left 
        update(2*node +1, i, val, l, mid, a, segTree);
    }
    else {// right
        update(2*node +2, i, val, l, mid, a, segTree);
    }

    segTree[node] = segTree[2*node +1] + segTree[2*node +2];

} 

// Query
int Query(int node, int s, int e, int l, int r, vector<int>& segTree) {
    
    // node is out of query 
    if (s > r || e < l) {
        return 0;
    }

    // node is in the query 
    else if (l >= s && r <= e) {
        return segTree[node];
    }

    // else {
        int mid = (l + r)/2;
        return Query(2*node +1, s, e, l, mid, segTree) + 
                Query(2*node +2, s, e, mid +1, r, segTree);
    // }
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

    cout<<"update Tree"<<endl;
    update(0, 3, 10, 0, n-1, arr, segTree);

    cout<<"Array"<<endl;
    for (int i : arr) {
        cout<<i<<" ";
    }cout<<endl;

    cout<<"Segment tree array: "<<endl;
    for (int i : segTree) {
        cout<<i<<" ";
    }cout<<endl;
    
    int sum = 0;
    sum += Query(0, 2, 6, 0, n-1, segTree);

    cout<<sum<<endl;

    return 0;
}
