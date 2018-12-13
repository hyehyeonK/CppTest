#include "stdafx.h"
#include "Inventory.h"

CInventory::CInventory()
	:m_pHead(nullptr), m_pTail(nullptr)
{
}

CInventory::~CInventory()
{
	while (true)
	{
		if (nullptr == m_pHead)
			break;

		SAFE_DELETE(m_pHead->pItem);
		m_pHead = m_pHead->pNext;
	}
}

void CInventory::Add(CItem * CItem)
{
	NODE* pTemp = new NODE;
	pTemp->pItem = CItem;
	pTemp->pNext = nullptr;

	if (nullptr == m_pHead)
	{
		m_pHead = pTemp;
		m_pTail = pTemp;
		pTemp = nullptr;
	}
	else
	{
		m_pTail->pNext = pTemp;
		m_pTail = pTemp;
	}
}

CItem * CInventory::Get(int iIndex)
{
	NODE*	pCurrNode = m_pHead;
	for (int i = 0; i < iIndex; ++i)
	{
		if (nullptr == pCurrNode->pNext)
		{
			return nullptr;
		}
		pCurrNode = pCurrNode->pNext;
	}

	return pCurrNode->pItem;
}

void CInventory::DeleteNode(int iIndex)
{
	if (0 == iIndex)
	{
		m_pHead = m_pHead->pNext;
	}
	else
	{
		NODE*	pCurrNode = m_pHead;

		for (int i = 0; i < (iIndex-1); ++i)
		{
			pCurrNode = pCurrNode->pNext;
		}
		NODE* pTargetNode = pCurrNode->pNext;
		pCurrNode->pNext = pTargetNode->pNext;
		//SAFE_DELETE(pTargetNode);
	}
}

void CInventory::DrawList() const
{
	cout << "\n===============< Inventory >==============" << endl;
	if (nullptr == m_pHead)
	{
		cout << "( 비어있음 )" << endl;
		return;
	}

	NODE* pCurrNode = m_pHead;
	int iCount = 0;
	while(true)
	{
		if (nullptr == pCurrNode)
			break;

		++iCount;
		cout << pCurrNode->pItem->GetName() << "\t";
		if (iCount % 3 == 0)
			cout << endl;

		pCurrNode = pCurrNode->pNext;
		
	}
	cout << endl;
}

bool CInventory::IsEmpty()
{
	if (nullptr == m_pHead) return true;
	else return false;
}
