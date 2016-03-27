#include "node.h"
#include "../../board/ConnectFourBoard.h"

class logger_node {
public:
	static void print_board(ConnectFourBoard board);
	static void print_nodes(Node * root);
};