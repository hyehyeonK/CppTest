#pragma once
class CObj
{

protected:
	char	m_szName[128];
	int		m_iHP;
	int		m_iPower;
public:
	void RenderInfo() const;
	
public:
	inline int GetHP() const { return m_iHP; };
	inline int GetPower() const { return m_iPower; };
	void Damaged(int iPower);

public:
	CObj();
	CObj(char* szName, int iHP, int iPower);
	~CObj();
};

