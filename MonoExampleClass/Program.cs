using System;
using System.Runtime.InteropServices;
using System.IO.MemoryMappedFiles;

namespace TestMnnoDrawing
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("Hi, Testing the new system!");
			Draw.Create();
			//Draw.Swap ();
		}
	}

	public class Color
	{
		private byte R,G,B;
		public static Color fromRGB(int R, int G, int B)
		{
			Color ret = new Color ();
			ret.R = (byte)R;
			ret.G = (byte)G;
			ret.B = (byte)B;
			return ret;
		}
		public int Red()
		{
			return R;
		}
		public int Blue()
		{
			return B;
		}
		public int Green()
		{
			return G;
		}
	}
	static class Draw
	{
		/*IntPtr FInfo;
		long Screensize;
		IntPtr Map;
		IntPtr TempMap;
		*/
		[DllImport("libDrawing.so.1.0")]
		private static extern void Init();
		[DllImport("libDrawing.so.1.0")]
		private static extern int Width();
		[DllImport("libDrawing.so.1.0")]
		private static extern int Height();
		
		[DllImport("libDrawing.so.1.0")]
		private static extern void DrawPixel(int x, int y, byte r, byte g, byte b);
		public static void Create()
		{
			Init ();
			Console.WriteLine (Width() + " - " + Height());
			Color Yellow = Color.fromRGB (255, 255, 0);
			for (int i = 0; i < 400; i++) {
				for (int d = 0; d < 400; d++) {
					DrawPixel (i, d, (byte)Yellow.Red(), (byte)Yellow.Green(), (byte)Yellow.Blue());
				}
			}
		}
	}
}
