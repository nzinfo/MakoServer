/*
 *     ____             _________                __                _
 *    / __ \___  ____ _/ /_  __(_)___ ___  ___  / /   ____  ____ _(_)____
 *   / /_/ / _ \/ __ `/ / / / / / __ `__ \/ _ \/ /   / __ \/ __ `/ / ___/
 *  / _, _/  __/ /_/ / / / / / / / / / / /  __/ /___/ /_/ / /_/ / / /__
 * /_/ |_|\___/\__,_/_/ /_/ /_/_/ /_/ /_/\___/_____/\____/\__, /_/\___/
 *                                                       /____/
 *
 *                             Mako Server
 **************************************************************************
 *
 *   $Id: SendError.c 2820 2013-01-24 18:16:26Z wini $
 *
 *   COPYRIGHT:  Real Time Logic, 2012
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
 *               http://www.realtimelogic.com
 ****************************************************************************
 *
 */


#include "mako.h"
#ifndef USE_AMALGAMATED_BAS
#include "../../../xrc/misc/HttpClient.h"
#include <JSerializer.h>
#endif

static int BufPrint_sockWrite(BufPrint* o, int sizeRequired)
{
   HttpClient_sendData((HttpClient*)o->userData,o->buf,o->cursor);
   o->cursor=0;
   return 0;
}

void sendFatalError(const char* eMsg,
                    BaFatalErrorCodes ecode1,
                    unsigned int ecode2,
                    const char* file,
                    int line)
{
#ifdef CRASH_HANDLER_URL
   SoDisp disp;
   HttpClient http;
   SoDisp_constructor(&disp,NULL);
   HttpClient_constructor(&http,&disp,0);

   if(!HttpClient_request(&http,HttpMethod_Put,
                          CRASH_HANDLER_URL,
                          0,0,0,0))
   {
      char outBuffer[256];
      JErr err;
      JSerializer js;
      BufPrint out;
      BufPrint_constructor(&out,&http,BufPrint_sockWrite);
      out.buf = outBuffer;
      out.bufSize = sizeof(outBuffer);
      JErr_constructor(&err);
      JSerializer_constructor(&js, &err, &out);
      JSerializer_set(&js,"{sddsdss}",
                      "emsg",eMsg,
                      "ecode1",ecode1,
                      "ecode2",ecode2,
                      "file",file,
                      "line",line,
                      "platform",SERVER_SOFTWARE_NAME,
                      "version",__DATE__);
      JSerializer_commit(&js);
      HttpClient_getStatus(&http);
      JSerializer_destructor(&js);
      BufPrint_destructor(&out);
   }
   HttpClient_destructor(&http);
   SoDisp_destructor(&disp);
#else
   (void)eMsg;
   (void)ecode1;
   (void)ecode2;
   (void)file;
   (void)line;
#endif
}
