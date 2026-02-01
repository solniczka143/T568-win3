#include "AboutDlg.h"
#include "Globals.h"
#include "MainWnd.h"
#include "Resource.h"

/* Main window class and title */
static const char MainWndClass[] = "T568 - Guess!";

short y = 130;
short a = 18;

/* A or B type*/
char AB = 'A';

/* Window procedure for our main window */
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  static int currentBitmap[8] = {0,1,2,3,4,5,6,7};
  static int i;
  static short y = 20;
  HDC hDC, hMemDC; 
  PAINTSTRUCT PtStr;
  switch (msg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          return 0;
        }

        case ID_FILE_EXIT:
        {
          DestroyWindow(hWnd);
          return 0;
        }

        /* Show how type A or B should look like*/
        case ID_HELP_T568A:
        {
          /* seting up bitmaps for type A*/
          currentBitmap[0] = 6; 
          currentBitmap[1] = 2;
          currentBitmap[2] = 7;
          currentBitmap[3] = 0;
          currentBitmap[4] = 4;
          currentBitmap[5] = 3;
          currentBitmap[6] = 5;
          currentBitmap[7] = 1;

          hCurrentBitmaps[0] = hBitmaps[6];
          hCurrentBitmaps[1] = hBitmaps[2];
          hCurrentBitmaps[2] = hBitmaps[7];
          hCurrentBitmaps[3] = hBitmaps[0];
          hCurrentBitmaps[4] = hBitmaps[4];
          hCurrentBitmaps[5] = hBitmaps[3];
          hCurrentBitmaps[6] = hBitmaps[5];
          hCurrentBitmaps[7] = hBitmaps[1];
	        break;
        }

        case ID_HELP_T568B:
        {
          /* seting up bitmaps for type B*/
          currentBitmap[0] = 7; 
          currentBitmap[1] = 3;
          currentBitmap[2] = 6;
          currentBitmap[3] = 0;
          currentBitmap[4] = 4;
          currentBitmap[5] = 2;
          currentBitmap[6] = 5;
          currentBitmap[7] = 1;

          hCurrentBitmaps[0] = hBitmaps[7];
          hCurrentBitmaps[1] = hBitmaps[3];
          hCurrentBitmaps[2] = hBitmaps[6];
          hCurrentBitmaps[3] = hBitmaps[0];
          hCurrentBitmaps[4] = hBitmaps[4];
          hCurrentBitmaps[5] = hBitmaps[2];
          hCurrentBitmaps[6] = hBitmaps[5];
          hCurrentBitmaps[7] = hBitmaps[1];
	        break;
        }

        case ID_BUTTON1:
        {
        /* changing bitmaps in cycle */
          currentBitmap[0] = (currentBitmap[0] + 1) % 8;
          hCurrentBitmaps[0] = hBitmaps[currentBitmap[0]];
          break;
        }

        case ID_BUTTON2:
        {
          currentBitmap[1] = (currentBitmap[1] + 1) % 8;
          hCurrentBitmaps[1] = hBitmaps[currentBitmap[1]];
          break;
        }

        case ID_BUTTON3:
        {
          currentBitmap[2] = (currentBitmap[2] + 1) % 8;
          hCurrentBitmaps[2] = hBitmaps[currentBitmap[2]];
          break;
        }

        case ID_BUTTON4:
        {
          currentBitmap[3] = (currentBitmap[3] + 1) % 8;
          hCurrentBitmaps[3] = hBitmaps[currentBitmap[3]];
          break;
        }

        case ID_BUTTON5:
        {
          currentBitmap[4] = (currentBitmap[4] + 1) % 8;
          hCurrentBitmaps[4] = hBitmaps[currentBitmap[4]];
          break;
        }

        case ID_BUTTON6:
        {
          currentBitmap[5] = (currentBitmap[5] + 1) % 8;
          hCurrentBitmaps[5] = hBitmaps[currentBitmap[5]];
          break;
        }

        case ID_BUTTON7:
        {
          currentBitmap[6] = (currentBitmap[6] + 1) % 8;
          hCurrentBitmaps[6] = hBitmaps[currentBitmap[6]];
          break;
        }

        case ID_BUTTON8:
        {
          currentBitmap[7] = (currentBitmap[7] + 1) % 8;
          hCurrentBitmaps[7] = hBitmaps[currentBitmap[7]];    
          break;
        }

        case ID_BUTTON9:
        {
          /* checking for Type A or B*/
          if((AB == 'A')&&(currentBitmap[0] == 6 && currentBitmap[1] == 2 && currentBitmap[2] == 7 && currentBitmap[3] == 0 && currentBitmap[4] == 4 && currentBitmap[5] == 3 && currentBitmap[6] == 5 && currentBitmap[7] == 1)) MessageBox (hWnd, "Great! It's T568-A", "That's right!" ,MB_OK); 
          else if((AB == 'B')&&(currentBitmap[0] == 7 && currentBitmap[1] == 3 && currentBitmap[2] == 6 && currentBitmap[3] == 0 && currentBitmap[4] == 4 && currentBitmap[5] == 2 && currentBitmap[6] == 5 && currentBitmap[7] == 1)) MessageBox (hWnd, "Great! It's T568-B", "That's right!" ,MB_OK);
          else MessageBox (hWnd, "It's Wrong!", "OH NO!" ,MB_OK);
          /*changing types A<->B*/
          if(AB == 'A') AB = 'B';
          else if(AB == 'B') AB = 'A';
          break;
        }    
      }
      InvalidateRect(hWnd, NULL, TRUE);
      break;
    }

    case WM_GETMINMAXINFO:
    {
      /* Prevent our window from being sized too small */
      MINMAXINFO FAR* minMax = (MINMAXINFO FAR*)lParam;
      minMax->ptMinTrackSize.x = 220;
      minMax->ptMinTrackSize.y = 110;

      return 0;
    }

    /* Item from system menu has been invoked */
    case WM_SYSCOMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        /* Show "about" dialog on about system menu item */
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          return 0;
        }
        
      }
      break;
    }

    /* Drawing Bitmaps and text*/
    case WM_PAINT:
    {
      hDC = BeginPaint(hWnd, &PtStr);

      TextOut(hDC, 15, 60, "Type:", 5);

      if(AB == 'B') TextOut(hDC, 25, 80, "B", 1);
      if(AB == 'A') TextOut(hDC, 25, 80, "A", 1);


      hMemDC = CreateCompatibleDC(hDC);
     
      SelectObject(hMemDC, hCurrentBitmaps[0]);
      BitBlt(hDC,60,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[1]);
      BitBlt(hDC,86,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[2]);
      BitBlt(hDC,112,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[3]);
      BitBlt(hDC,138,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[4]);
      BitBlt(hDC,164,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[5]);
      BitBlt(hDC,190,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[6]);
      BitBlt(hDC,216,y,18,100,hMemDC,0,0,SRCCOPY);

      SelectObject(hMemDC, hCurrentBitmaps[7]);
      BitBlt(hDC,242,y,18,100,hMemDC,0,0,SRCCOPY);
                
      DeleteDC(hMemDC);
      EndPaint(hWnd, &PtStr);
      return 0;
    }

    case WM_DESTROY:
    {
      for(i = 0; i < 8; i++) {
                DeleteObject(hBitmaps[i]);
            }
                PostQuitMessage(0);
                return 0;
      PostQuitMessage(0);
      return 0;
    }
  }

  return DefWindowProc(hWnd, msg, wParam, lParam);
}

