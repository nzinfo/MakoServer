/*
 *     ____             _________                __                _     
 *    / __ \___  ____ _/ /_  __(_)___ ___  ___  / /   ____  ____ _(_)____
 *   / /_/ / _ \/ __ `/ / / / / / __ `__ \/ _ \/ /   / __ \/ __ `/ / ___/
 *  / _, _/  __/ /_/ / / / / / / / / / / /  __/ /___/ /_/ / /_/ / / /__  
 * /_/ |_|\___/\__,_/_/ /_/ /_/_/ /_/ /_/\___/_____/\____/\__, /_/\___/  
 *                                                       /____/          
 *
 *                             Mako Server
 ****************************************************************************
 *            PROGRAM MODULE
 *
 *   $Id: MakoMain.c 3333 2014-05-02 00:10:55Z wini $
 *
 *   COPYRIGHT:  Real Time Logic LLC, 2012 - 2014
 *
 *   This software is copyrighted by and is the sole property of Real
 *   Time Logic LLC.  All rights, title, ownership, or other interests in
 *   the software remain the property of Real Time Logic LLC.  This
 *   software may only be used in accordance with the terms and
 *   conditions stipulated in the corresponding license agreement under
 *   which the software has been supplied.  Any unauthorized use,
 *   duplication, transmission, distribution, or disclosure of this
 *   software is expressly forbidden.
 *                                                                        
 *   This Copyright notice may not be removed or modified without prior
 *   written consent of Real Time Logic LLC.
 *                                                                         
 *   Real Time Logic LLC. reserves the right to modify this software
 *   without notice.
 *
 *               http://realtimelogic.com
 ****************************************************************************
 *
 */

#include "mako.h"

/* Version info */
#include "MakoVer.h"

#define MAKOEXNAME ""

#ifndef MAKO_VNAME
#define MAKO_VNAME      "Mako Server" MAKOEXNAME   ". Version " MAKO_VER
#endif
#ifndef MAKO_CPR
#define MAKO_CPR "Copyright (c) 2014 Real Time Logic.  All rights reserved."
#endif

/* The Mako Server can optionally use an embedded version of
 * mako.zip. The embedded ZIP file is a smaller version of mako.zip
 * and includes just enough code to open the server listening ports
 * and start LSP apps from command line params. This ZIP file is built
 * and converted to a C code array by the "BuildInternalZip.sh"
 * script. Note: The Mako Server will abort at startup if this macro
 * is not defined and if it is unable to open the external mako.zip.
 */
#define USE_EMBEDDED_ZIP


/* The Mako Server uses a few operating system depended functions for
 * Linux,Mac, QNX, and Windows. Defining this macro
 * makes it possible to compile the Mako Server for other
 * platforms. If you enable this macro, search below for CUSTOM_PLAT
 * and implement the missing functions.
*/
/* #define CUSTOM_PLAT */


/* Use the forkpty library on Linux. */
#ifndef CUSTOM_PLAT
#define USE_FORKPTY
#endif

/* If not using: https://realtimelogic.info/amalgamator/ */
#ifndef USE_AMALGAMATED_BAS
#include "../../../xrc/lua/lxrc.h"
#include <DiskIo.h>
#include <ZipIo.h>
#include "../../../xrc/misc/NetIo.h"
#include <BaTimer.h>
#include <balua.h>
#include <HttpTrace.h>
#include <HttpCmdThreadPool.h>
#include <HttpResRdr.h>
#include <IoIntfZipReader.h>
#include <lualib.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef CUSTOM_PLAT

/* Include custom header files */

#else
#ifdef _WIN32
#pragma warning(disable : 4996)
#include "Windows/servutil.h"
#include <direct.h>
#define xgetcwd _getcwd
#else
#include <pwd.h>
#include <syslog.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#define xgetcwd getcwd
#endif
#endif


typedef struct
{
   U32 trackerNodes,maxlogin;
   BaTime bantime;
} ConfigParams;
ConfigParams* cfgParams;

int daemonMode=FALSE;

#ifdef USE_EMBEDDED_ZIP
extern ZipReader* getLspZipReader(void); /* ../obj/debug|release/LspZip.c */
#endif

/* xrc/sql/ */
#ifdef MAKOEX
#define luaopen_SQL luaopen_luasql_ittiadb
extern int luaopen_luasql_ittiadb(lua_State *L);
#else
#define luaopen_SQL luaopen_luasql_sqlite3
extern int luaopen_luasql_sqlite3(lua_State *L);
#endif
#ifdef BAS_LOADED
void luaopen_ba_redirector(lua_State *L);
#endif

/* Global pointer to dispatcher declared on 'main' stack */
static SoDisp* dispatcher;
static lua_State* L; /* pointer to the Lua virtual machine */
static IoIntfZipReader* makoZipReader; /* When using the ZIP file */


static FILE* logFp; /* Log file */

/* Change log file location/name */
static int lSetLogFile(lua_State *L)
{
   const char* name = luaL_checkstring(L,1);
   FILE* fp = fopen(name, "wb");
   if(fp)
   {
      if(logFp) fclose(logFp);
      logFp=fp;
      lua_pushboolean(L, TRUE);
   }
   else
      lua_pushboolean(L, FALSE);
   return 1;
}

