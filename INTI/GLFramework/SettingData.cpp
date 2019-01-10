#include "stdafx.h"
#include "SettingData.h"

SettingData* SettingData::inst;

SettingData::SettingData(const SettingData &other)
{
	SamplingRate = other.SamplingRate;
	Date_From = other.Date_From;
	Date_To = other.Date_To;
}

std::vector<std::string> SettingData::csv_read_row(std::istream & file, char delimiter)
{
	std::stringstream ss;
	bool inquotes = false;
	std::vector<std::string> row;//relying on RVO

	while (file.good())
	{
		char c = file.get();
		if (!inquotes && c == '"')
		{
			inquotes = true;
		}
		else if (inquotes && c == '"')
		{
			if (file.peek() == '"')
			{
				ss << (char)file.get();
			}
			else
			{
				inquotes = false;
			}
		}
		else if (!inquotes && c == delimiter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n'))
		{
			if (file.peek() == '\n') { file.get(); }
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}
}

void SettingData::save()
{
	printf("save toPython");
	std::ofstream file("toPython.csv");
	file << SamplingRate << ", " << Date_From << ", " << Date_To;
}

void SettingData::LoadData()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	//
	si.cb = sizeof(STARTUPINFO);
	::CreateProcess("dataCrop.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("data loaded!");
}
