#ifndef RB_TREE_HPP
# define RB_TREE_HPP

/*--------------------------------------------------------*/
/*------------------ FT::RED_BLACK_TREE ------------------*/
/*
*		[ BINARY SEARCH TREE (BST) ]
*	- each node has 2 children (if any are missing, we
*	considere it a nil (leaf) node)
*	- node left has to have a key < to root key 
*	- node right has to have a key >= to root key
*	like: left < root <= right
*
*		[ RED-BLACK TREE (RBT) ]
*	- each node is red or black
*	- all nil (leaf) nodes are black
*	- if a node is red, then his children are black
*	- every simple path from root to leaves contains the same number
*     of black nodes
*/

enum Color { BLACK, RED };
/* struct that represent a node in the tree */
struct Node
{
	int _key; // hold the key
	int color;
	Node *parent;
	Node *left;
	Node *right;
};
typedef Node *node_ptr;
/* Node struct end */

namespace ft
{
	template<typename T, typename U>
	class RBTree
	{

	private:
		/*--------------------------------------------------------------*/
		/*						Attributes								*/
		node_ptr root;
		node_ptr TNULL;

		/*--------------------------------------------------------------*/
		/*				PRIVATE MEMBERS_FUNCTIONS						*/
		void delete_tree(Node* node)
		{
			if (node == NULL)
				return;
			delete_tree(node->left);
			delete_tree(node->right);
			delete_node(node);
		}

		void delete_node(Node* node) { delete node; }

		node_ptr search_tree_helper(node_ptr node, int key)
		{
			if (node == NULL || key == node->_key)
				return (node);
			if (key < node->_key)
				return (search_tree_helper(node->left, key));
			else
				return (search_tree_helper(node->right, key));
		}
		
	public:
		/*--------------------------------------------------------------*/
		/*						Constructors							*/
		RBTree()
		{
			TNULL = new Node;
			TNULL->color = BLACK;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
			std::cout << "RBT created" << std::endl;
		}
		RBTree(const RBTree &src)
		{
			*this = src;
			std::cout << "RBT copied" << std::endl;
		}
			
		~RBTree()
		{
			delete_tree(root);
			std::cout << "RBT destroyed" << std::endl;
		}

		// RBTree	&operator=(const RBTree &src)
		// {
		// 	if (*this != src)
		// 		copy_tree()
		// 	return (*this);
		// }

		/*--------------------------------------------------------------*/
		/*						MEMBERS_FUNCTIONS						*/

		/* search the tree for the key, and return the corresponding node */
		node_ptr search_tree(int key) { return(search_tree_helper(this->root, key)); }

		node_ptr minimum(node_ptr node)
		{
			if (node->left != TNULL)
				node = node->left;
			return (node);
		}
		node_ptr maximum(node_ptr node)
		{
			if (node->right != TNULL)
				node = node->right;
			return (node);
		}

		/* - if the right subtree isn't null, the successor is the leftmost node in the
			right subtree
			- else, the successor is the lowest ancestor of node, whose left child is
			also a node's ancestor */
		node_ptr successor(node_ptr x)
		{
			if (x->right != TNULL)
				return (minimum(x->right));
			node_ptr y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return (y);
		}
		/* predecessor: the same as successor, but in symetry */
		node_ptr predecessor(node_ptr x)
		{
			if (x->left != TNULL)
				return (maximum(x->left));
			node_ptr y = x->parent;
			while (y != TNULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}
			return (y);
		}
	};
}; // namespace ft
#endif