using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Windows.Interop; // #10
using D3DMesh;                // #10

namespace WPFD3DViewer
{
  /// <summary>
  /// MainWindow.xaml の相互作用ロジック
  /// </summary>
  public partial class MainWindow : Window
  {
    private readonly D3DWrapper myD3DScene = new D3DWrapper();

    public MainWindow()
    {
      InitializeComponent();
    }

    private void StartDXRendering()
    {
      if( !myD3DImage.IsFrontBufferAvailable )
        return;

      IntPtr scene = myD3DScene.Initialize( new WindowInteropHelper( this ).Handle );
      myD3DScene.InitGeometry();
      myD3DImage.Lock();
      myD3DImage.SetBackBuffer( D3DResourceType.IDirect3DSurface9, scene );
      myD3DImage.Unlock();
      CompositionTarget.Rendering += new EventHandler( OnRendering );
    }

    private void StopDXRendering()
    {
      CompositionTarget.Rendering -= OnRendering;
      myD3DScene.Cleanup();
    }

    void OnRendering( object sender, EventArgs e )
    {
      if( !myD3DImage.IsFrontBufferAvailable )
        return;

      myD3DImage.Lock();
      int width = 0, height = 0;
      myD3DScene.Render( ref width, ref height );
      myD3DImage.AddDirtyRect( new Int32Rect( 0, 0, width, height ) );  // #10 書き込む範囲を決める
      myD3DImage.Unlock();
    }

    private void Window_Loaded( object sender, RoutedEventArgs e )
    {
      StartDXRendering();
    }

    private void myD3DImage_IsFrontBufferAvailableChanged(
      object sender, DependencyPropertyChangedEventArgs e )
    {
      if( myD3DImage.IsFrontBufferAvailable )
      {
        StartDXRendering();
      }
      else
      {
        StopDXRendering();
      }
    }
  }
}
