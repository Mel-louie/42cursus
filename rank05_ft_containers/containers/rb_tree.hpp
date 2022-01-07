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

namespace ft
{
	template<typename T, typename U>
	class RBTree
	{
		struct Node
		{
			enum Color { BLACK, RED };
			T     _key;
			U     _val;
			Color color;
			Node* parent;
			Node* left;
			Node* right;

			Node(T key, U val = U()) : _key(key), _val(val), color(BLACK), parent(), left(), right() {}
			Node(Node const& src) { *this = src; }
			~Node() {}
			Node& operator=(Node const& rhs)
			{
				if (*this != rhs)
				{
					_key = rhs._key;
					_val = rhs._val;
					color = rhs.color;
					parent = rhs.parent;
					left = rhs.left;
					right = rhs.right;
				}
				return (*this);
			}
		};/* Node struct END */

		/*--------------------------------------------------------------*/
		/*							Attributes							*/
	private:
		Node	NIL_node;
		Node	*NIL;
		Node	*root;

	public:
		/*--------------------------------------------------------------*/
		/*						Constructors							*/
		RBTree(): NIL_node(T(), U()), NIL(&NIL_node), root(NIL)
		{
			NIL->color = Node::BLACK;
			NIL->left = NIL;
			NIL->parent = NIL;
			NIL->right = NIL;
			std::cout << "RBT created" << std::endl;
		}
		RBTree(const RBTree &src): NIL_node(T(), U(), NIL(&NIL_node), root(NIL))
		{
			*this = src;
			std::cout << "RBT copied" << std::endl;
		}
			
		~RBTree() { delete_tree(root); std::cout << "RBT destroyed" << std::endl; }


		void delete_tree(Node* node)
		{
			if (node == NIL)
			{
				return;
			}
			delete_tree(node->left);
			delete_tree(node->right);
			delete_tree(node);
		}
	};
}; // namespace ft
#endif