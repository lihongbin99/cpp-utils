g++ -o bin\test.exe ^
-I include ^
source\parse_param.cpp ^
test.cpp && bin\test.exe -a 123 --A 456 -b 789 --B 012 -c "Hello World" --D "中文测试abc"
echo %errorlevel%
pause