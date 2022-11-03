g++ -o bin\test.exe ^
-I incldue ^
source\cpp_utils.cpp ^
test.cpp && bin\test.exe
echo %errorlevel%
pause