/*
 * libmowgli: A collection of useful routines for programming.
 * machine.h: Defines to discover what machine we're on easily
 *
 * Copyright (c) 2012 Patrick McFarland <pmcfarland@adterrasperaspera.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "mowgli.h"

/* Machine environment specific macros, mostly sourced from this URL:
 * http://sourceforge.net/apps/mediawiki/predef/
 *
 * Please note: Just because a compiler, CPU, or OS is listed in this file,
 * that doesn't mean that it is supported by Mowgli.
 */

#ifndef __MOWGLI_MACHINE_H__
#define __MOWGLI_MACHINE_H__

#if defined __clang__
#define MOWGLI_COMPILER_CLANG
#define MOWGLI_COMPILER clang
#elif defined __INTEL_COMPILER || defined __ICC || defined __ICL
#define MOWGLI_COMPILER_ICC
#define MOWGLI_COMPILER icc
#elif defined __CC_ARM
#define MOWGLI_COMPILER_ARM
#define MOWGLI_COMPILER arm
#elif defined __xlc__ || defined __xlC__
#define MOWGLI_COMPILER_IBM
#define MOWGLI_COMPILER ibm
#elif defined __SUNPRO_C || defined __SUNPRO_CC
#define MOWGLI_COMPILER_SUN
#define MOWGLI_COMPILER sun
#elif defined __GNUC__
#define MOWGLI_COMPILER_GCC
#define MOWGLI_COMPILER gcc
#elif defined _MSC_VER
#define MOWGLI_COMPILER_MSVC
#define MOWGLI_COMPILER msvc
#else
#define MOWGLI_COMPILER_UNKNOWN
#define MOWGLI_COMPILER unknown
#endif

#if defined __GNUC__
#define MOWGLI_COMPILER_GCC_COMPAT
#endif

#if defined __amd64__ || defined __amd64 || defined __x86_64__ || defined __x86_64 || defined _M_X64 || defined _M_AMD64
#define MOWGLI_CPU_X86_64
#define MOWGLI_CPU x86_64
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#elif defined __i386__ || defined __i386 || defined __IA32__ || defined _M_IX86 || defined __X86__ || defined _X86__ || defined __I86__
#define MOWGLI_CPU_X86
#define MOWGLI_CPU x86
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif

#if defined __arm__ || defined __TARGET_ARCH_ARM || defined _ARM
#if defined __thumb__ || defined __TARGET_ARCH_THUMB
#define MOWGLI_CPU_ARM_THUMB
#endif
#define MOWGLI_CPU_ARM
#define MOWGLI_CPU arm
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif

#if defined __hppa__ || defined __HPPA__ || defined __hppa
#if defined _PA_RISC2_0 || defined __HPPA20__ || defined __RISC2_0__
#define MOWGLI_CPU_HPPA20
#define MOWGLI_CPU hppa20
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#else
#define MOWGLI_CPU_HPPA10
#define MOWGLI_CPU hppa10
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif
#endif

#if defined __ia64__ || defined __IA64__ || defined _M_IA64 || defined __ia64 || defined __itanium__
#define MOWGLI_CPU_ITANIUM
#define MOWGLI_CPU itanium
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#endif

#if defined __mips__ || defined mips || defined __mips || defined __MIPS__
#if defined __mips64 || defined __mips64__
#define MOWGLI_CPU_MIPS64
#define MOWGLI_CPU mips64
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#else
#define MOWGLI_CPU_MIPS
#define MOWGLI_CPU mips
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif
#endif

#if defined __powerpc || defined __powerpc__ || defined __POWERPC__ || defined __ppc__ || defined _M_PPC
#if defined __ppc64__ || defined __PPC64__
#define MOWGLI_CPU_POWERPC64
#define MOWGLI_CPU powerpc64
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#else
#define MOWGLI_CPU_POWERPC
#define MOWGLI_CPU powerpc
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif
#endif