#ifndef va_copy
#define va_copy(d,s) ((d) = (s))
#endif

void
makovprintf(int isErr,const char* fmt, va_list argList)
{
   va_list xList;
   if(daemonMode || logFp)
   {
#if !defined(_WIN32) && !defined(CUSTOM_PLAT)
      if(isErr)
      {
         va_copy(xList, argList);
         vsyslog(LOG_CRIT, fmt, xList);
         va_end(xList);
      }
#endif
      if(!logFp)
      {
         logFp=fopen("mako.log","wb+");
         if(!logFp)
         {
            char* tmp=getenv("TMP");
            if(!tmp)
               tmp=getenv("TEMP");
            if(tmp)
            {
               char* ptr=malloc(strlen(tmp)+10);
               if(ptr)
               {
                  sprintf(ptr,"%s/mako.log",tmp);
                  logFp=fopen(ptr,"wb+");
                  free(ptr);
               }
            }
         }
         if(!logFp) return;
      }
      if( ! daemonMode )
      {
         va_copy(xList, argList);
         vfprintf(logFp,fmt,xList);
         va_end(xList);
         vfprintf(stderr,fmt,argList);
      }
      else
         vfprintf(logFp,fmt,argList);
      fflush(logFp);
   }
   else
      vfprintf(stderr,fmt,argList);
}


void
makoprintf(int isErr,const char* fmt, ...)
{
   va_list varg;
   va_start(varg, fmt);
   makovprintf(isErr, fmt, varg);
   va_end(varg); 
}


void
errQuit(const char* fmt, ...)
{
   va_list varg;
   va_start(varg, fmt);
   makovprintf(TRUE, fmt, varg);
   va_end(varg);
   HttpTrace_flush();
   if(logFp) fclose(logFp);
   exit(1);
}


static void
serverErrHandler(BaFatalErrorCodes ecode1,
                 unsigned int ecode2,
                 const char* file,
                 int line)
{
   sendFatalError("FE",ecode1,ecode2,file,line);
   errQuit("Fatal err: %d:%d, %s %d\n",ecode1,ecode2,file,line);
}


static void
writeHttpTrace(char* buf, int bufLen)
{
   buf[bufLen]=0; /* Safe. See documentation. */
   makoprintf(FALSE,"%s",buf);
}


void
setDispExit(void)
{
   SoDisp_setExit(dispatcher);
}


static int
findFlag(int argc, char** argv, const char flag, const char** data)
{
   int i;
   for(i = 1; i < argc ; i++)
   {
      char* ptr = argv[i];
      if(*ptr == '-' && ptr[1] == flag && !ptr[2])
      {
         if(data)
            *data = ((i+1) < argc) ? argv[i+1] : NULL;
         return TRUE;
      }
   }
   if(data)
      *data = NULL;
   return FALSE;
}

#ifdef CUSTOM_PLAT

/* The "get current directory" function is used when searching for the
 * Mako config file. This function is not required and can return NULL.
 *
 * In addition to the optional command line parameter "-c", the Mako
 * Server also looks for the config file in the directory returned
 * by function findExecPath.
 */
static char*
xgetcwd(char *buf, size_t size)
{
   return 0;
}


/* This function should return the path to the directory where
 * mako.zip is stored. The buffer must be dynamically allocated since
 * the caller frees the memory by calling baFree. This function must
 * be implemented if the macro USE_EMBEDDED_ZIP is undefined.
 */
static char*
findExecPath(const char* argv0)
{
   /* The following example code shows how you could potentially use
    * xgetcwd to return the path, assuming that the home directory is
    * where the Mako ZIP file is stored.
    */
   char* buf=baMalloc(1000);
   if(buf)
      return xgetcwd(buf,1000);
   return 0;
}

/* The following functions are not required and are defined to do nothing. */

/* Disable signals on Linux */
#define initUnix()


/* Enter Linux daemon mode */
#define setLinuxDaemonMode()

/* Set Linux user */
#define setUser(argc, argv)

/* Install a CTRL-C handler */
#define setCtrlCHandler()

#else  /* CUSTOM_PLAT */

/******************************** WIN32 **********************************/
#ifdef _WIN32
#define BA_WIN32
static int
pxexit(int status, int pause)
{
   if(pause)
   {
      fprintf(stderr,"\nPress <Enter> to continue.\n");
      getchar();
   }
   exit(status);
}


static char*
findExecPath(const char* argv0)
{
   char buf[2048];
   (void)argv0;
   if(GetModuleFileName(NULL, buf, sizeof(buf)))
   {
      char* ptr=strrchr(buf,'\\');
      if(ptr)
         ptr[0]=0;
      else
         buf[0]=0;
      return baStrdup(buf);
   }
   return NULL;
}


static BOOL WINAPI
sigTerm(DWORD x)
{
   makoprintf(FALSE,"\nExiting...\n");
   setDispExit();
   while(dispatcher) Sleep(100); /* Ref-wait */
   return FALSE;
}


