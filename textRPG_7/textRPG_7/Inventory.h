#pragma once
#include "Item.h"

struct NODE
{
	CItem* pItem;
	NODE* pNextNode;
};

class CInventory
{
private:
	int		m_iSize;
	NODE*	m_pHead;
	NODE*	m_pTail;

public:
	void DrawInventory() const;

public:
	void AddItem(CItem* _pItem);
	CItem* GetItem(int _iIndex);
	void DeleteItem(int _iIndex);
	bool isEmpty();
	inline const int GetSize() const { return m_iSize; }

public:
	CInventory();
	~CInventory();
};

