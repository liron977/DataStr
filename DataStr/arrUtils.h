#ifndef _ARRUTILS_H
#define _ARRUTILS_H

class arrUtils
{
	double* arr;
	int size_arr;
public:
	void setArr(double* _arr, int _size_arr)
	{
		arr = _arr;
		size_arr = _size_arr;
	}
	bool isValidNumber(int str_size, char* str);
	void getArr();
	void printArr();
};

#endif //_ARRUTILS_H