#include "stdafx.h"
#include "SettingData.h"

SettingData* SettingData::inst;

SettingData::SettingData(const SettingData &other)
{
	SamplingRate = other.SamplingRate;
	Date_From = other.Date_From;
	Date_To = other.Date_To;
}
