#include "pch.h"

std::string GetAlphabet(std::string str)
{
	std::set<char> temp;
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		temp.insert(str[i]);
	}
	int count = temp.size();
	std::string res;
	res.resize(count);
	int i = 0;
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		res[i] = *iter;
		++i;
	}
	return res;
}


std::vector<int> FLastInd(std::string str, std::string alphabet) {
	int power = alphabet.length();
	std::vector<int> LastInclude(power);
	int m = str.length();
	int q = 0;
	for (int i = 0; i < power; ++i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			if (alphabet[i] == str[j])
			{
				LastInclude[i] = j == m - 1 ? m : m - j - 1;
				break;
			}
		}
	}
	return LastInclude;
}

int GetOffset(char c, std::string alphabet, std::vector<int> lastind, int size)
{
	bool InABC = false;
	int len = alphabet.length();
	int i;
	for (i = 0; i < len; ++i)
	{
		if (c == alphabet[i])
		{
			InABC = true;
			break;
		}
	}
	return InABC ? lastind[i] : size;
}
int BMSearch(std::string text, std::string str)
{
	int n = text.length();
	int m = str.length();
	int j, i;
	std::string alphabet = GetAlphabet(str);
	std::vector<int> lastind = FLastInd(str, alphabet);
	for (i = m - 1; i < n; )
	{
		for (j = m - 1; j >= 0; --j)
		{
			if (str[j] == text[i])
			{
				--i;
			}
			else
			{
				int offset = GetOffset(text[i], alphabet, lastind, m);
				i += offset;
				break;
			}
		}
		if (j == -1)
			return i + 1;
	}
	return -15;

}
