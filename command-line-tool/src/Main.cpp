#include "cliUtils.h"

#define EXIT_ERROR_CODE 1
#define PRINT_ERROR(msg) do{ std::wcerr << msg << std::endl; }while(0)

int wmain(int argc, wchar_t* argv[])
{

	if (argc < 2)
	{
		PRINT_ERROR(L"[X] No file name provided");
		return EXIT_ERROR_CODE;
	}

	std::wstring lFilePath(argv[1]);

	if (!isFileExists(lFilePath))
	{
		PRINT_ERROR(L"[X] File doesn't exists");
		return EXIT_ERROR_CODE;
	}

	if (isFileAFolder(lFilePath))
	{
		PRINT_ERROR(L"[X] File is a folder");
		return EXIT_ERROR_CODE;
	}

	auto lRetVal = CheckFile(lFilePath);

	return lRetVal;
}

