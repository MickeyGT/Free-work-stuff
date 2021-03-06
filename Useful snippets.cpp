lca(TreeNode* A, int val1, int val2)
{
    deque<TreeNode>nodes;
    TreeNode B(0);
    nodes.push_back(*A);
    if(B.left!=NULL)
    {
        nodes.push_back(*B.left);
        parents[B.left->val]=B.val;
    }
    if(B.right!=NULL)
    {
        nodes.push_back(*B.right);
        parents[B.right->val]=B.val;
    }
}

class Node 
{
	Node next = null;
	int data;

	public Node(int d) 
	{
		data = d;
	}

	void appendToTail(int d) 
	{
		Node end = new Node(d);
		Node n = this;
		while (n.next != null)
		{
			n = n.next;
		}
 		n.next = end;
	}
}

int binarySearch(int[] a, int x)
{
	int low = 0;
	int high = a.length - 1;
	int mid;

	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (a[mid] < x)
		{
			low = mid + 1;
		} 
		else if (a[mid] > x)
		{
			high = mid - 1;
		}
		else 
		{
			return mid;
		}
	 }
return -1; // Error
}
