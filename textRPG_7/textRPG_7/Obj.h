#pragma once

class CObj
{
protected:
	string m_strName;
	int		m_iPower;
	int		m_iHp;
	int		m_iMoney;

public:
	virtual inline int GetPower() const { return m_iPower; }
	inline int GetHP() const { return m_iHp; }
	inline int GetMoney() const { return m_iMoney; }

public:
	virtual void RenderInfo() const;
	virtual void SetDamage(int _iPower);

public:
	CObj();
	CObj(string _strName, int _iPower, int _iHP, int _iMoney);
	virtual ~CObj();
};

