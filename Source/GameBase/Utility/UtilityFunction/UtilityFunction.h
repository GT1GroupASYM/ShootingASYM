/////////////////////////////////////////////////////
// Name : UtilityFunction
//
// Author : 山田 聖弥
//
// Day : 2017/7/26
/////////////////////////////////////////////////////
#pragma once

/////////////////////////////////////////////////////
// Name : Clamp
//
// Over View : 値を範囲内に強制する
//
// Argument : 強制する値、最小値、最大値
//
// Return : 強制結果
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
// Over View : 値を範囲内に強制する
//
// Argument : 強制する値、最小値、最大値
//
// Return : 強制結果
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
// Over View : 値を範囲内に強制する
//
// Argument : 強制する値、最小値、最大値
//
// Return : 強制結果
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