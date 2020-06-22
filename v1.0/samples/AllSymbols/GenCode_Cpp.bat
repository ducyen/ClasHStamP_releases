echo off

SET OUTPUT=Cpp
SET PACKAGE=Model
SET LANGUAGE=cpp
SET SYNTAX=%TOOL_DIR%\Syntax_Hpp.csv
java -jar %CODE_GEN%

SET PACKAGE=Interfaces
SET LANGUAGE=cpp
SET SYNTAX=%TOOL_DIR%\Syntax_Hpp.csv
java -jar %CODE_GEN%

pause
