#include "stdafx.h"
#include "Item.h"

CItem::CItem()
{
}

CItem::CItem(string _strName, int _iPrice, int _iAbility)
	:m_strName(_strName), m_iPrice(_iPrice), m_iAblity(_iAbility)
{
}


CItem::~CItem()
{
}

void CItem::Draw()
{
	cout << m_strName << " (";
	RenderInfo();
	cout << ")\t°¡°Ý : " << m_iPrice << endl;
}