#pragma once
class CItem
{
protected:
	string	m_strName;
	int		m_iPrice;
	int		m_iAblity;

public:
	inline const string GetName() const { return m_strName; }
	inline const int GetPrice() const { return m_iPrice; }
	inline const int GetAbility() const { return m_iAblity; }

public:
	void Draw();
	virtual void RenderInfo() const = 0;

public:
	CItem();
	CItem(string _strName, int _iPrice, int _iAbility);
	virtual ~CItem();
};

