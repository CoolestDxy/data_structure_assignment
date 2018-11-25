#pragma once

class DblList;
class DblListNode {
	friend class DblList;
public:
	DblListNode(int x=0) { data = x; llink = rlink = this; }
private:

	int data;
	DblListNode*llink, *rlink;
};