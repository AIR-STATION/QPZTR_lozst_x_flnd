#pragma once
class SettingData
{
private:
	SettingData() {
		SamplingRate = 0;
		Date_From = 0;
		Date_To = 0;
	}
	~SettingData() {}
	SettingData(const SettingData& other);
	static SettingData* inst;
public:
	static SettingData* getInstance() {
		if (inst == 0) inst = new SettingData();
		return inst;
	}
	
	int SamplingRate;
	int Date_From;
	int Date_To;
};