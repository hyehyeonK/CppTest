#pragma once
#include "Obj.h"
#include "Item.h"

class CPlayer : public CObj
{
private:
	const int	m_iOriginHP;
	int			m_iMoney;
	CItem*		m_pArmor;
	CItem*		m_pWeapone;

public:
	void ResetHP();
	bool SpendMoney(int iPrice);
	inline void EarnMoney(int iCoin) { m_iMoney += iCoin; };

public:
	void RenderInfo() const;
	//int	ItemCount() const { return sizeof(m_pItemList) / sizeof(CItem); }

public:
	inline int GetMoney() const { return m_iMoney; };
	void SetMoney(int iMoney) { m_iMoney = iMoney; };
	void SetArmor(CItem* pItem);
	void SetWeapone(CItem* pItem);
	int GetPower() const;
	void Damaged(int iPower);
	
public:
	
	CPlayer();
	CPlayer(char* szName, int iHP, int iPower, int iMoney);

	~CPlayer();
};

