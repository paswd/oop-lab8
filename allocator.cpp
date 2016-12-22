#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "allocator.h"

#define NTREE_CONST 5

using namespace std;

AllocatorCluster::AllocatorCluster(void) {
	this->Alloced = false;
	this->Empty = true;
	this->Pointer = NULL;
}
AllocatorCluster::~AllocatorCluster(void) {
	if (this->Alloced) {
		free(this->Pointer);
	}
}
void *AllocatorCluster::Alloc(size_t size) {
	if (!this->Alloced) {
		this->Pointer = calloc(1, size);
		this->Alloced = true;
	} else if (size != this->Size) {
		this->Pointer = realloc(this->Pointer, size);
	}
	this->Empty = false;
	return this->Pointer;
}
void AllocatorCluster::Free(void) {
	this->Empty = true;
}
bool AllocatorCluster::IsEmpty(void) {
	return this->Empty;
}
bool AllocatorCluster::IsCurrentPointer(void *pointer) {
	return pointer == this->Pointer;
}


//=================================================

Allocator::Allocator(void) {
	this->Root = NULL;
	this->NConst = NTREE_CONST;
	//this->ClusterSize = cluster_size;
}

Allocator::~Allocator(void) {
	Node *tmp = this->Root;

	while (tmp != NULL) {
		Node *ths_tmp = tmp;
		tmp = tmp->Child;
		delete ths_tmp;
	}
}

void *Allocator::Alloc(size_t cluster_size) {
	bool found_empty = false;
	Node *ths_ptr = this->Root;
	Node *prev_ptr = NULL;
	void *res = NULL;
	for (size_t i = 0; !found_empty; i++) {
		if (ths_ptr == NULL) {
			ths_ptr = new Node;
			ths_ptr->Level = i;
			ths_ptr->Child = NULL;
			ths_ptr->Parent = prev_ptr;
			if (prev_ptr) {
				ths_ptr->Clusters.resize(prev_ptr->Clusters.size() * this->NConst);
				prev_ptr->Child = ths_ptr;
			} else {
				ths_ptr->Clusters.resize(1);
				this->Root = ths_ptr;
			}
		}
		for (size_t j = 0; j < ths_ptr->Clusters.size(); j++) {
			if (ths_ptr->Clusters[j].IsEmpty()) {
				res = ths_ptr->Clusters[j].Alloc(cluster_size);
				found_empty = true;
				break;
			}
		}
		prev_ptr = ths_ptr;
		ths_ptr = ths_ptr->Child;
	}
	return res;
}

void Allocator::Free(void *pointer) {
	bool found = false;
	Node *ths_ptr = this->Root;
	while (!found && ths_ptr) {
		for (size_t j = 0; j < ths_ptr->Clusters.size(); j++) {
			if (ths_ptr->Clusters[j].IsCurrentPointer(pointer)) {
				ths_ptr->Clusters[j].Free();
				found = true;
			}
		}
		ths_ptr = ths_ptr->Child;
	}
}
