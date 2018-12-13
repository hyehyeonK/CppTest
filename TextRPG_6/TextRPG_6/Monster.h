#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	void RenderInfo() const;
public:
	// CObj을(를) 통해 상속됨
	virtual void ResetHP() override;
	virtual bool SpendMoney(int iPrice) override;
	virtual void EarnMoney(int iCoin) override;
	virtual void SetArmor(CItem * pArmor) override;
	virtual CItem * GetArmor() override;
	virtual void SetWeapon(CItem * pWeapon) override;
	virtual CItem * GetWeapon() override;
public:
	CMonster();
	CMonster(string strName, int iHP, int iPower, int iMoney);
	~CMonster();

	
};

