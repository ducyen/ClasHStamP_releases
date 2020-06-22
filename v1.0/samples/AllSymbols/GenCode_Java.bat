echo off

SET OUTPUT=Java
SET PACKAGE=Model
SET LANGUAGE=java
SET SYNTAX=%TOOL_DIR%\Syntax_Java.csv
java -jar %CODE_GEN%

SET PACKAGE=Interfaces
SET LANGUAGE=java
SET SYNTAX=%TOOL_DIR%\Syntax_JvIfc.csv
java -jar %CODE_GEN%

pause
