#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "utilities.hpp"

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

namespace ft
{

	template<typename K, typename V>
	class RBTree
	{
		enum Color { BLACK, RED };
		/* struct that represent a node in the tree */
		struct Node
		{
			K _key; // hold the key
			V _val; // hold the value
			int color;
			Node *parent;
			Node *left;
			Node *right;
		};
		typedef Node *node_ptr;
		/* Node struct end */

	private:
		typedef ft::pair<K, V>	iter;
		typedef size_t						size_type;
	 	/*--------------------------------------------------------------*/
	 	/*						Attributes								*/
		node_ptr root;
		node_ptr TNULL;

		/*--------------------------------------------------------------*/
		/*				PRIVATE MEMBERS_FUNCTIONS						*/
 
		// init a node
		void initialize_node(node_ptr node, node_ptr parent)
		{
			node->_key = 0;
			node->parent = parent;
			node->left = NULL;
			node->right = NULL;
			node->color = BLACK;
		}

		// // deepp copy of a tree
		// node_ptr copy_tree(node_ptr src_root, node_ptr src_tnull)
		// {
		// 	if (src_root == src_tnull)
		// 		return (TNULL);
		// 	node_ptr copy = copy_node(src_root, src_tnull);
		// 	copy->parent = TNULL;
		// 	copy->left = copy_tree(src_root->left, src_tnull);
		// 	copy->left->parent = copy;
		// 	copy->right = copy_tree(src_root->right, src_tnull);
		// 	copy->right->parent = copy;
		// 	return (copy);
		// }

		// node_ptr copy_node(node_ptr const *src_node, node_ptr const *src_tnull)
		// {
		// 	if (src_node == src_tnull)
		// 		return (TNULL);f
		// 	node_ptr copy = new node_ptr(src_node);
		// 	return (copy);
		// }

		void delete_tree(Node* node)
		{
			if (node == TNULL)
				return;
			delete_tree(node->left);
			delete_tree(node->right);
			delete node;
		}

		void preorder_traversal_helper(node_ptr node)
		{
			if (node != TNULL)
			{
				std::cout << node->_key << " " << node->_val << " | ";
				preorder_traversal_helper(node->left);
				preorder_traversal_helper(node->right);
			}			
		}

		void inorder_traversal_helper(node_ptr node)
		{
			if (node != TNULL)
			{
				inorder_traversal_helper(node->left);
				std::cout << node->_key << " " << node->_val << " | ";
				inorder_traversal_helper(node->right);
			}
		}

