#pragma once
#include <vector>
#define simple 17

template <typename T>
class UniversalHash
{
public:
	std::vector<T> __table;
	int __mod;
	int __count;
public:
	UniversalHash();
	UniversalHash(int mod);
	UniversalHash(std::vector<T>);
	void Insert(T);
	void SetMod(int);
	void Rehash();
	void Delete(T);
	int Hash(T);
	int Search(T);
	int GetCount();
};

template<typename T>
inline UniversalHash<T>::UniversalHash()
{
	__count = 0;
	__mod = 11;
	std::vector<T> table(__mod);
	__table = table;
}

template<typename T>
inline UniversalHash<T>::UniversalHash(int mod)
{
	__count = 0;
	__mod = mod;
	std::vector<T> table(mod);
	__table = table;
}

template<typename T>
inline UniversalHash<T>::UniversalHash(std::vector<T> arr)
{
	UniversalHash<T> temp;
	__count = 0;
	__table = temp.__table;
	__mod = temp.__mod;
	for (auto k : arr)
	{
		Insert(k);
	}
}

template<typename T>
inline void UniversalHash<T>::Insert(T k)
{
	++__count;
	if (__count == __mod + 1)
	{
		Rehash();
	}
	int first = Hash(k);
	int second = 1 + k % (__mod - 1);
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (first + i * second) % __mod;
		if (!(__table[p] > 0))
		{
			__table[p] = k;
			break;
		}
	}
}



template<typename T>
inline void UniversalHash<T>::SetMod(int mod)
{
	__mod = mod;
}

template<typename T>
inline void UniversalHash<T>::Rehash()
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
inline void UniversalHash<T>::Delete(T k)
{
	int first = Hash(k);
	int second = 1 + k % (__mod - 1);;
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (first + i*second) % __mod;
		if (__table[p] == k)
		{
			__table[p] = -1;
			break;
		}
	}
	--__count;
}

template<typename T>
inline int UniversalHash<T>::Hash(T k)
{
	int a = rand() % (simple - 1) + 1;
	return ((a * k) % simple) % __mod;
}

template<typename T>
inline int UniversalHash<T>::Search(T k)
{
	int first = Hash(k);
	int second = 1 + k%(__mod - 1);
	int p;
	for (int i = 0; i < __mod; ++i)
	{
		p = (first + i * second) % __mod;
		if (__table[p] == k)
		{
			return p;
		}
	}
	return -15;
}

template<typename T>
inline int UniversalHash<T>::GetCount()
{
	return __count;
}