static void
setCtrlCHandler(void)
{
   SetConsoleCtrlHandler(sigTerm, TRUE);
}
#define initUnix()
#define setLinuxDaemonMode()
#define setUser(argc, argv)

/******************************** LINUX **********************************/
#else /* #ifdef _WIN32 */

#ifdef _OSX_
#include <mach-o/dyld.h>
static char*
findExecPath(const char* argv0)
{
   char path[2048];
   uint32_t size = sizeof(path);
   (void)argv0;
   if ( ! _NSGetExecutablePath(path, &size) )
   {
      char* ptr=strrchr(path,'/');
      if(ptr)
         ptr[0]=0;
      else
         path[0]=0;
      ptr=baStrdup(path);
      if(ptr && realpath(ptr, path))
      {
         free(ptr);
         return baStrdup(path);
      }
      return ptr;
   }
   return NULL;
}
#else
static char*
findExecPath(const char* argv0)
{
   char* ptr;
   char buf[2048];
   ssize_t size = readlink("/proc/self/exe", buf, sizeof(buf));
   if(size < 0)
   {
      if( (size = readlink("/proc/curproc/file", buf, sizeof(buf))) < 0)
      {
         if( (size = readlink("/proc/self/path/a.out", buf, sizeof(buf))) < 0)
         {
            struct stat statBuf;
            if(argv0 && ! stat(argv0, &statBuf) && S_ISREG(statBuf.st_mode) &&
               xgetcwd(buf, sizeof(buf)))
            {
               strcat(buf,"/");
               strcat(buf,argv0);
               size=1;
            }
            else
            {
               char* name;
               char* path=getenv("PATH");
               while(path)
               {
                  int len;
                  ptr=strchr(path,':');
                  if(!ptr)
                     ptr=path+strlen(path);
                  len = ptr-path;
                  name=malloc(len+10);
                  if(!name)
                     return 0;
                  strncpy(name, path, len);
                  name[len]=0;
                  if(name[len-1] != '/')
                     strcat(name,"/");
                  strcat(name,"mako.zip");
                  if( ! stat(name, &statBuf) )
                  {
                     ptr=strrchr(name,'/');
                     *ptr=0;
                     return name;
                  }
                  path=ptr+1;
                  if( ! *path )
                     return 0;
               }
            }
         }
      }
   }
   if(size > 0)
   {
      ptr=strrchr(buf,'/');
      if(ptr)
         ptr[0]=0;
      else
         buf[0]=0;
      return baStrdup(buf);
   }
   return 0;
}
#endif

static void
sigTerm(int x)
{
   (void)x;
   static int oneshot=FALSE;
   if(oneshot)
   {
      makoprintf(FALSE,"\nGot SIGTERM again; aborting...\n");
      HttpTrace_flush();
      if(logFp) fclose(logFp);
      abort();
   }
   oneshot=TRUE;
   makoprintf(FALSE,"\nGot SIGTERM; exiting...\n");
   setDispExit();
}
static void
setCtrlCHandler(void)
{
   signal(SIGINT, sigTerm);
   signal(SIGTERM, sigTerm);
}

static void
cfignoreSignal(int sig, const char* signame)
{
   struct sigaction sa;
   sa.sa_handler = SIG_IGN;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = 0;
   if (sigaction(sig, &sa, NULL) < 0)
      errQuit("can't ignore %s.\n", signame);
}
#define ignoreSignal(x) cfignoreSignal((int)(x), #x)
static void
cfblockSignal(int sig, const char* signame)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, sig);
    if (sigprocmask(SIG_BLOCK, (const sigset_t*) &set, NULL) < 0)
       errQuit("can't block %s - %s.\n", signame,strerror(errno));
}
#define blockSignal(x) cfblockSignal((int)(x), #x)
static void
initUnix(void)
{
    ignoreSignal(SIGHUP);
    ignoreSignal(SIGTTOU);
    ignoreSignal(SIGTTIN);
    ignoreSignal(SIGTSTP);
    ignoreSignal(SIGPIPE);
    blockSignal(SIGUSR1);
    blockSignal(SIGUSR2);
    ignoreSignal(SIGXFSZ);
}

static void
setLinuxDaemonMode(void)
{
   int fd0, fd1, fd2;
   pid_t pid;

   /*
    * Clear file creation mask.
    */
   umask(0);

   /*
    * Become a session leader to lose controlling TTY.
    */
   if((pid = fork()) < 0)
   {
      errQuit("%s: can't fork\n", APPNAME);
   }
   else if(pid != 0) /* parent */
      exit(0);
   setsid();

   if((pid = fork()) < 0)
      errQuit("%s: can't fork\n", APPNAME);
   else if (pid != 0) /* parent */
      exit(0);

   /*
   ** Attach file descriptors 0, 1, and 2 to /dev/null.
   ** Note that these do not have cloexec set.
   ** The idea is that both parent and child processes that write to
   ** stdout/stderr will gracefully do nothing.
   **/
   close(0);
   close(1);
   close(2);
   fd0 = open("/dev/null", O_RDWR);
   fd1 = dup(0);
   fd2 = dup(0);

   /*
    * Initialize the log file.
    */
   openlog(APPNAME, LOG_CONS|LOG_PID, LOG_DAEMON);
   if (fd0 != 0 || fd1 != 1 || fd2 != 2)
   {
      errQuit("unexpected file descriptors %d %d %d\n",fd0, fd1, fd2);
   }
   syslog(LOG_INFO, "%s: daemon started...", APPNAME);
}


