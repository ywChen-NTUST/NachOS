// userkernel.h
//	Global variables for the Nachos kernel, for the assignment
//	supporting running user programs.
//
//	The kernel supporting user programs is a version of the 
//	basic multithreaded kernel.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef USERKERNEL_H  
#define USERKERNEL_H

#include "kernel.h"
#include "filesys.h"
#include "machine.h"
#include "synchdisk.h"
class SynchDisk;
class UserProgKernel : public ThreadedKernel {
  public:
    UserProgKernel(int argc, char **argv);
				// Interpret command line arguments
    ~UserProgKernel();		// deallocate the kernel

    void Initialize();		// initialize the kernel 

    void Run();			// do kernel stuff 

    void SelfTest();		// test whether kernel is working

	// hw4
    SynchDisk *vm_Disk;

// These are public for notational convenience.
    Machine *machine;
    FileSystem *fileSystem;

	// hw4
    bool debugUserProg;
	MemReplaceType memType;

#ifdef FILESYS
    SynchDisk *synchDisk;
#endif // FILESYS

  private:
    //bool debugUserProg;		// single step user program
	Thread* t[10];
	int	pri[10];	// user defined priority
	bool	setPri[10];	// set priority or not
	char*	execfile[10];
	int	execfileNum;

	int stoi(char* str);
};

#endif //USERKERNEL_H
