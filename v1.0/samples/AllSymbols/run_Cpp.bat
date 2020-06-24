@echo off
rem Batch file to run a sample of Astah API on Windows

setlocal

SET OUTPUT=Cpp

SET PACKAGE=Model
SET LANGUAGE=cpp
SET SYNTAX=%TOOL_DIR%\Syntax_Hpp.csv
java %JAVA_OPTS% stm.TMain %1 %2
IF ERRORLEVEL 2 goto noJavaw

SET PACKAGE=Interfaces
SET LANGUAGE=cpp
SET SYNTAX=%TOOL_DIR%\Syntax_Hpp.csv
java %JAVA_OPTS% stm.TMain %1 %2
IF ERRORLEVEL 2 goto noJavaw

pause
goto end

:noJavaw
echo.
echo Failed to run java.
echo Java runtime environment is required to run Astah.
echo Please read README.txt in %ASTAH_HOME%
echo and setup Java environment at first.
echo.
echo ASTAH tries to run javaw. It should be in PATH system environment variable.
echo.
echo If you would like to run java in your specified folder, you can edit astah.bat(astah-std.bat,astah-pro.bat)
echo in %ASTAH_HOME%
echo like followings and set your JAVA_HOME.
echo     before:
echo       rem set JAVA_HOME=C:\jdk1.7.0_45
echo       rem set PATH=%JAVA_HOME%\bin;%PATH%
echo     after:
echo       set JAVA_HOME=C:\jdk1.7.0_45
echo       set PATH=%JAVA_HOME%\bin;%PATH%
echo.
echo.
pause
goto end

:end

endlocal