static void
setUser(int argc, char** argv)
{
   const char* userName;
   findFlag(argc, argv, 'u', &userName);
   if(userName)
   {
      if(getuid()==0 && getgid()==0)
      {
         struct passwd* pwd;
         makoprintf(FALSE,"Setting user to '%s'\n", userName);
         pwd = getpwnam(userName);
         if(pwd)
         {
            if(setgid(pwd->pw_gid) || setuid(pwd->pw_uid))
            {
               errQuit("Cannot set user and/or group ID to %s.\n",userName);
            }
            else
               return; /* success */
         }
         else
            errQuit("Cannot find user %s.\n",userName);
      }
      else
      {
         makoprintf(TRUE,
                    "Cannot use command line option: -u %s. "
                    "You are not root.\n", userName);
      }
   }
}

#endif /* #ifdef _WIN32 */
/***************************** END WIN/LINUX *******************************/
#endif /* #ifdef CUSTOM_PLAT */


/* Run the Lua 'onunload' handlers for all loaded apps when mako exits.
   onunload is an optional function applications loaded by mako can
   use if the applications require graceful termination such as
   sending a socket close message to peers.
 */
static void
onunload(void)
{
   /* Run the 'onunload' function in the .config Lua script, which in
    * turn runs the optional onunload for all loaded apps.
    */
   lua_getglobal(L,"onunload");
   if(lua_isfunction(L, -1))
   {
      if(lua_pcall(L, 0, 1, 0))
      {
         makoprintf(TRUE,"Error in 'onunload': %s\n",
                    lua_isstring(L,-1) ? lua_tostring(L, -1) : "?");
      }
   }
}

static int
loadConfigData(lua_State* L)
{
   U16 val;
   HttpServerConfig* cfg = (HttpServerConfig*)lua_touserdata(L,1);
   int status = luaL_loadfile(L, (const char*)lua_touserdata(L,2));
   const char** paramPtr = lua_touserdata(L,3);
   if (status != 0 && status != LUA_ERRFILE)
      lua_error(L);
   else
      lua_call(L,0,0);
   *paramPtr="commandcnt";
   lua_getglobal(L, *paramPtr);
   HttpServerConfig_setNoOfHttpCommands(cfg,(U16)luaL_optint(L,-1,3));

   *paramPtr="sessioncnt";
   lua_getglobal(L, *paramPtr);
   HttpServerConfig_setMaxSessions(cfg,(U16)luaL_optint(L,-1,50));

   *paramPtr="conncnt";
   lua_getglobal(L, *paramPtr);
   HttpServerConfig_setNoOfHttpConnections(cfg,(U16)luaL_optint(L,-1,50));

   *paramPtr="rspsz";
   lua_getglobal(L, *paramPtr);
   HttpServerConfig_setResponseData(cfg,(U16)luaL_optint(L,-1,8*1024));

   *paramPtr="reqminsz";
   lua_getglobal(L, *paramPtr);
   val=(U16)luaL_optint(L,-1,4*1024);
   *paramPtr="reqmaxsz";
   lua_getglobal(L, *paramPtr);
   HttpServerConfig_setRequest(cfg,val,(U16)luaL_optint(L,-1,8*1024));

   *paramPtr="tracker_nodes";
   lua_getglobal(L, *paramPtr);
   cfgParams->trackerNodes=(int)luaL_optint(L,-1,100);

   *paramPtr="tracker_maxlogin";
   lua_getglobal(L, *paramPtr);
   cfgParams->maxlogin=(int)luaL_optint(L,-1,4);

   *paramPtr="tracker_bantime";
   lua_getglobal(L, *paramPtr);
   cfgParams->bantime=(int)luaL_optint(L,-1,10*60);

   return 0;
}


static char*
openAndLoadConf(const char* path,  HttpServerConfig* scfg, int isdir)
{
   char* name=0;
   char* abspath=0;
   if(path)
   {
      if(*LUA_DIRSEP == '/' ? (path[0] != '/') : (path[1] != ':'))
      {
         char cwd[1024];
         if(xgetcwd(cwd, sizeof(cwd)))
         {
            abspath=baMalloc(strlen(cwd)+strlen(path)+5);
            basprintf(abspath,"%s%s%s",cwd,LUA_DIRSEP,path);
            baElideDotDot(abspath);
            path=abspath;
         }
      }
      name=malloc(strlen(path)+15);
      if(name)
      {
         struct stat statBuf;
         if(isdir)
            basprintf(name,"%s%smako.conf",path,LUA_DIRSEP);
         else
            basprintf(name,"%s",path);
         if( ! stat(name, &statBuf) )
         {
            const char* param=0;
            lua_State* L = luaL_newstate();
            luaopen_base(L);
            lua_pushcfunction(L,loadConfigData);
            lua_pushlightuserdata(L, scfg);
            lua_pushlightuserdata(L, name);
            lua_pushlightuserdata(L, (void*)&param);
            makoprintf(FALSE,"Loading %s.\n",name);
            if(lua_pcall(L,3,0,0))
            {
               const char* msg=lua_tostring(L,-1);
               if (!msg) msg="(error with no message)";
               if(param)
               {
                  const char* ptr=strchr(msg, '(');
                  makoprintf(TRUE,"Invalid value for paramater '%s': %s\n",
                             param, ptr ? ptr : msg);
               }
               else
                  makoprintf(TRUE,"%s\n",msg);
               exit(1);
            }
            lua_close(L);
         }
         else
         {
            free(name);
            name=NULL;
         }
      }
   }
   if(abspath)
      baFree(abspath);
   return name;
}


