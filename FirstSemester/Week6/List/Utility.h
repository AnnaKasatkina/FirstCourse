#pragma once

typedef enum ErrorCode
{
    ok,
    outOfMemory
}ErrorCode;

char* getString(ErrorCode* const errorCode);