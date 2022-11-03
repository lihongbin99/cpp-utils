g++ -o bin\test.exe ^
-I ..\cpp-utils\include ^
-I ..\parse-param\include ^
-I include ^
..\cpp-utils\source\cpp_utils.cpp ^
..\parse-param\source\parse_param.cpp ^
source\parse_ini.cpp ^
test.cpp && bin\test.exe -conf test.ini

echo %errorlevel%

pause