static char*
openAndLoadConfUsingExecPath(
   HttpServerConfig* cfg, const char* argv0, char** execpath)
{
   *execpath=findExecPath(argv0);
   if(*execpath)
   {
      char* cfgfname=openAndLoadConf(*execpath,cfg,TRUE);
      return cfgfname;
   }
   return NULL;
}


/* Initialize the HttpServer object by calling HttpServer_constructor.
   The HttpServerConfig object is only needed during initialization.
*/
static char*
createServer(HttpServer* server,int argc, char** argv, char** execpath)
{
   HttpServerConfig scfg;
   const char* ccfgfname;
   char* cfgfname=0;
   *execpath=0;
   HttpServerConfig_constructor(&scfg);

   if(findFlag(argc, argv, 'c', &ccfgfname))
   {
      if( ! (cfgfname=openAndLoadConf(ccfgfname,&scfg,FALSE)) )
      {
         errQuit("Error: cannot load configuration file %s.\n",ccfgfname);
      }
   }
   else if( ! (cfgfname=openAndLoadConfUsingExecPath(
                  &scfg,argc>0?argv[0]:0,execpath)) &&
            ! (cfgfname=openAndLoadConf("mako.conf",&scfg,FALSE)))
   {
      if( ! (cfgfname=openAndLoadConf(getenv("HOME"),&scfg,TRUE)) )
      {
#ifdef BA_WIN32
         if( ! (cfgfname=openAndLoadConf(getenv("USERPROFILE"),&scfg,TRUE)) )
            cfgfname=openAndLoadConf(getenv("HOMEPATH"),&scfg,TRUE);
#endif
      }
   }
   if(!cfgfname)
   {
      HttpServerConfig_setNoOfHttpCommands(&scfg,3);
      HttpServerConfig_setNoOfHttpConnections(&scfg,50);
      HttpServerConfig_setMaxSessions(&scfg,50);
      HttpServerConfig_setResponseData(&scfg,8*1024);
      HttpServerConfig_setRequest(&scfg,4*1024,8*1024);
   }

   /* Create and init the server, by using the above HttpServerConfig.
    */
   HttpServer_constructor(server, dispatcher, &scfg);
   return cfgfname;
}


/* Create Lua global variables "argv" for the command line arguments and
 * "env" for the system environment variables.
 */
static void
createLuaGlobals(
   int argc, char** argv, char** envp, char* cfgfname, const char* execpath)
{
   int i;
   char* ptr;
   static const luaL_Reg funcs[] = {
      {"logfile", lSetLogFile},
      {NULL, NULL}
   };

   lua_newtable(L);
   lua_pushstring(L, MAKO_VER);
   lua_setfield(L, -2, "version");
   lua_pushstring(L, __DATE__);
   lua_setfield(L, -2, "date");
#ifdef BASLIB_VER
   lua_pushstring(L, BASLIB_VER);
   lua_setfield(L, -2, "BAS");
#endif

   lua_newtable(L);
   for(i=1 ; i < argc; i++)
   {
      lua_pushstring(L, argv[i]);
      lua_rawseti(L, -2, i);
   }
   lua_setfield(L, -2, "argv");

   if(envp)
   {
      lua_newtable(L);
      for(ptr=*envp ; ptr; ptr=*++envp)
      {
         char* v = strchr(ptr, '=');
         if(v)
         {
            lua_pushlstring(L, ptr, v-ptr);
            lua_pushstring(L, v+1);
            lua_rawset(L, -3);
         }
      }
      lua_setfield(L, -2, "env");
   }
   if(cfgfname)
   {
      lua_pushstring(L, cfgfname);
      lua_setfield(L, -2, "cfgfname");
      free(cfgfname);
   }
   if(execpath)
   {
      lua_pushstring(L, execpath);
      lua_setfield(L, -2, "execpath");
   }

   luaL_setfuncs(L, funcs, 0);
   lua_setglobal(L, "mako");

};


