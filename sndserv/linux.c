// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: linux.c,v 1.3 1997/01/26 07:45:01 b1 Exp $
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
//
// $Log: linux.c,v $
// Revision 1.3  1997/01/26 07:45:01  b1
// 2nd formatting run, fixed a few warnings as well.
//
// Revision 1.2  1997/01/21 19:00:01  b1
// First formatting run:
//  using Emacs cc-mode.el indentation for C++ now.
//
// Revision 1.1  1997/01/19 17:22:45  b1
// Initial check in DOOM sources as of Jan. 10th, 1997
//
//
// DESCRIPTION:
//	UNIX, soundserver for Linux i386.
//
//-----------------------------------------------------------------------------

static const char rcsid[] = "$Id: linux.c,v 1.3 1997/01/26 07:45:01 b1 Exp $";


#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define SAMPLE_RATE 11025
#define FRAMES_PER_BUFFER 256

static PaStream *stream;

void myioctl(int command, int *arg) {
}

void I_InitMusic(void) {
}

void I_InitSound(int samplerate, int samplesize) {
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        exit(1);
    }

    err = Pa_OpenDefaultStream(
        &stream,
        0, // input channels
        2, // output channels
        paInt16, // 16-bit integer format
        SAMPLE_RATE,
        FRAMES_PER_BUFFER,
        NULL, // callback function
        NULL  // user data
    );

    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        exit(1);
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        exit(1);
    }
}

void I_SubmitOutputBuffer(void *samples, int samplecount) {
    PaError err;

    err = Pa_WriteStream(stream, samples, samplecount);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    }
}

void I_ShutdownSound(void) {
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
}

void I_ShutdownMusic(void) {
}
