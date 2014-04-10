#include "stdafx.h"

#define BitShift 3
#define BitsPerChar 8
#define BitMask 0x07
#define MaxNumber 1024
#define Numbers 10
#define Size ((MaxNumber / BitsPerChar) + 1)

unsigned char OutputArray[Size];

void Set(unsigned char a[], int i)
{
	a[i >> BitShift] |= (1 << (i & BitMask));
}

unsigned char Get(unsigned char a[], int i)
{
	return (a[i >> BitShift] & (1 << (i & BitMask)));
}

void Clear(unsigned char a[], int i)
{
	a[i >> BitShift] &= ~(1 << (i & BitMask));
}

int _tmain(int argc, _TCHAR* argv[])
{
	int InputArray[Numbers] = { 1, 3, 5, 7, 9, 11, 15, 19, 21, 25 };

	for (int i = 0; i < Numbers; i++)
	{
		Set(OutputArray, InputArray[i]);
	}

	for (int i = 0; i < Size; i++)
	{
		int result = Get(OutputArray, i);
		if (result != 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}

