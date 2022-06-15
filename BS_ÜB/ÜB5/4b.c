#include "4b.h"
#include <stdio.h> /* für NULL */
#include <stdlib.h> /* für exit(int) */

static void *recursive_alloc(node_t node, char request_id, size_t size) {
  // Diese rekrusive Funktion könnt ihr als Hilfsfunktion implementieren
	if(size<=0){
		return NULL;
	}
	if(*node>0){
		return NULL;
	}
	if(request_id<=0){
		exit(255);	
	}
	if(node == NULL){   //Blatt gefunden
		return NULL;
	}
	if(node_width_chunks(node) != size){  //size = Groesse die angefordert wird
		if(node_width_chunks(node) > size){
			node_t left_node = bst_left(node);
			node_t right_node = bst_right(node);
			void *startAdress  = recursive_alloc(left_node, request_id, size);
			if(startAdress!=NULL){
				*node = -1;  
				return startAdress;			
			}
			else{
			void *startAdress  = recursive_alloc(right_node, request_id, size);	
				
				if(startAdress!=NULL){  
					*node = -1;   //angebrochene Knoten
					return startAdress;			
				}	
			}
			
			
	}
		if(node_width_chunks(node) < size){
			return NULL;
		}
		
		
	}
	else{
		if(*node==0){
			*node = request_id; //Speicherplatz passt perfekt
			void *startAdress  = node_start_addr(node);
			return startAdress; 
		}
		else{
			return NULL;
		}	
	}

	return NULL;

}

void *buddy_alloc(char request_id, size_t size) {
  // inen unbelegten Knoten mit passenden Blockgröße suchen
	if(size<=0){
	return NULL;
	}
	else{
		size = size_to_chunks(size);
	}
	
	if(request_id >0){
	return recursive_alloc(bst_root(), request_id, size);
	}
	else{
		exit(255);  // return !=0 mit Wert 255 vom gesamten Programm
	}
	
	

}
