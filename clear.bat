@echo off 


for /r %%i in (*.exe) do (
	echo deleting: %%i
	del %%i
)

echo Finished clearing all files!

pause > nul