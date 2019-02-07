#include<iostream>
#include<stdlib.h>
#include<assert.h>


template<class K>
struct AVLTreeNode
{
	K _key;//节点内的值

	AVLTreeNode<K>* _left;//左子树节点
	AVLTreeNode<K>* _right;//右子树节点
	AVLTreeNode<K>* _parent;//双亲节点

	int _bf;//平衡因子

	AVLTreeNode(const K& key)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _bf(0)
	{}
};
template<class K>
class AVLTree
{
	typedef AVLTreeNode< K > Node;
public:
	size_t Height(Node* root)//计算树的高度
	{
		if (root == nullptr)
		{
			return 0;
		}

		size_t leftHeight = Height(root->_left);
		size_t rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);

	}
	void GetBf(Node *root)//计算平衡因子
	{
		if (root == nullptr)
		{
			return;
		}
		root->_bf = Height(root->_right) - Height(root->_left);
		if (abs(root->_bf) > 1)
		{
			std::cout << "节点" << root->_key << "的平衡因子有误！" << std::endl;
		}

		GetBf(root->_left);
		GetBf(root->_right);

	}
	bool insert(const K& key)
	{
		//1.判断空树
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;

		}
		//2.查找位置
		Node* cur = _root;
		Node * parent = nullptr;

		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//节点已经存在
			}
		}
		//3.插入数据
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//4.验证平衡因子的值

		while (parent)
		{
			if (cur == parent->_left)
			{
				--(parent->_bf);
			}
			else
			{
				++(parent->_bf);
			}
			if (parent->_bf == 0)//说明之前的平衡因子值为-1或1，此时满足AVL树特性，调整结束
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//说明之前的平衡因子值为0，需要向上调整。
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//说明已经不满足AVL树的特性，选择适当旋转方式
			{
				if ((parent->_bf == -2) && (cur->_bf == -1))//右单旋
				{
					_RotateR(parent);
				}
				if ((parent->_bf == 2) && (cur->_bf == 1))//左单旋
				{
					_RotateL(parent);
				}
				if ((parent->_bf == -2) && (cur->_bf == 1))//左右双旋
				{
					Node* subL = parent->_left;
					Node* subLR = subL->_right;
					int bf = subLR->_bf;

					_RotateL(parent->_left);
					_RotateR(parent);

					subLR->_bf = 0;
					if (bf == 1)
					{
						subL->_bf = -1;
						parent->_bf = 0;
					}
					else if (bf == -1)
					{
						parent->_bf = 1;
						subL->_bf = 0;
					}
					

				}
				if ((parent->_bf == 2) && (cur->_bf == -1))//右左双旋
				{

					Node* subR = parent->_right;
					Node* subRL = subR->_left;
					int bf = subRL->_bf;

					_RotateR(parent->_right);
					_RotateL(parent);

					subRL->_bf = 0;
					if (bf == 1)
					{
						subR->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1)
					{
						parent->_bf = 0;
						subR->_bf = 1;
					}
				}
				break;//调整之后一定符合AVL树特性，调整结束。
			}
			else//大于2的情况直接报错
			{
				assert(false);
			}
		}
		return true;
	}

	void _RotateL(Node* parent)
	{
		Node *ppnode = parent->_parent;
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		parent->_right = subRL;

		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;

		if (ppnode == nullptr)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}


		subR->_bf = parent->_bf = 0;
	}
	void _RotateR(Node* parent)
	{
		Node* ppnode = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;


		if (ppnode == nullptr)
		{
			subL->_parent = nullptr;
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}

			subL->_parent = ppnode;

		}

		subL->_bf = parent->_bf = 0;
	}

	bool IsBlanceTree()
	{
		return _IsBlanceTree(_root);
	}
	
	bool _IsBlanceTree(Node *root)
	{
		if (root == nullptr)
		{
			return true;
		}


		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		int bf = rightHeight - leftHeight;
		if (bf != root->_bf)
		{
			std::cout << root->_key << "结点平衡因子异常";
		}

		return abs(rightHeight - leftHeight)< 2 && _IsBlanceTree(root->_left) && _IsBlanceTree(root->_right);
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}
	
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		std::cout << root->_key << " ";
		_InOrder(root->_right);
	}
	
	Node* find(const K& key)
	{
		if (_root == nullptr)
			return nullptr;

		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;
	}
private:
	Node* _root = nullptr;
};

```
测试代码

```
int main()
{
	AVLTree<int> t;


	int a[] = { 2, 4, 3, 1, 0, 6, 5 };


	for (auto e : a)
	{
		t.insert(e);
		std::cout << e << "->" << t.IsBlanceTree()<<std::endl;
	}

	t.InOrder();

	if (t.IsBlanceTree())
	{
		std::cout << "该树是AVL树" << std::endl;
	}
	else
	{
		std::cout << "该树不是AVL树" << std::endl;
	}
	system("pause");
}	