/////////////////////////////////////////////////////
// Name : UtilityFunction
//
// Author : �R�c ����
//
// Day : 2017/7/26
/////////////////////////////////////////////////////
#pragma once

/////////////////////////////////////////////////////
// Name : Clamp
//
// Over View : �l��͈͓��ɋ�������
//
// Argument : ��������l�A�ŏ��l�A�ő�l
//
// Return : ��������
/////////////////////////////////////////////////////
int Clamp(int num,int min,int max)
{
	auto result = num;

	if (result < min)
		result = min;
	if (result > max)
		result = max;

	return result;
}

/////////////////////////////////////////////////////
// Name : Clamp
//
// Over View : �l��͈͓��ɋ�������
//
// Argument : ��������l�A�ŏ��l�A�ő�l
//
// Return : ��������
/////////////////////////////////////////////////////
float Clamp(float num, float min, float max)
{
	auto result = num;

	if (result < min)
		result = min;
	if (result > max)
		result = max;

	return result;
}

/////////////////////////////////////////////////////
// Name : Clamp
//
// Over View : �l��͈͓��ɋ�������
//
// Argument : ��������l�A�ŏ��l�A�ő�l
//
// Return : ��������
/////////////////////////////////////////////////////
double Clamp(double num, double min, double max)
{
	auto result = num;

	if (result < min)
		result = min;
	if (result > max)
		result = max;

	return result;
}