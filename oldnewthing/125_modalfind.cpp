#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include <commdlg.h>

HWND g_hwndFR;
TCHAR g_szFind[80];
FINDREPLACE g_fr = { sizeof(g_fr) };
UINT g_uMsgFindMsgString;
HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

void
OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild) {
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
    }
}

BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    return TRUE;
}

void
OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
}

void
OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    PaintContent(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

void
OnPrintClient(HWND hwnd, HDC hdc)
{
    PAINTSTRUCT ps;
    ps.hdc = hdc;
    GetClientRect(hwnd, &ps.rcPaint);
    ps.fErase = FALSE;
    PaintContent(hwnd, &ps);
}

void CreateFindDialogUIModally(HWND hwnd)
{
  if (!g_hwndFR) {
    g_uMsgFindMsgString = RegisterWindowMessage(FINDMSGSTRING);
    if (g_uMsgFindMsgString) {
      g_fr.hwndOwner = hwnd;
      g_fr.hInstance = g_hinst;
      g_fr.lpstrFindWhat = g_szFind;
      g_fr.wFindWhatLen = 80;
      g_hwndFR = FindText(&g_fr);
      if (g_hwndFR) {
        EnableWindow(hwnd, FALSE);
      }
    }
  }
}

void OnChar(HWND hwnd, TCHAR ch, int cRepeat)
{
  switch (ch) {
  case ' ': CreateFindDialogUIModally(hwnd); break;
  }
}

void OnFindReplace(HWND hwnd, FINDREPLACE *pfr)
{
  if (pfr->Flags & FR_DIALOGTERM) {
      EnableWindow(hwnd, TRUE);
      DestroyWindow(g_hwndFR);
      g_hwndFR = NULL;
  }
}

LRESULT CALLBACK
WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg) {
    HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
    HANDLE_MSG(hwnd, WM_SIZE, OnSize);
    HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
    case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
    HANDLE_MSG(hwnd, WM_CHAR, OnChar);

    default:
      if (uiMsg == g_uMsgFindMsgString && g_uMsgFindMsgString) {
        OnFindReplace(hwnd, (FINDREPLACE*)lParam);
      }
      break;
    }

    return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL
InitApp(void)
{
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_hinst;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("Scratch");

    if (!RegisterClass(&wc)) return FALSE;

    InitCommonControls();               /* In case we use a common control */

    return TRUE;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    MSG msg;
    HWND hwnd;

    g_hinst = hinst;

    if (!InitApp()) return 0;

    if (SUCCEEDED(CoInitialize(NULL))) {/* In case we use COM */

        hwnd = CreateWindow(
            TEXT("Scratch"),                /* Class Name */
            TEXT("Scratch"),                /* Title */
            WS_OVERLAPPEDWINDOW,            /* Style */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Size */
            NULL,                           /* Parent */
            NULL,                           /* No menu */
            hinst,                          /* Instance */
            0);                             /* No special parameters */

        ShowWindow(hwnd, nShowCmd);

        while (GetMessage(&msg, NULL, 0, 0)) {
            if (g_hwndFR && IsDialogMessage(g_hwndFR, &msg)) {
            } else {
              TranslateMessage(&msg);
              DispatchMessage(&msg);
            }
        }
        CoUninitialize();
    }

    return 0;
}

