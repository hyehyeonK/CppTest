#pragma once
class CItem
{
protected:
	char	m_szName[128];
	int		m_iType;
	int		m_iPrice;

public:
	inline int GetPrice() const { return m_iPrice; };
	inline int GetType() const { return m_iType; };

public:
	void RenderInfo() const;
	virtual int GetAbility() const = 0;
	virtual void RenderAbility() const = 0;

public:
	CItem();
	CItem(char* szName, int iType, int iPrice);
	~CItem();
};

