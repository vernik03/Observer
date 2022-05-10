#include "Listeners.h"

void ChangeColor::GetFlag(bool flag) {
	if (flag)
	{
		system("cls");
		system("color 2");
		std::cout << output_text;
	}
	else
	{
		system("cls");
		system("color 4");
		std::cout << output_text;
	}
};

void WriteLog::GetFlag(bool flag) {
	if (flag)
	{
		time_in = time(0);
	}
	else
	{
		time_out = time(0);
		try
		{
			log_file.open(filename, std::ios::app);
			if (time_out < time_in)
			{
				throw std::exception("time. time_out < time_in");
			}
			log_file << time_out - time_in << " cекунд\n";
			log_file.close();		

		}
		catch (const std::exception& exept)
		{
			std::cerr << "Error with " << exept.what() << std::endl;
		}

	}
};