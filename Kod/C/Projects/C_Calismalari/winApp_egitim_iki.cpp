#include <windows.h>

/*	Declare Windows procedure	*/
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*	Make the class name into a global variable	*/
char szClassName[ ] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpszArgument,
		int nCmdShow)
{
	HWND hwnd;			/* This is the handle for our window */
	MSG messages;		/* Here messages to the application are saved */
	WNDCLASSEX wincl;	/* Data structure for the windowclass */

	/* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
//	wincl.lpfnWnProc = WindowProcedure;		/* This function is called by windows */
//	wincl.style = CS DBLCLKS;				/* Catch double-clicks */
//	wincl.cbSzie = sizeof (WNDCLASSEX);

	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;				/* No menu */
	wincl.cbClsExtra = 0;					/* No exstra bytes after the window class */
	wincl.cbWndExtra = 0 ;					/* structure or the window instance */
	/* Use Windows's default colour as the backgorund of the window */
	
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

	/* Register the window class, and if it fails the program */
	if (!RegisterClassEx (&wincl))
		return 0;
	
		/* The class is registered, let's create the program */
		hwnd = CreateWindowEx (
		0,										/* Extended possibilites for variation */
		szClassName,							/* Classname */
		"Code::Blocks Template Windows App", 	/* Title text */
		WS_OVERLAPPEDWINDOW,					/* default window */
		CW_USEDEFAULT,							/* Windows decides the position */
		CW_USEDEFAULT,							/* where the window ends up on the screen */
		544,									/* The programs width */
		375,									/* and height in pixels */
		HWND_DESKTOP,							/* The window is a child-window to desktop */
		NULL,									/* No menu */
		hThisInstance,							/* Program Instance handler */
		NULL									/* No Window Creation data */
	);
	
	/* Make the window visible on the screen */
	ShowWindow (hwnd, nCmdShow);
	
	/* Run the message loop. It will run untill GetMessage() returns 0 */
	while (GetMessage (&messages, NULL, 0,0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}
	
	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return messages.wParam;
}


/* This function is called by the Windows function DispatchMessage() */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lparam)
{
	switch (message)				/* handle the message */
	{
		case WM_DESTROY:
			PostQuitMessage (0);	/* send a WM_QUIT to the message queue */
			break;
//		default:
//			return DefWindowProc (hwnd, message, wParam, lParam);
	}

	return 0;
}
