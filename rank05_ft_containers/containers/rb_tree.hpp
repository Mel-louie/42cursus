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
	enum { BLACK, RED };
	template<class T>
	struct node
	{
		node			*parent;
		node			*left;
		node			*right;
		size_t			color;		// 0 black and 1 red
		T				value;

		node(): parent(my_nullptr), left(my_nullptr), right(my_nullptr), color(0), value() {}

		node(const T &v, node *p = my_nullptr, node *l = my_nullptr, node *r = my_nullptr, int c = 0 ):
		parent(p), left(l), right(r), color(c), value(v) {}

		node(const node &copy): parent(copy.parent), left(copy.left), right(copy.right), color(copy.color), value(copy.value) {}

		node &operator=(const node &rhs) {

			if (this != &rhs)
			{
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
				this->color = rhs.color;
				this->value = rhs.value;
			}
			return (*this);
		}

		bool operator==( node const &x ) { return (this->value == x.value); }
	};

	template<class T, class Compare, class Alloc = std::allocator<ft::node<T> > >
	class RBTree
	{
		public:
			/* same as map */
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

		private:
		/*--------------------------------------------------------------*/
		/*						Attributes								*/
			pointer				_root;
			pointer				_null;
			size_type			_size;
			value_compare 		_cmp;
			allocation			_alloc_test;

		/*--------------------------------------------------------------*/
		/*				PRIVATE MEMBERS_FUNCTIONS						*/
			void	clear(pointer root)
			{
				if (root == _null)
					return ;
				clear(root->left);
				clear(root->right);
				_alloc_test.destroy(root);
				_alloc_test.deallocate(root, 1);
				return ;
			}

			void preorder_traversal_helper(pointer node)
			{
				if (node != _null)
				{
					std::cout << node->value << " ";
					preorder_traversal_helper(node->left);
					preorder_traversal_helper(node->right);
				}			
			}

			void inorder_traversal_helper(pointer node)
			{
				if (node != _null)
				{
					inorder_traversal_helper(node->left);
					std::cout << node->value << " ";
					inorder_traversal_helper(node->right);
				}
			}

			void postorder_traversal_helper(pointer node)
			{
				if (node != _null)
				{
					postorder_traversal_helper(node->left);
					postorder_traversal_helper(node->right);
					std::cout << node->value << " ";
				}			
			}

			pointer	search_tree_helper(pointer node, const value_type &value ) const
			{
				if (node == _null)
					return (node);
				else if (_cmp(value, node->value))
					return (search_tree_helper(node->left, value));
				else if (_cmp(node->value, value))
					return (search_tree_helper(node->right, value));
				else
					return (node);
			}

			pointer	min_node(pointer node) const
			{
				if (node == my_nullptr || node == _null)
					return (_null);
				while (node->left != _null)
					node = node->left;
				return (node);
			}

			pointer	max_node(pointer node) const
			{
				if (node == my_nullptr || node == _null)
					return (_null);
				while (node->right != _null)
					node = node->right;
				return (node);
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
			void	left_rotate(pointer x)
			{
				pointer y = x->right;
				x->right = y->left;

				if (y->left != _null)
					y->left->parent = x;

				y->parent = x->parent;

				if (x->parent == my_nullptr)
					this->_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;

				y->left = x;
				x->parent = y;
				return ;
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
			void	right_rotate(pointer x)
			{
				pointer y = x->left;
				x->left = y->right;

				if (y->right != _null)
					y->right->parent = x;

				y->parent = x->parent;

				if (x->parent == my_nullptr)
					this->_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else 
					x->parent->left = y;

				y->right = x;
				x->parent = y;
				return ;
			}

			void	fix_insert( pointer node )
			{
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
								right_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							left_rotate(node->parent->parent);
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
								left_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							right_rotate(node->parent->parent);
						}
					}
					if (node == _root)
						break ;
				}
				_root->color = BLACK;
				return ;
			}

			void	fix_delete(pointer node)
			{
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
							left_rotate(node->parent);
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
								right_rotate(tmp);
								tmp = node->parent->right;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							left_rotate(node->parent);
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
							right_rotate(node->parent);
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
								left_rotate(tmp);
								tmp = node->parent->left;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;
							right_rotate(node->parent);
							node = _root;
						}
					}
				}
				node->color = BLACK;
				return ;
			}

			void	transplant(pointer node, pointer to_transplant)
			{
				if (node->parent == my_nullptr)
					_root = to_transplant;
				else if (node == node->parent->left)
					node->parent->left = to_transplant;
				else
					node->parent->right = to_transplant;
				to_transplant->parent = node->parent;
				return ;
			}

			bool	delete_node_helper(pointer node, const value_type &key)
			{
				pointer to_delete = _null;
				pointer tmp	= my_nullptr;
				pointer current = my_nullptr;
				while (node != _null)
				{
					if (_cmp(node->value, key))
						node = node->right;
					else if (_cmp(key, node->value))
						node = node->left;
					else
					{
						to_delete = node;
						node = node->right;
					}
				}
				if (to_delete == _null)
					return (false);
				current = to_delete;
				int tmp_color = current->color;
				if (to_delete->left == _null)
				{
					tmp = to_delete->right;
					transplant(to_delete, to_delete->right);
				}
				else if (to_delete->right == _null)
				{
					tmp = to_delete->left;
					transplant(to_delete, to_delete->left);
				}
				else
				{
					current = min_node(to_delete->right);
					tmp_color = current->color;
					tmp = current->right;
					if (current->parent == to_delete)
						tmp->parent = current;
					else
					{
						transplant(current, current->right);
						current->right = to_delete->right;
						current->right->parent = current;	
					}
					transplant(to_delete, current);
					current->left = to_delete->left;
					current->left->parent = current;
					current->color = to_delete->color;
				}
				_alloc_test.destroy(to_delete);
				_alloc_test.deallocate(to_delete, 1);
				if (tmp_color == 0)
					fix_delete(tmp);
				--_size;
				return (true);
			}

			void print_helper(pointer root, std::string indent, bool last)
			{
				if (root != _null)
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
					std::cout << _COLO << "o" << _END << std::endl;
					print_helper(root->left, indent, false);
					print_helper(root->right, indent, true);
				}
			}
	
		/*--------------------------------------------------------------*/
		/*						MEMBERS_FUNCTIONS						*/
		public:
			RBTree(const value_compare &cmp = value_compare()): _size(0), _cmp(cmp)
			{
				_null = _alloc_test.allocate(1);
				_alloc_test.construct(_null, node_type());
				_root = _null;
				return ;
			}

			~RBTree() {}

			size_type max_size() const { return (_alloc_test.max_size()); }

			pointer search(value_type val) const { return (search_tree_helper(_root, val)); }

			pointer min_node( void ) const { return (min_node(_root)); }

			pointer max_node( void ) const { return (max_node(_root)); }

			// void	swap(RBTree &x)
			// {
			// 	pointer tmp_r = _root;
			// 	pointer tmp_n = _null;
			// 	size_type tmp_s = _size;
			// 	_root = x.get_root();
			// 	_null = x.get_null();
			// 	_size = x.get_size();
			// 	x._root = tmp_r;
			// 	x._null = tmp_n;
			// 	x._size = tmp_s;
			// }

		/*
		*	To insert a new node in a RTB we need to:
		*	- insert node using an ordinary BST insertion operation
		*	- color the new node in red
		*	- check if the insertion violated the RBT properties, if
		*	it did, we fix it
		*/
			bool insert(const value_type &val)
			{
				pointer new_node = allocator_type().allocate(1);
				allocator_type().construct(new_node, node_type(val, my_nullptr, _null,_null, 1));
				pointer node = my_nullptr;
				pointer root = _root;

				// ordinary Binary Search Insertion
				while (root != _null)
				{
					node = root;
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

				new_node->parent = node;
				if (node == my_nullptr)
					_root = new_node;
				else if (_cmp(new_node->value, node->value))
					node->left = new_node;
				else
					node->right = new_node;

				// if new node is a root node, simply return
				if (new_node->parent == my_nullptr)
				{
					new_node->color = BLACK;
					_size++;
					return (true);
				}
				// if the grandparent is null, simply return
				if (new_node->parent->parent == my_nullptr)
				{
					_size++;
					return (true);
				}
				// Fix the tree
				fix_insert(new_node);
				_size++;
				return (true);
			}

			bool delete_node( value_type const &value )
			{
				return (delete_node_helper(_root, value));
			}

			void destroy()
			{
				_size = 0;
				clear(_root);
				_root = _null;
				return ;
			}

			void destroy_null()
			{
				allocator_type().destroy(_null);
				allocator_type().deallocate(_null, 1);
				return ;
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
			pointer successor(pointer node) const // node = x ; tmp = y
			{
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
			/* predecessor: the same as successor, but in symetry */
			pointer predecessor(pointer node) const
			{
				if (node->left != _null)
					return (max_node(node->left));
				if (node->parent == my_nullptr || node == max_node())
					return (_null);
				pointer tmp = node->parent;
				while (tmp != _null && node == tmp->left)
				{
					node = tmp;
					tmp = tmp->parent;
				}
				return (tmp);
			}

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
				preorder_traversal_helper(this->_root);
			}
			void inorder_traversal()
			{
				inorder_traversal_helper(this->_root);
			}
			void postorder_traversal()
			{
				postorder_traversal_helper(this->_root);
			}

			/*
			*	getters
			*/
			pointer	get_root() const { return (_root); }

			pointer get_null() const { return (_null); }

			size_type get_size() const { return (_size); }


			void printRBT()
			{
				if (_root)
				{
					std::cout << std::endl;
					print_helper(this->_root, "", true);
					std::cout << _END;
				}
			}
	};
}; // namespace ft

#endif