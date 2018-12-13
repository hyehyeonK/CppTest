#pragma once
#include "Obj.h"
#include "Item.h"

class CPlayer : public CObj
{
private:
	int		m_iOriginHP;
	CItem*	m_pWeapon;
	CItem*	m_pArmor;

public:
	void SelectJob();
	virtual void RenderInfo() const override;

public:
	inline void SetWeapon(CItem* _pWeapon) { m_pWeapon = _pWeapon; }
	inline void SetArmor(CItem* _pArmor) { m_pArmor = _pArmor; }
	inline CItem* GetWeapon() const { return m_pWeapon; }
	inline CItem* GetArmor() const { return m_pArmor; }

public:
	inline void ResetHP() { m_iHp = m_iOriginHP; }
	virtual void SetDamage(int _iPower) override;
	virtual int GetPower() const;
	bool SpendMoney(int _iPrice);
	inline void EarnMoney(int _iMoney) { m_iMoney += _iMoney; }

public:
	CPlayer();
	~CPlayer();
};

