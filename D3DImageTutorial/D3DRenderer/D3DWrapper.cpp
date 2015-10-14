#include "D3DRenderer.h" 
#include <vcclr.h>
using namespace System;
namespace D3DMesh 
{ 
  public ref class D3DWrapper 
  { 
  public: 
    IntPtr Initialize(IntPtr hwnd) 
    { 
      if (SUCCEEDED(::InitD3D((HWND) hwnd.ToPointer()))) 
        return IntPtr(g_pd3dSurface); 
      return IntPtr::Zero; 
    } 

    VOID InitGeometry() 
    { 
      ::InitGeometry(); 
    }
    VOID Render(int% width, int% height) 
    { 
      ::Render(); 
      width = SCREEN_WIDTH; 
      height = SCREEN_HEIGHT; 
    }
    VOID Cleanup() 
    { 
      ::Cleanup(); 
    } 
  };
}
