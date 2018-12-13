#pragma once
#include "Item.h"

typedef struct tagNode
{
	CItem*	pItem;
	tagNode*	pNext;

}NODE;

class CInventory
{
private:
	NODE* m_pHead;
	NODE* m_pTail;

public:
	void Add(CItem* _pItem);
	CItem* Get(int iIndex);
	void DeleteNode(int iIndex);

public:
	void DrawList() const;
	bool IsEmpty();

public:
	CInventory();
	~CInventory();
};

