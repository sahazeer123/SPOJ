#include<iostream>
#include<vector>
using namespace std;
struct SegmentTree
{
	vector<int>st;
	SegmentTree(int n){
		st.resize(4*n,0);
	}
	void build(int*nums,int start,int end,int node){
		if(start == end){
			st[node] = nums[start];
			return ;
		}
		int mid = start + (end - start)/2;
		//left build
		build(nums,start,mid,2*node+1);
		//right build
		build(nums,mid+1,end,2*node+2);
		st[node] = st[2*node+1] + st[2*node+2];
	}
	int query(int start,int end,int node,int l,int r){
		//no overlap
		if(l > end || start > r)
			return 0;
		//completer overlap
		if(start >= l && end <= r)
			return st[node];
		//partial overlap
		int mid = start + (end - start) / 2;
		int left = query(start,mid,2*node+1,l,r);
		int right = query(mid+1,end,2*node+2,l,r);
		return left+right;
	}
	void update(int *nums,int start,int end,int node,int index,int value){
		if(start == end)
		{
			//start == end == index;
			st[index] = value;
			nums[index] = value;
			return ;
		}
		int mid = start + (end- start)/2;
		if(index <= mid){
			update(nums,start,mid,2*node+1,index,value);
		}
		else{
			update(nums,mid+1,end,2*node+2,index,value); 
		}
		//coming back and updating
		st[node] = st[2*node+1] + st[2*node+2];
	}
};
int main()
{
	int n;
	cin >> n;
	int nums[n];
	for(int i = 0;i < n;++i)
		cin >> nums[i];
	SegmentTree tree(n);
	tree.build(nums,0,n-1,0);
	cout << tree.query(0,n-1,0,0,7) << "\n";
	cout << tree.query(0,n-1,0,5,6) << "\n";
}