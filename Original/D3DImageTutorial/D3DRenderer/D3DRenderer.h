#include <Windows.h> 
#include <mmsystem.h> 
#include <d3d9.h> 
#include <d3dx9.h> 
#pragma warning( disable : 4996 ) 
#include <strsafe.h> 
#pragma warning ( default : 4996 ) 

#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480 

extern LPDIRECT3DSURFACE9 g_pd3dSurface; 

#define DXERR_FILE_NOT_FOUND 0x88760389 

HRESULT InitD3D(HWND hWnd); 
HRESULT InitGeometry(); 
VOID Render(bool b_AutoRotation, bool b_WireframeMode); 
VOID Cleanup();