static void
printUsage()
{
   static const char usage[]={
"Usage: " APPNAME " [options]\n"
"\nOptions:\n"
" -l[name]:[priority]:app  - Load one or multiple applications\n"
" -c configfile            - Load configuration file\n"
" -? -h                    - print this help message\n"
#ifdef BA_WIN32
" -install                 - Installs the service\n"
" -installauto             - Installs the service for autostart\n"
" -remove                  - Removes the service\n"
" -start                   - Starts the service\n"
" -stop                    - Stops the service\n"
" -restart                 - Stops and starts the service\n"
" -autostart               - Changes the service to automatic start\n"
" -manual                  - Changes the service to manual start\n"
" -state                   - Print the service state\n"
#else
" -d                       - Run in daemon mode\n"
" -u username              - Username to run as\n"
#endif
   };
   fprintf(stderr,"%s",usage);
   exit(1);
}


static IoIntf*
checkMakoIo(IoIntf* io, const char* name)
{
   IoStat sb;
   if( ! io->statFp(io, ".config", &sb) &&
       ! io->statFp(io, ".openports", &sb))
   {
      makoprintf(FALSE,"Mounting %s\n",name);
      return io;
   }
   makoprintf(
      TRUE,"%s is missing .config or .openports\n",name);
   return 0;
}

static IoIntf*
createAndCheckMakoZipIo(ZipReader* zipReader, const char* name)
{
   if(CspReader_isValid((CspReader*)zipReader))
   {
      ZipIo* vmIo=(ZipIo*)baMalloc(sizeof(ZipIo));
      ZipIo_constructor(vmIo, zipReader, 2048, 0);
      if(ZipIo_getECode(vmIo) ==  ZipErr_NoError)
      {
         if(checkMakoIo((IoIntf*)vmIo,name))
            return (IoIntf*)vmIo;
      }
      ZipIo_destructor(vmIo);
      baFree(vmIo);
   }
   return 0;
}


static IoIntf*
openMakoZip(IoIntf* rootIo, const char* path)
{
   IoStat st;
   IoIntf* io=0;
   int plen=strlen(path);
   char* buf=(char*)baMalloc(plen+12);
   basprintf(buf,"%s%smako.zip",
             path, path[plen-1] == *LUA_DIRSEP ? "" : LUA_DIRSEP);
   if(*LUA_DIRSEP == '\\')
   {
      char* ptr=buf;
      while(*ptr)
      {
         if(*ptr == '\\')
            *ptr='/';
         ptr++;
      }
      if(buf[1]==':')
      {
         buf[1] = buf[0];
         buf[0]='/';
      }
   }
   baElideDotDot(buf);
   if( ! rootIo->statFp(rootIo, buf, &st) )
   {
      makoZipReader = baMalloc(sizeof(IoIntfZipReader));
      IoIntfZipReader_constructor(makoZipReader, rootIo, buf);
      io=createAndCheckMakoZipIo((ZipReader*)makoZipReader, buf);
      if(!io)
      {
         IoIntfZipReader_destructor(makoZipReader);
         baFree(makoZipReader);
         makoZipReader=0;
      }
   }
   baFree(buf);
   return io;
}


static IoIntf*
openVmIo(IoIntf* rootIo,const char* execpath, const char* cfgfname)
{
   int status;
   IoIntf* io=0;
   char* path=getenv("MAKO_ZIP");
   if(path)
   {
      const char* nd="non-deployed mako.zip dir";
      DiskIo* dio = baMalloc(sizeof(DiskIo));
      DiskIo_constructor(dio);
      status=DiskIo_setRootDir(dio,path);
      if(!status)
      {
         if(checkMakoIo((IoIntf*)dio,path))
            return (IoIntf*)dio;
      }
      else
         makoprintf(TRUE,"Cannot open %s %s.\n",nd,path);
      baFree(dio);
   }
   if(execpath)
   {
      io=openMakoZip(rootIo,execpath);
      if(io)
         return io;
   }
   if(cfgfname)
   {
      char* ptr;
      path=baStrdup(cfgfname);
      ptr=strrchr(path,*LUA_DIRSEP);
      if(ptr) *ptr=0;
      else path=".";
      io=openMakoZip(rootIo,path);
      baFree(path);
      if(io)
         return io;
   }

   /*
     The following code opens the internal (embedded ZIP file), if
     finding/opening mako.zip fails.
   */
   {
#if defined(BAIO_DISK)
      /* Test only: Use filesystem, not internal ZIP for lsp dir */
      static const char* dirname="../../lsp";
      DiskIo* vmIo=(DiskIo)baMalloc(sizeof(DiskIo));
      DiskIo_constructor(vmIo);
      if( (ecode=DiskIo_setRootDir(vmIo, dirname)) != 0 &&
          (ecode=DiskIo_setRootDir(vmIo, dirname)) != 0)
      {
         errQuit("Cannot set DiskIo directory %s: %s\n",
                 dirname,
                 baErr2Str(ecode));
      }
      io=checkMakoIo((IoIntf*)vmIo);
#elif defined(USE_EMBEDDED_ZIP)
      /* Use embedded ZIP file, which is Created by the the BA tool: bin2c */
      io=createAndCheckMakoZipIo(getLspZipReader(),"'embedded mako.zip'");
#endif
   }
   if(!io)
      errQuit("Fatal error: cannot find mako.zip.\n");
   return io;
}


