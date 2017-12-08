#include<windows.h>
#include<stdlib.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (msg == WM_LBUTTONUP) {
		MessageBox(hwnd, TEXT("終わるにゃん"), TEXT("Kitty"), MB_ICONINFORMATION);
		exit(0);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = TEXT("MENUID");
	winc.lpszClassName = TEXT("VIEWERMASTER");

	if (!RegisterClass(&winc)) return 0;

	//ウィンドウ作成
	hwnd = CreateWindow(
		TEXT("ViewerMaster"),
		TEXT("ViewerMaster"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL
	);

	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg, NULL, 0, 0);
		DispatchMessage(&msg);
	}
	return 0;
}