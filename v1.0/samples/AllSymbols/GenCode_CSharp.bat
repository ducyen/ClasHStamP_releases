echo off

SET OUTPUT=CSharp
SET PACKAGE=Model
SET LANGUAGE=cs
SET SYNTAX=%TOOL_DIR%\Syntax_CSharp.csv
java -jar %CODE_GEN%

SET PACKAGE=Interfaces
SET LANGUAGE=cs
SET SYNTAX=%TOOL_DIR%\Syntax_CsIfc.csv
java -jar %CODE_GEN%

pause