static void
checkEndian()
{
   U16 endian;
   U8* ptr = (U8*)&endian;
#ifdef B_LITTLE_ENDIAN
   ptr[1]=0x11;
   ptr[0]=0x22;
#elif defined(B_BIG_ENDIAN)
   ptr[0]=0x11;
   ptr[1]=0x22;
#else
#error NO_ENDIAN
#endif
   if(endian != 0x1122)
      errQuit("Panic!!! Wrong endian\n");
} 


void
runMako(int isWinService, int argc, char* argv[], char* envp[])
{
   int ecode;
   ThreadMutex mutex;
   SoDisp disp;
   HttpServer server;
   BaTimer timer;
   HttpCmdThreadPool pool;
   NetIo netIo;
   BaLua_param blp = {0}; /* configuration parameters */
   DiskIo diskIo;
   DiskIo homeIo;
   char* cfgfname;
   char* execpath;
   balua_thread_Shutdown tShutdown;
#ifdef BA_WIN32
   int sMode=0; /* 0: nothing, 1: install, 2: installauto, 3: start now */ 
#endif

   checkEndian();

   dispatcher=&disp; /* The global ptr used by the CTRL-C signal handler */
   HttpTrace_setFLushCallback(writeHttpTrace);
   HttpServer_setErrHnd(serverErrHandler);
#ifdef BA_WIN32
   /* For dumb WebDAV clients trying to access non existing disks in Windows
    * i.e. empty CD ROM. Prevent server from popping up dialog 'error'.
    */
   SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOOPENFILEERRORBOX);
#endif
   if( ! isWinService )
   {
      setCtrlCHandler();
      fprintf(stderr,"\n%s\n%s\n%s\n\n",MAKO_VNAME,MAKO_DATE,MAKO_CPR);
   }
   initUnix();
   if(isWinService)
      daemonMode=isWinService;
   else
   {
      int i;
      for(i=1; i < argc ; i++)
      {
         char* ptr=argv[i];
         if(*ptr == '-')
         {
            ptr++;
            if( (*ptr == '?' || *ptr=='h') && !ptr[1])
               printUsage();
#ifdef BA_WIN32
            if(!strcmp("autostart",ptr))
            {
               mustBeAdmin();
               pxexit(prtok(serviceSetStartup(SERVICENAME, SERVICE_AUTO_START)
                            == SERVICE_AUTO_START,"set to auto start"),TRUE);
            }
            else if(!strcmp("install",ptr))
            {
               sMode=1;
            }
            else if(!strcmp("installauto",ptr))
            {
               sMode=2;
            }
            else if(!strcmp("manual",ptr))
            {
               mustBeAdmin();
               pxexit(prtok(
                         serviceSetStartup(SERVICENAME, SERVICE_DEMAND_START)
                         == SERVICE_DEMAND_START,"set to manual start"),TRUE);
            
            }
            else if(!strcmp("remove",ptr))
            {
               mustBeAdmin();
               pxexit(serviceRemove(SERVICENAME),TRUE);
            }
            else if(!strcmp("restart",ptr))
            {
               if(serviceState(SERVICENAME) != SERVICE_STOPPED &&
                  serviceStop(SERVICENAME) < 0)
               {
                  pxexit(1,TRUE);
               }
               sMode=3;
            }
            else if(!strcmp("start",ptr))
            {
               if(serviceState(SERVICENAME) == SERVICE_RUNNING)
                  pxexit(1,TRUE);
               sMode=3;
            }
            else if(!strcmp("state",ptr))
            {
               fprintf(stderr,"%s %s\n", SERVICENAME,
                       serviceStateDesc(serviceState(SERVICENAME)));
               exit(0);
            
            }
            else if(!strcmp("stop",ptr))
            {
               if(serviceState(SERVICENAME) != SERVICE_STOPPED)
               {
                  mustBeAdmin();
                  pxexit(prtok(serviceStop(SERVICENAME) ==SERVICE_STOPPED,
                               "stopped"),TRUE);
               }
               else
                  pxexit(1,TRUE);
            }
#else
            if( ! strcmp(ptr,"d") )
               daemonMode=TRUE;
#endif 
         }
      }
   }

#ifdef BA_WIN32
   if(!isWinService && sMode)
   {
      int status=0;
      mustBeAdmin();
      if(sMode == 3)
      {
         status=prtok(serviceStart(SERVICENAME,argc,argv)
                      == SERVICE_RUNNING,"started");
      }
      else if(serviceInstall(SERVICENAME,sMode==2,argc,argv))
         status=1;
      else if(sMode==2)
      {
         status=prtok(serviceStart(SERVICENAME,argc,argv)
                      == SERVICE_RUNNING,"started");
      }
      pxexit(status,TRUE);
   }
#else
   if(daemonMode)
      setLinuxDaemonMode();
