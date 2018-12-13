#pragma once

class CItem
{
protected:
	const int		m_iType;
	const string	m_strName;
	const int		m_iPrice;
	const int		m_iAbility;

public:
	inline int GetPrice() const { return m_iPrice; }
	inline int GetType() const { return m_iType; }
	inline int GetAblity() const { return m_iAbility; }
	inline string GetName() const { return m_strName; }

public:
	void DrawItem() const;
	virtual void RenderItem() const = 0;

public:
	CItem(int _iType, string _strName, int _iPrice, int _iAbility);
	virtual ~CItem();
};