		void postorder_traversal_helper(node_ptr node)
		{
			if (node != TNULL)
			{
				postorder_traversal_helper(node->left);
				postorder_traversal_helper(node->right);
				//std::cout << node->_key << " ";
				std::cout << node->_key << " " << node->_val << " | ";
			}			
		}

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
			node_ptr u;
			while (node->parent->color == 1)
			{
				if (node->parent == node->parent->parent->right)
				{
					u = node->parent->parent->left; // uncle
					if (u->color == 1)
					{
						// case 1.1
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							// case 1.2
							node = node->parent;
							right_rotate(node);
						}
						// case 1.1
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						left_rotate(node->parent->parent);
					}
				}
				else
				{
					u = node->parent->parent->right; // uncle

					if (u->color == 1)
					{
						// mirror case 1.1
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;	
					}
					else
					{
						if (node == node->parent->right)
						{
							// mirror case 1.2
							node = node->parent;
							left_rotate(node);
						}
						// mirror case 1.1
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						right_rotate(node->parent->parent);
					}
				}
				if (node == root)
					break;
			}
			root->color = BLACK;
		}
		

		void fix_delete(node_ptr x)
		{
			node_ptr s;
			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						// case 1.1
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						// case 1.2
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							// case 1.3
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s);
							s = x->parent->right;
						}

						// case 1.4
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						// case 1.1
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == BLACK && s->right->color == BLACK)
					{
						// case 1.2
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							// case 1.3
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}

						// case 1.4
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}

		void rb_transplant(node_ptr u, node_ptr v)
		{
			if (u->parent == NULL)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void delete_node_helper(node_ptr node, int key)
		{
			
			// find the node containing the key
			node_ptr z = TNULL;
			node_ptr x, y;
			while (node != TNULL)
			{
				if (node->_key == key)
					z = node;
				if (node->_key <= key)
					node = node->right;
				else
					node = node->left;
			}

			if (z == TNULL)
			{
				//std::cout << "Couldn't find the key in the tree " << key << std::endl;
				return ;
			}

			y = z;
			// save the color of the node at the begining
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rb_transplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rb_transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rb_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			std::cout << z->_key << std::endl;
			delete z;
			if (y_original_color == BLACK)
				fix_delete(x);
		}

		void print_helper(node_ptr root, std::string indent, bool last)
		{
			if (root != TNULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "     ";
				}
				else
				{
					std::cout << "L----";
					indent += "|    ";
				}

				std::string _COLO = root->color ? _RED : B_WHT;
				std::cout << _COLO << root->_key << "-" << root->_val << _END << std::endl;
				print_helper(root->left, indent, false);
				print_helper(root->right, indent, true);
			}
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

		// RBTree(const RBTree &src)
		// {
		// 	*this = src;
		// 	std::cout << "RBT copied" << std::endl;
		// }
			
		~RBTree()
		{
			delete_tree(root);
		//	delete root;
			std::cout << "RBT destroyed" << std::endl;
		}

		// RBTree	&operator=(const RBTree &src)
		// {
		// 	root = copy_tree(src.root, src.TNULL);
		// 	return (*this);
		// }

		node_ptr get_root() { return (this->root); }

		/*--------------------------------------------------------------*/
		/*						MEMBERS_FUNCTIONS						*/


		/*           1
		*          /   \
		*         2		3
		*        / \
		*       4   5
		*
		*	trees can be traversed in different ways which are generally those:
		*	- preorder: Root, Left, Right: 1 2 4 5 3
		*	- inorder: Left, Root, Right: 4 2 5 1 3
		*	- postorder: Left, Right, Root: 4 5 2 3 1
		*/
		void preorder_traversal()
		{
			preorder_traversal_helper(this->root);
		}
		void inorder_traversal()
		{
			inorder_traversal_helper(this->root);
		}
		void postorder_traversal()
		{
			postorder_traversal_helper(this->root);
		}

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

		/*             50
		*          /        \
		*         30		 70
		*       /    \         \
		*     23      35        80
		*    /  \    /  \      /  \
		*  11   25  31   42   73   85
		*
		*	- if the right subtree isn't null, the successor is the leftmost node in the
		*	right subtree. successor of 50 == 73
		*	- else, the successor is the lowest ancestor of node, whose left child is
		*	also a node's ancestor. for x = 25, y = 23
		*	while (y != TNULL && x == y->right) -> x = 23, y = 30 -> 30 is its parent's left -> stop
		*					successor of 25 == 30
		*/
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

		/*			|				   |
		*           x				   y   
		*         /   \				 /   \
		*        a     y	-->		x     c
		*             / \		   / \
		*            b   c		  a   b
		*
		*	the left rotation at node x makes x goes down 
		*	in the left direction and as a result, its 
		*	right child goes up
		*/
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

		/*			|				   |
		*           y   			   x
		*         /   \				 /   \
		*        x     c	-->		a     y
		*       / \						 / \
		*      a   b					b   c
		*
		*	the right rotation at node x makes x goes down 
		*	in the right direction and as a result, its 
		*	right child goes up
		*/
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
		void insert(const K &key, const V &val)
		{
			// Ordinary Binary Search Insertion
			node_ptr node = new Node;
			node->parent = NULL;
			node->_key = key;
			node->_val = val;
			node->left = TNULL;
			node->right = TNULL;
			node->color = RED; // new node must be red

			node_ptr y = NULL;
			node_ptr x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (node->_key < x->_key)
					x = x->left;
				else
					x = x->right;
			}

			// y is parent of x
			node->parent = y;
			if (y == NULL)
				root = node;
			else if (node->_key < y->_key)
				y->left = node;
			else
				y->right = node;

			// if new node is a root node, simply return
			if (node->parent == NULL)
			{
				node->color = BLACK;
				return ;
			}

			// if the grandparent is null, simply return
			if (node->parent->parent == NULL)
			{
				return ;
			}
			// Fix the tree
			fix_insert(node);
		}

		void delete_node(int key)
		{
			delete_node_helper(this->root, key);
		}

		void printRBT()
		{
			if (root)
			{
				std::cout << std::endl;
				print_helper(this->root, "", true);
				std::cout << _END;
			}
		}

		node_ptr find_key(const K &key) const
		{
			node_ptr node = root;
			while ( node != TNULL && node->_key != key)
			{
				if (key < node->_key)
					node = node->left;
				else
					node = node->right;
			}
			return (node);
		}

		V &operator[](const K &key) const
		{
			node_ptr node = find_key(key);
			if (node == TNULL)
				throw std::out_of_range("Invalid key");
			return (node->_val);
		}

	};
}; // namespace ft

#endif