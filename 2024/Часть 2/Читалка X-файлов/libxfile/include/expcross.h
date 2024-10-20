/** @mainpage ОБЩАЯ ИНФОРМАЦИЯ
* @author Юрий Голобоков
* @section ВВЕДЕНИЕ
**/

#ifndef _EXPCROSS_H
/// Определение для исключения многократных добавлений заголовочного файла
/// через директиву include
#define _EXPCROSS_H

// Общие заголовочники
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined( _WIN32 )
  #define OS_WINDOWS
#elif defined(linux) || defined(__linux)
  #define OS_LINUX
#endif

//#if defined(REQUIRED_MUTEX_PRIMITIVES)

#ifdef OS_LINUX 
  #define DEFINE_MUTEX(x)  pthread_mutex_t x  
  #define INIT_MUTEX(x)    pthread_mutex_init(&x, NULL)
  #define DELETE_MUTEX(x)  pthread_mutex_destroy(&x)
  #define GET_MUTEX(x)     pthread_mutex_lock(&x)
  #define RELEASE_MUTEX(x) pthread_mutex_unlock(&x)
#elif defined(OS_WINDOWS)
  #define DEFINE_MUTEX(x)  CRITICAL_SECTION x
  #define INIT_MUTEX(x)    InitializeCriticalSectionAndSpinCount(&x,0x400)
  #define DELETE_MUTEX(x)  DeleteCriticalSection(&x)
  #define GET_MUTEX(x)     EnterCriticalSection(&x)
  #define RELEASE_MUTEX(x) LeaveCriticalSection(&x)
#endif

//#endif

//#if defined(REQUIRED_THREAD_PRIMITIVES)

#ifdef OS_LINUX

  #define DEFINE_THREAD(x)                  pthread_t x = (pthread_t) -1
  #define EXIT_THREAD(x)                    pthread_exit(NULL)
  #define SETSIGMASK_THREAD(x)              pthread_sigmask(SIG_SETMASK, &x, NULL);
  #define SET_DEFAULT_ATTRIBUTES_THREAD(x)  pthread_attr_t x; \
                                            pthread_attr_init(&x); \
                                            pthread_attr_setschedpolicy(&x,SCHED_RR); \
                                            pthread_attr_setdetachstate(&x,PTHREAD_CREATE_DETACHED)
  #define START_THREAD(thread, attr, func)  pthread_create( &thread, &attr, func, NULL )

#elif defined(OS_WINDOWS)  
  #define DEFINE_THREAD(x)                  HANDLE x = (HANDLE)-1
  #define EXIT_THREAD(x)                    CloseHandle(x)
  
  #define SET_DEFAULT_ATTRIBUTES_THREAD(x)  DWORD x
  #define START_THREAD(thread, attr, func)  thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, NULL, 0, &attr)
  #define SETSIGMASK_THREAD(x)
#endif

//#endif
  
// Windows
#if defined(OS_WINDOWS)
  // Подавляет вывод сообщений о "небезопасных функциям"
  #pragma warning(disable:4996)
//  #include <io.h>
//  #include <winsock2.h>
  
  // Переопределяем функции
  #define fsync _commit
  #define snprintf _snprintf    
#endif


#endif
