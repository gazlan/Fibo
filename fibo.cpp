/* ******************************************************************** **
** @@ Fibonacci Sequence
** @  Copyrt : Public Domain
** @  Author : Ed Beroset 1996 
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

// This program demonstrates how to calculate any arbitrary term
// of the Fibonacci sequence using phi (the golden number) and
// eighteenth century mathematician A. de Moivre's formula.
//
// written on Fri  04-05-1996  by Ed Beroset
// and released to the public domain by the author
//
// modified for SNIPPETS 01-Sep-1996 by Bob Stout

/* ******************************************************************** **
** uses pre-compiled headers
** ******************************************************************** */

#include "stdafx.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef NDEBUG
#pragma optimize("gsy",on)
#pragma comment(linker,"/FILEALIGN:512 /MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR /IGNORE:4078")
#endif 

/* ******************************************************************** **
** @@                   internal defines
** ******************************************************************** */

#define PHI          ((1.0 + sqrt(5.0)) / 2.0)  // the golden number 
#define INV_PHI      (1.0 / PHI)                // the golden ratio  

/* ******************************************************************** **
** @@                   internal prototypes
** ******************************************************************** */

/* ******************************************************************** **
** @@ external global variables
** ******************************************************************** */

/* ******************************************************************** **
** @@ static global variables
** ******************************************************************** */
                  
CWinApp     theApp;

/* ******************************************************************** **
** @@ real code
** ******************************************************************** */

/* ******************************************************************** **
** @@ static double FibonacciSequence()
** @  Copyrt : Public Domain
** @  Author : Ed Beroset 1996 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

static double FibonacciSequence(WORD wTerm)
{  
   const double   fFactor = 1.0 / sqrt(5.0);   // A handy constant

   // This is de Moivre's formula using phi, the golden number (defined
   // in snipmath.h), and as simplified by Donald Knuth

   return fFactor * pow(PHI,wTerm);
}

/* ******************************************************************** **
** @@ static void ShowHelp()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

static void ShowHelp()
{
   const char  pszCopyright[] = "-*-   FibonacciSequence   *   Copyright (c) gazlan@yandex.ru, 2012   -*-";
   const char  pszDescript [] = "FibonacciSequence calculator";
   const char  pszE_Mail   [] = "complains_n_suggestions direct to gazlan@yandex.ru";

   printf("%s\n\n",pszCopyright);
   printf("%s\n\n",pszDescript);
   printf("Usage: fibo.exe [output.txt]\n\n");
   printf("%s\n",pszE_Mail);
}

/* ******************************************************************** **
** @@ main()
** @  Copyrt : Public Domain
** @  Author : Ed Beroset 1996 
** @  Modify :
** @  Update :
** @  Notes  : 
** ******************************************************************** */

#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter
int _tmain(int argc,TCHAR* argv[],TCHAR* envp[])
{
   if (argc < 2)
   {
// Do Notjing !
//      ShowHelp();
//      return 0;
   }

   if (argc == 2 && ((!strcmp(argv[1],"?")) || (!strcmp(argv[1],"/?")) || (!strcmp(argv[1],"-?")) || (!stricmp(argv[1],"/h")) || (!stricmp(argv[1],"-h"))))
   {
      ShowHelp();
      return 0;
   }

   // initialize MFC and print and error on failure
   if (!AfxWinInit(::GetModuleHandle(NULL),NULL,::GetCommandLine(),0))
   {
      // Error !
      return -1;  // Fatal Error: MFC initialization failed
   }

   for (int ii = 1; ii < 48; ++ii)  // Limit of precision
   {
      double   fValue  = FibonacciSequence((WORD)ii);
      DWORD    dwValue = (DWORD)(fValue + 0.5);
      
      printf("%2d: %12lu\n",ii,dwValue);
   }

   return 0;
}
#pragma warning(pop)

/* ******************************************************************** **
**                End of File
** ******************************************************************** */
