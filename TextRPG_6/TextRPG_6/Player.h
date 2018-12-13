#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:
	int	m_iOriginHP;
	CItem* m_pArmor;
	CItem* m_pWeapon;

public:
	inline void SetArmor(CItem* pArmor) { m_pArmor = pArmor; }
	inline CItem* GetArmor() { return m_pArmor; }
	inline void SetWeapon(CItem* pWeapon) { m_pWeapon = pWeapon; }
	inline CItem* GetWeapon() { return m_pWeapon; }


public:
	void ResetHP();
	bool SpendMoney(int iPrice);
	inline void EarnMoney(int iCoin) { m_iMoney += iCoin; };
	void SetDamage(const int iPower);
	const int GetPower() const;

public:
	void RenderInfo() const;

public:
	CPlayer();
	CPlayer(string strName, int iHP, int iPower);
	~CPlayer();
};

