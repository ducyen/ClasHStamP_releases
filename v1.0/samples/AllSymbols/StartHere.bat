echo off
set PATH=C:\Program Files\astah-professional\jre\bin;%PATH%;

SET TOOL_DIR=..\..\release
SET CODE_GEN=%TOOL_DIR%\ClasHStamP.jar
SET PROJECT=Design.asta
SET EXT_CODE_OPT=y

rem SET ENCODING=Shift-JIS
rem SET JAVA_TOOL_OPTIONS=-Dfile.encoding=Shift_JIS
SET ENCODING=UTF-8
SET JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8

cmd -c
