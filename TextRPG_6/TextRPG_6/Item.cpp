#include "stdafx.h"
#include "Item.h"

void CItem::DrawItem() const
{
	cout << m_strName << " (";
	RenderItem();
	cout << ")\t°¡°Ý : " << m_iPrice << endl;
}

CItem::CItem(int _iType, string _strName, int _iPrice, int _iAbility)
	:m_iType(_iType), m_strName(_strName), m_iPrice(_iPrice), m_iAbility(_iAbility)
{
}

CItem::~CItem()
{
}