#endif

   /* Create the Socket dispatcher (SoDisp), the SoDisp mutex, and the server.
    */
   cfgParams=baMalloc(sizeof(ConfigParams));
   cfgParams->trackerNodes=100;
   cfgParams->maxlogin=4;
   cfgParams->bantime=10*60;

   ThreadMutex_constructor(&mutex);
   SoDisp_constructor(&disp, &mutex);
   cfgfname=createServer(&server,argc,argv,&execpath);
   if(!execpath)
      execpath=findExecPath(argc>0?argv[0]:0);

   /* The optional timer */
   BaTimer_constructor(&timer, &mutex, 10000, 50, ThreadPrioNormal, 0);

   /* Root of local file system */
   DiskIo_constructor(&diskIo);

   /* Create a LSP virtual machine.
    */
   blp.vmio = openVmIo((IoIntf*)&diskIo,execpath,cfgfname);
   blp.server = &server;           /* pointer to a HttpServer */
   blp.timer = &timer;             /* Pointer to a BaTimer */
   L = balua_create(&blp);        /* create the Lua state */

   lua_gc(L, LUA_GCSTOP, 0);  /* stop collector during initialization */
   createLuaGlobals(argc,argv,envp,cfgfname,execpath);
   lua_gc(L, LUA_GCRESTART, 0);

   balua_usertracker_create(
      L, cfgParams->trackerNodes, cfgParams->maxlogin, cfgParams->bantime);
   baFree(cfgParams);

   /*** Add optional IO interfaces
        In Lua, use ba.openio(name), where name is net,disk,home from
        names below:
    ***/

   /* Make code compatible with the lspappmgr i.e. add 'net' io */
   NetIo_constructor(&netIo, &disp);
   balua_iointf(L, "net",  (IoIntf*)&netIo);

   balua_iointf(L, "disk",  (IoIntf*)&diskIo);

   DiskIo_constructor(&homeIo);
   DiskIo_setRootDir(&homeIo, ""); /* set to current directory */
   balua_iointf(L, "home",  (IoIntf*)&homeIo);

   balua_http(L); /* Install optional HTTP client library */
   tShutdown=balua_thread(L); /* Install optional Lua thread library */
   balua_socket(L);  /* Install optional Lua socket library */
   balua_sharkssl(L);  /* Install optional Lua SharkSSL library */
   balua_crypto(L);  /* Install optional crypto library */
   balua_tracelogger(L); /* Install optional trace logger  */

   /* Install optional SQL bindings */
   luaopen_SQL(L);

#ifdef BAS_LOADED
   luaopen_ba_redirector(L);
#ifndef _WIN32
   balua_forkpty(L); /* The optional forkpty Lua bindings for Linux */
#endif
#endif

   /* Dispatcher mutex must be locked when running the .openports script
    */
   ThreadMutex_set(&mutex);

   /* (Ref-ports)
      Open web server listen ports by calling the Lua script
      '.openports'. Notice that we do this on Linux before downgrading
      from user root to 'user'. Only root can open ports below 1024 on
      Linux (REF-user).
   */
   ecode=balua_loadconfig(L, blp.vmio, ".openports");

   ThreadMutex_release(&mutex);
   if(ecode)
      errQuit(".openports error: %s.\n", lua_tostring(L,-1)); 

   /* On Linux, optionally downgrade from root to 'user'
      When run as: sudo mako -u `whoami`
   */
   setUser(argc,argv);

   /* Dispatcher mutex must be locked when running the .config script
    */
   ThreadMutex_set(&mutex);
   ecode=balua_loadconfig(L, blp.vmio, 0); /* Load and run .config  */
   ThreadMutex_release(&mutex);
   if(ecode)
      errQuit(".config error: %s.\n", lua_tostring(L,-1)); 

   /* See (A) above */
   HttpCmdThreadPool_constructor(&pool, &server, ThreadPrioNormal, 10000);

   /*
     The dispatcher object waits for incoming HTTP requests. These
     requests are sent to the HttpServer object, where they are delegated to
     a Barracuda resource such as the WebDAV instance.
   */
   SoDisp_run(&disp, -1);/*-1: Never returns unless CTRL-C handler sets exit*/

   /*Dispatcher mutex must be locked when terminating the following objects.*/
   ThreadMutex_set(&mutex);   
   onunload(); /* Graceful termination of Lua apps. See function above. */
   tShutdown(L,&mutex); /* Wait for threads to exit, if any */
   HttpCmdThreadPool_destructor(&pool);

   /* Must cleanup all sessions before destroying the Lua VM */
   HttpServer_termAllSessions(&server);
   /* Destroy all objects, including server listening objects. */
   lua_close(L);

   IoIntf_destructor(blp.vmio); /* Virtual destr */
   baFree(blp.vmio);
   DiskIo_destructor(&homeIo);
   DiskIo_destructor(&diskIo);
   NetIo_destructor(&netIo);
   if(makoZipReader)
   {
      IoIntfZipReader_destructor(makoZipReader);
      baFree(makoZipReader);
   }
   BaTimer_destructor(&timer);

   HttpServer_destructor(&server);
   SoDisp_destructor(&disp);

   ThreadMutex_release(&mutex);   
   ThreadMutex_destructor(&mutex);

   HttpTrace_close();
   if(execpath) baFree(execpath);
   dispatcher=0; /* Ref-wait */
   HttpTrace_flush();
   if(logFp) fclose(logFp);
   return;
}


#ifndef _WIN32
int
main(int argc, char* argv[], char* envp[])
{
   runMako(FALSE,argc, argv, envp);
   return 0;
}
#endif
