#if defined(BUILD_DLL)
# define DLL_EXP __declspec(dllexport)
#else
# if defined(_APPMAINCPP)
# define DLL_EXP __declspec(dllimport)
# else
# define DLL_EXP
# endif
#endif

#include <vcl.h>
#include <tchar.h>

DLL_EXP bool download(String url, UnicodeString FileName, bool& result,String last_version);
DLL_EXP int ori(String sVersion1, String sVersion2);