/* Register a class for our main window */
BOOL RegisterMainWindowClass()
{
  WNDCLASS wc;

  /* Class for our main window */
  wc.style         = 0;
  wc.lpfnWndProc   = &MainWndProc;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = 0;
  wc.hInstance     = g_hInstance;
  wc.hIcon         = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPICON));
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = GetStockObject (WHITE_BRUSH);
  //wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
  wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
  wc.lpszClassName = MainWndClass;

  return (RegisterClass(&wc)) ? TRUE : FALSE;
}

/* Create an instance of our main window */
HWND CreateMainWindow()
{
    /* Create instance of main window */
  HWND hWnd = CreateWindowEx(
  0, 
  MainWndClass, /*class name*/
  MainWndClass, /*Caption*/
  WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, /* Style */
  CW_USEDEFAULT, /* x position */
  CW_USEDEFAULT, /*y position*/
  320,  /* cx - size */
  200,  /* cy - size */
  NULL, /* parent window */
  NULL, /*Menu */
  g_hInstance, /*program instace */
  NULL); /*parameters */
  

  if (hWnd)
  {
    /* Add "about" to the system menu */
    HMENU hSysMenu = GetSystemMenu(hWnd, FALSE);
    InsertMenu(hSysMenu, 5, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
    InsertMenu(hSysMenu, 6, MF_BYPOSITION, ID_HELP_ABOUT, "About");
    /* Add butons*/
    CreateWindow("BUTTON", "1", WS_VISIBLE | WS_CHILD,60, y, a, a, hWnd, (HMENU)ID_BUTTON1, g_hInstance, NULL);
    CreateWindow("BUTTON", "2", WS_VISIBLE | WS_CHILD,86, y, a, a, hWnd, (HMENU)ID_BUTTON2, g_hInstance, NULL);
    CreateWindow("BUTTON", "3", WS_VISIBLE | WS_CHILD,112, y, a, a, hWnd, (HMENU)ID_BUTTON3, g_hInstance, NULL);
    CreateWindow("BUTTON", "4", WS_VISIBLE | WS_CHILD,138, y, a, a, hWnd, (HMENU)ID_BUTTON4, g_hInstance, NULL);
    CreateWindow("BUTTON", "5", WS_VISIBLE | WS_CHILD,164, y, a, a, hWnd, (HMENU)ID_BUTTON5, g_hInstance, NULL);
    CreateWindow("BUTTON", "6", WS_VISIBLE | WS_CHILD,190, y, a, a, hWnd, (HMENU)ID_BUTTON6, g_hInstance, NULL);
    CreateWindow("BUTTON", "7", WS_VISIBLE | WS_CHILD,216, y, a, a, hWnd, (HMENU)ID_BUTTON7, g_hInstance, NULL);
    CreateWindow("BUTTON", "8", WS_VISIBLE | WS_CHILD,242, y, a, a, hWnd, (HMENU)ID_BUTTON8, g_hInstance, NULL);
    CreateWindow("BUTTON", "Check", WS_VISIBLE | WS_CHILD,266, 70, 45, a, hWnd, (HMENU)ID_BUTTON9, g_hInstance, NULL);
  }

  return hWnd;
}
