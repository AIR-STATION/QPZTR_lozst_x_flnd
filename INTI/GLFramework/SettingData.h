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
	
	std::vector<std::string> csv_read_row(std::istream & file, char delimiter);
	void save();
	void LoadData();

	int SamplingRate;
	int Date_From;
	int Date_To;
};