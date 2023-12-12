@echo off
chcp 65001
setlocal enabledelayedexpansion

:process_folder
for /D %%i in (*) do (
    set "project_path=!CD!\%%i"

    if exist !project_path!\Main.c (
        set "project_name=%%i"

        pushd !project_path! > nul

        if exist Tests.c (
            call :run_tests
            if %errorlevel% neq 0 (
                echo "Тесты не прошли для проекта !project_name!"
            ) else (
                echo "Тесты прошли успешно для проекта !project_name!"
            )
        ) else (
            echo "Отсутствует файл теста для проекта !project_name! Программа прекращает работу в данной подпапке."
        )

        popd > nul
    )

    if exist !project_path!\* (
        pushd !project_path! > nul
        call :process_folder
        popd > nul
    )
)
goto :eof

:run_tests
msbuild /t:build /p:Configuration=Release /p:MainFile=Tests.c > nul 2>&1
if not exist Tests.c (
    echo "Отсутствует файл теста. Программа прекращает выполнение тестов."
    exit /b 1
)
