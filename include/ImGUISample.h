#ifndef IMGUISAMPLE_H
#define IMGUISAMPLE_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#define IMGUITESTAPI __declspec(dllexport)

#include <d3d11.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <tchar.h>

#endif
