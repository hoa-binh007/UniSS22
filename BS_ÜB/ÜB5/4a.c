#include "4a.h"
#include <stdio.h> /* für NULL */
#include <stdlib.h> /* für exit(int) */

void buddy_free(void *addr) {
	node_t node = bst_root();
	if(addr == NULL ){				//Fehlerbehandlung
		return;
	}
		while(addr!=node_start_addr(node)){
			if(node == NULL){
				exit(255);
			}
			if(*node > 0){
				break;
			}
			//if(*node  == 0){
			//	break;
			//}
			node_t left_node = bst_left(node);
			node_t right_node = bst_right(node);
			
			if(addr < node_split_addr(node)){
				node = left_node;
			}
			else{
				node = right_node;
			}
		}
		
						
	*node = NODE_FREE;  // NODE_FREE ist 0
	
	
	// Aufrechterhaltung der Invariante (vereinige Buddies, wo nötig)
	bst_housekeeping(bst_root());   //Minus eisen die zu viel sind werden auf 0 gesetzt
	
}
