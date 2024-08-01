@echo off

REM Define the source file and the output executable
set SOURCE_FILE=main.cpp
set OUTPUT_FILE=chessdollplus.exe

REM Check if the source file exists
if not exist "%SOURCE_FILE%" (
    echo Source file %SOURCE_FILE% not found!
    exit /b 1
)

REM Compile the source file
g++ -o "%OUTPUT_FILE%" "%SOURCE_FILE%"

REM Check if the compilation was successful
if %errorlevel%==0 (
    echo Compilation successful. You can run the game with %OUTPUT_FILE%
) else (
    echo Compilation failed!
    exit /b 1
)