#if defined __sparc__ || defined __sparc
#if defined __sparcv9 || defined __sparc64 || defined __sparc64__
#define MOWGLI_CPU_SPARC64
#define MOWGLI_CPU sparc64
#define MOWGLI_CPU_BITS_64
#define MOWGLI_CPU_BITS 64
#else
#define MOWGLI_CPU_SPARC
#define MOWGLI_CPU sparc
#define MOWGLI_CPU_BITS_32
#define MOWGLI_CPU_BITS 32
#endif
#endif

#if defined __alpha || defined __alpha__ || defined _M_ALPHA
#define MOWGLI_CPU_ALPHA
#define MOWGLI_CPU alpha
#define MOWGLI_CPU_BITS 64
#define MOWGLI_CPU_BITS_64
#endif

#ifndef MOWGLI_CPU
#define MOWGLI_CPU_UNKNOWN
#define MOWGLI_CPU unknown
#endif

#ifndef MOWGLI_CPU_BITS
#if defined _LP64 || defined __LP64
#define MOWGLI_CPU_BITS 64
#define MOWGLI_CPU_BITS_64
#elif
#define MOWGLI_CPU_BITS 32
#define MOWGLI_CPU_BITS_32
#endif
#endif

#if defined __linux || defined __linux__
#define MOWGLI_OS_LINUX
#define MOWGLI_OS linux
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#endif

#if defined __APPLE__
#define MOWGLI_OS_OSX
#define MOWGLI_OS osx
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#define MOWGLI_OS_BSD_TYPE
#endif

#if defined __WINDOWS__ || defined _WIN32 || defined __WIN32__ || defined __TOS_WIN__
#if defined _WIN64
#define MOWGLI_OS_WIN64
#define MOWGLI_OS win64
#else
#define MOWGLI_OS_WIN32
#define MOWGLI_OS win32
#endif
#define MOWGLI_OS_WIN
#define MOWGLI_OS_THREADS_WIN
#define MOWGLI_OS_THREADS win
#define MOWGLI_OS_MUTEX_WIN
#define MOWGLI_OS_MUTEX win

#if defined __CYGWIN__
#define MOWGLI_OS_WIN_CYGWIN
#elif defined __MINGW32__
#define MOWGLI_OS_WIN_MINGW
#endif
#endif

#if defined __NetBSD__ || defined __OpenBSD__ || defined __FreeBSD__ || defined __bsdi__ || defined __DragonFly__ || defined BSD || defined _SYSTYPE_BSD
#define MOWGLI_OS_BSD
#define MOWGLI_OS bsd
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#define MOWGLI_OS_BSD_TYPE
#endif

#if defined __GNU__
#define MOWGLI_OS_HURD
#define MOWGLI_OS hurd
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#endif

#if defined sco || defined __sco
#define MOWGLI_OS_SCO
#define MOWGLI_OS sco
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#define MOWGLI_OS_UNIX_TYPE
#endif

#if defined sun || defined __sun
#define MOWGLI_OS_SOLARIS
#define MOWGLI_OS solaris
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#define MOWGLI_OS_UNIX_TYPE
#endif

#if defined __QNX__ || defined __QNXNTO__
#define MOWGLI_OS_QNX
#define MOWGLI_OS qnx
#define MOWGLI_OS_THREADS_QNX
#define MOWGLI_OS_THREADS qnx
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#endif

#ifndef MOWGLI_OS
#if defined __unix__ || __unix || unix
#define MOWGLI_OS_UNIX
#define MOWGLI_OS unix
#define MOWGLI_OS_THREADS_POSIX
#define MOWGLI_OS_THREADS posix
#define MOWGLI_OS_MUTEX_POSIX
#define MOWGLI_OS_MUTEX posix
#define MOWGLI_OS_UNIX_TYPE
#endif
#define MOWGLI_OS_UNKNOWN
#define MOWGLI_OS unknown
#warning OS unsupported/unknown
#endif

#ifndef MOWGLI_OS_THREADS
#define MOWGLI_OS_THREADS_NULL
#define MOWGLI_OS_THREADS null
#endif

#ifndef MOWGLI_OS_MUTEX
#define MOWGLI_OS_MUTEX_NULL
#define MOWGLI_OS_MUTEX null
#endif

#endif