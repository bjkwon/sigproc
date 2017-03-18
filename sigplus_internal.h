#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <audfret.h>
//#include "audstr.h"

#include "sigproc.h"

#define MAX_24BIT		(double)0x007fffff
#define iMAX_24BIT		0x007fffff
#define MAX_16BIT		(double)0x7fff
#define iMAX_16BIT		0x7fff

extern double playblock;

int remez(double h[], int numtaps, int numband, double bands[], double des[], double weight[], int type);


//from ellf.c
extern "C" int design_iir(double *num, double *den, int fs, int kind, int type, int n, double *freqs, double dbr /*rippledB*/, double dbd /*stopEdgeFreqORattenDB*/);
