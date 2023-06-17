#pragma once
#include <vector>
template <typename T>
class OpenHash
{
public:
	std::vector<T> __table;
	int __mod;
	int __count;
	int __a;
	int __b;
public:
	OpenHash();
	OpenHash(int mod);
	OpenHash(std::vector<T>);
	void Insert(T);
	void SetMod(int);
	void Rehash();
	void Delete(T);
	int Search(T);
	int GetCount();
};

template<typename T>
inline OpenHash<T>::OpenHash()
{
	__count = 0;
	__mod = 11;
	std::vector<T> table(__mod);
	__table = table;
}

template<typename T>
inline OpenHash<T>::OpenHash(int mod)
{
	__count = 0;
	__mod = mod;
	std::vector<T> table(mod);
	__table = table;
}

template<typename T>
inline OpenHash<T>::OpenHash(std::vector<T> arr)
{
	OpenHash<T> temp;
	__count = 0;
	__table = temp.__table;
	__mod = temp.__mod;
	for (auto k : arr)
	{
		Insert(k);
	}
}

template<typename T>
inline void OpenHash<T>::Insert(T k)
{
	++__count;
	if (__count == __mod + 1)
	{
		Rehash();
	}
	int j = k % __mod;
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (j + i) % __mod;
		if (!(__table[p] > 0))
		{
			__table[p] = k;
			break;
		}
	}	
}



template<typename T>
inline void OpenHash<T>::SetMod(int mod)
{
	__mod = mod;
}

template<typename T>
inline void OpenHash<T>::Rehash()
{
	__count = 0;
	SetMod(__mod * 2);
	std::vector<T> temptable = __table;
	std::vector<T> zero(__mod);
	__table = zero;
	for (auto k : temptable)
	{
		Insert(k);
	}
}

template<typename T>
inline void OpenHash<T>::Delete(T k)
{
	int j = k % __mod;
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (j + i) % __mod;
		if (__table[p] == k)
		{
			__table[p] = -1;
			break;
		}
	}
	--__count;
}

template<typename T>
inline int OpenHash<T>::Search(T k)
{
	int j = k % __mod;
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (j + i) % __mod;
		if (__table[p] == k)
		{
			return p;
		}
	}
	return -15;
}

template<typename T>
inline int OpenHash<T>::GetCount()
{
	return count;
}
