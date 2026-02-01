#include <windows.h>
#include "Globals.h"
#include "MainWnd.h"
#include "Resource.h"

/* Global instance handle */
HINSTANCE g_hInstance = NULL;

HBITMAP hBitmaps[8];
HBITMAP hCurrentBitmaps[8];

/* Our application entry point */
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  HWND hWnd;
  HACCEL hAccelerators;
  MSG msg;

  /* Assign global HINSTANCE */
  g_hInstance = hInstance;

  /* Register our main window class, or error */
  if (!hPrevInstance && !RegisterMainWindowClass())
  {
    MessageBox(NULL, "Error registering main window class.", "Error", MB_ICONHAND | MB_OK);
    return 0;
  }

  /* Create our main window, or error */
  if (!(hWnd = CreateMainWindow()))
  {
    MessageBox(NULL, "Error creating main window.", "Error", MB_ICONHAND | MB_OK);
    return 0;
  }

  /* Load accelerators */
  hAccelerators = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR));

  /* Load bitmaps */
  hBitmaps[0] = LoadBitmap(hInstance, "BLUE") ;
  hBitmaps[1] = LoadBitmap(hInstance, "BROWN") ;
  hBitmaps[2] = LoadBitmap(hInstance, "GREEN") ;
  hBitmaps[3] = LoadBitmap(hInstance, "ORANGE") ;
  hBitmaps[4] = LoadBitmap(hInstance, "WHITE_BLUE") ;
  hBitmaps[5] = LoadBitmap(hInstance, "WHITE_BROWN") ;
  hBitmaps[6] = LoadBitmap(hInstance, "WHITE_GREEN") ;
  hBitmaps[7] = LoadBitmap(hInstance, "WHITE_ORANGE") ;

  /* setup bitmaps */
  hCurrentBitmaps[0] = hBitmaps[0];
  hCurrentBitmaps[1] = hBitmaps[1];
  hCurrentBitmaps[2] = hBitmaps[2];
  hCurrentBitmaps[3] = hBitmaps[3];
  hCurrentBitmaps[4] = hBitmaps[4];
  hCurrentBitmaps[5] = hBitmaps[5];
  hCurrentBitmaps[6] = hBitmaps[6];
  hCurrentBitmaps[7] = hBitmaps[7];
  
  /* Show main window and force a paint */
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  /* Main message loop */
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    if (!TranslateAccelerator(hWnd, hAccelerators, &msg))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return (int)msg.wParam;
}
