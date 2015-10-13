#include "D3DRenderer.h" 
#include <vcclr.h> 

using namespace System; 

namespace WPFD3DViewer 
{ 
  public ref class D3DWrapper 
  { 
  private:
	  bool _rotation;
	  bool _wireframe;

  public: 
	D3DWrapper()
	{
		_rotation = true;
		_wireframe = false;
	}
	property bool AutoRotate
	{
		bool get() {return _rotation;}
		void set(bool value) { _rotation = value;}
	}
	property bool RenderWireframe
	{
		bool get() {return _wireframe;}
		void set(bool value) { _wireframe = value;}
	}

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
      ::Render(_rotation, _wireframe); 
      width = SCREEN_WIDTH; 
      height = SCREEN_HEIGHT; 
    }

    VOID Cleanup() 
    { 
      ::Cleanup(); 
    } 
  }; 
} 
