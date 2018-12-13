#include "stdafx.h"
#include "Item.h"


void CItem::RenderInfo() const
{
	cout << m_szName << " (";
	GetAbility();
	cout << ")\t/ АЁАн : " << m_iPrice;
}

CItem::CItem()
{
}

CItem::CItem(char * szName, int iType, int iPrice)
	:m_iType(iType), m_iPrice(iPrice)
{
	strcpy_s(m_szName, szName);
}


CItem::~CItem()
{
}
