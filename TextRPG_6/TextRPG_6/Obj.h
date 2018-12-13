#pragma once
#include "Item.h"

class CObj
{
protected:
	std::string  m_strName;
	int		m_iHP;
	int		m_iPower;
	int		m_iMoney;

public:
	inline const int GetHP() const { return m_iHP; }
	virtual inline const int GetPower() const { return m_iPower; }
	inline int	GetMoney() const { return m_iMoney; }

public:
	virtual inline void SetDamage(const int iPower) { m_iHP -= iPower; }

public:
	virtual void RenderInfo() const;

//Player
public:
	virtual void ResetHP() = 0;
	virtual bool SpendMoney(int iPrice) = 0;
	virtual void EarnMoney(int iCoin) = 0;
	virtual inline void SetArmor(CItem* pArmor) = 0;
	virtual inline CItem* GetArmor() = 0;
	virtual inline void SetWeapon(CItem* pWeapon) = 0;
	virtual inline CItem* GetWeapon() = 0;

public:
	CObj();
	CObj(string _strName, int _iHP, int _iPower, int _iMoney);
	virtual ~CObj();
};

