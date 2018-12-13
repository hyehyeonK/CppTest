#include "stdafx.h"
#include "Inventory.h"

CInventory::CInventory()
	:m_iSize(0)
	, m_pHead(nullptr)
	, m_pTail(nullptr)
{
}

CInventory::~CInventory()
{
	while (true)
	{
		NODE* pCurrNode = m_pHead;

		if (nullptr == m_pHead)
			break;

		m_pHead = m_pHead->pNextNode;

		SAFE_DELETE(pCurrNode->pItem);
		SAFE_DELETE(pCurrNode);
	}
}

void CInventory::DrawInventory() const
{
	int iCount = 0;
	cout << "\n================< INVENTORY >================" << endl;
	if (nullptr == m_pHead)
		cout << "( 비어있음 )" << endl;
	else
	{
		NODE* pCurrNode = m_pHead;
		while (true)
		{
			++iCount;
			cout << pCurrNode->pItem->GetName() << "\t";
			if (iCount % 3 == 0)
				cout << endl;

			pCurrNode = pCurrNode->pNextNode;
			if (nullptr == pCurrNode)
				break;
		}
		cout << endl;
	}
}

void CInventory::AddItem(CItem* _pItem)
{
	NODE* pNewNode = new NODE;
	pNewNode->pItem = _pItem;
	pNewNode->pNextNode = nullptr;

	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
		pNewNode = nullptr;
	}
	else
	{
		m_pTail->pNextNode = pNewNode;
		m_pTail = pNewNode;
		pNewNode = nullptr;
	}
	++m_iSize;
}

CItem* CInventory::GetItem(int _iIndex)
{
	if (nullptr == m_pHead)
		return nullptr;

	NODE* pCurrNode = m_pHead;

	for (int i = 0; i < _iIndex; ++i)
	{
		if (nullptr == pCurrNode->pNextNode)
			return nullptr;

		pCurrNode = pCurrNode->pNextNode;
	}

	return pCurrNode->pItem;
}

void CInventory::DeleteItem(int _iIndex)
{
	NODE* pCurrNode = m_pHead;

	if (0 == _iIndex)
	{
		m_pHead = m_pHead->pNextNode;
		SAFE_DELETE(pCurrNode);
	}
	else
	{
		for (int i = 0; i < (_iIndex - 1); ++i)
		{
			pCurrNode = pCurrNode->pNextNode;
		}

		NODE* pTargetNode = pCurrNode->pNextNode;
		pCurrNode->pNextNode = pTargetNode->pNextNode;
		SAFE_DELETE(pTargetNode);
	}
	--m_iSize;
}

bool CInventory::isEmpty()
{
	if (nullptr == m_pHead) return true;
	else return false;
}
