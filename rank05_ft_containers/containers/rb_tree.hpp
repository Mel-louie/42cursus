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

	// template<typename K, typename V>
	// class RBTree
	// {
	// 	enum Color { BLACK, RED };
	// 	public:
	// 	/* struct that represent a node in the tree */
	// 	struct Node
	// 	{
	// 		K _key; // hold the key
	// 		V _val; // hold the value
	// 		int color;
	// 		Node *parent;
	// 		Node *left;
	// 		Node *right;
	// 	};
	// 	typedef Node *node_ptr;
	// 	/* Node struct end */

	// private:
	// 	typedef ft::pair<K, V>	iter;
	// 	typedef size_t						size_type;
	//  	/*--------------------------------------------------------------*/
	//  	/*						Attributes								*/
	// 	node_ptr root;
	// 	node_ptr TNULL;

	// 	/*--------------------------------------------------------------*/
	// 	/*				PRIVATE MEMBERS_FUNCTIONS						*/
 
	// 	// create a node
	// 	node_ptr create_node(const K &k, const V &v)
	// 	{
	// 		node_ptr node = new Node;
	// 		node->parent = NULL;
	// 		node->_key = k;
	// 		node->_val = v;
	// 		node->left = TNULL;
	// 		node->right = TNULL;
	// 		node->color = RED; // new node must be red

	// 		return (node);
	// 	}

	// 	// // deepp copy of a tree
	// 	// node_ptr copy_tree(node_ptr src_root, node_ptr src_tnull)
	// 	// {
	// 	// 	if (src_root == src_tnull)
	// 	// 		return (TNULL);
	// 	// 	node_ptr copy = copy_node(src_root, src_tnull);
	// 	// 	copy->parent = TNULL;
	// 	// 	copy->left = copy_tree(src_root->left, src_tnull);
	// 	// 	copy->left->parent = copy;
	// 	// 	copy->right = copy_tree(src_root->right, src_tnull);
	// 	// 	copy->right->parent = copy;
	// 	// 	return (copy);
	// 	// }

	// 	// node_ptr copy_node(node_ptr const *src_node, node_ptr const *src_tnull)
	// 	// {
	// 	// 	if (src_node == src_tnull)
	// 	// 		return (TNULL);f
	// 	// 	node_ptr copy = new node_ptr(src_node);
	// 	// 	return (copy);
	// 	// }

	// 	void delete_tree(Node* node)
	// 	{
	// 		if (node == TNULL)
	// 			return;
	// 		delete_tree(node->left);
	// 		delete_tree(node->right);
	// 		delete node;
	// 	}

	// 	void preorder_traversal_helper(node_ptr node)
	// 	{
	// 		if (node != TNULL)
	// 		{
	// 			std::cout << node->_key << " " << node->_val << " | ";
	// 			preorder_traversal_helper(node->left);
	// 			preorder_traversal_helper(node->right);
	// 		}			
	// 	}

	// 	void inorder_traversal_helper(node_ptr node)
	// 	{
	// 		if (node != TNULL)
	// 		{
	// 			inorder_traversal_helper(node->left);
	// 			std::cout << node->_key << " " << node->_val << " | ";
	// 			inorder_traversal_helper(node->right);
	// 		}
	// 	}

	// 	void postorder_traversal_helper(node_ptr node)
	// 	{
	// 		if (node != TNULL)
	// 		{
	// 			postorder_traversal_helper(node->left);
	// 			postorder_traversal_helper(node->right);
	// 			//std::cout << node->_key << " ";
	// 			std::cout << node->_key << " " << node->_val << " | ";
	// 		}			
	// 	}

	// 	node_ptr search_tree_helper(node_ptr node, int key)
	// 	{
	// 		if (node == NULL || key == node->_key)
	// 			return (node);
	// 		if (key < node->_key)
	// 			return (search_tree_helper(node->left, key));
	// 		else
	// 			return (search_tree_helper(node->right, key));
	// 	}

	// 	void fix_insert(node_ptr node)
	// 	{
	// 		node_ptr u;
	// 		while (node->parent->color == 1)
	// 		{
	// 			if (node->parent == node->parent->parent->right)
	// 			{
	// 				u = node->parent->parent->left; // uncle
	// 				if (u->color == 1)
	// 				{
	// 					// case 1.1
	// 					u->color = BLACK;
	// 					node->parent->color = BLACK;
	// 					node->parent->parent->color = RED;
	// 					node = node->parent->parent;
	// 				}
	// 				else
	// 				{
	// 					if (node == node->parent->left)
	// 					{
	// 						// case 1.2
	// 						node = node->parent;
	// 						right_rotate(node);
	// 					}
	// 					// case 1.1
	// 					node->parent->color = BLACK;
	// 					node->parent->parent->color = RED;
	// 					left_rotate(node->parent->parent);
	// 				}
	// 			}
	// 			else
	// 			{
	// 				u = node->parent->parent->right; // uncle

	// 				if (u->color == 1)
	// 				{
	// 					// mirror case 1.1
	// 					u->color = BLACK;
	// 					node->parent->color = BLACK;
	// 					node->parent->parent->color = RED;
	// 					node = node->parent->parent;	
	// 				}
	// 				else
	// 				{
	// 					if (node == node->parent->right)
	// 					{
	// 						// mirror case 1.2
	// 						node = node->parent;
	// 						left_rotate(node);
	// 					}
	// 					// mirror case 1.1
	// 					node->parent->color = BLACK;
	// 					node->parent->parent->color = RED;
	// 					right_rotate(node->parent->parent);
	// 				}
	// 			}
	// 			if (node == root)
	// 				break;
	// 		}
	// 		root->color = BLACK;
	// 	}
		

	// 	void fix_delete(node_ptr x)
	// 	{
	// 		node_ptr s;
	// 		while (x != root && x->color == BLACK)
	// 		{
	// 			if (x == x->parent->left)
	// 			{
	// 				s = x->parent->right;
	// 				if (s->color == RED)
	// 				{
	// 					// case 1.1
	// 					s->color = BLACK;
	// 					x->parent->color = RED;
	// 					left_rotate(x->parent);
	// 					s = x->parent->right;
	// 				}
	// 				if (s->left->color == BLACK && s->right->color == BLACK)
	// 				{
	// 					// case 1.2
	// 					s->color = RED;
	// 					x = x->parent;
	// 				}
	// 				else
	// 				{
	// 					if (s->right->color == BLACK)
	// 					{
	// 						// case 1.3
	// 						s->left->color = BLACK;
	// 						s->color = RED;
	// 						right_rotate(s);
	// 						s = x->parent->right;
	// 					}

	// 					// case 1.4
	// 					s->color = x->parent->color;
	// 					x->parent->color = BLACK;
	// 					s->right->color = BLACK;
	// 					left_rotate(x->parent);
	// 					x = root;
	// 				}
	// 			}
	// 			else
	// 			{
	// 				s = x->parent->left;
	// 				if (s->color == RED)
	// 				{
	// 					// case 1.1
	// 					s->color = BLACK;
	// 					x->parent->color = RED;
	// 					right_rotate(x->parent);
	// 					s = x->parent->left;
	// 				}
	// 				if (s->right->color == BLACK && s->right->color == BLACK)
	// 				{
	// 					// case 1.2
	// 					s->color = RED;
	// 					x = x->parent;
	// 				}
	// 				else
	// 				{
	// 					if (s->left->color == BLACK)
	// 					{
	// 						// case 1.3
	// 						s->right->color = BLACK;
	// 						s->color = RED;
	// 						left_rotate(s);
	// 						s = x->parent->left;
	// 					}

	// 					// case 1.4
	// 					s->color = x->parent->color;
	// 					x->parent->color = BLACK;
	// 					s->left->color = BLACK;
	// 					right_rotate(x->parent);
	// 					x = root;
	// 				}
	// 			}
	// 		}
	// 		x->color = BLACK;
	// 	}

	// 	void rb_transplant(node_ptr u, node_ptr v)
	// 	{
	// 		if (u->parent == NULL)
	// 			root = v;
	// 		else if (u == u->parent->left)
	// 			u->parent->left = v;
	// 		else
	// 			u->parent->right = v;
	// 		v->parent = u->parent;
	// 	}

	// 	void delete_node_helper(node_ptr node, int key)
	// 	{
			
	// 		// find the node containing the key
	// 		node_ptr z = TNULL;
	// 		node_ptr x, y;
	// 		while (node != TNULL)
	// 		{
	// 			if (node->_key == key)
	// 				z = node;
	// 			if (node->_key <= key)
	// 				node = node->right;
	// 			else
	// 				node = node->left;
	// 		}

	// 		if (z == TNULL)
	// 		{
	// 			//std::cout << "Couldn't find the key in the tree " << key << std::endl;
	// 			return ;
	// 		}

	// 		y = z;
	// 		// save the color of the node at the begining
	// 		int y_original_color = y->color;
	// 		if (z->left == TNULL)
	// 		{
	// 			x = z->right;
	// 			rb_transplant(z, z->right);
	// 		}
	// 		else if (z->right == TNULL)
	// 		{
	// 			x = z->left;
	// 			rb_transplant(z, z->left);
	// 		}
	// 		else
	// 		{
	// 			y = minimum(z->right);
	// 			y_original_color = y->color;
	// 			x = y->right;
	// 			if (y->parent == z)
	// 				x->parent = y;
	// 			else
	// 			{
	// 				rb_transplant(y, y->right);
	// 				y->right = z->right;
	// 				y->right->parent = y;
	// 			}
	// 			rb_transplant(z, y);
	// 			y->left = z->left;
	// 			y->left->parent = y;
	// 			y->color = z->color;
	// 		}
	// 		std::cout << z->_key << std::endl;
	// 		delete z;
	// 		if (y_original_color == BLACK)
	// 			fix_delete(x);
	// 	}

	// 	void print_helper(node_ptr root, std::string indent, bool last)
	// 	{
	// 		if (root != TNULL)
	// 		{
	// 			std::cout << indent;
	// 			if (last)
	// 			{
	// 				std::cout << "R----";
	// 				indent += "     ";
	// 			}
	// 			else
	// 			{
	// 				std::cout << "L----";
	// 				indent += "|    ";
	// 			}

	// 			std::string _COLO = root->color ? _RED : B_WHT;
	// 			std::cout << _COLO << root->_key << "-" << root->_val << _END << std::endl;
	// 			print_helper(root->left, indent, false);
	// 			print_helper(root->right, indent, true);
	// 		}
	// 	}
		
		
	// public:
	// 	/*--------------------------------------------------------------*/
	// 	/*						Constructors							*/
	// 	RBTree()
	// 	{
	// 		TNULL = new Node;
	// 		TNULL->color = BLACK;
	// 		TNULL->left = NULL;
	// 		TNULL->right = NULL;
	// 		root = TNULL;
	// 		std::cout << "RBT created" << std::endl;
	// 	}

	// 	// RBTree(const RBTree &src)
	// 	// {
	// 	// 	*this = src;
	// 	// 	std::cout << "RBT copied" << std::endl;
	// 	// }
			
	// 	~RBTree()
	// 	{
	// 		delete_tree(root);
	// 	//	delete root;
	// 		std::cout << "RBT destroyed" << std::endl;
	// 	}

	// 	// RBTree	&operator=(const RBTree &src)
	// 	// {
	// 	// 	root = copy_tree(src.root, src.TNULL);
	// 	// 	return (*this);
	// 	// }

	// 	node_ptr get_root() { return (this->root); }

	// 	/*--------------------------------------------------------------*/
	// 	/*						MEMBERS_FUNCTIONS						*/


	// 	/*           1
	// 	*          /   \
	// 	*         2		3
	// 	*        / \
	// 	*       4   5
	// 	*
	// 	*	trees can be traversed in different ways which are generally those:
	// 	*	- preorder: Root, Left, Right: 1 2 4 5 3
	// 	*	- inorder: Left, Root, Right: 4 2 5 1 3
	// 	*	- postorder: Left, Right, Root: 4 5 2 3 1
	// 	*/
	// 	void preorder_traversal()
	// 	{
	// 		preorder_traversal_helper(this->root);
	// 	}
	// 	void inorder_traversal()
	// 	{
	// 		inorder_traversal_helper(this->root);
	// 	}
	// 	void postorder_traversal()
	// 	{
	// 		postorder_traversal_helper(this->root);
	// 	}

	// 	/* search the tree for the key, and return the corresponding node */
	// 	node_ptr search_tree(int key) { return(search_tree_helper(this->root, key)); }

	// 	node_ptr minimum(node_ptr node)
	// 	{
	// 		if (node->left != TNULL)
	// 			node = node->left;
	// 		return (node);
	// 	}
	// 	node_ptr maximum(node_ptr node)
	// 	{
	// 		if (node->right != TNULL)
	// 			node = node->right;
	// 		return (node);
	// 	}

	// 	/*             50
	// 	*          /        \
	// 	*         30		 70
	// 	*       /    \         \
	// 	*     23      35        80
	// 	*    /  \    /  \      /  \
	// 	*  11   25  31   42   73   85
	// 	*
	// 	*	- if the right subtree isn't null, the successor is the leftmost node in the
	// 	*	right subtree. successor of 50 == 73
	// 	*	- else, the successor is the lowest ancestor of node, whose left child is
	// 	*	also a node's ancestor. for x = 25, y = 23
	// 	*	while (y != TNULL && x == y->right) -> x = 23, y = 30 -> 30 is its parent's left -> stop
	// 	*					successor of 25 == 30
	// 	*/
	// 	node_ptr successor(node_ptr x)
	// 	{
	// 		if (x->right != TNULL)
	// 			return (minimum(x->right));
	// 		node_ptr y = x->parent;
	// 		while (y != TNULL && x == y->right)
	// 		{
	// 			x = y;
	// 			y = y->parent;
	// 		}
	// 		return (y);
	// 	}
	// 	/* predecessor: the same as successor, but in symetry */
	// 	node_ptr predecessor(node_ptr x)
	// 	{
	// 		if (x->left != TNULL)
	// 			return (maximum(x->left));
	// 		node_ptr y = x->parent;
	// 		while (y != TNULL && x == y->left)
	// 		{
	// 			x = y;
	// 			y = y->parent;
	// 		}
	// 		return (y);
	// 	}

	// 	/*			|				   |
	// 	*           x				   y   
	// 	*         /   \				 /   \
	// 	*        a     y	-->		x     c
	// 	*             / \		   / \
	// 	*            b   c		  a   b
	// 	*
	// 	*	the left rotation at node x makes x goes down 
	// 	*	in the left direction and as a result, its 
	// 	*	right child goes up
	// 	*/
	// 	void left_rotate(node_ptr x)
	// 	{
	// 		node_ptr y = x->right;
	// 		x->right = y->left;

	// 		if (y->left != TNULL)
	// 			y->left->parent = x;

	// 		y->parent = x->parent;

	// 		if (x->parent == NULL)
	// 			this->root = y;
	// 		else if (x == x->parent->left)
	// 			x->parent->left = y;
	// 		else
	// 			x->parent->right = y;

	// 		y->left = x;
	// 		x->parent = y;
	// 	}

	// 	/*			|				   |
	// 	*           y   			   x
	// 	*         /   \				 /   \
	// 	*        x     c	-->		a     y
	// 	*       / \						 / \
	// 	*      a   b					b   c
	// 	*
	// 	*	the right rotation at node x makes x goes down 
	// 	*	in the right direction and as a result, its 
	// 	*	right child goes up
	// 	*/
	// 	void right_rotate(node_ptr x)
	// 	{
	// 		node_ptr y = x->left;
	// 		x->left = y->right;

	// 		if (y->right != TNULL)
	// 			y->right->parent = x;

	// 		y->parent = x->parent;

	// 		if (x->parent == NULL)
	// 			this->root = y;
	// 		else if (x == x->parent->right)
	// 			x->parent->right = y;
	// 		else 
	// 			x->parent->left = y;

	// 		y->right = x;
	// 		x->parent = y;
	// 	}

	// 	/*
	// 	*	To insert a new node in a RTB we need to:
	// 	*	- insert node using an ordinary BST insertion operation
	// 	*	- color the new node in red
	// 	*	- check if the insertion violated the RBT properties, if
	// 	*	it did, we fix it
	// 	*/
	// 	void insert(const K &key, const V &val)
	// 	{
	// 		// ordinary Binary Search Insertion
	// 		node_ptr node = create_node(key, val);

	// 		node_ptr y = NULL;
	// 		node_ptr x = this->root;

	// 		while (x != TNULL)
	// 		{
	// 			y = x;
	// 			if (node->_key < x->_key)
	// 				x = x->left;
	// 			else
	// 				x = x->right;
	// 		}

	// 		// y is parent of x
	// 		node->parent = y;
	// 		if (y == NULL)
	// 			root = node;
	// 		else if (node->_key < y->_key)
	// 			y->left = node;
	// 		else
	// 			y->right = node;

	// 		// if new node is a root node, simply return
	// 		if (node->parent == NULL)
	// 		{
	// 			node->color = BLACK;
	// 			return ;
	// 		}

	// 		// if the grandparent is null, simply return
	// 		if (node->parent->parent == NULL)
	// 		{
	// 			return ;
	// 		}
	// 		// Fix the tree
	// 		fix_insert(node);
	// 	}

	// 	void delete_node(int key)
	// 	{
	// 		delete_node_helper(this->root, key);
	// 	}

	// 	void printRBT()
	// 	{
	// 		if (root)
	// 		{
	// 			std::cout << std::endl;
	// 			print_helper(this->root, "", true);
	// 			std::cout << _END;
	// 		}
	// 	}

	// 	node_ptr find_key(const K &key) const
	// 	{
	// 		node_ptr node = root;
	// 		while ( node != TNULL && node->_key != key)
	// 		{
	// 			if (key < node->_key)
	// 				node = node->left;
	// 			else
	// 				node = node->right;
	// 		}
	// 		return (node);
	// 	}

	// 	V &operator[](const K &key) const
	// 	{
	// 		node_ptr node = find_key(key);
	// 		if (node == TNULL)
	// 			throw std::out_of_range("Invalid key");
	// 		return (node->_val);
	// 	}

	// };

	enum { BLACK, RED };
	template < class T >
	struct node
	{
		node			*parent;
		node			*left;
		node			*right;
		size_t			color;		// 0 black and 1 red
		T				value;

		node( void ) : parent(my_nullptr), left(my_nullptr), right(my_nullptr), color(0), value() {
	
			return ;
		}

		node( T const & v, node *p = my_nullptr, node *l = my_nullptr, node *r = my_nullptr, int c = 0 ) :
		parent(p), left(l), right(r), color(c), value(v) {

			return ;
		}

		node( node const &other ) : parent(other.parent), left(other.left), right(other.right), color(other.color), value(other.value) {

			return ;
		}

		node		&operator=( node const &element ) {

			if (this != &element)
			{
				this->parent = element.parent;
				this->left = element.left;
				this->right = element.right;
				this->color = element.color;
				this->value = element.value;
			}
			return (*this);
		}

		bool		operator==( node const &other ) {

			return (this->value == other.value);
		}
	};

	template< class T, class Compare, class Alloc = std::allocator<ft::node<T> > >
	class RBTree
	{
		public:
			// Same as map
			typedef T																value_type;
			typedef typename ft::node<T>											node_type;
			typedef Compare															value_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other		allocation;
			typedef typename allocator_type::reference 								reference;
			typedef typename allocator_type::const_reference 						const_reference;
			typedef typename allocator_type::pointer 								pointer;
			typedef typename allocator_type::const_pointer 							const_pointer;
			typedef typename allocator_type::difference_type 						difference_type;
			typedef typename allocator_type::size_type 								size_type;

			RBTree( value_compare const & cmp = value_compare())  : _size(0), _cmp(cmp) {

				_null = _alloc_test.allocate(1);
				_alloc_test.construct(_null, node_type());
				_root = _null;
				return ;
			}

			~RBTree( void ) {

				return ;
			}

			size_type max_size( void ) const {

				return (_alloc_test.max_size());
			}

			pointer search(value_type val) const {

				return (searchTreeHelper(_root, val));
			}

			pointer min_node( void ) const {

				return (min_node(_root));
			}

			pointer max_node( void ) const {

				return (max_node(_root));
			}

			pointer lower_bound(value_type const & val) const {

				pointer begin = min_node();
				while (begin != _null)
				{
					if (_cmp(begin->value, val) == false)
						break ;
					begin = successor(begin);
				}
				return (begin);
			}

			pointer upper_bound(value_type const & val) const {

				pointer begin = min_node();
				while (begin != _null)
				{
					if (_cmp(val, begin->value) == true)
						break ;
					begin = successor(begin);
				}
				return (begin);
			}

			void	swap(RBTree & x) {

				pointer tmp_r = _root;
				pointer tmp_n = _null;
				size_type tmp_s = _size;
				_root = x.get_root();
				_null = x.get_null();
				_size = x.get_size();
				x._root = tmp_r;
				x._null = tmp_n;
				x._size = tmp_s;
			}

			bool insert(value_type const & val) {

				pointer new_node = allocator_type().allocate(1);
				allocator_type().construct(new_node, node_type(val, my_nullptr, _null,_null, 1));
				pointer cur = my_nullptr;
				pointer root = _root;
				while (root != _null)
				{
					cur = root;
					if (_cmp(new_node->value, root->value))
						root = root->left;
					else if (_cmp(root->value, new_node->value))
						root = root->right;
					else
					{
						allocator_type().destroy(new_node);
						allocator_type().deallocate(new_node, 1);
						return (false);
					}
				}
				new_node->parent = cur;
				if (cur == my_nullptr)
					_root = new_node;
				else if (_cmp(new_node->value, cur->value))
					cur->left = new_node;
				else
					cur->right = new_node;
				if (new_node->parent == my_nullptr)
				{
					new_node->color = BLACK;
					_size++;
					return (true);
				}
				if (new_node->parent->parent == my_nullptr)
				{
					_size++;
					return (true);
				}
				fixInsert(new_node);
				_size++;
				return (true);
			}

			bool deleteNode( value_type const &value ) {

				return deleteNodeHelper(_root, value);
			}

			void destroy( void ) {

				_size = 0;
				ft_clear(_root);
				_root = _null;
				return ;
			}

			void destroynull( void ) {

				allocator_type().destroy(_null);
				allocator_type().deallocate(_null, 1);
				return ;
			}

			pointer successor( pointer node ) const {

				if (node->right != _null)
					return (min_node(node->right));
				if (node->parent == my_nullptr || node == max_node())
					return (_null);
				pointer tmp = node->parent;
				while (tmp != _null && node == tmp->right)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

			/*
			**	Getters
			*/
			pointer	get_root( void ) const {

				return (_root);
			}

			pointer get_null( void ) const {

				return (_null);
			}

			size_type get_size( void ) const {

				return (_size);
			}

		private:
			/*
			**	Private functions
			*/
			void	ft_clear( pointer root ) {

				if (root == _null)
					return ;
				ft_clear(root->left);
				ft_clear(root->right);
				_alloc_test.destroy(root);
				_alloc_test.deallocate(root, 1);
				return ;
			}

			pointer	searchTreeHelper( pointer node, value_type const &value ) const {

				if (node == _null)
					return (node);
				else if (_cmp(value, node->value))
					return (searchTreeHelper(node->left, value));
				else if (_cmp(node->value, value))
					return (searchTreeHelper(node->right, value));
				else
					return (node);
			}

			pointer	min_node( pointer node ) const {

				if (node == my_nullptr || node == _null)
					return (_null);
				while (node->left != _null)
					node = node->left;
				return (node);
			}

			pointer	max_node( pointer node ) const {

				if (node == my_nullptr || node == _null)
					return (_null);
				while (node->right != _null)
					node = node->right;
				return (node);
			}

			void	leftRotate( pointer node ) {

				pointer tmp = node->right;
				node->right = tmp->left;
				if (tmp->left != _null)
					tmp->left->parent = node;
				tmp->parent = node->parent;
				if (node->parent == my_nullptr)
					_root = tmp;
				else if (node == node->parent->left)
					node->parent->left = tmp;
				else
					node->parent->right = tmp;
				tmp->left = node;
				node->parent = tmp;
				return ;
			}

			void	rightRotate( pointer node ) {

				pointer tmp = node->left;
				node->left = tmp->right;
				if (tmp->right != _null)
					tmp->right->parent = node;
				tmp->parent = node->parent;
				if (node->parent == my_nullptr)
					_root = tmp;
				else if (node == node->parent->right)
					node->parent->right = tmp;
				else
					node->parent->left = tmp;
				tmp->right = node;
				node->parent = tmp;
				return ;
			}

			void	fixInsert( pointer node ) {

				pointer tmp = my_nullptr;
				while (node->parent->color == 1)
				{
					if (node->parent == node->parent->parent->right)
					{
						tmp = node->parent->parent->left;
						if (tmp->color == 1)
						{
							tmp->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								rightRotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							leftRotate(node->parent->parent);
						}
					}
					else
					{
						tmp = node->parent->parent->right;
						if (tmp->color == 1)
						{
							tmp->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								leftRotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							rightRotate(node->parent->parent);
						}
					}
					if (node == _root)
						break ;
				}
				_root->color = BLACK;
				return ;
			}

			void	fixDelete( pointer node ) {

				pointer tmp = my_nullptr;
				while (node != _root && node->color == 0)
				{
					if (node == node->parent->left)
					{
						tmp = node->parent->right;
						if (tmp->color == 1)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							leftRotate(node->parent);
							tmp = node->parent->right;
						}
						if (tmp->left->color == 0 && tmp->right->color == 0)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else
						{
							if (tmp->right->color == 0)
							{
								tmp->left->color = BLACK;
								tmp->color = RED;
								rightRotate(tmp);
								tmp = node->parent->right;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							leftRotate(node->parent);
							node = _root;
						}
					}
					else
					{
						tmp = node->parent->left;
						if (tmp->color == 1)
						{
							tmp->color = BLACK;
							node->parent->color = RED;
							rightRotate(node->parent);
							tmp = node->parent->left;
						}
						if (tmp->left->color == 0 && tmp->right->color == 0)
						{
							tmp->color = RED;
							node = node->parent;
						}
						else
						{
							if (tmp->left->color == 0)
							{
								tmp->right->color = BLACK;
								tmp->color = RED;
								leftRotate(tmp);
								tmp = node->parent->left;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;
							rightRotate(node->parent);
							node = _root;
						}
					}
				}
				node->color = BLACK;
				return ;
			}

			void	transplant( pointer node, pointer toTransplant ) {

				if (node->parent == my_nullptr)
					_root = toTransplant;
				else if (node == node->parent->left)
					node->parent->left = toTransplant;
				else
					node->parent->right = toTransplant;
				toTransplant->parent = node->parent;
				return ;
			}

			bool	deleteNodeHelper( pointer node, value_type const &key ) {

				pointer toDelete = _null;
				pointer tmp	= my_nullptr;
				pointer cur = my_nullptr;
				while (node != _null)
				{
					if (_cmp(node->value, key))
						node = node->right;
					else if (_cmp(key, node->value))
						node = node->left;
					else
					{
						toDelete = node;
						node = node->right;
					}
				}
				if (toDelete == _null)
					return (false);
				cur = toDelete;
				int tmp_color = cur->color;
				if (toDelete->left == _null)
				{
					tmp = toDelete->right;
					transplant(toDelete, toDelete->right);
				}
				else if (toDelete->right == _null)
				{
					tmp = toDelete->left;
					transplant(toDelete, toDelete->left);
				}
				else
				{
					cur = min_node(toDelete->right);
					tmp_color = cur->color;
					tmp = cur->right;
					if (cur->parent == toDelete)
						tmp->parent = cur;
					else
					{
						transplant(cur, cur->right);
						cur->right = toDelete->right;
						cur->right->parent = cur;	
					}
					transplant(toDelete, cur);
					cur->left = toDelete->left;
					cur->left->parent = cur;
					cur->color = toDelete->color;
				}
				_alloc_test.destroy(toDelete);
				_alloc_test.deallocate(toDelete, 1);
				if (tmp_color == 0)
					fixDelete(tmp);
				--_size;
				return (true);
			}

			pointer				_root;
			pointer				_null;
			size_type			_size;
			value_compare 		_cmp;
			allocation			_alloc_test;
	};
}; // namespace ft

#endif