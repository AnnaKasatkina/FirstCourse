@echo off
SETLOCAL

set MSBuildPath="C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe"

for /r %%i in (*.sln) do (
    echo %%i is building...
    %MSBuildPath% "%%i" -nologo -consoleLoggerParameters:ErrorsOnly -p:WarningLevel=4;Configuration=Debug -target:Rebuild
    IF ERRORLEVEL 1 (
        ECHO Result: failure
    ) ELSE (
        ECHO Result: success
        echo Running tests for %%i
        for /r %%j in (%%~dpi*.exe) do (
            "%%j" RunTest
            echo %ERRORLEVEL%
            IF ERRORLEVEL 1 (
                ECHO %%j tests were not passed
            ) ELSE (
                ECHO %%j tests were passed
            )
        )
    )
    echo.
)

ENDLOCAL 