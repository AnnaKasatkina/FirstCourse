@echo off

if not "%1" == "" if not "%2" == "" (
    rem Создаем пустые файлы
    echo. > %1
    echo. > %2

    GrapgViz.exe %1 %2

    start "" "%1"
) else (
    echo Usage: %0 <file1> <file2>
    exit /b 1
)
