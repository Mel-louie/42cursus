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

		void fix_insert(node_ptr node)
		{
			// node parent is red, node too, it violated the RBT rules
			node_ptr u; // uncle
			while (node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->right)
				{
					u = node->parent->parent->left;
					if (u->color == RED)
					{
						// case 1
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							// case 2.2
							node = node->parent;
							right_rotate(node);
						}
						// case 2.1
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						left_rotate(node->parent->parent);
					}
				}
				else // same but miror
				{
					u = node->parent->parent->right;
					if (u->color == RED)
					{
						// miror case 1
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							// mirror case 2.2
							node = node->parent;
							left_rotate(node);
						}
						// mirror case 2.1
						node->parent->color = 0;
						node->parent->parent->color = 1;
						right_rotate(node->parent->parent);
					}
				}
				if (node == root)
					break ;
			}
			root->color = BLACK;
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

		// rotate left at node x
		void left_rotate(node_ptr x)
		{
			node_ptr y = x->right;
			x->right = y->left;

			if (y->left != TNULL)
				y->left->parent = x;

			y->parent = x->parent;

			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;

			y->left = x;
			x->parent = y;
		}

		// rotate right at node x
		void right_rotate(node_ptr x)
		{
			node_ptr y = x->left;
			x->left = y->right;

			if (y->right != TNULL)
				y->right->parent = x;

			y->parent = x->parent;

			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else 
				x->parent->left = y;

			y->right = x;
			x->parent = y;
		}

		/*
		*	To insert a new node in a RTB we need to:
		*	- insert node using an ordinary BST insertion operation
		*	- color the new node in red
		*	- check if the insertion violated the RBT properties, if
		*	it did, we fix it
		*/
		void insert(int key)
		{
			// ordinary BST insertion
			node_ptr node = new Node;
			node->parent = NULL;
			node->_key = key;
			node->left = TNULL;
			node->right = TNULL;
			node->color = RED;

			node_ptr y = NULL;
			node_ptr x = this->root;

			while (x != TNULL)
			{
				// y saves x, to become the parent of x
				y = x;
				if (node->_key < x->_key)
					x = x->left;
				else
					x = x->right;
			}
			node->parent = y; // since y is the parent of x
			if (y == NULL) // x doesn't have parent, it's root
				root = node;
			else if (node->_key < y->_key)
				y->left = node;
			else
				y->right = node;
			
			// if node is a root node
			if (node->parent == NULL)
			{
				// change the color to black, a root is always black
				node->color = BLACK;
				return ;
			}
			// if the grandparent is nuul
			if (node->parent->parent == NULL)
				return ;

			// fix the tree
			fix_insert(node);
		}
	};
}; // namespace ft
#endif