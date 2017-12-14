@echo off 

set working_path=%cd%
Setlocal EnableDelayedExpansion


for /r %%i in (*) do (

	if not !cd!\ == %%~di%%~pi (
		cd /d %%~pi
	)
	if "%%~xi" == ".cpp" (
		echo file being compiled: %%i
		g++ %%i -o %%~ni
	)
	if "%%~xi" == ".c" (
		echo file being compiled: %%i
		gcc %%i -o %%~ni
	)
	if not !cd!\ == %%~di%%~pi (
		cd /d working_path
	)
	
)


echo All possible files have been compiled!
pause > nul