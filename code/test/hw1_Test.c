#include "syscall.h"

main()
{
	int i;
	for(i=0; i<10; i++)
	{
		PrintInt(i);
		Sleep(2000000);	//ns
	}
}
