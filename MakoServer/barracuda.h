
/*
   Barracuda Embedded Web Server Amalgamation for posix
   Copyright Real Time Logic LLC. http://realtimelogic.com
*/


#ifndef _a_barracuda_h
#define _a_barracuda_h
#define lobject_c
#define LUA_CORE
#define BA_API
#define ZIP_ENCRYPTION
#define HTTP_TRACE
#define BA_SHARKSSL
#define SHARKSSL_API
#define _Z_UTIL_H
#define NDEBUG
#define BA_FILESIZE64
#define LUA_USE_LINUX
#define _POSIX
#define _REENTRANT
#define _LINUX_
#define _GNU_SOURCE

#include "baextinc.h"
#define HTTP_E_BASE 1

#ifndef __BaErrorCodes_h
#define __BaErrorCodes_h



typedef enum {
   FE_MALLOC = HTTP_E_BASE, 
   FE_ASSERT,               
   FE_NO_SERV_CON,          
   FE_SOCKET,               
   FE_GETHOSTBYNAME,        
   FE_GETHOSTBYNAME2,       
   FE_BIND,                 
   FE_LISTEN,               
   FE_IOCTL,                
   FE_SETSOCKOPT,           
   FE_ACCEPT,               
   FE_NO_IPV6_SUPPORT,      
   FE_INVALID_CSPREADER,    
   FE_CANNOT_READ,          
   FE_MAGIC_NO,             
   FE_THREAD_LIB,           
   FE_SSL_ERROR,                 
   FE_HTTPCON_INVALID_DISPEV,    
   FE_BLUA_PANIC,                
   FE_EXIT,
   FE_INCORRECT_USE,
   FE_TYPE_SIZE_ERROR, 
   FE_WRONG_ENDIAN, 

   FE_USER_ERROR_1 = HTTP_E_BASE+100,
   FE_USER_ERROR_2,
   FE_USER_ERROR_3,
   FE_USER_ERROR_4,
   FE_USER_ERROR_5,
   FE_USER_ERROR_6,
   FE_USER_ERROR_7,
   FE_USER_ERROR_8,
   FE_USER_ERROR_9,
   FE_USER_ERROR_10
} BaFatalErrorCodes;


typedef enum {
   E_NO_ERROR=0,
   E_INVALID_SOCKET_CON=-1000,
   E_GETHOSTBYNAME,
   E_BIND,
   E_SOCKET_CLOSED,
   E_SOCKET_WRITE_FAILED,
   E_SOCKET_READ_FAILED,
   E_SOCKET_READ_TIMEOUT,
   E_MALLOC,
   E_ALREADY_INSERTED,
   E_TOO_MUCH_DATA,
   E_PAGE_NOT_FOUND, 
   E_IS_COMMITTED,
   E_INVALID_PARAM,
   E_MIXING_WRITE_SEND,
   E_TOO_MANY_INCLUDES,
   E_TOO_MANY_FORWARDS,
   E_INCLUDE_OP_NOT_VALID,

   E_CANNOT_RESOLVE,
   E_CANNOT_CONNECT,
   E_INVALID_URL,
   E_INVALID_RESPONSE,

   E_INCORRECT_USE,  

   E_SSL_NOT_ENABLED,
   E_SHARK_ALERT_RECV, 
   E_SHARK_CRYPTOERR,
   E_SHARK_HANDSHAKE,
   E_NOT_TRUSTED, 

   E_PROXY_AUTH = -500, 
   E_PROXY_GENERAL, 
   E_PROXY_NOT_ALLOWED, 
   E_PROXY_NETWORK, 
   E_PROXY_HOST, 
   E_PROXY_REFUSED, 
   E_PROXY_TTL, 
   E_PROXY_COMMAND_NOT_SUP, 
   E_PROXY_ADDRESS_NOT_SUP, 
   E_PROXY_NOT_COMPATIBLE, 
   E_PROXY_UNKNOWN 
} BaErrorCodes;



#define baFatalE(ecode1, ecode2) baFatalEf(ecode1, ecode2, __FILE__, __LINE__)
#ifdef __cplusplus
extern "C" {
#endif
BA_API void baFatalEf(BaFatalErrorCodes ecode1, unsigned int ecode2,
                 const char* file, int line);

BA_API const char* baErr2Str(int ecode);

BA_API int baErr2HttpCode(int ecode);
#ifdef __cplusplus
}
#endif



#endif 

#ifndef __lxrc_h
#define __lxrc_h 


#ifndef _SharkSsl_h
#define _SharkSsl_h


#ifndef _SharkSsl_cfg_h
#define _SharkSsl_cfg_h




#ifndef SHARKSSL_USE_AES_256
#define SHARKSSL_USE_AES_256                             1
#endif

#ifndef SHARKSSL_USE_AES_128
#define SHARKSSL_USE_AES_128                             1
#endif


#ifndef SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ENABLE_AES_GCM                          1
#endif

#ifndef SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_ENABLE_AES_CCM                          1
#endif

#ifndef SHARKSSL_USE_3DES
#define SHARKSSL_USE_3DES                                1
#endif

#ifndef SHARKSSL_USE_ARC4
#define SHARKSSL_USE_ARC4                                1
#endif


#ifndef SHARKSSL_USE_DES
#define SHARKSSL_USE_DES                                 0
#endif

#ifndef SHARKSSL_USE_NULL_CIPHER
#define SHARKSSL_USE_NULL_CIPHER                         0
#endif





#ifndef SHARKSSL_USE_SHA_512
#define SHARKSSL_USE_SHA_512                             0
#endif


#ifndef SHARKSSL_USE_SHA_384
#define SHARKSSL_USE_SHA_384                             1
#endif


#ifndef SHARKSSL_USE_SHA_256
#define SHARKSSL_USE_SHA_256                             1
#endif


#ifndef SHARKSSL_USE_SHA1
#define SHARKSSL_USE_SHA1                                1
#endif


#ifndef SHARKSSL_USE_MD5
#define SHARKSSL_USE_MD5                                 1
#endif

  



#ifndef SHARKSSL_ENABLE_MD5_CIPHERSUITES
#define SHARKSSL_ENABLE_MD5_CIPHERSUITES                 0
#endif



#if SHARKSSL_ENABLE_MD5_CIPHERSUITES
#undef  SHARKSSL_USE_MD5
#define SHARKSSL_USE_MD5                                 1
#endif



#ifndef SHARKSSL_SSL_SERVER_CODE
#define SHARKSSL_SSL_SERVER_CODE                         1
#endif



#ifndef SHARKSSL_ACCEPT_CLIENT_HELLO_2_0
#define SHARKSSL_ACCEPT_CLIENT_HELLO_2_0                 1
#endif



#ifndef SHARKSSL_ENABLE_CLIENT_AUTH
#define SHARKSSL_ENABLE_CLIENT_AUTH                      1
#endif



#ifndef SHARKSSL_SSL_CLIENT_CODE
#define SHARKSSL_SSL_CLIENT_CODE                         1
#endif



#ifndef SHARKSSL_ENABLE_RSA
#define SHARKSSL_ENABLE_RSA                              1
#endif



#ifndef SHARKSSL_ENABLE_RSA_BLINDING
#define SHARKSSL_ENABLE_RSA_BLINDING                     1
#endif



#ifndef SHARKSSL_ENABLE_SESSION_CACHE
#define SHARKSSL_ENABLE_SESSION_CACHE                    1
#endif



#ifndef SHARKSSL_ENABLE_SECURE_RENEGOTIATION
#define SHARKSSL_ENABLE_SECURE_RENEGOTIATION             1
#endif



#ifndef SHARKSSL_ENABLE_CLIENT_INITIATED_RENEGOTIATION
#define SHARKSSL_ENABLE_CLIENT_INITIATED_RENEGOTIATION   0
#endif



#ifndef SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_ENABLE_TLS_1_2                          1
#endif



#if SHARKSSL_ENABLE_TLS_1_2
#undef  SHARKSSL_USE_SHA_256
#define SHARKSSL_USE_SHA_256                             1
#endif



#ifndef SHARKSSL_ENABLE_TLS_1_1
#define SHARKSSL_ENABLE_TLS_1_1                          1
#endif



#ifndef SHARKSSL_ENABLE_SSL_3_0
#define SHARKSSL_ENABLE_SSL_3_0                           0
#endif



#ifndef SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_ENABLE_DHE_RSA                          1
#endif



#ifndef SHARKSSL_ENABLE_SELECT_CIPHERSUITE
#define SHARKSSL_ENABLE_SELECT_CIPHERSUITE               1
#endif



#ifndef SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH
#define SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH           8
#endif



#ifndef SHARKSSL_ENABLE_PSK
#define SHARKSSL_ENABLE_PSK                              0
#endif



#ifndef SHARKSSL_ENABLE_RSA_API
#define SHARKSSL_ENABLE_RSA_API                          1
#endif



#ifndef SHARKSSL_ENABLE_RSA_PKCS1
#define SHARKSSL_ENABLE_RSA_PKCS1                        1
#endif



#ifndef SHARKSSL_ENABLE_PEM_API
#define SHARKSSL_ENABLE_PEM_API                          1
#endif



#ifndef SHARKSSL_ENABLE_INFO_API
#define SHARKSSL_ENABLE_INFO_API                         1
#endif



#ifndef SHARKSSL_ENABLE_CERT_CHAIN
#define SHARKSSL_ENABLE_CERT_CHAIN                       1
#endif



#ifndef SHARKSSL_ENABLE_CA_LIST
#define SHARKSSL_ENABLE_CA_LIST                          1
#endif



#ifndef SHARKSSL_ENABLE_CERTSTORE_API
#define SHARKSSL_ENABLE_CERTSTORE_API                    1
#endif



#ifndef SHARKSSL_ENABLE_CLONE_CERTINFO
#define SHARKSSL_ENABLE_CLONE_CERTINFO                   1
#endif



#ifndef SHARKSSL_MD5_SMALL_FOOTPRINT
#define SHARKSSL_MD5_SMALL_FOOTPRINT                     0
#endif

#ifndef SHARKSSL_SHA1_SMALL_FOOTPRINT
#define SHARKSSL_SHA1_SMALL_FOOTPRINT                    0
#endif

#ifndef SHARKSSL_SHA256_SMALL_FOOTPRINT
#define SHARKSSL_SHA256_SMALL_FOOTPRINT                  0
#endif



#ifndef SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K
#define SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K             4
#endif



#ifndef SHARKSSL_BIGINT_MULT_LOOP_UNROLL
#define SHARKSSL_BIGINT_MULT_LOOP_UNROLL                 1
#endif



#ifndef SHARKSSL_ENABLE_AES_CTR_MODE
#define SHARKSSL_ENABLE_AES_CTR_MODE                     1
#endif



#ifndef SHARKSSL_DES_CIPHER_LOOP_UNROLL
#define SHARKSSL_DES_CIPHER_LOOP_UNROLL                  1
#endif



#ifndef SHARKSSL_AES_CIPHER_LOOP_UNROLL
#define SHARKSSL_AES_CIPHER_LOOP_UNROLL                  1
#endif



#ifndef SHARKSSL_UNALIGNED_ACCESS
#ifdef UNALIGNED_ACCESS
#define SHARKSSL_UNALIGNED_ACCESS                        1
#else
#define SHARKSSL_UNALIGNED_ACCESS                        0
#endif
#endif



#ifndef SHARKSSL_BIGINT_WORDSIZE
#define SHARKSSL_BIGINT_WORDSIZE                         32
#endif



#ifndef SHARKSSL_USE_ECC
#define SHARKSSL_USE_ECC                                 1
#endif



#ifndef SHARKSSL_ENABLE_ECDSA
#define SHARKSSL_ENABLE_ECDSA                            1
#endif



#ifndef SHARKSSL_ECC_VERIFY_POINT
#define SHARKSSL_ECC_VERIFY_POINT                        1
#endif


#ifndef SHARKSSL_ECC_TIMING_RESISTANT
#define SHARKSSL_ECC_TIMING_RESISTANT                    0
#endif


#ifndef SHARKSSL_ECC_USE_SECP192R1
#define SHARKSSL_ECC_USE_SECP192R1                       1
#endif

#ifndef SHARKSSL_ECC_USE_SECP224R1
#define SHARKSSL_ECC_USE_SECP224R1                       1
#endif

#ifndef SHARKSSL_ECC_USE_SECP256R1
#define SHARKSSL_ECC_USE_SECP256R1                       1
#endif

#ifndef SHARKSSL_ECC_USE_SECP384R1
#define SHARKSSL_ECC_USE_SECP384R1                       1
#endif

#ifndef SHARKSSL_ECC_USE_SECP521R1
#define SHARKSSL_ECC_USE_SECP521R1                       1
#endif



#ifndef SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ENABLE_ECDHE_RSA                        1
#endif



#ifndef SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ENABLE_ECDH_RSA                         1
#endif



#ifndef SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ENABLE_ECDHE_ECDSA                      1
#endif



#ifndef SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ENABLE_ECDH_ECDSA                       1
#endif

  

#endif
#ifdef __cplusplus
#endif

#ifndef SHARKSSL_API
#define SHARKSSL_API
#else  
#define SHARKSSL_BA 1


#ifndef ThreadLib_hpp


#ifndef _HttpConfig_h
#define _HttpConfig_h


#ifndef _TargConfig_h
#define _TargConfig_h



#if !defined(B_LITTLE_ENDIAN) && !defined(B_BIG_ENDIAN)
#define B_LITTLE_ENDIAN 1
#endif



#if defined(GNUC) || defined(__GNU__) || defined(__GNUC_MINOR__)
#ifndef __GNUC__
#define __GNUC__
#endif
#endif



#define HTTP_E_BASE 1 
#ifndef SERVER_SOFTWARE_NAME
#define SERVER_SOFTWARE_NAME "BarracudaServer.com (Posix)"
#endif

#ifndef BA_API
#define BA_API
#endif

#if defined(SHARKSSL_LIB)
#if !defined(BA_LIB)
#define BA_LIB SHARKSSL_LIB
#endif
#endif


#if defined(BALUA_LIB)
#if !defined(BA_LIB)
#define BA_LIB BALUA_LIB
#endif
#endif



#if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
      defined(__ELF__)
#define BAI_FUNC	__attribute__((visibility("hidden"))) extern
#define BAI_DATA	BAI_FUNC

#else
#define BAI_FUNC	extern
#define BAI_DATA	extern
#endif

#ifndef SHARKSSL_API
#define SHARKSSL_API BA_API
#endif

#ifndef BALUA_API
#define BALUA_API BA_API
#endif




#ifndef baAssert
#ifdef NDEBUG
#define baAssert(exp)
#else
#define baAssert(exp) ( (exp) ? (void)0 : baFatalEf(FE_ASSERT, 0, __FILE__, __LINE__) )
#endif
#endif



#ifdef BA_LEAK_CHECK
#else
#ifdef USE_DLMALLOC
#ifdef __cplusplus
extern "C" {
#endif
void init_dlmalloc(char* heapstart, char* heapend);
void* dlmalloc(size_t bytes);
void* dlrealloc(void* oldmem, size_t bytes);
void dlfree(void* mem);
#ifdef __cplusplus
}
#endif
#define baMalloc(size) dlmalloc(size)
#define baRealloc(ptr, size) dlrealloc(ptr, size);
#define baFree(ptr) dlfree(ptr)
#else
#define baMalloc(size) malloc(size)
#define baRealloc(ptr,size) realloc(ptr,size)
#define baFree(ptr) free(ptr)
#endif
#endif



#ifndef _GenPrimT_h
#define _GenPrimT_h

#ifndef _TargConfig_h
#endif





#if defined(__GNUC__) || defined(__CODEWARRIOR__) || defined(__DCC__) || defined(__ghs) || defined(__IAR_SYSTEMS_ICC__) || defined(__ARMCC_VERSION)
   
   typedef unsigned long long U64;
   typedef long long S64;
#elif defined(_MSC_VER)
   
   typedef unsigned __int64 U64;
   typedef __int64 S64;
#else
#error Add "typedef U64" for your platform
#endif




#ifndef B_OVERLOAD_BASIC_TYPES
typedef signed char S8;
typedef unsigned char U8;
typedef signed short S16;
typedef unsigned short U16;
typedef signed int S32;
typedef unsigned int U32;
#endif


typedef U32 BaTime;

typedef U8 BaBool;
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define S64_getMsw(o) ((S32)(0xFFFFFFFF & ((o) >> 32) ))

#ifdef BA_FILESIZE64
typedef U64 BaFileSize;
typedef S64 SBaFileSize;

#define BA_UFSF "llu"
#define BA_SFSF "lld"
#else
typedef U32 BaFileSize;
typedef S32 SBaFileSize;
#define BA_UFSF "lu"
#define BA_SFSF "ld"
#endif


#ifdef __cplusplus
extern "C" {
#endif


BA_API U64 U64_atoll(const char* s);
BA_API U64 U64_atoll2(const char* s, const char* e);

#define S64_atoll(s) ((S64)U64_atoll(s))


   
BA_API U32 U32_negate(U32 n);

   
BA_API U32 U32_atoi(const char* s);

   
BA_API U32 U32_atoi2(const char* s, const char* e);

   
BA_API U32 U32_hextoi(const char *s);
#ifdef __cplusplus
}
#endif




#endif
#define baGetUnixTime() time(0)

#ifdef __cplusplus
extern "C" {
#endif
   BA_API unsigned int baGetMsClock(void);
#ifdef __cplusplus
}
#endif



#define bStrncmp strncmp
#define bStrchr strchr
#define bStrstr strstr
#define bStrrchr strrchr
#define bStrncpy strncpy
#define bAtoi atoi
#define bTolower tolower
#define bIsspace isspace
#define bIsxdigit isxdigit


#endif


#ifndef _gBsdDspO_h
#define _gBsdDspO_h





#define CONNECTION_DISPATCHER_OBJ DoubleLink dispatcherLink;






#ifndef _DoubleList_h
#define _DoubleList_h

struct DoubleList;

typedef struct DoubleLink
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
       DoubleLink();
      ~DoubleLink();
      void insertAfter(DoubleLink* newLink);
      void insertBefore(DoubleLink* newLink);
      void unlink();
      bool isLinked();
      DoubleLink* getNext();
#endif
      struct DoubleLink* next;
      struct DoubleLink* prev;
} DoubleLink;



typedef struct DoubleList
{
#ifdef __cplusplus
      DoubleList();
      void insertFirst(DoubleLink* newLink);
      void insertLast(DoubleLink* newLink);
      bool isLast(DoubleLink* n);
      DoubleLink* firstNode();
      DoubleLink* lastNode();
      bool isEmpty();
      DoubleLink* removeFirst();
      bool isInList(DoubleLink* n);
#endif
   DoubleLink* next;
   DoubleLink* prev;
} DoubleList;


#define DoubleLink_constructor(o) do { \
   ((DoubleLink*)o)->next = 0; \
   ((DoubleLink*)o)->prev = 0; \
} while(0)


#define DoubleLink_destructor(o) do { \
      if(DoubleLink_isLinked(o)) \
         DoubleLink_unlink(o); \
} while(0)

#define DoubleLink_insertAfter(o, newLink) do { \
   baAssert(((DoubleLink*)newLink)->prev==0&&((DoubleLink*)newLink)->next==0);\
   ((DoubleLink*)newLink)->next = ((DoubleLink*)o)->next; \
   ((DoubleLink*)newLink)->prev = ((DoubleLink*)o); \
   ((DoubleLink*)o)->next->prev = ((DoubleLink*)newLink); \
   ((DoubleLink*)o)->next = ((DoubleLink*)newLink); \
} while(0)


#define DoubleLink_insertBefore(o, newLink) do { \
   baAssert(((DoubleLink*)newLink)->prev==0&&((DoubleLink*)newLink)->next==0);\
   ((DoubleLink*)newLink)->prev = ((DoubleLink*)o)->prev; \
   ((DoubleLink*)newLink)->next = ((DoubleLink*)o); \
   ((DoubleLink*)o)->prev->next = ((DoubleLink*) newLink); \
   ((DoubleLink*)o)->prev = ((DoubleLink*) newLink); \
} while(0)


#define DoubleLink_unlink(o) do { \
   baAssert(((DoubleLink*)o)->prev && ((DoubleLink*)o)->next);\
   ((DoubleLink*) o)->next->prev = ((DoubleLink*)o)->prev; \
   ((DoubleLink*) o)->prev->next = ((DoubleLink*)o)->next; \
   ((DoubleLink*) o)->next = 0; \
   ((DoubleLink*) o)->prev = 0; \
} while(0)

#ifdef NDEBUG
#define DoubleLink_isLinked(o) \
   (((DoubleLink*)o)->prev ? TRUE : FALSE)
#else
#define DoubleLink_isLinked(o) \
   (((DoubleLink*)o)->prev ? (baAssert(((DoubleLink*)o)->next), TRUE) : FALSE)
#endif

#define DoubleLink_getNext(o) ((DoubleLink*)(o))->next


#define DoubleList_constructor(o) do { \
   (o)->next = (DoubleLink*)o; \
   (o)->prev = (DoubleLink*)o; \
} while(0)


#define DoubleList_insertFirst(o, newLink) do { \
   baAssert(((DoubleLink*)newLink)->prev==0&&((DoubleLink*)newLink)->next==0);\
   ((DoubleLink*)newLink)->next = (o)->next; \
   ((DoubleLink*)newLink)->prev = (DoubleLink*)o; \
   (o)->next->prev = ((DoubleLink*) newLink); \
   (o)->next = ((DoubleLink*) newLink); \
} while(0)


#define DoubleList_insertLast(o, newLink) do { \
   baAssert(((DoubleLink*)newLink)->prev==0&&((DoubleLink*)newLink)->next==0);\
   ((DoubleLink*)newLink)->next = (DoubleLink*)o; \
   ((DoubleLink*)newLink)->prev = (o)->prev; \
   (o)->prev->next = ((DoubleLink*)newLink); \
   (o)->prev = ((DoubleLink*)newLink); \
} while(0)


#define DoubleList_isLast(o, n) (((DoubleLink*)(n))->next == (DoubleLink*)(o))
#define DoubleList_isEnd(o, n) ((DoubleLink*)(n) == (DoubleLink*)(o))

#define DoubleList_firstNode(o) \
   ((o)->next != (DoubleLink*)o ? (o)->next : 0)


#define DoubleList_lastNode(o) \
   ((o)->prev != (DoubleLink*)o ? (o)->prev : 0)



#define DoubleList_isEmpty(o)  \
   (((DoubleLink*)(o))->next == (DoubleLink*)(o))


#ifdef __cplusplus
extern "C" {
#endif

BA_API DoubleLink* DoubleList_removeFirst(DoubleList* o);


#ifdef NDEBUG
#define DoubleList_isInList(o, node) (((DoubleLink*)node)->prev ? TRUE : FALSE)
#else
#define DoubleList_isInList(o, node) DoubleList_isInListF(o, node, __FILE__, __LINE__)
BA_API BaBool DoubleList_isInListF(DoubleList* o,void* node,const char* file,int line);
#endif


#ifdef __cplusplus
}
inline DoubleLink::DoubleLink() {
   DoubleLink_constructor(this);
}
inline DoubleLink::~DoubleLink() {
   DoubleLink_destructor(this);
}
inline void DoubleLink::insertAfter(DoubleLink* newLink) {
   DoubleLink_insertAfter(this, newLink);
}
inline void DoubleLink::insertBefore(DoubleLink* newLink) {
   DoubleLink_insertBefore(this, newLink);
}
inline void DoubleLink::unlink() {
   DoubleLink_unlink(this);
}
inline bool DoubleLink::isLinked() {
   return DoubleLink_isLinked(this) ? true : false;
}
inline DoubleLink* DoubleLink::getNext() {
   return DoubleLink_getNext(this);
}
inline DoubleList::DoubleList() {
   DoubleList_constructor(this);
}
inline void DoubleList::insertFirst(DoubleLink* newLink) {
   DoubleList_insertFirst(this, newLink);
}
inline void DoubleList::insertLast(DoubleLink* newLink) {
   DoubleList_insertLast(this, newLink);
}
inline bool DoubleList::isLast(DoubleLink* n) {
   return DoubleList_isLast(this, n) ? true : false;
}
inline  DoubleLink* DoubleList::firstNode() {
   return DoubleList_firstNode(this);
}
inline DoubleLink* DoubleList::lastNode() {
   return DoubleList_lastNode(this);
}
inline bool DoubleList::isEmpty() {
   return DoubleList_isEmpty(this) ? true : false;
}
inline DoubleLink* DoubleList::removeFirst() {
   return DoubleList_removeFirst(this);
}
inline bool DoubleList::isInList(DoubleLink* n) {
   return DoubleList_isInList(this, n)  ? true : false;
}
#endif





typedef struct DoubleListEnumerator
{
#ifdef __cplusplus
      DoubleListEnumerator(){}
      DoubleListEnumerator(DoubleList* list);
      DoubleLink* getElement();
      DoubleLink* nextElement();
      DoubleLink* removeElement();
   private:
#endif
      DoubleList* list;
      DoubleLink* curElement;
} DoubleListEnumerator;

#define DoubleListEnumerator_constructor(o, listMA) do \
{ \
   (o)->list = listMA; \
   (o)->curElement = DoubleList_firstNode((o)->list);\
} while(0)

#define DoubleListEnumerator_getElement(o) (o)->curElement

#define DoubleListEnumerator_nextElement(o) \
   ((o)->curElement ? ( \
      (o)->curElement = (o)->curElement->next == (DoubleLink*)(o)->list ? 0 : (o)->curElement->next, \
      (o)->curElement \
    ) : 0)

#ifdef __cplusplus
extern "C" {
#endif
BA_API DoubleLink* DoubleListEnumerator_removeElement(DoubleListEnumerator* o);
#ifdef __cplusplus
}
inline DoubleListEnumerator::DoubleListEnumerator(DoubleList* list) {
   DoubleListEnumerator_constructor(this, list); }
inline DoubleLink*
DoubleListEnumerator::removeElement() {
   return DoubleListEnumerator_removeElement(this); }
inline DoubleLink*
DoubleListEnumerator::getElement() {return DoubleListEnumerator_getElement(this);}
inline DoubleLink*
DoubleListEnumerator::nextElement() {return DoubleListEnumerator_nextElement(this); }
#endif


#endif
#define DISPATCHER_DATA \
  DoubleList conList; \
  DoubleList pendingList; \
  DoubleLink* curL; \
  DoubleListEnumerator iter; \
  int defaultPollDelay; \
  int pollDelay
#endif

#ifndef _NetConv_h
#define _NetConv_h


#ifdef B_LITTLE_ENDIAN
#define baHtonl(x) ((U32)((((U32)(x) & 0x000000ffU) << 24) | \
                         (((U32)(x) & 0x0000ff00U) <<  8) | \
                         (((U32)(x) & 0x00ff0000U) >>  8) | \
                         (((U32)(x) & 0xff000000U) >> 24)))
#define baHtons(x) ((U16)((((U16)(x) & 0x00ff) << 8) | \
                         (((U16)(x) & 0xff00) >> 8)))
#elif defined B_BIG_ENDIAN
#define baHtonl(x) x
#define baHtons(x) x
#else
#error endian needed
#endif
#define baNtohl(x) baHtonl(x)
#define baNtohs(x) baHtons(x)



#endif

#if defined(FD_CLOEXEC)

#undef HttpSocket_setcloexec
#undef HttpSocket_clearcloexec
#undef basocketpair

#define HttpSocket_setcloexec(o) (void)fcntl((o)->hndl, F_SETFD, FD_CLOEXEC)

#define HttpSocket_clearcloexec(o)  (void)fcntl((o)->hndl, F_SETFD, 0)

#define basocketpair(fd) socketpair(AF_UNIX,SOCK_STREAM,0,fd)

#else
#define HttpSocket_setcloexec(x)
#define HttpSocket_clearcloexec(x)
#define basocketpair(x)
#endif 


#if defined(EINTR) && defined(EAGAIN)
 
#undef socketAccept
#define socketAccept
#undef socketSend
#define socketSend

#define HttpSocket_accept(o, conSock, status) do { int e; \
 (conSock)->hndl=accept((o)->hndl, NULL, NULL); \
 if ((conSock)->hndl < 0) {e=errno; \
 if (e==EINTR||e==EAGAIN) continue;*(status)=e?e:-1;break;}    \
 else {*(status)=0;HttpSocket_setcloexec(o);break;} \
 } while(1)

#define HttpSocket_recv(o, data, len, retLen) do { \
  *(retLen)=recv((o)->hndl,data,len,0); \
  if(*(retLen) == 0) {*(retLen) = -1;break;}  \
  if(*(retLen) < 0) { int e=errno; \
    if (e==EINTR) continue; \
    if (e==EAGAIN) {*(retLen)=0;break;}   \
  } \
  break; \
} while(1)

#define HttpSocket_send(o, m, isTerminated, data, len, retLen) do { \
  if(m && ThreadMutex_isOwner(m)) { \
    ThreadMutex_release(m); \
    *(retLen)=send((o)->hndl,data,len,0); \
    ThreadMutex_set(m); \
  } \
  else \
    *(retLen)=send((o)->hndl,data,len,0); \
  if(*(retLen) < 0) { \
    int e=errno; \
    if (e==EINTR) continue; \
    if (e==EAGAIN) {*(retLen)=0;} \
  } \
  break; \
} while(1)

#endif 




#ifndef _gBsdSock_h
#define _gBsdSock_h

#ifdef __cplusplus
extern "C" {
#endif

struct HttpSockaddr;

#ifndef basocklen_t
#define basocklen_t socklen_t
#endif

#ifndef SocketHandle
#define SocketHandle int
#endif

#ifndef socketAccept
#define socketAccept accept
#endif

#ifndef socketBind
#define socketBind bind
#endif

#ifndef socketClose
#define socketClose close
#endif

#ifndef socketShutdown
#define socketShutdown shutdown
#endif

#ifndef socketErrno
#define socketErrno(s) errno
#endif


#ifndef socketIoctl
#define socketIoctl ioctl
#endif

#ifndef socketGetPeerName
#define socketGetPeerName getpeername
#endif

#ifndef socketGetSockName
#define socketGetSockName getsockname
#endif

#ifndef socketListen
#define socketListen listen
#endif

#ifndef socketRecv
#define socketRecv recv
#endif

#ifndef socketSelect
#define socketSelect select
#endif

#ifndef socketSend
#define socketSend send
#endif

#ifndef socketSetsockopt
#define socketSetsockopt setsockopt
#endif

#ifndef socketSocket
#define socketSocket socket
#endif

#ifndef socketInetAddr
#define socketInetAddr inet_addr
#endif

#ifndef socketInetPton
#define socketInetPton inet_pton
#endif

#ifndef socketGethostbyname
#define socketGethostbyname gethostbyname
#endif

#ifndef socketInetNtoa
#define socketInetNtoa inet_ntoa
#endif

#ifndef socketWouldBlock
#define socketWouldBlock(s) (EWOULDBLOCK == socketErrno(s))
#endif

#ifndef socketInProgress
#ifdef EINPROGRESS
#define socketInProgress(s) (EINPROGRESS == socketErrno(s))
#else
#define socketInProgress(s) 0
#endif
#endif

#ifndef socketConnect
#define socketConnect connect
#endif


#ifndef HttpSocket_setcloexec
#define HttpSocket_setcloexec(x)
#endif
#ifndef HttpSocket_clearcloexec
#define HttpSocket_clearcloexec(x)
#endif
#ifndef basocketpair
#define basocketpair(x)
#endif



typedef struct {
      SocketHandle hndl;
} HttpSocket;


#ifndef HttpSocket_accept
#define HttpSocket_accept(o, conSock, status) do { \
   (conSock)->hndl=socketAccept((o)->hndl, NULL, NULL); \
   *(status) = (HttpSocket_isValid(conSock)) ? 0 : -1; \
   HttpSocket_setcloexec(o); \
}while(0)
#endif


#ifndef HttpSocket_bind
#define HttpSocket_bindIp4(o, sockAddr, port, status) do { \
   struct sockaddr_in in; \
   memset(&in, 0, sizeof(struct sockaddr_in)); \
   in.sin_family = AF_INET; \
   in.sin_port = baHtons(port); \
   memcpy(&in.sin_addr.s_addr,(sockAddr)->addr, 4); \
   *(status) = socketBind((o)->hndl, (struct sockaddr *)&in, \
                          sizeof(struct sockaddr_in)); \
} while(0)
#ifdef USE_IPV6
#define HttpSocket_bindIp6(o, sockAddr, port, status) do { \
      struct sockaddr_in6 in6; \
      memset(&in6, 0, sizeof(struct sockaddr_in6)); \
      in6.sin6_family = AF_INET6; \
      in6.sin6_port = baHtons(port); \
      memcpy(&in6.sin6_addr, (sockAddr)->addr, 16); \
      *(status) = socketBind((o)->hndl, (struct sockaddr*)&in6, \
                       sizeof(struct sockaddr_in6)); \
} while(0)
#else
#define HttpSocket_bindIp6(o, sockAddr, port, status) baAssert(0)
#endif
#define HttpSocket_bind(o, sockAddr, port, status) do { \
   if((sockAddr)->isIp6) \
      HttpSocket_bindIp6(o, sockAddr, port, status); \
   else \
      HttpSocket_bindIp4(o, sockAddr, port, status); \
}while(0)
#endif

#ifndef HttpSocket_close
#define HttpSocket_close(o) do {\
   int status;\
   HttpSocket_setNonblocking(o,&status);\
   (void)status; \
   socketClose((o)->hndl);\
   HttpSocket_invalidate(o);\
 } while(0)
#endif



#ifndef HttpSocket_hardClose
#define HttpSocket_hardClose(o) do {\
   struct linger l;\
   l.l_onoff = 1; l.l_linger = 0;\
   setsockopt((o)->hndl,SOL_SOCKET,SO_LINGER,(char*)&l,sizeof(struct linger));\
   socketClose((o)->hndl);\
   HttpSocket_invalidate(o);\
 } while(0)
#endif


#ifndef HttpSocket_shutdown
#define HttpSocket_shutdown(o) do {\
   int status;\
   HttpSocket_setBlocking(o,&status);\
   (void)status; \
   socketShutdown((o)->hndl,2);\
   socketClose((o)->hndl);\
   HttpSocket_invalidate(o);\
 } while(0)
#endif


#ifndef HttpSocket_constructor
#define HttpSocket_constructor(o) do { \
   memset(o, 0, sizeof(HttpSocket)); \
   HttpSocket_invalidate(o); \
}while(0)
#endif

#ifndef HttpSocket_errno
#define HttpSocket_errno(o, status, ecode) *(ecode) = socketErrno((o)->hndl)
#endif

#ifndef HttpSocket_getId
#define HttpSocket_getId(o) (int)(o)->hndl
#endif

#ifndef HttpSocket_getPeerName
#define HttpSocket_getPeerNameIp4(o, sockAddr, port, status) do { \
   struct sockaddr_in in; basocklen_t size=sizeof(struct sockaddr_in);\
   *(status) = socketGetPeerName((o)->hndl, (struct sockaddr *)&in, &size); \
   memcpy((sockAddr)->addr, &in.sin_addr.s_addr, 4);\
   if(port) *(port)=baHtons(in.sin_port);\
} while(0)
#ifdef USE_IPV6
#define HttpSocket_getPeerNameIp6(o, sockAddr, port, status) do { \
  struct sockaddr_in6 in6; basocklen_t size=sizeof(struct sockaddr_in6);\
  *(status) = socketGetPeerName((o)->hndl, (struct sockaddr*)&in6, &size); \
  memcpy(sockAddr, &in6.sin6_addr, 16); \
   if(port) *(port)=baHtons(in6.sin6_port);\
} while(0)
#else
#define HttpSocket_getPeerNameIp6(o, sockAddr, port, status) baAssert(0)
#endif
#define HttpSocket_getPeerName(o, sockAddr, port, setIsIp6, status) do { \
   if(setIsIp6) \
      HttpSocket_getPeerNameIp6(o, sockAddr, port, status); \
   else \
      HttpSocket_getPeerNameIp4(o, sockAddr, port, status); \
   (sockAddr)->isIp6=setIsIp6; \
}while(0)
#endif

#ifndef HttpSocket_getSockName
#define HttpSocket_getSockNameIp4(o, sockAddr, port, status) do { \
   struct sockaddr_in in; basocklen_t size=sizeof(struct sockaddr_in);\
   *(status) = socketGetSockName((o)->hndl, (struct sockaddr *)&in, &size); \
   memcpy((sockAddr)->addr, &in.sin_addr.s_addr, 4);\
   if(port) *(port)=baHtons(in.sin_port);\
} while(0)
#ifdef USE_IPV6
#define HttpSocket_getSockNameIp6(o, sockAddr, port, status) do { \
  struct sockaddr_in6 in6; basocklen_t size=sizeof(struct sockaddr_in6);\
  *(status) = socketGetSockName((o)->hndl, (struct sockaddr*)&in6, &size); \
  memcpy(sockAddr, &in6.sin6_addr, 16); \
   if(port) *(port)=baHtons(in6.sin6_port);\
} while(0)
#else
#define HttpSocket_getSockNameIp6(o, sockAddr, port, status) baAssert(0)
#endif
#define HttpSocket_getSockName(o, sockAddr, port, setIsIp6, status) do { \
   if(setIsIp6) \
      HttpSocket_getSockNameIp6(o, sockAddr, port, status); \
   else \
      HttpSocket_getSockNameIp4(o, sockAddr, port, status); \
   (sockAddr)->isIp6=setIsIp6; \
}while(0)
#endif

#ifndef HttpSocket_invalidate
#define HttpSocket_invalidate(o) (o)->hndl = -1
#endif

#ifndef HttpSocket_isValid
#define HttpSocket_isValid(o) ((o)->hndl >= 0)
#endif

#ifndef HttpSocket_listen
#define HttpSocket_listen(o, sockaddrNotUsed, queueSize, status) do { \
   *(status)=socketListen((o)->hndl, queueSize); \
   HttpSocket_setcloexec(o); \
}while(0)
#endif

#ifndef HttpSocket_move
#define HttpSocket_move(o, newS) do{ \
  (newS)->hndl=(o)->hndl;HttpSocket_invalidate(o);}while(0)
#endif

#ifndef HttpSocket_recv
#define HttpSocket_recv(o, data, len, retLen) do { \
  *(retLen)=socketRecv((o)->hndl,data,len,0);\
  if(*(retLen) <= 0) { \
     if(*(retLen) < 0) { \
        int wb; \
        HttpSocket_wouldBlock(o, &wb); \
        if(wb) \
           *(retLen)=0;   \
     } \
     else *(retLen) = -1;  \
  } \
} while(0)
#endif

#ifndef HttpSocket_send
#define HttpSocket_send(o, m, isTerminated, data, len, retLen) do { \
  if(m && ThreadMutex_isOwner(m)) { \
    ThreadMutex_release(m); \
    *(retLen)=socketSend((o)->hndl,data,len,0); \
    ThreadMutex_set(m); \
  } \
  else \
    *(retLen)=socketSend((o)->hndl,data,len,0); \
  if(*(retLen) < 0) { \
     int wb; \
     HttpSocket_wouldBlock(o, &wb); \
     if(wb) \
        *(retLen)=0;   \
  } \
} while(0)
#endif

#ifndef HttpSocket_setBlocking
#define HttpSocket_setBlocking(o, status) do { \
   U32 arg=0;  \
  *(status)=socketIoctl((o)->hndl, FIONBIO, &arg); \
} while(0)
#endif

#ifndef HttpSocket_setNonblocking
#define HttpSocket_setNonblocking(o, status) \
do { \
   U32 arg=1;  \
  *(status)=socketIoctl((o)->hndl, FIONBIO, &arg); \
} while(0)
#endif

#ifndef HttpSocket_setTCPNoDelay
#define HttpSocket_setTCPNoDelay(o, enable, status) do { \
   int enableFlag = enable ? 1 : 0; \
   *(status) = socketSetsockopt((o)->hndl, IPPROTO_TCP, TCP_NODELAY, \
                               (char*)&enableFlag, sizeof(int)); \
}while(0)
#endif

#ifndef HttpSocket_soReuseaddr
#define HttpSocket_soReuseaddr(o, status) do { \
   int enableFlag = 1; \
   *(status) = socketSetsockopt((o)->hndl, SOL_SOCKET, SO_REUSEADDR, \
                               (char*)&enableFlag, sizeof(int)); \
}while(0)
#endif

#ifndef HttpSocket_sockStream
#ifdef USE_IPV6
#define HttpSocket_sockStreamIp6(o, status) do { \
   (o)->hndl=socketSocket(AF_INET6, SOCK_STREAM, 0); \
   *(status) = HttpSocket_isValid(o) ? 0 : -1; \
}while(0)
#else
#define HttpSocket_sockStreamIp6(o, status) HttpSocket_sockStreamIp4(o, status)
#endif

#define HttpSocket_sockStreamIp4(o, status) do { \
  (o)->hndl=socketSocket(AF_INET, SOCK_STREAM, 0); \
   *(status) = HttpSocket_isValid(o) ? 0 : -1; \
}while(0)

#define HttpSocket_sockStream(o, interfNameNotUsed, useIp6, status) do { \
   if(useIp6) \
     HttpSocket_sockStreamIp6(o, status); \
   else \
     HttpSocket_sockStreamIp4(o, status); \
}while(0)
#endif


#ifndef HttpSocket_wouldBlock
#define HttpSocket_wouldBlock(o, status) do { \
   *(status)=socketWouldBlock((o)->hndl); \
   if(!*(status)) { \
      *(status)=socketInProgress((o)->hndl); \
   } \
} while(0)
#endif



#ifndef HttpSocket_connect

#define HttpSocket_connectV4(o, addr, port, status) \
   struct sockaddr_in sin; \
   memset((char *)&sin, 0, sizeof(sin)); \
   sin.sin_family = AF_INET; \
   sin.sin_port = baHtons(port); \
   memcpy(&sin.sin_addr.s_addr, (addr)->addr, 4);\
   *(status) = socketConnect((o)->hndl,(struct sockaddr *)&sin, sizeof(sin));



#ifdef USE_IPV6
#define HttpSocket_connectV6(o, addr, port, status)\
   struct sockaddr_in6 sin6; \
   memset((char *)&sin6, 0, sizeof(sin6)); \
   sin6.sin6_family =  (addr)->isIp6 ? AF_INET6 : AF_INET; \
   sin6.sin6_port = baHtons(port); \
   memcpy(&sin6.sin6_addr, (addr)->addr, 16); \
   *(status)=socketConnect((o)->hndl,(struct sockaddr *)&sin6,sizeof(sin6));


#define HttpSocket_connect(o, addr, port, status) do {\
   if((addr)->isIp6) {\
      HttpSocket_connectV6(o, addr, port, status)\
   }\
   else {\
      HttpSocket_connectV4(o, addr, port, status)\
   }\
} while(0)


#else
#define HttpSocket_connect(o, addr, port, status) do {\
  HttpSocket_connectV4(o, addr, port, status) } while(0)
#endif
#endif


BA_API int HttpSocket_makeClientCon(
   HttpSocket* o,struct HttpSockaddr* addr,
   const char* interfaceName,U16 port, BaBool nonBlocking);

typedef struct HttpSockaddr {
      char addr[16];
      BaBool isIp6;
} HttpSockaddr;


#ifndef HttpSockaddr_gethostbynameIp6
#ifdef USE_IPV6
#define HttpSockaddr_gethostbynameIp6(o, host, status) do { \
   if(host) { \
      struct addrinfo hints, *servinfo; \
      memset(&hints, 0, sizeof hints); \
      hints.ai_family = AF_INET6; \
      hints.ai_socktype = SOCK_STREAM; \
      *(status) = getaddrinfo(host, 0, &hints, &servinfo); \
      if( ! *(status) ) { \
         memcpy((o)->addr, \
                &((struct sockaddr_in6*)servinfo->ai_addr)->sin6_addr, 16); \
         freeaddrinfo(servinfo); \
      } \
   } \
   else { \
      memset((o)->addr, 0, 16); \
      *(status)=0; \
   } \
   (o)->isIp6=TRUE; \
}while(0)
#else
#define HttpSockaddr_gethostbynameIp6(o, host, status) \
  HttpSockaddr_gethostbynameIp4(o, host, status)
#endif
#endif

#ifndef HttpSockaddr_gethostbyname
#define HttpSockaddr_gethostbynameIp4(o, host, status)  do { \
   unsigned long ipAddr; \
   (o)->isIp6=FALSE; \
   *(status)=0; \
   if(host) \
   { \
      ipAddr = socketInetAddr(host);  \
      if(ipAddr == INADDR_NONE)  \
      { \
         struct hostent* hostInfo = socketGethostbyname((char*)host); \
         if(!hostInfo) \
            *(status)=-1; \
         else \
            memcpy(&ipAddr,&((struct in_addr *)hostInfo->h_addr)->s_addr,4);\
      } \
   } \
   else \
      ipAddr = baHtonl(INADDR_ANY); \
   memcpy((o)->addr,&ipAddr, 4); \
}while(0)


#define HttpSockaddr_gethostbyname(o, host, useIp6, status) do { \
   if(useIp6) \
     HttpSockaddr_gethostbynameIp6(o, host, status); \
   else \
     HttpSockaddr_gethostbynameIp4(o, host, status); \
}while(0)
#endif


#ifndef HttpSockaddr_addr2String
BA_API void HttpSockaddr_addr2String(
   HttpSockaddr* o, char* buf, int bufLen, int* status);
#endif


#ifndef HttpSockaddr_inetAddr
BA_API void HttpSockaddr_inetAddr(
   HttpSockaddr* o, const char* host, BaBool useIp6, int* status);
#endif


#ifdef __cplusplus
}
#endif


#endif
#endif
typedef enum { 
   ThreadPrioLowest, 
   ThreadPrioLow, 
   ThreadPrioNormal, 
   ThreadPrioHigh, 
   ThreadPrioHighest 
} ThreadPriority;


#ifndef __DOXYGEN__
struct HttpRequest;
struct ThreadMutex;
struct Thread;
#endif


typedef void (*Thread_Run)(struct Thread* th);

#ifdef __cplusplus
extern "C" {
#else
struct ThreadReleaseLock;
#endif

BA_API void ThreadReleaseLock_internalConstructor(
   struct ThreadReleaseLock* o, struct HttpRequest* req);

#ifdef __cplusplus
}
#endif




#if defined(__cplusplus)

#ifndef __DOXYGEN__
struct ThreadReleaseLock;
#endif


struct ThreadLock
{
      
      ThreadLock(ThreadMutex& m);

      
      ThreadLock(ThreadMutex* m);

      
      ~ThreadLock();
   private:
      friend struct ThreadReleaseLock;
      struct ThreadMutex* mutex;
};



struct ThreadReleaseLock
{
      
      ThreadReleaseLock(struct HttpRequest* req);
      
      ThreadReleaseLock(ThreadMutex& m);
      
      ThreadReleaseLock(ThreadMutex* m);
      
      ThreadReleaseLock(ThreadLock& tl);
      
      ThreadReleaseLock(ThreadLock* tl);
      
      ~ThreadReleaseLock();
   private:
      struct ThreadMutex* mutex;
};


#else
#define ThreadMutexBase ThreadMutex
#define ThreadSemaphoreBase ThreadSemaphore
#define ThreadBase Thread
#endif




#ifndef ThreadLib_hpp
#define ThreadLib_hpp

#ifndef POLICY
#define POLICY SCHED_FIFO
#endif

#ifdef __CYGWIN__
#define SYGW_SEM_FIX(sem) memset(&sem, 0, sizeof(sem))
#else
#define SYGW_SEM_FIX(sem)
#endif

#define INFINITE ((unsigned long)~0)

#ifdef NDEBUG
#define Thread_ce(x) x
#else
#ifdef __cplusplus
extern "C" {
#endif
BA_API void Thread_cef(int status, const char* file, int line);
#ifdef __cplusplus
}
#endif
#define Thread_ce(x) Thread_cef(x, __FILE__, __LINE__)
#endif

struct ThreadSemaphoreBase;
struct ThreadMutexBase;

typedef struct ThreadMutexBase
{
      pthread_t tid; 
      pthread_mutex_t mutex;
} ThreadMutexBase;

#define ThreadMutex_destructor(o) Thread_ce(pthread_mutex_destroy(&(o)->mutex))
#define ThreadMutex_set(o) do {\
   Thread_ce(pthread_mutex_lock(&(o)->mutex));\
   (o)->tid = pthread_self();\
} while(0)
#define ThreadMutex_release(o) do{\
   (o)->tid=0;\
   Thread_ce(pthread_mutex_unlock(&(o)->mutex));\
} while(0)
#define ThreadMutex_isOwner(o) ((o)->tid == pthread_self())
#ifdef __cplusplus
extern "C" {
#endif
BA_API void ThreadMutex_constructor(struct ThreadMutexBase* o);
#ifdef __cplusplus
}
#endif


typedef struct ThreadSemaphoreBase
{
#ifdef __APPLE__
      sem_t* semPtr;
#else
      sem_t sem;
#endif
} ThreadSemaphoreBase;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void ThreadSemaphore_constructor(struct ThreadSemaphoreBase* o);
BA_API void ThreadSemaphore_destructor(struct ThreadSemaphoreBase* o);
#ifdef __cplusplus
}
#endif

#ifdef __APPLE__
#define SEM_PTR(o) (o)->semPtr
#else
#define SEM_PTR(o) &(o)->sem
#endif

#if defined(EINTR)

#ifdef __cplusplus
extern "C" {
#endif
BA_API int xsem_wait(sem_t *sem);
#ifdef __cplusplus
}
#endif
#else
#define xsem_wait sem_wait
#endif
#define ThreadSemaphore_wait(o) \
   Thread_ce(xsem_wait(SEM_PTR(o)))
#define ThreadSemaphore_signal(o) \
   Thread_ce(sem_post(SEM_PTR(o)))



typedef struct ThreadBase
{
      ThreadSemaphoreBase startSem;
      pthread_t tid;
      pthread_attr_t attr;
      Thread_Run runnable;
} ThreadBase;

#define Thread_sleep(ms) do {                   \
      struct timespec tp;                       \
      tp.tv_sec = (ms)/1000;                    \
      tp.tv_nsec = ((ms) % 1000) * 1000000;     \
      nanosleep(&tp,0);                         \
   } while(0)

#define Thread_destructor(o)
#ifdef __cplusplus
extern "C" {
#endif
BA_API void Thread_start(Thread* o);
BA_API void Thread_constructor(
   ThreadBase* o, Thread_Run r, ThreadPriority priority, int stackSize);
#ifdef __cplusplus
}
#endif


#endif
#if defined(__cplusplus)


struct ThreadMutex : public ThreadMutexBase
{
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      ThreadMutex() { ThreadMutex_constructor(this); }
      
      ~ThreadMutex() { ThreadMutex_destructor(this); }
      
      void set() { ThreadMutex_set(this); }
      
      void release() { ThreadMutex_release(this); }
      
      bool isOwner() { return ThreadMutex_isOwner(this)?true:false; }
};


struct ThreadSemaphore : public ThreadSemaphoreBase
{
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      ThreadSemaphore(){ ThreadSemaphore_constructor(this); }
      
      ~ThreadSemaphore(void) { ThreadSemaphore_destructor(this); }

      
      void wait() { ThreadSemaphore_wait(this); }

      
      void signal() { ThreadSemaphore_signal(this); }
};



struct Thread : public ThreadBase
{
      Thread() {}
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      Thread(Thread_Run r, ThreadPriority priority, int stackSize) {
         Thread_constructor(this, r, priority, stackSize); }
      ~Thread() { Thread_destructor(this); }
      
      void start() {  Thread_start(this); }

      
      static void sleep(unsigned int milliseconds) {
         Thread_sleep(milliseconds); }
};

inline ThreadLock::ThreadLock(ThreadMutex& m) : mutex(&m) { mutex->set(); }
inline ThreadLock::ThreadLock(ThreadMutex* m) : mutex(m) { mutex->set(); }
inline ThreadLock::~ThreadLock() { mutex->release(); }

inline ThreadReleaseLock::ThreadReleaseLock(struct HttpRequest* req) {
   ThreadReleaseLock_internalConstructor(this, req);
}
inline ThreadReleaseLock::ThreadReleaseLock(ThreadMutex& m) :
   mutex(&m) { mutex->release(); }
inline ThreadReleaseLock::ThreadReleaseLock(ThreadMutex* m) : 
   mutex(m) { mutex->release(); }
inline ThreadReleaseLock::ThreadReleaseLock(ThreadLock& tl) :
   mutex(tl.mutex) { mutex->release(); }
inline ThreadReleaseLock::ThreadReleaseLock(ThreadLock* tl) :
   mutex(tl->mutex) { mutex->release(); }
inline ThreadReleaseLock::~ThreadReleaseLock() { mutex->set(); }

#endif

 

#endif



#ifndef __httpServerLib_h
#define __httpServerLib_h

#ifdef BA_MEM_CHECK
#define AllocatorIntf AllocCheckIntf
#endif

#ifndef __DOXYGEN__
struct AllocatorIntf;
#endif



#ifdef __cplusplus
extern "C" {
#endif



 

#ifdef INL_baConvBin2Hex

extern const char baBin2HexTable[]; 

#define baConvBin2Hex(hexOutData, binIn) \
      hexOutData[0] = baBin2HexTable[((U8)binIn) >> 4], \
      hexOutData[1] = baBin2HexTable[((U8)binIn) & 0x0f]

#else

BA_API void baConvBin2Hex(void* hexOutData, U8 binIn);

#endif

BA_API BaTime baISO8601ToTime(const char* tStr, const char** emsg);

BA_API U8 baConvHex2Bin( U8 c );
BA_API void baConvU32ToHex(void* to, U32 from);
BA_API U32 baConvHexToU32(const void* from);



#ifdef BA_LEAK_CHECK
char* baStrdupLC(const char* str,const char* file, int line);
char* baStrdup2LC(struct AllocatorIntf* a, const char* str,
                const char* file, int line);
#define baStrdup(str) baStrdupLC(str, __FILE__, __LINE__)
#define baStrdup2(a, str) baStrdup2LC(a, str, __FILE__, __LINE__)
#else

BA_API char* baStrdup(const char* str);

BA_API char* baStrdup2(struct AllocatorIntf* a, const char* str);
#endif



BA_API const void* baBSearch(const void* key, const void* base, int num, 
                             int size, int (*cmp)(const void*,const void*));


BA_API int baStrCaseCmp(const char *a, const char *b);


BA_API int baStrnCaseCmp(const char *a, const char *b, int len);

const char* baGetToken(const char** str, const char* set);


BA_API BaTime baParseDate(const char* str);



BA_API int baB64Decode(
   unsigned char* outStr,int outStrSize,const char* b64EncStr);


BA_API int baElideDotDot(char* str);

BA_API void baXmlUnescape(char* f);

#if defined(_WIN32) && !defined(NDEBUG)

#undef bIsspace
#define bIsspace(c)  (c ==  ' ' || c == '\f' || c == '\n' || c == '\r' ||\
                                c == '\t' || c == '\v')
#endif

#define httpEatWhiteSpace(ptr) while(bIsspace(*ptr)) (ptr)++
#define httpEatNonWhiteSpace(ptr) while(!bIsspace(*ptr)) (ptr)++
#define httpEatCharacters(ptr, delimiter) \
   while(*ptr && *ptr != delimiter) (ptr)++


struct BaTm
{
      
      int       tm_sec;
      
      int       tm_min;
      
      int       tm_hour;
      
      int       tm_mday;
      
      int       tm_mon;
      
      int       tm_year;
      
      int       tm_wday;
      
      int       tm_yday;
      int       tm_isdst;
};


BA_API void baTime2tm(struct BaTm *tmP, BaTime t);


BA_API BaTime baTm2Time(struct BaTm* tmP);

 


#ifdef __cplusplus
}
#endif




#ifndef BA_MEM_CHECK


typedef void* (*AllocatorIntf_Malloc)(struct AllocatorIntf* o, size_t* size);


typedef void* (*AllocatorIntf_Realloc)(
   struct AllocatorIntf* o, void* memblock, size_t* size);


typedef void (*AllocatorIntf_Free)(struct AllocatorIntf* o, void* memblock);


typedef struct AllocatorIntf
{
#ifdef __cplusplus
      AllocatorIntf() {}
      
      AllocatorIntf(AllocatorIntf_Malloc malloc,
                    AllocatorIntf_Realloc realloc,
                    AllocatorIntf_Free free);

      
      static AllocatorIntf* getDefault(void);

      
      void* malloc(size_t* size);
      void* malloc(size_t size) { return malloc(&size); }

      
      void* realloc(void* p, size_t* size);
      void* realloc(void* p, size_t size) { return realloc(p, &size); }

      
      void free(void* p);
#endif
      AllocatorIntf_Malloc mallocCB;
      AllocatorIntf_Realloc reallocCB; 
      AllocatorIntf_Free freeCB;
#ifdef BA_LEAK_CHECK
      const char* file;
      int line;
#endif
} AllocatorIntf;

#define AllocatorIntf_constructor(o, m, r, f) do { \
   (o)->mallocCB=m; \
   (o)->reallocCB=r; \
   (o)->freeCB=f; \
} while(0)

#ifdef BA_LEAK_CHECK
#define AllocatorIntf_malloc(o, size) \
  ((o)->file=__FILE__,(o)->line=__LINE__,(o)->mallocCB(o, size))
#define AllocatorIntf_realloc(o, memblock, size) \
   ((o)->reallocCB ? ((o)->file=__FILE__,(o)->line=__LINE__,\
    (o)->reallocCB(o,memblock,size)) : 0)
#define AllocatorIntf_free(o, memblock) \
  ((o)->file=__FILE__,(o)->line=__LINE__,(o)->freeCB(o,memblock))
#else
#define AllocatorIntf_malloc(o, size) (o)->mallocCB(o, size)
#define AllocatorIntf_realloc(o, memblock, size) \
   ((o)->reallocCB ? (o)->reallocCB(o,memblock,size) : 0)
#define AllocatorIntf_free(o, memblock) (o)->freeCB(o,memblock)
#endif

#ifdef __cplusplus
extern "C" {
#endif
BA_API AllocatorIntf* AllocatorIntf_getDefault(void);
#ifdef __cplusplus
}
inline AllocatorIntf::AllocatorIntf(AllocatorIntf_Malloc malloc,
                                    AllocatorIntf_Realloc realloc,
                                    AllocatorIntf_Free free) {
   AllocatorIntf_constructor(this, malloc,realloc,free); }
inline AllocatorIntf* AllocatorIntf::getDefault(void) {
   return AllocatorIntf_getDefault(); }
inline void* AllocatorIntf::malloc(size_t* size) {
   return AllocatorIntf_malloc(this, size); }
inline void* AllocatorIntf::realloc(void* memblock, size_t* size) {
   return AllocatorIntf_realloc(this, memblock, size); }
inline void AllocatorIntf::free(void* memblock) {
   AllocatorIntf_free(this, memblock); }
#endif

#else
#endif

#ifdef __DOXYGEN__



void* baMalloc(size_t size);


void* baRealloc(void* p, size_t size);



void baFree(void* p);

#endif 


 

#endif
#endif


#ifndef _SharkSslCrypto_h
#define _SharkSslCrypto_h

#define SHARKSSL_LIB 1
#if SHARKSSL_USE_MD5

typedef struct SharkSslMd5Ctx
{
    U32 total[2];
    U32 state[4];
    U8  buffer[64];
} SharkSslMd5Ctx;
#endif


#if SHARKSSL_USE_SHA1

typedef struct SharkSslSha1Ctx
{
    U32 total[2];
    U32 state[5];
    U8  buffer[64];
} SharkSslSha1Ctx;
#endif


#if SHARKSSL_USE_SHA_256

typedef struct SharkSslSha256Ctx
{
    U32 total[2];
    U32 state[8];
    U8  buffer[64];
} SharkSslSha256Ctx;
#endif


#if (SHARKSSL_USE_SHA_384 || SHARKSSL_USE_SHA_512)

typedef struct SharkSslSha384Ctx
{
    U32 total[4];
    U64 state[8];
    U8  buffer[128];
} SharkSslSha384Ctx;
#endif


#if SHARKSSL_USE_SHA_512

typedef struct SharkSslSha384Ctx SharkSslSha512Ctx;
#endif


#if SHARKSSL_USE_ARC4

typedef struct SharkSslArc4Ctx
{
    U8 x;
    U8 y;
    U8 b[256];
} SharkSslArc4Ctx;
#endif


#if (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)

typedef struct SharkSslDesCtx
{
   #if SHARKSSL_USE_CAU
   #if SHARKSSL_USE_3DES
   U32 key[6];
   #else
   U32 key[2];
   #endif

   #else

   #if SHARKSSL_USE_3DES
   U32 key[96];
   #else
   U32 key[32];
   #endif
   #endif

   #if (SHARKSSL_USE_DES && SHARKSSL_USE_3DES)
   U8  tdea;
   #endif
} SharkSslDesCtx;


typedef enum
{
   SharkSslDesCtx_Decrypt,
   SharkSslDesCtx_Encrypt
} SharkSslDesCtx_Type;
#endif


#if (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)

typedef struct SharkSslAesCtx
{
    #if SHARKSSL_USE_AES_256
    U32 key[60];     
    #else
    U32 key[44];     
    #endif
    U16 nr;          
} SharkSslAesCtx;

typedef enum 
{
   SharkSslAesCtx_Decrypt,
   SharkSslAesCtx_Encrypt
} SharkSslAesCtx_Type;

#if SHARKSSL_ENABLE_AES_GCM

typedef struct SharkSslAesGcmCtx
{
   SharkSslAesCtx super;
   U8 M0[16][16];
} SharkSslAesGcmCtx;
#endif

#if SHARKSSL_ENABLE_AES_CCM

typedef struct SharkSslAesCcmCtx
{
   SharkSslAesCtx super;
   U8 tagLen;
} SharkSslAesCcmCtx;
#endif
#endif  


#ifdef __cplusplus
extern "C" {
#endif


SHARKSSL_API int   sharkssl_entropy(U32);
SHARKSSL_API int   sharkssl_rng(U8*, U16);

#if SHARKSSL_USE_MD5

SHARKSSL_API void  SharkSslMd5Ctx_constructor(SharkSslMd5Ctx* ctx);


SHARKSSL_API void  SharkSslMd5Ctx_append(SharkSslMd5Ctx* ctx, const U8* data, U32 len);


SHARKSSL_API void  SharkSslMd5Ctx_finish(SharkSslMd5Ctx* ctx, U8 digest[16]);


SHARKSSL_API int   sharkssl_md5(const U8*, U16, U8*);
#endif

#if SHARKSSL_USE_SHA1

SHARKSSL_API void  SharkSslSha1Ctx_constructor(SharkSslSha1Ctx* ctx);


SHARKSSL_API void  SharkSslSha1Ctx_append(SharkSslSha1Ctx* ctx, const U8* data, U32 len);


SHARKSSL_API void  SharkSslSha1Ctx_finish(SharkSslSha1Ctx*, U8 digest[20]);


SHARKSSL_API int   sharkssl_sha1(const U8*, U16, U8*);
#endif

#if SHARKSSL_USE_SHA_256

SHARKSSL_API void  SharkSslSha256Ctx_constructor(SharkSslSha256Ctx* ctx);


SHARKSSL_API void  SharkSslSha256Ctx_append(SharkSslSha256Ctx*, const U8* data, U32 len);


SHARKSSL_API void  SharkSslSha256Ctx_finish(SharkSslSha256Ctx*, U8 digest[32]);


SHARKSSL_API int   sharkssl_sha256(const U8*, U16, U8*);
#endif

#if SHARKSSL_USE_SHA_384

SHARKSSL_API void  SharkSslSha384Ctx_constructor(SharkSslSha384Ctx* ctx);


SHARKSSL_API void  SharkSslSha384Ctx_append(SharkSslSha384Ctx*, const U8* data, U32 len);


SHARKSSL_API void  SharkSslSha384Ctx_finish(SharkSslSha384Ctx*, U8 digest[48]);


SHARKSSL_API int   sharkssl_sha384(const U8*, U16, U8*);
#endif

#if SHARKSSL_USE_SHA_512

SHARKSSL_API void  SharkSslSha512Ctx_constructor(SharkSslSha512Ctx* ctx);


#define SharkSslSha512Ctx_append(ctx, d, l) SharkSslSha384Ctx_append((SharkSslSha384Ctx*)ctx, d, l)


SHARKSSL_API void  SharkSslSha512Ctx_finish(SharkSslSha512Ctx*, U8 digest[64]);


SHARKSSL_API int   sharkssl_sha512(const U8*, U16, U8*);
#endif

#if SHARKSSL_USE_ARC4

SHARKSSL_API void  SharkSslArc4Ctx_constructor(SharkSslArc4Ctx *ctx, 
                                               const U8 *key, U8 keyLen);

#define SharkSslArc4Ctx_destructor(ctx) memset(ctx, 0, sizeof(SharkSslArc4Ctx))


SHARKSSL_API void  SharkSslArc4Ctx_crypt(SharkSslArc4Ctx *ctx, U8 *input, U8 *output, U16 len);          
#endif

#if (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)

SHARKSSL_API void  SharkSslDesCtx_constructor(SharkSslDesCtx *ctx, 
                                              SharkSslDesCtx_Type type,
                                              const U8 *key, U8 keyLen);
#define SharkSslDesCtx_destructor(ctx)  memset(ctx, 0, sizeof(SharkSslDesCtx))


SHARKSSL_API void  SharkSslDesCtx_encrypt(SharkSslDesCtx *ctx, U8 input[8], U8 output[8]);
#if SHARKSSL_USE_CAU


SHARKSSL_API void  SharkSslDesCtx_decrypt(SharkSslDesCtx *ctx, U8 input[8], U8 output[8]);
#else
#define SharkSslDesCtx_decrypt(ctx,i,o) SharkSslDesCtx_encrypt((ctx),(i),(o))
#endif


SHARKSSL_API void  SharkSslDesCtx_cbc_encrypt(SharkSslDesCtx *ctx, U8 vect[8], 
                                              U8 *input, U8 *output, U16 len);


SHARKSSL_API void  SharkSslDesCtx_cbc_decrypt(SharkSslDesCtx *ctx, U8 vect[8], 
                                              U8 *input, U8 *output, U16 len);
#endif

#if (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)

SHARKSSL_API void  SharkSslAesCtx_constructor(SharkSslAesCtx *ctx, 
                                              SharkSslAesCtx_Type type,
                                              const U8 *key, U8 keyLen);
#define SharkSslAesCtx_destructor(ctx) memset(ctx, 0, sizeof(SharkSslAesCtx))


SHARKSSL_API void  SharkSslAesCtx_decrypt(SharkSslAesCtx *ctx, U8 input[16], U8 output[16]);


SHARKSSL_API void  SharkSslAesCtx_encrypt(SharkSslAesCtx *ctx, U8 input[16], U8 output[16]);


SHARKSSL_API void  SharkSslAesCtx_cbc_encrypt(SharkSslAesCtx *ctx, U8 vect[16], 
                                              U8 *input, U8 *output, U16 len);


SHARKSSL_API void  SharkSslAesCtx_cbc_decrypt(SharkSslAesCtx *ctx, U8 vect[16], 
                                              U8 *input, U8 *output, U16 len);
#if SHARKSSL_ENABLE_AES_CTR_MODE


SHARKSSL_API void  SharkSslAesCtx_ctr_mode(SharkSslAesCtx *ctx, U8 ctr[16], 
                                           U8 *input, U8 *output, U16 len);
#endif                          
#if SHARKSSL_ENABLE_AES_GCM

SHARKSSL_API void  SharkSslAesGcmCtx_constructor(SharkSslAesGcmCtx *ctx,
                                                 const U8 *key, U8 keyLen);

#define SharkSslAesGcmCtx_destructor(ctx) memset(ctx, 0, sizeof(SharkSslAesGcmCtx))


SHARKSSL_API int   SharkSslAesGcmCtx_encrypt(SharkSslAesGcmCtx *ctx, 
                                             const U8 vect[12], U8 tagout[16],
                                             const U8 *auth, U16 authlen,
                                             U8 *input, U8 *output, U16 len);



SHARKSSL_API int   SharkSslAesGcmCtx_decrypt(SharkSslAesGcmCtx *ctx, 
                                             const U8 vect[12], U8 tagin[16],
                                             const U8 *auth, U16 authlen,
                                             U8 *input, U8 *output, U16 len);
#endif
#if SHARKSSL_ENABLE_AES_CCM

SHARKSSL_API void  SharkSslAesCcmCtx_constructor(SharkSslAesCcmCtx *ctx,
                                                 const U8 *key, U8 keyLen, U8 tagLen);

#define SharkSslAesCcmCtx_destructor(ctx) memset(ctx, 0, sizeof(SharkSslAesCcmCtx))


SHARKSSL_API int   SharkSslAesCcmCtx_encrypt(SharkSslAesCcmCtx *ctx, 
                                             const U8 vect[12], U8 *tagout,
                                             const U8 *auth, U16 authlen,
                                             U8 *input, U8 *output, U16 len);



SHARKSSL_API int   SharkSslAesCcmCtx_decrypt(SharkSslAesCcmCtx *ctx, 
                                             const U8 vect[12], U8 *tagin,
                                             const U8 *auth, U16 authlen,
                                             U8 *input, U8 *output, U16 len);
#endif
#endif

#ifdef __cplusplus
}
#endif


#endif 
#define SHARKSSL_ALERT_LEVEL_WARNING               1


#define SHARKSSL_ALERT_LEVEL_FATAL                 2




#define SHARKSSL_ALERT_CLOSE_NOTIFY                0

#define SHARKSSL_ALERT_UNEXPECTED_MESSAGE          10

#define SHARKSSL_ALERT_BAD_RECORD_MAC              20

#define SHARKSSL_ALERT_DECRYPTION_FAILED           21

#define SHARKSSL_ALERT_RECORD_OVERFLOW             22

#define SHARKSSL_ALERT_DECOMPRESSION_FAILURE       30

#define SHARKSSL_ALERT_HANDSHAKE_FAILURE           40

#define SHARKSSL_ALERT_NO_CERTIFICATE              41  

#define SHARKSSL_ALERT_BAD_CERTIFICATE             42

#define SHARKSSL_ALERT_UNSUPPORTED_CERTIFICATE     43

#define SHARKSSL_ALERT_CERTIFICATE_REVOKED         44

#define SHARKSSL_ALERT_CERTIFICATE_EXPIRED         45

#define SHARKSSL_ALERT_CERTIFICATE_UNKNOWN         46

#define SHARKSSL_ALERT_ILLEGAL_PARAMETER           47

#define SHARKSSL_ALERT_UNKNOWN_CA                  48

#define SHARKSSL_ALERT_ACCESS_DENIED               49

#define SHARKSSL_ALERT_DECODE_ERROR                50

#define SHARKSSL_ALERT_DECRYPT_ERROR               51

#define SHARKSSL_ALERT_EXPORT_RESTRICTION          60

#define SHARKSSL_ALERT_PROTOCOL_VERSION            70

#define SHARKSSL_ALERT_INSUFFICIENT_SECURITY       71

#define SHARKSSL_ALERT_INTERNAL_ERROR              80

#define SHARKSSL_ALERT_USER_CANCELED               90

#define SHARKSSL_ALERT_NO_RENEGOTIATION            100

#define SHARKSSL_ALERT_UNKNOWN_PSK_IDENTITY        115

  
  


#define TLS_NULL_WITH_NULL_NULL                    0x0000
#define TLS_RSA_WITH_NULL_MD5                      0x0001
#define TLS_RSA_WITH_NULL_SHA                      0x0002
#define TLS_RSA_WITH_RC4_128_MD5                   0x0004
#define TLS_RSA_WITH_RC4_128_SHA                   0x0005
#define TLS_RSA_WITH_DES_CBC_SHA                   0x0009
#define TLS_RSA_WITH_3DES_EDE_CBC_SHA              0x000A
#define TLS_DHE_RSA_WITH_DES_CBC_SHA               0x0015
#define TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA          0x0016
#define TLS_RSA_WITH_AES_128_CBC_SHA               0x002F
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA           0x0033
#define TLS_RSA_WITH_AES_256_CBC_SHA               0x0035
#define TLS_DHE_RSA_WITH_AES_256_CBC_SHA           0x0039
#define TLS_RSA_WITH_NULL_SHA256                   0x003B
#define TLS_RSA_WITH_AES_128_CBC_SHA256            0x003C
#define TLS_RSA_WITH_AES_256_CBC_SHA256            0x003D
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA256        0x0067
#define TLS_DHE_RSA_WITH_AES_256_CBC_SHA256        0x006B
#define TLS_PSK_WITH_RC4_128_SHA                   0x008A
#define TLS_PSK_WITH_3DES_EDE_CBC_SHA              0x008B
#define TLS_PSK_WITH_AES_128_CBC_SHA               0x008C
#define TLS_PSK_WITH_AES_256_CBC_SHA               0x008D
#define TLS_RSA_WITH_AES_128_GCM_SHA256            0x009C
#define TLS_RSA_WITH_AES_256_GCM_SHA384            0x009D
#define TLS_DHE_RSA_WITH_AES_128_GCM_SHA256        0x009E
#define TLS_DHE_RSA_WITH_AES_256_GCM_SHA384        0x009F
#define TLS_ECDH_ECDSA_WITH_NULL_SHA               0xC001
#define TLS_ECDH_ECDSA_WITH_RC4_128_SHA            0xC002
#define TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA       0xC003
#define TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA        0xC004
#define TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA        0xC005
#define TLS_ECDHE_ECDSA_WITH_NULL_SHA              0xC006
#define TLS_ECDHE_ECDSA_WITH_RC4_128_SHA           0xC007
#define TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA      0xC008
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA       0xC009
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA       0xC00A
#define TLS_ECDH_RSA_WITH_NULL_SHA                 0xC00B
#define TLS_ECDH_RSA_WITH_RC4_128_SHA              0xC00C
#define TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA         0xC00D
#define TLS_ECDH_RSA_WITH_AES_128_CBC_SHA          0xC00E
#define TLS_ECDH_RSA_WITH_AES_256_CBC_SHA          0xC00F
#define TLS_ECDHE_RSA_WITH_NULL_SHA                0xC010
#define TLS_ECDHE_RSA_WITH_RC4_128_SHA             0xC011
#define TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA        0xC012
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA         0xC013
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA         0xC014
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256    0xC023
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384    0xC024
#define TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256     0xC025
#define TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384     0xC026
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256      0xC027
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384      0xC028
#define TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256       0xC029
#define TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384       0xC02A
#define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256    0xC02B
#define TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384    0xC02C
#define TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256     0xC02D
#define TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384     0xC02E
#define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256      0xC02F
#define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384      0xC030
#define TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256       0xC031
#define TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384       0xC032
#define TLS_RSA_WITH_AES_128_CCM                   0xC09C
#define TLS_RSA_WITH_AES_256_CCM                   0xC09D
#define TLS_DHE_RSA_WITH_AES_128_CCM               0xC09E
#define TLS_DHE_RSA_WITH_AES_256_CCM               0xC09F
#define TLS_RSA_WITH_AES_128_CCM_8                 0xC0A0
#define TLS_RSA_WITH_AES_256_CCM_8                 0xC0A1
#define TLS_DHE_RSA_WITH_AES_128_CCM_8             0xC0A2
#define TLS_DHE_RSA_WITH_AES_256_CCM_8             0xC0A3





#define SHARKSSL_PROTOCOL_UNKNOWN                  0x00

#define SHARKSSL_PROTOCOL_SSL_3_0                  0x30

#define SHARKSSL_PROTOCOL_TLS_1_0                  0x31

#define SHARKSSL_PROTOCOL_TLS_1_1                  0x32 

#define SHARKSSL_PROTOCOL_TLS_1_2                  0x33

  


#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
#ifndef BA_API  
#define BA_API SHARKSSL_API
typedef U8 BaBool;
#ifdef _SHARKSSL_C_
#define SingleListCode 1
#endif
#endif

#ifndef _SingleList_h
#define _SingleList_h








struct SingleList; 
struct SingleListEnumerator;


typedef struct SingleLink
{
#ifdef __cplusplus
      SingleLink();
      SingleLink* getNext();
   private:
      friend struct SingleList;
      friend struct SingleListEnumerator;
#endif
      struct SingleLink* next;
} SingleLink;
#define SingleLink_constructor(o) ((SingleLink*)(o))->next = 0
#define SingleLink_getNext(o) ((SingleLink*)(o))->next
#define SingleLink_isLinked(o) \
   (((SingleLink*)o)->next ? TRUE : FALSE) 

#ifdef __cplusplus
inline SingleLink::SingleLink() {SingleLink_constructor(this);}
inline SingleLink* SingleLink::getNext() {return SingleLink_getNext(this);}
#endif


typedef struct SingleList
{
#ifdef __cplusplus
      SingleList();
      void insertLast(SingleLink* link);
      SingleLink* removeFirst();
      SingleLink* peekFirst();
      bool isEmpty();
      bool isLast(SingleLink* link);
   private:
      friend struct SingleListEnumerator;
#endif
      SingleLink link;   
      SingleLink* last;
} SingleList;

#define SingleList_insertLast(o, linkMA) do \
{ \
   baAssert((SingleLink*)(linkMA) != (SingleLink*)(o)); \
   baAssert(((SingleLink*)(linkMA))->next == 0); \
   (o)->last->next = (SingleLink*)(linkMA); \
   (o)->last = (SingleLink*)(linkMA); \
   ((SingleLink*)(linkMA))->next = (SingleLink*)(o); \
} while(0)

#define SingleList_peekFirst(o) ((o)->link.next == (SingleLink*)(o) ? 0 : (o)->link.next)

#define SingleList_isEmpty(o) ((o)->link.next == (SingleLink*)(o))
#define SingleList_isLast(o, n) ((n)->next == (SingleLink*)(o))

#ifdef __cplusplus
extern "C" {
#endif
BA_API void SingleList_constructor(SingleList* o);
BA_API SingleLink* SingleList_removeFirst(SingleList* o);
#ifdef __cplusplus
}
inline
SingleList::SingleList() { SingleList_constructor(this); }
inline void
SingleList::insertLast(SingleLink* link) { SingleList_insertLast(this, link); }
inline SingleLink*
SingleList::peekFirst() { return SingleList_peekFirst(this); }
inline bool
SingleList::isEmpty() { return SingleList_isEmpty(this); }
inline bool
SingleList::isLast(SingleLink* link) { return SingleList_isLast(this,link); }
inline SingleLink*
SingleList::removeFirst() { return SingleList_removeFirst(this); }
#endif


typedef struct SingleListEnumerator
{
#ifdef __cplusplus
      SingleListEnumerator(){}
      SingleListEnumerator(SingleList* list);
      SingleLink* getElement();
      SingleLink* nextElement();
      SingleLink* removeElement();
      int insertBefore(SingleLink* l);
   private:
#endif
      SingleList* list;
      SingleLink* prevElement;
      SingleLink* curElement;
} SingleListEnumerator;

#define SingleListEnumerator_constructor(o, listMA) do \
{ \
   (o)->list = listMA; \
   (o)->prevElement = (SingleLink*)listMA; \
   (o)->curElement = SingleList_isEmpty(listMA) ? 0 : (o)->list->link.next; \
} while(0)

#define SingleListEnumerator_getElement(o) (o)->curElement

#define SingleListEnumerator_nextElement(o) \
   ((o)->curElement ? ( \
      (o)->prevElement = (o)->prevElement->next, \
      (o)->curElement = (o)->curElement == (o)->list->last ? 0 : (o)->curElement->next, \
      (o)->curElement \
    ) : 0)

#ifdef __cplusplus
extern "C" {
#endif
BA_API int SingleListEnumerator_insertBefore(
   SingleListEnumerator*, SingleLink*);
BA_API SingleLink* SingleListEnumerator_removeElement(SingleListEnumerator* o);
#ifdef __cplusplus
}
inline SingleListEnumerator::SingleListEnumerator(SingleList* list) {
   SingleListEnumerator_constructor(this, list); }
inline SingleLink*
SingleListEnumerator::removeElement() {
   return SingleListEnumerator_removeElement(this); }
inline SingleLink*
SingleListEnumerator::getElement() {return SingleListEnumerator_getElement(this);}
inline SingleLink*
SingleListEnumerator::nextElement() {return SingleListEnumerator_nextElement(this); }
inline int SingleListEnumerator::insertBefore(SingleLink* l) {
   return SingleListEnumerator_insertBefore(this, l); }
#endif


#endif 


#if defined(SingleListCode) && ! defined(SingleListCodeIncluded)
#define SingleListCodeIncluded

BA_API void
SingleList_constructor(SingleList* o)
{
   SingleLink_constructor((SingleLink*)o);
   o->last = ((SingleLink*)o);
   o->last->next = ((SingleLink*)o);
   o->link.next = ((SingleLink*)o);
}


BA_API int
SingleListEnumerator_insertBefore(SingleListEnumerator* o, SingleLink* l)
{
   if(l->next)
      return -1;

   if(SingleList_isEmpty(o->list))
      SingleList_insertLast(o->list, l);
   else
   {
      l->next = o->prevElement->next;
      o->prevElement->next = l;
   }
   o->prevElement = l;
   return 0;
}


BA_API SingleLink*
SingleListEnumerator_removeElement(SingleListEnumerator* o)
{
   if(o->curElement)
   {
      
      SingleLink* cur = o->curElement;
      
      if(cur == o->list->last)
      {
         o->curElement = 0;
         o->list->last = o->prevElement;
         o->prevElement->next = (SingleLink*)o->list;
      }
      else
      {
         o->curElement =  o->curElement->next;
         o->prevElement->next = o->curElement;
      }
      cur->next = 0;
   }
   return o->curElement;
}


BA_API SingleLink*
SingleList_removeFirst(SingleList* o)
{
   SingleLink* link2Remove;
   link2Remove = o->link.next;
   if(o->link.next == o->last)
   {
      if(o->link.next == (SingleLink*)o)
         return 0;
      o->link.next = o->last = (SingleLink*)o;
   }
   else
      o->link.next = o->link.next->next;
   link2Remove->next = 0;
   return link2Remove;
}

#endif 
#endif


#if SHARKSSL_ENABLE_SESSION_CACHE




typedef struct SharkSslSession SharkSslSession;

  

#ifndef _DOXYGEN
typedef struct SharkSslSessionCache
{
   SharkSslSession *cache;
   ThreadMutexBase  cacheMutex;
   U16 cacheSize;
} SharkSslSessionCache;
#endif
#endif





typedef enum
{
   SharkSsl_Unspecified,  
   SharkSsl_Server,       
   SharkSsl_Client        
} SharkSsl_Role;

 


#if (SHARKSSL_ENABLE_RSA || (SHARKSSL_ENABLE_ECDSA))



typedef const U8 *SharkSslCert;

#if SHARKSSL_ENABLE_CA_LIST

typedef const U8 *SharkSslCAList;
#endif

 
#endif

#ifndef _DOXYGEN
struct SharkSsl;
#endif



#ifndef _DOXYGEN
struct SharkSslIntf;
typedef void (*SharkSslIntf_Terminate)(struct SharkSslIntf* o,
                                       struct SharkSsl* ssl); 
typedef struct SharkSslIntf
{
   SharkSslIntf_Terminate terminate;
} SharkSslIntf;
#define SharkSslIntf_constructor(o,terminateFunc) (o)->terminate=terminateFunc
#endif





typedef struct SharkSslCon SharkSslCon;



typedef struct
SharkSsl
{
#ifdef __cplusplus
   void *operator new(size_t s) { return ::baMalloc(s); }
   void operator delete(void* d) { if(d) ::baFree(d); }
   void *operator new(size_t, void *place) { return place; }
   void operator delete(void*, void *) { }

   SharkSsl() {};

   SharkSsl(SharkSsl_Role role,
            U16 cacheSize         = 0,
            U16 inBufStartSize    = 4096,
            U16 outBufSize        = 4096
            );

   ~SharkSsl();
   SharkSslCon *createCon(void);
   U8 setCAList(SharkSslCAList caList);
   U8 addCertificate(SharkSslCert cert);
   void terminateCon(SharkSslCon *sslCon);
#endif
   #if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_SSL_CLIENT_CODE)
   SharkSsl_Role role;
   #endif
   U16 outBufSize;
   U16 inBufStartSize;
   U16 nCon;
   #if (SHARKSSL_ENABLE_RSA || (SHARKSSL_ENABLE_ECDSA))
   SingleList certList;
   #if SHARKSSL_ENABLE_CA_LIST
   SharkSslCAList caList;
   #endif
   #endif
   #if SHARKSSL_ENABLE_SESSION_CACHE
   SharkSslSessionCache sessionCache;
   
   SharkSslIntf* intf;
   #endif
} SharkSsl;

 




typedef enum
{
   
   SharkSslCon_Error = 1, 

   
   SharkSslCon_AllocationError,

   
   SharkSslCon_Decrypted,

   
   SharkSslCon_Handshake,

   
   SharkSslCon_NeedMoreData,

   
   SharkSslCon_AlertSend,

   
   SharkSslCon_AlertRecv,

   
   SharkSslCon_Encrypted,

   
   SharkSslCon_HandshakeNotComplete,

   
   SharkSslCon_Certificate,

   
   SharkSslCon_CertificateError

} SharkSslCon_RetVal;

 

#if (SHARKSSL_ENABLE_RSA || (SHARKSSL_ENABLE_ECDSA))




typedef struct SharkSslCertDN
{
   U8 *countryName; 
   U8 *province;  
   U8 *locality;  
   U8 *organization; 
   U8 *unit; 
   
   U8 *commonName;
} SharkSslCertDN;



typedef struct SharkSslCertInfo
{
     
   U16 snLen;

   
   U8  version; 

   
   U8 CAflag;

   
   U8 *sn;

   
   U8 *timeFrom;

   
   U8 *timeTo;

   
   SharkSslCertDN issuer;

   
   SharkSslCertDN subject;

   
   U8 *subjectAltDNSNames;

   
   struct SharkSslCertInfo *parent;
} SharkSslCertInfo;

  
#endif




#ifdef __cplusplus
extern "C" {
#endif


SHARKSSL_API void  SharkSsl_constructor(
                      SharkSsl *o,
                      SharkSsl_Role role,
                      U16 cacheSize,
                      U16 inBufStartSize,
                      U16 outBufSize
                      );


SHARKSSL_API void  SharkSsl_destructor(SharkSsl *o);



SharkSslCon *SharkSsl_createCon(SharkSsl *o);



void SharkSsl_terminateCon(const SharkSsl *o, SharkSslCon* con);


#if SHARKSSL_ENABLE_SESSION_CACHE


SHARKSSL_API U16   SharkSsl_getCacheSize(SharkSsl *o);

#define SharkSsl_setIntf(o, sharkSslIntf) (o)->intf=sharkSslIntf
#define SharkSsl_getIntf(o) (o)->intf

#endif


 
#define SharkSslCon_terminate(o) SharkSsl_terminateCon(0, o)




SharkSslCon_RetVal SharkSslCon_decrypt(SharkSslCon *o, U16 readLen);



SharkSslCon_RetVal SharkSslCon_encrypt(SharkSslCon *o, U8 *buf, U16 maxLen);



U8 SharkSslCon_isHandshakeComplete(SharkSslCon *o);



U8  SharkSslCon_encryptMore(SharkSslCon *o);



U8  SharkSslCon_decryptMore(SharkSslCon *o);


U8 *SharkSslCon_getBuf(SharkSslCon *o);



U16 SharkSslCon_getBufLen(SharkSslCon *o);


U16 SharkSslCon_copyDecData(SharkSslCon *o, U8 *buf, U16 maxLen);



SHARKSSL_API U16 SharkSslCon_getDecData(SharkSslCon *o, U8 **bufPtr);



U8 *SharkSslCon_getHandshakeData(SharkSslCon *o);



U16 SharkSslCon_getHandshakeDataLen(SharkSslCon *o);



U8 *SharkSslCon_getEncData(SharkSslCon *o);



U16 SharkSslCon_getEncDataLen(SharkSslCon *o);



U8 *SharkSslCon_getEncBufPtr(SharkSslCon *o);



U16 SharkSslCon_getEncBufSize(SharkSslCon *o);



U8  SharkSslCon_getAlertLevel(SharkSslCon *o);



U8  SharkSslCon_getAlertDescription(SharkSslCon *o);



#define SharkSslCon_getAlertData(o)    SharkSslCon_getEncData(o)



#define SharkSslCon_getAlertDataLen(o) SharkSslCon_getEncDataLen(o)

  

#if SHARKSSL_ENABLE_INFO_API


SHARKSSL_API U16 SharkSslCon_getCiphersuite(SharkSslCon *o);


SHARKSSL_API U8  SharkSslCon_getProtocol(SharkSslCon *o);

#endif

#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
#if (SHARKSSL_SSL_CLIENT_CODE && SHARKSSL_ENABLE_CLIENT_AUTH)

U8  SharkSslCon_certificateRequested(SharkSslCon *o);
#endif


SHARKSSL_API SharkSslCertInfo  *SharkSslCon_getCertInfo(SharkSslCon *o);



SHARKSSL_API U8 SharkSsl_addCertificate(SharkSsl *o, SharkSslCert cert);

#if SHARKSSL_ENABLE_CA_LIST


SHARKSSL_API U8  SharkSsl_setCAList(SharkSsl *o, SharkSslCAList caList);


SHARKSSL_API U8  SharkSslCon_trustedCA(SharkSslCon *o);

U8  SharkSslCon_isCAListEmpty(SharkSslCon *o);
#endif  

#if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_RSA)

U8  SharkSslCon_favorRSA(SharkSslCon *o);
#endif  
#endif  

#if SHARKSSL_SSL_CLIENT_CODE 
U8  SharkSslCon_selectProtocol(SharkSslCon *o, U8 protocol);
#endif



#if SHARKSSL_ENABLE_SESSION_CACHE


SHARKSSL_API U8    SharkSslSession_release(SharkSslSession *o, SharkSsl *s);
#if SHARKSSL_SSL_CLIENT_CODE 


SHARKSSL_API SharkSslSession *SharkSslCon_acquireSession(SharkSslCon *o);



SHARKSSL_API U8    SharkSslCon_resumeSession(SharkSslCon *o, SharkSslSession *s); 


SHARKSSL_API U32   SharkSslSession_getLatestAccessTime(SharkSslSession *o);
#endif
#endif

 

#if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH && (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA))
U8 SharkSslCon_requestClientCert(SharkSslCon *o, const void *caList);
#endif

#if ((SHARKSSL_SSL_SERVER_CODE || SHARKSSL_SSL_CLIENT_CODE) && \
     SHARKSSL_ENABLE_SELECT_CIPHERSUITE)
SHARKSSL_API U8 SharkSslCon_selectCiphersuite(SharkSslCon *o, U16 cipherSuite); 
#endif

#if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_SECURE_RENEGOTIATION)
U8 SharkSslCon_renegotiate(SharkSslCon *o);
#endif

  


#if SHARKSSL_ENABLE_PEM_API




typedef enum
{
   
   SHARKSSL_PEM_OK = 0,

   
   SHARKSSL_PEM_OK_PUBLIC = 1,

   
   SHARKSSL_PEM_ALLOCATION_ERROR = - 3000,

   
   SHARKSSL_PEM_KEY_PARSE_ERROR,

   
   SHARKSSL_PEM_KEY_WRONG_IV,

   
   SHARKSSL_PEM_KEY_WRONG_LENGTH,

   
   SHARKSSL_PEM_KEY_PASSPHRASE_REQUIRED,

   
   SHARKSSL_PEM_KEY_UNRECOGNIZED_FORMAT,

   
   SHARKSSL_PEM_KEY_UNSUPPORTED_FORMAT,

   
   SHARKSSL_PEM_KEY_UNSUPPORTED_MODULUS_LENGTH,

   
   SHARKSSL_PEM_KEY_UNSUPPORTED_ENCRYPTION_TYPE,

   
   SHARKSSL_PEM_KEY_CERT_MISMATCH,

   
   SHARKSSL_PEM_CERT_UNRECOGNIZED_FORMAT,

   
   SHARKSSL_PEM_CERT_UNSUPPORTED_TYPE,

   
   SHARKSSL_PEM_KEY_UNSUPPORTED_VERSION
} sharkssl_PEM_RetVal;



SHARKSSL_API sharkssl_PEM_RetVal sharkssl_PEM(
   const char *certPEM, const char *keyPEM, 
   const char *passphrase, SharkSslCert *sharkSslCert);

 
#endif

#if SHARKSSL_ENABLE_RSA_API




typedef SharkSslCert SharkSslRSAKey;

#if SHARKSSL_ENABLE_PEM_API

SharkSslRSAKey sharkssl_PEM_to_RSAKey(
   const char *PEMKey, const char *passphrase);


void SharkSslRSAKey_free(SharkSslRSAKey key);
#endif



U16 SharkSslRSAKey_size(SharkSslRSAKey key);


#define SHARKSSL_RSA_NO_PADDING      0


#define SHARKSSL_RSA_PKCS1_PADDING   1


int sharkssl_RSA_public_encrypt(
   U16 len, U8 *in, U8 *out, SharkSslRSAKey key, U8 padding);



int sharkssl_RSA_private_decrypt(
   U16 len, U8 *in, U8 *out, SharkSslRSAKey privkey, U8 padding);



int sharkssl_RSA_private_encrypt(
   U16 len, U8 *in, U8 *out, SharkSslRSAKey privkey, U8 padding);



int sharkssl_RSA_public_decrypt(
   U16 len, U8 *in, U8 *out, SharkSslRSAKey key, U8 padding);

 
#endif





#if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_ENABLE_CERTSTORE_API)




#ifndef BA_API  
#define BA_API SHARKSSL_API
typedef U8 BaBool;
#endif
typedef struct SharkSslCertStore
{
      DoubleList certList;
      U16 elements; 
} SharkSslCertStore;


SHARKSSL_API void  SharkSslCertStore_constructor(SharkSslCertStore *o);


SHARKSSL_API void  SharkSslCertStore_destructor(SharkSslCertStore* o);


#define            SharkSslCertStore_release(o) SharkSslCertStore_destructor(o)


SHARKSSL_API U16   SharkSslCertStore_add(
   SharkSslCertStore *o, const char *cert, U32 certlen);


SHARKSSL_API U8  SharkSslCertStore_assemble(
   SharkSslCertStore *o, SharkSslCAList *outList);


#define SharkSslCAList_free(list) baFree((void*)list)

  
#endif  





#ifdef __cplusplus
}


inline SharkSsl::SharkSsl(
   SharkSsl_Role role, U16 cacheSize, U16 inBufStartSize, U16 outBufSize) {
   SharkSsl_constructor(this, role, cacheSize, inBufStartSize, outBufSize);
}
inline SharkSsl::~SharkSsl() {
   SharkSsl_destructor(this);
}
inline SharkSslCon *SharkSsl::createCon(void) {
   return SharkSsl_createCon(this);
}
inline void SharkSsl::terminateCon(SharkSslCon *sslCon) {
   SharkSsl_terminateCon(this, sslCon);
}

inline U8 SharkSsl::setCAList(SharkSslCAList caList) {
   return SharkSsl_setCAList(this, caList);
}
inline U8 SharkSsl::addCertificate(SharkSslCert cert) {
   return SharkSsl_addCertificate(this, cert);

}
#endif  


#endif


 
#ifndef _balua_h
#define _balua_h

#ifdef __cplusplus
extern "C" {
#endif




#ifndef lua_h
#define lua_h


#ifndef lconfig_h

#define BA_HAS_ANSI_IO


#ifndef NO_BA_SERVER
#undef snprintf
#undef sprintf
#define snprintf nonosnprintf
#define sprintf nonosprintf
#undef snprintf
#undef sprintf
#define snprintf basnprintf
#define sprintf basprintf
extern int basnprintf(char* buf, int len, const char* fmt, ...);
extern int basprintf(char* buf, const char* fmt, ...);
#endif




#ifndef lconfig_h
#define lconfig_h




#ifndef __HttpTrace_h
#define __HttpTrace_h







#ifndef __HttpServer_h
#define __HttpServer_h


#ifndef __HttpConnection_h
#define __HttpConnection_h



#ifndef __SoDispCon_h
#define __SoDispCon_h



#ifndef _SoDisp_h
#define _SoDisp_h

struct SoDispCon;
struct HttpServer;





typedef struct SoDisp
{
#ifdef __cplusplus

      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      SoDisp(ThreadMutex* mutex);

      
      void mutexSet();

      
      void mutexRelease();

      
      ThreadMutex* getMutex();

      void addConnection(SoDispCon* con);
      void activateRec(SoDispCon* con);
      void deactivateRec(SoDispCon* con);
      void activateSend(SoDispCon* con);
      void deactivateSend(SoDispCon* con);
      void removeConnection(SoDispCon* con);

      
      void setExit();

      
      void run(S32 timeout=-1);
#ifdef OSE
      union SIGNAL* receive(S32 timeout=-1, SIGSELECT* sel=0);
#endif
#endif
      DISPATCHER_DATA;
      ThreadMutex* mutex;
      void* timeoutO;
      BaBool doExit;
} SoDisp;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void SoDisp_constructor(SoDisp* o, ThreadMutex* mutex);
#define SoDisp_destructor(o)
BA_API void SoDisp_addConnection(SoDisp* o, struct SoDispCon* con);
BA_API void SoDisp_activateRec(SoDisp* o, struct SoDispCon* con);
BA_API void SoDisp_deactivateRec(SoDisp* o, struct SoDispCon* con);
#ifdef NO_ASYNCH_RESP
#define SoDisp_activateSend(o, con)
#define SoDisp_deactivateSend(o, con)
#else
BA_API void SoDisp_activateSend(SoDisp* o, struct SoDispCon* con);
BA_API void SoDisp_deactivateSend(SoDisp* o, struct SoDispCon* con);
#endif
BA_API void SoDisp_removeConnection(SoDisp* o, struct SoDispCon* con);
BA_API void SoDisp_run(SoDisp* o, S32 timeout);
#ifdef OSE
union SIGNAL* SoDisp_receive(SoDisp* o, S32 time, SIGSELECT* sel);
#endif
#define SoDisp_getMutex(o) ((o) ? ((o)->mutex) : 0)
#define SoDisp_mutexSet(o) ThreadMutex_set((o)->mutex)
#define SoDisp_mutexRelease(o) ThreadMutex_release((o)->mutex)
#define SoDisp_setExit(o) (o)->doExit=TRUE

BA_API void SoDisp_newCon(SoDisp*, struct SoDispCon*);

#ifdef __cplusplus
}
inline SoDisp::SoDisp(ThreadMutex* mutex) {
   SoDisp_constructor(this, mutex); }
inline void SoDisp::addConnection(SoDispCon* con) {
   SoDisp_addConnection(this, con); }
inline void SoDisp::activateRec(SoDispCon* con) {
   SoDisp_activateRec(this, con); }
inline void SoDisp::deactivateRec(SoDispCon* con) {
   SoDisp_deactivateRec(this, con); }
inline void SoDisp::activateSend(SoDispCon* con) {
   SoDisp_activateSend(this, con); }
inline void SoDisp::deactivateSend(SoDispCon* con) {
   SoDisp_deactivateSend(this, con); }
inline void SoDisp::removeConnection(SoDispCon* con) {
   SoDisp_removeConnection(this, con); }
inline void SoDisp::run(S32 timeout) {
   SoDisp_run(this, timeout); }
inline ThreadMutex* SoDisp::getMutex() {
   return SoDisp_getMutex(this); }
#ifdef OSE
inline union SIGNAL* SoDisp::receive(S32 time, SIGSELECT* sel) {
   return SoDisp_receive(this, time, sel); }
#endif
inline void SoDisp::mutexSet() { SoDisp_mutexSet(this); }
inline void SoDisp::mutexRelease() {SoDisp_mutexRelease(this);}
inline void SoDisp::setExit() { SoDisp_setExit(this); }

#endif

void SoDisp_setTimeout(
   SoDisp* o, BaTime t, void (*cb)(void* object), void* object);


#endif
struct SharkSslCon;






typedef enum {
   SoDispCon_ExTypeRead=1,
   SoDispCon_ExTypeWrite,
   SoDispCon_GetSharkSslCon,
   SoDispCon_ExTypeClose,
   SoDispCon_ExTypeMoveCon,
   SoDispCon_ExTypeAllocAsynchBuf,
   SoDispCon_ExTypeAsyncReady,
   SoDispCon_ExTypeIdle
} SoDispCon_ExType;



 
struct SoDispCon;
struct SharkSsl;

typedef int (*SoDispCon_Execute)(
   struct SoDispCon* con, ThreadMutex* m,SoDispCon_ExType s,void* d1,int d2);


typedef void (*SoDispCon_DispRecEv)(struct SoDispCon* con);
typedef void (*SoDispCon_DispSendEv)(struct SoDispCon* con);



typedef struct SoDispCon
{
#ifdef __cplusplus
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      SoDispCon() {}

     
     bool isSecure();

      
     bool getSharkSslCon(SharkSslCon** sc);


      
      bool isValid();

      
      bool isIP6();

      
      int getPeerName(HttpSockaddr* addr,U16* port=0);

      
      int getSockName(HttpSockaddr* addr,U16* port=0);

      
      char* addr2String(HttpSockaddr* addr, char* buf, int len);

      
      bool cmpAddr(HttpSockaddr* addr2);

      
      void setTCPNoDelay(bool enable);
      
      
      struct SoDisp* getDispatcher();

      
      bool hasMoreData();

      
      bool dispatcherHasCon();

      
      bool recEvActive();

      
      bool sendEvActive();

      void setDispSendEvent(SoDispCon_DispSendEv ev);
      void setDispRecEvent(SoDispCon_DispRecEv ev);
      int readData(void* data, int len, bool relmutex=false);
      int setNonblocking();
      int setBlocking();
      int sendData(const void* data, int len);
      int asyncSend(int len);
      int sendChunkData(const void* data, int len);
      int asyncReady();
      void* allocAsynchBuf(int* size);
#endif
      CONNECTION_DISPATCHER_OBJ 

      
      void* sslData;
      SoDispCon_Execute exec;

      HttpSocket httpSocket;
      SoDispCon_DispRecEv dispRecEv;
      SoDispCon_DispSendEv dispSendEv;
      struct SoDisp* dispatcher;
      BaBool* sendTermPtr;
      BaBool* recTermPtr;
      U16 rtmo; 
      U8 dataBits;
      U8 isSending;
} SoDispCon;

#define SoDispCon_socketHasNonBlockDataBitMask 0x01
#define SoDispCon_hasMoreDataDataBitMask 0x02

#define SoDispCon_dispatcherHasConDataBitMask 0x04
#define SoDispCon_recEvActiveDataBitMask 0x08
#define SoDispCon_sendEvActiveDataBitMask 0x10
#define SoDispCon_isNonBlockingDataBitMask 0x20
#define SoDispCon_IP6DataBitMask 0x40

#define SoDispCon_setDispHasRecData(o)\
  ((o)->dataBits |= \
   (SoDispCon_hasMoreDataDataBitMask | SoDispCon_socketHasNonBlockDataBitMask))
#define SoDispCon_setDispatcherHasCon(o)\
  ((o)->dataBits |= SoDispCon_dispatcherHasConDataBitMask)
#define SoDispCon_setRecEvActive(o)\
  ((o)->dataBits |= SoDispCon_recEvActiveDataBitMask)
#define SoDispCon_setSendEvActive(o)\
  ((o)->dataBits |= SoDispCon_sendEvActiveDataBitMask)
#define SoDispCon_setIP6(o)\
  ((o)->dataBits |= SoDispCon_IP6DataBitMask)

#define SoDispCon_clearSocketHasNonBlockData(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_socketHasNonBlockDataBitMask)
#define SoDispCon_clearHasMoreData(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_hasMoreDataDataBitMask)
#define SoDispCon_clearDispatcherHasCon(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_dispatcherHasConDataBitMask)
#define SoDispCon_setRecEvInactive(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_recEvActiveDataBitMask)
#define SoDispCon_setSendEvInactive(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_sendEvActiveDataBitMask)
#define SoDispCon_clearIP6(o)\
  ((o)->dataBits &= ~(U8)SoDispCon_IP6DataBitMask)

#define SoDispCon_socketHasNonBlockData(o)\
  (((o)->dataBits & SoDispCon_socketHasNonBlockDataBitMask) ? TRUE : FALSE)
#define SoDispCon_hasMoreData(o)\
  (((o)->dataBits & SoDispCon_hasMoreDataDataBitMask) ? TRUE : FALSE)
#define SoDispCon_dispatcherHasCon(o)\
  (((o)->dataBits & SoDispCon_dispatcherHasConDataBitMask)?TRUE:FALSE)
#define SoDispCon_recEvActive(o)\
  (((o)->dataBits & SoDispCon_recEvActiveDataBitMask)?TRUE:FALSE)
#define SoDispCon_sendEvActive(o)\
  (((o)->dataBits & SoDispCon_sendEvActiveDataBitMask)?TRUE:FALSE)
#define SoDispCon_isNonBlocking(o)\
  (((o)->dataBits & SoDispCon_isNonBlockingDataBitMask) ?  TRUE : FALSE)
#ifndef SoDispCon_isIP6
#define SoDispCon_isIP6(o)\
  (((o)->dataBits & SoDispCon_IP6DataBitMask) ? TRUE : FALSE)
#endif
#define SoDispCon_isSecure(o) \
   ((o)->exec(o,0,SoDispCon_GetSharkSslCon,0,0) > 0)
#define SoDispCon_getSharkSslCon(o,sharkSslConPtrPtr) \
   (o)->exec(o,0,SoDispCon_GetSharkSslCon,sharkSslConPtrPtr,0)
#define SoDispCon_isValid(o) HttpSocket_isValid(&(o)->httpSocket)
#define SoDispCon_invalidate(o) HttpSocket_invalidate(&(o)->httpSocket)
#define SoDispCon_getDispatcher(o) (o)->dispatcher
#define SoDispCon_dispRecEvent(o) (o)->dispRecEv(o)
#define SoDispCon_dispSendEvent(o) (o)->dispSendEv(o)
#define SoDispCon_setDispSendEvent(o, dispSendEvFp) \
   (o)->dispSendEv=dispSendEvFp

#define SoDispCon_setDispRecEvent(o, dispRecEvFp) \
   (o)->dispRecEv=dispRecEvFp

#define SoDispCon_readData(o, data, len, relmutex) \
   (o)->exec(o, (relmutex) ? SoDisp_getMutex((o)->dispatcher) : 0, \
           SoDispCon_ExTypeRead,data,len)


#ifndef SoDispCon_newConnectionIsReady
#define SoDispCon_newConnectionIsReady(con)
#endif

BA_API int SoDispCon_getSharkAlert(SoDispCon* o, U8* alertLevel, U8* alertDescription);

#ifdef __cplusplus
extern "C" {
#endif
BA_API void SoDispCon_constructor(
   SoDispCon* o, struct SoDisp* dispatcher, SoDispCon_DispRecEv e);
BA_API int SoDispCon_upgrade(SoDispCon* o, struct SharkSsl* ssl,
                             const char* host, int port);
BA_API int SoDispCon_blockRead(SoDispCon* o,void* data,int len);
BA_API int SoDispCon_sendData(SoDispCon* o, const void* data, int len);
BA_API int SoDispCon_sendDataNT(SoDispCon* o, const void* data, int len);
BA_API int SoDispCon_sendChunkData(SoDispCon* o,const void* data, int len);
BA_API int SoDispCon_asyncReadyF(SoDispCon* o);
#define SoDispCon_asyncReady(o)\
   (o)->exec(o,SoDisp_getMutex((o)->dispatcher),\
             SoDispCon_ExTypeAsyncReady,0,0)
#define SoDispCon_asyncSend(o, len) \
   (o)->exec(o,SoDisp_getMutex((o)->dispatcher),\
             SoDispCon_ExTypeAsyncReady,0,len)
struct AllocatorIntf;

#ifndef __DOXYGEN__
typedef struct
{
      void* retVal;
      int size;
} AllocAsynchBufArgs;
#endif

BA_API void* SoDispCon_allocAsynchBuf(
        SoDispCon* o, int* size);
BA_API int SoDispCon_setNonblocking(SoDispCon* o);
BA_API int SoDispCon_setBlocking(SoDispCon* o);
BA_API int SoDispCon_peek(SoDispCon* o);
BA_API int SoDispCon_moveCon(SoDispCon* o, SoDispCon*  newCon);
#define SoDispCon_destructor(o) SoDispCon_zzCloseCon(o,1)
#define SoDispCon_hardClose(o) SoDispCon_zzCloseCon(o, 2)
#define SoDispCon_shutdown(o) SoDispCon_zzCloseCon(o, 1)
#define SoDispCon_closeCon(o) SoDispCon_zzCloseCon(o, 0)
#define SoDispCon_setReadTmo(o,timeout)  (o)->rtmo = (U16)((timeout)/50)
BA_API void SoDispCon_zzCloseCon(SoDispCon* o, int shutdown);
BA_API void SoDispCon_setTCPNoDelay(SoDispCon* o, int enable);
BA_API int SoDispCon_getPeerName(SoDispCon* o,HttpSockaddr* addr,U16* port);
BA_API int SoDispCon_getSockName(SoDispCon* o, HttpSockaddr* addr, U16* port);
BA_API char* SoDispCon_addr2String(
   SoDispCon* o, HttpSockaddr* addr, char* buf, int len);
BA_API BaBool SoDispCon_cmpAddr(SoDispCon* o, HttpSockaddr* addr2);
BA_API void SoDispCon_printSockErr(
   SoDispCon* o,const char* type,HttpSocket* s,int status);
#define SoDispCon_getId(o) HttpSocket_getId(&(o)->httpSocket)

int SoDispCon_platReadData(SoDispCon* o, ThreadMutex* m, BaBool* isTerminated,
                           void* data, int len);
#ifdef __cplusplus
}
inline int SoDispCon::readData(void* data, int len, bool relmutex) {
   return SoDispCon_readData(this, data, len, relmutex ? TRUE : FALSE); }
inline int SoDispCon::setNonblocking() {
   return SoDispCon_setNonblocking(this); }
inline int SoDispCon::setBlocking() {
   return SoDispCon_setBlocking(this); }
inline bool SoDispCon::isSecure() {
   return SoDispCon_isSecure(this) ? true : false; }
inline bool SoDispCon::getSharkSslCon(SharkSslCon** sc) {
   return SoDispCon_getSharkSslCon(this,sc) ? true : false; }
inline bool SoDispCon::isIP6() {
	return SoDispCon_isIP6(this) ? true : false; }
inline bool SoDispCon::isValid() {
	return SoDispCon_isValid(this) ? true : false; }
inline int SoDispCon::getPeerName(HttpSockaddr* addr,U16* port){
   return SoDispCon_getPeerName(this,addr,port); }
inline int SoDispCon::getSockName(HttpSockaddr* addr,U16* port){
   return SoDispCon_getSockName(this, addr,port); }
inline char* SoDispCon::addr2String(HttpSockaddr* addr,char* buf,int len){
   return SoDispCon_addr2String(this, addr, buf, len); }
inline bool SoDispCon::cmpAddr(HttpSockaddr* addr2) {
   return SoDispCon_cmpAddr(this, addr2) ? true : false;
}
inline void SoDispCon::setTCPNoDelay(bool enable) {
   SoDispCon_setTCPNoDelay(this, enable); }
inline bool SoDispCon::hasMoreData() {
   return SoDispCon_hasMoreData(this) ? true : false;
}
inline bool SoDispCon::dispatcherHasCon() {
   return SoDispCon_dispatcherHasCon(this) ? true : false; }
inline bool SoDispCon::recEvActive() {
   return SoDispCon_recEvActive(this) ? true : false; }
inline bool SoDispCon::sendEvActive() {
   return SoDispCon_sendEvActive(this) ? true : false; }
inline struct SoDisp* SoDispCon::getDispatcher() {
   return SoDispCon_getDispatcher(this); }
inline void SoDispCon::setDispSendEvent(SoDispCon_DispSendEv ev) {
   SoDispCon_setDispSendEvent(this, ev); }
inline void SoDispCon::setDispRecEvent(SoDispCon_DispRecEv ev) {
   SoDispCon_setDispRecEvent(this, ev); }
inline int SoDispCon::sendData(const void* data, int len) {
   return SoDispCon_sendData(this,data, len); }
inline int SoDispCon::asyncSend(int len) {
   return SoDispCon_asyncSend(this, len); }
inline int SoDispCon::sendChunkData(const void* data, int len) {
   return SoDispCon_sendChunkData(this, data, len); }
inline int SoDispCon::asyncReady() {
   return SoDispCon_asyncReadyF(this) ? true : false; }
inline void* SoDispCon::allocAsynchBuf(int* size){
   return SoDispCon_allocAsynchBuf(this, size); }

#endif


#endif
struct HttpServer;
struct HttpConnection;





typedef enum 
{ 
   HttpConnection_Free=0,        
   HttpConnection_Connected,   
   HttpConnection_Ready,       
   HttpConnection_Running,     
   HttpConnection_Moved,       
   HttpConnection_Terminated,   
   
   HttpConnection_HardClose
} HttpConnection_State;




#ifdef __cplusplus
typedef struct HttpConnection : public SoDispCon
{
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      HttpConnection() {}

      
      struct HttpServer* getServer();

      
      void setKeepAlive();

      
      void clearKeepAlive();
#else
typedef struct HttpConnection
{
      SoDispCon super;
#if 0
}
#endif
#endif
      struct HttpServer* server;
      struct HttpCommand* cmd;
      void* pushBackData;
      int pushBackDataSize;
      U8 state; 
      U8 keepAlive;
} HttpConnection;

#define HttpConnection_setKeepAlive(o) (o)->keepAlive=TRUE
#define HttpConnection_clearKeepAlive(o) (o)->keepAlive=FALSE
#define HttpConnection_keepAlive(o) (o)->keepAlive
#define HttpConnection_getState(o) (o)->state
#define HttpConnection_getServer(o) (o)->server
#define HttpConnection_getDispatcher(o) SoDispCon_getDispatcher((SoDispCon*)o)
#define HttpConnection_dispRecEvent(o) SoDispCon_dispRecEvent((SoDispCon*)o)
#define HttpConnection_newConnectionIsReady(con) \
  SoDispCon_newConnectionIsReady(con)

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpConnection_constructor(HttpConnection* o,
                                       struct HttpServer* server,
                                       struct SoDisp* dispatcher,
                                       SoDispCon_DispRecEv e);
BA_API void HttpConnection_setState(
   HttpConnection* o, HttpConnection_State state);
BA_API int HttpConnection_moveCon(HttpConnection* o, HttpConnection*  newCon);
int HttpConnection_sendChunkData6bOffs(
   HttpConnection* o,const void* data,int len);
BA_API void HttpConnection_destructor(HttpConnection* o);
BA_API int HttpConnection_pushBack(HttpConnection* o, const void* d, int s);
#define HttpConnection_isSecure(o)\
   SoDispCon_isSecure((SoDispCon*)o)
#define HttpConnection_isValid(o)\
   SoDispCon_isValid((SoDispCon*)o)
#define HttpConnection_sendData(o, data, len)\
   SoDispCon_sendData((SoDispCon*)o, data, len)
#define HttpConnection_sendDataNT(o, data, len)\
   SoDispCon_sendDataNT((SoDispCon*)o, data, len)
#define HttpConnection_sendChunkData(o,data, len)\
   SoDispCon_sendChunkData((SoDispCon*)o,data, len)
#define HttpConnection_allocAsynchBuf(o, sizePtr)\
   SoDispCon_allocAsynchBuf((SoDispCon*)o, sizePtr)
#define HttpConnection_asyncSend(o,len) SoDispCon_asyncSend((SoDispCon*)o,len)
#define HttpConnection_asyncReady(o) SoDispCon_asyncReady((SoDispCon*)o)
BA_API int HttpConnection_readData(HttpConnection* con, void* data, int len);
BA_API int HttpConnection_blockRead(HttpConnection* con, void* data, int len);
#define HttpConnection_setNonblocking(o)\
   SoDispCon_setNonblocking((SoDispCon*)o)
#define HttpConnection_setBlocking(o)\
   SoDispCon_setBlocking((SoDispCon*)o)
#define HttpConnection_peek(o)\
   SoDispCon_peek((SoDispCon*)o)
#define HttpConnection_setTCPNoDelay(o, enable)\
   SoDispCon_setTCPNoDelay((SoDispCon*)o, enable)
#define HttpConnection_getPeerName(o, addr,port)\
   SoDispCon_getPeerName((SoDispCon*)o, addr,port)
#define HttpConnection_getSockName(o, addr,port)\
   SoDispCon_getSockName((SoDispCon*)o, addr,port)
#define HttpConnection_addr2String(o, addr, buf, len)\
   SoDispCon_addr2String((SoDispCon*)o, addr, buf, len)
#define HttpConnection_cmpAddr(o, addr2)\
   SoDispCon_cmpAddr((SoDispCon*)o, addr2)
#define HttpConnection_recEvActive(o)\
   SoDispCon_recEvActive((SoDispCon*)o)
#define HttpConnection_sendEvActive(o)\
   SoDispCon_sendEvActive((SoDispCon*)o)
#define HttpConnection_hasMoreData(o)\
   (SoDispCon_hasMoreData((SoDispCon*)o) || (o)->pushBackData)
#define HttpConnection_dispatcherHasCon(o)\
   SoDispCon_dispatcherHasCon((SoDispCon*)o)
#define HttpConnection_setDispSendEvent(o, dispSendEvFp)\
   SoDispCon_setDispSendEvent((SoDispCon*)o, dispSendEvFp)
#ifdef __cplusplus
}
inline void HttpConnection::setKeepAlive() {
   HttpConnection_setKeepAlive(this);
}
inline void HttpConnection::clearKeepAlive() {
   HttpConnection_clearKeepAlive(this);
}
#endif


#endif


#ifndef __SplayTree_h
#define __SplayTree_h

typedef const void* SplayTreeKey;

typedef struct SplayTreeNode
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      SplayTreeNode(){} 
      SplayTreeNode(SplayTreeKey key);
      SplayTreeKey getKey();
#endif
      struct SplayTreeNode* left;
      struct SplayTreeNode* right;
      SplayTreeKey key;
} SplayTreeNode;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void SplayTreeNode_constructor(SplayTreeNode* o, SplayTreeKey key);
#define SplayTreeNode_getKey(o) (o)->key

#ifdef __cplusplus
}
inline SplayTreeNode::SplayTreeNode(SplayTreeKey key) {
   SplayTreeNode_constructor(this, key); }
inline SplayTreeKey SplayTreeNode::getKey() {
   return SplayTreeNode_getKey(this); }
#endif


typedef int (*SplayTree_Compare)(SplayTreeNode* n, SplayTreeKey k);
 
typedef int (*SplayTree_Iter)(void* o, SplayTreeNode* n);


typedef struct SplayTree
{
#ifdef __cplusplus
      SplayTree(){} 
      SplayTree(SplayTree_Compare compare);
      int insert(SplayTreeNode* n);
      SplayTreeNode* find(SplayTreeKey key);
      int remove(SplayTreeNode* n);
      SplayTreeNode* getRoot();
   private:
#endif
      SplayTreeNode* root;
      SplayTree_Compare compare;
} SplayTree;

#ifdef __cplusplus
extern "C" {
#endif
#define SplayTree_constructor(o, compareCB) do { \
   (o)->compare = compareCB; \
   (o)->root = 0; \
} while(0)
BA_API int SplayTree_insert(SplayTree* o, SplayTreeNode* n);
BA_API SplayTreeNode* SplayTree_find(SplayTree* o, SplayTreeKey key);
BA_API int SplayTree_remove(SplayTree* o, SplayTreeNode* n);
#define SplayTree_getRoot(o) (o)->root
BA_API int SplayTree_iterate(SplayTree* o, void* userObj, SplayTree_Iter i);
#ifdef __cplusplus
}
inline SplayTree::SplayTree(SplayTree_Compare compare) {
   SplayTree_constructor(this, compare); }
inline int SplayTree::insert(SplayTreeNode* n) {
   return SplayTree_insert(this, n); }
inline SplayTreeNode* SplayTree::find(SplayTreeKey key) {
   return SplayTree_find(this, key); }
inline int SplayTree::remove(SplayTreeNode* n) {
   return SplayTree_remove(this, n); }
inline SplayTreeNode* SplayTree::getRoot() {
   return SplayTree_getRoot(this); }
#endif


#endif


#ifndef __BufPrint_h
#define __BufPrint_h

#ifdef __cplusplus
#ifndef putc
#define putc noputc
#endif
#undef putc
#endif

struct BufPrint;

#ifdef __cplusplus
extern "C" {
#endif


BA_API int basprintf(char* buf, const char* fmt, ...);


BA_API int basnprintf(char* buf, int len, const char* fmt, ...);

#ifdef __cplusplus
#undef printf
}
#endif 




typedef int (*BufPrint_Flush)(struct BufPrint* o, int sizeRequired);


typedef struct BufPrint
{
#ifdef __cplusplus
      BufPrint() {}

      
      BufPrint(void* userData, BufPrint_Flush flush);

      
      void* getUserData();

      
      int vprintf(const char* fmt, va_list argList);

      
      int printf(const char* fmt, ...);

      
      int putc(int c);

      
      int write(const void* data, int len);

      
      int write(const char* buf);


      
      char* getBuf();

      
      U32 getBufSize();


      
      void erase();

      
      int flush();

      
      int b64Encode(const void* data, S32 slen);


      
      int jsonString(const char* str);
#endif
      BufPrint_Flush flushCB;
      void *userData;
      char* buf;
      int cursor;
      int bufSize;
}BufPrint;

#define BufPrint_putcMacro(o, c) do { \
   if((o)->cursor == (o)->bufSize) \
   { \
      if((o)->flushCB(o, 1)) \
         return -1; \
   } \
   (o)->buf[(o)->cursor++] = c; \
} while(0)

#ifdef __cplusplus
extern "C" {
#endif
#define BufPrint_getUserData(o) (o)->userData
#define BufPrint_erase(o) (o)->cursor=0
#define BufPrint_getBuf(o) (o)->buf
#define BufPrint_getBufSize(o) (o)->cursor
BA_API void BufPrint_constructor(
   BufPrint* o,void* userData,BufPrint_Flush flush);
#define BufPrint_destructor(o)
BA_API int BufPrint_vprintf(BufPrint* o, const char* fmt, va_list argList);
BA_API int BufPrint_printf(BufPrint* o, const char* fmt, ...);
BA_API int BufPrint_write(BufPrint* o, const void* data, int len);
BA_API int BufPrint_putc(BufPrint* o, int c);
BA_API int BufPrint_flush(BufPrint* o);
#define BufPrint_write2(o, data) BufPrint_write(o, data, -1)
BA_API int BufPrint_b64Encode(BufPrint* o, const void* source, S32 slen);
BA_API int BufPrint_jsonString(BufPrint* o, const char* str);
#ifdef __cplusplus
}
inline void* BufPrint::getUserData() {
   return BufPrint_getUserData(this);
}
inline BufPrint::BufPrint(void* userData, BufPrint_Flush flush) {
   BufPrint_constructor(this, userData,flush); }
inline int BufPrint::vprintf(const char* fmt, va_list argList) {
   return BufPrint_vprintf(this, fmt, argList); }
inline int BufPrint::printf(const char* fmt, ...) {
   int retv; va_list varg;
   va_start(varg, fmt);
   retv = BufPrint_vprintf(this, fmt, varg);
   va_end(varg);
   return retv;
}
inline char* BufPrint::getBuf() {
   return BufPrint_getBuf(this); }
inline U32 BufPrint::getBufSize() {
   return BufPrint_getBufSize(this); }
inline void BufPrint::erase() {
   BufPrint_erase(this); }
inline int BufPrint::putc(int c) {
   return BufPrint_putc(this, c); }
inline int BufPrint::write(const void* data, int len) {
   return BufPrint_write(this, data, len); }
inline int BufPrint::write(const char* data) {
   return BufPrint_write2(this, data); }
inline int BufPrint::flush() {
   return BufPrint_flush(this);
}
inline int BufPrint::b64Encode(const void* source, S32 slen){
   return BufPrint_b64Encode(this, source, slen);
}
inline int BufPrint::jsonString(const char* str){
   return BufPrint_jsonString(this, str);
}
#endif

 


#endif


#ifndef __IoIntf_h
#define __IoIntf_h
 
#define IOINTF_OK 0


#define IOINTF_EOF 1



#define IOINTF_INVALIDNAME -1


#define IOINTF_NOTFOUND -2


#define IOINTF_EXIST -3


#define IOINTF_ENOENT -4


#define IOINTF_NOACCESS -5


#define IOINTF_NOTEMPTY -6


#define IOINTF_NOSPACE -7


#define IOINTF_IOERROR -8


#define IOINTF_MEM -9

#define IOINTF_LOCKED -10



#define IOINTF_NOIMPLEMENTATION -50


#define IOINTF_BUFTOOSMALL -51



#define IOINTF_NOZIPLIB -100


#define IOINTF_NOTCOMPRESSED -101


#define IOINTF_ZIPERROR -102




#define IOINTF_NOAESLIB -200

 
#define IOINTF_AES_NO_SUPPORT -201

#define IOINTF_NO_PASSWORD -202


#define IOINTF_WRONG_PASSWORD -203


#define IOINTF_AES_WRONG_AUTH -204


#define IOINTF_AES_COMPROMISED -205

 

#ifndef __DOXYGEN__
struct IoIntf;
typedef struct IoIntf* IoIntfPtr;
struct DirIntf;
typedef struct DirIntf* DirIntfPtr;
struct ResIntf;
typedef struct ResIntf* ResIntfPtr;
#endif


typedef struct
{
      
      BaTime lastModified;
      
      BaFileSize size;
      
      BaBool isDir;
} IoStat;


#define OpenRes_RDONLY 1


#define OpenRes_WRONLY 2

#ifdef __cplusplus
extern "C" {
#endif


BA_API int IoIntf_setPassword(
   IoIntfPtr o, const char* password, size_t passwordLen);



BA_API int IoIntf_setPasswordProp(
   IoIntfPtr o, BaBool passwordRequired, BaBool passwordBin);


BA_API char* IoIntf_getAbspath(IoIntfPtr o, const char* path);



BA_API int IoIntf_getType(IoIntfPtr o,const char** type,const char** platform);


BA_API int IoIntf_isEncrypted(
   IoIntfPtr o,const char* name,BaBool* isEncrypted);



BA_API void IoIntf_destructor(IoIntfPtr o);



typedef ResIntfPtr (*IoIntf_InflateGzip)(
   IoIntfPtr io, const char* name, int* status, const char** ecode);



typedef ResIntfPtr (*IoIntf_DeflateGzip)(
   ResIntfPtr resPtr, const char* name, ThreadMutex* m,
   BaFileSize* size, BaBool* isCompressed);


#ifdef __cplusplus
}
#endif 




typedef int (*IoIntf_Property)(IoIntfPtr o,const char* name,void* a,void* b);


typedef DirIntfPtr (*IoIntf_OpenDir)(IoIntfPtr o, const char* dirname,
                                   int* status, const char** ecode);


typedef int (*IoIntf_Stat)(IoIntfPtr o, const char* name, IoStat* st);


typedef ResIntfPtr (*IoIntf_OpenRes)(IoIntfPtr o, const char* name,
                                     U32 mode, int* status,
                                     const char** ecode);


typedef int (*IoIntf_CloseDir)(IoIntfPtr o, DirIntfPtr* dirIntf);


typedef ResIntfPtr (*IoIntf_OpenResGzip)(IoIntfPtr o, const char* name,
                                         ThreadMutex* m, BaFileSize* size,
                                         int* status, const char** ecode);


typedef int (*IoIntf_MkDir)(IoIntfPtr o, const char* name, const char** ecode);


typedef int (*IoIntf_Rename)(IoIntfPtr o, const char* from, const char* to,
                           const char** ecode);

typedef int (*IoIntf_Remove)(IoIntfPtr o,const char* name, const char** ecode);


typedef int (*IoIntf_RmDir)(IoIntfPtr o, const char* name, const char** ecode);

typedef int (*IoIntf_SeekAndRead)(
   ResIntfPtr super, BaFileSize offset,void* buf,size_t maxSize,size_t* size);


typedef void (*IoIntf_OnTerminate)(IoIntfPtr o, IoIntfPtr io);


typedef struct IoIntf
{
      
      IoIntf_Property propertyFp;

      
      IoIntf_CloseDir closeDirFp;

      
      IoIntf_MkDir mkDirFp;

      
      IoIntf_Rename renameFp;

      
      IoIntf_OpenDir openDirFp;

      
      IoIntf_OpenRes openResFp;

      
      IoIntf_OpenResGzip openResGzipFp;

      
      IoIntf_Remove removeFp;

      
      IoIntf_RmDir rmDirFp;

      
      IoIntf_Stat statFp;

      
      struct IoIntf* attachedIo;
      IoIntf_OnTerminate onTerminate;
} IoIntf;



#define IoIntf_constructorRW(o, property, closeDir, mkDir, rename,\
                             openDir, openRes, openResGzip, rm,\
                             rmDir, st) do {\
   (o)->propertyFp=property;\
   (o)->closeDirFp=closeDir;\
   (o)->mkDirFp=mkDir;\
   (o)->renameFp=rename;\
   (o)->openDirFp=openDir;\
   (o)->openResFp=openRes;\
   (o)->openResGzipFp=openResGzip;\
   (o)->removeFp=rm;\
   (o)->rmDirFp=rmDir;\
   (o)->statFp=st;\
   (o)->attachedIo=0;\
   (o)->onTerminate=0;\
} while(0)




#define IoIntf_constructorR(o, property, closeDir, openDir,\
                            openRes, openResGzip, st) do {\
   (o)->propertyFp=property;\
   (o)->closeDirFp=closeDir;\
   (o)->mkDirFp=0;\
   (o)->renameFp=0;\
   (o)->openDirFp=openDir;\
   (o)->openResFp=openRes;\
   (o)->openResGzipFp=openResGzip;\
   (o)->removeFp=0;\
   (o)->rmDirFp=0;\
   (o)->statFp=st;\
   (o)->attachedIo=0;\
   (o)->onTerminate=0;\
} while(0)




typedef int (*DirIntf_Read)(DirIntfPtr o);


typedef const char* (*DirIntf_GetName)(DirIntfPtr o);


typedef int (*DirIntf_Stat)(DirIntfPtr o, IoStat* st);


typedef struct DirIntf
{
      
      DirIntf_Read readFp;
      
      DirIntf_GetName getNameFp;
      
      DirIntf_Stat statFp;
}DirIntf;


#define DirIntf_constructor(o, read, getName, st) do {\
  (o)->readFp=read;\
  (o)->getNameFp=getName;\
  (o)->statFp=st;\
}while(0)


typedef int (*ResIntf_Read)(
   ResIntfPtr o, void* buf, size_t maxSize, size_t* size);
typedef int (*ResIntf_Write)(ResIntfPtr o, const void* buf, size_t size); 
typedef int (*ResIntf_Seek)(ResIntfPtr o, BaFileSize offset);
typedef int (*ResIntf_Flush)(ResIntfPtr o);
typedef int (*ResIntf_Close)(ResIntfPtr o);



typedef struct ResIntf
{
      
      ResIntf_Read readFp;
      
      ResIntf_Write writeFp;
      
      ResIntf_Seek seekFp;
      
      ResIntf_Flush flushFp;
      
      ResIntf_Close closeFp;
}ResIntf;

#define ResIntf_constructor(o, read, write, seek, flush, close) do {\
  (o)->readFp=read;\
  (o)->writeFp=write;\
  (o)->seekFp=seek;\
  (o)->flushFp=flush;\
  (o)->closeFp=close;\
}while(0)

  

#endif
#ifdef putc
#undef putc
#endif


#define BA_COOKIE_ID "z9ZAqJtI"

#ifndef __DOXYGEN__
struct HttpRequest;
struct HttpResponse;
struct HttpPage;
struct HttpServer;
struct HttpSession;
struct HttpLinkCon;
struct HttpDir;
struct AuthenticatedUser;
struct UserIntf;
struct CspReader;
struct HttpCmdThreadPoolIntf;
struct AuthUserList;
struct AuthorizerIntf;
struct AuthenticatorIntf;
struct LHttpCommand;
#endif





#ifdef __cplusplus
extern "C" {
#endif
BA_API struct AuthenticatedUser* AuthenticatedUser_get2(
   struct HttpSession* session);

BA_API void httpFmtDate(char* buf, U16 bufLen, BaTime t);

BA_API char* httpUnescape(char* from);

BA_API char* httpEscape(char* out, const char* in);
#ifdef __cplusplus
}
#endif


typedef void (*UserDefinedErrHandler)(BaFatalErrorCodes ecode1,
                                      unsigned int ecode2,
                                      const char* file,
                                      int line);






typedef void (*CspInit)(
   struct HttpDir* cspRoot,struct CspReader* reader);

 


struct z_stream_s;
typedef int (*ZlibInflateInit2)(struct z_stream_s* s, int  windowBits,
                     const char *version, int stream_size);

typedef int (*ZlibInflate)(struct z_stream_s* s, int flush);
typedef int (*ZlibInflateEnd)(struct z_stream_s* s);


#ifndef __DOXYGEN__

typedef struct
{
      char* buf;
      U16 size;
      U16 index;
} HttpAllocator;



typedef struct
{
#ifdef __cplusplus
      const char* name(HttpRequest* req);
      const char* value(HttpRequest* req);
#endif
      U16 nameI;
      U16 valueI;
}HttpHeader;

#ifdef __cplusplus
extern "C" {
#endif
BA_API const char* HttpHeader_name(HttpHeader* o, struct HttpRequest* req);
BA_API const char* HttpHeader_value(HttpHeader* o, struct HttpRequest* req);
#ifdef __cplusplus
}
inline const char* HttpHeader::name(HttpRequest* req) {
   return HttpHeader_name(this, req); }
inline const char* HttpHeader::value(HttpRequest* req) {
   return HttpHeader_value(this, req); }
#endif

#endif







#ifndef __DOXYGEN__

typedef enum {
   HttpInData_ParseHeader,
   HttpInData_ReadBody,
   HttpInData_ReadBodyAndParseUrlEncData
} HttpInData_ParseState;
#endif



typedef struct HttpInData
{
#ifdef __cplusplus
      
      const char* getBuf();

      
      S32 getBufSize();
#endif
      HttpAllocator allocator;
      struct HttpRequest* request;
      U16 lineStartI;
      U16 lineEndI;
      S16 maxRequest;
      U8 parseState; 
      U8 overflow; 
} HttpInData;

#define HttpAllocator_2Ptr(o, index) ((&(o)->buf[index]))
#define HttpInData_lineStartPtr(o) \
  HttpAllocator_2Ptr(&(o)->allocator,(o)->lineStartI)

#define HttpInData_getBufSize(o) \
  ((o)->lineStartI < (o)->allocator.index ? \
  (o)->allocator.index-(o)->lineStartI : 0)

#define HttpInData_getBuf(o) HttpInData_lineStartPtr(o)
BaBool HttpInData_hasMoreData(HttpInData* o);

#ifdef __cplusplus
inline const char* HttpInData::getBuf() {
   return HttpInData_getBuf(this); }
inline S32 HttpInData::getBufSize() {
   return HttpInData_getBufSize(this); }
#endif




typedef struct HttpParameter
{
#ifdef __cplusplus
      
      static U32 calculateSize(struct HttpRequest* req);

      
      static HttpParameter* clone(void* buf, struct HttpRequest* req);

      
      const char* getParameter(const char* paramName);

   private:
      HttpParameter() {}
#endif
      U16 formLen;
} HttpParameter;


#ifdef __cplusplus
extern "C" {
#endif
BA_API U32 HttpParameter_calculateSize(struct HttpRequest* req);
BA_API HttpParameter* HttpParameter_clone(void* buf, struct HttpRequest* req);
BA_API const char* HttpParameter_getParameter(
   HttpParameter* o,const char* paramName);

#ifdef __cplusplus
}
inline U32 HttpParameter::calculateSize(struct HttpRequest* req) {
   return HttpParameter_calculateSize(req); }
inline HttpParameter* HttpParameter::clone(void* buf, struct HttpRequest* req){
   return HttpParameter_clone(buf, req); }
inline const char* HttpParameter::getParameter(const char* paramName) {
   return HttpParameter_getParameter(this, paramName); }
#endif







typedef struct HttpParameterIterator
{
#ifdef __cplusplus
      HttpParameterIterator(){}
      
      HttpParameterIterator(HttpRequest* req);

      
      HttpParameterIterator(HttpParameter* param);

      
      void nextElement();
      
      bool hasMoreElements();
      
      const char* getName() const { return name; }
      
      const char* getValue() const { return value; }
   private:
#endif
      void* formElemBase;
      U8* dataEntry;
      U16 pos;
      U16 formLen;
      const char* name;
      const char* value;

} HttpParameterIterator;

#ifdef __cplusplus
extern "C" {
#endif

BA_API int HttpParameterIterator_constructor(
   HttpParameterIterator* o, struct HttpRequest* req);
BA_API int HttpParameterIterator_constructor2(HttpParameterIterator* o,
                                              HttpParameter* param);
BA_API void HttpParameterIterator_nextElement(HttpParameterIterator* o);
#define HttpParameterIterator_hasMoreElements(o) ((o)->name != 0)
#define HttpParameterIterator_getName(o) (o)->name
#define HttpParameterIterator_getValue(o) (o)->value


#ifdef __cplusplus
}
inline HttpParameterIterator::HttpParameterIterator(HttpRequest* req) {
   HttpParameterIterator_constructor(this, req); }
inline HttpParameterIterator::HttpParameterIterator(HttpParameter* param) {
   HttpParameterIterator_constructor2(this, param); }
inline void HttpParameterIterator::nextElement() {
   HttpParameterIterator_nextElement(this); }
#endif



typedef struct HttpCookie
{
#ifdef __cplusplus
      ~HttpCookie();

      
      const char* getComment() const { return comment; }

      
      const char* getDomain()  const { return domain; }

      
      BaTime      getMaxAge()  const { return maxAge; }

      
      const char* getName()    const { return name; }

      
      const char* getPath()    const { return path; }

      
      bool        getSecure()  const { return secure ? true : false; }

      
      const char* getValue()   const { return value; }

      
      void setComment(const char* purpose);

      
      void setDomain(const char* pattern);

      
      void setMaxAge(BaTime expiry);
      

      
      void deleteCookie();

      
      void setPath(const char* uri);

      
      void setSecure(bool flag);

      
      void setValue(const char* newValue);

#if 0
      
      int getVersion() const { return version; }
      
      void setVersion(int v);
#endif

      
      void activate();
   private:
      HttpCookie();
#endif
      struct HttpCookie* next;
      char* comment;
      char* domain;
      char* name;
      char* path;
      char* value;
      U32 maxAge;
      int   secure;
      int   version;
      BaBool deleteCookieFlag;
      BaBool   activateFlag; 
} HttpCookie;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpCookie_destructor(HttpCookie* o);
BA_API const char* HttpCookie_getComment(HttpCookie* o);
BA_API const char* HttpCookie_getDomain(HttpCookie* o);
BA_API BaTime HttpCookie_getMaxAge(HttpCookie* o);
BA_API const char* HttpCookie_getName(HttpCookie* o);
BA_API const char* HttpCookie_getPath(HttpCookie* o);
BA_API int HttpCookie_getSecure(HttpCookie* o);
BA_API const char* HttpCookie_getValue(HttpCookie* o);
BA_API void HttpCookie_setComment(HttpCookie* o, const char* purpose);
BA_API void HttpCookie_setDomain(HttpCookie* o, const char* pattern);
BA_API void HttpCookie_setMaxAge(HttpCookie* o, BaTime expiry);
#define HttpCookie_deleteCookie(o) (o)->deleteCookieFlag = TRUE;
BA_API void HttpCookie_setPath(HttpCookie* o, const char* uri);
BA_API void HttpCookie_setSecure(HttpCookie* o, int flag);
BA_API void HttpCookie_setValue(HttpCookie* o, const char* newValue);

#if 0
int HttpCookie_getVersion(HttpCookie* o);
void HttpCookie_setVersion(HttpCookie* o, int v);
#endif

BA_API void HttpCookie_activate(HttpCookie* o);
#ifdef __cplusplus
}
inline HttpCookie::HttpCookie() { baAssert(0); }
inline HttpCookie::~HttpCookie() { HttpCookie_destructor(this); }
inline void HttpCookie::setComment(const char* purpose) {
   HttpCookie_setComment(this, purpose); }
inline void HttpCookie::setDomain(const char* pattern) {
   HttpCookie_setDomain(this, pattern); }
inline void HttpCookie::setMaxAge(BaTime expiry) {
   HttpCookie_setMaxAge(this, expiry); }
inline void HttpCookie::deleteCookie() {
   HttpCookie_deleteCookie(this); }
inline void HttpCookie::setPath(const char* uri) {
   HttpCookie_setPath(this, uri); }
inline void HttpCookie::setSecure(bool flag) {
   HttpCookie_setSecure(this, flag); }
inline void HttpCookie::setValue(const char* newValue) {
   HttpCookie_setValue(this, newValue); }
#if 0
inline void HttpCookie::setVersion(int v) {
   HttpCookie_setVersion(this, v); }
#endif
inline void HttpCookie::activate() {
   HttpCookie_activate(this); }
#endif



typedef struct
{
#ifdef __cplusplus
      
      const char* getConnection();

      
      const char* getHost();

      
      const char* getDomain();

      
      const char* getContentType();

      
      SBaFileSize getContentLength();
#endif
      HttpInData* inData;
      char* domain;
      BaFileSize contentLength;
      U16 connectionHOffs;
      U16 hostHOffs;
      U16 contentTypeHOffs;
} HttpStdHeaders;

#ifdef __cplusplus
extern "C" {
#endif
BA_API const char* HttpStdHeaders_zzGetValFromOffs(
   HttpStdHeaders* o, U16 offset);
BA_API const char* HttpStdHeaders_getDomain(HttpStdHeaders* o);
#define HttpStdHeaders_getConnection(o) \
  HttpStdHeaders_zzGetValFromOffs(o,(o)->connectionHOffs)
#define HttpStdHeaders_getHost(o) \
  HttpStdHeaders_zzGetValFromOffs(o,(o)->hostHOffs)
#define HttpStdHeaders_getContentType(o) \
  HttpStdHeaders_zzGetValFromOffs(o,(o)->contentTypeHOffs)
#define HttpStdHeaders_getContentLength(o) (o)->contentLength

#ifdef __cplusplus
}
inline const char* HttpStdHeaders::getConnection() {
   return  HttpStdHeaders_getConnection(this); }
inline const char* HttpStdHeaders::getHost() {
   return  HttpStdHeaders_getHost(this); }
inline const char* HttpStdHeaders::getDomain() {
   return  HttpStdHeaders_getDomain(this); }
inline const char* HttpStdHeaders::getContentType() {
   return  HttpStdHeaders_getContentType(this); }
inline SBaFileSize HttpStdHeaders::getContentLength() {
   return  HttpStdHeaders_getContentLength(this); }

#endif



 



typedef enum {
   HttpMethod_Connect=0x1,
   HttpMethod_Get=0x2,
   HttpMethod_Head=0x4,
   HttpMethod_Options=0x8,
   HttpMethod_Post=0x10,
   HttpMethod_Put=0x20,
   HttpMethod_Trace=0x40,

   
   HttpMethod_Copy=0x80,
   HttpMethod_Delete=0x100,
   HttpMethod_Lock=0x200,
   HttpMethod_Move=0x400,
   HttpMethod_Mkcol=0x800,
   HttpMethod_Propfind=0x1000,
   HttpMethod_Proppatch=0x2000,
   HttpMethod_Unlock=0x4000,
   HttpMethod_Unknown=0x8000 
} HttpMethod;



BA_API HttpMethod HttpMethod_a2m(const char* str);




typedef struct HttpRequest
{
#ifdef __cplusplus

      
      int checkMethods(HttpResponse* resp, U32 methods, bool addDefault=TRUE);

      
      BaBool checkTime(struct HttpResponse* resp, BaTime time);

      
      AuthenticatedUser* getAuthenticatedUser();

      
      const char* getRequestURI();

      
      const char* getRequestURL(bool forceHttps=false);

      
      HttpStdHeaders* getStdHeaders();

      
      const char* getVersion();

      
      const char* getHeaderValue(const char* name);

      
      HttpCookie* getCookie(const char* name);

      
      HttpMethod getMethodType();

      
      const char* getMethod();

      
      static const char* getMethod(HttpMethod method);

      
      const char* getParameter(const char* paramName);

      
      HttpHeader* getHeaders(int* len);



      
#ifndef NO_HTTP_SESSION
      HttpSession* getSession(BaBool create=true);
#endif
      
      HttpConnection* getConnection();

      
      HttpServer* getServer();

      
      HttpResponse* getResponse();

      
      HttpCommand* getCommand();

      
      HttpInData* getBuffer();


      int setUserObj(void* userObj, bool overwrite=false);
      void* getUserObj();

#endif
      HttpStdHeaders stdH;
      HttpAllocator headerAlloc;
      HttpAllocator formAlloc;
      HttpInData inData;
      struct HttpServer* server;
      void* userObj;
      struct HttpSession* session;
      HttpMethod methodType;
      U16 pathI;
      U16 versionI;
      U16 headersI;
      U16 headerLen;
      U16 formsI;
      U16 formLen;
      BaBool postDataConsumed; 
}HttpRequest;

#ifdef __cplusplus
extern "C" {
#endif
BA_API int HttpRequest_checkMethods(HttpRequest* o, struct HttpResponse* resp,
                                    U32 methods, BaBool addDefault);
BA_API int HttpRequest_checkOptions(
   HttpRequest* o, struct HttpResponse* resp, int optLen, ...);
#define HttpRequest_getAuthenticatedUser(o) \
  AuthenticatedUser_get2(HttpRequest_getSession(o,FALSE))
#define HttpRequest_getConnection(o) HttpRequest_getCommand(o)->con
#define HttpRequest_getMethodType(o) (o)->methodType
#define HttpRequest_getMethod(o) HttpRequest_getMethod2((o)->methodType)
BA_API const char* HttpRequest_getMethod2(HttpMethod method);
#define HttpRequest_getServer(o) (o)->server
#define HttpRequest_getResponse(o) (&HttpRequest_getCommand(o)->response)
BA_API struct HttpCommand* HttpRequest_getCommand(HttpRequest*);
BA_API BaBool HttpRequest_checkTime(
   HttpRequest* o, struct HttpResponse* resp, BaTime time);
BA_API const char* HttpRequest_getRequestURI(HttpRequest* o);
BA_API const char* HttpRequest_getRequestURL(HttpRequest* o,BaBool forceHttps);
#define HttpRequest_getStdHeaders(o) (&(o)->stdH)
BA_API const char* HttpRequest_getVersion(HttpRequest* o);
BA_API const char* HttpRequest_getHeaderValue(HttpRequest* o,const char* name);
#define HttpRequest_getNoOfParameters(o) (o)->formLen
BA_API HttpCookie* HttpRequest_getCookie(HttpRequest* o, const char* name);
#define HttpRequest_getUserObj(o) (o)->userObj
BA_API int HttpRequest_setUserObj(
   HttpRequest* o, void* userObj, BaBool overwrite);
#define HttpRequest_getBuffer(o) (&(o)->inData)
BA_API const char* HttpRequest_getParameter(
   HttpRequest* o, const char* paramName);
BA_API HttpHeader* HttpRequest_getHeaders(HttpRequest* o, int* len);
#ifdef BA_SHARKSSL
BA_API int HttpRequest_wsUpgrade(HttpRequest* o);
#endif
BA_API BaBool HttpRequest_enableKeepAlive(HttpRequest* o);
BA_API int HttpRequest_pushBackData(HttpRequest* o);
#ifndef NO_HTTP_SESSION
BA_API struct HttpSession* HttpRequest_getSession(
   HttpRequest* o, BaBool create);
BA_API struct HttpSession* HttpRequest_session(
   HttpRequest* o, const char* val, size_t len, int set);
#define HttpRequest_setSession(o,val) \
  (val ? HttpRequest_session(o,val,strlen(val),TRUE) : 0)
#endif
#ifdef __cplusplus
}

inline int HttpRequest::checkMethods(HttpResponse* resp,
                        U32 methods, bool addDefault){
   return HttpRequest_checkMethods(this,resp,
      methods, addDefault ? TRUE : FALSE);}

inline BaBool HttpRequest::checkTime(struct HttpResponse* resp, BaTime time) {
   return HttpRequest_checkTime(this, resp, time); }
inline AuthenticatedUser* HttpRequest::getAuthenticatedUser() {
   return HttpRequest_getAuthenticatedUser(this); }
inline HttpMethod HttpRequest::getMethodType() {
   return HttpRequest_getMethodType(this); }
inline const char* HttpRequest::getMethod() {
   return HttpRequest_getMethod(this); }
inline const char* HttpRequest::getMethod(HttpMethod method) {
   return HttpRequest_getMethod2(method); }
inline HttpServer* HttpRequest::getServer() {
   return HttpRequest_getServer(this); }
inline const char* HttpRequest::getRequestURI() {
   return HttpRequest_getRequestURI(this); }
inline const char* HttpRequest::getRequestURL(bool forceHttps) {
   return HttpRequest_getRequestURL(this, forceHttps); }
inline HttpStdHeaders* HttpRequest::getStdHeaders() {
   return HttpRequest_getStdHeaders(this); }
inline const char* HttpRequest::getVersion() {
   return HttpRequest_getVersion(this); }
inline const char* HttpRequest::getHeaderValue(const char* name) {
   return HttpRequest_getHeaderValue(this, name); }
inline HttpCookie* HttpRequest::getCookie(const char* name) {
   return HttpRequest_getCookie(this, name); }
inline const char* HttpRequest::getParameter(const char* paramName) {
   return HttpRequest_getParameter(this, paramName); }
inline HttpHeader* HttpRequest::getHeaders(int* len) {
   return HttpRequest_getHeaders(this, len); }
inline int HttpRequest::setUserObj(void* userObj, bool overwrite) {
   return HttpRequest_setUserObj(this, userObj, overwrite); }
inline void* HttpRequest::getUserObj() {
   return HttpRequest_getUserObj(this); }
#ifndef NO_HTTP_SESSION
inline HttpSession* HttpRequest::getSession(BaBool create) {
   return HttpRequest_getSession(this, create); }
#endif
inline bool HttpParameterIterator::hasMoreElements() {
   return HttpParameterIterator_hasMoreElements(this); }
inline HttpInData* HttpRequest::getBuffer() {
   return HttpRequest_getBuffer(this); }
#endif


#ifndef __DOXYGEN__

typedef struct
{
      HttpAllocator data;
      U16 maxResponseHeader;
} NameValMM;


typedef struct
{
      U8 major;
      U8 minor;
} HttpProtocol;

#endif


typedef struct HttpResponse
{
#ifdef __cplusplus

      
      U32 byteCount();


      
      HttpCookie* createCookie(const char* name);

      
      const char* containsHeader(const char* name);

      
      const char* encodeRedirectURL(const char* pathName);

      
      const char* encodeRedirectURLWithParam(const char* pathName);

      
      const char* encodeUrl(const char* path);

      
      int flush();

      
      int forward(const char* path);

      
      int redirect(const char* path);


      
      HttpRequest* getRequest();

      
      HttpCommand* getCommand();


      
      int include(const char* path);

      
      bool committed() const;

      
      bool isForward() const;

      
      bool isInclude() const;

      
      bool initial() const;

      
      int resetHeaders();

      
      int resetBuffer();

      
      int sendError(int eCode);

      
      int sendError(int eCode, const char* msg);

      
      int sendBufAsError(int eCode);

      
      int sendBufAsTxtError(int eCode);


      
      int fmtError(int eCode, const char* fmt, ...);

      
      int sendRedirect(const char* url);

      
      int forceHttps();

      
      int setContentLength(BaFileSize len);

      
      int setContentType(const char* type);

      
      int setDateHeader(const char* name, BaTime time);

      
      int setHeader(const char* name, const char* value, bool replace=true);

      
      int setMaxAge(BaTime seconds);


      
      char* fmtHeader(const char* name, int valueLen, bool replace=true);


      
      void setStatus(int statusCode);

      
      int printf(const char* fmt, ...);

      
      BufPrint* getWriter();

      
      int write(const void* data, int len, int useBuffering=TRUE);

      
      int write(const char* data, int useBuffering=TRUE);

      
      int send(const void* data, int len);

      
      int setDefaultHeaders();

      
      int setResponseBuf(BufPrint* buf, bool useDefBuffer=true);

      
      int removeResponseBuf();


      int setUserObj(void* userObj, bool overwrite=false);
#endif
      NameValMM nameValMM;
      BufPrint headerPrint;
      BufPrint defaultBodyPrint;
      BufPrint* bodyPrint;
      struct HttpDir* currentDir;
      char* encodedURL;
      char* encodedRedirectURL;
      HttpCookie* cookieList;
      void* userObj;
      int statusCode;
      U32 msgLen; 
      HttpProtocol protocol;
      U16 includeCounter;
      U16 forwardCounter;
      char headerSent;
      char printAndWriteInitialized;
      char useChunkTransfer;
} HttpResponse;

#ifdef __cplusplus
extern "C" {
#endif
BA_API HttpCookie* HttpResponse_createCookie(
   struct HttpResponse* o,const char* name);
BA_API const char* HttpResponse_containsHeader(
   HttpResponse* o, const char* name);
BA_API int HttpResponse_dataAdded(HttpResponse* o, U32 size);
#define HttpResponse_byteCount(o) ((o)->msgLen + (o)->bodyPrint->cursor)
BA_API const char* HttpResponse_encodeRedirectURL(
   HttpResponse* o, const char* pathName);
BA_API const char* HttpResponse_encodeRedirectURLWithParamOrSessionURL(
   HttpResponse* o,const char* path,BaBool setUrlCookie);
#define HttpResponse_encodeRedirectURLWithParam(o, path) \
   HttpResponse_encodeRedirectURLWithParamOrSessionURL(o, path, FALSE)
#define HttpResponse_encodeSessionURL(o, path) \
   HttpResponse_encodeRedirectURLWithParamOrSessionURL(o, path, TRUE)
BA_API const char* HttpResponse_encodeUrl(HttpResponse* o, const char* path);
BA_API int HttpResponse_flush(HttpResponse* o);
#define HttpResponse_forward(o,path) HttpResponse_incOrForward(o,path,FALSE)
#define HttpResponse_getConnection(o) HttpResponse_getCommand(o)->con
#define HttpResponse_getRequest(o) (&HttpResponse_getCommand(o)->request)
BA_API struct HttpCommand* HttpResponse_getCommand(HttpResponse*);
#define HttpResponse_getBuf(o) (o)->bodyPrint->buf
#define HttpResponse_getBufSize(o) (o)->bodyPrint->bufSize
#define HttpResponse_getBufOffs(o) \
   ((o)->bodyPrint->buf + (o)->bodyPrint->cursor)
#define HttpResponse_getRemBufSize(o) \
   ((o)->bodyPrint->bufSize - (o)->bodyPrint->cursor)
#define HttpResponse_getUserObj(o) (o)->userObj
BA_API int HttpResponse_incOrForward(
   HttpResponse* o, const char* path, BaBool isInc);
BA_API int HttpResponse_redirect(HttpResponse* o, const char* path);
#define HttpResponse_include(o,path) HttpResponse_incOrForward(o,path,TRUE)
#define HttpResponse_isChunkTransfer(o) (o)->useChunkTransfer
#define HttpResponse_committed(o) (o)->headerSent
#define HttpResponse_isForward(o) ((o)->forwardCounter != 0)
#define HttpResponse_isInclude(o) ((o)->includeCounter != 0)
#define HttpResponse_initial(o) (!HttpResponse_isForward(o) && \
                                 !HttpResponse_isInclude(o))
BA_API int HttpResponse_setResponseBuf(
   HttpResponse* o,BufPrint* buf,BaBool useDefBuffer);
BA_API int HttpResponse_removeResponseBuf(HttpResponse* o);

BA_API int HttpResponse_resetHeaders(HttpResponse* o);
BA_API int HttpResponse_resetBuffer(HttpResponse* o);
BA_API int HttpResponse_sendError1(HttpResponse* o, int eCode);
BA_API int HttpResponse_sendError2(HttpResponse* o,int eCode,const char* msg);
BA_API int HttpResponse_sendBufAsError(HttpResponse* o,int eCode);
BA_API int HttpResponse_sendBufAsTxtError(HttpResponse* o,int eCode);
BA_API int HttpResponse_fmtVError(
   HttpResponse* response,
   int eCode,
   const char* fmt,
   va_list varg);
BA_API int HttpResponse_fmtError(
   HttpResponse* response,
   int eCode,
   const char* fmt, ...);
BA_API int HttpResponse_sendRedirect(HttpResponse* o, const char* url);
BA_API int HttpResponse_sendRedirectI(
   HttpResponse* o, const char* url, int status);
BA_API int HttpResponse_forceHttps(HttpResponse* o);
#define HttpResponse_setBufPos(o, pos) (o)->bodyPrint->cursor = pos
BA_API int HttpResponse_setContentLength(HttpResponse* o, BaFileSize len);
BA_API int HttpResponse_setContentType(HttpResponse* o, const char* type);
BA_API int HttpResponse_setDateHeader(
   HttpResponse* o, const char* name, BaTime t);
BA_API int HttpResponse_setHeader(
   HttpResponse* o,const char* name,const char* value, BaBool replace);
BA_API int HttpResponse_setMaxAge(HttpResponse* response, BaTime seconds);
BA_API char* HttpResponse_fmtHeader(
   HttpResponse* o, const char* name, int valueLen, BaBool replace);
BA_API int HttpResponse_setStatus(HttpResponse* o, int eCode);
BA_API int HttpResponse_vprintf(
   HttpResponse* o, const char* fmt, va_list argList);
BA_API int HttpResponse_printf(HttpResponse* o, const char* fmt, ...);
BA_API int HttpResponse_write(HttpResponse* o, const void* data, int len,
                              int useBuffering);
BA_API BufPrint* HttpResponse_getWriter(HttpResponse* o);
BA_API int HttpResponse_send(HttpResponse* o, const void* data, int len);
BA_API int HttpResponse_setDefaultHeaders(HttpResponse* o);
BA_API int HttpResponse_downgrade(HttpResponse* o);
BA_API int HttpResponse_setUserObj(
   HttpResponse* o,void* userObj,BaBool overwrite);
BA_API int HttpResponse_printAndWriteInit(HttpResponse* o);
BA_API int HttpResponse_send100Continue(HttpResponse* o);
BA_API int HttpResponse_setChunkEncoding(HttpResponse* o);
BA_API const char* HttpResponse_getRespData(HttpResponse* o, int* len);
#define HttpResponse_getStatus(o) (o)->statusCode
#ifdef __cplusplus
}
inline HttpCookie* HttpResponse::createCookie(const char* name) {
   return HttpResponse_createCookie(this, name); }
inline const char* HttpResponse::containsHeader(const char* name) {
   return HttpResponse_containsHeader(this, name); }
inline U32 HttpResponse::byteCount() {
   return HttpResponse_byteCount(this); }
inline const char* HttpResponse::encodeRedirectURL(const char* pathName) {
   return HttpResponse_encodeRedirectURL(this, pathName); }
inline const char* HttpResponse::encodeRedirectURLWithParam(const char* p) {
   return HttpResponse_encodeRedirectURLWithParam(this, p); }
inline const char* HttpResponse::encodeUrl(const char* path) {
   return HttpResponse_encodeUrl(this, path); }
inline int HttpResponse::flush() {
   return HttpResponse_flush(this); }
inline int HttpResponse::forward(const char* path) {
   return HttpResponse_forward(this, path); }
inline int HttpResponse::redirect(const char* path) {
   return HttpResponse_redirect(this, path); }
inline int HttpResponse::include(const char* path) {
   return HttpResponse_include(this, path); }
inline bool HttpResponse::committed() const {
   return HttpResponse_committed(this) ? true : false; }
inline bool HttpResponse::isForward() const {
   return HttpResponse_isForward(this) ? true : false; }
inline bool HttpResponse::isInclude() const {
   return HttpResponse_isInclude(this) ? true : false; }
inline bool HttpResponse::initial() const {
   return HttpResponse_initial(this) ? true : false; }
inline int HttpResponse::setResponseBuf(BufPrint* buf, bool useDefBuffer) {
   return HttpResponse_setResponseBuf(this, buf, useDefBuffer?TRUE:FALSE); }
inline int HttpResponse::removeResponseBuf() {
   return HttpResponse_removeResponseBuf(this); }
inline int HttpResponse::resetHeaders() {
   return HttpResponse_resetHeaders(this); }
inline int HttpResponse::resetBuffer() {
   return HttpResponse_resetBuffer(this); }
inline int HttpResponse::sendError(int eCode) {
   return HttpResponse_sendError1(this, eCode); }
inline int HttpResponse::sendError(int eCode, const char* msg) {
   return HttpResponse_sendError2(this, eCode, msg); }
inline int HttpResponse::sendBufAsError(int eCode) {
   return HttpResponse_sendBufAsError(this, eCode); }
inline int HttpResponse::sendBufAsTxtError(int eCode) {
   return HttpResponse_sendBufAsTxtError(this,eCode);}
inline int HttpResponse::fmtError(int eCode,const char* fmt,...) {
   int retv; va_list varg;
   va_start(varg, fmt);
   retv = HttpResponse_fmtVError(this, eCode, fmt, varg);
   va_end(varg);
   return retv; }
inline int HttpResponse::sendRedirect(const char* url) {
   return HttpResponse_sendRedirect(this, url); }
inline int HttpResponse::forceHttps() {
   return HttpResponse_forceHttps(this); }
inline int HttpResponse::setContentLength(BaFileSize len) {
   return HttpResponse_setContentLength(this, len); }
inline int HttpResponse::setContentType(const char* type) {
   return HttpResponse_setContentType(this, type); }
inline int HttpResponse::setDateHeader(const char* name, BaTime t) {
   return HttpResponse_setDateHeader(this, name, t); }
inline int HttpResponse::setHeader(
   const char* name, const char* value, bool replace) {
   return HttpResponse_setHeader(this,name, value, replace?TRUE:FALSE); }
inline int HttpResponse::setMaxAge(BaTime seconds) {
   return HttpResponse_setMaxAge(this, seconds); }
inline char* HttpResponse::fmtHeader(
   const char* name, int valueLen, bool replace) {
   return HttpResponse_fmtHeader(this, name, valueLen, replace?TRUE:FALSE); }
inline void HttpResponse::setStatus(int eCode) {
   HttpResponse_setStatus(this, eCode);}

inline int HttpResponse::printf(const char* fmt, ...) {
   int retv; va_list varg; va_start(varg, fmt);
   retv = HttpResponse_vprintf(this, fmt, varg); va_end(varg); return retv;}
inline int HttpResponse::write(const char* data, int useBuffering) {
   return HttpResponse_write(this, data, (int)strlen(data), useBuffering); }
inline BufPrint* HttpResponse::getWriter() {
   return HttpResponse_getWriter(this); }
inline int HttpResponse::write(const void* data, int len, int useBuffering){
   return HttpResponse_write(this, data, len, useBuffering); }
inline int HttpResponse::send(const void* data, int len) {
   return HttpResponse_send(this, data, len); }
inline int HttpResponse::setDefaultHeaders() {
   return HttpResponse_setDefaultHeaders(this); }
inline int HttpResponse::setUserObj(void* userObj, bool overwrite) {
   return HttpResponse_setUserObj(this, userObj, overwrite); }

#endif


typedef struct HttpCommand
{
#ifdef __cplusplus

      
      HttpRequest* getRequest();

      
      HttpResponse* getResponse();

      
      struct HttpConnection* getConnection();

      
      struct HttpServer* getServer();

      HttpCommand() {}
#endif
      DoubleLink super;
#ifdef __cplusplus
   public:
#endif
      HttpRequest request;
      HttpResponse response;
      struct HttpConnection* con;
      struct LHttpCommand* lcmd; 
	  U32 requestTime;
      BaBool runningInThread;
}HttpCommand;

#define HttpCommand_getRequest(o) (&(o)->request)
#define HttpCommand_getResponse(o) (&(o)->response)
#define HttpCommand_getConnection(o) (o)->con
#define HttpCommand_getServer(o) HttpConnection_getServer((o)->con)
#ifdef __cplusplus
inline HttpRequest* HttpCommand::getRequest() {
   return HttpCommand_getRequest(this); }
inline HttpResponse* HttpCommand::getResponse() {
   return HttpCommand_getResponse(this); }
inline struct HttpConnection* HttpCommand::getConnection() {
   return HttpCommand_getConnection(this); }
inline struct HttpServer* HttpCommand::getServer() {
   return HttpCommand_getServer(this);
}
#endif


#ifndef NO_HTTP_SESSION

#ifndef __DOXYGEN__
struct HttpSessionAttribute;
struct HttpSessionContainer;
#endif


typedef void (*HttpSessionAttribute_Destructor)(
   struct HttpSessionAttribute* o);


typedef struct HttpSessionAttribute
{
#ifdef __cplusplus
      
      HttpSessionAttribute(const char* name,
                           HttpSessionAttribute_Destructor terminate);

      
      HttpSession* getSession();
#endif
      struct HttpSessionAttribute* next;
      struct HttpSession* session;
      HttpSessionAttribute_Destructor destructor;
      char* name;
} HttpSessionAttribute;

#ifdef __cplusplus
extern "C" {
#endif

BA_API void HttpSessionAttribute_constructor(
   HttpSessionAttribute* o,
   const char* name,
   HttpSessionAttribute_Destructor d);
BA_API void HttpSessionAttribute_destructor(HttpSessionAttribute* o);
#define HttpSessionAttribute_getSession(o) (o)->session
#ifdef __cplusplus
}
inline HttpSessionAttribute::HttpSessionAttribute(
   const char* name,
   HttpSessionAttribute_Destructor d) {
   HttpSessionAttribute_constructor(this, name, d); }
inline HttpSession* HttpSessionAttribute::getSession() {
   return HttpSessionAttribute_getSession(this); }

#endif


typedef struct HttpSession
{
#ifdef __cplusplus

      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      void terminate();

      
      HttpSessionAttribute* getAttribute(const char* name);

      
      BaTime getCreationTime();

      
      BaTime getLastAccessedTime();

      
      BaTime getMaxInactiveInterval();

      
      HttpServer* getServer();

      
      int removeAttribute(const char* name);

      
      int setAttribute(HttpSessionAttribute* value);

      
      void setMaxInactiveInterval(BaTime interval);

      
      void incrRefCntr();

      
      void decrRefCntr();

      
      U32 getId();

      
      AuthenticatedUser* getAuthenticatedUser();

      
      U32 getUseCounter();


      void incrementLock();
      void decrementLock();

      HttpSession() {}
   private:
#endif
      SplayTreeNode super; 
      DoubleLink dlink;
      HttpSockaddr peer;
      HttpSessionAttribute* attrList;
      struct HttpSessionContainer* container;
      BaTime creationTime;
      BaTime lastAccessedTime;
      BaTime maxInactiveInterval;
      U32 useCounter;
      int refCounter;
      U16 lockCounter;
      U8 termPending; 
} HttpSession;


#ifdef __cplusplus
extern "C" {
#endif
BA_API HttpSessionAttribute* HttpSession_getAttribute(HttpSession* o,
                                                      const char* name);
BA_API BaTime HttpSession_getCreationTime(HttpSession* o);
BA_API BaTime HttpSession_getLastAccessedTime(HttpSession* o);
BA_API BaTime HttpSession_getMaxInactiveInterval(HttpSession* o);
BA_API struct HttpServer* HttpSession_getServer(HttpSession* o);
BA_API void HttpSession_terminate(HttpSession* o);
BA_API BaBool HttpSession_isNew(HttpSession* o);
BA_API int HttpSession_removeAttribute(HttpSession* o, const char* name);
BA_API int HttpSession_setAttribute(HttpSession* o,
                                    HttpSessionAttribute* value);
BA_API void HttpSession_setMaxInactiveInterval(HttpSession* o,BaTime interval);
#define HttpSession_incrRefCntr(o) (o)->refCounter++
BA_API void HttpSession_decrRefCntr(HttpSession* o);
#define HttpSession_incrementLock(o) (o)->lockCounter++
#define HttpSession_decrementLock(o) do {\
      baAssert((o)->lockCounter > 0);\
      (o)->lockCounter--; } while(0)
void HttpSession_fmtSessionId(HttpSession* o, U8* buf);
#define HttpSession_getId(o) \
   ((U32)((ptrdiff_t)SplayTreeNode_getKey((SplayTreeNode*)(o))))
#define HttpSession_getAuthenticatedUser(o) AuthenticatedUser_get2((o))
#define HttpSession_getUseCounter(o) (o)->useCounter
#define HttpSession_getPeerName(o) (&(o)->peer)
#ifdef __cplusplus
}
inline HttpSessionAttribute* HttpSession::getAttribute(const char* name) {
   return HttpSession_getAttribute(this, name); }
inline BaTime HttpSession::getCreationTime() {
   return HttpSession_getCreationTime(this); }
inline BaTime HttpSession::getLastAccessedTime() {
   return HttpSession_getLastAccessedTime(this); }
inline BaTime HttpSession::getMaxInactiveInterval() {
   return HttpSession_getMaxInactiveInterval(this); }
inline HttpServer* HttpSession::getServer() {
   return HttpSession_getServer(this); }
inline void HttpSession::terminate() {
   HttpSession_terminate(this); }
inline int HttpSession::removeAttribute(const char* name) {
   return HttpSession_removeAttribute(this, name); }
inline int HttpSession::setAttribute(HttpSessionAttribute* value) {
   return HttpSession_setAttribute(this, value); }
inline void HttpSession::setMaxInactiveInterval(BaTime interval) {
   HttpSession_setMaxInactiveInterval(this, interval); }
inline void HttpSession::incrRefCntr() {
   HttpSession_incrRefCntr(this); }
inline void HttpSession::decrRefCntr() {
   HttpSession_decrRefCntr(this); }
inline U32 HttpSession::getId() { return HttpSession_getId(this); }
inline U32 HttpSession::getUseCounter() {
   return HttpSession_getUseCounter(this); }
inline AuthenticatedUser* HttpSession::getAuthenticatedUser() {
   return HttpSession_getAuthenticatedUser(this); }
inline void HttpSession::incrementLock() {HttpSession_incrementLock(this);}
inline void HttpSession::decrementLock() {HttpSession_decrementLock(this);}

#endif 

typedef enum {
   HttpSessionContainer_OK = 0,
   HttpSessionContainer_NoMemory,
   HttpSessionContainer_TooManySessions,
   HttpSessionContainer_NoPeerAddress
} HttpSessionContainer_ECode;



typedef struct HttpSessionContainer
{
#ifdef __cplusplus
      HttpSessionContainer() {}
      
      void setMaxSessions(int max);
   private:
#endif
      SplayTree sessionTree;
      DoubleList sessionList;
      DoubleList sessionTermList;
      DoubleLink* sessionLinkIter;
      struct HttpServer* server;
      int noOfSessions; 
      int maxSessions;
      HttpSessionContainer_ECode eCode;
} HttpSessionContainer;

#ifdef __cplusplus
extern "C" {
#endif
void HttpSessionContainer_constructor(struct HttpSessionContainer* o,
                                      struct HttpServer* server,
                                      U16 maxSessions);
void HttpSessionContainer_destructor(struct HttpSessionContainer* o);
void HttpSessionContainer_sessionTimer(struct HttpSessionContainer* o);
#define HttpSessionContainer_setMaxSessions(o,max) (o)->maxSessions = max
#ifdef __cplusplus
}
inline void HttpSessionContainer::setMaxSessions(int max) {
   HttpSessionContainer_setMaxSessions(this, max); }
#endif

#endif 



typedef void (*HttpPage_Service)(struct HttpPage* page,
                                 HttpRequest* request,
                                 HttpResponse* response);


#define HttpPageType_HttpPageSE                0x00020

#ifndef __DOXYGEN__
typedef struct HttpPageNode
{
      struct HttpPageNode* next;
} HttpPageNode;
#endif


typedef struct HttpPage
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      HttpPage() {}
      
      HttpPage(HttpPage_Service service, const char* name);

      
      ~HttpPage();

      
      const char* getName() const { return name; }

      
      void service(HttpRequest* request, HttpResponse* response);

      
      bool isLinked();

      
      int unlink();
#endif
      HttpPageNode super; 
      HttpPage_Service serviceCB;
      const char* name;
} HttpPage;

#ifdef __cplusplus
extern "C" {
#endif
void
BA_API HttpPage_constructor(
   HttpPage* o, HttpPage_Service service, const char* name);
BA_API void HttpPage_destructor(HttpPage* o);
#define HttpPage_getName(o) (o)->name
#define HttpPage_isLinked(o) ((HttpPageNode*)(o))->next
BA_API int HttpPage_unlink(HttpPage* o);
#define HttpPage_service(o, request, response) \
  (o)->serviceCB(o, request, response)
#ifdef __cplusplus
}
inline HttpPage::HttpPage(HttpPage_Service service, const char* name) {
   HttpPage_constructor(this, service, name); }
inline HttpPage::~HttpPage() {
   HttpPage_destructor(this); }
inline bool HttpPage::isLinked() {
   return HttpPage_isLinked(this) ? true : false;
}
inline int HttpPage::unlink() {return HttpPage_unlink(this); }
inline void HttpPage::service(HttpRequest* request, HttpResponse* response) {
   HttpPage_service(this, request, response);
}
#endif



typedef int (*HttpDir_Service)(struct HttpDir* o,
                               const char* relPath,
                               HttpCommand* cmd);

#define HttpDirType_EhDir                    0x00001
#define HttpDirType_HttpResRdr               0x00002
#define HttpDirType_AuthenticateDir          0x00008
#define HttpDirType_AuthenticateDirWrapper   0x00010



typedef struct HttpDir
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      
      HttpDir();

      
      HttpDir(const char* name, S8 priority=0);
      ~HttpDir();

      
      int insertDir(HttpDir* dir);

      
      int insertPage(HttpPage* page);

      
      HttpPage* getFirstPage();

      
      HttpDir* getFirstDir();

      
      HttpDir* getDir(const char* name);

      
      HttpPage* getPage(const char* name);

      
      HttpDir* getNext();

      
      HttpPage* findPage(HttpPage* iter, const char* name);

      
      static HttpDir* findDir(HttpDir* iter, const char* name,
                              unsigned int nameLen);

      
      HttpDir* createOrGet(const char* name);

      
      const char* getName() const { return name; }

      
      HttpDir* getParent() const { return parent; }

      
      char* makeAbsPath(const char* relPath, int relPathLen);

      
      char* getRootPath();


      
      HttpDir_Service overloadService(HttpDir_Service s);

      
      void p403(const char* p403);

      
      bool isLinked();

      
      int unlink();

      
      void setAuthenticator(
         struct AuthenticatorIntf* authenticator,
         struct AuthorizerIntf* authorizer=0);

      
      bool authenticateAndAuthorize(HttpCommand* cmd,const char* path);


#endif
      HttpDir_Service service;
      struct HttpDir* parent;      
      struct HttpDir* next;        
      const char* name;            
      struct HttpDir* dirList;     
      struct AuthorizerIntf* realm;  
      struct AuthenticatorIntf* authenticator; 
      char* _p403;          
      HttpPageNode pageList;     
      U8 type;
      S8 priority;
} HttpDir;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpDir_constructor(HttpDir* o, const char* name, S8 priority);
BA_API void HttpDir_destructor(HttpDir* o);
BA_API char* HttpDir_makeAbsPath(
   HttpDir* o, const char* relPath, int relPathLen);
#define HttpDir_getRootPath(o) HttpDir_makeAbsPath(o,"",0)
BA_API int HttpDir_insertDir(HttpDir* o, HttpDir* dir);
#define HttpDir_getFirstPage(o) \
   (o)->pageList.next != &(o)->pageList ? ((HttpPage*)(o)->pageList.next) : 0
#define HttpDir_getFirstDir(o) (o)->dirList
BA_API HttpDir* HttpDir_getDir(HttpDir* o, const char* name);
BA_API HttpPage* HttpDir_getPage(HttpDir* o, const char* name);
#define HttpDir_getNext(o) (o)->next
#define HttpDir_getName(o) (o)->name
#define HttpDir_getParent(o) (o)->parent
BA_API int HttpDir_insertPage(HttpDir* o, HttpPage* page);
BA_API HttpPage* HttpDir_findPage(
   HttpDir* o, HttpPage* iter, const char* name);
BA_API HttpDir* HttpDir_findDir(
   HttpDir* iter, const char* name,unsigned int nameLen);
BA_API HttpDir* HttpDir_createOrGet(HttpDir* o, const char* name);
BA_API void HttpDir_p403(HttpDir* o, const char* p403);
BA_API HttpDir_Service HttpDir_overloadService(HttpDir*o, HttpDir_Service s);
#define HttpDir_isLinked(o) (o)->parent
BA_API int HttpDir_unlink(HttpDir* o);
#define HttpDir_setAuthenticator(o,authenticatorMA,authorizerMA) \
   (o)->authenticator = authenticatorMA,(o)->realm = authorizerMA
BA_API int HttpDir_authenticateAndAuthorize(
   HttpDir* o,HttpCommand* cmd,const char* path);
#define HttpDir_isAuthorized(o,user,method,path) \
  ((o)->realm ? \
  (user ? AuthorizerIntf_authorize((o)->realm,user,method,path) : FALSE) : \
  TRUE)
#ifdef __cplusplus
}
inline HttpDir::HttpDir() {
   HttpDir_constructor(this, 0, 0); }
inline HttpDir::HttpDir(const char* name, S8 priority) {
   HttpDir_constructor(this, name, priority); }
inline HttpDir::~HttpDir() {
   HttpDir_destructor(this); }
inline char* HttpDir::makeAbsPath(const char* relPath, int relPathLen) {
   return HttpDir_makeAbsPath(this, relPath, relPathLen); }
inline char* HttpDir::getRootPath() {
   return HttpDir_getRootPath(this); }
inline int HttpDir::insertDir(HttpDir* dir) {
   return HttpDir_insertDir(this, dir); }
inline int HttpDir::insertPage(HttpPage* page) {
   return HttpDir_insertPage(this, page); }
inline HttpPage* HttpDir::getFirstPage() { return HttpDir_getFirstPage(this); }
inline HttpDir* HttpDir::getFirstDir() { return HttpDir_getFirstDir(this); }
inline HttpDir* HttpDir::getDir(const char* name) {
   return HttpDir_getDir(this,name); }
inline HttpPage* HttpDir::getPage(const char* name) {
   return HttpDir_getPage(this,name); }
inline HttpDir* HttpDir::getNext() { return HttpDir_getNext(this); }
inline HttpPage* HttpDir::findPage(HttpPage* iter, const char* name) {
   return HttpDir_findPage(this, iter, name); }
inline HttpDir* HttpDir::findDir(HttpDir* iter, const char* name,
                                        unsigned int nameLen) {
   return HttpDir_findDir(iter, name, nameLen); }
inline HttpDir* HttpDir::createOrGet(const char* name) {
   return HttpDir_createOrGet(this, name); }
inline HttpDir_Service HttpDir::overloadService(HttpDir_Service s) {
   return HttpDir_overloadService(this, s); }
inline void HttpDir::p403(const char* p403) {
   HttpDir_p403(this, p403); }
inline int HttpDir::unlink() {return HttpDir_unlink(this); }
inline bool HttpDir::isLinked() {
   return HttpDir_isLinked(this) ? true : false; }
inline void HttpDir::setAuthenticator(struct AuthenticatorIntf* authenticator,
                                      struct AuthorizerIntf* authorizer){
   HttpDir_setAuthenticator(this,authenticator,authorizer);
}
inline bool HttpDir::authenticateAndAuthorize(
   HttpCommand* cmd, const char* path) {
   return HttpDir_authenticateAndAuthorize(this,cmd,path) ? true : false; }
#endif

#ifndef __DOXYGEN__

typedef struct HttpLinkCon
{
      HttpConnection con; 
      DoubleLink link;
} HttpLinkCon;


typedef struct
{
      HttpDir super; 
      HttpDir_Service superServiceFunc;
      char* page404;
      BaBool page404InProgress;
} HttpRootDir;

#endif


typedef struct HttpServerConfig
{
#ifdef __cplusplus
      
      HttpServerConfig();

      
      int setRequest(S16 min, S16 max);

      
      int setResponseHeader(U16 min, U16 max);

      
      int setResponseData(U16 size);

      
      int setCommit(U16 size);

      
      int setNoOfHttpCommands(U16 size);

      
      int setNoOfHttpConnections(U16 size);

      
      int setMaxSessions(U16 size);
#endif
      S16 minRequest;
      S16 maxRequest;
      U16 minResponseHeader;
      U16 maxResponseHeader;
      U16 commit;
      U16 responseData;
      U16 noOfHttpCommands;
      U16 noOfHttpConnections;
      U16 maxSessions;
} HttpServerConfig;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpServerConfig_constructor(HttpServerConfig* o);
BA_API int HttpServerConfig_setRequest(HttpServerConfig* o, S16 min, S16 max);
BA_API int HttpServerConfig_setResponseHeader(
   HttpServerConfig* o, U16 min, U16 max);
BA_API int HttpServerConfig_setResponseData(HttpServerConfig* o, U16 size);
BA_API int HttpServerConfig_setCommit(HttpServerConfig* o, U16 size);
BA_API int HttpServerConfig_setNoOfHttpCommands(HttpServerConfig* o, U16 size);
BA_API int HttpServerConfig_setNoOfHttpConnections(
   HttpServerConfig* o, U16 size);
BA_API int HttpServerConfig_setMaxSessions(HttpServerConfig* o, U16 size);
#ifdef __cplusplus
}
inline HttpServerConfig::HttpServerConfig() {
   HttpServerConfig_constructor(this); }
inline int HttpServerConfig::setRequest(S16 min, S16 max) {
   return HttpServerConfig_setRequest(this, min, max); }
inline int HttpServerConfig::setResponseHeader(U16 min, U16 max) {
   return HttpServerConfig_setResponseHeader(this, min, max); }
inline int HttpServerConfig::setResponseData(U16 size) {
   return HttpServerConfig_setResponseData(this, size); }
inline int HttpServerConfig::setCommit(U16 size) {
   return HttpServerConfig_setCommit(this, size); }
inline int HttpServerConfig::setNoOfHttpCommands(U16 size) {
   return HttpServerConfig_setNoOfHttpCommands(this, size); }
inline int HttpServerConfig::setNoOfHttpConnections(U16 size) {
   return HttpServerConfig_setNoOfHttpConnections(this, size); }
inline int HttpServerConfig::setMaxSessions(U16 size) {
   return HttpServerConfig_setMaxSessions(this, size); }

#endif


typedef DoubleList HttpLinkConList;


typedef void (*LspOnTerminateRequest)(struct LHttpCommand* lcmd);


typedef struct HttpServer
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      
      HttpServer(SoDisp* dispatcher, HttpServerConfig* cfg=0);

      ~HttpServer();

      
      int insertRootDir(HttpDir* dir);

      
      int insertDir(const char* virtualDirRootPath, HttpDir* dir);

      
      int insertCSP(CspInit cspInit,
                    const char* virtualDirRootPath,
                    struct CspReader* reader);

      struct AuthUserList* getAuthUserList(const char* name);

      
      ThreadMutex* getMutex();

      
      SoDisp* getDispatcher();

      
      HttpDir* getFirstRootDir();

      
      HttpSessionContainer* getSessionContainer();

#ifndef NO_HTTP_SESSION
      
      HttpSession* getSession(U32 id);
#endif

      
      void set404Page(const char* page404);

      
      const char* get404Page();

      int setUserObj(void* userObj, bool overwrite=false);

      
      static void initStatic(void);

      
      static void setErrHnd(UserDefinedErrHandler e);

      
      static int setZlib(ZlibInflateInit2 init,
                         ZlibInflate inflate,
                         ZlibInflateEnd end){
                            (void)init; (void)inflate; (void)end;
                            return 0;                         }
      
      static const char* getStatusCode(int code);


#endif
      DoubleList commandPool;
      DoubleList cmdReqList;
      HttpConnection noOpCon;
      HttpLinkConList freeList;
      HttpLinkConList readyList;
      HttpLinkConList connectedList;
      HttpRootDir rootDirContainer;
      SplayTree authUserTree; 
      struct HttpCmdThreadPoolIntf* threadPoolIntf;
      HttpLinkCon* connections;
      SoDisp* dispatcher;
      void* userObj;
      void* waitForConClose; 
      LspOnTerminateRequest lspOnTerminateRequest;
      int commandPoolSize;
      U16 noOfConnections;
      S16 maxHttpRequestLen;
#ifndef NO_HTTP_SESSION
      HttpSessionContainer sessionContainer;
#endif
} HttpServer;



void HttpServer_AsynchProcessDir(HttpServer* o,
                                 HttpDir* dir,
                                 HttpCommand* cmd);

#define HttpServer_setThreadPoolIntf(o, intf) (o)->threadPoolIntf=intf
#define HttpServer_luaenv(o) (o)->luaenv

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpServer_constructor(HttpServer*,SoDisp*, HttpServerConfig*);
BA_API void HttpServer_destructor(HttpServer* o);
BA_API int HttpServer_insertRootDir(HttpServer* o, HttpDir* dir);
BA_API int HttpServer_insertDir(HttpServer* o,
                                const char* virtualDirRootPath,
                                HttpDir* dir);
BA_API int HttpServer_insertCSP(HttpServer* o,
                                CspInit cspInit,
                                const char* virtualDirRootPath,
                                struct CspReader* reader);
#define HttpServer_getAuthUserList(o, name) \
   (AuthUserList*)SplayTree_find(&(o)->authUserTree, name)
#define HttpServer_getDispatcher(o) (o)->dispatcher
#define HttpServer_getFirstRootDir(o) \
     HttpDir_getFirstDir((HttpDir*)&(o)->rootDirContainer)
#define HttpServer_getUserObj(o) (o)->userObj
#define HttpServer_getSessionContainer(o) (&(o)->sessionContainer)
#define HttpServer_getMutex(o) SoDisp_getMutex((o)->dispatcher)
BA_API const char* HttpServer_getStatusCode(int code);
void HttpServer_addCon2ConnectedList(HttpServer* o, HttpConnection* con);
void HttpServer_doLingeringClose(
   HttpServer* o, HttpConnection* con, BaFileSize contLen);

#ifndef NO_HTTP_SESSION
BA_API HttpSession* HttpServer_getSession(HttpServer* o, U32 id);
#endif
BA_API HttpConnection* HttpServer_getFreeCon(HttpServer* o);
void HttpServer_returnFreeCon(HttpServer* o, HttpConnection* con);
BA_API void HttpServer_installNewCon(HttpServer* o, HttpConnection* con);
BA_API void HttpServer_setErrHnd(UserDefinedErrHandler e);
void HttpServer_initStatic(void);
int HttpServer_termOldestIdleCon(HttpServer* o);
BA_API void HttpServer_set404Page(HttpServer*o, const char* page404);
#define HttpServer_get404Page(o) (o)->rootDirContainer.page404
BA_API int HttpServer_setUserObj(
   HttpServer* o, void* userObj, BaBool overwrite);
#define HttpServer_termAllSessions(o) \
   HttpSessionContainer_destructor(&(o)->sessionContainer)

#define HttpServer_setZlib(init,inflate,end);
#ifdef __cplusplus
}
inline HttpServer::HttpServer(SoDisp* disp, HttpServerConfig* cfg){
   HttpServer_constructor(this, disp, cfg); }
inline HttpServer::~HttpServer()  {
   HttpServer_destructor(this); }
inline int HttpServer::insertRootDir(HttpDir* dir) {
   return HttpServer_insertRootDir(this, dir); }
inline ThreadMutex* HttpServer::getMutex() {
   return HttpServer_getMutex(this);
}
inline int HttpServer::insertDir(const char* virtualDirRootPath,HttpDir* dir){
   return HttpServer_insertDir(this, virtualDirRootPath, dir); }
inline int HttpServer::insertCSP(CspInit cspInit,
                                 const char* virtualDirRootPath,
                                 struct CspReader* reader) {
   return HttpServer_insertCSP(this, cspInit, virtualDirRootPath, reader); }
inline struct AuthUserList* HttpServer::getAuthUserList(const char* name) {
   return HttpServer_getAuthUserList(this,name); }
inline SoDisp* HttpServer::getDispatcher() {
   return HttpServer_getDispatcher(this); }
inline HttpDir* HttpServer::getFirstRootDir() {
   return HttpServer_getFirstRootDir(this); }
inline HttpSessionContainer* HttpServer::getSessionContainer() {
   return HttpServer_getSessionContainer(this); }
#ifndef NO_HTTP_SESSION
inline HttpSession* HttpServer::getSession(U32 id) {
   return HttpServer_getSession(this, id); }
inline void HttpServer::initStatic(void) {
   HttpServer_initStatic(); }
inline void HttpServer::setErrHnd(UserDefinedErrHandler e) {
   HttpServer_setErrHnd(e); }
inline void HttpServer::set404Page(const char* page404) {
   HttpServer_set404Page(this, page404); }
inline const char* HttpServer::get404Page() {
   return HttpServer_get404Page(this); }
inline int HttpServer::setUserObj(void* userObj, bool overwrite) {
   return HttpServer_setUserObj(this, userObj, overwrite); }
inline const char* HttpServer::getStatusCode(int code) {
   return HttpServer_getStatusCode(code);
}
#endif


inline HttpResponse* HttpRequest::getResponse() {
   return HttpRequest_getResponse(this); }
inline HttpConnection* HttpRequest::getConnection() {
   return HttpRequest_getConnection(this); }
inline HttpRequest* HttpResponse::getRequest() {
   return HttpResponse_getRequest(this); }
inline HttpCommand* HttpResponse::getCommand() {
   return HttpResponse_getCommand(this); }
inline HttpCommand* HttpRequest::getCommand() {
   return HttpRequest_getCommand(this); }
inline struct HttpServer* HttpConnection::getServer() {
   return HttpConnection_getServer(this); }

#endif 

 


#endif 
#ifndef NO_HTTP_TRACE
#ifndef HTTP_TRACE
#define HTTP_TRACE
#endif
#endif

#define HttpTrace_doRequestMask          0x01
#define HttpTrace_doRequestHeadersMask   0x02
#define HttpTrace_doResponseHeadersMask  0x04
#define HttpTrace_doResponseBodyMask     0x08
#define HttpTrace_doHttp11StateMask      0x10
#define HttpTrace_doReqBufOverflowMask   0x20


typedef void (*HttpTrace_Flush)(char* buf, int bufLen);


typedef struct HttpTrace
{
#ifdef __cplusplus
      
      static void setFLushCallback(HttpTrace_Flush fcb);

      
      static void vprintf(int prio, const char* fmt, va_list argList);

      
      static void printf(int prio, const char* fmt, ...);

      
      static void write(int prio, const char* buf, int len = -1);

      
      static int setPrio(int prio);

      
      static BufPrint* getWriter();

      
      static void releaseWriter(void);

      
      static void setRequest(bool cmd);

      
      static void setRequestHeaders(bool cmd);

      
      static void setResponseHeaders(bool cmd);

      
      static void setResponseBody(bool cmd);

      
      static void setHttp11State(bool cmd);

      
      static void setReqBufOverflow(bool cmd);

      
      static int setBufSize(int size);

      
      static void flush();

      static bool isRequestSet();
      static bool isRequestHeadersSet();
      static bool isResponseHeadersSet();
      static bool isResponseBodySet();
      static bool isHttp11StateSet();

   private:
      
      inline HttpTrace() {}
#endif
      BufPrint print; 
      int prio;
      U8 traceCmds;
}HttpTrace;

#ifdef __cplusplus
extern "C" {
#endif
BA_API int HttpTrace_setPrio(int prio);
BA_API void HttpTrace_setFLushCallback(HttpTrace_Flush fcb);
BA_API HttpTrace_Flush HttpTrace_getFLushCallback(void);
BA_API void HttpTrace_vprintf(int prio, const char* fmt, va_list argList);
BA_API void HttpTrace_printf(int prio, const char* fmt, ...);
BA_API void HttpTrace_write(int prio, const char* buf, int len);
BA_API void HttpTrace_flush(void);

BA_API void HttpTrace_setRequest(BaBool cmd);
BA_API void HttpTrace_setRequestHeaders(BaBool cmd);
BA_API void HttpTrace_setResponseHeaders(BaBool cmd);
BA_API void HttpTrace_setResponseBody(BaBool cmd);
BA_API void HttpTrace_setHttp11State(BaBool cmd);
BA_API void HttpTrace_setReqBufOverflow(BaBool cmd);
BA_API int HttpTrace_setBufSize(int size);
BA_API void HttpTrace_close(void);


BA_API U8 HttpTrace_getTraceCmds(void);
#define HttpTrace_isRequestSet() \
  (HttpTrace_getTraceCmds() & HttpTrace_doRequestMask ? TRUE : FALSE)
#define HttpTrace_isRequestHeadersSet() \
  (HttpTrace_getTraceCmds() & HttpTrace_doRequestHeadersMask ? TRUE : FALSE)
#define HttpTrace_isResponseHeadersSet() \
  (HttpTrace_getTraceCmds() & HttpTrace_doResponseHeadersMask ? TRUE : FALSE)
#define HttpTrace_isResponseBodySet() \
  (HttpTrace_getTraceCmds() & HttpTrace_doResponseBodyMask ? TRUE : FALSE)
#define HttpTrace_isHttp11StateSet() \
  (HttpTrace_getTraceCmds() & HttpTrace_doHttp11StateMask ? TRUE : FALSE)



#ifdef HTTP_TRACE
#define TRPR(data) HttpTrace_TRPR data
BA_API void HttpTrace_TRPR(const char* fmt, ...);
#else
#define TRPR(data)
#endif
BA_API HttpTrace* HttpTrace_get(void);
#define HttpTrace_doRequest() \
  (HttpTrace_get()->traceCmds & HttpTrace_doRequestMask)
#define HttpTrace_doRequestHeaders() \
  (HttpTrace_get()->traceCmds & HttpTrace_doRequestHeadersMask)
#define HttpTrace_doResponseHeaders() \
  (HttpTrace_get()->traceCmds & HttpTrace_doResponseHeadersMask)
#define HttpTrace_doResponseBody() \
  (HttpTrace_get()->traceCmds & HttpTrace_doResponseBodyMask)
#define HttpTrace_doHttp11State() \
  (HttpTrace_get()->traceCmds & HttpTrace_doHttp11StateMask)
#define HttpTrace_doReqBufOverflow() \
  (HttpTrace_get()->traceCmds & HttpTrace_doReqBufOverflowMask)
BA_API BufPrint* HttpTrace_getWriter(void);
BA_API void HttpTrace_releaseWriter(void);
#ifdef __cplusplus
}
inline int HttpTrace::setPrio(int prio) {
   return HttpTrace_setPrio(prio);
}
inline void HttpTrace::setFLushCallback(HttpTrace_Flush fcb) {
   HttpTrace_setFLushCallback(fcb); }
inline void HttpTrace::vprintf(int prio, const char* fmt, va_list argList) {
   HttpTrace_vprintf(prio, fmt, argList); }
inline void HttpTrace::printf(int prio, const char* fmt, ...) {
   va_list varg;
   va_start(varg, fmt);
   HttpTrace_vprintf(prio, fmt, varg);
   va_end(varg);
}
inline void HttpTrace::write(int prio, const char* buf, int len) {
   HttpTrace_write(prio, buf, len); }

inline BufPrint* HttpTrace::getWriter() {
   return HttpTrace_getWriter(); }
inline void HttpTrace::releaseWriter(void) {
   HttpTrace_releaseWriter(); }
inline void HttpTrace::setRequest(bool cmd) {
   HttpTrace_setRequest(cmd); }
inline void HttpTrace::setRequestHeaders(bool cmd) {
   HttpTrace_setRequestHeaders(cmd); }
inline void HttpTrace::setResponseHeaders(bool cmd) {
   HttpTrace_setResponseHeaders(cmd); }
inline void HttpTrace::setResponseBody(bool cmd) {
   HttpTrace_setResponseBody(cmd); }
inline void HttpTrace::setHttp11State(bool cmd) {
   HttpTrace_setHttp11State(cmd); }
inline void HttpTrace::setReqBufOverflow(bool cmd) {
   HttpTrace_setReqBufOverflow(cmd); }
inline int HttpTrace::setBufSize(int size) {
   return HttpTrace_setBufSize(size); }
inline void HttpTrace::flush() {
   HttpTrace_flush();
}
inline bool HttpTrace::isRequestSet() {
   return HttpTrace_isRequestSet() ? true : false;
}
inline bool HttpTrace::isRequestHeadersSet() {
   return HttpTrace_isRequestHeadersSet() ? true : false;
}
inline bool HttpTrace::isResponseHeadersSet() {
   return HttpTrace_isResponseHeadersSet() ? true : false;
}
inline bool HttpTrace::isResponseBodySet() {
   return HttpTrace_isResponseBodySet() ? true : false;
}
inline bool HttpTrace::isHttp11StateSet() {
   return HttpTrace_isHttp11StateSet() ? true : false;
}
#endif

#ifdef __cplusplus

struct HttpTraceWriteLock
{
      HttpTraceWriteLock() {
         _bufPrint = HttpTrace_getWriter();
      }
      ~HttpTraceWriteLock() {
         release();
      }

      
      void release() {
         if(_bufPrint) {_bufPrint=0; HttpTrace_releaseWriter(); }
      }

      
      void lock() {
         if(!_bufPrint) {_bufPrint = HttpTrace_getWriter(); }
      }

      
      operator BufPrint*() { return _bufPrint; }

      
      BufPrint* operator -> () { return _bufPrint; }
   private:
      BufPrint* _bufPrint;
};
#endif



#endif
#undef LoadString


#define luai_makeseed() baGetMsClock()





#if !defined(LUA_ANSI) && defined(__STRICT_ANSI__)
#define LUA_ANSI
#endif


#if !defined(LUA_ANSI) && defined(_WIN32) && !defined(_WIN32_WCE)
#define LUA_WIN		
#endif

#if defined(LUA_WIN)
#define LUA_DL_DLL
#define LUA_USE_AFORMAT		
#endif



#if defined(LUA_USE_LINUX)
#define LUA_USE_POSIX
#ifndef LUA_NO_DLOPEN
#define LUA_USE_DLOPEN		
#endif
#define LUA_USE_READLINE	
#define LUA_USE_STRTODHEX	
#define LUA_USE_AFORMAT		
#define LUA_USE_LONGLONG	
#endif

#if defined(LUA_USE_MACOSX)
#define LUA_USE_POSIX
#define LUA_USE_DLOPEN		
#define LUA_USE_READLINE	
#define LUA_USE_STRTODHEX	
#define LUA_USE_AFORMAT		
#define LUA_USE_LONGLONG	
#endif




#if defined(LUA_USE_POSIX)
#define LUA_USE_MKSTEMP
#define LUA_USE_ISATTY
#define LUA_USE_POPEN
#define LUA_USE_ULONGJMP
#define LUA_USE_GMTIME_R
#endif




#if defined(_WIN32)	

#define LUA_LDIR	"!\\lua\\"
#define LUA_CDIR	"!\\"
#ifndef LUA_PATH_DEFAULT
#define LUA_PATH_DEFAULT  \
		LUA_LDIR"?.lua;"  LUA_LDIR"?\\init.lua;" \
		LUA_CDIR"?.lua;"  LUA_CDIR"?\\init.lua;" ".\\?.lua"
#endif
#ifndef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT \
		LUA_CDIR"?.dll;" LUA_CDIR"loadall.dll;" ".\\?.dll"
#endif
#else			
#define LUA_VDIR	LUA_VERSION_MAJOR "." LUA_VERSION_MINOR "/"
#define LUA_ROOT	"/usr/local/"
#define LUA_LDIR	LUA_ROOT "share/lua/" LUA_VDIR
#define LUA_CDIR	LUA_ROOT "lib/lua/" LUA_VDIR
#ifndef LUA_PATH_DEFAULT
#define LUA_PATH_DEFAULT  \
		LUA_LDIR"?.lua;"  LUA_LDIR"?/init.lua;" \
		LUA_CDIR"?.lua;"  LUA_CDIR"?/init.lua;" "./?.lua"
#endif
#ifndef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT \
		LUA_CDIR"?.so;" LUA_CDIR"loadall.so;" "./?.so"
#endif
#endif			



#ifndef LUA_DIRSEP
#if defined(_WIN32)
#define LUA_DIRSEP	"\\"
#else
#define LUA_DIRSEP	"/"
#endif
#endif



#define LUA_ENV		"_ENV"



#if defined(LUA_BUILD_AS_DLL)	

#if defined(LUA_CORE) || defined(LUA_LIB)	
#define LUA_API __declspec(dllexport)
#else						
#define LUA_API __declspec(dllimport)
#endif						

#else				

#define LUA_API		extern

#endif				



#define LUALIB_API	LUA_API
#define LUAMOD_API	LUALIB_API



#if defined(__GNUC__) && ((__GNUC__*100 + __GNUC_MINOR__) >= 302) && \
    defined(__ELF__)		
#define LUAI_FUNC	__attribute__((visibility("hidden"))) extern
#define LUAI_DDEC	LUAI_FUNC
#define LUAI_DDEF	

#else				
#define LUAI_FUNC	extern
#define LUAI_DDEC	extern
#define LUAI_DDEF	
#endif				




#define LUA_QL(x)	"'" x "'"
#define LUA_QS		LUA_QL("%s")



#define LUA_IDSIZE	60

#ifdef NO_BA_SERVER


#define luai_writestring(s,l)	fwrite((s), sizeof(char), (l), stdout)
#define luai_writeline()	(luai_writestring("\n", 1), fflush(stdout))


#define luai_writestringerror(s,p) \
	(fprintf(stderr, (s), (p)), fflush(stderr))


#else
#define luai_writestring(s,l)      HttpTrace_write(0,s,-1)
#define luai_writeline()	   HttpTrace_write(0,"\n",1),HttpTrace_flush()
#define luai_writestringerror(s,p) HttpTrace_printf(0,s,p),HttpTrace_flush()
#endif



#define LUAI_MAXSHORTLEN        40





#if defined(LUA_COMPAT_ALL)	


#define LUA_COMPAT_UNPACK


#define LUA_COMPAT_LOADERS


#define lua_cpcall(L,f,u)  \
	(lua_pushcfunction(L, (f)), \
	 lua_pushlightuserdata(L,(u)), \
	 lua_pcall(L,1,0,0))



#define LUA_COMPAT_LOG10


#define LUA_COMPAT_LOADSTRING


#define LUA_COMPAT_MAXN


#define lua_strlen(L,i)		lua_rawlen(L, (i))

#define lua_objlen(L,i)		lua_rawlen(L, (i))

#define lua_equal(L,idx1,idx2)		lua_compare(L,(idx1),(idx2),LUA_OPEQ)
#define lua_lessthan(L,idx1,idx2)	lua_compare(L,(idx1),(idx2),LUA_OPLT)


#define LUA_COMPAT_MODULE

#endif				







#ifndef LUAI_BITSINT


#if INT_MAX-20 < 32760		
#define LUAI_BITSINT	16
#elif INT_MAX > 2147483640L	

#define LUAI_BITSINT	32
#else				
#error "you must define LUA_BITSINT with number of bits in an integer"
#endif				

#endif


#if LUAI_BITSINT >= 32		
#define LUA_INT32	int
#define LUAI_UMEM	size_t
#define LUAI_MEM	ptrdiff_t
#else				

#define LUA_INT32	long
#define LUAI_UMEM	unsigned long
#define LUAI_MEM	long
#endif				



#if LUAI_BITSINT >= 32
#define LUAI_MAXSTACK		1000000
#else
#define LUAI_MAXSTACK		15000
#endif


#define LUAI_FIRSTPSEUDOIDX	(-LUAI_MAXSTACK - 1000)





#define LUAL_BUFFERSIZE		BUFSIZ







#define l_mathop(x)		(x)


#ifndef LUA_NUMBER

#ifdef LUA_NUMBER_INTEGER
#define luai_hashnum(i,n)(i)=(n)
#define lua_number2int(i,n)	((i)=(n))
#define lua_number2integer(i,n)	((i)=(n))
#define LUA_NUMBER	long
#define LUAI_UACNUMBER	long
#define LUA_NUMBER_SCAN         "%ld"
#define LUA_NUMBER_FMT          "%d"
#define LUAI_MAXNUMBER2STR	32
#define lua_str2number(s,p)     strtoul((s),(p),10) 
#else 

#define LUA_NUMBER_DOUBLE
#define LUA_NUMBER	double


#define LUAI_UACNUMBER	double



#define LUA_NUMBER_SCAN		"%lf"
#define LUA_NUMBER_FMT		"%.14g"
#define LUAI_MAXNUMBER2STR	32 



#define lua_str2number(s,p)	strtod((s), (p))

#if defined(LUA_USE_STRTODHEX)
#define lua_strx2number(s,p)	strtod((s), (p))
#endif



#endif 


#ifdef NO_BA_SERVER
#define lua_number2str(s,n)	sprintf((s), LUA_NUMBER_FMT, (n))
#else
#define lua_number2str(s,n)	basnprintf((s), 1000, LUA_NUMBER_FMT, (n))
#endif
#endif 


#ifdef LUA_NUMBER_INTEGER
extern int bapower(int a, int x, int k);
extern int bamod(int a,int b);
#endif






#if defined(lobject_c) || defined(lvm_c)
#ifdef LUA_NUMBER_INTEGER
#define luai_nummod(L,a,b)         bamod(a,b)
#define luai_numpow(L,a,b)         bapower(a,b,1)
#else
#define luai_nummod(L,a,b)	((a) - l_mathop(floor)((a)/(b))*(b))
#define luai_numpow(L,a,b)	(l_mathop(pow)(a,b))
#endif
#endif


#if defined(LUA_CORE)
#define luai_numadd(L,a,b)	((a)+(b))
#define luai_numsub(L,a,b)	((a)-(b))
#define luai_nummul(L,a,b)	((a)*(b))
#ifdef LUA_NUMBER_INTEGER
#define luai_numdiv(L,a,b)	((b)?(a)/(b):0)
#else
#define luai_numdiv(L,a,b)	((a)/(b))
#endif
#define luai_numunm(L,a)	(-(a))
#define luai_numeq(a,b)		((a)==(b))
#define luai_numlt(L,a,b)	((a)<(b))
#define luai_numle(L,a,b)	((a)<=(b))
#define luai_numisnan(L,a)	(!luai_numeq((a), (a)))
#endif




#ifdef LUA_NUMBER_INTEGER
#define LUA_INTEGER	long
#else
#define LUA_INTEGER	ptrdiff_t
#endif

#define LUA_UNSIGNED	unsigned LUA_INT32





#if defined(LUA_NUMBER_DOUBLE) && !defined(LUA_ANSI)	



#if defined(LUA_WIN) && defined(_MSC_VER) && defined(_M_IX86)	

#define LUA_MSASMTRICK
#define LUA_IEEEENDIAN		0
#define LUA_NANTRICK



#elif defined(__i386__) || defined(__i386) || defined(__X86__) 

#define LUA_IEEE754TRICK
#define LUA_IEEELL
#define LUA_IEEEENDIAN		0
#define LUA_NANTRICK


#elif defined(__x86_64)						

#define LUA_IEEE754TRICK
#define LUA_IEEEENDIAN		0

#elif defined(__POWERPC__) || defined(__ppc__)			

#define LUA_IEEE754TRICK
#define LUA_IEEEENDIAN		1

#else								


#define LUA_IEEE754TRICK

#endif								

#endif							













#undef LUA_USE_AFORMAT
#ifndef LUA_USE_LONGLONG
#define LUA_USE_LONGLONG
#endif

#ifdef LUA_NUMBER_INTEGER
#undef LUA_USE_LONGLONG
#endif

#endif
#endif
#define LUA_VERSION_MAJOR	"5"
#define LUA_VERSION_MINOR	"2"
#define LUA_VERSION_NUM		502
#define LUA_VERSION_RELEASE	"2"

#define LUA_VERSION	"Lua " LUA_VERSION_MAJOR "." LUA_VERSION_MINOR
#define LUA_RELEASE	LUA_VERSION "." LUA_VERSION_RELEASE
#define LUA_COPYRIGHT	LUA_RELEASE "  Copyright (C) 1994-2013 Lua.org, PUC-Rio"
#define LUA_AUTHORS	"R. Ierusalimschy, L. H. de Figueiredo, W. Celes"



#define LUA_SIGNATURE	"\033Lua"


#define LUA_MULTRET	(-1)



#define LUA_REGISTRYINDEX	LUAI_FIRSTPSEUDOIDX
#define lua_upvalueindex(i)	(LUA_REGISTRYINDEX - (i))



#define LUA_OK		0
#define LUA_YIELD	1
#define LUA_ERRRUN	2
#define LUA_ERRSYNTAX	3
#define LUA_ERRMEM	4
#define LUA_ERRGCMM	5
#define LUA_ERRERR	6


typedef struct lua_State lua_State;

typedef int (*lua_CFunction) (lua_State *L);



typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer) (lua_State *L, const void* p, size_t sz, void* ud);



typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);



#define LUA_TNONE		(-1)

#define LUA_TNIL		0
#define LUA_TBOOLEAN		1
#define LUA_TLIGHTUSERDATA	2
#define LUA_TNUMBER		3
#define LUA_TSTRING		4
#define LUA_TTABLE		5
#define LUA_TFUNCTION		6
#define LUA_TUSERDATA		7
#define LUA_TTHREAD		8

#define LUA_NUMTAGS		9




#define LUA_MINSTACK	20



#define LUA_RIDX_MAINTHREAD	1
#define LUA_RIDX_GLOBALS	2
#define LUA_RIDX_LAST		LUA_RIDX_GLOBALS



typedef LUA_NUMBER lua_Number;



typedef LUA_INTEGER lua_Integer;


typedef LUA_UNSIGNED lua_Unsigned;




#if defined(LUA_USER_H)
#include LUA_USER_H
#endif



extern const char lua_ident[];



LUA_API lua_State *(lua_newstate) (lua_Alloc f, void *ud);
LUA_API void       (lua_close) (lua_State *L);
LUA_API lua_State *(lua_newthread) (lua_State *L);

LUA_API lua_CFunction (lua_atpanic) (lua_State *L, lua_CFunction panicf);


LUA_API const lua_Number *(lua_version) (lua_State *L);



LUA_API int   (lua_absindex) (lua_State *L, int idx);
LUA_API int   (lua_gettop) (lua_State *L);
LUA_API void  (lua_settop) (lua_State *L, int idx);
LUA_API void  (lua_pushvalue) (lua_State *L, int idx);
LUA_API void  (lua_remove) (lua_State *L, int idx);
LUA_API void  (lua_insert) (lua_State *L, int idx);
LUA_API void  (lua_replace) (lua_State *L, int idx);
LUA_API void  (lua_copy) (lua_State *L, int fromidx, int toidx);
LUA_API int   (lua_checkstack) (lua_State *L, int sz);

LUA_API void  (lua_xmove) (lua_State *from, lua_State *to, int n);




LUA_API int             (lua_isnumber) (lua_State *L, int idx);
LUA_API int             (lua_isstring) (lua_State *L, int idx);
LUA_API int             (lua_iscfunction) (lua_State *L, int idx);
LUA_API int             (lua_isuserdata) (lua_State *L, int idx);
LUA_API int             (lua_type) (lua_State *L, int idx);
LUA_API const char     *(lua_typename) (lua_State *L, int tp);

LUA_API lua_Number      (lua_tonumberx) (lua_State *L, int idx, int *isnum);
LUA_API lua_Integer     (lua_tointegerx) (lua_State *L, int idx, int *isnum);
LUA_API lua_Unsigned    (lua_tounsignedx) (lua_State *L, int idx, int *isnum);
LUA_API int             (lua_toboolean) (lua_State *L, int idx);
LUA_API const char     *(lua_tolstring) (lua_State *L, int idx, size_t *len);
LUA_API size_t          (lua_rawlen) (lua_State *L, int idx);
LUA_API lua_CFunction   (lua_tocfunction) (lua_State *L, int idx);
LUA_API void	       *(lua_touserdata) (lua_State *L, int idx);
LUA_API lua_State      *(lua_tothread) (lua_State *L, int idx);
LUA_API const void     *(lua_topointer) (lua_State *L, int idx);




#define LUA_OPADD	0	
#define LUA_OPSUB	1
#define LUA_OPMUL	2
#define LUA_OPDIV	3
#define LUA_OPMOD	4
#define LUA_OPPOW	5
#define LUA_OPUNM	6

LUA_API void  (lua_arith) (lua_State *L, int op);

#define LUA_OPEQ	0
#define LUA_OPLT	1
#define LUA_OPLE	2

LUA_API int   (lua_rawequal) (lua_State *L, int idx1, int idx2);
LUA_API int   (lua_compare) (lua_State *L, int idx1, int idx2, int op);



LUA_API void        (lua_pushnil) (lua_State *L);
LUA_API void        (lua_pushnumber) (lua_State *L, lua_Number n);
LUA_API void        (lua_pushinteger) (lua_State *L, lua_Integer n);
LUA_API void        (lua_pushunsigned) (lua_State *L, lua_Unsigned n);
LUA_API const char *(lua_pushlstring) (lua_State *L, const char *s, size_t l);
LUA_API const char *(lua_pushstring) (lua_State *L, const char *s);
LUA_API const char *(lua_pushvfstring) (lua_State *L, const char *fmt,
                                                      va_list argp);
LUA_API const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
LUA_API void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
LUA_API void  (lua_pushboolean) (lua_State *L, int b);
LUA_API void  (lua_pushlightuserdata) (lua_State *L, void *p);
LUA_API int   (lua_pushthread) (lua_State *L);



LUA_API void  (lua_getglobal) (lua_State *L, const char *var);
LUA_API void  (lua_gettable) (lua_State *L, int idx);
LUA_API void  (lua_getfield) (lua_State *L, int idx, const char *k);
LUA_API void  (lua_rawget) (lua_State *L, int idx);
LUA_API void  (lua_rawgeti) (lua_State *L, int idx, int n);
LUA_API void  (lua_rawgetp) (lua_State *L, int idx, const void *p);
LUA_API void  (lua_createtable) (lua_State *L, int narr, int nrec);
LUA_API void *(lua_newuserdata) (lua_State *L, size_t sz);
LUA_API int   (lua_getmetatable) (lua_State *L, int objindex);
LUA_API void  (lua_getuservalue) (lua_State *L, int idx);



LUA_API void  (lua_setglobal) (lua_State *L, const char *var);
LUA_API void  (lua_settable) (lua_State *L, int idx);
LUA_API void  (lua_setfield) (lua_State *L, int idx, const char *k);
LUA_API void  (lua_rawset) (lua_State *L, int idx);
LUA_API void  (lua_rawseti) (lua_State *L, int idx, int n);
LUA_API void  (lua_rawsetp) (lua_State *L, int idx, const void *p);
LUA_API int   (lua_setmetatable) (lua_State *L, int objindex);
LUA_API void  (lua_setuservalue) (lua_State *L, int idx);



LUA_API void  (lua_callk) (lua_State *L, int nargs, int nresults, int ctx,
                           lua_CFunction k);
#define lua_call(L,n,r)		lua_callk(L, (n), (r), 0, NULL)

LUA_API int   (lua_getctx) (lua_State *L, int *ctx);

LUA_API int   (lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc,
                            int ctx, lua_CFunction k);
#define lua_pcall(L,n,r,f)	lua_pcallk(L, (n), (r), (f), 0, NULL)

LUA_API int   (lua_load) (lua_State *L, lua_Reader reader, void *dt,
                                        const char *chunkname,
                                        const char *mode);

LUA_API int (lua_dump) (lua_State *L, lua_Writer writer, void *data);



LUA_API int  (lua_yieldk) (lua_State *L, int nresults, int ctx,
                           lua_CFunction k);
#define lua_yield(L,n)		lua_yieldk(L, (n), 0, NULL)
LUA_API int  (lua_resume) (lua_State *L, lua_State *from, int narg);
LUA_API int  (lua_status) (lua_State *L);



#define LUA_GCSTOP		0
#define LUA_GCRESTART		1
#define LUA_GCCOLLECT		2
#define LUA_GCCOUNT		3
#define LUA_GCCOUNTB		4
#define LUA_GCSTEP		5
#define LUA_GCSETPAUSE		6
#define LUA_GCSETSTEPMUL	7
#define LUA_GCSETMAJORINC	8
#define LUA_GCISRUNNING		9
#define LUA_GCGEN		10
#define LUA_GCINC		11

LUA_API int (lua_gc) (lua_State *L, int what, int data);




LUA_API int   (lua_error) (lua_State *L);

LUA_API int   (lua_next) (lua_State *L, int idx);

LUA_API void  (lua_concat) (lua_State *L, int n);
LUA_API void  (lua_len)    (lua_State *L, int idx);

LUA_API lua_Alloc (lua_getallocf) (lua_State *L, void **ud);
LUA_API void      (lua_setallocf) (lua_State *L, lua_Alloc f, void *ud);





#define lua_tonumber(L,i)	lua_tonumberx(L,i,NULL)
#define lua_tointeger(L,i)	lua_tointegerx(L,i,NULL)
#define lua_tounsigned(L,i)	lua_tounsignedx(L,i,NULL)

#define lua_pop(L,n)		lua_settop(L, -(n)-1)

#define lua_newtable(L)		lua_createtable(L, 0, 0)

#define lua_register(L,n,f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))

#define lua_pushcfunction(L,f)	lua_pushcclosure(L, (f), 0)

#define lua_isfunction(L,n)	(lua_type(L, (n)) == LUA_TFUNCTION)
#define lua_istable(L,n)	(lua_type(L, (n)) == LUA_TTABLE)
#define lua_islightuserdata(L,n)	(lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define lua_isnil(L,n)		(lua_type(L, (n)) == LUA_TNIL)
#define lua_isboolean(L,n)	(lua_type(L, (n)) == LUA_TBOOLEAN)
#define lua_isthread(L,n)	(lua_type(L, (n)) == LUA_TTHREAD)
#define lua_isnone(L,n)		(lua_type(L, (n)) == LUA_TNONE)
#define lua_isnoneornil(L, n)	(lua_type(L, (n)) <= 0)

#define lua_pushliteral(L, s)	\
	lua_pushlstring(L, "" s, (sizeof(s)/sizeof(char))-1)

#define lua_pushglobaltable(L)  \
	lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS)

#define lua_tostring(L,i)	lua_tolstring(L, (i), NULL)







#define LUA_HOOKCALL	0
#define LUA_HOOKRET	1
#define LUA_HOOKLINE	2
#define LUA_HOOKCOUNT	3
#define LUA_HOOKTAILCALL 4



#define LUA_MASKCALL	(1 << LUA_HOOKCALL)
#define LUA_MASKRET	(1 << LUA_HOOKRET)
#define LUA_MASKLINE	(1 << LUA_HOOKLINE)
#define LUA_MASKCOUNT	(1 << LUA_HOOKCOUNT)

typedef struct lua_Debug lua_Debug;  



typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);


LUA_API int (lua_getstack) (lua_State *L, int level, lua_Debug *ar);
LUA_API int (lua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
LUA_API const char *(lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
LUA_API const char *(lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
LUA_API const char *(lua_getupvalue) (lua_State *L, int funcindex, int n);
LUA_API const char *(lua_setupvalue) (lua_State *L, int funcindex, int n);

LUA_API void *(lua_upvalueid) (lua_State *L, int fidx, int n);
LUA_API void  (lua_upvaluejoin) (lua_State *L, int fidx1, int n1,
                                               int fidx2, int n2);

LUA_API int (lua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
LUA_API lua_Hook (lua_gethook) (lua_State *L);
LUA_API int (lua_gethookmask) (lua_State *L);
LUA_API int (lua_gethookcount) (lua_State *L);


struct lua_Debug {
  int event;
  const char *name;	
  const char *namewhat;	
  const char *what;	
  const char *source;	
  int currentline;	
  int linedefined;	
  int lastlinedefined;	
  unsigned char nups;	
  unsigned char nparams;
  char isvararg;        
  char istailcall;	
  char short_src[LUA_IDSIZE]; 
  
  struct CallInfo *i_ci;  
};







#endif



#ifndef lauxlib_h
#define lauxlib_h


#define LUA_ERRFILE     (LUA_ERRERR+1)


typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;


LUALIB_API void (luaL_checkversion_) (lua_State *L, lua_Number ver);
#define luaL_checkversion(L)	luaL_checkversion_(L, LUA_VERSION_NUM)

LUALIB_API int (luaL_getmetafield) (lua_State *L, int obj, const char *e);
LUALIB_API int (luaL_callmeta) (lua_State *L, int obj, const char *e);
LUALIB_API const char *(luaL_tolstring) (lua_State *L, int idx, size_t *len);
LUALIB_API int (luaL_argerror) (lua_State *L, int numarg, const char *extramsg);
LUALIB_API const char *(luaL_checklstring) (lua_State *L, int numArg,
                                                          size_t *l);
LUALIB_API const char *(luaL_optlstring) (lua_State *L, int numArg,
                                          const char *def, size_t *l);
LUALIB_API lua_Number (luaL_checknumber) (lua_State *L, int numArg);
LUALIB_API lua_Number (luaL_optnumber) (lua_State *L, int nArg, lua_Number def);

LUALIB_API lua_Integer (luaL_checkinteger) (lua_State *L, int numArg);
LUALIB_API lua_Integer (luaL_optinteger) (lua_State *L, int nArg,
                                          lua_Integer def);
LUALIB_API lua_Unsigned (luaL_checkunsigned) (lua_State *L, int numArg);
LUALIB_API lua_Unsigned (luaL_optunsigned) (lua_State *L, int numArg,
                                            lua_Unsigned def);

LUALIB_API void (luaL_checkstack) (lua_State *L, int sz, const char *msg);
LUALIB_API void (luaL_checktype) (lua_State *L, int narg, int t);
LUALIB_API void (luaL_checkany) (lua_State *L, int narg);

LUALIB_API int   (luaL_newmetatable) (lua_State *L, const char *tname);
LUALIB_API void  (luaL_setmetatable) (lua_State *L, const char *tname);
LUALIB_API void *(luaL_testudata) (lua_State *L, int ud, const char *tname);
LUALIB_API void *(luaL_checkudata) (lua_State *L, int ud, const char *tname);

LUALIB_API void (luaL_where) (lua_State *L, int lvl);
LUALIB_API int (luaL_error) (lua_State *L, const char *fmt, ...);

LUALIB_API int (luaL_checkoption) (lua_State *L, int narg, const char *def,
                                   const char *const lst[]);

LUALIB_API int (luaL_fileresult) (lua_State *L, int stat, const char *fname);
LUALIB_API int (luaL_execresult) (lua_State *L, int stat);


#define LUA_NOREF       (-2)
#define LUA_REFNIL      (-1)

LUALIB_API int (luaL_ref) (lua_State *L, int t);
LUALIB_API void (luaL_unref) (lua_State *L, int t, int ref);

LUALIB_API int (luaL_loadfilex) (lua_State *L, const char *filename,
                                               const char *mode);

#define luaL_loadfile(L,f)	luaL_loadfilex(L,f,NULL)

LUALIB_API int (luaL_loadbufferx) (lua_State *L, const char *buff, size_t sz,
                                   const char *name, const char *mode);
LUALIB_API int (luaL_loadstring) (lua_State *L, const char *s);

LUALIB_API lua_State *(luaL_newstate) (void);

LUALIB_API int (luaL_len) (lua_State *L, int idx);

LUALIB_API const char *(luaL_gsub) (lua_State *L, const char *s, const char *p,
                                                  const char *r);

LUALIB_API void (luaL_setfuncs) (lua_State *L, const luaL_Reg *l, int nup);

LUALIB_API int (luaL_getsubtable) (lua_State *L, int idx, const char *fname);

LUALIB_API void (luaL_traceback) (lua_State *L, lua_State *L1,
                                  const char *msg, int level);

LUALIB_API void (luaL_requiref) (lua_State *L, const char *modname,
                                 lua_CFunction openf, int glb);




#define luaL_newlibtable(L,l)	\
  lua_createtable(L, 0, sizeof(l)/sizeof((l)[0]) - 1)

#define luaL_newlib(L,l)	(luaL_newlibtable(L,l), luaL_setfuncs(L,l,0))

#define luaL_argcheck(L, cond,numarg,extramsg)	\
		((void)((cond) || luaL_argerror(L, (numarg), (extramsg))))
#define luaL_checkstring(L,n)	(luaL_checklstring(L, (n), NULL))
#define luaL_optstring(L,n,d)	(luaL_optlstring(L, (n), (d), NULL))
#define luaL_checkint(L,n)	((int)luaL_checkinteger(L, (n)))
#define luaL_optint(L,n,d)	((int)luaL_optinteger(L, (n), (d)))
#define luaL_checklong(L,n)	((long)luaL_checkinteger(L, (n)))
#define luaL_optlong(L,n,d)	((long)luaL_optinteger(L, (n), (d)))

#define luaL_typename(L,i)	lua_typename(L, lua_type(L,(i)))

#define luaL_dofile(L, fn) \
	(luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0))

#define luaL_dostring(L, s) \
	(luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0))

#define luaL_getmetatable(L,n)	(lua_getfield(L, LUA_REGISTRYINDEX, (n)))

#define luaL_opt(L,f,n,d)	(lua_isnoneornil(L,(n)) ? (d) : f(L,(n)))

#define luaL_loadbuffer(L,s,sz,n)	luaL_loadbufferx(L,s,sz,n,NULL)




typedef struct luaL_Buffer {
  char *b;  
  size_t size;  
  size_t n;  
  lua_State *L;
  char initb[LUAL_BUFFERSIZE];  
} luaL_Buffer;


#define luaL_addchar(B,c) \
  ((void)((B)->n < (B)->size || luaL_prepbuffsize((B), 1)), \
   ((B)->b[(B)->n++] = (c)))

#define luaL_addsize(B,s)	((B)->n += (s))

LUALIB_API void (luaL_buffinit) (lua_State *L, luaL_Buffer *B);
LUALIB_API char *(luaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
LUALIB_API void (luaL_addlstring) (luaL_Buffer *B, const char *s, size_t l);
LUALIB_API void (luaL_addstring) (luaL_Buffer *B, const char *s);
LUALIB_API void (luaL_addvalue) (luaL_Buffer *B);
LUALIB_API void (luaL_pushresult) (luaL_Buffer *B);
LUALIB_API void (luaL_pushresultsize) (luaL_Buffer *B, size_t sz);
LUALIB_API char *(luaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);

#define luaL_prepbuffer(B)	luaL_prepbuffsize(B, LUAL_BUFFERSIZE)









#define LUA_FILEHANDLE          "FILE*"


typedef struct luaL_Stream {
#ifndef LUA_NOIOLIB
  FILE *f;  
#endif
  lua_CFunction closef;  
} luaL_Stream;






#if defined(LUA_COMPAT_MODULE)

LUALIB_API void (luaL_pushmodule) (lua_State *L, const char *modname,
                                   int sizehint);
LUALIB_API void (luaL_openlib) (lua_State *L, const char *libname,
                                const luaL_Reg *l, int nup);

#define luaL_register(L,n,l)	(luaL_openlib(L,(n),(l),0))

#endif


#endif


#ifdef __cplusplus
}
#endif 


#ifndef __AuthenticatedUser_h
#define __AuthenticatedUser_h

#ifndef __DOXYGEN__
struct AuthenticatorIntf;
struct UserIntf;
struct AuthorizerIntf;
struct AuthenticatedUser;
struct LoginRespIntf;
struct LoginTracker;
struct LoginTrackerIntf;
struct LoginTrackerNode;
struct AuthInfo;
#endif


#ifdef __cplusplus
extern "C" {
#endif
extern const char BasicAuthUser_derivedType[];
extern const char DigestAuthUser_derivedType[];
extern const char FormAuthUser_derivedType[];
#ifdef __cplusplus
}
#endif





typedef enum {
   AuthenticatedUserType_Unknown,
   AuthenticatedUserType_Digest,
   AuthenticatedUserType_Basic,
   AuthenticatedUserType_Form
} AuthenticatedUserType;



typedef BaBool (*AuthorizerIntf_Authorize)(
   struct AuthorizerIntf* intf,
   struct AuthenticatedUser* user,
   HttpMethod httpMethod,
   const char* path);


typedef struct AuthorizerIntf
{
#ifdef __cplusplus
      AuthorizerIntf(){}

      
      AuthorizerIntf(AuthorizerIntf_Authorize authorize);

      
      bool authorize(struct AuthenticatedUser* user,
                     HttpMethod method,
                     const char* path);
#endif
      AuthorizerIntf_Authorize authorizeFP;
} AuthorizerIntf;

#define AuthorizerIntf_constructor(o, authorize) (o)->authorizeFP=authorize
#define AuthorizerIntf_authorize(o, user, method, path) \
  (o)->authorizeFP(o, user, method, path)

#ifdef __cplusplus
inline
AuthorizerIntf::AuthorizerIntf(AuthorizerIntf_Authorize authorize) {
   AuthorizerIntf_constructor(this,authorize); }
inline bool
AuthorizerIntf::authorize(struct AuthenticatedUser* user,
                             HttpMethod method,
                             const char* path) {
   return AuthorizerIntf_authorize(this,user,method,path) ? true : false; }
#endif



typedef void (*UserIntf_GetPwd)(struct UserIntf* intf,struct AuthInfo* info);


typedef struct UserIntf
{
#ifdef __cplusplus

      UserIntf() {}
      
      
      UserIntf(UserIntf_GetPwd getPwd);

#endif
      UserIntf_GetPwd getPwdFp;
} UserIntf;

#ifdef __cplusplus
extern "C" {
#endif

#define UserIntf_constructor(o, getPwd) (o)->getPwdFp = getPwd

#define UserIntf_getPwd(o, username) (o)->getPwdFp(o, username)
#ifdef __cplusplus
}
inline UserIntf::UserIntf(
   UserIntf_GetPwd getPwd) {
   UserIntf_constructor(this, getPwd);
}
#endif


#ifndef __DOXYGEN__
typedef struct AuthUserList
{
#ifdef __cplusplus
#endif
      SplayTreeNode super; 
      DoubleList list; 
      struct UserIntf* userDb;
      HttpServer* server;
      char* username;
      char* password;
      int listLen; 
} AuthUserList;
#endif

int AuthUserList_createOrCheck(struct AuthInfo* info,
                               UserIntf* userDb,
                               void** ptr,
                               size_t size);


typedef DoubleListEnumerator AuthUserListEnumerator;
#define AuthUserListEnumerator_constructor(e, o) \
   DoubleListEnumerator_constructor(e, &(o)->list)
BA_API struct AuthenticatedUser*
AuthUserListEnumerator_getElement(DoubleListEnumerator* o);
BA_API struct AuthenticatedUser*
AuthUserListEnumerator_nextElement(DoubleListEnumerator* o);
void AuthUserList_termIfEmpty(AuthUserList* o);



 
typedef struct AuthenticatedUser
{
#ifdef __cplusplus

       
      static AuthenticatedUser* get(HttpRequest* request);


      
      static AuthenticatedUser* get(HttpSession* session);

      
      HttpSession* getSession();

      
      const char* getPassword();

      
      const char* getName();

      
      void logout(bool all=false);

      
      AuthenticatedUserType getType();

      
      static AuthenticatedUser* getAnonymous();
#endif
      HttpSessionAttribute superClass; 
      DoubleLink dlink; 
      AuthUserList* authUserList;
      const char* derivedType; 
} AuthenticatedUser;

#ifdef __cplusplus
extern "C" {
#endif

BA_API void
AuthenticatedUser_constructor(AuthenticatedUser* o,
                              const char* derivedType,
                              AuthUserList* list,
                              HttpSessionAttribute_Destructor destructor);
BA_API void AuthenticatedUser_destructor(AuthenticatedUser* o);
BA_API AuthenticatedUser* AuthenticatedUser_get1(HttpRequest* request);
BA_API AuthenticatedUser* AuthenticatedUser_get2(HttpSession* session);
#define AuthenticatedUser_getName(o) \
  ((o) && (o)->authUserList && (o)->authUserList->username ? \
  (o)->authUserList->username : 0)
#define AuthenticatedUser_getDerivedType(o) (o)->derivedType
#define AuthenticatedUser_getSession(o) \
   HttpSessionAttribute_getSession((HttpSessionAttribute*)o)
#define AuthenticatedUser_getPassword(o) \
   ((o) && (o)->authUserList && (o)->authUserList->password ? \
    (o)->authUserList->password : 0)
BA_API void AuthenticatedUser_logout(AuthenticatedUser* o, BaBool all);
BA_API AuthenticatedUserType AuthenticatedUser_getType(AuthenticatedUser* o);
BA_API AuthenticatedUser* AuthenticatedUser_getAnonymous(void);
#ifdef __cplusplus
}
inline AuthenticatedUser* AuthenticatedUser::get(HttpRequest* request){
   return AuthenticatedUser_get1(request); }
inline AuthenticatedUser* AuthenticatedUser::get(HttpSession* session){
   return AuthenticatedUser_get2(session); }
inline const char* AuthenticatedUser::getName() {
   return AuthenticatedUser_getName(this); }
inline HttpSession* AuthenticatedUser::getSession() {
   return AuthenticatedUser_getSession(this); }
inline const char* AuthenticatedUser::getPassword() {
   return AuthenticatedUser_getPassword(this); }
inline void AuthenticatedUser::logout(bool all) {
   AuthenticatedUser_logout(this, all ? TRUE : FALSE); }
inline AuthenticatedUserType AuthenticatedUser::getType() {
   return AuthenticatedUser_getType(this); }
inline AuthenticatedUser* AuthenticatedUser::getAnonymous() {
   return AuthenticatedUser_getAnonymous(); }
#endif


typedef AuthenticatedUser* (*AuthenticatorIntf_Authenticate)(
   struct AuthenticatorIntf* super,
   const char* relPath,
   HttpCommand* cmd);


 
typedef struct AuthenticatorIntf
{
#ifdef __cplusplus
      
      AuthenticatorIntf(){}

      
      AuthenticatorIntf(AuthenticatorIntf_Authenticate authenticate);

      
      AuthenticatedUser* authenticate(const char* relPath, HttpCommand* cmd);
#endif
      AuthenticatorIntf_Authenticate authenticateCB;
} AuthenticatorIntf;

#ifdef __cplusplus
extern "C" {
#endif

#define AuthenticatorIntf_authenticate(o, relPath, cmd) \
  (o)->authenticateCB(o, relPath, cmd)

BA_API void AuthenticatorIntf_constructor(
   AuthenticatorIntf* o,
   AuthenticatorIntf_Authenticate authenticate);
#ifdef __cplusplus
}
inline AuthenticatorIntf::AuthenticatorIntf(
   AuthenticatorIntf_Authenticate authenticate) {
   AuthenticatorIntf_constructor(this,authenticate);
}
inline AuthenticatedUser* AuthenticatorIntf::authenticate(
   const char* relPath, HttpCommand* cmd) {
   return AuthenticatorIntf_authenticate(this, relPath, cmd);
}
#endif



typedef void (*LoginRespIntf_Service)(struct LoginRespIntf* intf,
                                      struct AuthInfo* info);


typedef struct LoginRespIntf
{
#ifdef __cplusplus
      LoginRespIntf() {}
      
      LoginRespIntf(LoginRespIntf_Service service);
#endif
      LoginRespIntf_Service serviceFp;
} LoginRespIntf;

#define LoginRespIntf_constructor(o, service) (o)->serviceFp=service
#ifdef __cplusplus
inline LoginRespIntf::LoginRespIntf(LoginRespIntf_Service service) {
   LoginRespIntf_constructor(this, service); }
#endif



typedef enum {
   
   AuthInfoCT_Password=5,
   
   AuthInfoCT_HA1,
   
   AuthInfoCT_Valid,

   
   AuthInfoCT_Invalid
} AuthInfoCT;



typedef struct AuthInfo
{
   
   struct LoginTracker* tracker;

   
   HttpCommand* cmd;

   
   const char* username;

   
   const char* upwd;

   
   AuthenticatedUser* user;

   
   AuthenticatedUserType type;
   
   
   AuthInfoCT ct;

   
   void* userObj;

   AuthUserList* authUserList;

   
   BaTime maxInactiveInterval;

   U32 seed;
   U32 seedKey;

   
   int maxUsers;

   
   int loginAttempts;

   
   BaBool denied;

   
   BaBool recycle;

   
   U8 password[100];
} AuthInfo;

#define AuthInfo_constructor(o, trackerMA, cmdMA, typeMA) do {\
   memset(o, 0, sizeof(AuthInfo));\
   (o)->tracker=trackerMA;\
   (o)->cmd=cmdMA;\
   (o)->type=typeMA;\
   (o)->maxUsers=3;\
   (o)->ct=AuthInfoCT_Password;\
   (o)->password[0]=0;\
} while(0)


typedef BaBool (*LoginTrackerIntf_Validate)(
   struct LoginTrackerIntf* o,
   AuthInfo* info,
   struct LoginTrackerNode* node);



typedef void (*LoginTrackerIntf_Login)(
   struct LoginTrackerIntf* o,
   AuthInfo* info,
   struct LoginTrackerNode* node);


typedef void (*LoginTrackerIntf_LoginFailed)(
   struct LoginTrackerIntf* o,
   AuthInfo* info,
   struct LoginTrackerNode* node);


typedef void (*LoginTrackerIntf_TerminateNode)(
   struct LoginTrackerIntf* o,
   struct LoginTrackerNode* node);



typedef struct LoginTrackerIntf
{
#ifdef __cplusplus
      
      LoginTrackerIntf(LoginTrackerIntf_Validate validate,
                       LoginTrackerIntf_Login login,
                       LoginTrackerIntf_LoginFailed loginFailed,
                       LoginTrackerIntf_TerminateNode terminateNode);
#endif
      LoginTrackerIntf_Validate validate;
      LoginTrackerIntf_Login login;
      LoginTrackerIntf_LoginFailed loginFailed;
      LoginTrackerIntf_TerminateNode terminateNode;
} LoginTrackerIntf;

#define LoginTrackerIntf_constructor(\
 o, validateMA, loginMA, loginFailedMA, terminateNodeMA) do {\
   (o)->validate=validateMA;\
   (o)->login=loginMA;\
   (o)->loginFailed=loginFailedMA;\
   (o)->terminateNode=terminateNodeMA;\
} while(0)
#define LoginTrackerIntf_validate(o, request, node) \
  (o)->validate(o, request, node)
#define LoginTrackerIntf_login(o, request, user) \
  (o)->login(o, request, user)
#define LoginTrackerIntf_loginFailed(o, node, loginName) \
  (o)->loginFailed(o, node, loginName)
#define LoginTrackerIntf_terminateNode(o, node) \
  (o)->terminateNode(o, node)

#ifdef __cplusplus
inline LoginTrackerIntf::LoginTrackerIntf(
   LoginTrackerIntf_Validate validate,
   LoginTrackerIntf_Login login,
   LoginTrackerIntf_LoginFailed loginFailed,
   LoginTrackerIntf_TerminateNode terminateNode) {
   LoginTrackerIntf_constructor(this,validate,login,loginFailed,terminateNode);
}
#endif



typedef struct LoginTrackerNode
{
#ifdef __cplusplus
      
      U32 getCounter();

      
      U32 getAuxCounter();

      
      void setAuxCounter(U32 count);

      
      HttpSockaddr* getAddr();

      
      void setUserData(void* data);

      
      void* getUserData();

      
      BaTime getTime();
#endif
      SplayTreeNode super;
      DoubleLink dlink;
      HttpSockaddr addr;
      void* userData;
      BaTime t;
      U32 loginCounter;
      U32 auxCounter;
} LoginTrackerNode;

#define LoginTrackerNode_getCounter(o) (o)->loginCounter
#define LoginTrackerNode_getAuxCounter(o) (o)->auxCounter
#define LoginTrackerNode_setAuxCounter(o, count) (o)->auxCounter=count
#define LoginTrackerNode_getAddr(o) (&(o)->addr)
#define LoginTrackerNode_setUserData(o, data) (o)->userData=data
#define LoginTrackerNode_getUserData(o) (o)->userData
#define LoginTrackerNode_getTime(o) (o)->t

#ifdef __cplusplus
inline U32 LoginTrackerNode::getCounter() {
   return LoginTrackerNode_getCounter(this);
}
inline U32 LoginTrackerNode::getAuxCounter() {
   return LoginTrackerNode_getAuxCounter(this);
}

inline void LoginTrackerNode::setAuxCounter(U32 count) {
   LoginTrackerNode_setAuxCounter(this, count);
}

inline HttpSockaddr* LoginTrackerNode::getAddr() {
   return LoginTrackerNode_getAddr(this);
}
inline void LoginTrackerNode::setUserData(void* data) {
   LoginTrackerNode_setUserData(this, data);
}
inline void* LoginTrackerNode::getUserData() {
   return  LoginTrackerNode_getUserData(this);
}
inline BaTime LoginTrackerNode::getTime() {
   return LoginTrackerNode_getTime(this);
}
#endif


typedef struct LoginTracker
{
#ifdef __cplusplus
      
      LoginTracker(U32 noOfLoginTrackerNodes,
                   LoginTrackerIntf* intf,
                   AllocatorIntf* allocator = AllocatorIntf::getDefault());

      
      void clearCache();

      
      LoginTrackerNode* getFirstNode();

      
      LoginTrackerNode* getNextNode(LoginTrackerNode* n);

      
      LoginTrackerNode* find(HttpRequest* request);
#endif
      SplayTree tree;
      DoubleList dInUseList;
      DoubleList dFreeList;
      LoginTrackerIntf* loginTrackerIntf;
      U32 cursor;
      U32 noOfLoginTrackerNodes;
      LoginTrackerNode* nodes;
} LoginTracker;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void LoginTracker_constructor(LoginTracker* o,
                                     U32 noOfLoginTrackerNodes,
                                     LoginTrackerIntf* intf,
                                     AllocatorIntf* allocator);
BA_API void LoginTracker_destructor(LoginTracker* o);
BA_API void LoginTracker_clearCache(LoginTracker* o);
BA_API LoginTrackerNode* LoginTracker_getFirstNode(LoginTracker* o);
BA_API LoginTrackerNode* LoginTracker_getNextNode(
   LoginTracker* o, LoginTrackerNode* n);
BA_API LoginTrackerNode* LoginTracker_find(LoginTracker*o, HttpRequest* req);
BA_API void LoginTracker_loginFailed(
   LoginTracker* o, AuthInfo* info);
BA_API BaBool LoginTracker_validate(LoginTracker* o, AuthInfo* info);
BA_API void LoginTracker_login(LoginTracker* o, AuthInfo* info);
#ifdef __cplusplus
}
inline LoginTracker::LoginTracker(U32 noOfLoginTrackerNodes,
                                  LoginTrackerIntf* intf,
                                  AllocatorIntf* allocator) {
   LoginTracker_constructor(this, noOfLoginTrackerNodes, intf, allocator);
}
inline void LoginTracker::clearCache() {
   LoginTracker_clearCache(this);
}
inline LoginTrackerNode* LoginTracker::getFirstNode() {
   return LoginTracker_getFirstNode(this);
}
inline LoginTrackerNode* LoginTracker::getNextNode(LoginTrackerNode* n) {
   return LoginTracker_getNextNode(this,n);
}
inline LoginTrackerNode* LoginTracker::find(HttpRequest* request) {
      return LoginTracker_find(this,request);
}
#endif


 


#ifdef BA_SHARKSSL
void calculateHA1Hex(
   const char* realm, const char* uname, const char* pwd, U8 hexbuf[33]);
#endif

#endif
#ifdef __cplusplus
extern "C" {
#endif

#define BALUA_VERSION 20
#define BA_ENV_IX lua_upvalueindex(1)
#define BA_TABLE "_BA_"
#define BA_WKTABLE "_BAWK"
#define balua_create(p) _balua_create(p, BALUA_VERSION)
#define balua_optboolean(L,narg,def) luaL_opt(L, balua_checkboolean, narg, def)
#define baluaENV_getmetatable(L,mtId) lua_rawgeti(L, BA_ENV_IX, mtId)
#define baluaENV_checkudata(L,ud,mtid) _baluaENV_isudtype(L,ud,mtid,TRUE)
#define baluaENV_isudtype(L,ud,mtid) _baluaENV_isudtype(L,ud,mtid,FALSE)
#define balua_pushbatab(L) lua_getfield(L,LUA_REGISTRYINDEX,BA_TABLE)
#define balua_pushwktab(L) lua_getfield(L,LUA_REGISTRYINDEX,BA_WKTABLE)
#define balua_newlib(L,l) \
  (luaL_newlibtable(L,l), balua_pushbatab(L), luaL_setfuncs(L,l,1))
#define baluaENV_getmutex(L) baluaENV_getparam(L)->mutex
#define balua_getmutex(L) balua_getparam(L)->mutex
#define GET_BAMUTEX ThreadMutex* m = baluaENV_getmutex(L)
#define balua_releasemutex(m) if(m) ThreadMutex_release(m)
#define balua_setmutex(m) if(m) ThreadMutex_set(m)

#ifdef NDEBUG
#define balua_check(x,y) x
#else
#define balua_check(x,y) baAssert(y == x)
#endif


#define dmpstk1(L,x) \
  fprintf(stderr," %s %p : %d\n", lua_typename(L,lua_type(L,(x))), \
         lua_topointer(L,x),__LINE__)

struct BaTimer;
struct LoginTracker;


typedef struct
{
      lua_State* L; 
      HttpServer* server; 
      struct BaTimer* timer; 
      IoIntf* vmio; 
      ThreadMutex* mutex; 
      struct LoginTracker* tracker; 
      int errHndRef; 
} BaLua_param;



#ifdef BA_LEAK_CHECK
BA_API void* baLMallocL(lua_State* L, U32 size,const char* file, int line);
#define baLMalloc(L,size) baLMallocL(L,size,__FILE__,__LINE__)
#else
BA_API void* baLMalloc(lua_State* L, U32 size);
#endif


BA_API lua_State* _balua_create(const BaLua_param* p, int version);


BA_API int balua_usertracker_create(
   lua_State* L, U32 noOfLoginTrackerNodes, U32 maxNumberOfLogins,
   BaTime banTime);


BA_API const char* balua_baerrorstr(int ecode);
BA_API lua_State* balua_getmainthread(lua_State* L);
BA_API int balua_typeerror(lua_State *L, int narg, const char *tname);
BA_API int balua_checkboolean(lua_State *L, int narg);
BA_API int baluaENV_newmetatable(lua_State *L, int mtid, int inheritmtid);
BA_API void baluaENV_register(
   lua_State *L, int mtid, int inheritmtid, const luaL_Reg* lib);
BA_API void* baluaENV_newuserdata(lua_State *L, int mtid, size_t size);
BA_API void* _baluaENV_isudtype(lua_State* L, int udIx, int mtid, int check);
BA_API HttpCommand* baluaENV_checkcmd(lua_State* L, int ix);
BA_API BaLua_param* balua_getparam(lua_State* L);
BA_API BaLua_param* baluaENV_getparam(lua_State* L);
BA_API int balua_errorhandler(lua_State* L);
BA_API void balua_manageerr(
   lua_State* L,const char* ewhere,const char* emsg,HttpCommand* cmd);
BA_API void balua_resumeerr(lua_State* L,const char* ewhere);
BA_API int balua_loadconfig(lua_State* L,struct IoIntf* io,const char* file);
BA_API IoIntf* baluaENV_checkIoIntf(lua_State *L, int udIx);
BA_API IoIntf* balua_iointf(
   lua_State* L, const char* name, struct IoIntf* newio);
BA_API struct IoIntf** balua_createiointf(lua_State* L);
BA_API HttpDir* baluaENV_toDir(lua_State* L, int ix);
BA_API HttpDir* baluaENV_createDir(lua_State* L,int mtId,size_t dirSize);



typedef struct
{
   int (*pushCertificate)(lua_State *L, SoDispCon* con);
   int (*pushCipher)(lua_State *L, SoDispCon* con);
   void (*unlockSharkSSL)(lua_State *L,struct SharkSsl* super);
   struct SharkSsl* (*lockSharkSSL)(
      lua_State *L,int tabIx,SharkSsl_Role role,SharkSsl* lockedShark);
} LSharkSSLFuncs;
 
extern const LSharkSSLFuncs* lSharkSSLFuncs;


enum BaUserDataTypes {
   BA_VMPTR=1,
   BA_IOINTFTAB,
   BA_DIRTAB,
   BA_CMDTAB,
   BA_JSONPARSER,
   BA_TDIR,
   BA_TDIR_RSRDR,
   BA_TDIR_DAV,
   BA_TDIR_LEH,
   BA_TLEHS,
   BA_TRESINTF,
   BA_TIOINTF,
   BA_TDIRITER,
   BA_THTTPCMD,
   BA_TCOOKIE,
   BA_TSESSION,
   BA_TSETRESPONSE,
   BA_TAUTHORIZERINTF,
   BA_TLUA_AUTHORIZER,
   BA_TUSERINTF,
   BA_TLUA_USER,
   BA_TJAUTHORIZER,
   BA_TJUSER,
   BA_TAUTHENTICATORINTF,
   BA_TAUTHENTICATOR,
   BA_TTIMER,
   BA_TUPLOAD,
   BA_TASYNCRESP,

   BA_TDIR_REDIRECTOR,
   BA_TDIR_TRACELOGGER
};



typedef struct LHttpDir
{
      lua_State *LM;
      HttpDir_Service orgServiceFunc;
      struct LHttpDir* parent;
      int parentRef;
      int funcRef; 
      int authenticatorRef; 
      int authorizerRef; 
} LHttpDir;


#ifdef __cplusplus
}
#endif


 

#endif
#ifdef __cplusplus
extern "C" {
#endif

void balua_forkpty(lua_State* L);
void balua_http(lua_State* L);
void balua_luaio(lua_State *L);
void balua_sharkssl(lua_State *L);
void balua_socket(lua_State* L);
void balua_crypto(lua_State *L);
void balua_tracelogger(lua_State *L);

typedef void (*balua_thread_Shutdown)(lua_State* L, ThreadMutex* dispMutex);
balua_thread_Shutdown balua_thread(lua_State* L);

#ifdef __cplusplus
}
#endif



int lGetStdSockOptions(lua_State* L, int tabIx, const char** intf,
                       BaBool* ipv6, BaBool* secure);
void lsharkssl_unlock(lua_State *L,SharkSsl* super);
SharkSsl* lsharkssl_lock(
   lua_State *L,int tabIx,SharkSsl_Role role,SharkSsl* lockedShark);
int pushCertificate(lua_State *L, SoDispCon* con);
int pushCiphers(lua_State *L, SoDispCon* con);


#define HTTPCLIENT "HTTPCLIENT"
struct HttpClient;
#define toHttpClient(L,ix) (struct HttpClient*)luaL_checkudata(L,ix,HTTPCLIENT)


#endif

#ifndef __HttpClient_h
#define __HttpClient_h



#ifndef _DynBuffer_h
#define _DynBuffer_h
 
struct DynBuffer;
typedef void (*DynBuffer_OnAllocError)(struct DynBuffer* o, int eCode);


typedef struct DynBuffer
#ifdef __cplusplus 
: public BufPrint
{
      DynBuffer() {}

      
      DynBuffer(int startSize, int expandSize, AllocatorIntf* alloc=0,
                DynBuffer_OnAllocError onAllocError=0);

      
      ~DynBuffer();

      
      void release();

      
      char* getBuf();

      
      U32 getBufSize();

      
      int getECode();

      
      int expand(int sizeNeeded);

      
      char* getCurPtr();

      
      void incrementCursor(int nBytes);

      
      static const char* ecode2str(int eCode);
#else
{
   BufPrint super; 
#if 0
}//Emacs fix
#endif
#endif

      AllocatorIntf* alloc;
      DynBuffer_OnAllocError onAllocError;
      int startSize;
      int expandSize;
} DynBuffer;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void DynBuffer_constructor(DynBuffer* o, int startSize, int expandSize,
                           AllocatorIntf* alloc,
                           DynBuffer_OnAllocError onAllocError);
#define DynBuffer_destructor(o) DynBuffer_release(o)
BA_API void DynBuffer_release(DynBuffer* o);
BA_API char* DynBuffer_getBuf(DynBuffer* o);
#define DynBuffer_getBufSize(o) BufPrint_getBufSize((BufPrint*)(o))
#define DynBuffer_getCurPtr(o) (((BufPrint*)(o))->buf+((BufPrint*)(o))->cursor)
#define DynBuffer_incrementCursor(o,nBytes) ((BufPrint*)(o))->cursor+=nBytes
#define DynBuffer_getECode(o) ((o)->expandSize < 0 ? (o)->expandSize : 0)
BA_API int DynBuffer_expand(DynBuffer* o, int sizeNeeded);
BA_API const char* DynBuffer_ecode2str(int eCode);
#ifdef __cplusplus
}

inline DynBuffer::DynBuffer(
   int startSize, int expandSize, AllocatorIntf* alloc,
   DynBuffer_OnAllocError onAllocError) {
   DynBuffer_constructor(this, startSize, expandSize, alloc, onAllocError); }
inline DynBuffer::~DynBuffer() {
   DynBuffer_destructor(this); }
inline void DynBuffer::release() {
   DynBuffer_release(this); }
inline char* DynBuffer::getBuf() {
   return DynBuffer_getBuf(this); }
inline U32 DynBuffer::getBufSize() {
   return DynBuffer_getBufSize(this); }
inline int DynBuffer::getECode() {
   return DynBuffer_getECode(this); }
inline int DynBuffer::expand(int sizeNeeded) {
   return DynBuffer_expand(this, sizeNeeded); }
inline char* DynBuffer::getCurPtr() {
   return DynBuffer_getCurPtr(this); }
inline void DynBuffer::incrementCursor(int nBytes) {
   DynBuffer_incrementCursor(this, nBytes); }
inline const char* DynBuffer::ecode2str(int eCode) {
   return DynBuffer_ecode2str(eCode); }
#endif

#endif


#ifndef __ClientConnection_h
#define __ClientConnection_h

typedef struct ClientConnection
#ifdef __cplusplus
:public SoDispCon
{
      
      ClientConnection(SoDisp* dispatcher=0,
                       SoDispCon_DispRecEv re=0,
                       SoDispCon_DispSendEv se=0);
      
      ~ClientConnection();

      
      void closeCon();

      
      int open(const char* host,
               U16 port,
               bool nonBlocking=false,
               const void* intfName=0,
               bool useIp6=false);

      
      int readData(void* data, int len, bool relmutex=false);

      
      int blockRead(void* data, int len);
#if 0
} //For emacs
#endif
#else
{ 
   SoDispCon super;
#endif
   int disableAutoActivate;
} ClientConnection;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void ClientConnection_constructor(ClientConnection* o,
                                         struct SoDisp* dispatcher,
                                         SoDispCon_DispRecEv re,
                                         SoDispCon_DispSendEv se);

BA_API int ClientConnection_open(ClientConnection* o,
                          const char* host,
                          U16 port,
                          BaBool nonBlocking,
                          const void* intfName,
                          BaBool useIp6);

struct SharkSsl;
struct SharkSslSession;
#define ClientConnection_readData(o, data, len, relmutex)\
  SoDispCon_readData((SoDispCon*)(o),data,len, relmutex)
#define ClientConnection_blockRead(o, data, len)\
  SoDispCon_blockRead((SoDispCon*)(o),data,len)
#define ClientConnection_closeCon(o) SoDispCon_closeCon((SoDispCon*)(o))
#define ClientConnection_shutdown(o) SoDispCon_shutdown((SoDispCon*)(o))
#define ClientConnection_destructor(o) SoDispCon_destructor((SoDispCon*)(o))
#define ClientConnection_setReadTmo(o,timeout)\
   SoDispCon_setReadTmo((SoDispCon*)(o), timeout)
#define ClientConnection_isSecure(o)\
   SoDispCon_isSecure((SoDispCon*)o)
#define ClientConnection_isValid(o)\
   SoDispCon_isValid((SoDispCon*)o)
#define ClientConnection_getDispatcher(o) \
   SoDispCon_getDispatcher((SoDispCon*)o)
#define ClientConnection_sendData(o, data, len)\
   SoDispCon_sendData((SoDispCon*)o, data, len)
#define ClientConnection_sendChunkData(o,data, len)\
   SoDispCon_sendChunkData((SoDispCon*)o,data, len)
#define ClientConnection_allocAsynchBuf(o, sizePtr)\
   SoDispCon_allocAsynchBuf((SoDispCon*)o, sizePtr)
#define ClientConnection_asyncSend(o,len) \
   SoDispCon_asyncSend((SoDispCon*)o,len)
#define ClientConnection_asyncReady(o) SoDispCon_asyncReady((SoDispCon*)o)
#define ClientConnection_setNonblocking(o)\
   SoDispCon_setNonblocking((SoDispCon*)o)
#define ClientConnection_setBlocking(o)\
   SoDispCon_setBlocking((SoDispCon*)o)
#define ClientConnection_isNonBlocking(o)\
   SoDispCon_isNonBlocking((SoDispCon*)o)
#define ClientConnection_peek(o)\
   SoDispCon_peek((SoDispCon*)o)
#define ClientConnection_setTCPNoDelay(o, enable)\
   SoDispCon_setTCPNoDelay((SoDispCon*)o, enable)
#define ClientConnection_getPeerName(o, addr,port)\
   SoDispCon_getPeerName((SoDispCon*)o, addr,port)
#define ClientConnection_getSockName(o, addr, port)\
   SoDispCon_getSockName((SoDispCon*)o, addr, port)
#define ClientConnection_addr2String(o, addr, buf, len)\
   SoDispCon_addr2String((SoDispCon*)o, addr, buf, len)
#define ClientConnection_cmpAddr(o, addr2)\
   SoDispCon_cmpAddr((SoDispCon*)o, addr2)
#define ClientConnection_recEvActive(o)\
   SoDispCon_recEvActive((SoDispCon*)o)
#define ClientConnection_sendEvActive(o)\
   SoDispCon_sendEvActive((SoDispCon*)o)
#define ClientConnection_dispatcherHasCon(o)\
   SoDispCon_dispatcherHasCon((SoDispCon*)o)
#define ClientConnection_hasMoreData(o)\
   SoDispCon_hasMoreData((SoDispCon*)o)
#define ClientConnection_setDispSendEvent(o, dispSendEvFp)\
   SoDispCon_setDispSendEvent((SoDispCon*)o, dispSendEvFp)

#define ClientConnection_disableAutoActivate(o) (o)->disableAutoActivate=TRUE;

#ifdef __cplusplus
}
inline ClientConnection::ClientConnection(SoDisp* dispatcher,
                                          SoDispCon_DispRecEv re,
                                          SoDispCon_DispSendEv se) {
   ClientConnection_constructor(this, dispatcher, re, se);
}
inline ClientConnection::~ClientConnection() {
   ClientConnection_destructor(this); 
}
inline void ClientConnection::closeCon() {
   ClientConnection_closeCon(this);
}
inline int ClientConnection::open(const char* host,
                                  U16 port,
                                  bool nonBlocking,
                                  const void* intfName,
                                  bool useIp6) {
   return ClientConnection_open(this,host,port,nonBlocking?TRUE:FALSE,
                                intfName,useIp6?TRUE:FALSE);
}
inline int ClientConnection::readData(void* data, int len, bool relmutex) {
   return ClientConnection_readData(this, data, len, relmutex ? TRUE : FALSE);
}
inline int ClientConnection::blockRead(void* data, int len) {
   return ClientConnection_blockRead(this, data, len);
}
#endif

 
#endif

#ifndef _SharkSslEx_h
#define _SharkSslEx_h

int sharkStrCaseCmp(const char *a, const char *b);



 
typedef enum
{
   
   SharkSslConTrust_CertCn = 1,

   
   SharkSslConTrust_Cn = 0,

   
   SharkSslConTrust_Cert = -1,

   
   SharkSslConTrust_None = -2,

   
   SharkSslConTrust_NotSSL = -3,

} SharkSslConTrust;

  




SHARKSSL_API SharkSslConTrust SharkSslCon_trusted(
   SharkSslCon* o, const char* name, SharkSslCertInfo** cPtr);

  

#endif
struct HttpClient;





typedef struct
{
      const char* key;
      const char* val;
} HttpClientKeyVal;




typedef struct
{
#ifdef __cplusplus
      
      const char* getKey(HttpClient* c);
      
      const char* getVal(HttpClient* c);
#endif
      U16 key;
      U16 val;
} HttpClientHeader;

#define HttpClientHeader_key(c,o) ((c)->db.super.buf + (o)->key)
#define HttpClientHeader_val(c,o) ((c)->db.super.buf + (o)->val)


#define HTTP_CLIENT_MAX_HEADERS 16

#define HttpClient_SocksProxy 1
#define HttpClient_Persistent 2
#define HttpClient_IPv6       4


typedef struct HttpClient
#ifdef __cplusplus
: public ClientConnection
{
      
      HttpClient(SoDisp* disp, U8 mode=HttpClient_Persistent);

      
      ~HttpClient();

      
      void setSSL(SharkSsl* ssl);

      
      void setReadTmo(BaTime timeout);

      
      static int isURL(const char* url);

      
      int trusted(void);

      
      void setAcceptTrusted(bool acceptTrusted);

      
      int request(HttpMethod methodType,
                  const char* url,
                  const char* userPass=0,
                  const HttpClientKeyVal* query=0,
                  const HttpClientKeyVal* headers=0,
                  BaFileSize size=0);

      
      int sendData(const void* data, int len);

      int getBufSize();

      
      int readData(void* buf, int bufSize);

      
      const char* getHeaderValue(const char* name);

      
      HttpClientHeader* getHeaders(int* hlen);

      
      void close();

      
      int getStatus();

      
      int getError();

   
   SharkSslCon* getSharkSslCon();

      SoDispCon* getSoDispCon();
#else
{
      ClientConnection super;
#endif
      DynBuffer db;
      HttpClientHeader headers[HTTP_CLIENT_MAX_HEADERS];

      struct SharkSsl* sharkSslClient; 

      
      const char* proxy; 
      const char* proxyUserPass; 
      const char* intfName; 

      char* data; 
      char* host; 
      BaFileSize size; 
      BaTime readTmo; 
      int chunkSize;
      int lastError;
      int portNo; 
      U16 proxyPortNo; 
      U16 headerLen;
      U16 httpStatus;
      BaBool chunkEncoding;
      BaBool respManaged; 
      BaBool closeCon;
      BaBool acceptTrusted; 
      
      U8 mode;
      U8 methodType;
} HttpClient;

#ifdef __cplusplus
extern "C" {
#endif

void HttpClient_constructor(HttpClient* o, SoDisp* disp, U8 mode);
#define HttpClient_setSSL(o, ssl) (o)->sharkSslClient=ssl
#define HttpClient_setReadTmo(o, timeout) (o)->readTmo=timeout
SharkSslCon* HttpClient_getSharkSslCon(HttpClient* o);

void HttpClient_destructor(HttpClient* o);
int HttpClient_isURL(const char* url);
int HttpClient_request(HttpClient* o,
                       HttpMethod methodType,
                       const char* url,
                       const char* userPass,
                       const HttpClientKeyVal* params,
                       const HttpClientKeyVal* headers,
                       BaFileSize size);

int HttpClient_sendData(HttpClient* o, const void* data, int len);
int HttpClient_getBufSize(HttpClient* o);
int HttpClient_readData(HttpClient* o, void* buf, int bufSize);
const char* HttpClient_getHeaderValue(HttpClient* o, const char* name);
HttpClientHeader* HttpClient_getHeaders(HttpClient* o, int* hlen);
void HttpClient_close(HttpClient* o);
int HttpClient_getStatus(HttpClient* o);
#define HttpClient_getError(o) (o)->lastError
#define HttpClient_getSoDispCon(o) ((SoDispCon*)(o))
int HttpClient_trusted(HttpClient* o);
#define HttpClient_setAcceptTrusted(o, t) (o)->acceptTrusted=t

#ifdef __cplusplus
}

inline HttpClient::HttpClient(SoDisp* disp, U8 mode) {
   HttpClient_constructor(this,disp, mode);
}

inline HttpClient::~HttpClient() {
   HttpClient_destructor(this);
}

inline void HttpClient::setSSL(SharkSsl* ssl) {
   HttpClient_setSSL(this,ssl);
}

inline void HttpClient::setReadTmo(BaTime timeout) {
   HttpClient_setReadTmo(this,timeout);
}

inline int HttpClient::isURL(const char* url) {
   return HttpClient_isURL(url);
}


inline int HttpClient::trusted(void){
   return HttpClient_trusted(this);
}

inline void HttpClient::setAcceptTrusted(bool t) {
   HttpClient_setAcceptTrusted(this, t?TRUE:FALSE);
}


inline SharkSslCon* HttpClient::getSharkSslCon() {
   return HttpClient_getSharkSslCon(this);
}


inline int HttpClient::request(HttpMethod methodType,
                               const char* url,
                               const char* userPass,
                               const HttpClientKeyVal* params,
                               const HttpClientKeyVal* headers,
                               BaFileSize size)
{
   return HttpClient_request(this,methodType,url,userPass,params,headers,size);
}

inline int HttpClient::sendData(const void* data, int len) {
   return HttpClient_sendData(this, data, len);
}

inline int HttpClient::getBufSize() {
   return HttpClient_getBufSize(this);
}

inline int HttpClient::readData(void* buf, int bufSize) {
   return HttpClient_readData(this, buf, bufSize);
}

inline const char* HttpClient::getHeaderValue(const char* name) {
   return HttpClient_getHeaderValue(this, name);
}

inline HttpClientHeader* HttpClient::getHeaders(int* hlen) {
   return HttpClient_getHeaders(this, hlen);
}

inline void HttpClient::close() {
   HttpClient_close(this);
}

inline int HttpClient::getStatus() {
   return HttpClient_getStatus(this);
}


inline int HttpClient::getError() {
   return HttpClient_getError(this);
}

inline SoDispCon* HttpClient::getSoDispCon() {
   return HttpClient_getSoDispCon(this);
}

inline const char* HttpClientHeader::getKey(HttpClient* c) {
   return c->db.buf + key;
}
inline const char* HttpClientHeader::getVal(HttpClient* c) {
   return c->db.buf + val;
}
#endif

 


#endif

#ifndef __NetIo_h
#define __NetIo_h

struct SoDisp;
struct SharkSsl;


typedef struct NetIo
#ifdef __cplusplus
: public IoIntf
{
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
      
      NetIo(struct SoDisp* disp=0);

      
      ~NetIo();

      
      int setRootDir(const char* url);

      
      int setUser(const char* user, const char* password);

      
      int setProxy(const char* proxy, U16 portNo, BaBool useSocksProxy);

      
      int setProxyUser(const char* user, const char* password);
      
      
      int setIntfName(const char* intfName);

      
      void setIPv6(bool enable);

      
      void setSSL(struct SharkSsl* sharkSslClient);
#if 0
}
#endif
#else
{
      IoIntf super; 
#endif 
      SoDisp* disp;

      struct SharkSsl* sharkSslClient; 

      
      char* proxy; 
      char* proxyUserPass; 
      char* intfName; 

      char* userPass;
      char* rootPath; 
      int rootPathLen;

      U16 proxyPortNo; 

      U8 httpClientMode; 
} NetIo;

#ifdef __cplusplus
extern "C" {
#endif

void NetIo_constructor(NetIo* o, struct SoDisp* disp);
void NetIo_destructor(NetIo* o);
int NetIo_setRootDir(NetIo* o, const char* url);


int NetIo_setUser(NetIo* o, const char* user, const char* password);
int NetIo_setProxy(
   NetIo* o, const char* proxy, U16 portNo, BaBool useSocksProxy);
int NetIo_setProxyUser(NetIo* o, const char* user, const char* password);
int NetIo_setIntfName(NetIo* o, const char* intfName);
int NetIo_setIPv6(NetIo* o, BaBool enable);
#define NetIo_setSSL(o, ssl) (o)->sharkSslClient=ssl


#ifdef __cplusplus
}

inline NetIo::NetIo(struct SoDisp* disp) {
   NetIo_constructor(this, disp);
}
inline NetIo::~NetIo() {
   NetIo_destructor(this);
}
inline int NetIo::setRootDir(const char* url) {
   return NetIo_setRootDir(this, url);
}
inline int NetIo::setUser(const char* user, const char* password) {
   return NetIo_setUser(this, user, password);
}
inline int NetIo::setProxy(const char* proxy,U16 portNo,BaBool useSocksProxy) {
   return NetIo_setProxy(this, proxy, portNo, useSocksProxy);
}
inline int NetIo::setProxyUser(const char* user, const char* password) {
   return NetIo_setProxyUser(this, user, password);
}
inline int NetIo::setIntfName(const char* intfName) {
   return NetIo_setIntfName(this, intfName);
}
inline void NetIo::setIPv6(bool enable) {
   NetIo_setIPv6(this, enable ? TRUE : FALSE);
}
inline void NetIo::setSSL(struct SharkSsl* sharkSslClient) {
   NetIo_setSSL(this, sharkSslClient);
}
#endif


#endif

#endif


#ifndef _DiskIo_h
#define _DiskIo_h
 
#ifndef ROOTPT
#define ROOTPT void*
#endif

#ifndef DiskIo_DATA
#define DiskIo_DATA void* data
#endif






typedef struct DiskIo
#ifdef __cplusplus
: public IoIntf
{
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
 
      
      DiskIo();

      
      ~DiskIo();

      
      int setRootDir(const char* root);

      int getRootDir(char* buf, int len);
#if 0
}
#endif
#else
{
      IoIntf super; 
#endif
      ROOTPT rootPath;
      int rootPathLen;
      DiskIo_DATA; 
} DiskIo;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void DiskIo_constructor(DiskIo* o);
BA_API void DiskIo_destructor(DiskIo* o);
BA_API int DiskIo_setRootDir(DiskIo* o, const char* root);
BA_API int DiskIo_getRootDir(DiskIo* o, char* buf, int len);
#ifdef __cplusplus
}

inline DiskIo::DiskIo() {
   DiskIo_constructor(this);
}
inline DiskIo::~DiskIo() {
   DiskIo_destructor(this);
}
inline int DiskIo::setRootDir(const char* root) {
   return DiskIo_setRootDir(this, root);
}
inline int DiskIo::getRootDir(char* buf, int len) {
   return DiskIo_getRootDir(this, buf, len);
}

#endif
 
  

#endif


#ifndef __BaFile_h
#define __BaFile_h



#ifdef __cplusplus
extern "C" {
#endif


BA_API DirIntfPtr baOpenDir(const char* dirname, int* status, const char** ecode);


BA_API int baCloseDir(DirIntfPtr* dirIntf);


BA_API int baStat(const char* name, IoStat* st);



BA_API ResIntfPtr baOpenRes(const char* name,U32 mode,int* status,const char** ecode);


BA_API int baCloseRes(ResIntfPtr* fp);


 
BA_API int baMkDir(const char* dname, const char** ecode);


BA_API int baRmdDir(const char* dname, const char** ecode);



BA_API int baRemove(const char* fname, const char** ecode);



BA_API int baRename(const char* from, const char* to, const char** ecode);

#ifdef __cplusplus
}
#endif

  

#endif


#ifndef __BasicAuthenticator_h
#define __BasicAuthenticator_h

typedef struct BasicAuthenticator
#ifdef __cplusplus
: public AuthenticatorIntf
{
      BasicAuthenticator(){}
      
      BasicAuthenticator(UserIntf* userDbIntf,
                         const char* realm,
                         LoginRespIntf* sendLogin);

      
      void setLoginTracker(LoginTracker* tracker);

      
      static void setAutHeader(const char* realm, HttpResponse* response);

#else
{
   AuthenticatorIntf superClass; 
#endif
      UserIntf* userDbIntf;
      LoginTracker* tracker;
      char* realm;
      LoginRespIntf* sendLogin;
      BaBool filterMsDomain; 
} BasicAuthenticator;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void BasicAuthenticator_constructor(
   BasicAuthenticator* o,
   UserIntf* userDbIntf,
   const char* realm,
   LoginRespIntf* sendLogin);
BA_API void BasicAuthenticator_destructor(BasicAuthenticator* o);
#define BasicAuthenticator_setLoginTracker(o,loginTracker) \
   (o)->tracker=loginTracker
#define BasicAuthenticator_setFilterMsDomain(o, state) \
  (o)->filterMsDomain=state
BA_API void BasicAuthenticator_setAutHeader(
   const char* realm,HttpResponse* resp);
#ifdef __cplusplus
}
inline BasicAuthenticator::BasicAuthenticator(UserIntf* userDbIntf,
                                              const char* realm,
                                              LoginRespIntf* sendLogin) {
   BasicAuthenticator_constructor(
      this,userDbIntf,realm,sendLogin); }
inline void BasicAuthenticator::setLoginTracker(LoginTracker* tracker) {
   BasicAuthenticator_setLoginTracker(this, tracker); }
inline void BasicAuthenticator::setAutHeader(
   const char* realm, HttpResponse* resp) {
   BasicAuthenticator_setAutHeader(realm,resp); }
#endif

 

#endif


#ifndef __DigestAuthenticator_h
#define __DigestAuthenticator_h

typedef struct DigestAuthenticator
#ifdef __cplusplus
: public AuthenticatorIntf
{
      DigestAuthenticator(){}

      
      DigestAuthenticator(UserIntf* userDbIntf,
                          const char* realm,
                          LoginRespIntf* sendLogin);

      
      void setLoginTracker(LoginTracker* tracker);

      
      static void setAutHeader(const char* realm, HttpResponse* response);

      
      void setStrictMode(bool enableStrictMode=false);

#else
{
   AuthenticatorIntf superClass; 
#endif
      UserIntf* userDbIntf;
      LoginTracker* tracker;
      char* realm;
      LoginRespIntf* sendLogin;
      BaBool strictMode;
      BaBool filterMsDomain; 
} DigestAuthenticator;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void DigestAuthenticator_constructor(
   DigestAuthenticator* o,
   UserIntf* userDbIntf,
   const char* realm,
   LoginRespIntf* sendLogin);
BA_API void DigestAuthenticator_destructor(DigestAuthenticator* o);
#define DigestAuthenticator_setLoginTracker(o,loginTracker) \
  (o)->tracker=loginTracker
#define DigestAuthenticator_setFilterMsDomain(o, state) \
  (o)->filterMsDomain=state
BA_API void DigestAuthenticator_setAutHeader(
   const char*,HttpResponse*);
#define DigestAuthenticator_setStrictMode(o, enableStrictMode) \
  (o)->strictMode=enableStrictMode
BA_API BaBool DigestAuthenticator_isDigest(AuthenticatedUser* user);
#ifdef __cplusplus
}
inline DigestAuthenticator::DigestAuthenticator(UserIntf* userDbIntf,
                                                const char* realm,
                                                LoginRespIntf* sendLogin) {
   DigestAuthenticator_constructor(this,userDbIntf,realm,sendLogin);
}
inline void DigestAuthenticator::setLoginTracker(LoginTracker* tracker) {
   DigestAuthenticator_setLoginTracker(this, tracker);
}
inline void DigestAuthenticator::setAutHeader(
   const char* realm, HttpResponse* resp) {
   DigestAuthenticator_setAutHeader(realm,resp); }
inline void DigestAuthenticator::setStrictMode(bool enableStrictMode) {
   DigestAuthenticator_setStrictMode(this, enableStrictMode ? TRUE : FALSE);
}

#endif

 

#endif

#ifndef _SharkSslCon_h
#define _SharkSslCon_h

#define SHARKSSL_LIB 1
#if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_SSL_CLIENT_CODE)

#define            SharkSsl_isServer(o) (o->role == SharkSsl_Server)
#define            SharkSsl_isClient(o) (o->role == SharkSsl_Client)

#elif SHARKSSL_SSL_SERVER_CODE

#define            SharkSsl_isServer(o) (1)
#define            SharkSsl_isClient(o) (0)

#elif SHARKSSL_SSL_CLIENT_CODE

#define            SharkSsl_isServer(o) (0)
#define            SharkSsl_isClient(o) (1)

#elif ((!SHARKSSL_ENABLE_RSA_API) && (!SHARKSSL_ENABLE_PEM_API))

#error NEITHER SERVER NOR CLIENT CODE SELECTED
#endif

#define SHARKSSL_CONTENT_TYPE_CHANGE_CIPHER_SPEC   20
#define SHARKSSL_CONTENT_TYPE_ALERT                21
#define SHARKSSL_CONTENT_TYPE_HANDSHAKE            22
#define SHARKSSL_CONTENT_TYPE_APPLICATION_DATA     23

#define SHARKSSL_HANDSHAKETYPE_HELLO_REQUEST       0
#define SHARKSSL_HANDSHAKETYPE_CLIENT_HELLO        1
#define SHARKSSL_HANDSHAKETYPE_SERVER_HELLO        2
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE         11
#define SHARKSSL_HANDSHAKETYPE_SERVER_KEY_EXCHANGE 12
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE_REQUEST 13
#define SHARKSSL_HANDSHAKETYPE_SERVER_HELLO_DONE   14
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE_VERIFY  15
#define SHARKSSL_HANDSHAKETYPE_CLIENT_KEY_EXCHANGE 16
#define SHARKSSL_HANDSHAKETYPE_FINISHED            20
#define SHARKSSL_HANDSHAKETYPE_COMPLETE            0xFF

#define SHARKSSL_HASHALGORITHM_NONE                0x00
#define SHARKSSL_HASHALGORITHM_MD5                 0x01
#define SHARKSSL_HASHALGORITHM_SHA1                0x02
#define SHARKSSL_HASHALGORITHM_SHA224              0x03
#define SHARKSSL_HASHALGORITHM_SHA256              0x04
#define SHARKSSL_HASHALGORITHM_SHA384              0x05
#define SHARKSSL_HASHALGORITHM_SHA512              0x06
#define SHARKSSL_HASHALGORITHM_TLS_MD5_SHA1        0xEE  

#define SHARKSSL_SIGNATUREALGORITHM_RSA            0x01
#define SHARKSSL_SIGNATUREALGORITHM_DSA            0x02
#define SHARKSSL_SIGNATUREALGORITHM_ECDSA          0x03
#define SHARKSSL_OID_EC_PUBLIC_KEY                 0x0C  

#define SHARKSSL_CLIENTCERTTYPE_RSA                0x01
#define SHARKSSL_CLIENTCERTTYPE_DSA                0x02
#define SHARKSSL_CLIENTCERTTYPE_ECDSA              0x40

#define TLS_EMPTY_RENEGOTIATION_INFO_SCSV          0x00FF

#define TLS_COMPRESSION_METHOD_NULL                0


#define TLS_EXTENSION_SERVER_NAME                  0 
#define TLS_EXTENSION_MAX_FRAGMENT_LENGTH          1
#define TLS_EXTENSION_CLIENT_CERTIFICATE_URL       2
#define TLS_EXTENSION_TRUSTED_CA_KEYS              3
#define TLS_EXTENSION_TRUNCATED_HMAC               4
#define TLS_EXTENSION_STATUS_REQUEST               5
#define TLS_EXTENSION_USER_MAPPPING                6
#define TLS_EXTENSION_CLIENT_AUTHZ                 7
#define TLS_EXTENSION_SERVER_AUTHZ                 8
#define TLS_EXTENSION_CERT_TYPE                    9
#define TLS_EXTENSION_ELLIPTIC_CURVES              10
#define TLS_EXTENSION_EC_POINT_FORMATS             11
#define TLS_EXTENSION_SRP                          12
#define TLS_EXTENSION_SIGNATURE_ALGORITHM          13
#define TLS_EXTENSION_USE_SRTP                     14
#define TLS_EXTENSION_HEARTBEAT                    15
#define TLS_EXTENSION_APPL_LAYER_PROT_NEGOTIATION  16
#define TLS_EXTENSION_STATUS_REQUEST_V2            17
#define TLS_EXTENSION_SIGNED_CERTIFICATE_TIMESTAMP 18
#define TLS_EXTENSION_SESSION_TICKET               35
#define TLS_EXTENSION_RENEGOTIATION_INFO           0xFF01


#define TLS_NAMEDCURVE_SECP192R1                   19
#define TLS_NAMEDCURVE_SECP224R1                   21
#define TLS_NAMEDCURVE_SECP256R1                   23
#define TLS_NAMEDCURVE_SECP384R1                   24
#define TLS_NAMEDCURVE_SECP521R1                   25



#define TLS_ECPOINTFORMAT_UNCOMPRESSED             0
#define TLS_ECPOINTFORMAT_ANSIX962_COMP_PRIME      1
#define TLS_ECPOINTFORMAT_ANSIX962_COMP_CHAR2      2



#define TLS_ECCURVETYPE_EXPLICIT_PRIME             1
#define TLS_ECCURVETYPE_EXPLICIT_CHAR2             2
#define TLS_ECCURVETYPE_NAMED_CURVE                3



#if (!SHARKSSL_ENABLE_RSA)
#if SHARKSSL_ENABLE_DHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_DHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#endif


#if SHARKSSL_USE_ECC
#if ((!SHARKSSL_ECC_USE_SECP192R1) && (!SHARKSSL_ECC_USE_SECP224R1) && (!SHARKSSL_ECC_USE_SECP256R1) && \
      (!SHARKSSL_ECC_USE_SECP384R1) && (!SHARKSSL_ECC_USE_SECP521R1))
#error no elliptic curve selected
#endif
#else
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDHE_ECDSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDH_ECDSA is enabled
#endif

#if (!SHARKSSL_ENABLE_RSA)
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#endif  

#if SHARKSSL_ENABLE_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDSA is enabled
#else
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#error SHARKSSL_ENABLE_ECDSA must be selected when SHARKSSL_ENABLE_ECDHE_ECDSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_ECDSA
#error SHARKSSL_ENABLE_ECDSA must be selected when SHARKSSL_ENABLE_ECDH_ECDSA is enabled
#endif
#endif  
#endif  



#if SHARKSSL_USE_NULL_CIPHER
#define SHARKSSL_SSL_RSA_WITH_NULL_SHA             TLS_RSA_WITH_NULL_SHA
#if SHARKSSL_ENABLE_MD5_CIPHERSUITES
#define SHARKSSL_SSL_RSA_WITH_NULL_MD5             TLS_RSA_WITH_NULL_MD5
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_NULL_SHA           TLS_ECDHE_RSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_NULL_SHA            TLS_ECDH_RSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_NULL_SHA         TLS_ECDHE_ECDSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_NULL_SHA          TLS_ECDH_ECDSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_NULL_SHA256          TLS_RSA_WITH_NULL_SHA256
#endif  
#endif  

#if SHARKSSL_USE_ARC4
#define SHARKSSL_SSL_RSA_WITH_ARC4_128_SHA         TLS_RSA_WITH_RC4_128_SHA
#if SHARKSSL_ENABLE_MD5_CIPHERSUITES
#define SHARKSSL_SSL_RSA_WITH_ARC4_128_MD5         TLS_RSA_WITH_RC4_128_MD5
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_ARC4_128_SHA       TLS_ECDHE_RSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_ARC4_128_SHA        TLS_ECDH_RSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_ARC4_128_SHA     TLS_ECDHE_ECDSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_ARC4_128_SHA      TLS_ECDH_ECDSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_ARC4_128_SHA             TLS_PSK_WITH_RC4_128_SHA
#endif
#endif

#if SHARKSSL_USE_DES
#define SHARKSSL_SSL_RSA_WITH_DES_CBC_SHA          TLS_RSA_WITH_DES_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_DES_CBC_SHA          TLS_DHE_RSA_WITH_DES_CBC_SHA
#endif
#endif

#if SHARKSSL_USE_3DES
#define SHARKSSL_SSL_RSA_WITH_3DES_EDE_CBC_SHA     TLS_RSA_WITH_3DES_EDE_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA     TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA   TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_3DES_EDE_CBC_SHA    TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA  TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_3DES_EDE_CBC_SHA         TLS_PSK_WITH_3DES_EDE_CBC_SHA
#endif
#endif

#if SHARKSSL_USE_AES_128
#define SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA      TLS_RSA_WITH_AES_128_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA      TLS_DHE_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA     TLS_ECDH_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA  TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA   TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_AES_128_CBC_SHA          TLS_PSK_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA256   TLS_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_GCM_SHA256   TLS_RSA_WITH_AES_128_GCM_SHA256
#endif  
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_CCM          TLS_RSA_WITH_AES_128_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_CCM_8        TLS_RSA_WITH_AES_128_CCM_8
#endif  
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA256   TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_GCM_SHA256   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
#endif  
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_CCM          TLS_DHE_RSA_WITH_AES_128_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_CCM_8        TLS_DHE_RSA_WITH_AES_128_CCM_8
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256 TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256 TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA256  TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_RSA_WITH_AES_128_GCM_SHA256  TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA256 TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_GCM_SHA256 TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#endif  
#endif  

#if SHARKSSL_USE_AES_256
#define SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA      TLS_RSA_WITH_AES_256_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA      TLS_DHE_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA     TLS_ECDH_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA  TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA   TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_AES_256_CBC_SHA          TLS_PSK_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA256   TLS_RSA_WITH_AES_256_CBC_SHA256
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_CCM          TLS_RSA_WITH_AES_256_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_CCM_8        TLS_RSA_WITH_AES_256_CCM_8
#endif  
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA256   TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_256_CCM          TLS_DHE_RSA_WITH_AES_256_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_256_CCM_8        TLS_DHE_RSA_WITH_AES_256_CCM_8
#endif  
#endif  
#if SHARKSSL_USE_SHA_384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_GCM_SHA384   TLS_RSA_WITH_AES_256_GCM_SHA384
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_GCM_SHA384   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384 TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384 TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA384  TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_RSA_WITH_AES_256_GCM_SHA384  TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA384 TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_GCM_SHA384 TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#endif  
#endif  
#endif  


#define SHARKSSL_MD5_MAC_LEN                       16
#define SHARKSSL_SHA1_MAC_LEN                      20
#define SHARKSSL_SHA256_MAC_LEN                    32
#define SHARKSSL_SHA384_MAC_LEN                    48
#define SHARKSSL_SHA512_MAC_LEN                    64

#define SHARKSSL_MD5_BLOCK_LEN                     64
#define SHARKSSL_SHA1_BLOCK_LEN                    64
#define SHARKSSL_SHA256_BLOCK_LEN                  64
#define SHARKSSL_SHA384_BLOCK_LEN                  128
#define SHARKSSL_SHA512_BLOCK_LEN                  128

#define SHARKSSL_FINISHED_MSG_LEN_SSL              36   
#define SHARKSSL_FINISHED_MSG_LEN_TLS              12   
#if SHARKSSL_ENABLE_SSL_3_0
#define SHARKSSL_MAX_FINISHED_MSG_LEN              SHARKSSL_FINISHED_MSG_LEN_SSL
#else
#define SHARKSSL_MAX_FINISHED_MSG_LEN              SHARKSSL_FINISHED_MSG_LEN_TLS
#endif

#define SHARKSSL_RECORD_HEADER_SIZE                5    
#define SHARKSSL_HANDSHAKE_HEADER_SIZE             4    
#define SHARKSSL_MAX_SESSION_ID_LEN                32   
#define SHARKSSL_SEQ_NUM_LEN                       8    
#define SHARKSSL_RANDOM_LEN                        32   
#define SHARKSSL_MASTER_SECRET_LEN                 48   


#if SHARKSSL_ENABLE_TLS_1_2
#if   SHARKSSL_USE_SHA_512
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA512_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA512_BLOCK_LEN
#elif SHARKSSL_USE_SHA_384
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA384_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA384_BLOCK_LEN
#else
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA256_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA256_BLOCK_LEN
#endif  
#else
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA1_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA1_BLOCK_LEN
#endif  
#define SHARKSSL_MAX_DIGEST_PAD_LEN                48   
#define SHARKSSL_MAX_REC_LEN                       (16384 + 2048) 
#define SHARKSSL_MAX_REC_PAD_LEN                   SHARKSSL_MAX_BLOCK_LEN

#if   SHARKSSL_USE_AES_256
#define SHARKSSL_MAX_KEY_LEN                       32   
#elif SHARKSSL_USE_3DES
#define SHARKSSL_MAX_KEY_LEN                       24   
#elif (SHARKSSL_USE_AES_128 || SHARKSSL_USE_ARC4)
#define SHARKSSL_MAX_KEY_LEN                       16   
#elif SHARKSSL_USE_DES
#define SHARKSSL_MAX_KEY_LEN                        8   
#elif SHARKSSL_USE_NULL_CIPHER
#define SHARKSSL_MAX_KEY_LEN                        0   
#else
#error At least one cipher must be selected in SharkSSL_cfg.h 
#endif

#if   (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)
#define SHARKSSL_MAX_BLOCK_LEN                     16   
#elif (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)
#define SHARKSSL_MAX_BLOCK_LEN                     8    
#else
#define SHARKSSL_MAX_BLOCK_LEN                     0    
#endif



#ifndef UPTR
#define UPTR                                       U32
#endif
#ifndef SHARKSSL_ALIGNMENT
#define SHARKSSL_ALIGNMENT                         4   
#endif 
#define SHARKSSL_ALIGN_SIZE(s)                     (((s) + (SHARKSSL_ALIGNMENT - 1)) & ((U32)-SHARKSSL_ALIGNMENT))
#define SHARKSSL_ALIGNED_POINTER(p)                (U8*)(((UPTR)((UPTR)(p) + SHARKSSL_ALIGNMENT - 1)) & ((UPTR)-SHARKSSL_ALIGNMENT))
#define SHARKSSL_POINTER_IS_ALIGNED(p)             (0 == ((unsigned int)(UPTR)(p) & (SHARKSSL_ALIGNMENT - 1)))

#if SHARKSSL_UNALIGNED_MALLOC
#define SHARKSSL_MALLOC_ALIGN(s)                   ((s) + SHARKSSL_ALIGNMENT)
#define SHARKSSL_PNTR_ALIGNMENT(p)                 SHARKSSL_ALIGNED_POINTER(p)
#else
#define SHARKSSL_MALLOC_ALIGN(s)                   (s)
#define SHARKSSL_PNTR_ALIGNMENT(p)                 (U8*)(p)
#endif


#define SHARKSSL_DIM_ARR(a)                        (sizeof(a)/sizeof(a[0]))
 
#define SHARKSSL_BUF_EXPANDSIZE                    1024                                                                  
#define SHARKSSL_BUF_HEADROOM_SIZE                 (SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_SEQ_NUM_LEN)



#if (SHARKSSL_MAX_BLOCK_LEN <= (SHARKSSL_FINISHED_MSG_LEN_SSL - SHARKSSL_FINISHED_MSG_LEN_TLS))
#define SHARKSSL_HS_PARAM_OFFSET                   SHARKSSL_ALIGN_SIZE(SHARKSSL_RECORD_HEADER_SIZE + 1 + \
                                                                       SHARKSSL_RECORD_HEADER_SIZE + \
                                                                       SHARKSSL_FINISHED_MSG_LEN_SSL + \
                                                                       SHARKSSL_MAX_DIGEST_LEN + \
                                                                       SHARKSSL_MAX_REC_PAD_LEN)
#else
#define SHARKSSL_HS_PARAM_OFFSET                   SHARKSSL_ALIGN_SIZE(SHARKSSL_RECORD_HEADER_SIZE + 1 + \
                                                                       SHARKSSL_RECORD_HEADER_SIZE + \
                                                                       SHARKSSL_MAX_BLOCK_LEN + \
                                                                       SHARKSSL_FINISHED_MSG_LEN_TLS + \
                                                                       SHARKSSL_MAX_DIGEST_LEN + \
                                                                       SHARKSSL_MAX_REC_PAD_LEN)
#endif

#define SHARKSSL_FLAG_HAS_MORE_DATA                0x00000001
#define SHARKSSL_FLAG_SPLIT_ENCRYPT                0x00000002
#define SHARKSSL_FLAG_CHANGECIPHERSPEC_RECEIVED    0x00000004
#define SHARKSSL_FLAG_TMPBUF_CREATED               0x00000008
#define SHARKSSL_FLAG_DECRYPT_INITIALIZE           0x00000010
#define SHARKSSL_FLAG_INVALID_CON                  0x00000020
#define SHARKSSL_FLAG_ALERTED_CON                  0x00000040
#define SHARKSSL_FLAG_ZERO_LEN_APPLI               0x00000080
#define SHARKSSL_FLAG_CREATE_CLIENT_HELLO          0x00000100
#define SHARKSSL_FLAG_RESUMED_SESSION              0x00000200
#define SHARKSSL_FLAG_CERTIFICATE_REQUEST          0x00000400
#define SHARKSSL_FLAG_CERTIFICATE_REQUESTED        0x00000800
#define SHARKSSL_FLAG_HAS_CERTIFICATE              0x00001000
#define SHARKSSL_FLAG_EMPTY_CERTIFICATE            0x00002000
#define SHARKSSL_FLAG_TRUSTED_CA                   0x00004000
#define SHARKSSL_FLAG_SECURE_RENEGOTIATION         0x00008000
#define SHARKSSL_FLAG_RENEGOTIATION_REQUESTED      0x00010000
#define SHARKSSL_FLAG_RENEGOTIATION_SUBMITTED      0x00020000
#define SHARKSSL_FLAG_RENEGOTIATION_ONGOING        0x00040000  
#define SHARKSSL_FLAG_HANDSHAKE_DATA_IN_OUTBUF     0x00080000
#define SHARKSSL_FLAG_CACHED_SESSION               0x00100000
#define SHARKSSL_FLAG_HANDSHAKE_FINISHED           0x00200000
#define SHARKSSL_FLAG_FAVOR_RSA                    0x00400000


#define SHARKSSL_OP_INITIALIZE                     0x01
#define SHARKSSL_OP_FINALIZE                       0x02
#define SHARKSSL_OP_DESTRUCTOR                     (SHARKSSL_OP_INITIALIZE | SHARKSSL_OP_FINALIZE)
#define SHARKSSL_OP_ENCRYPT                        0x10
#define SHARKSSL_OP_DECRYPT                        0x20
#define SHARKSSL_OP_PUBLIC                         0x40  
#define SHARKSSL_OP_PRIVATE                        0x80  
#define SHARKSSL_OP_CALC_Y                         0x04  
#define SHARKSSL_OP_CALC_XY                        0x04  
#define SHARKSSL_OP_CALC_KEY                       0x08  
#define SHARKSSL_OP_SIGN                           0x10  
#define SHARKSSL_OP_VERIFY                         0x20  



#define SHARKSSL_CS_DHE                            0x0001
#define SHARKSSL_CS_EC                             0x0002
#define SHARKSSL_CS_DSA                            0x0004
#define SHARKSSL_CS_RSA                            0x0008
#define SHARKSSL_CS_PSK                            0x0010
#define SHARKSSL_CS_AEAD                           0x0020  
#define SHARKSSL_CS_TLS12                          0x0080
#define SHARKSSL_CS_SHA384                         0x0100
#define SHARKSSL_CS_SHA512                         0x0200
#define SHARKSSL_CS_SUITE_B                        0x0400



#define SHARKSSL_EXPLEN_GET_EXPLEN(e)              (U16)((e) & 0x00FF)
#define SHARKSSL_EXPLEN_GET_FORMAT(e)              (U16)(((U16)(e) & 0x0F00) >> 8)
#define SHARKSSL_EXPLEN_GET_CHAINLEN(e)            (U16)(((U16)(e) & 0xF000) >> 12)

#define SHARKSSL_EXPLEN_KEYTYPE_RSA                0x0
#define SHARKSSL_EXPLEN_KEYTYPE_EC                 0x2
#define SHARKSSL_EXPLEN_KEYTYPE_MASK               0x6
#define SHARKSSL_EXPLEN_PUBLIC_KEY                 0x8

#define SHARKSSL_EXPLEN_IS_PUBKEY(e)               (SHARKSSL_EXPLEN_GET_FORMAT(e) & SHARKSSL_EXPLEN_PUBLIC_KEY)
#define SHARKSSL_EXPLEN_GET_KEYTYPE(e)             (SHARKSSL_EXPLEN_GET_FORMAT(e) & SHARKSSL_EXPLEN_KEYTYPE_MASK)
#define SHARKSSL_EXPLEN_IS_KEYTYPE_RSA(e)          (SHARKSSL_EXPLEN_GET_KEYTYPE(e) == SHARKSSL_EXPLEN_KEYTYPE_RSA)
#define SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e)           (SHARKSSL_EXPLEN_GET_KEYTYPE(e) == SHARKSSL_EXPLEN_KEYTYPE_EC)


#define SHARKSSL_EXPLEN_SET_KEYTYPE_RSA_PUBLIC(e)  (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_RSA + SHARKSSL_EXPLEN_PUBLIC_KEY) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_RSA_PRIVATE(e) (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_RSA) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_EC_PUBLIC(e)   (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_EC + SHARKSSL_EXPLEN_PUBLIC_KEY) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_EC_PRIVATE(e)  (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_EC) << 8);



#define SHARKSSL_MODLEN_GET_EC_PUBLEN(m)           (U16)((m) & 0x00FF)
#define SHARKSSL_MODLEN_GET_RSA_MODLEN(m)          (m)
#define SHARKSSL_MODLEN_GET_EC_OID(m)              (U16)(((U16)(m) & 0xFF00) >> 8)
#define SHARKSSL_MODLEN_GET_RSA_OID(m)             0

#define SHARKSSL_MODLEN_GET_MODLEN(m, e)           (SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e) ? SHARKSSL_MODLEN_GET_EC_PUBLEN(m) : SHARKSSL_MODLEN_GET_RSA_MODLEN(m))
#define SHARKSSL_MODLEN_GET_OID(m, e)              (SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e) ? SHARKSSL_MODLEN_GET_EC_OID(m) : SHARKSSL_MODLEN_GET_RSA_OID(m))


#define SHARKSSL_MODLEN_SET_OID(m, o)              (m = (((U16)l & 0xFF) << 8) | (m & 0xFF))



#if (SHARKSSL_ENABLE_CA_LIST  || SHARKSSL_ENABLE_CERTSTORE_API)
#define SHARKSSL_CA_LIST_NAME_SIZE                 8  
#define SHARKSSL_CA_LIST_ELEMENT_SIZE              (SHARKSSL_CA_LIST_NAME_SIZE + 4)
#define SHARKSSL_CA_LIST_INDEX_TYPE                0x00  

#ifdef __IAR_SYSTEMS_ICC__

#else
#if (SHARKSSL_CA_LIST_NAME_SIZE != SHARKSSL_ALIGN_SIZE(SHARKSSL_CA_LIST_NAME_SIZE))
#error SHARKSSL CA_STORE_API: UNSUPPORTED CA_LIST_NAME_SIZE
#endif
#endif

#if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_ENABLE_CERTSTORE_API)
#define SHARKSSL_CA_LIST_PTR_SIZE                  sizeof(U8*)
#define SHARKSSL_CA_LIST_PTR_TYPE                  0xAD
#define SHARKSSL_MAX_SNAME_LEN                     32

#if (SHARKSSL_MAX_SNAME_LEN < SHARKSSL_CA_LIST_NAME_SIZE)
#error SHARKS_MAX_SNAME_LEN must be >= SHARKSSL_CA_LIST_NAME_SIZE
#endif

typedef struct SharkSslCSCert
{
      DoubleLink super;
      U8 *ptr;  
      char name[SHARKSSL_MAX_SNAME_LEN + 1];  
} SharkSslCSCert;

#endif  
#endif  
 

typedef struct SharkSslBuf
{
   #if SHARKSSL_UNALIGNED_MALLOC
   U8  *mem;     
   #endif
   U8  *buf;     
   U8  *data;    
   U16  size;    
   U16  dataLen; 
   U16  temp;
} SharkSslBuf;

void    SharkSslBuf_constructor(SharkSslBuf*, U16);
void    SharkSslBuf_destructor(SharkSslBuf*);
U8     *SharkSslBuf_expand(SharkSslBuf*, U16);
void    SharkSslBuf_leftAlignData(SharkSslBuf*);
#define SharkSslBuf_notAllocated(o) (!((o)->buf))
#define SharkSslBuf_dataPtrLeftAligned(o) \
   ((o)->buf + SHARKSSL_BUF_HEADROOM_SIZE)
#define SharkSslBuf_isLeftAligned(o) \
   ((o)->data == SharkSslBuf_dataPtrLeftAligned(o))
#define SharkSslBuf_leftAlignDataPtr(o) do {\
   (o)->data = SharkSslBuf_dataPtrLeftAligned(o); \
   } while (0)
#if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
#define SharkSslBuf_cloneHeader(dest, src) \
   memcpy((U8*)((dest)->buf), (U8*)((src)->buf), SHARKSSL_BUF_HEADROOM_SIZE)
#endif



typedef int (*SharkSslCon_cipherFunc)(SharkSslCon*, U8, U8*, U16);
typedef int (*SharkSslCon_digestFunc)(SharkSslCon*, const U8*, U16, U8*);


typedef struct SharkSslCipherSuite
{
   SharkSslCon_cipherFunc cipherFunc;
   SharkSslCon_digestFunc digestFunc;
   U16 id;
   U16 flags;
   U8  keyLen;
   U8  blockLen;
   U8  digestLen;
} SharkSslCipherSuite;


#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
typedef struct SharkSslCertParsed
{
   SharkSslCert cert;
   U16 msgLen;    
   U8  keyType;
   U8  keyOID;
   U8  signatureAlgo;
   U8  hashAlgo;
} SharkSslCertParsed;


typedef struct SharkSslCertList
{
   SingleLink link;
   SharkSslCertParsed certP;
} SharkSslCertList;
 

typedef struct SharkSslCertKey
{
   U8 *mod, *exp;
   U16 modLen, expLen;
} SharkSslCertKey;


typedef struct SharkSslSignature
{
   #if (SHARKSSL_MAX_DIGEST_LEN > (SHARKSSL_MD5_MAC_LEN + SHARKSSL_SHA1_MAC_LEN))
   U8 hash[SHARKSSL_MAX_DIGEST_LEN];
   #else
   U8 hash[SHARKSSL_MD5_MAC_LEN + SHARKSSL_SHA1_MAC_LEN];
   #endif
   U8 *signature;
   U16 signLen;
   U8  signatureAlgo;
   U8  hashAlgo;
} SharkSslSignature;


typedef struct SharkSslCertParam
{
   SharkSslCertInfo  certInfo;
   SharkSslCertKey   certKey;
   SharkSslSignature signature;
} SharkSslCertParam;


typedef struct SharkSslSignParam  
{
   SharkSslCertKey  *pCertKey;
   SharkSslSignature signature; 
} SharkSslSignParam;


#if SHARKSSL_ENABLE_CLONE_CERTINFO
typedef struct SharkSslClonedCertInfo
{
   SharkSslCertInfo ci;
   #if SHARKSSL_ENABLE_SESSION_CACHE
   U8 flags;
   #endif
} SharkSslClonedCertInfo;



#define SHARKSSL_CCINFO_CERT_CLONED  0x01
#define SHARKSSL_CCINFO_CERT_CACHED  0x02
#endif  
#endif  


#if SHARKSSL_ENABLE_DHE_RSA
typedef struct SharkSslDHParam
{
   U8 *p;     
   U8 *g;     
   U8 *Y;     
   U8 *r;     
   U16 pLen;  
   U16 gLen;  
} SharkSslDHParam;
#endif


#if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
typedef struct SharkSslECDHParam
{
   U8 *XY;         
   U8 *k;          
   U16 xLen;        
   U16 curveType;  
} SharkSslECDHParam;
#endif


#if SHARKSSL_ENABLE_ECDSA
typedef struct SharkSslECDSAParam
{
   U8 *R;          
   U8 *S;          
   U8 *key;        
   U8 *hash;       
   U16 keyLen;      
   U16 hashLen;    
   U16 curveType;  
} SharkSslECDSAParam;
#endif


typedef struct SharkSslHSParam
{
   U8  clientRandom[SHARKSSL_RANDOM_LEN];
   U8  serverRandom[SHARKSSL_RANDOM_LEN];
   U8  masterSecret[SHARKSSL_MASTER_SECRET_LEN];
   U8  sharedSecret[2 * (SHARKSSL_MAX_DIGEST_LEN +
                         SHARKSSL_MAX_KEY_LEN +
                         SHARKSSL_MAX_BLOCK_LEN) + SHARKSSL_MAX_DIGEST_LEN];
   SharkSslMd5Ctx      md5Ctx;
   SharkSslSha1Ctx     sha1Ctx;
   #if SHARKSSL_ENABLE_TLS_1_2
   SharkSslSha256Ctx   sha256Ctx;
   #if SHARKSSL_USE_SHA_384
   SharkSslSha384Ctx   sha384Ctx;
   #endif
   #if SHARKSSL_USE_SHA_512
   SharkSslSha384Ctx   sha512Ctx;
   #endif
   #endif
   #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
   SharkSslCertParsed *certParsed;  
   SharkSslCertKey     certKey;     
   SharkSslCertParam   certParam;   
   SharkSslSignParam   signParam;
   #endif
   #if SHARKSSL_ENABLE_DHE_RSA
   SharkSslDHParam     dhParam;
   #endif
   #if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
   SharkSslECDHParam   ecdhParam;
   #endif
   SharkSslCipherSuite *cipherSuite;
} SharkSslHSParam;


void    SharkSslHSParam_constructor(SharkSslHSParam*);
void    SharkSslHSParam_destructor(SharkSslHSParam*);
void    SharkSslHSParam_add(SharkSslHSParam*, U8*, U16);
#define hsParam(o) ((SharkSslHSParam*)(SharkSslBuf_dataPtrLeftAligned(&o->outBuf) + SHARKSSL_HS_PARAM_OFFSET))


#if SHARKSSL_ENABLE_SESSION_CACHE
struct SharkSslSession
{
   SharkSslCipherSuite *cipherSuite;
   U32 firstAccess, latestAccess;
   U8  id[SHARKSSL_MAX_SESSION_ID_LEN];
   U8  masterSecret[SHARKSSL_MASTER_SECRET_LEN];
   U16 nUse;
   U8  major_minor, flags;
   #if SHARKSSL_ENABLE_CLONE_CERTINFO
   SharkSslClonedCertInfo *clonedCertInfo;
   #endif
};

#define SharkSslSession_cmpMajMin(o,maj,min) ((o)->major_minor == (((maj & 0x0F) << 4) | (min & 0x0F)))
#define SharkSslSession_getMaj(o)            (((o)->major_minor & 0xF0) >> 4)
#define SharkSslSession_getMin(o)            ((o)->major_minor & 0x0F)
#define SharkSslSession_setMajMin(o,maj,min) do {           \
   baAssert((maj <= 0x0F) && (min <= 0x0F));                \
   (o)->major_minor = (((maj & 0x0F) << 4) | (min & 0x0F)); \
   } while (0);



#define SHARKSSL_SESSION_FLAG_TRUSTED_CA             0x80


void    SharkSslSessionCache_constructor(SharkSslSessionCache*, U16);
void    SharkSslSessionCache_destructor(SharkSslSessionCache*);
#define SharkSslSessionCache_lock(o)   ThreadMutex_set(&((o)->cacheMutex))
#define SharkSslSessionCache_unlock(o) ThreadMutex_release(&((o)->cacheMutex))
SharkSslSession *SharkSslSessionCache_newSession(SharkSslSessionCache*, SharkSslCon*, U8*, U16);
SharkSslSession *SharkSslSessionCache_findSession(SharkSslSessionCache*, SharkSslCon*, U8*, U16);
#endif


struct SharkSslCon   
{
   #if SHARKSSL_MAX_BLOCK_LEN
   U8 rIV[SHARKSSL_MAX_BLOCK_LEN];
   #endif
   #if SHARKSSL_MAX_KEY_LEN
   U8 rKey[SHARKSSL_MAX_KEY_LEN];
   #endif
   U8 rMacH[SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_MAX_DIGEST_LEN];

   #if SHARKSSL_MAX_BLOCK_LEN
   U8 wIV[SHARKSSL_MAX_BLOCK_LEN];
   #endif
   #if SHARKSSL_MAX_KEY_LEN
   U8 wKey[SHARKSSL_MAX_KEY_LEN];
   #endif
   U8 wMacH[SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_MAX_DIGEST_LEN];

   SharkSsl *sharkSsl;
   SharkSslCipherSuite *rCipherSuite, *wCipherSuite;
   #if SHARKSSL_ENABLE_SESSION_CACHE
   SharkSslSession *session;
   #endif

   void *rCtx, *wCtx;
   #if SHARKSSL_UNALIGNED_MALLOC
   SharkSslCon *mem;
   #endif

   #if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
   U8 clientVerifyData[SHARKSSL_MAX_FINISHED_MSG_LEN];
   U8 serverVerifyData[SHARKSSL_MAX_FINISHED_MSG_LEN];
   #endif

   #if ((SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA) && SHARKSSL_ENABLE_CLONE_CERTINFO)
   SharkSslClonedCertInfo *clonedCertInfo;
   #endif

   #if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH && (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA))
   SharkSslCAList caListCertReq;
   #endif

   SharkSslBuf inBuf, outBuf;
   #if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
   SharkSslBuf tmpBuf;
   #endif

   U32 flags;
   #if SHARKSSL_ENABLE_SSL_3_0
   U16 rSeq, wSeq;
   #endif
   U8 state;
   U8 reqMajor, reqMinor;
   U8 major, minor;
   U8 ccLen;
   U8 padLen;
   U8 alertLevel, alertDescr; 
   #if ((SHARKSSL_SSL_SERVER_CODE || SHARKSSL_SSL_CLIENT_CODE) && SHARKSSL_ENABLE_SELECT_CIPHERSUITE)
   #if (SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH > 0xFF)
   #error SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH must be lower than 256
   #endif
   U8 cipherSelection[SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH];
   U8 cipherSelCtr;
   #endif
};


typedef enum 
{
  SharkSslCon_SenderIsClient,
  SharkSslCon_SenderIsServer
  #if SHARKSSL_ENABLE_SSL_3_0
  #if ((SHARKSSL_SSL_CLIENT_CODE && (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)) || \
       (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH))
  ,
  SharkSslCon_NoSender  
  #endif
  #endif
} SharkSslCon_SendersRole;



#define SharkSsl_createCon2(o, sharkSslCon) do {\
   (o)->nCon++;\
   SharkSslCon_constructor(sharkSslCon, o);\
} while (0)



void               SharkSslCon_constructor(SharkSslCon *o, SharkSsl *sharkSsl);
void               SharkSslCon_destructor(SharkSslCon *o);


SharkSslCon_RetVal SharkSslCon_buildFatalMessage(SharkSslCon*, U8);
SharkSslCon_RetVal SharkSslCon_buildAlertMessage(SharkSslCon*, U8, U8);
SharkSslCon_RetVal SharkSslCon_processHandshake(SharkSslCon*, U8*, U16*, U8);
SharkSslCon_RetVal SharkSslCon_processChangeCipherSpec(SharkSslCon*, U8*, U16);
U8                *SharkSslCon_writeSslHeader(SharkSslCon*, U8, U8*, U16);
U16                SharkSslCon_calcSharedSecretLen(SharkSslCon*, SharkSslCipherSuite*);
int                SharkSslCon_calcCryptoParam(SharkSslCon*, U8*, U16, U8*, U16, U8[32], U8[32], U8*);
int                SharkSslCon_calcFinishedHash(SharkSslCon*, SharkSslCon_SendersRole, U8*, U8*);
int                SharkSslCon_buildFinished(SharkSslCon *o, SharkSslCon_SendersRole, U8*, U8*);
void               SharkSslCon_setHMacKey(SharkSslCon*, U8*, U8*, U8*, U8, U8);
int                SharkSslCon_calcMacAndEncrypt(SharkSslCon*, U8);
U8                 SharkSslCon_calcCCLen(SharkSslCon *o, SharkSslCipherSuite *cipherSuite);
void               SharkSslCon_invalidateCon(SharkSslCon*);

#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)

int  SharkSslSignParam_sign(SharkSslSignParam*);
int  SharkSslSignParam_verify(const SharkSslSignParam*);

int  SharkSslCertParam_parseCert(SharkSslCertParam*, U8*, U32, U8*);
U8   SharkSslCertDN_equal(const SharkSslCertDN*, const SharkSslCertDN*);
SHARKSSL_API U8 SharkSslCertKey_setFromSharkSslCert(SharkSslCertKey*, SharkSslCert);
#if SHARKSSL_ENABLE_CLIENT_AUTH
U8   SharkSslCert_CAfound(SharkSslCert, U8*, U16);
#endif
U8   SharkSslCert_outCert(SharkSslCert, U16, U8*);
U16  SharkSslCert_certMsgLen(SharkSslCert);
#if SHARKSSL_ENABLE_CLONE_CERTINFO
U8   SharkSslCon_cloneCertInfo(SharkSslCon *o, SharkSslClonedCertInfo **outCertInfoPtr);
#endif
#if SHARKSSL_USE_ECC
U8   sharkssl_EC_getPointLen(U16 curveOID);
#endif
#endif

int  SharkSslCon_md5(SharkSslCon*, const U8*, U16, U8*);
int  SharkSslCon_sha1(SharkSslCon*, const U8*, U16, U8*);
#if SHARKSSL_USE_SHA_384
int  SharkSslCon_sha384(SharkSslCon*, const U8*, U16, U8*);
#endif
#if SHARKSSL_USE_SHA_256
int  SharkSslCon_sha256(SharkSslCon*, const U8*, U16, U8*);
#endif
int  SharkSslCon_HMAC(SharkSslCon *, U8, U8*, U16, U8*, U8, U8, SharkSslCon_digestFunc);
#if SHARKSSL_ENABLE_RSA   
SHARKSSL_API int  SharkSslCertKey_RSA(const SharkSslCertKey*, U8, U8*);
int SharkSslCertKey_RSA_public_encrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_private_decrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_private_encrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_public_decrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
#endif
#if SHARKSSL_ENABLE_DHE_RSA
int  SharkSslDHParam_DH(const SharkSslDHParam*, U8 op, U8*);
#if SHARKSSL_SSL_SERVER_CODE
void SharkSslDHParam_setParam(SharkSslDHParam *dh);
#endif
#endif  
#if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
int  SharkSslECDHParam_ECDH(const SharkSslECDHParam*, U8 op, U8*);
#endif
#if SHARKSSL_ENABLE_ECDSA
int SharkSslECDSAParam_ECDSA(const SharkSslECDSAParam*, U8 op);
#endif
#if SHARKSSL_USE_NULL_CIPHER
int  SharkSslCon_null(SharkSslCon*, U8, U8*, U16);
#endif
#if SHARKSSL_USE_ARC4
int  SharkSslCon_arc4(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)
int  SharkSslCon_des_cbc(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)
int  SharkSslCon_aes_cbc(SharkSslCon*, U8, U8*, U16);
#if (SHARKSSL_ENABLE_AES_GCM && SHARKSSL_ENABLE_TLS_1_2)
int  SharkSslCon_aes_gcm(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_ENABLE_AES_CCM && SHARKSSL_ENABLE_TLS_1_2)
int  SharkSslCon_aes_ccm(SharkSslCon*, U8, U8*, U16);
#endif
#endif

#endif


#ifndef __FormAuthenticator_h
#define __FormAuthenticator_h

#ifndef __DOXYGEN__
typedef struct
{
      AuthenticatedUser superClass; 
      const char* errorMessagePage; 
      BaBool isFirstTime;
} FormAuthUser;
#endif





typedef struct FormAuthenticator
#ifdef __cplusplus
: public AuthenticatorIntf
{
      FormAuthenticator(){}
      
      FormAuthenticator(
         UserIntf* userDbIntf, const char* realm, LoginRespIntf* sendLogin);

      
      void setLoginTracker(LoginTracker* tracker);

      
      void setSecure();

#else
{
   AuthenticatorIntf superClass; 
#endif
      UserIntf* userDbIntf;
      LoginTracker* tracker;
      char* realm;
      LoginRespIntf* sendLogin;
      BaBool secure;
      U8 aesKey[32];
} FormAuthenticator;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void FormAuthenticator_constructor(
   FormAuthenticator* o,
   UserIntf* userDbIntf,
   const char* realm,
   LoginRespIntf* login);

#define FormAuthenticator_destructor(o) do { \
   if((o)->realm) baFree((o)->realm); (o)->realm=0;} while(0)

#define FormAuthenticator_setLoginTracker(o,loginTracker) \
   (o)->tracker=loginTracker

#define FormAuthenticator_setSecure(o) (o)->secure=TRUE

#ifdef __cplusplus
}
inline FormAuthenticator::FormAuthenticator(UserIntf* userDbIntf,
                                            const char* realm,
                                            LoginRespIntf* login) {
   FormAuthenticator_constructor(
      this, userDbIntf, realm, login);
}
inline void FormAuthenticator::setLoginTracker(LoginTracker* tracker) {
   FormAuthenticator_setLoginTracker(this, tracker);
}
inline void FormAuthenticator::setSecure() {
   FormAuthenticator_setSecure(this);
}
#endif

 


#endif


#ifndef __Authenticator_h
#define __Authenticator_h

typedef struct Authenticator
#ifdef __cplusplus
   : public AuthenticatorIntf
{
      
      Authenticator(UserIntf* userDbIntf,
                    const char* realm,
                    LoginRespIntf* sendLogin);


      
      void setLoginTracker(LoginTracker* tracker);

      
      BasicAuthenticator* getBasicAuthenticator();

      
      DigestAuthenticator* getDigestAuthenticator();

      
      FormAuthenticator* getFormAuthenticator();
#else
      {
         AuthenticatorIntf superClass; 
#endif
         BasicAuthenticator basicAuth;
         DigestAuthenticator digestAuth;
         FormAuthenticator  formAuth;
         int authpref;
      } Authenticator;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void Authenticator_constructor(Authenticator* o,
                               UserIntf* userDbIntf,
                               const char* realm,
                               LoginRespIntf* sendLogin);
BA_API void Authenticator_destructor(Authenticator* o);
#define Authenticator_setLoginTracker(o, loginTracker)\
   BasicAuthenticator_setLoginTracker(&(o)->basicAuth, loginTracker),\
   DigestAuthenticator_setLoginTracker(&(o)->digestAuth, loginTracker),\
   FormAuthenticator_setLoginTracker(&(o)->formAuth, loginTracker)
#define Authenticator_getBasicAuthenticator(o) (&(o)->basicAuth)
#define Authenticator_getDigestAuthenticator(o) (&(o)->digestAuth)
#define Authenticator_getFormAuthenticator(o) (&(o)->formAuth)
#ifdef __cplusplus
}
inline Authenticator::Authenticator(
   UserIntf* userDbIntf,
   const char* realm,
   LoginRespIntf* sendLogin) {
   Authenticator_constructor(this, userDbIntf, realm, sendLogin);
}
inline void Authenticator::setLoginTracker(LoginTracker* tracker) {
   Authenticator_setLoginTracker(this, tracker);
}
inline BasicAuthenticator* Authenticator::getBasicAuthenticator() {
   return Authenticator_getBasicAuthenticator(this);
}
inline DigestAuthenticator* Authenticator::getDigestAuthenticator() {
   return Authenticator_getDigestAuthenticator(this);
}
inline FormAuthenticator* Authenticator::getFormAuthenticator() {
   return Authenticator_getFormAuthenticator(this);
}
#endif

 


#endif


#ifndef __DavAuth_h
#define __DavAuth_h

typedef struct DavAuth
#ifdef __cplusplus
   : public AuthenticatorIntf
{
      
      DavAuth(UserIntf* userDbIntf, const char* realm);

      
      BasicAuthenticator* getBasicAuth();

      
      DigestAuthenticator* getDigestAuth();

      
      void setLoginTracker(LoginTracker* tracker);
#else
      {
         AuthenticatorIntf superClass; 
#endif
         LoginRespIntf sendLogin;
         BasicAuthenticator basicAuth;
         DigestAuthenticator digestAuth;
      } DavAuth;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void DavAuth_constructor(DavAuth* o,
                        UserIntf* userDbIntf,
                        const char* realm);

BA_API void DavAuth_destructor(DavAuth* o);
#define DavAuth_getBasicAuth(o) (&(o)->basicAuth)
#define DavAuth_getDigestAuth(o) (&(o)->digestAuth)
#define DavAuth_setLoginTracker(o, loginTracker) do{\
   BasicAuthenticator_setLoginTracker(&(o)->basicAuth, loginTracker);\
   DigestAuthenticator_setLoginTracker(&(o)->digestAuth, loginTracker);\
   }while(0)
#ifdef __cplusplus
}
inline DavAuth::DavAuth(UserIntf* userDbIntf,const char* realm) {
   DavAuth_constructor(this, userDbIntf, realm);
}
inline BasicAuthenticator* DavAuth::getBasicAuth() {
   return DavAuth_getBasicAuth(this);
}
inline DigestAuthenticator* DavAuth::getDigestAuth() {
   return DavAuth_getDigestAuth(this);
}
inline void DavAuth::setLoginTracker(LoginTracker* tracker) {
   DavAuth_setLoginTracker(this, tracker);
}
#endif

 


#endif


#ifndef __JUserCont_h
#define __JUserCont_h



#ifndef __JVal_h
#define __JVal_h



#ifndef __JParser_h
#define __JParser_h


typedef enum {
   
   JVType_InvalidType,
   
   JVType_String,
   
   JVType_Double,
   
   JVType_Int,
   
   JVType_Long,
   
   JVType_Boolean,
   
   JVType_Null,
   
   JVType_Object,
   
   JVType_Array
} JVType;


typedef enum
{
   
   JErrT_NoErr=0,
   
   JErrT_JsonErr,
   
   JErrT_WrongType,
   
   JErrT_InvalidMethodParams,
   
   JErrT_FmtValErr,
   
   JErrT_MemErr,
   
   JErrT_IOErr
} JErrT;


typedef struct JErr
{
#ifdef __cplusplus
      
      JErr();
      
      void reset();
      
      bool isError();
      
      bool noError();
      
      JErrT getErrT();
      
      JVType getExpT();
      
      JVType getRecT();
      int setTooFewParams();
      int setTypeErr(JVType expT, JVType recT);
      int setError(JErrT err,const char* msg);
#endif
      const char* msg;
      JErrT err;
      JVType expType;
      JVType recType;
} JErr;
#ifdef __cplusplus
extern "C" {
#endif
#define JErr_constructor(o) (o)->err=JErrT_NoErr
#define JErr_reset(o) (o)->err=JErrT_NoErr, (o)->msg=0
#define JErr_isError(o) (o)->err!=JErrT_NoErr
#define JErr_noError(o) (o)->err==JErrT_NoErr
#define JErr_getErrT(o) (o)->err
#define JErr_getExpT(o) (o)->expType
#define JErr_getRecT(o) (o)->recType
BA_API int JErr_setTooFewParams(JErr* o);
BA_API int JErr_setTypeErr(JErr* o, JVType expT, JVType recT);
BA_API int JErr_setError(JErr* o,JErrT err,const char* msg);
#ifdef __cplusplus
}
inline JErr::JErr() {
   JErr_constructor(this); }
inline void JErr::reset() {
   JErr_reset(this); }
inline bool JErr::isError() {
   return JErr_isError(this) ? true : false;}
inline bool JErr::noError() {
   return JErr_noError(this) ? true : false;}
inline JErrT JErr::getErrT() {
   return JErr_getErrT(this);}
inline JVType JErr::getExpT() {
   return JErr_getExpT(this);}
inline JVType JErr::getRecT() {
   return JErr_getRecT(this);}
inline int JErr::setTooFewParams() {
   return JErr_setTooFewParams(this);}
inline int JErr::setTypeErr(JVType expT, JVType recT) {
   return JErr_setTypeErr(this, expT, recT);}
inline int JErr::setError(JErrT err,const char* msg) {
   return JErr_setError(this,err,msg);}
#endif



#ifndef __DOXYGEN__
typedef struct
{
      AllocatorIntf* alloc;
      U8* buf;
      U32 index;
      size_t size;
} JDBuf;
#endif



typedef enum {
   JLexerT_Null,
   JLexerT_Boolean,
   JLexerT_Number,
   JLexerT_String,
   JLexerT_StartObject,
   JLexerT_StartArray,
   JLexerT_EndObject,
   JLexerT_EndArray,
   JLexerT_Comma, 
   JLexerT_MemberSep, 
   JLexerT_NeedMoreData, 
   JLexerT_ParseErr,
   JLexerT_MemErr
} JLexerT;



typedef enum {
   JLexerSt_StartComment,
   JLexerSt_EatComment,
   JLexerSt_EndComment,
   JLexerSt_EatCppComment,
   JLexerSt_TrueFalseNull,
   JLexerSt_String,
   JLexerSt_StringEscape,
   JLexerSt_StringUnicode,
   JLexerSt_Number,
   JLexerSt_GetNextToken
} JLexerSt;


#ifndef __DOXYGEN__
typedef struct
{
      JDBuf asmB;

      const U8* bufStart;
      const U8* bufEnd;
      const U8* tokenPtr;

      U32 unicode;
      S16 unicodeShift;

      
      const U8* typeChkPtr;
      U8 retVal;

      U8 state; 
      
       
      U8 sn;
      U8 isDouble; 
} JLexer;


typedef enum {
   JParserT_InvalidType=0,
   JParserT_String,
   JParserT_Double,
   JParserT_Int,
   JParserT_Long,   
   JParserT_Boolean,
   JParserT_Null,
   JParserT_StartObject,
   JParserT_StartArray,
   JParserT_EndObject,
   JParserT_EndArray
} JParserT;


typedef struct JParserVal
{
      union
      {
            U8* s; 
#ifndef NO_DOUBLE
            double f; 
#endif
            S32 d; 
            U64 l; 
            BaBool b;
      } v;
      char* memberName;
      JParserT t;
} JParserVal;


struct JParserIntf;
typedef int (*JParserIntf_Service)(
   struct JParserIntf* o, JParserVal* v, int recLevel);
#endif 


typedef struct JParserIntf
{
      JParserIntf_Service service;
} JParserIntf;

#define JParserIntf_constructor(o,serviceMA) (o)->service=serviceMA

#define JParserIntf_service(o, v, recLev) (o)->service(o,v,recLev)



typedef enum {

   
   JParsStat_DoneEOS=1,

   
   JParsStat_Done,


    
   JParsStat_NeedMoreData = 100,

   
   JParsStat_ParseErr = 200,

   
   JParsStat_IntfErr,

   
   JParsStat_MemErr
} JParsStat;


typedef enum {
   JParserSt_StartObj,
   JParserSt_EmptyArray,
   JParserSt_MemberName,
   JParserSt_MemberSep,
   JParserSt_Value,
   JParserSt_EndObj,
   JParserSt_Comma
} JParserSt;


typedef struct JParser
{
#ifdef __cplusplus
      
      JParser(JParserIntf* intf, AllocatorIntf* alloc);

      
      int parse(const U8* buf, U32 size);

      
      ~JParser();

      
      JParsStat getStatus();
#endif
      JDBuf stack;
      JLexer lexer;
      JParserVal val;
      JParserIntf* intf;
      JParsStat status;
      JParserSt state;
} JParser;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JParser_constructor(
   JParser* o, JParserIntf* intf, AllocatorIntf* alloc);
BA_API int JParser_parse(JParser* o, const U8* buf, U32 size);
BA_API void JParser_destructor(JParser* o);
#define JParser_getStatus(o) (o)->status
#ifdef __cplusplus
}
inline JParser::JParser(JParserIntf* intf, AllocatorIntf* alloc) {
   JParser_constructor(this, intf, alloc);}
inline int JParser::parse(const U8* buf, U32 size) {
   return JParser_parse(this, buf, size);}
inline JParser::~JParser() {
   JParser_destructor(this);}
inline JParsStat JParser::getStatus() {
   return JParser_getStatus(this);}
#endif

  

#endif
typedef struct JVal
{
#ifdef __cplusplus
      
      JVType getType();

      
      JVal* vget(JErr* err,const char** fmt, va_list* argList);

      
      JVal* get(JErr* err, const char* fmt, ...);

      
      S32 getInt(JErr* e);

      
      void setInt(JErr* e,S32 v);

      
      S64 getLong(JErr* e);

      
      void setLong(JErr* e,S64 v);

      
      double getDouble(JErr* e);

      
      void setDouble(JErr* e,double v);

      
      BaBool getBoolean(JErr* e);

      
      void setBoolean(JErr* e,BaBool v);

      
      void setNull(JErr* e);

      
      const char* getString(JErr* e);

      
      void setString(JErr* e, char* v);

      
      char* manageString(JErr* e);

      
      const char* getMemberName();

      
      char* manageMemberName();

      
      JVal* getNextElem();

      
      JVal* getObject(JErr* e);

      
      JVal* getArray(JErr* e);

      
      JVal* getJ(JErr* e);

      
      JVal* manageJ(JErr* e);

      
      S32 getLength(JErr* e);

      
      bool isObjectMember();

      
      int unlink(JVal* child);

      
      int addMember(JErr* e, const char* memberName,
                    JVal* child, AllocatorIntf* dAlloc);

      
      int add(JErr* e, JVal* child);

      
      void terminate(AllocatorIntf* vAlloc, AllocatorIntf* dAlloc);
#endif
      union
      {
            struct JVal* firstChild; 
            U8* s; 
#ifndef NO_DOUBLE
            double f; 
#endif
            S32 d; 
            S64 l; 
            BaBool b; 
      } v;

      char* memberName;
      struct JVal* next;
      JVType type;
} JVal;
#ifdef __cplusplus
extern "C" {
#endif
#define JVal_getType(o) (o)->type
BA_API JVal* JVal_vget(JVal* o,JErr* err,const char** fmt, va_list* argList);
BA_API JVal* JVal_get(JVal* o, JErr* err, const char* fmt, ...);
BA_API S32 JVal_getInt(JVal* o, JErr* e);
BA_API S64 JVal_getLong(JVal* o, JErr* e);
BA_API double JVal_getDouble(JVal* o, JErr* e);
BA_API BaBool JVal_getBoolean(JVal* o, JErr* e);
BA_API const char* JVal_getString(JVal* o, JErr* e);
BA_API char* JVal_manageString(JVal* o, JErr* e);
BA_API const char* JVal_getMemberName(JVal* o);
BA_API char* JVal_manageMemberName(JVal* o);
#define JVal_getNextElem(o) (o)->next
BA_API JVal* JVal_getObject(JVal* o, JErr* e);
BA_API JVal* JVal_getArray(JVal* o, JErr* e);
BA_API JVal* JVal_getJ(JVal* o, JErr* e);
BA_API JVal* JVal_manageJ(JVal* o, JErr* e);
BA_API S32 JVal_getLength(struct JVal* o, JErr* e);
#define JVal_isObjectMember(o) ((o)->memberName != 0) 
BA_API int JVal_unlink(JVal* o, JVal* child);
BA_API int JVal_addMember(JVal* o, JErr* e, const char* memberName,
                          JVal* child, AllocatorIntf* dAlloc);
BA_API int JVal_add(JVal* o, JErr* e, JVal* child);
BA_API void JVal_terminate(JVal* o, AllocatorIntf* vAlloc,
                           AllocatorIntf* dAlloc);
#define JVal_setInt(o, e, v) JVal_setX(o, e, JVType_Int, &v)
#define JVal_setLong(o, e, v) JVal_setX(o, e, JVType_Long, &v)
#define JVal_setDouble(o, e, v) JVal_setX(o, e, JVType_Double, &v)
#define JVal_setBoolean(o, e, v) JVal_setX(o, e, JVType_Boolean, &v)
#define JVal_setNull(o, e) JVal_setX(o, e, JVType_Null, 0)
#define JVal_setString(o, e, v) JVal_setX(o, e, JVType_String, v)
BA_API void JVal_setX(JVal* o, JErr* e, JVType t, void* v);
#ifdef __cplusplus
}
inline JVType JVal::getType(){
   return JVal_getType(this); }
inline JVal* JVal::vget(JErr* err,const char** fmt, va_list* argList){
   return JVal_vget(this,err,fmt, argList); }
inline JVal* JVal::get( JErr* err, const char* fmt, ...){
   JVal* retv; va_list argList;
   va_start(argList, fmt); 
   retv = JVal_vget(this,err,&fmt,&argList);
   va_end(argList);
   return retv; 
}
inline S32 JVal::getInt(JErr* e){
   return JVal_getInt(this, e); }
inline S64 JVal::getLong(JErr* e){
   return JVal_getLong(this, e); }
inline double JVal::getDouble(JErr* e){
   return JVal_getDouble(this, e); }
inline BaBool JVal::getBoolean(JErr* e){
   return JVal_getBoolean(this, e); }
inline const char* JVal::getString(JErr* e){
   return JVal_getString(this, e); }
inline char* JVal::manageString(JErr* e){
   return JVal_manageString(this, e); }
inline const char* JVal::getMemberName(){
   return JVal_getMemberName(this); }
inline char* JVal::manageMemberName(){
   return JVal_manageMemberName(this); }
inline JVal* JVal::getNextElem(){
   return JVal_getNextElem(this); }
inline JVal* JVal::getObject(JErr* e){
   return JVal_getObject(this, e); }
inline JVal* JVal::getArray(JErr* e){
   return JVal_getArray(this, e); }
inline JVal* JVal::getJ(JErr* e){
   return JVal_getJ(this, e); }
inline JVal* JVal::manageJ(JErr* e){
   return JVal_manageJ(this, e); }
inline S32 JVal::getLength(JErr* e){
   return JVal_getLength(this, e); }

inline void JVal::setInt(JErr* e,S32 v) {
  JVal_setInt(this, e, v); }
inline void JVal::setLong(JErr* e,S64 v) {
  JVal_setLong(this, e, v); }
inline void JVal::setDouble(JErr* e,double v) {
  JVal_setDouble(this, e, v); }
inline void JVal::setBoolean(JErr* e,BaBool v) {
  JVal_setBoolean(this, e, v); }
inline void JVal::setNull(JErr* e) {
  JVal_setNull(this, e); }
inline void JVal::setString(JErr* e, char* v) {
  JVal_setString(this, e, v); }
inline bool JVal::isObjectMember(){
   return JVal_isObjectMember(this) ? true : false; }
inline int JVal::unlink(JVal* child){
   return JVal_unlink(this, child); }
inline int JVal::addMember(JErr* e, const char* memberName,
                           JVal* child, AllocatorIntf* dAlloc) {
   return JVal_addMember(this, e, memberName, child, dAlloc); }
inline int JVal::add(JErr* e, JVal* child) {
   return JVal_add(this, e, child); }
inline void JVal::terminate(AllocatorIntf* vAlloc, AllocatorIntf* dAlloc){
   JVal_terminate(this, vAlloc, dAlloc); }
#endif


typedef enum
{
   JParserValFactStat_OK=0,
   JParserValFactStat_DMemErr,
   JParserValFactStat_VMemErr,
   JParserValFactStat_MaxNodes
} JParserValFactStat;


#ifdef __cplusplus
typedef struct JParserValFact : public JParserIntf
{
      
      JParserValFact(AllocatorIntf* vAlloc, AllocatorIntf* dAlloc);

      
      ~JParserValFact();

      
      JVal* getFirstVal();

      
      JVal* manageFirstVal();

      
      void termFirstVal();
#else
typedef struct JParserValFact
{
      JParserIntf super; 
#endif
      AllocatorIntf* dAlloc;
      AllocatorIntf* vAlloc;
      JVal** vStack;
      int vStackSize;
      U32 nodeCounter;
      U32 maxNodes;
      JParserValFactStat status;
} JParserValFact;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JParserValFact_constructor(
   JParserValFact* o, AllocatorIntf* vAlloc, AllocatorIntf* dAlloc);
#define JParserValFact_getFirstVal(o) \
   ((o)->vStack && *(o)->vStack ? *(o)->vStack : 0)
BA_API JVal* JParserValFact_manageFirstVal(JParserValFact* o);
BA_API void JParserValFact_termFirstVal(JParserValFact* o);
BA_API void JParserValFact_destructor(JParserValFact* o);
#ifdef __cplusplus
}
inline JParserValFact::JParserValFact(
   AllocatorIntf* vAlloc, AllocatorIntf* dAlloc){
   JParserValFact_constructor(this, vAlloc, dAlloc);}
inline JVal* JParserValFact::getFirstVal() {
   return JParserValFact_getFirstVal(this); }
inline JVal* JParserValFact::manageFirstVal() {
   return JParserValFact_manageFirstVal(this); }
inline void JParserValFact::termFirstVal() {
    JParserValFact_termFirstVal(this); }
inline JParserValFact::~JParserValFact() {
    JParserValFact_destructor(this); }
#endif


typedef struct JValFact
{
#ifdef __cplusplus
      
      JValFact(AllocatorIntf* vAlloc, AllocatorIntf* dAlloc);
      
      
      JVal* mkString(const char* v);

      
      JVal* mkDouble(double v);

      
      JVal* mkInt(S32 v);

      
      JVal* mkLong(S64 v);

      
      JVal* mkBoolean(bool v);

      
      JVal* mkNull();

      
      JVal* mkObject();

      
      JVal* mkArray();
#endif
      AllocatorIntf* dAlloc;
      AllocatorIntf* vAlloc;
} JValFact;
#ifdef __cplusplus
extern "C" {
#endif
#define JValFact_mkString(o, v) JValFact_mkVal(o, JVType_String, v)
#define JValFact_mkDouble(o, v) JValFact_mkVal(o, JVType_Double, &v)
#define JValFact_mkInt(o, v) JValFact_mkVal(o, JVType_Int, &v)
#define JValFact_mkLong(o, v) JValFact_mkVal(o, JVType_Long, &v)
#define JValFact_mkBoolean(o, v) JValFact_mkVal(o, JVType_Boolean, &v)
#define JValFact_mkNull(o) JValFact_mkVal(o, JVType_Null, 0)
#define JValFact_mkObject(o) JValFact_mkVal(o, JVType_Object, 0)
#define JValFact_mkArray(o) JValFact_mkVal(o, JVType_Array, 0)
BA_API void JValFact_constructor(
   JValFact* o, AllocatorIntf* vAlloc, AllocatorIntf* dAlloc);
BA_API JVal* JValFact_mkVal(JValFact* o, JVType t, const void* uv);
#ifdef __cplusplus
}
inline JValFact::JValFact(AllocatorIntf* vAlloc, AllocatorIntf* dAlloc) {
   JValFact_constructor(this,vAlloc, dAlloc); }
inline JVal* JValFact::mkString(const char* v) {
   return JValFact_mkString(this, v); }
inline JVal* JValFact::mkDouble(double v) {
   return JValFact_mkDouble(this, v); }
inline JVal* JValFact::mkInt(S32 v) {
   return JValFact_mkInt(this, v); }
inline JVal* JValFact::mkLong(S64 v) {
   return JValFact_mkLong(this, v); }
inline JVal* JValFact::mkBoolean(bool v) {
   BaBool b = v ? TRUE : FALSE;
   return JValFact_mkBoolean(this, b); }
inline JVal* JValFact::mkNull() {
   return JValFact_mkNull(this); }
inline JVal* JValFact::mkObject() {
   return JValFact_mkObject(this); }
inline JVal* JValFact::mkArray() {
   return JValFact_mkArray(this); }
#endif

 

#endif
typedef struct
{
      SplayTreeNode super;
      char* name; 
      char* pwd;  
      BaTime maxInactiveInterval;
      U16 noOfRoles;
      U16 maxUsers;
      BaBool recycle;
      BaBool pwdIsHA1; 
      
      U16 roles[1]; 
} JUser;


typedef struct
{
      SplayTreeNode super;
      U16 roleId;
      char name[1];
} JRole;


typedef struct JUserCont
#ifdef __cplusplus
   : public UserIntf
{
      JUserCont(AllocatorIntf* alloc);
      ~JUserCont();
      void setUserDb(JVal* usersVal, JErr* err);
#else
{
   UserIntf super; 
#endif

   SplayTree userdb;  
   SplayTree roledb;  
   AllocatorIntf* alloc;
   U32 noOfUsers;
   U16 nextUniqueRoleId;
} JUserCont;

#ifdef __cplusplus
extern "C" {
#endif
#define JUserCont_findUser(o, uname) \
  (JUser*)SplayTree_find(&(o)->userdb, uname)
U16 JUserCont_role2Id(JUserCont* o, const char* roleName);
U16* JUserCont_copyRoles(JUserCont* o,U16* roles,JVal* rolesVal,JErr* err);
BA_API void JUserCont_constructor(JUserCont* o, AllocatorIntf* alloc);
BA_API void JUserCont_destructor(JUserCont* o);
BA_API void JUserCont_setUserDb(JUserCont* o, JVal* usersVal, JErr* err);
#ifdef __cplusplus
}
inline JUserCont::JUserCont(AllocatorIntf* alloc) {
   JUserCont_constructor(this, alloc); }
inline JUserCont::~JUserCont() {
   JUserCont_destructor(this); }
inline void JUserCont::setUserDb(JVal* usersVal, JErr* err) {
   JUserCont_setUserDb(this, usersVal, err); }
#endif 

#endif


#ifndef __JConstrCont_h
#define __JConstrCont_h


#ifndef _HashTable_h
#define _HashTable_h

struct HashTableNode;

typedef void (*HashTableNode_terminate)(struct HashTableNode*, void* tmobj);

typedef struct HashTableNode
{
#ifdef __cplusplus
      HashTableNode(const char* name, HashTableNode_terminate terminate);
#endif
      SingleLink super;
      HashTableNode_terminate destructor;
      const char* name;
} HashTableNode;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HashTableNode_constructor(HashTableNode* o,
                               const char* name,
                               HashTableNode_terminate destructor);
#define HashTableNode_terminate(o, tmObj) (*o->destructor)(o, tmObj)
#ifdef __cplusplus
}
inline HashTableNode::HashTableNode(const char* name,
                                    HashTableNode_terminate destructor) {
   HashTableNode_constructor(this,name,destructor);
}
#endif

typedef int (*HashTable_CbFunc)(void* cbObj, struct HashTableNode*);

typedef struct HashTable
{
#ifdef __cplusplus
      static HashTable* create(U32 noOfHashElements,AllocatorIntf* alloctr=0);
      ~HashTable();
      void add(HashTableNode* node);
      HashTableNode* lookup(const char* ident);
      void setTmObj(void* obj);
#endif
      void* tmObj;
      U32 noOfHashElements;
      SingleList table[1]; 
} HashTable;

#ifdef __cplusplus
extern "C" {
#endif
BA_API HashTable* HashTable_create(U32 noOfHashElements, AllocatorIntf* alloc);
BA_API void HashTable_destructor(HashTable* o);
BA_API void HashTable_add(HashTable* o, HashTableNode* node);
#define HashTable_setTmObj(o, tmObjMA) (o)->tmObj=tmObjMA
BA_API HashTableNode* HashTable_lookup(HashTable* o, const char* ident);
BA_API int HashTable_iter(HashTable* o, void* cbObj, HashTable_CbFunc cbFunc);
#ifdef __cplusplus
}
inline HashTable* HashTable::create(U32 noOfHashElements, AllocatorIntf* alloc)
{
   return HashTable_create(noOfHashElements, alloc);
}
inline HashTable::~HashTable() {
   HashTable_destructor(this);
}
inline void HashTable::add(HashTableNode* node) {
   HashTable_add(this, node);
}
inline HashTableNode* HashTable::lookup(const char* ident) {
   return HashTable_lookup(this, ident);
}

inline void HashTable::setTmObj(void* obj) {
   HashTable_setTmObj(this, obj);
}

#endif


#endif
typedef struct JConstrCont
#ifdef __cplusplus
   : public AuthorizerIntf 
{
      JConstrCont(JUserCont* userCont, AllocatorIntf* alloc=0);
      ~JConstrCont();
      void setConstraints(JVal* constraintsVal, JErr* err);

      
      void setCaseInsensitive();
 
#else
{
   AuthorizerIntf super; 
#endif

   DoubleList resourceList;
   JUserCont* userCont;
   HashTable* resourceTable;
   int noOfResources;
   AllocatorIntf* alloc;
   BaBool caseSensensitive;

} JConstrCont;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void JConstrCont_constructor(JConstrCont* o, JUserCont* userCont,
                             AllocatorIntf* alloc);
BA_API void JConstrCont_destructor(JConstrCont* o);
BA_API void JConstrCont_setConstraints(JConstrCont* o,
                                JVal* constraintsVal, JErr* err);
#define JConstrCont_setCaseInsensitive(o) (o)->caseSensensitive=FALSE
#ifdef __cplusplus
}
inline JConstrCont::JConstrCont(JUserCont* userCont, AllocatorIntf* alloc) {
   JConstrCont_constructor(this, userCont, alloc); }
inline JConstrCont::~JConstrCont() {
   JConstrCont_destructor(this); }
inline void JConstrCont::setConstraints(JVal* constraintsVal, JErr* err) {
   JConstrCont_setConstraints(this,constraintsVal, err); }
inline void JConstrCont::setCaseInsensitive() {
   JConstrCont_setCaseInsensitive(this);
}
#endif

#endif


#ifndef __BaMimeTypes_h
#define __BaMimeTypes_h

#ifdef __cplusplus
extern "C" {
#endif

BA_API const char* httpFindMime(const char* ext);

#ifdef __cplusplus
}
#endif

#endif


#ifndef __cspCompileCommon_h
#define __cspCompileCommon_h


#ifndef __CspCompileTypes_h
#define __CspCompileTypes_h

#define HTTP_MAGIC_NO 0x12345678

typedef struct HttpDiskBlock
{
      U32 offset;
      U32 size;
} HttpDiskBlock;

typedef struct HttpDiskPage
{
      U32 magicNo;
      U32 isDynamic;
      U32 noOfBlocks;
      HttpDiskBlock blocks[1];
} HttpDiskPage;


#endif 
#ifdef __cplusplus
extern "C" {
#endif

BA_API void cspCompileTypeIntegrityCheck(void);

#ifdef __cplusplus
}
#endif




#endif 


#ifndef __BaTimer_h
#define __BaTimer_h

#define BA_TIMER_SLOTS 32


typedef BaBool (*BaTimer_CB)(void* data);


typedef struct BaTimer
#ifdef __cplusplus
: public Thread
{
      
      BaTimer(ThreadMutex* mutex,int stackSize, BaTime ticklen=10,
              ThreadPriority priority=ThreadPrioNormal,
              AllocatorIntf* alloc=0);
      
      ~BaTimer();

      
      U32 set(BaTimer_CB cb, void* data, U32 milliSec);

      
      int reset(U32 tkey, U32 milliSec);

      
      int cancel(U32 tkey);
#else
#if 0
}
#endif
{
   Thread super;
#endif
   DoubleList slots[BA_TIMER_SLOTS];
   DoubleList readyQ;
   SplayTree tnTree;
   ThreadMutex* mutex;
   AllocatorIntf* alloc;
   BaTime ticklen;
   S16 dataInReadyQ;
   U16 curIndex;
} BaTimer;

#ifdef __cplusplus
extern "C" {
#endif  
BA_API void BaTimer_constructor(
   BaTimer* o, ThreadMutex* mutex,int stackSize, BaTime ticklen,
   ThreadPriority priority, AllocatorIntf* alloc);
BA_API void BaTimer_destructor(BaTimer* o);
BA_API U32 BaTimer_set(BaTimer* o, BaTimer_CB cb, void* data, U32 milliSec);
BA_API int BaTimer_reset(BaTimer* o, U32 tkey, U32 milliSec);
BA_API int BaTimer_cancel(BaTimer* o, U32 tkey);
#ifdef __cplusplus
}
inline BaTimer::BaTimer(ThreadMutex* mutex,int stackSize, BaTime ticklen,
                 ThreadPriority priority, AllocatorIntf* alloc) {
   BaTimer_constructor(this, mutex, stackSize, ticklen, priority,alloc);
}
inline BaTimer::~BaTimer() {
   BaTimer_destructor(this);
}
inline U32 BaTimer::set(BaTimer_CB cb, void* data, U32 milliSec) {
   return BaTimer_set(this, cb, data, milliSec);
}
inline int BaTimer::reset(U32 tkey, U32 milliSec) {
   return BaTimer_reset(this, tkey, milliSec);
}
inline int BaTimer::cancel(U32 tkey) {
   return BaTimer_cancel(this, tkey);
}
#endif  

#endif  

#ifndef _SharkSslBigInt_h
#define _SharkSslBigInt_h

#ifndef SHARKSSL_BIGINT_WORDSIZE
#error UNDEFINED SHARKSSL_BIGINT_WORDSIZE 
#endif

#ifndef SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K
#error UNDEFINED SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K
#endif

#ifndef SHARKSSL_BIGINT_MULT_LOOP_UNROLL
#error UNDEFINED SHARKSSL_BIGINT_MULT_LOOP_UNROLL
#endif



#if   (SHARKSSL_BIGINT_WORDSIZE == 8)
typedef U8  SharkSslBigIntWord;
typedef U16 SharkSslBigIntDoubleWord;
typedef S16 SharkSslBigIntDoubleWordS;
#elif (SHARKSSL_BIGINT_WORDSIZE == 16)
typedef U16 SharkSslBigIntWord;
typedef U32 SharkSslBigIntDoubleWord;
typedef S32 SharkSslBigIntDoubleWordS;
#elif (SHARKSSL_BIGINT_WORDSIZE == 32)
typedef U32 SharkSslBigIntWord;
typedef U64 SharkSslBigIntDoubleWord;
typedef S64 SharkSslBigIntDoubleWordS;
#else
#error SHARKSSL_BIGINT_WORDSIZE should be 8, 16 or 32
#endif



#if (((SharkSslBigIntDoubleWord)-1LL >> 1) & (1LL << SHARKSSL_BIGINT_WORDSIZE))  
#define signed_rshift(a) (a >>= SHARKSSL_BIGINT_WORDSIZE);
#else
#define signed_rshift(a) do {                                                                            \
   if (a < 0)                                                                                            \
   {                                                                                                     \
      a = ((SharkSslBigIntDoubleWord)-1LL ^ (SharkSslBigIntWord)-1L) | (a >> SHARKSSL_BIGINT_WORDSIZE);  \
   }                                                                                                     \
   else                                                                                                  \
   {                                                                                                     \
      a >>= SHARKSSL_BIGINT_WORDSIZE;                                                                    \
   }                                                                                                     \
} while (0)
#endif


typedef struct SharkSslBigInt
{
   SharkSslBigIntWord *mem, *beg;
   U16  len;   
} SharkSslBigInt;


#define SHARKSSL__M (SHARKSSL_BIGINT_WORDSIZE / 8)


#ifdef __cplusplus
extern "C" {
#endif


#define SharkSslBigInt_constructor(o,bits,d) \
        SharkSslBigInt_constructor_w(o, (U16)((bits)/SHARKSSL_BIGINT_WORDSIZE),(void*)d)

#define SharkSslBigInt_getDataPtr(o)     ((o)->beg)

#define SharkSslBigInt_getLengthWords(o) ((o)->len)

#define SharkSslBigInt_getLength(o)      (SharkSslBigInt_getLengthWords(o) * SHARKSSL__M)
        
void    SharkSslBigInt_zero(const SharkSslBigInt *o);

void    SharkSslBigInt_ltrim(SharkSslBigInt *o);

void    SharkSslBigInt_constructor_w(SharkSslBigInt *o, U16 words, void *data);

void    SharkSslBigInt_copy(const SharkSslBigInt *src, SharkSslBigInt *dest);

SharkSslBigIntWord SharkSslBigInt_add(SharkSslBigInt *o1, const SharkSslBigInt *o2);

SharkSslBigIntWord SharkSslBigInt_sub(SharkSslBigInt *o1, const SharkSslBigInt *o2);

void    SharkSslBigInt_addmod(SharkSslBigInt *o1, const SharkSslBigInt *o2,
                              const SharkSslBigInt *mod);

void    SharkSslBigInt_submod(SharkSslBigInt *o1, const SharkSslBigInt *o2,
                              const SharkSslBigInt *mod);

U8      SharkSslBigInt_ge(const SharkSslBigInt *o1, const SharkSslBigInt *o2);

void    SharkSslBigInt_mult(const SharkSslBigInt *o1, const SharkSslBigInt *o2, 
                            SharkSslBigInt *result);

int     SharkSslBigInt_modulo(SharkSslBigInt *dividend, const SharkSslBigInt *mod);

int     SharkSslBigInt_expmod(const SharkSslBigInt *base, SharkSslBigInt *exp,
                              const SharkSslBigInt *mod,  SharkSslBigInt *res,
                              U8 window);

void    SharkSslBigInt_invmod_buf(SharkSslBigInt *u, const SharkSslBigInt *mod,
                                  SharkSslBigIntWord *tmpBuf);

void    SharkSslBigInt_shiftr(SharkSslBigInt *o);

#if (SHARKSSL_ENABLE_RSA_BLINDING || SHARKSSL_ENABLE_ECDSA || (SHARKSSL_ENABLE_ECDH_RSA && SHARKSSL_ENABLE_CLIENT_AUTH))
int     SharkSslBigInt_invmod(SharkSslBigInt *o, const SharkSslBigInt *mod);
#endif

#if (SHARKSSL_ENABLE_ECDSA || (SHARKSSL_ENABLE_ECDH_RSA && SHARKSSL_ENABLE_CLIENT_AUTH))
U8      SharkSslBigInt_isZero(SharkSslBigInt *o);
#endif

#ifdef __cplusplus
}
#endif


#endif 


#ifndef __HttpServCon_h
#define __HttpServCon_h

struct HttpServer;
struct HttpServCon;

typedef void (*HttpServCon_AcceptNewCon)(
   struct HttpServCon* scon, HttpConnection* newcon);



typedef struct HttpServCon
{
#ifdef __cplusplus

      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }


      
      HttpServCon(HttpServer* server,
                  SoDisp* dispatcher,
                  U16 port=80,
                  BaBool setIP6=FALSE,
                  const void* interfaceName=0,
                  HttpServCon_AcceptNewCon userDefinedAccept=0);

      
      BaBool isValid();
      
      
      int setPort(U16 portNumber, bool setIp6=false,
                  const void* interfaceName=0);

      ~HttpServCon();
      HttpServCon() {}
   private:
#endif
      HttpConnection con;
      HttpServCon_AcceptNewCon userDefinedAccept;
} HttpServCon;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpServCon_constructor(HttpServCon* o,
                             struct HttpServer* server,
                             struct SoDisp* dispatcher,
                             U16 port,
                             BaBool setIP6,
                             const void* interfaceName,
                             HttpServCon_AcceptNewCon userDefinedAccept);
#define HttpServCon_isValid(o) \
        SoDispCon_isValid((SoDispCon*)(o))
BA_API int HttpServCon_setPort(HttpServCon* o, U16 portNumber,
                               BaBool setIp6, const void* interfaceName);
BA_API void HttpServCon_destructor(HttpServCon* o);
BA_API int HttpServCon_init(
   HttpServCon* o,
   struct HttpServer* server,
   U16 port,
   BaBool setIP6,
   const void* interfaceName);


void HttpServCon_bindExec(SoDispCon* con);

#ifdef __cplusplus
}
inline HttpServCon::HttpServCon(HttpServer* server,
                                SoDisp* dispatcher,
                                U16 port,
                                BaBool setIP6,
                                const void* interfaceName,
                                HttpServCon_AcceptNewCon userDefinedAccept) {
   HttpServCon_constructor(this,server,dispatcher,port,setIP6,interfaceName,
                           userDefinedAccept);
}
inline HttpServCon::~HttpServCon() {
   HttpServCon_destructor(this);
}
inline BaBool HttpServCon::isValid() { return HttpServCon_isValid(this); }
inline int HttpServCon::setPort(
   U16 portNumber,bool setIp6,const void* interfaceName) {
   return HttpServCon_setPort(this,portNumber,setIp6?TRUE:FALSE,interfaceName);
}


#endif

#endif

#ifndef __CspRunTm_h
#define __CspRunTm_h

#ifndef SharkSslStandalone
#endif


#ifndef __DOXYGEN__
struct GzipHeader
{
      U8 id1;
      U8 id2;
      U8 compressionMethod;
      U8 flags;
      U8 unixTime[4];
      U8 extraflag; 
      U8 operatingSystem;
}
#ifdef __GNUC__
__attribute__((__packed__))
#endif
;

typedef struct GzipHeader GzipHeader;
#endif

#define FLG_FTEXT    ( 1 << 0 )
#define FLG_FHCRC    ( 1 << 1 )
#define FLG_FEXTRA   ( 1 << 2 )
#define FLG_FNAME    ( 1 << 3 )
#define FLG_FCOMMENT ( 1 << 4 )

#ifndef __DOXYGEN__
struct GzipTrailer
{
      U8 crc[4];
      U8 uncompressedSize[4];
}
#ifdef __GNUC__
__attribute__((__packed__))
#endif
;

typedef struct GzipTrailer GzipTrailer;
#endif

struct CspReader;



typedef  int (*CspReader_Read)(
   struct CspReader* o, void* data, U32 offset, U32 size, int blockStart);

#define CspReader_validFlag 0xA503


typedef struct CspReader
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      
      bool isValid();
      int read(void* data, U32 offset, U32 size, bool blockStart);
      void setIsValid() { validFlag=CspReader_validFlag; }
   private:
#endif
      CspReader_Read readCB;
      U16 validFlag;
} CspReader;

#ifdef __cplusplus
extern "C" {
#endif
#define CspReader_constructor(o, httpDiskRead) do {\
        (o)->readCB = httpDiskRead; \
        (o)->validFlag = (U16)~CspReader_validFlag; \
}while(0)

#define CspReader_isValid(o) (((CspReader*)o)->readCB != 0 && \
                             ((CspReader*)o)->validFlag == CspReader_validFlag)
#define CspReader_setIsValid(o) ((CspReader*)o)->validFlag=CspReader_validFlag
#define CspReader_read(httpData, data, offset, size, blockStart) \
  (*((CspReader*)httpData)->readCB)((CspReader*)httpData, data, \
                                 offset, size, blockStart)
#ifdef __cplusplus
}
inline bool CspReader::isValid() {
   return CspReader_isValid(this) ? true : false;
}
inline int CspReader::read(void* data, U32 offset, U32 size, bool blockStart) {
   return CspReader_read(this, data, offset, size, blockStart);
}
#endif

#ifndef SharkSslStandalone

#ifndef __DOXYGEN__
typedef struct HttpStaticMemPage
{
      HttpPage page;
      CspReader* data;
      U32 time;
      HttpDiskBlock mimeBlock;
      HttpDiskBlock payloadBlock;
      char isCompressed;
} HttpStaticMemPage;
#endif

#ifdef __cplusplus
extern "C" {
#endif
BA_API int httpWriteSection(
   CspReader* data, HttpResponse* reply,U32 offset,U32 size);
BA_API int httpUnzipAndWrite(CspReader* data,
                      HttpResponse* response,
                      U32 offset,
                      U32 size,
                      GzipHeader* gzipH);
BA_API void httpRawWrite(CspReader* data,
                  HttpRequest* request,
                  HttpResponse* response,
                  U32 time,
                  U32 offset,
                  U32 size,
                  GzipHeader* gzipH,
                  GzipTrailer* gzipT);

BA_API int cspCheckCondition(HttpRequest* request, HttpResponse* response);

BA_API void HttpStaticMemPage_loadAndInit(HttpStaticMemPage* o,
                                   CspReader* data, U32 time,
                                   U32 nameOffset, U32 nameSize,
                                   U32 mimeOffset, U32 mimeSize,
                                   U32 payloadOffset, U32 payloadSize,
                                   char isCompressed, HttpDir* parent);
   
BA_API void HttpDynamicMemPage_loadAndInit(
   HttpPage* o, CspReader* data, U32 size,
   HttpPage_Service fptr,
   U32 nameOffset, U32 nameSize);
#ifdef __cplusplus
}
#endif

#endif

#endif 






#ifndef __ZipFileIterator_h
#define __ZipFileIterator_h

#ifndef __DOXYGEN__
struct ZipContainer;
struct ZipFileHeaderData;
#endif

#ifdef _SHARK_DOXY

#else

#endif


typedef struct ZipReader
#ifdef __cplusplus
: public CspReader
{
      ZipReader() {}
      ZipReader(CspReader_Read r, U32 zipFileSize);
#else
{ 
      CspReader super; 
#endif
      U32 size;
} ZipReader;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void ZipReader_constructor(
   ZipReader* o, CspReader_Read r, U32 zipFileSize);
#ifdef __cplusplus
}
inline ZipReader::ZipReader(CspReader_Read r, U32 zipFileSize) {
   ZipReader_constructor(this, r, zipFileSize); }
#endif


typedef enum {
   ZipErr_Buf = -2000, 
   ZipErr_Reading, 
   ZipErr_Spanned,  
   ZipErr_Compression, 
   ZipErr_Incompatible, 
   ZipErr_NoError = 0
} ZipErr;


typedef enum {
   ZipComprMethod_Stored=0,
   ZipComprMethod_Deflated=8,
   ZipComprMethod_AES=99       
} ZipComprMethod;


#ifndef __DOXYGEN__

typedef struct ZipFileHeader
{
#ifdef __cplusplus
      const char* getFn();
      const char* getEf();
	  const char* getAESef();
      bool isDirectory();
      U16 getFnLen();
      U16 getEfLen();
      U16 getFcLen();
      ZipComprMethod getComprMethod();
      U32 getUncompressedSizeLittleEndian();
      U32 getCrc32LittleEndian();
      U32 getCompressedSize();
      U32 getUncompressedSize();
      U32 getCrc32();
      static const char* e2str(ZipErr e);
      U16 getVersionMade();
      U16 getFlag();
      U32 getDataOffset();
      U32 getTime();
      CspReader* getReader();
   private:
#endif
      struct ZipFileHeaderData* data;
      char* fn;  
      U8* ef;    
      U8* AESef; 
      ZipReader* reader;
      U8* buf;
      U32 bufSize;
      U32 fileHeaderOffs;
      ZipComprMethod comprMethod;
      U16 fnLen;
      U16 efLen;
      U16 fcLen;
} ZipFileHeader;

#ifdef __cplusplus
extern "C" {
#endif
#define ZipFileHeader_getFn(o) (o)->fn
#define ZipFileHeader_getEf(o) (o)->ef
#define ZipFileHeader_getAESef(o) (o)->AESef
#define ZipFileHeader_isDirectory(o) ((o)->fn[(o)->fnLen-1] == '/')
#define ZipFileHeader_getFnLen(o) (o)->fnLen
#define ZipFileHeader_getEfLen(o) (o)->efLen
#define ZipFileHeader_getFcLen(o) (o)->fcLen
#define ZipFileHeader_getComprMethod(o) (o)->comprMethod
#define ZipFileHeader_getReader(o) (CspReader*)(o)->reader
BA_API U32 ZipFileHeader_getUncompressedSizeLittleEndian(ZipFileHeader* o);
BA_API U32 ZipFileHeader_getCrc32LittleEndian(ZipFileHeader* o);
BA_API U32 ZipFileHeader_getCompressedSize(ZipFileHeader* o);
BA_API U32 ZipFileHeader_getUncompressedSize(ZipFileHeader* o);
BA_API U32 ZipFileHeader_getCrc32(ZipFileHeader* o);
BA_API const char* ZipFileHeader_e2str(ZipErr e);


BA_API U16 ZipFileHeader_getVersionMade(ZipFileHeader* o);


BA_API U16 ZipFileHeader_getFlag(ZipFileHeader* o);

BA_API U32 ZipFileHeader_getDataOffset(ZipFileHeader* o);
BA_API U32 ZipFileHeader_getTime(ZipFileHeader* o);

#ifdef __cplusplus
}
inline const char* ZipFileHeader::getFn() {
   return ZipFileHeader_getFn(this);
}
inline const char* ZipFileHeader::getEf() {
   return (char*)ZipFileHeader_getEf(this);
}
inline const char* ZipFileHeader::getAESef() {
   return (char*)ZipFileHeader_getAESef(this);
}
inline bool ZipFileHeader::isDirectory() {
   return ZipFileHeader_isDirectory(this) ? true : false;
}
inline U16 ZipFileHeader::getFnLen() {
   return ZipFileHeader_getFnLen(this);
}
inline U16 ZipFileHeader::getEfLen() {
   return ZipFileHeader_getEfLen(this);
}
inline U16 ZipFileHeader::getFcLen() {
   return ZipFileHeader_getFcLen(this);
}
inline ZipComprMethod ZipFileHeader::getComprMethod() {
   return ZipFileHeader_getComprMethod(this);
}
inline CspReader* ZipFileHeader::getReader() {
   return ZipFileHeader_getReader(this);
}
inline U32 ZipFileHeader::getUncompressedSizeLittleEndian() {
   return ZipFileHeader_getUncompressedSizeLittleEndian(this);
}
inline U32 ZipFileHeader::getCrc32LittleEndian() {
   return ZipFileHeader_getCrc32LittleEndian(this);
}
inline U32 ZipFileHeader::getCompressedSize() {
   return ZipFileHeader_getCompressedSize(this);
}
inline U32 ZipFileHeader::getUncompressedSize() {
   return ZipFileHeader_getUncompressedSize(this);
}
inline U32 ZipFileHeader::getCrc32() {
   return ZipFileHeader_getCrc32(this);
}
inline const char* ZipFileHeader::e2str(ZipErr e) {
   return ZipFileHeader_e2str(e);
}
inline U16 ZipFileHeader::getVersionMade() {
   return ZipFileHeader_getVersionMade(this);
}
inline U16 ZipFileHeader::getFlag() {
   return ZipFileHeader_getFlag(this);
}
inline U32 ZipFileHeader::getDataOffset() {
   return ZipFileHeader_getDataOffset(this);
}
inline U32 ZipFileHeader::getTime() {
   return ZipFileHeader_getTime(this);
}
#endif

#endif 



typedef struct ZipFileInfo
{
      U32 crc32;
      U32 dataOffset;
      U32 uncompressedSize;
      U32 compressedSize;
      U32 time;
      ZipComprMethod comprMethod;
      U16 flag;
      U8  *ef;  
      U8  *AESef; 
} ZipFileInfo;

#if defined(B_LITTLE_ENDIAN)
#define ZipFileInfo_makeLittleEndianU32(x) x
#elif defined(B_BIG_ENDIAN)
#define ZipFileInfo_makeLittleEndianU32(x) \
 ((U32)((((U32)(x) & 0x000000ffU) << 24) | \
 (((U32)(x) & 0x0000ff00U) <<  8) | \
 (((U32)(x) & 0x00ff0000U) >>  8) | \
 (((U32)(x) & 0xff000000U) >> 24))) 
#else
#error in config/make file, you must define one of B_LITTLE_ENDIAN or B_BIG_ENDIAN
#endif

#define ZipFileInfo_getCrc32LittleEndian(o) \
  ZipFileInfo_makeLittleEndianU32((o)->crc32);
#define ZipFileInfo_getUncompressedSizeLittleEndian(o) \
  ZipFileInfo_makeLittleEndianU32((o)->uncompressedSize);


#define ZipFileInfo_constructor(o, fileHeader, EfPtr) \
do { \
   (o)->crc32 = ZipFileHeader_getCrc32(fileHeader); \
   (o)->dataOffset = ZipFileHeader_getDataOffset(fileHeader); \
   (o)->uncompressedSize = ZipFileHeader_getUncompressedSize(fileHeader); \
   (o)->compressedSize = ZipFileHeader_getCompressedSize(fileHeader); \
   (o)->time = ZipFileHeader_getTime(fileHeader); \
   (o)->comprMethod = ZipFileHeader_getComprMethod(fileHeader); \
   (o)->flag = ZipFileHeader_getFlag(fileHeader); \
   (o)->ef = EfPtr; \
   (o)->AESef = (EfPtr + (ZipFileHeader_getAESef(fileHeader) - ZipFileHeader_getEf(fileHeader))); \
}while(0)


#ifndef __DOXYGEN__
typedef struct
{
      U32 dataOffset;
      U32 uncompressedSize;
      U32 compressedSize;
      ZipComprMethod comprMethod;
} MiniZipFileInfo;
#endif

#define MiniZipFileInfo_constructor(o, fileHeader) \
do { \
   (o)->dataOffset = ZipFileHeader_getDataOffset(fileHeader); \
   (o)->uncompressedSize = ZipFileHeader_getUncompressedSize(fileHeader); \
   (o)->compressedSize = ZipFileHeader_getCompressedSize(fileHeader); \
   (o)->comprMethod = ZipFileHeader_getComprMethod(fileHeader); \
}while(0)



typedef struct CentralDirIterator
{
#ifdef __cplusplus
      CentralDirIterator(ZipContainer* container);
      CentralDirIterator(ZipContainer* container, U8* buf, U32 bufSize);
      ZipErr getECode();
      ZipFileHeader* getElement();
      bool nextElement();
   private:
#endif
      ZipFileHeader fileHeader;
      U32 curFileHeaderOffs;
      ZipErr err;
      U16 entriesInCd;
      U16 curEntry;
} CentralDirIterator;

#ifdef __cplusplus
extern "C" {
#endif
#define CentralDirIterator_getECode(o) (o)->err
BA_API void CentralDirIterator_constructor(CentralDirIterator* o,
                                    struct ZipContainer* container);

BA_API void CentralDirIterator_constructorR(CentralDirIterator* o,
                                     struct ZipContainer* container,
                                     U8* buf, U32 bufSize);
BA_API ZipFileHeader* CentralDirIterator_getElement(CentralDirIterator* o);
BA_API BaBool CentralDirIterator_nextElement(CentralDirIterator* o);
#ifdef __cplusplus
}
inline CentralDirIterator::CentralDirIterator(ZipContainer* container) {
   CentralDirIterator_constructor(this, container);
}
inline CentralDirIterator::CentralDirIterator(
   ZipContainer* container, U8* buf, U32 bufSize) {
   CentralDirIterator_constructorR(this, container, buf, bufSize);
}
inline ZipErr CentralDirIterator::getECode() {
   return CentralDirIterator_getECode(this);
}
inline ZipFileHeader* CentralDirIterator::getElement() {
   return CentralDirIterator_getElement(this);
}
inline bool CentralDirIterator::nextElement() {
   return CentralDirIterator_nextElement(this) ? true : false;
}
#endif




typedef struct ZipContainer
{
#ifdef __cplusplus
      ZipContainer(){}
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }
 
      
      ZipContainer(ZipReader* reader, U8* buf, U32 bufSize);
      ZipErr getECode();
   private:
#endif
      ZipReader* reader;
      U8* buf;
      U32 bufSize;
      U32 cdOffset;
      ZipErr errCode;
      U16 entriesInCd;
} ZipContainer;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void ZipContainer_constructor(ZipContainer* o,
                              ZipReader* reader,
                              U8* buf,
                              U32 bufSize);
#define ZipContainer_getECode(o) (o)->errCode
#ifdef __cplusplus
}
inline ZipContainer::ZipContainer(ZipReader* reader, U8* buf, U32 bufSize) {
   ZipContainer_constructor(this,reader,buf,bufSize); }
inline ZipErr ZipContainer::getECode() {
   return ZipContainer_getECode(this); }
#endif

int initGZipHeader(struct ZipFileInfo* zfi, GzipHeader* gzipH);


  


#endif


#ifndef _ZLIB_H
#define _ZLIB_H





#ifndef _ZCONF_H
#define _ZCONF_H


#ifdef Z_PREFIX
#  define deflateInit_	z_deflateInit_
#  define deflate	z_deflate
#  define deflateEnd	z_deflateEnd
#  define inflateInit_ 	z_inflateInit_
#  define inflate	z_inflate
#  define inflateEnd	z_inflateEnd
#  define deflateInit2_	z_deflateInit2_
#  define deflateSetDictionary z_deflateSetDictionary
#  define deflateCopy	z_deflateCopy
#  define deflateReset	z_deflateReset
#  define deflateParams	z_deflateParams
#  define inflateInit2_	z_inflateInit2_
#  define inflateSetDictionary z_inflateSetDictionary
#  define inflateSync	z_inflateSync
#  define inflateSyncPoint z_inflateSyncPoint
#  define inflateReset	z_inflateReset
#  define compress	z_compress
#  define compress2	z_compress2
#  define uncompress	z_uncompress
#  define adler32	z_adler32
#  define crc32		z_crc32
#  define get_crc_table z_get_crc_table

#  define Byte		z_Byte
#  define uInt		z_uInt
#  define uLong		z_uLong
#  define Bytef	        z_Bytef
#  define charf		z_charf
#  define intf		z_intf
#  define uIntf		z_uIntf
#  define uLongf	z_uLongf
#  define voidpf	z_voidpf
#  define voidp		z_voidp
#endif

#if (defined(_WIN32) || defined(__WIN32__)) && !defined(WIN32)
#  define WIN32
#endif
#if defined(__GNUC__) || defined(WIN32) || defined(__386__) || defined(i386)
#  ifndef __32BIT__
#    define __32BIT__
#  endif
#endif
#if defined(__MSDOS__) && !defined(MSDOS)
#  define MSDOS
#endif


#if defined(MSDOS) && !defined(__32BIT__)
#  define MAXSEG_64K
#endif
#ifdef MSDOS
#  define UNALIGNED_OK
#endif

#if (defined(MSDOS) || defined(_WINDOWS) || defined(WIN32))  && !defined(STDC)
#  define STDC
#endif
#if defined(__STDC__) || defined(__cplusplus) || defined(__OS2__)
#  ifndef STDC
#    define STDC
#  endif
#endif

#ifndef STDC
#  ifndef const 
#    define const
#  endif
#endif


#if defined(__MWERKS__) || defined(applec) ||defined(THINK_C) ||defined(__SC__)
#  define NO_DUMMY_DECL
#endif


#if defined(__BORLANDC__) && (__BORLANDC__ < 0x500)
#  define NEED_DUMMY_RETURN
#endif



#ifndef MAX_MEM_LEVEL
#  ifdef MAXSEG_64K
#    define MAX_MEM_LEVEL 8
#  else
#    define MAX_MEM_LEVEL 9
#  endif
#endif


#ifndef MAX_WBITS
#  define MAX_WBITS   15 
#endif



                        

#ifndef OF 
#  ifdef STDC
#    define OF(args)  args
#  else
#    define OF(args)  ()
#  endif
#endif


#if (defined(M_I86SM) || defined(M_I86MM)) && !defined(__32BIT__)
   
#  define SMALL_MEDIUM
#  ifdef _MSC_VER
#    define FAR _far
#  else
#    define FAR far
#  endif
#endif
#if defined(__BORLANDC__) && (defined(__SMALL__) || defined(__MEDIUM__))
#  ifndef __32BIT__
#    define SMALL_MEDIUM
#    define FAR _far
#  endif
#endif


#if defined(ZLIB_DLL)
#  if defined(_WINDOWS) || defined(WINDOWS)
#    ifdef FAR
#      undef FAR
#    endif
#    define ZEXPORT  WINAPI
#    ifdef WIN32
#      define ZEXPORTVA  WINAPIV
#    else
#      define ZEXPORTVA  FAR _cdecl _export
#    endif
#  endif
#  if defined (__BORLANDC__)
#    if (__BORLANDC__ >= 0x0500) && defined (WIN32)
#      define ZEXPORT __declspec(dllexport) WINAPI
#      define ZEXPORTRVA __declspec(dllexport) WINAPIV
#    else
#      if defined (_Windows) && defined (__DLL__)
#        define ZEXPORT _export
#        define ZEXPORTVA _export
#      endif
#    endif
#  endif
#endif

#if defined (__BEOS__)
#  if defined (ZLIB_DLL)
#    define ZEXTERN extern __declspec(dllexport)
#  else
#    define ZEXTERN extern __declspec(dllimport)
#  endif
#endif

#ifndef ZEXPORT
#  define ZEXPORT
#endif
#ifndef ZEXPORTVA
#  define ZEXPORTVA
#endif
#ifndef ZEXTERN
#  define ZEXTERN extern
#endif

#ifndef FAR
#   define FAR
#endif

#if !defined(MACOS) && !defined(TARGET_OS_MAC)
typedef unsigned char  Byte;  
#endif
typedef unsigned int   uInt;  
typedef unsigned long  uLong; 

#ifdef SMALL_MEDIUM
   
#  define Bytef Byte FAR
#else
   typedef Byte  FAR Bytef;
#endif
typedef char  FAR charf;
typedef int   FAR intf;
typedef uInt  FAR uIntf;
typedef uLong FAR uLongf;

#ifdef STDC
   typedef void FAR *voidpf;
   typedef void     *voidp;
#else
   typedef Byte FAR *voidpf;
   typedef Byte     *voidp;
#endif

#ifdef HAVE_UNISTD_H
#  define z_off_t  off_t
#endif
#ifndef SEEK_SET
#  define SEEK_SET        0       
#  define SEEK_CUR        1       
#  define SEEK_END        2       
#endif
#ifndef z_off_t
#  define  z_off_t long
#endif


#if defined(__MVS__)
#   pragma map(deflateInit_,"DEIN")
#   pragma map(deflateInit2_,"DEIN2")
#   pragma map(deflateEnd,"DEEND")
#   pragma map(inflateInit_,"ININ")
#   pragma map(inflateInit2_,"ININ2")
#   pragma map(inflateEnd,"INEND")
#   pragma map(inflateSync,"INSY")
#   pragma map(inflateSetDictionary,"INSEDI")
#   pragma map(inflate_blocks,"INBL")
#   pragma map(inflate_blocks_new,"INBLNE")
#   pragma map(inflate_blocks_free,"INBLFR")
#   pragma map(inflate_blocks_reset,"INBLRE")
#   pragma map(inflate_codes_free,"INCOFR")
#   pragma map(inflate_codes,"INCO")
#   pragma map(inflate_fast,"INFA")
#   pragma map(inflate_flush,"INFLU")
#   pragma map(inflate_mask,"INMA")
#   pragma map(inflate_set_dictionary,"INSEDI2")
#   pragma map(inflate_copyright,"INCOPY")
#   pragma map(inflate_trees_bits,"INTRBI")
#   pragma map(inflate_trees_dynamic,"INTRDY")
#   pragma map(inflate_trees_fixed,"INTRFI")
#   pragma map(inflate_trees_free,"INTRFR")
#endif

#endif 
#ifdef __cplusplus
extern "C" {
#endif

#define ZLIB_VERSION "1.1.4"



typedef voidpf (*alloc_func) OF((voidpf opaque, uInt items, uInt size));
typedef void   (*free_func)  OF((voidpf opaque, voidpf address));

struct internal_state;

typedef struct z_stream_s {
    Bytef    *next_in;  
    uInt     avail_in;  
    uLong    total_in;  

    Bytef    *next_out; 
    uInt     avail_out; 
    uLong    total_out; 

    char     *msg;      
    struct internal_state FAR *state; 

    alloc_func zalloc;  
    free_func  zfree;   
    voidpf     opaque;  

    int     data_type;  
    uLong   adler;      
    uLong   reserved;   
} z_stream;

typedef z_stream FAR *z_streamp;



                        

#define Z_NO_FLUSH      0
#define Z_PARTIAL_FLUSH 1 
#define Z_SYNC_FLUSH    2
#define Z_FULL_FLUSH    3
#define Z_FINISH        4


#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_VERSION_ERROR (-6)


#define Z_NO_COMPRESSION         0
#define Z_BEST_SPEED             1
#define Z_BEST_COMPRESSION       9
#define Z_DEFAULT_COMPRESSION  (-1)


#define Z_FILTERED            1
#define Z_HUFFMAN_ONLY        2
#define Z_DEFAULT_STRATEGY    0


#define Z_BINARY   0
#define Z_ASCII    1
#define Z_UNKNOWN  2


#define Z_DEFLATED   8


#define Z_NULL  0  

#define zlib_version zlibVersion()


                        

ZEXTERN const char * ZEXPORT zlibVersion OF((void));





ZEXTERN int ZEXPORT deflate OF((z_streamp strm, int flush));



ZEXTERN int ZEXPORT deflateEnd OF((z_streamp strm));






ZEXTERN int ZEXPORT inflate OF((z_streamp strm, int flush));



ZEXTERN int ZEXPORT inflateEnd OF((z_streamp strm));


                        




                            
ZEXTERN int ZEXPORT deflateSetDictionary OF((z_streamp strm,
                                             const Bytef *dictionary,
                                             uInt  dictLength));


ZEXTERN int ZEXPORT deflateCopy OF((z_streamp dest,
                                    z_streamp source));


ZEXTERN int ZEXPORT deflateReset OF((z_streamp strm));


ZEXTERN int ZEXPORT deflateParams OF((z_streamp strm,
				      int level,
				      int strategy));




ZEXTERN int ZEXPORT inflateSetDictionary OF((z_streamp strm,
                                             const Bytef *dictionary,
                                             uInt  dictLength));


ZEXTERN int ZEXPORT inflateSync OF((z_streamp strm));


ZEXTERN int ZEXPORT inflateReset OF((z_streamp strm));



                        



ZEXTERN int ZEXPORT compress OF((Bytef *dest,   uLongf *destLen,
                                 const Bytef *source, uLong sourceLen));


ZEXTERN int ZEXPORT compress2 OF((Bytef *dest,   uLongf *destLen,
                                  const Bytef *source, uLong sourceLen,
                                  int level));


ZEXTERN int ZEXPORT uncompress OF((Bytef *dest,   uLongf *destLen,
                                   const Bytef *source, uLong sourceLen));



typedef voidp gzFile;

ZEXTERN gzFile ZEXPORT gzopen  OF((const char *path, const char *mode));


ZEXTERN gzFile ZEXPORT gzdopen  OF((int fd, const char *mode));


ZEXTERN int ZEXPORT gzsetparams OF((gzFile file, int level, int strategy));


ZEXTERN int ZEXPORT    gzread  OF((gzFile file, voidp buf, unsigned len));


ZEXTERN int ZEXPORT    gzwrite OF((gzFile file, 
				   const voidp buf, unsigned len));


ZEXTERN int ZEXPORTVA   gzprintf OF((gzFile file, const char *format, ...));


ZEXTERN int ZEXPORT gzputs OF((gzFile file, const char *s));


ZEXTERN char * ZEXPORT gzgets OF((gzFile file, char *buf, int len));


ZEXTERN int ZEXPORT    gzputc OF((gzFile file, int c));


ZEXTERN int ZEXPORT    gzgetc OF((gzFile file));


ZEXTERN int ZEXPORT    gzflush OF((gzFile file, int flush));


ZEXTERN z_off_t ZEXPORT    gzseek OF((gzFile file,
				      z_off_t offset, int whence));


ZEXTERN int ZEXPORT    gzrewind OF((gzFile file));


ZEXTERN z_off_t ZEXPORT    gztell OF((gzFile file));


ZEXTERN int ZEXPORT gzeof OF((gzFile file));


ZEXTERN int ZEXPORT    gzclose OF((gzFile file));


ZEXTERN const char * ZEXPORT gzerror OF((gzFile file, int *errnum));


                        



ZEXTERN uLong ZEXPORT adler32 OF((uLong adler, const Bytef *buf, uInt len));



ZEXTERN uLong ZEXPORT crc32   OF((uLong crc, const Bytef *buf, uInt len));



                        


ZEXTERN int ZEXPORT deflateInit_ OF((z_streamp strm, int level,
                                     const char *version, int stream_size));
ZEXTERN int ZEXPORT inflateInit_ OF((z_streamp strm,
                                     const char *version, int stream_size));
ZEXTERN int ZEXPORT deflateInit2_ OF((z_streamp strm, int  level, int  method,
                                      int windowBits, int memLevel,
                                      int strategy, const char *version,
                                      int stream_size));
ZEXTERN int ZEXPORT inflateInit2_ OF((z_streamp strm, int  windowBits,
                                      const char *version, int stream_size));
#define deflateInit(strm, level) \
        deflateInit_((strm), (level),       ZLIB_VERSION, sizeof(z_stream))
#define inflateInit(strm) \
        inflateInit_((strm),                ZLIB_VERSION, sizeof(z_stream))
#define deflateInit2(strm, level, method, windowBits, memLevel, strategy) \
        deflateInit2_((strm),(level),(method),(windowBits),(memLevel),\
                      (strategy),           ZLIB_VERSION, sizeof(z_stream))
#define inflateInit2(strm, windowBits) \
        inflateInit2_((strm), (windowBits), ZLIB_VERSION, sizeof(z_stream))


#if !defined(_Z_UTIL_H) && !defined(NO_DUMMY_DECL)
    struct internal_state {int dummy;}; 
#endif

ZEXTERN const char   * ZEXPORT zError           OF((int err));
ZEXTERN int            ZEXPORT inflateSyncPoint OF((z_streamp z));
ZEXTERN const uLongf * ZEXPORT get_crc_table    OF((void));

#ifdef __cplusplus
}
#endif

#endif 

#ifndef _SharkSslECC_h
#define _SharkSslECC_h

#if SHARKSSL_USE_ECC
typedef struct  
{
   SharkSslBigInt x, y;
} SharkSslECPoint;


typedef struct       
{                                                        
   SharkSslBigInt  prime;                
   SharkSslBigInt  order;                
   SharkSslECPoint G;               
   #if SHARKSSL_ECC_VERIFY_POINT
   SharkSslBigInt  b;     
   #endif
   U16 bits;     
} SharkSslECNISTCurve;


#define SHARKSSL_EC_CURVE_ID_UNKNOWN    0

#define SHARKSSL_EC_CURVE_ID_SECP192R1  19
#define SHARKSSL_EC_CURVE_ID_SECP224R1  21
#define SHARKSSL_EC_CURVE_ID_SECP256R1  23
#define SHARKSSL_EC_CURVE_ID_SECP384R1  24
#define SHARKSSL_EC_CURVE_ID_SECP521R1  25


#define SHARKSSL_EC_POINT_UNCOMPRESSED  0x04


#ifdef __cplusplus
extern "C" {
#endif


void    SharkSslECNISTCurve_constructor(SharkSslECNISTCurve *o, U16 type);

int     SharkSslECNISTCurve_setPoint(SharkSslECNISTCurve *o, SharkSslECPoint *p);

int     SharkSslECNISTCurve_multiply(SharkSslECNISTCurve *o, SharkSslBigInt *k, 
                                     SharkSslECPoint *result);

#if (SHARKSSL_ENABLE_ECDSA || (SHARKSSL_ENABLE_ECDH_RSA && SHARKSSL_ENABLE_CLIENT_AUTH))                                     
int     SharkSslECNISTCurve_multiply2(SharkSslECNISTCurve *S, SharkSslBigInt *d, 
                                      SharkSslECNISTCurve *T, SharkSslBigInt *e, 
                                      SharkSslECPoint *result);
#endif

#define SharkSslECPoint_constructor_w(o,w,a,b) \
        SharkSslBigInt_constructor_w(&((o)->x),(w),(a)); SharkSslBigInt_constructor_w(&((o)->y),(w),(b))

#define SharkSslECPoint_constructor(o,t,a,b) \
        SharkSslBigInt_constructor(&((o)->x),(t),(a)); SharkSslBigInt_constructor(&((o)->y),(t),(b))

#ifdef __cplusplus
}
#endif

#endif  
#endif 



#ifndef __DefaultMq_h
#define __DefaultMq_h



#ifndef __MqInterf_h
#define __MqInterf_h

#ifndef __DOXYGEN__
struct MqMessage;
struct MqInterf;
#endif




typedef void (*MqMessage_Runnable)(struct MqMessage* m);


typedef struct MqMessage
{
#ifdef __cplusplus
      
      MqMessage(MqMessage_Runnable runnable);

      
      void run();
#endif
      MqMessage_Runnable runnable;
} MqMessage;

#define MqMessage_constructor(o, runnableMA) (o)->runnable=runnableMA
#define MqMessage_run(o) (o)->runnable(o)

#ifdef __cplusplus
inline MqMessage::MqMessage(MqMessage_Runnable runnable) {
   MqMessage_constructor(this, runnable);
}
inline void MqMessage::run() {
   MqMessage_run(this);
}
#endif


typedef int (*MqInterf_Send)(struct MqInterf* mq, MqMessage* msg);


typedef MqMessage* (*MqInterf_Receive)(struct MqInterf* mq);


typedef struct MqInterf
{
#ifdef __cplusplus
      MqInterf(){}

      
      MqInterf(MqInterf_Send send, MqInterf_Receive rec);

      
      void sendmsg(MqMessage* m);

      
      MqMessage* receivemsg();
#endif
      MqInterf_Send sendF;
      MqInterf_Receive receiveF;
} MqInterf;


#define MqInterf_constructor(o, send, receive) \
   (o)->sendF=send,(o)->receiveF=receive

#define MqInterf_sendmsg(o, message) (o)->sendF(o, message)
#define MqInterf_receivemsg(o) (o)->receiveF(o)

#ifdef __cplusplus
inline MqInterf::MqInterf(MqInterf_Send send, MqInterf_Receive rec) {
   MqInterf_constructor(this, send, rec);
}
inline void MqInterf::sendmsg(MqMessage* m) {
      MqInterf_sendmsg(this, m);
}
inline MqMessage* MqInterf::receivemsg() {
   return MqInterf_receivemsg(this);
}
#endif

 

#endif
#ifndef __DOXYGEN__
typedef struct DefaultMqNode
{
      SingleLink super;
      MqMessage* msg;
} DefaultMqNode;
#endif




typedef struct DefaultMq
#ifdef __cplusplus
: public MqInterf
{
      
      DefaultMq(AllocatorIntf* allocator=0);
      char mutexBuf[sizeof(ThreadMutex)];
      char queueBuf[sizeof(SingleList)];
      char semBuf[sizeof(ThreadSemaphore)];
#else
{
      MqInterf super; 
      ThreadMutex mutex;
      SingleList queue;
      ThreadSemaphore sem;
#endif

      AllocatorIntf* allocator;
} DefaultMq;

#ifdef __cplusplus
extern "C" {
#endif 
BA_API void DefaultMq_constructor(DefaultMq* o,
                           AllocatorIntf* allocator);
#ifdef __cplusplus
}
inline DefaultMq::DefaultMq(AllocatorIntf* allocator) {
   DefaultMq_constructor(this, allocator);
}
#endif

 


#endif


#ifndef __FixedSizeAllocator_h
#define __FixedSizeAllocator_h

typedef struct FixedSizeAllocator
#ifdef __cplusplus
: public AllocatorIntf
{
      FixedSizeAllocator() {}

      
      FixedSizeAllocator(void* buffer, size_t bufSize, size_t blockSize);
      
#else
{
   AllocatorIntf super;
#endif
   SingleList freeList;
   size_t blockSize;
} FixedSizeAllocator;


#ifdef __cplusplus
extern "C" {
#endif 
BA_API void FixedSizeAllocator_constructor(FixedSizeAllocator* o,
                                    void* buffer,
                                    size_t bufSize,
                                    size_t blockSize);
#ifdef __cplusplus
}
inline FixedSizeAllocator::FixedSizeAllocator(void* buffer,
                                              size_t bufSize,
                                              size_t blockSize) {
   FixedSizeAllocator_constructor(this, buffer, bufSize, blockSize);
}
#endif 


#endif 


#ifndef __HttpAsynchReq_h
#define __HttpAsynchReq_h



#ifndef __HttpAsynchResp_h
#define __HttpAsynchResp_h

#define RESPONSESTATE_IDLE 0
#define RESPONSESTATE_WRITEMODE 1
#define RESPONSESTATE_WRITEMODE_CHUNK 2
#define RESPONSESTATE_BODYSENT 3
#define RESPONSESTATE_CLOSED 4







typedef struct HttpAsynchResp
#ifdef __cplusplus
: public HttpConnection
{
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      HttpAsynchResp() {}

      
      HttpAsynchResp(char* buf, int size, HttpRequest* req);

      
      HttpAsynchResp(char* buf,int size,HttpConnection* con);

      
      bool isValid();

      
      void asynchThreadMode();

      
      ~HttpAsynchResp();

      
      void close();

      
      ThreadMutex* getMutex();

      
      int setConClose();

      
      int setLingeringClose();


      
      int setStatus(int statusCode, const char* protocol=0);

      
      int setHeader(const char *name, const char *value);

      
      int sendData(const void* data, int pktSize, int chunkSize);

      
      int sendNextChunk(const void* data,int chunkSize);

      
      BufPrint* getWriter();
#else
{
   HttpConnection super;
#endif
   BufPrint bufPrint;
   HttpConnection* con; 
   ThreadMutex* mutex; 
   BaBool statusSent;
   BaBool headerSent;
   U8 responseState;
   U8 doLingeringClose;
} HttpAsynchResp;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpAsynchResp_constructor(
   HttpAsynchResp* o, char* buf, int size, HttpRequest* req);
BA_API void HttpAsynchResp_constructor2(
   HttpAsynchResp* o, char* buf, int size, HttpConnection* con);
BA_API void HttpAsynchResp_ReqRespInit(
   HttpAsynchResp* o, char* buf, int size, HttpConnection* con);
BA_API BaBool HttpAsynchResp_isValid(HttpAsynchResp* o);
#define HttpAsynchResp_asynchThreadMode(o) \
   ((o)->mutex=HttpAsynchResp_getMutex(o))
BA_API void HttpAsynchResp_close(HttpAsynchResp* o);
#define HttpAsynchResp_destructor(o) HttpAsynchResp_close(o)
#define HttpAsynchResp_getMutex(o) \
   SoDisp_getMutex(HttpConnection_getDispatcher((HttpConnection*)(o)))
#define HttpAsynchResp_setConClose(o)\
   HttpConnection_clearKeepAlive((HttpConnection*)(o))
#define HttpAsynchResp_setLingeringClose(o) (o)->doLingeringClose=TRUE
BA_API int HttpAsynchResp_setStatus(
   HttpAsynchResp* o, int statusCode, const char* protocol);
BA_API int HttpAsynchResp_setHeader(
   HttpAsynchResp* o,const char *name,const char *value);
BA_API int HttpAsynchResp_sendData(
   HttpAsynchResp* o, const void* data, int pktSize, int chunkSize);
BA_API int HttpAsynchResp_sendNextChunk(
   HttpAsynchResp* o,const void* data,int chunkSize);
BA_API BufPrint* HttpAsynchResp_getWriter(HttpAsynchResp* o);
#define HttpAsynchResp_isAsynchThreadMode(o) ((o)->mutex ? TRUE : FALSE)
#ifdef __cplusplus
}
inline HttpAsynchResp::HttpAsynchResp(char* buf, int size, HttpRequest* req) {
    HttpAsynchResp_constructor(this, buf, size, req);
}
inline HttpAsynchResp::HttpAsynchResp(char* buf,int size,HttpConnection* con) {
    HttpAsynchResp_constructor2(this, buf, size, con);
}
inline bool HttpAsynchResp::isValid() {
      return HttpAsynchResp_isValid(this) ? TRUE : FALSE;
}
inline HttpAsynchResp::~HttpAsynchResp() {
   HttpAsynchResp_destructor(this);
}
inline void HttpAsynchResp::close() {
   HttpAsynchResp_close(this);
}
inline void HttpAsynchResp::asynchThreadMode() {
   HttpAsynchResp_asynchThreadMode(this);
}
inline ThreadMutex* HttpAsynchResp::getMutex() {
   return HttpAsynchResp_getMutex(this);
}
inline int HttpAsynchResp::setConClose() {
   return HttpAsynchResp_setConClose(this); 
}
inline int HttpAsynchResp::setLingeringClose() {
   return HttpAsynchResp_setConClose(this); 
}
inline int HttpAsynchResp::setStatus(int statusCode, const char* protocol) {
   return HttpAsynchResp_setStatus(this, statusCode, protocol); 
}
inline int HttpAsynchResp::setHeader(const char *name,const char *value) {
   return HttpAsynchResp_setHeader(this, name, value);
}
inline int HttpAsynchResp::sendData(
   const void* data, int pktSize, int chunkSize) {
   return HttpAsynchResp_sendData(this, data, pktSize, chunkSize);
}
inline int HttpAsynchResp::sendNextChunk(const void* data,int chunkSize) {
   return HttpAsynchResp_sendNextChunk(this,data,chunkSize); }
inline BufPrint* HttpAsynchResp::getWriter() {
   return HttpAsynchResp_getWriter(this);
}
#endif

 
  

#endif
#ifndef __DOXYGEN__
struct HttpAsynchReq;
#endif




typedef void (*HttpAsynchReq_OnData)(struct HttpAsynchReq* super,
                                      void* data, S32 size);


typedef struct HttpAsynchReq
{
#ifdef __cplusplus
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      HttpAsynchReq(){}

      
      HttpAsynchReq(HttpServer* server, HttpAsynchReq_OnData data);

      
      ~HttpAsynchReq();

      
      SBaFileSize getPacketSizeLeft();

      
      void* getBuffer();

      
      SBaFileSize getBufferSize();


      bool isChunkEncoding();

      
      static SBaFileSize calcPacketSize(HttpRequest* req);

      
      int start(HttpRequest* req,void* buffer, S32 bufferSize);

      
      void stop();

      
      HttpConnection* getCon(HttpAsynchReq* o);
#endif
   HttpConnection super; 
   SBaFileSize bufferSize;
   SBaFileSize packetSizeLeft;
   SBaFileSize offset;
   HttpAsynchReq_OnData data;
   BaBool* isTerminatedPtr;
   U8* buffer;
   BaBool chunkEncoding;
} HttpAsynchReq;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpAsynchReq_constructor(HttpAsynchReq* o,
                                HttpServer* server,
                                HttpAsynchReq_OnData data);
BA_API void HttpAsynchReq_destructor(HttpAsynchReq* o);
#define HttpAsynchReq_getPacketSizeLeft(o) (o)->packetSizeLeft
#define HttpAsynchReq_getBuffer(o) (o)->buffer
#define HttpAsynchReq_getBufferSize(o) (o)->bufferSize
#define HttpAsynchReq_isChunkEncoding(o) (o)->chunkEncoding
#define HttpAsynchReq_getServer(o) \
  HttpConnection_getServer((HttpConnection*)(o))
BA_API SBaFileSize HttpAsynchReq_calcPacketSize(HttpRequest* req);
BA_API int HttpAsynchReq_start(
   HttpAsynchReq* o,HttpRequest* req, void* buffer, S32 bufferSize);

BA_API void HttpAsynchReq_stop(HttpAsynchReq* o);
BA_API HttpConnection* HttpAsynchReq_getCon(HttpAsynchReq* o);
#ifdef __cplusplus
}
inline HttpAsynchReq::HttpAsynchReq(HttpServer* server,
                               HttpAsynchReq_OnData data) {
   HttpAsynchReq_constructor(this, server, data);
}
inline HttpAsynchReq::~HttpAsynchReq() {
   HttpAsynchReq_destructor(this);
}
inline SBaFileSize HttpAsynchReq::getPacketSizeLeft() {
   return HttpAsynchReq_getPacketSizeLeft(this);
}
inline void* HttpAsynchReq::getBuffer() {
   return HttpAsynchReq_getBuffer(this);
}
inline SBaFileSize HttpAsynchReq::getBufferSize() {
   return HttpAsynchReq_getBufferSize(this);
}
inline bool HttpAsynchReq::isChunkEncoding() {
   return HttpAsynchReq_isChunkEncoding(this) ? true : false;
}
inline SBaFileSize HttpAsynchReq::calcPacketSize(HttpRequest* req) {
   return HttpAsynchReq_calcPacketSize(req);
}
inline int HttpAsynchReq::start(HttpRequest* req,void* buffer, S32 bufferSize){
   return HttpAsynchReq_start(this,req,buffer,bufferSize);
}
inline void HttpAsynchReq::stop() {
   HttpAsynchReq_stop(this);
}

inline HttpConnection* HttpAsynchReq::getCon(HttpAsynchReq* o){
   return HttpAsynchReq_getCon(this); }
#endif




typedef struct HttpAsynchReqResp
#ifdef __cplusplus
   :public HttpAsynchReq
{
      HttpAsynchReqResp(){}

      
      HttpAsynchReqResp(HttpServer* server, HttpAsynchReq_OnData onData);

      
      int start(HttpRequest* req,void* recBuf,S32 recBufSize,
                void* sendBuf,S32 sendBufSize);
      
      int startResp(HttpRequest* req,void* sendBuf,S32 sendBufSize);

#if 0
      
      void disableRecEv();

      
      void enableRecEv();
#endif

      
      ThreadMutex* getMutex();

      
      HttpServer* getServer();

      
      HttpAsynchResp* getResponse();
#else
#if 0
}//Make Emacs happy
#endif
{
   HttpAsynchReq super;
#endif
   HttpAsynchResp resp;
}HttpAsynchReqResp;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpAsynchReqResp_constructor(HttpAsynchReqResp* o,
                                          HttpServer* server,
                                          HttpAsynchReq_OnData data);
#if 0
void HttpAsynchReqResp_disableRecEv(HttpAsynchReqResp* o);
void HttpAsynchReqResp_enableRecEv(HttpAsynchReqResp* o);
#endif
BA_API int HttpAsynchReqResp_start(HttpAsynchReqResp* o,
                                   HttpRequest* req,
                                   void* recBuf,
                                   S32 recBufSize,
                                   void* sendBuf,
                                   S32 sendBufSize);
BA_API int HttpAsynchReqResp_startResp(HttpAsynchReqResp* o,
                                       HttpRequest* req,
                                       void* sendBuf,
                                       S32 sendBufSize);
#define HttpAsynchReqResp_destructor(o) do {\
   HttpAsynchResp_destructor(&(o)->resp);\
   HttpAsynchReq_destructor((HttpAsynchReq*)(o));\
}while(0)
#define HttpAsynchReqResp_getPacketSizeLeft(o)\
   HttpAsynchReq_getPacketSizeLeft((HttpAsynchReq*)o)
#define HttpAsynchReqResp_getBuffer(o)\
   HttpAsynchReq_getBuffer((HttpAsynchReq*)o)
#define HttpAsynchReqResp_getBufferSize(o)\
   HttpAsynchReq_getBufferSize((HttpAsynchReq*)o)
#define HttpAsynchReqResp_isChunkEncoding(o)\
   HttpAsynchReq_isChunkEncoding((HttpAsynchReq*)o)
#define HttpAsynchReqResp_calcPacketSize(req)\
   HttpAsynchReq_calcPacketSize(req)

#define HttpAsynchReqResp_getCon(o) ((o))->resp.con
#define HttpAsynchReqResp_getMutex(o) \
   SoDisp_getMutex(HttpConnection_getDispatcher( \
     HttpAsynchReqResp_getCon(o)))
#define HttpAsynchReqResp_getServer(o) \
  HttpConnection_getServer(HttpAsynchReqResp_getCon(o))
#define HttpAsynchReqResp_getResponse(o) (&(o)->resp)
#ifdef __cplusplus
}
inline HttpAsynchReqResp::HttpAsynchReqResp(HttpServer* server,
                                     HttpAsynchReq_OnData data) {
   HttpAsynchReqResp_constructor(this, server, data);
}
inline int HttpAsynchReqResp::start(HttpRequest* req,
                                    void* recBuf,
                                    S32 recBufSize,
                                    void* sendBuf,
                                    S32 sendBufSize) {
   return HttpAsynchReqResp_start(
      this,req,recBuf,recBufSize,sendBuf,sendBufSize); }
inline int HttpAsynchReqResp::startResp(HttpRequest* req,
                                        void* sendBuf,
                                        S32 sendBufSize) {
   return HttpAsynchReqResp_startResp(this,req,sendBuf,sendBufSize); }
#if 0
inline void HttpAsynchReqResp::disableRecEv() {
   HttpAsynchReqResp_disableRecEv(this); }
inline void HttpAsynchReqResp::enableRecEv() {
   HttpAsynchReqResp_enableRecEv(this); }
#endif
inline ThreadMutex* HttpAsynchReqResp::getMutex() {
   return HttpAsynchReqResp_getMutex(this);
}
inline struct HttpServer* HttpAsynchReqResp::getServer() {
   return HttpAsynchReqResp_getServer(this);
}
inline HttpAsynchResp* HttpAsynchReqResp::getResponse() {
   return HttpAsynchReqResp_getResponse(this);
}
#endif


 
  

#endif


#ifndef _HttpCmdThreadPool_h
#define _HttpCmdThreadPool_h




#ifndef _HttpCmdThreadPoolIntf_h
#define _HttpCmdThreadPoolIntf_h


 
struct HttpCmdThreadPoolIntf;

typedef int(*HttpCmdThreadPoolIntf_DoPage)(
   struct HttpCmdThreadPoolIntf* o, HttpCommand* cmd,HttpPage* page);
typedef int(*HttpCmdThreadPoolIntf_DoDir)(
   struct HttpCmdThreadPoolIntf* o,HttpCommand* cmd,
   HttpDir* dir);

typedef struct HttpCmdThreadPoolIntf
{
      HttpCmdThreadPoolIntf_DoPage doPage;
      HttpCmdThreadPoolIntf_DoDir doDir;
}  HttpCmdThreadPoolIntf;

#define HttpCmdThreadPoolIntf_doDir(o, cmd, dir) \
   (o)->doDir(o, cmd, dir)
#define HttpCmdThreadPoolIntf_doPage(o, cmd, page) (o)->doPage(o, cmd, page)

#endif
struct HttpCmdThreadPool;

typedef enum {
   HttpCmdThreadState_Idle,
   HttpCmdThreadState_RunDir,
   HttpCmdThreadState_Exit
} HttpCmdThreadState;


#ifndef __DOXYGEN__
typedef struct
{
      Thread super;
      DoubleLink node;
      ThreadSemaphore sem;
      struct HttpCmdThreadPool* pool;
      HttpCommand* cmd;
      HttpDir* dir;
      HttpCmdThreadState state;
} HttpCmdThread;
#endif




typedef struct HttpCmdThreadPool
{
#ifdef __cplusplus

      
      HttpCmdThreadPool(
         HttpServer* server,ThreadPriority priority,int stackSize);

      
      ~HttpCmdThreadPool();
   private:
#endif
      HttpCmdThreadPoolIntf super;
      DoubleList freeList;
      DoubleList runningList;
      SoDisp* dispatcher;
      HttpServer* server;
      HttpCmdThread* pool;
#ifdef BA_SELECT_DISP
      ThreadSemaphore sem;
#endif
} HttpCmdThreadPool;



#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpCmdThreadPool_constructor(HttpCmdThreadPool* o,
                                          HttpServer* server,
                                          ThreadPriority priority,
                                          int stackSize);
BA_API void HttpCmdThreadPool_destructor(HttpCmdThreadPool* o);
#ifdef __cplusplus
}
inline HttpCmdThreadPool::HttpCmdThreadPool(HttpServer* server,
                                            ThreadPriority priority,
                                            int stackSize) {
   HttpCmdThreadPool_constructor(this, server, priority, stackSize); }
inline HttpCmdThreadPool::~HttpCmdThreadPool() {
   HttpCmdThreadPool_destructor(this); }
#endif

 


#endif


#ifndef __HttpFiber_h
#define __HttpFiber_h

 
typedef struct HttpFiberHandle
{
      HttpRequest* req;
      const char* path;
      S32 derivedSize;
      S32 paramSize;
      S32 dataSize;
      S32 pathSize;
      S32 sendBufSize;
} HttpFiberHandle;
 






typedef struct HttpFiber
#ifdef __cplusplus
      : public HttpAsynchReqResp
{

      
      HttpParameter* getParam();

      
      const char* getPath();

      
      HttpMethod getMethodType();

      
      void* getData();

      
      S32 getDataSize();
 
      
      HttpFiber(HttpAsynchReq_OnData onData, HttpFiberHandle* fh);

      
      int start(void* derivedObjPtr, HttpFiberHandle* fh);

      
      static S32 calcRequiredSize(HttpRequest* req,
                                  size_t derivedSize,
                                  bool copyParameters,
                                  size_t sendBufSize,
                                  HttpFiberHandle* fh);

      
      static S32 calcRequiredSize(HttpCommand* cmd,
                                  const char* path,
                                  size_t derivedSize,
                                  bool copyParameters,
                                  size_t sendBufSize,
                                  HttpFiberHandle* fh);
#if 0
}
#endif
#else
{
   HttpAsynchReqResp super;
#endif
      HttpParameter* param;
      char* path;
      HttpMethod methodType;
} HttpFiber;

#ifdef __cplusplus
extern "C" {
#endif

#define HttpFiber_getMutex(o) \
   HttpAsynchReqResp_getMutex((HttpAsynchReqResp*)(o))
#define HttpFiber_getServer(o) \
   HttpAsynchReqResp_getServer((HttpAsynchReqResp*)(o))
#define HttpFiber_getResponse(o) \
   HttpAsynchReqResp_getResponse((HttpAsynchReqResp*)(o))

#define HttpFiber_destructor(o) \
  HttpAsynchReqResp_destructor((HttpAsynchReqResp*)(o))
#define HttpFiber_getParam(o) (o)->param
#define HttpFiber_getPath(o) (o)->path
#define HttpFiber_getMethodType(o) (o)->methodType
#define HttpFiber_getData(o) ((HttpAsynchReq*)(o))->buffer
#define HttpFiber_getDataSize(o) ((HttpAsynchReq*)(o))->bufferSize
BA_API void HttpFiber_constructor(
   HttpFiber* o,HttpAsynchReq_OnData onData,HttpFiberHandle* fh);
BA_API int HttpFiber_start(
   HttpFiber* o, void* derivedObjPtr, HttpFiberHandle* fh);
BA_API S32 HttpFiber_calcRequiredSize(HttpRequest* req,
                                      size_t derivedSize,
                                      BaBool copyParameters,
                                      size_t sendBufSize,
                                      HttpFiberHandle* fh);
BA_API S32 HttpFiber_calcRequiredSize2(HttpCommand* cmd,
                                       const char* path,
                                       size_t derivedSize,
                                       BaBool copyParameters,
                                       size_t sendBufSize,
                                       HttpFiberHandle* fh);
#ifdef __cplusplus
}
inline void* HttpFiber::getData() {
   return HttpFiber_getData(this);
}
inline S32 HttpFiber::getDataSize() {
   return HttpFiber_getDataSize(this);
}
inline HttpParameter* HttpFiber::getParam() {
   return HttpFiber_getParam(this);
}
inline const char* HttpFiber::getPath() {
   return HttpFiber_getPath(this);
}
inline HttpMethod HttpFiber::getMethodType() {
   return HttpFiber_getMethodType(this);
}
inline HttpFiber::HttpFiber(HttpAsynchReq_OnData onData,HttpFiberHandle* fh){
   HttpFiber_constructor(this, onData,fh);
}
inline int HttpFiber::start(void* derivedObjPtr, HttpFiberHandle* fh) {
   return HttpFiber_start(this, derivedObjPtr, fh);
}
inline S32 HttpFiber::calcRequiredSize(HttpRequest* req,
                                       size_t derivedSize,
                                       bool copyParameters,
                                       size_t sendBufSize,
                                       HttpFiberHandle* fh) {
   return HttpFiber_calcRequiredSize(
      req,derivedSize,copyParameters?TRUE:FALSE,sendBufSize,fh);
}
inline S32 HttpFiber::calcRequiredSize(HttpCommand* cmd,
                                       const char* path,
                                       size_t derivedSize,
                                       bool copyParameters,
                                       size_t sendBufSize,
                                       HttpFiberHandle* fh) {
   return HttpFiber_calcRequiredSize2(
      cmd,path,derivedSize,copyParameters?TRUE:FALSE,sendBufSize,fh);
}
#endif 



 
  

#endif


#ifndef _HttpRecData_h
#define _HttpRecData_h


typedef struct HttpRecData
{
#ifdef __cplusplus

      
      static SBaFileSize valid(HttpRequest* req);


      
      HttpRecData(HttpRequest* req);

      
      ~HttpRecData();

      
      S32 read(void* buf, S32 bufSize);
#endif
      HttpRequest* req;
      HttpConnection* con;
      SBaFileSize sizeLeft;
      SBaFileSize bufSize;
      SBaFileSize readPos;
      SBaFileSize chunkSize;
} HttpRecData;

#ifdef __cplusplus
extern "C" {
#endif
BA_API SBaFileSize HttpRecData_valid(HttpRequest* req);
BA_API void HttpRecData_constructor(HttpRecData* o, HttpRequest* req);
BA_API void HttpRecData_destructor(HttpRecData* o);
BA_API S32 HttpRecData_read(HttpRecData* o, void* buf, S32 bufSize);
#ifdef __cplusplus
}
inline SBaFileSize HttpRecData::valid(HttpRequest* req) {
   return HttpRecData_valid(req);
}
inline HttpRecData::HttpRecData(HttpRequest* req) {
   HttpRecData_constructor(this, req);
}
inline S32 HttpRecData::read(void* buf, S32 bufSize) {
   return HttpRecData_read(this, buf, bufSize);
}
inline HttpRecData::~HttpRecData() {
   HttpRecData_destructor(this);
}
#endif

 

#endif


#ifndef _HttpResRdr_h
#define _HttpResRdr_h

struct HttpRdFilter;
typedef void (*HttpRdFilter_Service)(struct HttpRdFilter* o,
                                     const char* name,
                                     IoStat* st,
                                     HttpCommand* cmd);


typedef struct HttpRdFilter
{
      DoubleLink super;
      HttpRdFilter_Service serviceFp;
      const char* ext; 
} HttpRdFilter;

BA_API void HttpRdFilter_constructor(
   HttpRdFilter* o, const char* ext, HttpRdFilter_Service serviceFp);

BA_API void HttpRdFilter_destructor(HttpRdFilter* o);



typedef struct HttpResRdr
#ifdef __cplusplus
: public HttpDir
{
      HttpResRdr() {}
      
      HttpResRdr(IoIntf* io, const char* dirName,
                  AllocatorIntf* alloc=0, S8 priority=0);

      
      HttpResRdr(IoIntf* io, const char* domain, const char* p404,
                 AllocatorIntf* alloc=0, S8 priority=0);

      
      int insertPrologDir(HttpDir* dir);

      
      ~HttpResRdr();

      
      int installFilter(HttpRdFilter* filter);

      
      void  setMaxAge(BaTime maxAge);

      
      static void sendFile(
         IoIntf* io,const char* name, IoStat* st, HttpCommand* cmd);

      
      IoIntf* getIo();
#if 0
}
#endif
#else
{
      HttpDir super; 
#endif
      DoubleList filterList;
      AllocatorIntf* alloc;
      IoIntf* io;
      HttpDir_Service superServiceFunc;
      HttpDir* prologDirRoot;
      const char* domain;
      const char* p404;
      BaTime maxAge;
      int maxFilterLen;
} HttpResRdr;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpResRdr_constructor(
   HttpResRdr* o, IoIntf* io, const char* dirName,
   AllocatorIntf* alloc, S8 priority);
BA_API void HttpResRdr_constructor2(
   HttpResRdr* o,IoIntf* io,const char* domain,
   const char* p404,AllocatorIntf* alloc,
   S8 priority);
BA_API int HttpResRdr_insertPrologDir(HttpResRdr* o, HttpDir* dir);
BA_API void HttpResRdr_destructor(HttpResRdr* o);
BA_API int HttpResRdr_installFilter(HttpResRdr* o, HttpRdFilter* filter);
#define HttpResRdr_setMaxAge(o, maxAgeMA) (o)->maxAge=maxAgeMA
#define HttpResRdr_setAuthenticator(o, authenticator, realm) \
   HttpDir_setAuthenticator((HttpDir*)o, authenticator, realm)
BA_API void HttpResRdr_sendFile(IoIntf* io,const char* name,
   IoStat* st,HttpCommand* cmd);
BA_API void set_deflategzip(IoIntf_DeflateGzip ptr);
BA_API IoIntf_DeflateGzip get_deflategzip(void);


#define HttpResRdr_getIo(o) (o)->io
#ifdef __cplusplus
}
inline HttpResRdr::HttpResRdr(IoIntf* io, const char* domain, const char* p404,
                              AllocatorIntf* alloc, S8 priority) {
   HttpResRdr_constructor2(this, io, domain, p404, alloc, priority);
}
inline HttpResRdr::HttpResRdr(IoIntf* io, const char* dirName,
                              AllocatorIntf* alloc, S8 priority) {
   HttpResRdr_constructor(this, io, dirName, alloc, priority);
}

inline int HttpResRdr::insertPrologDir(HttpDir* dir) {
   return HttpResRdr_insertPrologDir(this, dir);
}

inline HttpResRdr::~HttpResRdr(){
   HttpResRdr_destructor(this);
}
inline int HttpResRdr::installFilter(HttpRdFilter* filter){
   return HttpResRdr_installFilter(this, filter);
}
inline void  HttpResRdr::setMaxAge(BaTime maxAge){
   HttpResRdr_setMaxAge(this, maxAge);
}
inline void HttpResRdr::sendFile(
   IoIntf* io, const char* name, IoStat* st, HttpCommand* cmd){
   HttpResRdr_sendFile(io,name,st,cmd);
}
inline IoIntf* HttpResRdr::getIo() {
   return HttpResRdr_getIo(this);
}
#endif


#endif

#ifndef _SharkSslCipher_h
#define _SharkSslCipher_h


#ifdef _SHARKSSLCON_HS_C_

static const SharkSslCipherSuite sharkSslCipherSuiteList[] =
{
   
   #if SHARKSSL_PSK_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc, 
   SharkSslCon_sha1,
   SHARKSSL_PSK_WITH_AES_256_CBC_SHA,
   32, 16, 
   SHARKSSL_SHA1_MAC_LEN, 
   SHARKSSL_CS_PSK
   },
   #endif
   #if SHARKSSL_PSK_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc, 
   SharkSslCon_sha1,
   SHARKSSL_PSK_WITH_AES_128_CBC_SHA,
   16, 16, 
   SHARKSSL_SHA1_MAC_LEN, 
   SHARKSSL_CS_PSK
   },
   #endif
   #if SHARKSSL_PSK_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc, 
   SharkSslCon_sha1,
   SHARKSSL_PSK_WITH_3DES_EDE_CBC_SHA,
   24,  8, 
   SHARKSSL_SHA1_MAC_LEN, 
   SHARKSSL_CS_PSK
   },
   #endif
   #if SHARKSSL_PSK_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4, 
   SharkSslCon_sha1,
   SHARKSSL_PSK_WITH_ARC4_128_SHA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN, 
   SHARKSSL_CS_PSK 
   },
   #endif
   
   #if SHARKSSL_ENABLE_ECDHE_ECDSA
   
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_DSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha384,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 16,  
   SHARKSSL_SHA384_MAC_LEN  
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA | SHARKSSL_CS_TLS12,
   16, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA,
   32, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA,
   16, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_ECDSA_WITH_ARC4_128_SHA,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_ECDSA_WITH_NULL_SHA
   {
   SharkSslCon_null,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_ECDSA_WITH_NULL_SHA,
   SHARKSSL_CS_EC |  SHARKSSL_CS_DHE | SHARKSSL_CS_DSA,
   0,   0,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #endif

   #if SHARKSSL_ENABLE_ECDH_ECDSA
   
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_ECDH_ECDSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA384
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha384,
   SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 16,  
   SHARKSSL_SHA384_MAC_LEN  
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_128_GCM_SHA256
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_ECDH_ECDSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA | SHARKSSL_CS_TLS12,
   16, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA,
   32, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA,
   16, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_ECDSA_WITH_ARC4_128_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_ECDSA_WITH_NULL_SHA
   {
   SharkSslCon_null,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_ECDSA_WITH_NULL_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DSA,
   0,   0,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #endif

   #if SHARKSSL_ENABLE_RSA
   
   #if SHARKSSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha384,
   SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 16,  
   SHARKSSL_SHA384_MAC_LEN  
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   16, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   32, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   16, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_RSA_WITH_ARC4_128_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDHE_RSA_WITH_NULL_SHA
   {
   SharkSslCon_null,
   SharkSslCon_sha1,
   SHARKSSL_ECDHE_RSA_WITH_NULL_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   0,   0,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif

   
   #if SHARKSSL_ECDH_RSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_ECDH_RSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA384
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha384,
   SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA384,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 16,  
   SHARKSSL_SHA384_MAC_LEN  
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_AES_128_GCM_SHA256
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_ECDH_RSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   16, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA,
   32, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA,
   16, 16,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_RSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_RSA_WITH_ARC4_128_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_ECDH_RSA_WITH_NULL_SHA
   {
   SharkSslCon_null,
   SharkSslCon_sha1,
   SHARKSSL_ECDH_RSA_WITH_NULL_SHA,
   SHARKSSL_CS_EC | SHARKSSL_CS_RSA,
   0,   0,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif

   
   #if SHARKSSL_DHE_RSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_DHE_RSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_AES_256_CCM
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_256_CCM,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   32, 
   0,  
   16  
   },
   #endif   
   #if SHARKSSL_DHE_RSA_WITH_AES_256_CCM_8
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_256_CCM_8,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   32, 
   0,  
   8   
   },
   #endif   
   #if SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA256,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   32, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA ,
   32, 16, 
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_AES_128_GCM_SHA256
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_AES_128_CCM
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_128_CCM,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif   
   #if SHARKSSL_DHE_RSA_WITH_AES_128_CCM_8
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_128_CCM_8,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   8   
   },
   #endif   
   #if SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   16, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   16, 16,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_DHE_RSA_WITH_DES_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_DHE_RSA_WITH_DES_CBC_SHA,
   SHARKSSL_CS_DHE | SHARKSSL_CS_RSA,
   8,   8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif

   
   #if SHARKSSL_SSL_RSA_WITH_AES_256_GCM_SHA384
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha384,
   SHARKSSL_SSL_RSA_WITH_AES_256_GCM_SHA384,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12 | SHARKSSL_CS_SHA384,
   32, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_AES_256_CCM
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_256_CCM,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   32, 
   0,  
   16  
   },
   #endif   
   #if SHARKSSL_SSL_RSA_WITH_AES_256_CCM_8
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_256_CCM_8,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   32, 
   0,  
   8   
   },
   #endif   
   #if SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA256,
   SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   32, 16, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA,
   SHARKSSL_CS_RSA,
   32, 16,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_AES_128_GCM_SHA256 
   {
   SharkSslCon_aes_gcm,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_128_GCM_SHA256,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_AES_128_CCM
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_128_CCM,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   16  
   },
   #endif   
   #if SHARKSSL_SSL_RSA_WITH_AES_128_CCM_8
   {
   SharkSslCon_aes_ccm,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_128_CCM_8,
   SHARKSSL_CS_RSA | SHARKSSL_CS_AEAD | SHARKSSL_CS_TLS12,
   16, 
   0,  
   8   
   },
   #endif   
   #if SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA256
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA256,
   SHARKSSL_CS_RSA | SHARKSSL_CS_TLS12,
   16, 16
   , SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA
   {
   SharkSslCon_aes_cbc,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA,
   SHARKSSL_CS_RSA,
   16, 16,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_3DES_EDE_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_3DES_EDE_CBC_SHA,
   SHARKSSL_CS_RSA,
   24,  8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_ARC4_128_SHA
   {
   SharkSslCon_arc4,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_ARC4_128_SHA,
   SHARKSSL_CS_RSA,
   16,  0,  
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_ARC4_128_MD5
   {
   SharkSslCon_arc4,
   SharkSslCon_md5,
   SHARKSSL_SSL_RSA_WITH_ARC4_128_MD5,
   SHARKSSL_CS_RSA,
   16,  0,  
   SHARKSSL_MD5_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_DES_CBC_SHA
   {
   SharkSslCon_des_cbc,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_DES_CBC_SHA,
   SHARKSSL_CS_RSA,
   8,   8,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_NULL_SHA256
   {
   SharkSslCon_null,
   SharkSslCon_sha256,
   SHARKSSL_SSL_RSA_WITH_NULL_SHA256,
   SHARKSSL_CS_RSA,
   0,   0, 
   SHARKSSL_SHA256_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_NULL_SHA
   {
   SharkSslCon_null,
   SharkSslCon_sha1,
   SHARKSSL_SSL_RSA_WITH_NULL_SHA,
   SHARKSSL_CS_RSA,
   0,   0,
   SHARKSSL_SHA1_MAC_LEN
   },
   #endif
   #if SHARKSSL_SSL_RSA_WITH_NULL_MD5
   {
   SharkSslCon_null,
   SharkSslCon_md5,
   SHARKSSL_SSL_RSA_WITH_NULL_MD5,
   SHARKSSL_CS_RSA,
   0,   0,
   SHARKSSL_MD5_MAC_LEN
   },
   #endif
   #endif  
};
#endif  

#endif


#ifndef _HttpUpload_h
#define _HttpUpload_h



#ifndef __HttpMultipartUpload_h
#define __HttpMultipartUpload_h

typedef enum
{
   MultipartUpload_NoError=0,
   MultipartUpload_ConnectionTerminated=-100,
   MultipartUpload_NoMemory,
   MultipartUpload_ParseError1,
   MultipartUpload_ParseError2,
   MultipartUpload_ParseError3,
   MultipartUpload_ParseError4,
   MultipartUpload_ParseError5,
   MultipartUpload_ParseError6,
   MultipartUpload_UserRetErr
} MultipartUpload_ErrorType;

#ifndef __DOXYGEN__
struct MultipartUpload;
#endif


typedef void (*MultipartUpload_EndOfReq)(
   struct MultipartUpload* o);



typedef int (*MultipartUpload_FormData)(
   struct MultipartUpload* o,
   const char* name,
   const char* value);


typedef int (*MultipartUpload_FileBegin)(
   struct MultipartUpload* o,
   const char* name,
   const char* fileName,
   const char* contentType,
   const char* contentTransferEncoding);


typedef int (*MultipartUpload_FileData)(
   struct MultipartUpload* o,
   const U8* data,
   U16 len);


typedef void (*MultipartUpload_Error)(
   struct MultipartUpload* o,
   MultipartUpload_ErrorType e);



typedef enum {
   MultipartUpload_ReadBoundaryTag,
   MultipartUpload_ReadHeaders,
   MultipartUpload_ReadFormData,
   MultipartUpload_ReadFileData
} MultipartUpload_States;



typedef struct MultipartUpload
{
#ifdef __cplusplus
     MultipartUpload() {}
 
      
      MultipartUpload(HttpServer* server,
                      MultipartUpload_EndOfReq onEndOfReq,
                      MultipartUpload_FormData onFormData,
                      MultipartUpload_FileBegin onFileBegin,
                      MultipartUpload_FileData onFileData,
                      MultipartUpload_Error onError,
                      U32 bufferSize,
                      AllocatorIntf* allocator = 0);

      
      ~MultipartUpload();

      
      int start(HttpRequest *req);


      int run(HttpRequest *req, bool setKeepAlive=true);

      
      HttpConnection* getCon(MultipartUpload* o);
 
      
      HttpServer* getServer();

   private:
#endif
      HttpConnection super; 

       
      DoubleList boundaryStack;
      MultipartUpload_EndOfReq endOfReq;
      MultipartUpload_FormData formData;
      MultipartUpload_FileBegin fileBegin;
      MultipartUpload_FileData fileData;
      MultipartUpload_Error onError;
      HttpConnection* con; 
      char* dataBuffer;
      char* name;
      char* fileName;
      char* contentType;
      char* contentTransferEncoding;
      char* currBName;
      AllocatorIntf* alloc;
      MultipartUpload_States state;
      U32 currentI;
      U32 readI;
      U32 lineStartI;
      U32 lineEndI;
      U32 dataBufferSize;
      U32 expandSize;
      U32 maxFormSize;
      BaBool newBoundaryTag;
      BaBool copyingHttpReqData;
} MultipartUpload;


#ifdef __cplusplus
extern "C" {
#endif
void
BA_API MultipartUpload_constructor(
   MultipartUpload* o,
   HttpServer* server,
   MultipartUpload_EndOfReq endOfReq,
   MultipartUpload_FormData formData,
   MultipartUpload_FileBegin fileBegin,
   MultipartUpload_FileData fileData,
   MultipartUpload_Error onError,
   U32 bufferSize,
   AllocatorIntf* allocator);
BA_API void MultipartUpload_destructor(MultipartUpload* o);
BA_API int MultipartUpload_start(MultipartUpload* o, HttpRequest *req);
BA_API int MultipartUpload_run(
   MultipartUpload* o, HttpRequest *req, BaBool setKeepAlive);
BA_API HttpConnection* MultipartUpload_getCon(MultipartUpload* o); 
#define MultipartUpload_getServer(o) \
   HttpConnection_getServer((HttpConnection*)(o))
#ifdef __cplusplus
}
inline MultipartUpload::MultipartUpload(
   HttpServer* server,
   MultipartUpload_EndOfReq endOfReq,
   MultipartUpload_FormData formData,
   MultipartUpload_FileBegin fileBegin,
   MultipartUpload_FileData fileData,
   MultipartUpload_Error onError,
   U32 size,
   AllocatorIntf* allocator) {
   MultipartUpload_constructor(this, server, endOfReq, formData,
                               fileBegin, fileData, onError, size, allocator);
}
inline MultipartUpload::~MultipartUpload() {
   MultipartUpload_destructor(this);
}
inline int MultipartUpload::start(HttpRequest *req){
   return MultipartUpload_start(this,req);
}
inline int MultipartUpload::run(HttpRequest *req, bool setKeepAlive) {
   return MultipartUpload_run(this,req,setKeepAlive?TRUE:FALSE);
}
inline HttpConnection* MultipartUpload::getCon(MultipartUpload* o){
   return MultipartUpload_getCon(this); }
inline HttpServer* MultipartUpload::getServer(){
   return MultipartUpload_getServer(this);
}
#endif

 
  

#endif
struct HttpConnection;



#ifdef __cplusplus

struct HttpUploadNode
{
      
      const char* getName();

      
      const char* getUrl();

      
      HttpAsynchResp* getResponse();

      struct HttpConnection* getConnection();

      IoIntfPtr getIoIntf();

      
      HttpSession* getSession();


      
      bool isMultipartUpload();
};
#else
struct HttpUploadNode;
#endif

#ifdef __cplusplus
extern "C" {
#endif
BA_API const char* HttpUploadNode_getName(struct HttpUploadNode* o);
BA_API const char* HttpUploadNode_getUrl(struct HttpUploadNode* o);
BA_API HttpAsynchResp* HttpUploadNode_getResponse(struct HttpUploadNode* o);
BA_API struct HttpConnection* HttpUploadNode_getConnection(
   struct HttpUploadNode* o);
BA_API IoIntfPtr HttpUploadNode_getIoIntf(struct HttpUploadNode* o);
BA_API void* HttpUploadNode_getdata(struct HttpUploadNode* o);
BA_API HttpSession* HttpUploadNode_getSession(struct HttpUploadNode* o);
BA_API BaBool HttpUploadNode_isMultipartUpload(struct HttpUploadNode* o);
BA_API BaBool HttpUploadNode_isResponseMode(struct HttpUploadNode* o);
BA_API BaBool HttpUploadNode_initial(struct HttpUploadNode* o);
BA_API int HttpUploadNode_decrRef(struct HttpUploadNode* o);
BA_API void HttpUploadNode_incRef(struct HttpUploadNode* o);
BA_API void set_inflategzip(IoIntf_InflateGzip ptr);
BA_API IoIntf_InflateGzip get_inflategzip(void);
#ifdef __cplusplus
}
inline const char* HttpUploadNode::getName() {
   return HttpUploadNode_getName(this); }
inline const char* HttpUploadNode::getUrl() {
   return  HttpUploadNode_getUrl(this); }
inline HttpAsynchResp* HttpUploadNode::getResponse() {
   return HttpUploadNode_getResponse(this); }
inline struct HttpConnection* HttpUploadNode::getConnection() {
   return HttpUploadNode_getConnection(this); }
inline IoIntfPtr HttpUploadNode::getIoIntf() {
   return HttpUploadNode_getIoIntf(this); }
inline  HttpSession* HttpUploadNode::getSession() {
   return HttpUploadNode_getSession(this); }
inline bool HttpUploadNode::isMultipartUpload() {
   return HttpUploadNode_isMultipartUpload(this) ? true : false; }
#endif



#ifndef __DOXYGEN__
struct HttpUploadCbIntf;
#endif

typedef void (*HttpUploadCbIntf_OnFile)(
   struct HttpUploadCbIntf* o, struct HttpUploadNode* node, BaBool completed);
typedef void (*HttpUploadCbIntf_OnError)(
   struct HttpUploadCbIntf* o, struct HttpUploadNode* node,
   int ecode, const char* extraEcode);


typedef struct HttpUploadCbIntf
{
#ifdef __cplusplus
      HttpUploadCbIntf(){}

      
      HttpUploadCbIntf(HttpUploadCbIntf_OnFile of,HttpUploadCbIntf_OnError oe);
#endif
      HttpUploadCbIntf_OnFile onFileFp;
      HttpUploadCbIntf_OnError onErrorFp;
} HttpUploadCbIntf;

#define HttpUploadCbIntf_constructor(o, onFile, onError) do { \
   (o)->onFileFp=onFile; \
   (o)->onErrorFp=onError; \
} while(0)

#ifdef __cplusplus
      inline HttpUploadCbIntf::HttpUploadCbIntf(
         HttpUploadCbIntf_OnFile of,HttpUploadCbIntf_OnError oe) {
         HttpUploadCbIntf_constructor(this, of, oe);
      }
#endif



typedef struct HttpUpload
{
#ifdef __cplusplus
      HttpUpload() {}

      
      HttpUpload(IoIntfPtr io, AllocatorIntf* alloc,
                 HttpUploadCbIntf* uploadCb, int maxUploads);

      
      ~HttpUpload();

      
      int service(const char* name, HttpCommand* cmd, void* userdata=0);

      
      IoIntfPtr getIoIntf();
#endif

      DoubleList uploadNodeList;
      IoIntfPtr io;
      AllocatorIntf* alloc;
      HttpUploadCbIntf* uploadCb;
      int uploadsLeft;
} HttpUpload;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void HttpUpload_constructor(
   HttpUpload* o, IoIntfPtr io, AllocatorIntf* alloc,
   HttpUploadCbIntf* uploadCb, int maxUploads);
BA_API void HttpUpload_destructor(HttpUpload* o);
BA_API int HttpUpload_service(
   HttpUpload* o, const char* name, HttpCommand* cmd, void* userdata);
#define HttpUpload_getIoIntf(o) (o)->io
#ifdef __cplusplus
}
inline HttpUpload::HttpUpload(IoIntfPtr io, AllocatorIntf* alloc,
                              HttpUploadCbIntf* uploadCb, int maxUploads) {
   HttpUpload_constructor(this, io, alloc, uploadCb, maxUploads); }
inline HttpUpload::~HttpUpload() {
    HttpUpload_destructor(this); }
inline int HttpUpload::service(const char* name, HttpCommand* cmd, void* userdata) {
   return  HttpUpload_service(this, name, cmd,userdata); }
inline IoIntfPtr HttpUpload::getIoIntf() {
   return HttpUpload_getIoIntf(this); }
#endif

 

#endif


#ifndef _IoBufPrint_h
#define _IoBufPrint_h 

typedef struct IoBufPrint
{
      BufPrint super;
      IoIntf* io;
      ResIntfPtr res;
} IoBufPrint;


BA_API IoBufPrint* IoBufPrint_create(AllocatorIntf* alloc,
                              IoIntf* io,
                              size_t bufSize,
                              const char* name);
BA_API IoBufPrint* IoBufPrint_create2(AllocatorIntf* alloc,
                               size_t bufSize,
                               ResIntfPtr out);
BA_API void IoBufPrint_destructor(IoBufPrint* o);

#endif

#ifndef __IoIntfCspReader_h
#define __IoIntfCspReader_h

typedef struct IoIntfCspReader
#ifdef __cplusplus
: public CspReader
{
      IoIntfCspReader() {}

   
   IoIntfCspReader(IoIntf* io, const char* pathName);
      
   
   ~IoIntfCspReader();

   
    int close();

   private:
#else
{
   CspReader reader;
#endif
      U32 currentOffset;
      IoIntf_SeekAndRead seekAndReadFp;
      ResIntfPtr fp;
} IoIntfCspReader;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void IoIntfCspReader_constructor(IoIntfCspReader* o,
                                        IoIntf* io,
                                        const char* pathName);
BA_API int IoIntfCspReader_close(IoIntfCspReader* o);
#define IoIntfCspReader_destructor(o) IoIntfCspReader_close(o);
#ifdef __cplusplus
}
inline IoIntfCspReader::IoIntfCspReader(IoIntf* io, const char* pathName) {
   IoIntfCspReader_constructor(this, io, pathName); }
inline IoIntfCspReader::~IoIntfCspReader() {
   IoIntfCspReader_destructor(this); }
inline int IoIntfCspReader::close() {
   return IoIntfCspReader_close(this); }
#endif


#endif

#ifndef __IoIntfZipReader_h
#define __IoIntfZipReader_h

typedef struct IoIntfZipReader
#ifdef __cplusplus
: public ZipReader
{
      IoIntfZipReader() {}

   
   IoIntfZipReader(IoIntf* io, const char* pathName);
      
   
   ~IoIntfZipReader();

   
    int close();

   
   int getECode();

   private:
#else
{
   ZipReader reader;
#endif
      U32 currentOffset;
      IoIntf_SeekAndRead seekAndReadFp;
      ResIntfPtr fp;
      int lastECode;
} IoIntfZipReader;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void IoIntfZipReader_constructor(IoIntfZipReader* o,
                                        IoIntf* io,
                                        const char* pathName);
BA_API int IoIntfZipReader_close(IoIntfZipReader* o);
#define IoIntfZipReader_destructor(o) IoIntfZipReader_close(o);
#define IoIntfZipReader_getECode(o) (o)->lastECode
#ifdef __cplusplus
}
inline IoIntfZipReader::IoIntfZipReader(IoIntf* io, const char* pathName) {
   IoIntfZipReader_constructor(this, io, pathName); }
inline IoIntfZipReader::~IoIntfZipReader() {
   IoIntfZipReader_destructor(this); }
inline int IoIntfZipReader::close() {
   return IoIntfZipReader_close(this); }

inline int IoIntfZipReader::getECode() {
   return IoIntfZipReader_getECode(this); }
#endif


#endif

#ifndef __HttpSharkSslServCon_h
#define __HttpSharkSslServCon_h

typedef struct HttpSharkSslServCon
{
#ifdef __cplusplus

      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }

      // Default constructor is used as a dummy op with the C constructors
      HttpSharkSslServCon() {}
      
      
      HttpSharkSslServCon(SharkSsl* sharkSsl,
                          HttpServer* server,
                          SoDisp* dispatcher,
                          U16 port=443,
                          bool setIP6=false,
                          const void* interfaceName=0,
                          HttpServCon_AcceptNewCon userDefinedAccept=0);
      BaBool isValid();

      
      int setPort(U16 portNumber, bool setIp6=false,
                  const void* interfaceName=0);
      ~HttpSharkSslServCon();
   private:
#endif
      HttpServCon sCon;
      DoubleList sharkSslConList;
      SharkSsl* sharkSsl;
      BaBool requestClientCert;
} HttpSharkSslServCon;


#ifdef __cplusplus
extern "C" {
#endif
SHARKSSL_API void HttpSharkSslServCon_constructor(
   HttpSharkSslServCon* o,
   SharkSsl* sharkSsl,
   struct HttpServer* server,
   struct SoDisp* dispatcher,
   U16 port,
   BaBool setIP6,
   const void* interfaceName,
   HttpServCon_AcceptNewCon userDefinedAccept);
SHARKSSL_API int HttpServCon_setPort(HttpServCon* o, U16 portNumber,
                               BaBool setIp6, const void* interfaceName);
SHARKSSL_API int HttpSharkSslServCon_setPort(HttpSharkSslServCon* o,
                                             U16 portNumber,
                                             BaBool setIp6,
                                             const void* interfaceName);
#define HttpSharkSslServCon_isValid(o) HttpServCon_isValid((HttpServCon*)o)
#define HttpSharkSslServCon_requestClientCert(o,enable) (o)->requestClientCert=enable

SHARKSSL_API void HttpSharkSslServCon_destructor(HttpSharkSslServCon* o);

int HttpSharkSslServCon_bindExec(
   SoDispCon* con, SharkSsl* ssl, const char* host, int port);

#ifdef __cplusplus
}
inline HttpSharkSslServCon::HttpSharkSslServCon(
   SharkSsl* sharkSsl,
   HttpServer* server,
   SoDisp* dispatcher,
   U16 port,
   bool setIP6,
   const void* interfaceName,
   HttpServCon_AcceptNewCon userDefinedAccept) {
   HttpSharkSslServCon_constructor(
      this,sharkSsl,server,dispatcher,
      port,setIP6?TRUE:FALSE,
      interfaceName,userDefinedAccept); }
inline BaBool HttpSharkSslServCon::isValid() {
   return HttpServCon_isValid(this); }
inline int HttpSharkSslServCon::setPort(
   U16 portNumber,bool setIp6,const void* interfaceName) {
   return HttpSharkSslServCon_setPort(
      this,portNumber,setIp6?TRUE:FALSE,interfaceName);
}

inline HttpSharkSslServCon::~HttpSharkSslServCon() {
   HttpSharkSslServCon_destructor(this);}
#endif

#endif

 
#ifndef __VirDir_h
#define __VirDir_h 

struct VirFileNode;

typedef struct VirDirNode
{
      struct VirDirNode* next;
      struct VirDirNode* subDir;
      struct VirFileNode* firstFile;
      char name[1];
} VirDirNode;


typedef struct VirFileNode
{
      struct VirFileNode* next;
      const char* name;
} VirFileNode;


typedef enum { VirDir_NotFound=0, VirDir_IsDir, VirDir_IsFile } VirDir_Type;
typedef void (*VirFileNode_Free)(VirFileNode* o, AllocatorIntf* alloc);
void VirFileNode_constructor(VirFileNode* o, const char* name);
void VirDirNode_constructor(VirDirNode* o, const char* name, size_t len);
VirDir_Type VirDirNode_find(VirDirNode* o, const char* relPath, void** retVal);
VirDirNode* VirDirNode_findSubDir(VirDirNode* o, const char* name, size_t len);
VirFileNode* VirDirNode_findFile(VirDirNode* o, const char* name);
VirDirNode* VirDirNode_makeDir(VirDirNode* o, const char* pathName,
                               AllocatorIntf* alloc);
int VirDirNode_mkDirInsertFile(VirDirNode* o, const char* pathName,
                               VirFileNode* vfn, AllocatorIntf* alloc);

void VirDirNode_free(
   VirDirNode* o,AllocatorIntf* alloc,VirFileNode_Free freeNode);

#endif

#ifndef _SharkSslSCMgr_h
#define _SharkSslSCMgr_h

#ifndef SHARKSSL_API
#define SHARKSSL_API
#else  
#define SHARKSSL_BA 1
#endif 





typedef struct
{
   SplayTreeNode super;
   DoubleLink dlink;
   SharkSslSession* ss;
   const char* host;
   int port;
} SharkSslSCMgrNode;




typedef struct
{
   SharkSslIntf super;
   SplayTree stree;
   DoubleList dlist;
   SharkSsl* ssl;
   U32 maxTime;
   int noOfSessions;
} SharkSslSCMgr;


#ifdef __cplusplus
extern "C" {
#endif


SHARKSSL_API void SharkSslSCMgr_constructor(
   SharkSslSCMgr* o, SharkSsl* ssl, U32 maxTime);


SHARKSSL_API SharkSslSCMgrNode* SharkSslSCMgr_get(
   SharkSslSCMgr* o,SharkSslCon* scon,const char* host,U16 port);


SHARKSSL_API void SharkSslSCMgr_save(
   SharkSslSCMgr* o, SharkSslCon* scon,
   const char* host, U16 port,  SharkSslSCMgrNode* n);

#ifdef __cplusplus
}
#endif

  

#endif


#ifndef __ZipIo_h
#define __ZipIo_h 

typedef struct ZipIo
#ifdef __cplusplus
: public IoIntf
{
      ZipIo() {}
      void *operator new(size_t s) { return ::baMalloc(s); }
      void operator delete(void* d) { if(d) ::baFree(d); }
      void *operator new(size_t, void *place) { return place; }
      void operator delete(void*, void *) { }


      ZipIo(ZipReader* reader,size_t size=256,AllocatorIntf* alloc=0);


      ~ZipIo();


      ZipErr getECode();
#if 0
}
#endif
#else
{
      IoIntf super; 
#endif
      VirDirNode root;
      ZipContainer zc;
      AllocatorIntf* alloc;
      char* password;
      U16   passwordLen;
      ZipErr ecode;
      BaBool passwordRequired;
      BaBool passwordBin;
} ZipIo;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void ZipIo_constructor(
   ZipIo* o,
   ZipReader* reader,
   size_t size,
   AllocatorIntf* alloc);
BA_API void ZipIo_destructor(ZipIo* o);
#define ZipIo_getECode(o) (o)->ecode
#ifdef __cplusplus
}
inline ZipIo::ZipIo(ZipReader* reader,size_t size,AllocatorIntf* alloc) {
   ZipIo_constructor(this,reader,size,alloc);
}
inline ZipIo::~ZipIo() {
   ZipIo_destructor(this);
}
inline ZipErr ZipIo::getECode() {
   return ZipIo_getECode(this);
}
#endif

  

#endif

#ifndef _DeadProp_h
#define _DeadProp_h







#ifndef __SimpleXml_h
#define __SimpleXml_h

struct SXmlRoot;


typedef struct
{
   jmp_buf buf;
} SlException;

#define SlException_INIT(ex) setjmp(ex.buf)
void SlException_set(SlException* o, int err);
#define SlException_assert(o, expr) \
  if( !(expr) ) SlException_set(o, 1)
#define SlException_assertE(o, expr, errCode) \
  if( !(expr) ) SlException_set(o, errCode)

typedef enum
{
   SXmlErrT_OK,
   SXmlErrT_EOF,
   SXmlErrT_Lex,
   SXmlErrT_ExpectedEndElem,
   SXmlErrT_NameNotFound,
   SXmlErrT_NsNotFound,
   SXmlErrT_ExpectedElement,
   SXmlErrT_Mem,
   SXmlErrT_Err
} SXmlErrT;



typedef struct
{
      U16 ns;   
      U16 name; 
      U16 data; 
      U16 next; 
      U16 childNodes; 
      U16 firstChild; 
      U16 attributes[1]; 
} SXmlNode;


#define SXmlNode_getNs(o, r) (o->ns?SXmlRoot_dOffs2Str(r,o->ns):"")
#define SXmlNode_getNsId(o) ((unsigned int)o->ns)
#define SXmlNode_childNodes(o) ((unsigned int)o->childNodes)
#define SXmlNode_getName(o, r) SXmlRoot_dOffs2Str(r,o->name)
#define SXmlNode_getData(o, r) (o->data?SXmlRoot_dOffs2Str(r,o->data):0)
#define SXmlNode_getNoOfAttr(o) ((unsigned int)o->attributes[0])
#define SXmlNode_getAttr(o) (o->attributes[0]?o->attributes+1:0)
#define SXmlNode_next(o, r) (o->next?SXmlRoot_eOffs2Elem(r,o->next):0)
#define SXmlNode_firstChild(o, r) \
   (o->firstChild?SXmlRoot_eOffs2Elem(r,o->firstChild):0)
void SXmlNode_unlinkChild(SXmlNode* o, SXmlNode* child, struct SXmlRoot* r);

typedef U16* SXmlAttr;
#define SXmlAttr_getNs(o, r, n) (o[3*n]?SXmlRoot_dOffs2Str(r,o[3*n]):"")
#define SXmlAttr_getNsId(o, n) o[3*n]
#define SXmlAttr_getName(o, r, n) SXmlRoot_dOffs2Str(r,o[1+(3*n)])
#define SXmlAttr_getValue(o, r, n) SXmlRoot_dOffs2Str(r,o[2+(3*n)])


typedef struct
{
      U16 ns;   
      U16 next; 
} SXmlNsNode;

#define SXmlNsNode_getNs(o, r) SXmlRoot_dOffs2Str(r,o->ns)
#define SXmlNsNode_getNsId(o) ((unsigned int)o->ns)
#define SXmlNsNode_next(o, r) (o->next?SXmlRoot_eOffs2SXmlNsNode(r, o->next):0)


typedef struct SXmlRoot
{
      AllocatorIntf* alloc;
      SlException* ex;
      U8* xmlElemBuf; 
      int line;
      U8* xmlData;
      U16 xmlElemBufSize;
      U16 xmlElemBufNextPos; 
      U16 dataSize;
      U16 parserPos;
      U16 endTagPos;
      U16 xmlnsPos; 
      U16 xmlnsFreeList; 
      U16 xmlnsNodePos; 
      U16 csl; 
} SXmlRoot;

void SXmlRoot_constructor(SXmlRoot* o, AllocatorIntf* alloc);

void SXmlRoot_constructor2(SXmlRoot* o, AllocatorIntf* alloc,
                          U8* xmlData, U16 dataSize, U16 elemBufStartSize,
                          SlException* ex);


void SXmlRoot_destructor(SXmlRoot* o);
int SXmlRoot_parse(
   SXmlRoot* o, U8* xmlData, U16 dataSize, U16 elemBufStartSize);
U16 SXmlRoot_childNodes(SXmlRoot* o);
SXmlNode* SXmlRoot_firstChild(SXmlRoot* o);
SXmlNsNode* SXmlRoot_firstNsNode(SXmlRoot* o);



#define SXmlRoot_eOffs2Xmlns(o, offs) ((Xmlns*)((o)->xmlElemBuf+offs))
#define SXmlRoot_eOffs2SXmlNsNode(o, offs) ((SXmlNsNode*)((o)->xmlElemBuf+offs))
#define SXmlRoot_eOffs2Elem(o, offs) ((SXmlNode*)((o)->xmlElemBuf+offs))
#define SXmlRoot_ePtr2Offs(o, ptr) (U16)(((U8*)ptr) - (o)->xmlElemBuf)



#define SXmlRoot_dOffs2Str(o, offs) ((char*)((o)->xmlData+offs))


struct SerializeSXml;

typedef struct
{
      SplayTree super;
      SingleList nsTreeNodeList;
      AllocatorIntf* alloc;
      SlException* ex;
      unsigned int nextNsId;
} NsTree;

void NsTree_addNs(NsTree* o, SXmlNode* n, SXmlRoot* r);
void NsTree_addAllNs(NsTree* o, SXmlNode* n, SXmlRoot* r);
unsigned int NsTree_getNsId(NsTree* o, const char* ns);
void NsTree_printNsAttrList(NsTree* o, const char nsprfx, BufPrint* out);
struct SerializeSXml* NsTree_createSerializer(
   NsTree* o, const char nsprfx, BufPrint* bp);
void NsTree_constructor(NsTree* o, AllocatorIntf* alloc, SlException* ex);
void NsTree_destructor(NsTree* o);

typedef struct SerializeSXml
{
      BufPrint* bp;
      NsTree* nst;
      char nsprfx;
      BaBool printNsAttrList;
} SerializeSXml;

void SerializeSXml_printNode(
   SerializeSXml* o,SXmlNode* n,SXmlRoot* r, BaBool all);
#define SerializeSXml_constructor(o,nsprfx,bp) \
  SerializeSXml_constructor2(o,nsprfx,bp,0)
void SerializeSXml_constructor2(
   SerializeSXml* o, const char nsprfx, BufPrint* bp, NsTree* nst);
#define SerializeSXml_printNsAttrList(o) (o)->printNsAttrList=TRUE

#endif
typedef struct DeadProp
{
      SXmlRoot op;
      SXmlRoot* nr;
      U8* xmlRootBuf;
      SXmlNode* oprop;
      SXmlNode** nprops;
      SXmlNode* oPropIter; 
      IoIntf* io;
      AllocatorIntf* alloc;
      char* propFileName;
      U16 npropsCursor;
      U16 npropsLen;
      BaBool noPropFile;
      BaBool elemRemoved;
} DeadProp;


void DeadProp_constructor(DeadProp* o, IoIntf* io, AllocatorIntf* alloc);
char* DeadProp_fname2PropFName(AllocatorIntf* alloc, const char* filename);
int DeadProp_mkPropDir(IoIntf* io, char* propFileName);
U8* DeadProp_readFile(IoIntf* io, AllocatorIntf* alloc,
                      const char* name, size_t* size);
int DeadProp_setFile(DeadProp* o, char* propFileName);
int DeadProp_save(DeadProp* o);
SXmlNode* DeadProp_getProp(DeadProp* o, const char* ns, const char* name);
int DeadProp_setProp(DeadProp* o, SXmlNode* nn, SXmlRoot* nr);
int DeadProp_removeProp(DeadProp* o, SXmlNode* nn, SXmlRoot* nr);
SXmlNode* DeadProp_getFirstProp(DeadProp* o);
SXmlNode* DeadProp_getNextProp(DeadProp* o);
void DeadProp_destructor(DeadProp* o);
#define DeadProp_getRoot(o) (&(o)->op)

#endif



#ifndef __EventHndl_h
#define __EventHndl_h

#ifndef __DOXYGEN__
struct EhConListener;
struct EhConListener;
struct EventHandler;
struct PushConNode;
struct PushConPage;
struct EhDir;
struct JsPushConPageFmt;
struct EhInterface;
#endif





typedef enum  {
   EhMutexT_Default,
   EhMutexT_Mutex,
   EhMutexT_Con
} EhMutexT;






typedef U16 EhType;
#define EhType_Byte   0x0000
#define EhType_String 0x1000

#define EhType_Int    0x4000
#define EhType_Long   0x5000
#define EhType_Double 0x6000


#define EhType_isArray(type)   ((0x8000 & type) != 0)

#define EhType_getType(type)     (0x7000 & type)
#define EhType_isByte(type)     ((0x7000 & type) == EhType_Byte)
#define EhType_isString(type)   ((0x7000 & type) == EhType_String)
#define EhType_isInt(type)     ((0x7000 & type) == EhType_Int)
#define EhType_isLong(type)     ((0x7000 & type) == EhType_Long)
#define EhType_isDouble(type)  ((0x7000 & type) == EhType_Double)

#define EhType_isNumber(type)  ((0x4000 & type) != 0)

#define EhType_getLen(type) (0x0FFF & type)
  
#ifdef __cplusplus
extern "C" { 
#endif
BA_API S32 EhType_needInt(EhType t, void* arg);
BA_API S32* EhType_needIntA(EhType t, void* arg);
BA_API U64 EhType_needLong(EhType t, void* arg);
BA_API U64* EhType_needLongA(EhType t, void* arg);
#ifndef NO_DOUBLE
BA_API double EhType_needDouble(EhType t, void* arg);
BA_API double* EhType_needDoubleA(EhType t, void* arg);
#endif
#ifdef __cplusplus
}
#endif





typedef enum
{
   EhErrorMsgT_MaxClients=0,
   EhErrorMsgT_InterfaceNotFound,
   EhErrorMsgT_MethodNotFound,
   EhErrorMsgT_InvalidParameters,
   EhErrorMsgT_InvalidData,
   EhErrorMsgT_NoDouble,
   EhErrorMsgT_ArrayTooLong,
   EhErrorMsgT_Malloc,
   EhErrorMsgT_BufferIsTooSmall,
   EhErrorMsgT_UnknownCID,
   EhErrorMsgT_UserError,
   EhErrorMsgT_NoError 
}EhErrorMsgT;




typedef EhErrorMsgT (*EventHandler_AsynchRecCB)(
   void* o,
   const char* intf,
   const char* method,
   U32 cid,
   int noOfArgs,
   EhType argTypes[],
   void* args[]);

#define EventHandler_setAsynchRecCB(eh, asynchRecCBObj, asynchRecCB) \
  (eh)->asynchRec=asynchRecCB,(eh)->asynchRecObj=asynchRecCBObj

typedef struct
{
      EhType type;
      int len;
      union
      {
            S32 i;
            S32* ia;
            U64 l;
            U64* la;
            const char* s;
            const char** sa;
            void* b;
#ifndef NO_DOUBLE
            double d;
            double* da;
#endif
      } arg;
} ZzEhSend;





#ifndef __DOXYGEN__
typedef struct EhDecodeBuf
{
      AllocatorIntf* alloc;
      union EhTypeContainer* ehTypeCont;
      void** args;
      EhType* argsType;
      int noOfArgs;
} EhDecodeBuf;
#endif
 




typedef void (*PushConPage_PrePostFmt)(
   struct PushConPage* page, struct JsPushConPageFmt* enc, BaBool isPreFmt);


#ifndef __DOXYGEN__
typedef struct PushConPage
{
      PushConPage_PrePostFmt prePostFmt;
} PushConPage;
#endif






typedef int (*PushConNode_Send)(
   struct PushConNode* con, const void* data, int len);


#ifndef __DOXYGEN__
typedef struct PushConNode 
{
      HttpConnection super; 

      
      DoubleLink conLink;

      
      SplayTreeNode stn;

      struct EventHandler* eh;
      PushConNode_Send sendData;
      PushConPage* pushConPage;
      ThreadMutex* mx;
      U32 sessionID; 
      U8 mxT; 
      U8 pushConNodeT;
      U8 recycling;
} PushConNode;
#endif
 




typedef int (*EhConListener_New)(struct EhConListener* o,
                                 struct EventHandler* eh,
                                 U32 cid);

typedef void (*EhConListener_Terminate)(struct EhConListener* o,
                                        struct EventHandler* eh,
                                        U32 cid);


typedef struct EhConListener
{
#ifdef __cplusplus
       
      EhConListener(EhConListener_New newCon, EhConListener_Terminate termCon);
   private:
#endif
      SingleLink link; 
      EhConListener_New newCon;
      EhConListener_Terminate termCon;
} EhConListener;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void EhConListener_constructor(
   EhConListener* o,EhConListener_New newCon,EhConListener_Terminate termCon);
#ifdef __cplusplus
}
inline EhConListener::EhConListener(
   EhConListener_New newCon, EhConListener_Terminate termCon) {
   EhConListener_constructor(this, newCon, termCon); }
#endif



typedef int (*EhMethod_MethodCB)(
   struct EhInterface* o,
   U32 cid,
   int noOfArgs,
   EhType argsType[],
   void* args[]);


     
typedef struct EhMethod
{
        const char* methodName;
      EhMethod_MethodCB method;
} EhMethod;



typedef struct EhInterface
{
#ifdef __cplusplus
      
      EhInterface(EventHandler* eh,const char* name,
                  const EhMethod* methods,int methodsSize);

      
      ~EhInterface();
#endif
      SplayTreeNode super; 
      struct EventHandler* eh;
      const EhMethod* methods;
      int methodsSize;
} EhInterface;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void EhInterface_constructor(
   EhInterface* o,struct EventHandler* eh,const char* name,
   const EhMethod* methods,int methodsSize);
BA_API void EhInterface_destructor(EhInterface* o);
#ifdef __cplusplus
}
inline EhInterface::EhInterface(EventHandler* eh,const char* name,
                                const EhMethod* methods,int methodsSize) {
   EhInterface_constructor(this,eh,name, methods, methodsSize);
}
inline EhInterface::~EhInterface() {
   EhInterface_destructor(this);
}
#endif



#ifndef __DOXYGEN__
typedef struct EhConListenerList
{
      SingleList list;
} EhConListenerList;
#endif

  
typedef struct EventHandlerConfig
{
#ifdef __cplusplus
      
      EventHandlerConfig();

      
      void setConAllocator(AllocatorIntf* conAlloc);

      
      void setRespBufAllocator(
         int startSize, int expandSize, AllocatorIntf* respBufAlloc);

      
      void setDecodeAllocator(AllocatorIntf* decodeAlloc);

      
      void setMutex(ThreadMutex* mutex);

      
      void setMutexState(EhMutexT mxT);

   private:
#endif
      ThreadMutex* mutex;
      EhMutexT mxT;
      AllocatorIntf* conAlloc; 
      AllocatorIntf* respBufAlloc;
      int respBufAllocStartSize;
      int respBufAllocExpandSize;
      AllocatorIntf* decodeAlloc;
} EventHandlerConfig;

#ifdef __cplusplus
extern "C" {
#endif
BA_API void EventHandlerConfig_constructor(EventHandlerConfig* o);
#define EventHandlerConfig_setConAllocator(o, allocator) \
   (o)->conAlloc = allocator;
#define EventHandlerConfig_setRespBufAllocator(\
   o, startSize, expandSize, allocator) do {\
   (o)->respBufAllocStartSize=startSize;\
      (o)->respBufAllocExpandSize=expandSize;\
   (o)->respBufAlloc = allocator;\
}while(0)
#define EventHandlerConfig_setDecodeAllocator(o, allocator) \
   (o)->decodeAlloc = allocator
BA_API void EventHandlerConfig_setMutex(
   EventHandlerConfig* o, ThreadMutex* mutex);
BA_API void EventHandlerConfig_setMutexState(
   EventHandlerConfig* o, EhMutexT mxT);
#ifdef __cplusplus
}
inline EventHandlerConfig::EventHandlerConfig() {
   EventHandlerConfig_constructor(this);
}
inline void EventHandlerConfig::setConAllocator(AllocatorIntf* conAlloc) {
   EventHandlerConfig_setConAllocator(this, conAlloc);
}
inline void EventHandlerConfig::setRespBufAllocator(
   int startSize, int expandSize, AllocatorIntf* respBufAlloc) {
   EventHandlerConfig_setRespBufAllocator(
      this, startSize, expandSize, respBufAlloc);
}
inline void EventHandlerConfig::setDecodeAllocator(
   AllocatorIntf* decodeAlloc) {
   EventHandlerConfig_setDecodeAllocator(this, decodeAlloc);
}
inline void EventHandlerConfig::setMutex(ThreadMutex* mutex) {
   EventHandlerConfig_setMutex(this, mutex);
}
inline void EventHandlerConfig::setMutexState(EhMutexT mxT) {
   EventHandlerConfig_setMutexState(this, mxT);
}
#endif




typedef int _EhSendDataFmtCB(void* o, ZzEhSend*);

typedef struct
{
      union
      {
            struct 
            {
                  const char* fmt;
                  va_list varg1;
                  va_list varg2;
            } vaT;
            struct  
            {
                  void* fmtData;
                  _EhSendDataFmtCB* fmtCB;
            } arT;
      } u;
      BaBool isVaT;
} _EhSendData;


 
typedef struct EventHandler
{
#ifdef __cplusplus
      
      void addConListener(EhConListener* cl);

      
      HttpConnection* getCon(U32 cid);

      
      HttpServer* getServer();

      
      HttpSession* getSession(U32 cid);

      
      AuthenticatedUser* getUser(U32 cid);


      
      int sendData(U32 cid, const char* intf, const char* method,
                   const char* fmt, ...);

      
      int sendData2All(const char* intf, const char* method,
                       const char* fmt,...);

      
      void sendErrMsg(U32 cid, const char* msg);
   
       
      void setTCPNoDelay(bool enable);

      
      ThreadMutex* getMutex();

      
      void mutexSet();

      
      void mutexRelease();

   private:
#endif
       
      DoubleList schedTermList;
      DoubleList binConList;
      DoubleList iframeConList;
      DoubleList webSocketConList;
      SplayTree pushConTree;
      SplayTree ehIntfTree;
      EhConListenerList conListenerList;
      HttpServer* server;
      struct EhDir* ehDir;
      AllocatorIntf* conAlloc; 
      AllocatorIntf* respBufAlloc;
      int respBufAllocStartSize;
      int respBufAllocExpandSize;
      ThreadMutex* mutex;
      EventHandler_AsynchRecCB asynchRec;
      void* asynchRecObj;
      BaBool tcpNoDelay;
      U8 mxT; 
} EventHandler;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void EventHandler_addConListener(EventHandler* o, EhConListener* cl);
BA_API HttpSession* EventHandler_getSession(EventHandler* o, U32 cid);
BA_API HttpConnection* EventHandler_getCon(EventHandler*o, U32 cid);
#define EventHandler_getServer(o) (o)->server
#define EventHandler_getUser(o, cid) \
   AuthenticatedUser_get2(EventHandler_getSession(o, cid))
BA_API void EventHandler_sendErrMsg(EventHandler*o, U32 cid, const char* msg);
BA_API void EventHandler_setTCPNoDelay(EventHandler* o, int enable);
BA_API int EventHandler_sendData2All(
   EventHandler* o, const char*intf, const char* method, const char* fmt, ...);
BA_API int EventHandler_zzsendData2All(
   EventHandler* o, const char*intf, const char* method, _EhSendData* d);
BA_API int EventHandler_sendData(
   EventHandler* o, U32 cid, const char*intf, const char* method,
   const char* fmt, ...);
BA_API int EventHandler_zzsendData(
   EventHandler* o, U32 cid, const char* intf, const char* method,
   _EhSendData* d);

#define EventHandler_getMutex(o) HttpServer_getMutex((o)->server)
#define EventHandler_mutexSet(o) \
   ThreadMutex_set(HttpServer_getMutex((o)->server))
BA_API void EventHandler_mutexRelease(EventHandler* o);
#ifdef NO_DOUBLE
#define EventHandler_intA2Dbl ERROR_compiling_with_NODOUBLE
#define EventHandler_dblA2Int ERROR_compiling_with_NODOUBLE
#else
BA_API double* EventHandler_intA2Dbl(int len, S32* array);
BA_API S32* EventHandler_dblA2Int(int len, double* array);
#endif
#ifdef __cplusplus
}
inline void EventHandler::addConListener(EhConListener* cl) {
   EventHandler_addConListener(this,cl);
}
inline HttpConnection* EventHandler::getCon(U32 cid) {
   return EventHandler_getCon(this, cid);
}
inline HttpServer* EventHandler::getServer() {
   return EventHandler_getServer(this);
}
inline HttpSession* EventHandler::getSession(U32 cid) {
   return EventHandler_getSession(this,cid);
}
inline AuthenticatedUser* EventHandler::getUser(U32 cid) {
   return EventHandler_getUser(this,cid);
}
inline void EventHandler::sendErrMsg(U32 cid, const char* msg) {
   EventHandler_sendErrMsg(this,cid, msg);
}

inline void EventHandler::setTCPNoDelay(bool enable) {
   EventHandler_setTCPNoDelay(this, enable?TRUE:FALSE);
}

inline int EventHandler::sendData2All(const char* i, const char* m,
                                      const char* f, ...) {
   int retv;
   _EhSendData d;
   d.u.vaT.fmt=f;
   va_start(d.u.vaT.varg1, f);  
   va_start(d.u.vaT.varg2, f);
   d.isVaT=TRUE;
   retv = EventHandler_zzsendData2All(this,i,m,&d);
   va_end(d.u.vaT.varg1);
   va_end(d.u.vaT.varg2);
   return retv;
}
inline int EventHandler::sendData(U32 cid, const char* i, const char* m,
                                      const char* f, ...) {
   int retv;
   _EhSendData d;
   d.u.vaT.fmt=f;
   va_start(d.u.vaT.varg1, f);  
   d.isVaT=TRUE;
   retv = EventHandler_zzsendData(this,cid,i,m,&d);
   va_end(d.u.vaT.varg1);
   return retv;
}
 
inline ThreadMutex* EventHandler::getMutex() {
   return EventHandler_getMutex(this);
}
inline void EventHandler::mutexSet() {
   EventHandler_mutexSet(this);
}
inline void EventHandler::mutexRelease() {
   EventHandler_mutexRelease(this);
}
#endif


#ifdef __cplusplus

struct LockEventHandler
{
      
      LockEventHandler(EventHandler* eh) : _eh(eh) { eh->mutexSet(); }
      
      ~LockEventHandler() { _eh->mutexRelease(); }
   private:
      EventHandler* _eh;
};
#endif


#ifndef __DOXYGEN__
typedef struct IframePage
{
      PushConPage super;
      EventHandler* eh;
      U16 startCursor;
} IframePage;

typedef struct WebSocket
{
      PushConPage super;
      EventHandler* eh;
}WebSocket;


typedef struct CommandPage
{
      AllocatorIntf* alloc;
      EventHandler* eh;
}CommandPage;
#endif

 
typedef struct EhDir
#ifdef __cplusplus
   : public HttpDir
{
      
      EhDir(const char* dirName,HttpServer* server,EventHandlerConfig* cfg=0);

      
      EventHandler* getEventHandler();
   private:
#else
{
      HttpDir dir; 
#endif
      EventHandler eh;
      IframePage iframePage;
      WebSocket webSocket;
      CommandPage commandPage;
      HttpDir_Service orgServiceFunc;
} EhDir;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void EhDir_constructor(EhDir* o,
                       const char* dirName,
                       HttpServer* server,
                       EventHandlerConfig* cfg);
BA_API void EhDir_destructor(EhDir* o);
#define EhDir_getEventHandler(o) (&(o)->eh)
#ifdef __cplusplus
}
inline EhDir::EhDir(
   const char* dirName,HttpServer* server,EventHandlerConfig* cfg) {
   EhDir_constructor(this,dirName,server,cfg);
}
inline EventHandler* EhDir::getEventHandler() {
   return  EhDir_getEventHandler(this);
}

#endif

 
 
#endif



#ifndef __HttpServerPipe_h
#define __HttpServerPipe_h

typedef struct HttpServerPipe
#ifdef __cplusplus
:public SoDispCon
{
      
      static bool isHttpPipeReq(HttpRequest* request);

      
      HttpServerPipe(SoDisp* dispatcher,
                     SoDispCon_DispRecEv onRecEvent);

      
      int start(HttpRequest* request);

      
      ~HttpServerPipe();

      
      bool hasMoreData();

      
      int readData(void* data, int len);

      
      int sendData(void* data, int len);
#if 0
} //For emacs
#endif
#else
{
   SoDispCon super; 
#endif
} HttpServerPipe;

#ifdef __cplusplus
extern "C" {
#endif
BA_API BaBool HttpServerPipe_isHttpPipeReq(HttpRequest* request);
BA_API void HttpServerPipe_constructor(HttpServerPipe* o,
                                       SoDisp* dispatcher,
                                       SoDispCon_DispRecEv onRecEvent);
BA_API int HttpServerPipe_start(HttpServerPipe* o, HttpRequest* request);
BA_API void HttpServerPipe_destructor(HttpServerPipe* o);
#define HttpServerPipe_hasMoreData(o) \
   SoDispCon_hasMoreData((SoDispCon*)(o))
BA_API int HttpServerPipe_readData(HttpServerPipe* o, void* data, int len);
#define HttpServerPipe_sendData( o, data, len) \
   SoDispCon_sendData((SoDispCon*)(o), data, len)
#ifdef __cplusplus
}

inline bool HttpServerPipe::isHttpPipeReq(HttpRequest* request) {
   return HttpServerPipe_isHttpPipeReq(request) ? true : false;
}
inline HttpServerPipe::HttpServerPipe(SoDisp* dispatcher,
                                      SoDispCon_DispRecEv onRecEvent) {
   HttpServerPipe_constructor(this,dispatcher,onRecEvent);
}
inline int HttpServerPipe::start(HttpRequest* request) {
   return HttpServerPipe_start(this, request);
}
inline HttpServerPipe::~HttpServerPipe() {
   HttpServerPipe_destructor(this);
}
inline bool HttpServerPipe::hasMoreData() {
   return HttpServerPipe_hasMoreData(this);
}
inline int HttpServerPipe::readData(void* data, int len) {
   return HttpServerPipe_readData(this, data, len);
}
inline int HttpServerPipe::sendData(void* data, int len) {
   return HttpServerPipe_sendData(this, data, len);
}
#endif

 


#endif

#ifndef _SharkSslCon_h
#define _SharkSslCon_h

#define SHARKSSL_LIB 1
#if (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_SSL_CLIENT_CODE)

#define            SharkSsl_isServer(o) (o->role == SharkSsl_Server)
#define            SharkSsl_isClient(o) (o->role == SharkSsl_Client)

#elif SHARKSSL_SSL_SERVER_CODE

#define            SharkSsl_isServer(o) (1)
#define            SharkSsl_isClient(o) (0)

#elif SHARKSSL_SSL_CLIENT_CODE

#define            SharkSsl_isServer(o) (0)
#define            SharkSsl_isClient(o) (1)

#elif ((!SHARKSSL_ENABLE_RSA_API) && (!SHARKSSL_ENABLE_PEM_API))

#error NEITHER SERVER NOR CLIENT CODE SELECTED
#endif

#define SHARKSSL_CONTENT_TYPE_CHANGE_CIPHER_SPEC   20
#define SHARKSSL_CONTENT_TYPE_ALERT                21
#define SHARKSSL_CONTENT_TYPE_HANDSHAKE            22
#define SHARKSSL_CONTENT_TYPE_APPLICATION_DATA     23

#define SHARKSSL_HANDSHAKETYPE_HELLO_REQUEST       0
#define SHARKSSL_HANDSHAKETYPE_CLIENT_HELLO        1
#define SHARKSSL_HANDSHAKETYPE_SERVER_HELLO        2
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE         11
#define SHARKSSL_HANDSHAKETYPE_SERVER_KEY_EXCHANGE 12
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE_REQUEST 13
#define SHARKSSL_HANDSHAKETYPE_SERVER_HELLO_DONE   14
#define SHARKSSL_HANDSHAKETYPE_CERTIFICATE_VERIFY  15
#define SHARKSSL_HANDSHAKETYPE_CLIENT_KEY_EXCHANGE 16
#define SHARKSSL_HANDSHAKETYPE_FINISHED            20
#define SHARKSSL_HANDSHAKETYPE_COMPLETE            0xFF

#define SHARKSSL_HASHALGORITHM_NONE                0x00
#define SHARKSSL_HASHALGORITHM_MD5                 0x01
#define SHARKSSL_HASHALGORITHM_SHA1                0x02
#define SHARKSSL_HASHALGORITHM_SHA224              0x03
#define SHARKSSL_HASHALGORITHM_SHA256              0x04
#define SHARKSSL_HASHALGORITHM_SHA384              0x05
#define SHARKSSL_HASHALGORITHM_SHA512              0x06
#define SHARKSSL_HASHALGORITHM_TLS_MD5_SHA1        0xEE  

#define SHARKSSL_SIGNATUREALGORITHM_RSA            0x01
#define SHARKSSL_SIGNATUREALGORITHM_DSA            0x02
#define SHARKSSL_SIGNATUREALGORITHM_ECDSA          0x03
#define SHARKSSL_OID_EC_PUBLIC_KEY                 0x0C  

#define SHARKSSL_CLIENTCERTTYPE_RSA                0x01
#define SHARKSSL_CLIENTCERTTYPE_DSA                0x02
#define SHARKSSL_CLIENTCERTTYPE_ECDSA              0x40

#define TLS_EMPTY_RENEGOTIATION_INFO_SCSV          0x00FF

#define TLS_COMPRESSION_METHOD_NULL                0


#define TLS_EXTENSION_SERVER_NAME                  0 
#define TLS_EXTENSION_MAX_FRAGMENT_LENGTH          1
#define TLS_EXTENSION_CLIENT_CERTIFICATE_URL       2
#define TLS_EXTENSION_TRUSTED_CA_KEYS              3
#define TLS_EXTENSION_TRUNCATED_HMAC               4
#define TLS_EXTENSION_STATUS_REQUEST               5
#define TLS_EXTENSION_USER_MAPPPING                6
#define TLS_EXTENSION_CLIENT_AUTHZ                 7
#define TLS_EXTENSION_SERVER_AUTHZ                 8
#define TLS_EXTENSION_CERT_TYPE                    9
#define TLS_EXTENSION_ELLIPTIC_CURVES              10
#define TLS_EXTENSION_EC_POINT_FORMATS             11
#define TLS_EXTENSION_SRP                          12
#define TLS_EXTENSION_SIGNATURE_ALGORITHM          13
#define TLS_EXTENSION_USE_SRTP                     14
#define TLS_EXTENSION_HEARTBEAT                    15
#define TLS_EXTENSION_APPL_LAYER_PROT_NEGOTIATION  16
#define TLS_EXTENSION_STATUS_REQUEST_V2            17
#define TLS_EXTENSION_SIGNED_CERTIFICATE_TIMESTAMP 18
#define TLS_EXTENSION_SESSION_TICKET               35
#define TLS_EXTENSION_RENEGOTIATION_INFO           0xFF01


#define TLS_NAMEDCURVE_SECP192R1                   19
#define TLS_NAMEDCURVE_SECP224R1                   21
#define TLS_NAMEDCURVE_SECP256R1                   23
#define TLS_NAMEDCURVE_SECP384R1                   24
#define TLS_NAMEDCURVE_SECP521R1                   25



#define TLS_ECPOINTFORMAT_UNCOMPRESSED             0
#define TLS_ECPOINTFORMAT_ANSIX962_COMP_PRIME      1
#define TLS_ECPOINTFORMAT_ANSIX962_COMP_CHAR2      2



#define TLS_ECCURVETYPE_EXPLICIT_PRIME             1
#define TLS_ECCURVETYPE_EXPLICIT_CHAR2             2
#define TLS_ECCURVETYPE_NAMED_CURVE                3



#if (!SHARKSSL_ENABLE_RSA)
#if SHARKSSL_ENABLE_DHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_DHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#endif


#if SHARKSSL_USE_ECC
#if ((!SHARKSSL_ECC_USE_SECP192R1) && (!SHARKSSL_ECC_USE_SECP224R1) && (!SHARKSSL_ECC_USE_SECP256R1) && \
      (!SHARKSSL_ECC_USE_SECP384R1) && (!SHARKSSL_ECC_USE_SECP521R1))
#error no elliptic curve selected
#endif
#else
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDHE_ECDSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDH_ECDSA is enabled
#endif

#if (!SHARKSSL_ENABLE_RSA)
#if SHARKSSL_ENABLE_ECDHE_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDHE_RSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_RSA
#error SHARKSSL_ENABLE_RSA must be selected when SHARKSSL_ENABLE_ECDH_RSA is enabled
#endif
#endif  

#if SHARKSSL_ENABLE_ECDSA
#error SHARKSSL_USE_ECC must be selected when SHARKSSL_ENABLE_ECDSA is enabled
#else
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#error SHARKSSL_ENABLE_ECDSA must be selected when SHARKSSL_ENABLE_ECDHE_ECDSA is enabled
#endif
#if SHARKSSL_ENABLE_ECDH_ECDSA
#error SHARKSSL_ENABLE_ECDSA must be selected when SHARKSSL_ENABLE_ECDH_ECDSA is enabled
#endif
#endif  
#endif  



#if SHARKSSL_USE_NULL_CIPHER
#define SHARKSSL_SSL_RSA_WITH_NULL_SHA             TLS_RSA_WITH_NULL_SHA
#if SHARKSSL_ENABLE_MD5_CIPHERSUITES
#define SHARKSSL_SSL_RSA_WITH_NULL_MD5             TLS_RSA_WITH_NULL_MD5
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_NULL_SHA           TLS_ECDHE_RSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_NULL_SHA            TLS_ECDH_RSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_NULL_SHA         TLS_ECDHE_ECDSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_NULL_SHA          TLS_ECDH_ECDSA_WITH_NULL_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_NULL_SHA256          TLS_RSA_WITH_NULL_SHA256
#endif  
#endif  

#if SHARKSSL_USE_ARC4
#define SHARKSSL_SSL_RSA_WITH_ARC4_128_SHA         TLS_RSA_WITH_RC4_128_SHA
#if SHARKSSL_ENABLE_MD5_CIPHERSUITES
#define SHARKSSL_SSL_RSA_WITH_ARC4_128_MD5         TLS_RSA_WITH_RC4_128_MD5
#endif
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_ARC4_128_SHA       TLS_ECDHE_RSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_ARC4_128_SHA        TLS_ECDH_RSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_ARC4_128_SHA     TLS_ECDHE_ECDSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_ARC4_128_SHA      TLS_ECDH_ECDSA_WITH_RC4_128_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_ARC4_128_SHA             TLS_PSK_WITH_RC4_128_SHA
#endif
#endif

#if SHARKSSL_USE_DES
#define SHARKSSL_SSL_RSA_WITH_DES_CBC_SHA          TLS_RSA_WITH_DES_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_DES_CBC_SHA          TLS_DHE_RSA_WITH_DES_CBC_SHA
#endif
#endif

#if SHARKSSL_USE_3DES
#define SHARKSSL_SSL_RSA_WITH_3DES_EDE_CBC_SHA     TLS_RSA_WITH_3DES_EDE_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA     TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA   TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_3DES_EDE_CBC_SHA    TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA  TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_3DES_EDE_CBC_SHA         TLS_PSK_WITH_3DES_EDE_CBC_SHA
#endif
#endif

#if SHARKSSL_USE_AES_128
#define SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA      TLS_RSA_WITH_AES_128_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA      TLS_DHE_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA     TLS_ECDH_RSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA  TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA   TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_AES_128_CBC_SHA          TLS_PSK_WITH_AES_128_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_AES_128_CBC_SHA256   TLS_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_GCM_SHA256   TLS_RSA_WITH_AES_128_GCM_SHA256
#endif  
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_CCM          TLS_RSA_WITH_AES_128_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_128_CCM_8        TLS_RSA_WITH_AES_128_CCM_8
#endif  
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_128_CBC_SHA256   TLS_DHE_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_GCM_SHA256   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256
#endif  
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_CCM          TLS_DHE_RSA_WITH_AES_128_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_128_CCM_8        TLS_DHE_RSA_WITH_AES_128_CCM_8
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_CBC_SHA256 TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_RSA_WITH_AES_128_GCM_SHA256 TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_128_CBC_SHA256  TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_RSA_WITH_AES_128_GCM_SHA256  TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA256 TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_ECDSA_WITH_AES_128_GCM_SHA256 TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256
#endif  
#endif  
#endif  
#endif  

#if SHARKSSL_USE_AES_256
#define SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA      TLS_RSA_WITH_AES_256_CBC_SHA
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA      TLS_DHE_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA     TLS_ECDH_RSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA  TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA   TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_PSK
#define SHARKSSL_PSK_WITH_AES_256_CBC_SHA          TLS_PSK_WITH_AES_256_CBC_SHA
#endif  
#if SHARKSSL_ENABLE_TLS_1_2
#define SHARKSSL_SSL_RSA_WITH_AES_256_CBC_SHA256   TLS_RSA_WITH_AES_256_CBC_SHA256
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_CCM          TLS_RSA_WITH_AES_256_CCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_CCM_8        TLS_RSA_WITH_AES_256_CCM_8
#endif  
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_CBC_SHA256   TLS_DHE_RSA_WITH_AES_256_CBC_SHA256
#if SHARKSSL_ENABLE_AES_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_256_CCM          TLS_DHE_RSA_WITH_AES_256_CCM
#define SHARKSSL_DHE_RSA_WITH_AES_256_CCM_8        TLS_DHE_RSA_WITH_AES_256_CCM_8
#endif  
#endif  
#if SHARKSSL_USE_SHA_384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_SSL_RSA_WITH_AES_256_GCM_SHA384   TLS_RSA_WITH_AES_256_GCM_SHA384
#if SHARKSSL_ENABLE_DHE_RSA
#define SHARKSSL_DHE_RSA_WITH_AES_256_GCM_SHA384   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_RSA
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_CBC_SHA384 TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_RSA_WITH_AES_256_GCM_SHA384 TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_RSA
#define SHARKSSL_ECDH_RSA_WITH_AES_256_CBC_SHA384  TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_RSA_WITH_AES_256_GCM_SHA384  TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDHE_ECDSA
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#if SHARKSSL_ENABLE_ECDH_ECDSA
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA384 TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384
#if SHARKSSL_ENABLE_AES_GCM
#define SHARKSSL_ECDH_ECDSA_WITH_AES_256_GCM_SHA384 TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384
#endif  
#endif  
#endif  
#endif  
#endif  


#define SHARKSSL_MD5_MAC_LEN                       16
#define SHARKSSL_SHA1_MAC_LEN                      20
#define SHARKSSL_SHA256_MAC_LEN                    32
#define SHARKSSL_SHA384_MAC_LEN                    48
#define SHARKSSL_SHA512_MAC_LEN                    64

#define SHARKSSL_MD5_BLOCK_LEN                     64
#define SHARKSSL_SHA1_BLOCK_LEN                    64
#define SHARKSSL_SHA256_BLOCK_LEN                  64
#define SHARKSSL_SHA384_BLOCK_LEN                  128
#define SHARKSSL_SHA512_BLOCK_LEN                  128

#define SHARKSSL_FINISHED_MSG_LEN_SSL              36   
#define SHARKSSL_FINISHED_MSG_LEN_TLS              12   
#if SHARKSSL_ENABLE_SSL_3_0
#define SHARKSSL_MAX_FINISHED_MSG_LEN              SHARKSSL_FINISHED_MSG_LEN_SSL
#else
#define SHARKSSL_MAX_FINISHED_MSG_LEN              SHARKSSL_FINISHED_MSG_LEN_TLS
#endif

#define SHARKSSL_RECORD_HEADER_SIZE                5    
#define SHARKSSL_HANDSHAKE_HEADER_SIZE             4    
#define SHARKSSL_MAX_SESSION_ID_LEN                32   
#define SHARKSSL_SEQ_NUM_LEN                       8    
#define SHARKSSL_RANDOM_LEN                        32   
#define SHARKSSL_MASTER_SECRET_LEN                 48   


#if SHARKSSL_ENABLE_TLS_1_2
#if   SHARKSSL_USE_SHA_512
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA512_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA512_BLOCK_LEN
#elif SHARKSSL_USE_SHA_384
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA384_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA384_BLOCK_LEN
#else
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA256_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA256_BLOCK_LEN
#endif  
#else
#define SHARKSSL_MAX_DIGEST_LEN                    SHARKSSL_SHA1_MAC_LEN
#define SHARKSSL_MAX_DIGEST_BLOCK_LEN              SHARKSSL_SHA1_BLOCK_LEN
#endif  
#define SHARKSSL_MAX_DIGEST_PAD_LEN                48   
#define SHARKSSL_MAX_REC_LEN                       (16384 + 2048) 
#define SHARKSSL_MAX_REC_PAD_LEN                   SHARKSSL_MAX_BLOCK_LEN

#if   SHARKSSL_USE_AES_256
#define SHARKSSL_MAX_KEY_LEN                       32   
#elif SHARKSSL_USE_3DES
#define SHARKSSL_MAX_KEY_LEN                       24   
#elif (SHARKSSL_USE_AES_128 || SHARKSSL_USE_ARC4)
#define SHARKSSL_MAX_KEY_LEN                       16   
#elif SHARKSSL_USE_DES
#define SHARKSSL_MAX_KEY_LEN                        8   
#elif SHARKSSL_USE_NULL_CIPHER
#define SHARKSSL_MAX_KEY_LEN                        0   
#else
#error At least one cipher must be selected in SharkSSL_cfg.h 
#endif

#if   (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)
#define SHARKSSL_MAX_BLOCK_LEN                     16   
#elif (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)
#define SHARKSSL_MAX_BLOCK_LEN                     8    
#else
#define SHARKSSL_MAX_BLOCK_LEN                     0    
#endif



#ifndef UPTR
#define UPTR                                       U32
#endif
#ifndef SHARKSSL_ALIGNMENT
#define SHARKSSL_ALIGNMENT                         4   
#endif 
#define SHARKSSL_ALIGN_SIZE(s)                     (((s) + (SHARKSSL_ALIGNMENT - 1)) & ((U32)-SHARKSSL_ALIGNMENT))
#define SHARKSSL_ALIGNED_POINTER(p)                (U8*)(((UPTR)((UPTR)(p) + SHARKSSL_ALIGNMENT - 1)) & ((UPTR)-SHARKSSL_ALIGNMENT))
#define SHARKSSL_POINTER_IS_ALIGNED(p)             (0 == ((unsigned int)(UPTR)(p) & (SHARKSSL_ALIGNMENT - 1)))

#if SHARKSSL_UNALIGNED_MALLOC
#define SHARKSSL_MALLOC_ALIGN(s)                   ((s) + SHARKSSL_ALIGNMENT)
#define SHARKSSL_PNTR_ALIGNMENT(p)                 SHARKSSL_ALIGNED_POINTER(p)
#else
#define SHARKSSL_MALLOC_ALIGN(s)                   (s)
#define SHARKSSL_PNTR_ALIGNMENT(p)                 (U8*)(p)
#endif


#define SHARKSSL_DIM_ARR(a)                        (sizeof(a)/sizeof(a[0]))
 
#define SHARKSSL_BUF_EXPANDSIZE                    1024                                                                  
#define SHARKSSL_BUF_HEADROOM_SIZE                 (SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_SEQ_NUM_LEN)



#if (SHARKSSL_MAX_BLOCK_LEN <= (SHARKSSL_FINISHED_MSG_LEN_SSL - SHARKSSL_FINISHED_MSG_LEN_TLS))
#define SHARKSSL_HS_PARAM_OFFSET                   SHARKSSL_ALIGN_SIZE(SHARKSSL_RECORD_HEADER_SIZE + 1 + \
                                                                       SHARKSSL_RECORD_HEADER_SIZE + \
                                                                       SHARKSSL_FINISHED_MSG_LEN_SSL + \
                                                                       SHARKSSL_MAX_DIGEST_LEN + \
                                                                       SHARKSSL_MAX_REC_PAD_LEN)
#else
#define SHARKSSL_HS_PARAM_OFFSET                   SHARKSSL_ALIGN_SIZE(SHARKSSL_RECORD_HEADER_SIZE + 1 + \
                                                                       SHARKSSL_RECORD_HEADER_SIZE + \
                                                                       SHARKSSL_MAX_BLOCK_LEN + \
                                                                       SHARKSSL_FINISHED_MSG_LEN_TLS + \
                                                                       SHARKSSL_MAX_DIGEST_LEN + \
                                                                       SHARKSSL_MAX_REC_PAD_LEN)
#endif

#define SHARKSSL_FLAG_HAS_MORE_DATA                0x00000001
#define SHARKSSL_FLAG_SPLIT_ENCRYPT                0x00000002
#define SHARKSSL_FLAG_CHANGECIPHERSPEC_RECEIVED    0x00000004
#define SHARKSSL_FLAG_TMPBUF_CREATED               0x00000008
#define SHARKSSL_FLAG_DECRYPT_INITIALIZE           0x00000010
#define SHARKSSL_FLAG_INVALID_CON                  0x00000020
#define SHARKSSL_FLAG_ALERTED_CON                  0x00000040
#define SHARKSSL_FLAG_ZERO_LEN_APPLI               0x00000080
#define SHARKSSL_FLAG_CREATE_CLIENT_HELLO          0x00000100
#define SHARKSSL_FLAG_RESUMED_SESSION              0x00000200
#define SHARKSSL_FLAG_CERTIFICATE_REQUEST          0x00000400
#define SHARKSSL_FLAG_CERTIFICATE_REQUESTED        0x00000800
#define SHARKSSL_FLAG_HAS_CERTIFICATE              0x00001000
#define SHARKSSL_FLAG_EMPTY_CERTIFICATE            0x00002000
#define SHARKSSL_FLAG_TRUSTED_CA                   0x00004000
#define SHARKSSL_FLAG_SECURE_RENEGOTIATION         0x00008000
#define SHARKSSL_FLAG_RENEGOTIATION_REQUESTED      0x00010000
#define SHARKSSL_FLAG_RENEGOTIATION_SUBMITTED      0x00020000
#define SHARKSSL_FLAG_RENEGOTIATION_ONGOING        0x00040000  
#define SHARKSSL_FLAG_HANDSHAKE_DATA_IN_OUTBUF     0x00080000
#define SHARKSSL_FLAG_CACHED_SESSION               0x00100000
#define SHARKSSL_FLAG_HANDSHAKE_FINISHED           0x00200000
#define SHARKSSL_FLAG_FAVOR_RSA                    0x00400000


#define SHARKSSL_OP_INITIALIZE                     0x01
#define SHARKSSL_OP_FINALIZE                       0x02
#define SHARKSSL_OP_DESTRUCTOR                     (SHARKSSL_OP_INITIALIZE | SHARKSSL_OP_FINALIZE)
#define SHARKSSL_OP_ENCRYPT                        0x10
#define SHARKSSL_OP_DECRYPT                        0x20
#define SHARKSSL_OP_PUBLIC                         0x40  
#define SHARKSSL_OP_PRIVATE                        0x80  
#define SHARKSSL_OP_CALC_Y                         0x04  
#define SHARKSSL_OP_CALC_XY                        0x04  
#define SHARKSSL_OP_CALC_KEY                       0x08  
#define SHARKSSL_OP_SIGN                           0x10  
#define SHARKSSL_OP_VERIFY                         0x20  



#define SHARKSSL_CS_DHE                            0x0001
#define SHARKSSL_CS_EC                             0x0002
#define SHARKSSL_CS_DSA                            0x0004
#define SHARKSSL_CS_RSA                            0x0008
#define SHARKSSL_CS_PSK                            0x0010
#define SHARKSSL_CS_AEAD                           0x0020  
#define SHARKSSL_CS_TLS12                          0x0080
#define SHARKSSL_CS_SHA384                         0x0100
#define SHARKSSL_CS_SHA512                         0x0200
#define SHARKSSL_CS_SUITE_B                        0x0400



#define SHARKSSL_EXPLEN_GET_EXPLEN(e)              (U16)((e) & 0x00FF)
#define SHARKSSL_EXPLEN_GET_FORMAT(e)              (U16)(((U16)(e) & 0x0F00) >> 8)
#define SHARKSSL_EXPLEN_GET_CHAINLEN(e)            (U16)(((U16)(e) & 0xF000) >> 12)

#define SHARKSSL_EXPLEN_KEYTYPE_RSA                0x0
#define SHARKSSL_EXPLEN_KEYTYPE_EC                 0x2
#define SHARKSSL_EXPLEN_KEYTYPE_MASK               0x6
#define SHARKSSL_EXPLEN_PUBLIC_KEY                 0x8

#define SHARKSSL_EXPLEN_IS_PUBKEY(e)               (SHARKSSL_EXPLEN_GET_FORMAT(e) & SHARKSSL_EXPLEN_PUBLIC_KEY)
#define SHARKSSL_EXPLEN_GET_KEYTYPE(e)             (SHARKSSL_EXPLEN_GET_FORMAT(e) & SHARKSSL_EXPLEN_KEYTYPE_MASK)
#define SHARKSSL_EXPLEN_IS_KEYTYPE_RSA(e)          (SHARKSSL_EXPLEN_GET_KEYTYPE(e) == SHARKSSL_EXPLEN_KEYTYPE_RSA)
#define SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e)           (SHARKSSL_EXPLEN_GET_KEYTYPE(e) == SHARKSSL_EXPLEN_KEYTYPE_EC)


#define SHARKSSL_EXPLEN_SET_KEYTYPE_RSA_PUBLIC(e)  (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_RSA + SHARKSSL_EXPLEN_PUBLIC_KEY) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_RSA_PRIVATE(e) (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_RSA) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_EC_PUBLIC(e)   (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_EC + SHARKSSL_EXPLEN_PUBLIC_KEY) << 8);
#define SHARKSSL_EXPLEN_SET_KEYTYPE_EC_PRIVATE(e)  (e |= (U16)(SHARKSSL_EXPLEN_KEYTYPE_EC) << 8);



#define SHARKSSL_MODLEN_GET_EC_PUBLEN(m)           (U16)((m) & 0x00FF)
#define SHARKSSL_MODLEN_GET_RSA_MODLEN(m)          (m)
#define SHARKSSL_MODLEN_GET_EC_OID(m)              (U16)(((U16)(m) & 0xFF00) >> 8)
#define SHARKSSL_MODLEN_GET_RSA_OID(m)             0

#define SHARKSSL_MODLEN_GET_MODLEN(m, e)           (SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e) ? SHARKSSL_MODLEN_GET_EC_PUBLEN(m) : SHARKSSL_MODLEN_GET_RSA_MODLEN(m))
#define SHARKSSL_MODLEN_GET_OID(m, e)              (SHARKSSL_EXPLEN_IS_KEYTYPE_EC(e) ? SHARKSSL_MODLEN_GET_EC_OID(m) : SHARKSSL_MODLEN_GET_RSA_OID(m))


#define SHARKSSL_MODLEN_SET_OID(m, o)              (m = (((U16)l & 0xFF) << 8) | (m & 0xFF))



#if (SHARKSSL_ENABLE_CA_LIST  || SHARKSSL_ENABLE_CERTSTORE_API)
#define SHARKSSL_CA_LIST_NAME_SIZE                 8  
#define SHARKSSL_CA_LIST_ELEMENT_SIZE              (SHARKSSL_CA_LIST_NAME_SIZE + 4)
#define SHARKSSL_CA_LIST_INDEX_TYPE                0x00  

#ifdef __IAR_SYSTEMS_ICC__

#else
#if (SHARKSSL_CA_LIST_NAME_SIZE != SHARKSSL_ALIGN_SIZE(SHARKSSL_CA_LIST_NAME_SIZE))
#error SHARKSSL CA_STORE_API: UNSUPPORTED CA_LIST_NAME_SIZE
#endif
#endif

#if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_ENABLE_CERTSTORE_API)
#define SHARKSSL_CA_LIST_PTR_SIZE                  sizeof(U8*)
#define SHARKSSL_CA_LIST_PTR_TYPE                  0xAD
#define SHARKSSL_MAX_SNAME_LEN                     32

#if (SHARKSSL_MAX_SNAME_LEN < SHARKSSL_CA_LIST_NAME_SIZE)
#error SHARKS_MAX_SNAME_LEN must be >= SHARKSSL_CA_LIST_NAME_SIZE
#endif

typedef struct SharkSslCSCert
{
      DoubleLink super;
      U8 *ptr;  
      char name[SHARKSSL_MAX_SNAME_LEN + 1];  
} SharkSslCSCert;

#endif  
#endif  
 

typedef struct SharkSslBuf
{
   #if SHARKSSL_UNALIGNED_MALLOC
   U8  *mem;     
   #endif
   U8  *buf;     
   U8  *data;    
   U16  size;    
   U16  dataLen; 
   U16  temp;
} SharkSslBuf;

void    SharkSslBuf_constructor(SharkSslBuf*, U16);
void    SharkSslBuf_destructor(SharkSslBuf*);
U8     *SharkSslBuf_expand(SharkSslBuf*, U16);
void    SharkSslBuf_leftAlignData(SharkSslBuf*);
#define SharkSslBuf_notAllocated(o) (!((o)->buf))
#define SharkSslBuf_dataPtrLeftAligned(o) \
   ((o)->buf + SHARKSSL_BUF_HEADROOM_SIZE)
#define SharkSslBuf_isLeftAligned(o) \
   ((o)->data == SharkSslBuf_dataPtrLeftAligned(o))
#define SharkSslBuf_leftAlignDataPtr(o) do {\
   (o)->data = SharkSslBuf_dataPtrLeftAligned(o); \
   } while (0)
#if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
#define SharkSslBuf_cloneHeader(dest, src) \
   memcpy((U8*)((dest)->buf), (U8*)((src)->buf), SHARKSSL_BUF_HEADROOM_SIZE)
#endif



typedef int (*SharkSslCon_cipherFunc)(SharkSslCon*, U8, U8*, U16);
typedef int (*SharkSslCon_digestFunc)(SharkSslCon*, const U8*, U16, U8*);


typedef struct SharkSslCipherSuite
{
   SharkSslCon_cipherFunc cipherFunc;
   SharkSslCon_digestFunc digestFunc;
   U16 id;
   U16 flags;
   U8  keyLen;
   U8  blockLen;
   U8  digestLen;
} SharkSslCipherSuite;


#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
typedef struct SharkSslCertParsed
{
   SharkSslCert cert;
   U16 msgLen;    
   U8  keyType;
   U8  keyOID;
   U8  signatureAlgo;
   U8  hashAlgo;
} SharkSslCertParsed;


typedef struct SharkSslCertList
{
   SingleLink link;
   SharkSslCertParsed certP;
} SharkSslCertList;
 

typedef struct SharkSslCertKey
{
   U8 *mod, *exp;
   U16 modLen, expLen;
} SharkSslCertKey;


typedef struct SharkSslSignature
{
   #if (SHARKSSL_MAX_DIGEST_LEN > (SHARKSSL_MD5_MAC_LEN + SHARKSSL_SHA1_MAC_LEN))
   U8 hash[SHARKSSL_MAX_DIGEST_LEN];
   #else
   U8 hash[SHARKSSL_MD5_MAC_LEN + SHARKSSL_SHA1_MAC_LEN];
   #endif
   U8 *signature;
   U16 signLen;
   U8  signatureAlgo;
   U8  hashAlgo;
} SharkSslSignature;


typedef struct SharkSslCertParam
{
   SharkSslCertInfo  certInfo;
   SharkSslCertKey   certKey;
   SharkSslSignature signature;
} SharkSslCertParam;


typedef struct SharkSslSignParam  
{
   SharkSslCertKey  *pCertKey;
   SharkSslSignature signature; 
} SharkSslSignParam;


#if SHARKSSL_ENABLE_CLONE_CERTINFO
typedef struct SharkSslClonedCertInfo
{
   SharkSslCertInfo ci;
   #if SHARKSSL_ENABLE_SESSION_CACHE
   U8 flags;
   #endif
} SharkSslClonedCertInfo;



#define SHARKSSL_CCINFO_CERT_CLONED  0x01
#define SHARKSSL_CCINFO_CERT_CACHED  0x02
#endif  
#endif  


#if SHARKSSL_ENABLE_DHE_RSA
typedef struct SharkSslDHParam
{
   U8 *p;     
   U8 *g;     
   U8 *Y;     
   U8 *r;     
   U16 pLen;  
   U16 gLen;  
} SharkSslDHParam;
#endif


#if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
typedef struct SharkSslECDHParam
{
   U8 *XY;         
   U8 *k;          
   U16 xLen;        
   U16 curveType;  
} SharkSslECDHParam;
#endif


#if SHARKSSL_ENABLE_ECDSA
typedef struct SharkSslECDSAParam
{
   U8 *R;          
   U8 *S;          
   U8 *key;        
   U8 *hash;       
   U16 keyLen;      
   U16 hashLen;    
   U16 curveType;  
} SharkSslECDSAParam;
#endif


typedef struct SharkSslHSParam
{
   U8  clientRandom[SHARKSSL_RANDOM_LEN];
   U8  serverRandom[SHARKSSL_RANDOM_LEN];
   U8  masterSecret[SHARKSSL_MASTER_SECRET_LEN];
   U8  sharedSecret[2 * (SHARKSSL_MAX_DIGEST_LEN +
                         SHARKSSL_MAX_KEY_LEN +
                         SHARKSSL_MAX_BLOCK_LEN) + SHARKSSL_MAX_DIGEST_LEN];
   SharkSslMd5Ctx      md5Ctx;
   SharkSslSha1Ctx     sha1Ctx;
   #if SHARKSSL_ENABLE_TLS_1_2
   SharkSslSha256Ctx   sha256Ctx;
   #if SHARKSSL_USE_SHA_384
   SharkSslSha384Ctx   sha384Ctx;
   #endif
   #if SHARKSSL_USE_SHA_512
   SharkSslSha384Ctx   sha512Ctx;
   #endif
   #endif
   #if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)
   SharkSslCertParsed *certParsed;  
   SharkSslCertKey     certKey;     
   SharkSslCertParam   certParam;   
   SharkSslSignParam   signParam;
   #endif
   #if SHARKSSL_ENABLE_DHE_RSA
   SharkSslDHParam     dhParam;
   #endif
   #if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
   SharkSslECDHParam   ecdhParam;
   #endif
   SharkSslCipherSuite *cipherSuite;
} SharkSslHSParam;


void    SharkSslHSParam_constructor(SharkSslHSParam*);
void    SharkSslHSParam_destructor(SharkSslHSParam*);
void    SharkSslHSParam_add(SharkSslHSParam*, U8*, U16);
#define hsParam(o) ((SharkSslHSParam*)(SharkSslBuf_dataPtrLeftAligned(&o->outBuf) + SHARKSSL_HS_PARAM_OFFSET))


#if SHARKSSL_ENABLE_SESSION_CACHE
struct SharkSslSession
{
   SharkSslCipherSuite *cipherSuite;
   U32 firstAccess, latestAccess;
   U8  id[SHARKSSL_MAX_SESSION_ID_LEN];
   U8  masterSecret[SHARKSSL_MASTER_SECRET_LEN];
   U16 nUse;
   U8  major_minor, flags;
   #if SHARKSSL_ENABLE_CLONE_CERTINFO
   SharkSslClonedCertInfo *clonedCertInfo;
   #endif
};

#define SharkSslSession_cmpMajMin(o,maj,min) ((o)->major_minor == (((maj & 0x0F) << 4) | (min & 0x0F)))
#define SharkSslSession_getMaj(o)            (((o)->major_minor & 0xF0) >> 4)
#define SharkSslSession_getMin(o)            ((o)->major_minor & 0x0F)
#define SharkSslSession_setMajMin(o,maj,min) do {           \
   baAssert((maj <= 0x0F) && (min <= 0x0F));                \
   (o)->major_minor = (((maj & 0x0F) << 4) | (min & 0x0F)); \
   } while (0);



#define SHARKSSL_SESSION_FLAG_TRUSTED_CA             0x80


void    SharkSslSessionCache_constructor(SharkSslSessionCache*, U16);
void    SharkSslSessionCache_destructor(SharkSslSessionCache*);
#define SharkSslSessionCache_lock(o)   ThreadMutex_set(&((o)->cacheMutex))
#define SharkSslSessionCache_unlock(o) ThreadMutex_release(&((o)->cacheMutex))
SharkSslSession *SharkSslSessionCache_newSession(SharkSslSessionCache*, SharkSslCon*, U8*, U16);
SharkSslSession *SharkSslSessionCache_findSession(SharkSslSessionCache*, SharkSslCon*, U8*, U16);
#endif


struct SharkSslCon   
{
   #if SHARKSSL_MAX_BLOCK_LEN
   U8 rIV[SHARKSSL_MAX_BLOCK_LEN];
   #endif
   #if SHARKSSL_MAX_KEY_LEN
   U8 rKey[SHARKSSL_MAX_KEY_LEN];
   #endif
   U8 rMacH[SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_MAX_DIGEST_LEN];

   #if SHARKSSL_MAX_BLOCK_LEN
   U8 wIV[SHARKSSL_MAX_BLOCK_LEN];
   #endif
   #if SHARKSSL_MAX_KEY_LEN
   U8 wKey[SHARKSSL_MAX_KEY_LEN];
   #endif
   U8 wMacH[SHARKSSL_MAX_DIGEST_BLOCK_LEN + SHARKSSL_MAX_DIGEST_LEN];

   SharkSsl *sharkSsl;
   SharkSslCipherSuite *rCipherSuite, *wCipherSuite;
   #if SHARKSSL_ENABLE_SESSION_CACHE
   SharkSslSession *session;
   #endif

   void *rCtx, *wCtx;
   #if SHARKSSL_UNALIGNED_MALLOC
   SharkSslCon *mem;
   #endif

   #if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
   U8 clientVerifyData[SHARKSSL_MAX_FINISHED_MSG_LEN];
   U8 serverVerifyData[SHARKSSL_MAX_FINISHED_MSG_LEN];
   #endif

   #if ((SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA) && SHARKSSL_ENABLE_CLONE_CERTINFO)
   SharkSslClonedCertInfo *clonedCertInfo;
   #endif

   #if (SHARKSSL_ENABLE_CA_LIST && SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH && (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA))
   SharkSslCAList caListCertReq;
   #endif

   SharkSslBuf inBuf, outBuf;
   #if SHARKSSL_ENABLE_SECURE_RENEGOTIATION
   SharkSslBuf tmpBuf;
   #endif

   U32 flags;
   #if SHARKSSL_ENABLE_SSL_3_0
   U16 rSeq, wSeq;
   #endif
   U8 state;
   U8 reqMajor, reqMinor;
   U8 major, minor;
   U8 ccLen;
   U8 padLen;
   U8 alertLevel, alertDescr; 
   #if ((SHARKSSL_SSL_SERVER_CODE || SHARKSSL_SSL_CLIENT_CODE) && SHARKSSL_ENABLE_SELECT_CIPHERSUITE)
   #if (SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH > 0xFF)
   #error SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH must be lower than 256
   #endif
   U8 cipherSelection[SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH];
   U8 cipherSelCtr;
   #endif
};


typedef enum 
{
  SharkSslCon_SenderIsClient,
  SharkSslCon_SenderIsServer
  #if SHARKSSL_ENABLE_SSL_3_0
  #if ((SHARKSSL_SSL_CLIENT_CODE && (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)) || \
       (SHARKSSL_SSL_SERVER_CODE && SHARKSSL_ENABLE_CLIENT_AUTH))
  ,
  SharkSslCon_NoSender  
  #endif
  #endif
} SharkSslCon_SendersRole;



#define SharkSsl_createCon2(o, sharkSslCon) do {\
   (o)->nCon++;\
   SharkSslCon_constructor(sharkSslCon, o);\
} while (0)



void               SharkSslCon_constructor(SharkSslCon *o, SharkSsl *sharkSsl);
void               SharkSslCon_destructor(SharkSslCon *o);


SharkSslCon_RetVal SharkSslCon_buildFatalMessage(SharkSslCon*, U8);
SharkSslCon_RetVal SharkSslCon_buildAlertMessage(SharkSslCon*, U8, U8);
SharkSslCon_RetVal SharkSslCon_processHandshake(SharkSslCon*, U8*, U16*, U8);
SharkSslCon_RetVal SharkSslCon_processChangeCipherSpec(SharkSslCon*, U8*, U16);
U8                *SharkSslCon_writeSslHeader(SharkSslCon*, U8, U8*, U16);
U16                SharkSslCon_calcSharedSecretLen(SharkSslCon*, SharkSslCipherSuite*);
int                SharkSslCon_calcCryptoParam(SharkSslCon*, U8*, U16, U8*, U16, U8[32], U8[32], U8*);
int                SharkSslCon_calcFinishedHash(SharkSslCon*, SharkSslCon_SendersRole, U8*, U8*);
int                SharkSslCon_buildFinished(SharkSslCon *o, SharkSslCon_SendersRole, U8*, U8*);
void               SharkSslCon_setHMacKey(SharkSslCon*, U8*, U8*, U8*, U8, U8);
int                SharkSslCon_calcMacAndEncrypt(SharkSslCon*, U8);
U8                 SharkSslCon_calcCCLen(SharkSslCon *o, SharkSslCipherSuite *cipherSuite);
void               SharkSslCon_invalidateCon(SharkSslCon*);

#if (SHARKSSL_ENABLE_RSA || SHARKSSL_ENABLE_ECDSA)

int  SharkSslSignParam_sign(SharkSslSignParam*);
int  SharkSslSignParam_verify(const SharkSslSignParam*);

int  SharkSslCertParam_parseCert(SharkSslCertParam*, U8*, U32, U8*);
U8   SharkSslCertDN_equal(const SharkSslCertDN*, const SharkSslCertDN*);
SHARKSSL_API U8 SharkSslCertKey_setFromSharkSslCert(SharkSslCertKey*, SharkSslCert);
#if SHARKSSL_ENABLE_CLIENT_AUTH
U8   SharkSslCert_CAfound(SharkSslCert, U8*, U16);
#endif
U8   SharkSslCert_outCert(SharkSslCert, U16, U8*);
U16  SharkSslCert_certMsgLen(SharkSslCert);
#if SHARKSSL_ENABLE_CLONE_CERTINFO
U8   SharkSslCon_cloneCertInfo(SharkSslCon *o, SharkSslClonedCertInfo **outCertInfoPtr);
#endif
#if SHARKSSL_USE_ECC
U8   sharkssl_EC_getPointLen(U16 curveOID);
#endif
#endif

int  SharkSslCon_md5(SharkSslCon*, const U8*, U16, U8*);
int  SharkSslCon_sha1(SharkSslCon*, const U8*, U16, U8*);
#if SHARKSSL_USE_SHA_384
int  SharkSslCon_sha384(SharkSslCon*, const U8*, U16, U8*);
#endif
#if SHARKSSL_USE_SHA_256
int  SharkSslCon_sha256(SharkSslCon*, const U8*, U16, U8*);
#endif
int  SharkSslCon_HMAC(SharkSslCon *, U8, U8*, U16, U8*, U8, U8, SharkSslCon_digestFunc);
#if SHARKSSL_ENABLE_RSA   
SHARKSSL_API int  SharkSslCertKey_RSA(const SharkSslCertKey*, U8, U8*);
int SharkSslCertKey_RSA_public_encrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_private_decrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_private_encrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
int SharkSslCertKey_RSA_public_decrypt(const SharkSslCertKey *certKey, U16 len, U8 *in, U8 *out, U8 padding);
#endif
#if SHARKSSL_ENABLE_DHE_RSA
int  SharkSslDHParam_DH(const SharkSslDHParam*, U8 op, U8*);
#if SHARKSSL_SSL_SERVER_CODE
void SharkSslDHParam_setParam(SharkSslDHParam *dh);
#endif
#endif  
#if (SHARKSSL_ENABLE_ECDHE_RSA || SHARKSSL_ENABLE_ECDH_RSA || SHARKSSL_ENABLE_ECDHE_ECDSA || SHARKSSL_ENABLE_ECDH_ECDSA)
int  SharkSslECDHParam_ECDH(const SharkSslECDHParam*, U8 op, U8*);
#endif
#if SHARKSSL_ENABLE_ECDSA
int SharkSslECDSAParam_ECDSA(const SharkSslECDSAParam*, U8 op);
#endif
#if SHARKSSL_USE_NULL_CIPHER
int  SharkSslCon_null(SharkSslCon*, U8, U8*, U16);
#endif
#if SHARKSSL_USE_ARC4
int  SharkSslCon_arc4(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_USE_DES || SHARKSSL_USE_3DES)
int  SharkSslCon_des_cbc(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_USE_AES_128 || SHARKSSL_USE_AES_256)
int  SharkSslCon_aes_cbc(SharkSslCon*, U8, U8*, U16);
#if (SHARKSSL_ENABLE_AES_GCM && SHARKSSL_ENABLE_TLS_1_2)
int  SharkSslCon_aes_gcm(SharkSslCon*, U8, U8*, U16);
#endif
#if (SHARKSSL_ENABLE_AES_CCM && SHARKSSL_ENABLE_TLS_1_2)
int  SharkSslCon_aes_ccm(SharkSslCon*, U8, U8*, U16);
#endif
#endif

#endif


#ifndef __JRpc_h
#define __JRpc_h



#ifndef __JSerializer_h
#define __JSerializer_h

typedef struct JSerializer
{
#ifdef __cplusplus
      
      JSerializer(JErr* err, BufPrint* out);
      ~JSerializer();

      
      int setInt(S32 val);

      
      int setLong(S64 val);
#ifndef NO_DOUBLE

      
      int setDouble(double val);
#endif

      
      int setString(const char* val);

      
      int fmtString(const char* fmt,...);

       
      int vFmtString(const char* fmt,va_list argList);

      
      int setBoolean(bool val);

      
      int setNull();

      
      int setJV(struct JVal* val, bool iterateNext=false);

      
      int set(const char* fmt, ...);

      
      int setMemberName(const char* name);

      

      
      int beginObject();

      
      int endObject();

      
      int beginArray();

      
      int endArray();

      
      JErr* getErr();

      
      int flush();

      
      int commit();

      
      BufPrint* getBufPrint();

#endif
      JErr* err;
      struct
      {
            S32 level;
            U8 data[64];
      }objectStack;
      BufPrint* out;
      BaBool objectMember;
      BaBool startNewObj;
} JSerializer;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JSerializer_constructor(JSerializer* o, JErr* err, BufPrint* out);
#define JSerializer_destructor(o) JSerializer_flush(o)
BA_API int JSerializer_flush(JSerializer* o);
BA_API int JSerializer_commit(JSerializer* o);
#define JSerializer_getErr(o) (o)->err
BA_API int JSerializer_setInt(JSerializer* o, S32 val);
BA_API int JSerializer_setLong(JSerializer* o, S64 val);
#ifdef NO_DOUBLE
#define JSerializer_setDouble JSerializer_setInt
#else
BA_API int JSerializer_setDouble(JSerializer* o, double val);
#endif

BA_API int JSerializer_fmtString(JSerializer* o, const char* fmt,...);
BA_API int JSerializer_vFmtString(
   JSerializer* o, const char* fmt,va_list argList);
BA_API int JSerializer_setString(JSerializer* o, const char* val);
BA_API int JSerializer_setBoolean(JSerializer* o, BaBool val);
BA_API int JSerializer_setNull(JSerializer* o);
BA_API int JSerializer_setJV(
   JSerializer* o, struct JVal* val, BaBool iterateNext);
BA_API int JSerializer_vSetJV(
   JSerializer* o,const char** fmt,va_list* argList);
BA_API int JSerializer_set(JSerializer* o, const char* fmt, ...);
BA_API int JSerializer_setMemberName(JSerializer* o, const char* name);
BA_API int JSerializer_beginObject(JSerializer* o);
BA_API int JSerializer_endObject(JSerializer* o);
BA_API int JSerializer_beginArray(JSerializer* o);
BA_API int JSerializer_endArray(JSerializer* o);
#define JSerializer_getBufPrint(o) (o)->out
#ifdef __cplusplus
}
inline JSerializer::JSerializer(JErr* err, BufPrint* out) {
   JSerializer_constructor(this,err, out); }
inline JSerializer::~JSerializer() {
   JSerializer_destructor(this); }
inline int JSerializer::setInt(S32 val) {
   return  JSerializer_setInt(this, val); }
inline int JSerializer::setLong(S64 val) {
   return  JSerializer_setLong(this, val); }
#ifndef NO_DOUBLE
inline int JSerializer::setDouble(double val) {
   return  JSerializer_setDouble(this, val); }
#endif
inline int JSerializer::fmtString(const char* fmt,...) {
   int retv; va_list argList;
   va_start(argList, fmt); 
   retv = JSerializer_fmtString(this, fmt, argList);
   va_end(argList);
   return retv;
}
inline int JSerializer::vFmtString(const char* fmt,va_list argList) {
   return JSerializer_vFmtString(this, fmt, argList); }
inline int JSerializer::setString(const char* val) {
   return  JSerializer_setString(this, val); }
inline int JSerializer::setBoolean(bool val) {
   return  JSerializer_setBoolean(this, val ? TRUE : FALSE); }
inline int JSerializer::setNull() {
   return  JSerializer_setNull(this); }
inline int JSerializer::setJV(struct JVal* val, bool iterateNext) {
   return  JSerializer_setJV(this,val,iterateNext?TRUE:FALSE); }
inline int JSerializer::set(const char* fmt, ...) {
   int retv; va_list argList;
   va_start(argList, fmt); 
   retv=JSerializer_vSetJV(this,&fmt,&argList);
   va_end(argList);
   return retv;
}
inline int JSerializer::setMemberName(const char* name) {
   return  JSerializer_setMemberName(this, name); }
inline int JSerializer::beginObject() {
   return  JSerializer_beginObject(this); }
inline int JSerializer::endObject() {
   return  JSerializer_endObject(this); }
inline int JSerializer::beginArray() {
   return  JSerializer_beginArray(this); }
inline int JSerializer::endArray() {
   return  JSerializer_endArray(this); }
inline JErr* JSerializer::getErr() {
   return JSerializer_getErr(this); }
inline int JSerializer::flush() {
   return JSerializer_flush(this); }
inline int JSerializer::commit() {
   return JSerializer_commit(this); }
inline BufPrint* JSerializer::getBufPrint() {
   return JSerializer_getBufPrint(this); }
#endif

  

#endif
#ifndef __DOXYGEN__
struct JRpc;
struct JRpcObj;
#endif





typedef int (*JRpcMethodCB)(
   struct JRpcObj* rpc,JVal* val,JErr* err,BufPrint* out);
 

typedef struct JRpcMethod
{
      const char* methodName;
      JRpcMethodCB rpc;
} JRpcMethod;
 


typedef struct JRpc
{
#ifdef __cplusplus
      
      JRpc();
      
      ~JRpc();

      
      static void sendErr(JErr* err, BufPrint* out);

      
      static void sendUserErr(BufPrint* out, S32 errCode, JVal* errVal,
                              const char* fmt, ...);

      
      static void vSendUserErr(BufPrint* out, S32 errCode,JVal* errVal,
                               const char* fmt, va_list argList);

      
      int service(JParser* p, JVal* val, BufPrint* out);
#endif
      SplayTree rpcObjTree;  
} JRpc;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JRpc_sendErr(JErr* err, BufPrint* out);
BA_API void JRpc_sendUserErr(BufPrint* out, S32 errCode,
                             JVal* errVal, const char* fmt, ...);
BA_API void JRpc_vSendUserErr(BufPrint* out, S32 errCode,
                              JVal* errVal, const char* fmt, va_list argList);
BA_API int JRpc_service(JRpc* o, JParser* p, JVal* val, BufPrint* out);
BA_API void JRpc_constructor(JRpc* o);
BA_API void JRpc_destructor(JRpc* o);
#ifdef __cplusplus
}
inline void JRpc::sendErr(JErr* err, BufPrint* out) {
   JRpc_sendErr(err, out); }
inline void JRpc::sendUserErr(BufPrint* out, S32 errCode,
                              JVal* errVal, const char* fmt, ...) {
   va_list argList;
   va_start(argList, fmt); 
   JRpc_vSendUserErr(out,  errCode, errVal, fmt, argList);
   va_end(argList);
}
inline void JRpc::vSendUserErr(BufPrint* out, S32 errCode,JVal* errVal,
                               const char* fmt, va_list argList) {
   JRpc_vSendUserErr(out,  errCode, errVal, fmt, argList); }
inline int JRpc::service(JParser* p, JVal* val, BufPrint* out) {
   return JRpc_service(this, p, val, out); }
inline JRpc::JRpc() {
   JRpc_constructor(this); }
inline JRpc::~JRpc() {
   JRpc_destructor(this); }
#endif



typedef struct JRpcObj
{
#ifdef __cplusplus
      
       JRpcObj(JRpc* rpc, const char* objName,
              const struct JRpcMethod* methods, int methodSize);
      
      ~JRpcObj();

#endif
      SplayTreeNode super; 
      JRpc* rpc;
      const struct JRpcMethod* methods;
      int methodsSize;
} JRpcObj;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JRpcObj_constructor(JRpcObj* o, JRpc* rpc, const char* objName,
                         const struct JRpcMethod* methods, int methodSize);
BA_API void JRpcObj_destructor(JRpcObj* o);
#ifdef __cplusplus
}
inline JRpcObj::JRpcObj(JRpc* rpc, const char* objName,
                       const struct JRpcMethod* methods, int methodSize) {
   JRpcObj_constructor(this, rpc, objName, methods, methodSize); }
inline JRpcObj::~JRpcObj() {
   JRpcObj_destructor(this); }
#endif



typedef struct JRpcResp
{
#ifdef __cplusplus
      
      JRpcResp(JErr* err, BufPrint* out);

      
      ~JRpcResp();

      
      JSerializer* getSerializer();
      
      void sendResponse();

      U8 buf[sizeof(JSerializer)];
#else
      JSerializer s;
#endif
      U32 cursor;
      BaBool respSent;
} JRpcResp;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void JRpcResp_constructor(JRpcResp* o, JErr* err, BufPrint* out);
#define JRpcResp_destructor(o) JRpcResp_sendResponse(o)
BA_API JSerializer* JRpcResp_getSerializer(JRpcResp* o);
BA_API void JRpcResp_sendResponse(JRpcResp* o);
#ifdef __cplusplus
}
inline JRpcResp::JRpcResp(JErr* err, BufPrint* out) {
   JRpcResp_constructor(this, err, out); }
inline JRpcResp::~JRpcResp() {
   JRpcResp_destructor(this); }
inline JSerializer* JRpcResp::getSerializer() {
   return JRpcResp_getSerializer(this); }
inline void JRpcResp::sendResponse() {
   JRpcResp_sendResponse(this); }
#endif

  
#endif


#ifndef __JRpcPage_h
#define __JRpcPage_h
 
typedef struct JRpcPage
#ifdef __cplusplus
   : public HttpPage 
{
      
      JRpcPage(const char* pageName,
               JRpc* rpc,
               AllocatorIntf* vAlloc=AllocatorIntf_getDefault(),
               AllocatorIntf* dAlloc=AllocatorIntf_getDefault());
#else
{
   HttpPage super;
#endif
      JRpc* rpc;
      AllocatorIntf* vAlloc; //Allocator used for allocating JVal types
      AllocatorIntf* dAlloc; //Allocator used for generic dynamic allocation
} JRpcPage;

#ifdef __cplusplus
      extern "C" {
#endif
BA_API void JRpcPage_constructor(JRpcPage* o, const char* pageName,JRpc* rpc,
                                 AllocatorIntf* vAlloc,AllocatorIntf* dAlloc);
#ifdef __cplusplus
}
inline JRpcPage::JRpcPage(const char* pageName,JRpc* rpc,
                          AllocatorIntf* vAlloc,AllocatorIntf* dAlloc) {
   JRpcPage_constructor(this, pageName,rpc,vAlloc,dAlloc); }
#endif

  
#endif

#ifndef _RecIoIter_h
#define _RecIoIter_h

struct RecIoIter;

typedef int (*RecIoIter_OnResponse)(
   struct RecIoIter* o, const char* from, const char* to, IoStat* st);
typedef int (*RecIoIter_OnErr)(
   struct RecIoIter* o, const char* name, int err, const char* errMsg);

typedef struct RecIoIter
{
      IoStat st;
      AllocatorIntf* alloc;
      IoIntf* io;
      RecIoIter_OnResponse onResponseFp;
      RecIoIter_OnErr onErrFp;
      int recCounter;
} RecIoIter;

#define RecIoIter_constructor( \
o, allocMA, ioMA, onResponseFpMA, onErrFpMA) do { \
   (o)->alloc=allocMA; \
   (o)->io=ioMA; \
   (o)->onResponseFp=onResponseFpMA; \
   (o)->onErrFp=onErrFpMA; \
   (o)->recCounter=0; \
} while(0)   


BA_API int RecIoIter_doResource(RecIoIter* o,const char* from,const char* to);

#endif


#ifndef __WebDAV_h
#define __WebDAV_h

struct WebDAV;

#ifndef __DOXYGEN__
typedef struct
{
      SplayTree lTree; 
      SingleList lList; 
      struct WebDAV* webDAV;
      char* lockDir;
      char* lockDirFn;
      U32 nextLockFileNumber;
      U32 locksLeft; 
} LockContainer;
#endif




typedef struct WebDAV
#ifdef __cplusplus
: public HttpDir
{ 
      
      WebDAV(IoIntf* io,
             int maxUploads,
             const char* dirName, 
             const char* lockDir,
             U32 maxNumberOfLocks=10,
             AllocatorIntf* alloc=0,
             S8 priority=0);

      
      ~WebDAV();

#if 0
}
#endif
#else
{
   HttpDir super; 
#endif
   HttpUploadCbIntf uploadCb;
   LockContainer lock;
   HttpUpload upload;
   IoIntf* io;
   AllocatorIntf* alloc;
   char* vdRootPath;
   size_t vdRootPathLen;
   BaBool ioReadOnly; 
   BaBool ioMoveDir; 
} WebDAV;


#ifdef __cplusplus
extern "C" {
#endif

BA_API void WebDAV_constructor(
   WebDAV* o,
   IoIntf* io,
   int maxUploads,
   const char* dirName, 
   const char* lockDir,
   U32 maxNumberOfLocks,
   AllocatorIntf* alloc,
   S8 priority);

BA_API void WebDAV_destructor(WebDAV* o);

#define WebDAV_setAuthenticator(o, authenticator, realm) \
   HttpDir_setAuthenticator((HttpDir*)o, authenticator, realm)

typedef struct
{
      
      int action; 
      BaTime lockTime; 
      const char* name; 
      const char* owner; 
      ResIntfPtr fp; 
} WebDAVLockMgr;
 

BA_API int WebDAV_lockmgr(WebDAV* o, WebDAVLockMgr* mgr);



#ifdef __cplusplus
}
inline WebDAV::WebDAV(IoIntf* io,
                      int maxUploads,
                      const char* dirName, 
                      const char* lockDir,
                      U32 maxNumberOfLocks,
                      AllocatorIntf* alloc,
                      S8 priority) {
   WebDAV_constructor(this,io,maxUploads,dirName, lockDir,
                      maxNumberOfLocks, alloc,priority);
}

inline WebDAV::~WebDAV(){
   WebDAV_destructor(this);
}
#endif

#endif 


#ifndef __lbaint_h
#define __lbaint_h




#ifndef lualib_h
#define lualib_h

LUAMOD_API int (luaopen_base) (lua_State *L);

#define LUA_COLIBNAME	"coroutine"
LUAMOD_API int (luaopen_coroutine) (lua_State *L);

#define LUA_TABLIBNAME	"table"
LUAMOD_API int (luaopen_table) (lua_State *L);

#define LUA_IOLIBNAME	"io"
LUAMOD_API int (luaopen_io) (lua_State *L);

#define LUA_OSLIBNAME	"os"
LUAMOD_API int (luaopen_os) (lua_State *L);

#define LUA_STRLIBNAME	"string"
LUAMOD_API int (luaopen_string) (lua_State *L);

#define LUA_BITLIBNAME	"bit32"
LUAMOD_API int (luaopen_bit32) (lua_State *L);

#define LUA_MATHLIBNAME	"math"
LUAMOD_API int (luaopen_math) (lua_State *L);

#define LUA_DBLIBNAME	"debug"
LUAMOD_API int (luaopen_debug) (lua_State *L);

#define LUA_LOADLIBNAME	"package"
LUAMOD_API int (luaopen_package) (lua_State *L);



LUALIB_API void (luaL_openlibs) (lua_State *L);



#if !defined(lua_assert)
#define lua_assert(x)	((void)0)
#endif


#endif
typedef struct LHttpCommand
{
   lua_State *LM; 
   lua_State* L; 
   HttpCommand* cmd; 
    
   const char* curLspPathname;
   HttpDir* curDir;
   int threadRef; 
   int envRef; 
   BaBool isInLspPage;
   BaBool stopRequest; 
} LHttpCommand;



#define LHttpCommand_toCmd(L,ix) \
  ((LHttpCommand*)baluaENV_checkudata(L, ix, BA_THTTPCMD))


#define LHttpCommand_check(L,ix) \
  LHttpCommand_checkCmd(L,LHttpCommand_toCmd(L,ix))

LHttpCommand* LHttpCommand_checkCmd(lua_State* L,void* lcmd);
void LHttpCommand_stopRequest(LHttpCommand* lcmd, lua_State* L);
LHttpCommand* LHttpCommand_create(lua_State* LM, HttpCommand* cmd);
int LHttpCommand_error(lua_State *L);
#define LHttpCommand_release(lcmd) lua_settop(lcmd->L,1)



int balua_loadfile(
	lua_State *L, const char *filename, struct IoIntf* io, int envix);
int balua_pushstatus(lua_State* L, int ret);
int balua_preprocess(lua_State* L, const char* buf, int addStartupCode);
int LSessionENV_push(lua_State* L, HttpSession* s);

void baiolib_register(lua_State *L);
void LHttpDir_register(lua_State *L);
void LTimer_register(lua_State *L);
void ljsonlib_register(lua_State* L);

void luaopen_ba_create(lua_State *L);
void luaopen_ba_aes(lua_State* L);
void luaopen_ba_misc(lua_State *L);
void luaopen_ba_io(lua_State *L);
void luaopen_ba_json(lua_State* L);
void luaopen_ba_xmlrpc(lua_State* L);
void luaopen_ba_timer(lua_State* L);
int luaopen_xparser(lua_State *L);

int ljsonlibTabEncode(lua_State* L, BufPrint* b, int recIxTab, int tabIx);

#define LUserIntf_check(L,ix) \
  ((UserIntf*)baluaENV_checkudata(L,ix,BA_TUSERINTF))

#define LAuthorizerIntf_check(L,ix) \
      (AuthorizerIntf*)baluaENV_checkudata(L, ix, BA_TAUTHORIZERINTF)


#endif

 
#ifndef _XmlRpc_h
#define _XmlRpc_h

#ifndef __DOXYGEN__
struct XmlRpcMethod;
struct XmlRpcVal;
struct XmlRpcFiber;
struct XmlRpcPage;
#endif

typedef enum {
   
   XmlRpcElemType_Array=0,
   XmlRpcElemType_Base64,
   XmlRpcElemType_Boolean,
   XmlRpcElemType_Data,
   XmlRpcElemType_DateTime,
   XmlRpcElemType_Double,
   XmlRpcElemType_I4,
   XmlRpcElemType_Int,
   XmlRpcElemType_Member,
   XmlRpcElemType_MethodCall,
   XmlRpcElemType_MethodName,
   XmlRpcElemType_Name,
   XmlRpcElemType_Nil,
   XmlRpcElemType_Param,
   XmlRpcElemType_Params,
   XmlRpcElemType_String,
   XmlRpcElemType_Struct,
   XmlRpcElemType_Value,
   

   
   XmlRpcElemType_Base64Decoded,
   XmlRpcElemType_EndTagDetected,
   XmlRpcElemType_Unknown
}XmlRpcElemType;

 






typedef enum {
   XmlRpcFault_NoError=0,

   XmlRpcFault_NotWellFormed = -32700,
   XmlRpcFault_UnsupportedEncoding = -32701,
   XmlRpcFault_InvalidCharacterForEncoding = -32702,

   XmlRpcFault_InvalidXmlRpc = -32600,
   XmlRpcFault_MethodNotFound = -32601,
   XmlRpcFault_InvalidMethodParams = -32602,

   XmlRpcFault_ApplicationError = -32500,
   XmlRpcFault_SystemError = -32400
} XmlRpcFaultCodes;


    
typedef struct XmlRpcFault
{
#ifdef __cplusplus

      
      XmlRpcFault();

      
      ~XmlRpcFault();

      
      void reset();

      
      bool isError();
      
      bool noError();

      
      int fmtError(int ecode,const char* fmt, ...);

      
      void setDynBuffer(DynBuffer* dynBuffer);

      
      BufPrint* getBufPrint();

      
      int commitBufPrint(int eCode);

      
      int setError(int ecode,const char* msg);

      
      int setMallocError();

      
      int setReallocError();

      
      int setTooFewParams();
#endif
      const char* msg;
      const char* found;
      AllocatorIntf* alloc;
      DynBuffer* dynBuffer;
      U32 errorStartPos;
      int eCode;
} XmlRpcFault;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void XmlRpcFault_constructor(XmlRpcFault* o);
#define XmlRpcFault_destructor(o) 
#define XmlRpcFault_reset(o) (o)->eCode = XmlRpcFault_NoError
#define XmlRpcFault_isError(o) ((o)->eCode != XmlRpcFault_NoError)
#define XmlRpcFault_noError(o) ((o)->eCode == XmlRpcFault_NoError)
BA_API BufPrint* XmlRpcFault_getBufPrint(XmlRpcFault* o);
BA_API int XmlRpcFault_commitBufPrint(XmlRpcFault* o, int eCode);
BA_API int XmlRpcFault_vfmtError(
   XmlRpcFault* o,int ecode,const char* fmt,va_list argList);
BA_API int XmlRpcFault_fmtError(XmlRpcFault* o,int ecode,const char* fmt, ...);
#define XmlRpcFault_setDynBuffer(o, db) (o)->dynBuffer=db
BA_API int XmlRpcFault_setError(XmlRpcFault* o,int ecode,const char* msg);
BA_API int XmlRpcFault_setMallocError(XmlRpcFault* o);
BA_API int XmlRpcFault_setReallocError(XmlRpcFault* o);
BA_API int XmlRpcFault_setTooFewParams(XmlRpcFault* o);
BA_API void XmlRpcFault_sendError(XmlRpcFault* o, HttpAsynchResp* resp);
BA_API void XmlRpcFault_sendError2(
   int ecode,const char* msg, struct XmlRpcFiber* fiber);
#ifdef __cplusplus
}
inline XmlRpcFault::XmlRpcFault() {
   XmlRpcFault_constructor(this); }
inline XmlRpcFault::~XmlRpcFault() {
   XmlRpcFault_destructor(this); }
inline void XmlRpcFault::reset() {
   XmlRpcFault_reset(this); }
inline bool XmlRpcFault::isError() {
   return XmlRpcFault_isError(this) ? true : false; }
inline bool XmlRpcFault::noError() {
   return XmlRpcFault_noError(this) ? true : false; }
inline BufPrint* XmlRpcFault::getBufPrint() {
   return XmlRpcFault_getBufPrint(this); }
inline int XmlRpcFault::commitBufPrint(int eCode) {
   return XmlRpcFault_commitBufPrint(this, eCode); }
inline int XmlRpcFault::fmtError(int ecode,const char* fmt, ...) {
   int retv; va_list varg;
   va_start(varg, fmt);  
   retv=XmlRpcFault_vfmtError(this, ecode, fmt, varg);
   va_end(varg);
   return retv;
}
inline void XmlRpcFault::setDynBuffer(DynBuffer* dynBuffer) {
   XmlRpcFault_setDynBuffer(this, dynBuffer); }
inline int XmlRpcFault::setError(int ecode,const char* msg) {
   return  XmlRpcFault_setError(this,ecode,msg); }
inline int XmlRpcFault::setMallocError() {
   return  XmlRpcFault_setMallocError(this); }
inline int XmlRpcFault::setReallocError() {
   return  XmlRpcFault_setReallocError(this); }
inline int XmlRpcFault::setTooFewParams() {
   return  XmlRpcFault_setTooFewParams(this); }
#endif


typedef struct XmlRpcVal
{
#ifdef __cplusplus
      
      S32 getInt(XmlRpcFault* fault);

      
      const char* getAsciiVal(XmlRpcFault* fault);

      
      bool isStructMember();

      
      XmlRpcElemType getType();

#ifndef NO_DOUBLE
      
      double getDouble(XmlRpcFault* fault);
#endif
      
      const char* getString(XmlRpcFault* fault);

      
      BaBool getBoolean(XmlRpcFault* fault);

      
      int getBase64(XmlRpcFault* fault, void** data);


      
      BaTime getDateTime(XmlRpcFault* fault);

      
      const char* getIso8601(XmlRpcFault* fault);

      
      const char* getMemberName();

      
      struct XmlRpcVal* getX(XmlRpcFault* fault);

      
      XmlRpcVal* getStruct(XmlRpcFault* fault);

      
      XmlRpcVal* getArray(XmlRpcFault* fault);


      
      S32 getLength(XmlRpcFault* fault);

      
      XmlRpcVal* getNextElem();

      
      XmlRpcVal* get(XmlRpcFault* fault,const char* fmt, ...);
#endif
      U8 elemType; 
      U8 magicNo;
      U16 valOffs;
      U16 nextElemOffs; 
      U16 nameOffs;
} XmlRpcVal;

#ifdef __cplusplus
extern "C" {
#endif
#define XmlRpcVal_isStructMember(o) ((o)->nameOffs != 0)
BA_API S32 XmlRpcVal_getInt(struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API const char* XmlRpcVal_getAsciiVal(
   struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API XmlRpcElemType XmlRpcVal_getType(struct XmlRpcVal* o);
#ifdef NO_DOUBLE
#define XmlRpcVal_getDouble XmlRpcVal_getInt
#else
BA_API double XmlRpcVal_getDouble(struct XmlRpcVal* o, XmlRpcFault* fault);
#endif
BA_API const char* XmlRpcVal_getString(
   struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API BaBool XmlRpcVal_getBoolean(struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API int XmlRpcVal_getBase64(
   struct XmlRpcVal* o, XmlRpcFault* fault, void** data);
BA_API BaTime XmlRpcVal_getDateTime(struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API const char* XmlRpcVal_getIso8601(XmlRpcVal* o, XmlRpcFault* fault);
BA_API const char* XmlRpcVal_getMemberName(struct XmlRpcVal* o);
BA_API struct XmlRpcVal* XmlRpcVal_getX(
   struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API struct XmlRpcVal* XmlRpcVal_getStruct(
   struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API struct XmlRpcVal* XmlRpcVal_getArray(
   struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API S32 XmlRpcVal_getLength(struct XmlRpcVal* o, XmlRpcFault* fault);
BA_API struct XmlRpcVal* XmlRpcVal_getNextElem(struct XmlRpcVal* o);
BA_API struct XmlRpcVal* XmlRpcVal_vget(
   struct XmlRpcVal* o,
   XmlRpcFault* fault,
   const char** fmt,
   va_list* argList);
BA_API struct XmlRpcVal* XmlRpcVal_get(
   struct XmlRpcVal* o,XmlRpcFault* fault,const char* fmt, ...);

#ifdef __cplusplus
}
inline bool XmlRpcVal::isStructMember() {
   return  XmlRpcVal_isStructMember(this); }
inline S32 XmlRpcVal::getInt(XmlRpcFault* fault) {
   return  XmlRpcVal_getInt(this, fault); }
inline const char* XmlRpcVal::getAsciiVal(XmlRpcFault* fault) {
   return  XmlRpcVal_getAsciiVal(this, fault); }
inline XmlRpcElemType XmlRpcVal::getType() {
   return  XmlRpcVal_getType(this); }
#ifndef NO_DOUBLE
inline double XmlRpcVal::getDouble(XmlRpcFault* fault) {
   return  XmlRpcVal_getDouble(this, fault); }
#endif
inline const char* XmlRpcVal::getString(XmlRpcFault* fault) {
   return  XmlRpcVal_getString(this, fault); }
inline BaBool XmlRpcVal::getBoolean(XmlRpcFault* fault) {
   return  XmlRpcVal_getBoolean(this, fault); }
inline int XmlRpcVal::getBase64(XmlRpcFault* fault, void** data) {
   return  XmlRpcVal_getBase64(this, fault, data); }
inline BaTime XmlRpcVal::getDateTime(XmlRpcFault* fault) {
   return  XmlRpcVal_getDateTime(this, fault); }
inline const char* XmlRpcVal::getIso8601(XmlRpcFault* fault) {
   return  XmlRpcVal_getIso8601(this, fault); }
inline const char* XmlRpcVal::getMemberName() {
   return  XmlRpcVal_getMemberName(this); }
inline struct XmlRpcVal* XmlRpcVal::getX(XmlRpcFault* fault) {
   return  XmlRpcVal_getX(this, fault); }
inline XmlRpcVal* XmlRpcVal::getStruct(XmlRpcFault* fault) {
   return  XmlRpcVal_getStruct(this, fault); }
inline XmlRpcVal* XmlRpcVal::getArray(XmlRpcFault* fault) {
   return  XmlRpcVal_getArray(this, fault); }
inline S32 XmlRpcVal::getLength(XmlRpcFault* fault) {
   return XmlRpcVal_getLength(this, fault);
}
inline XmlRpcVal* XmlRpcVal::getNextElem() {
   return  XmlRpcVal_getNextElem(this); }
inline XmlRpcVal* XmlRpcVal::get(XmlRpcFault* fault,const char* fmt, ...) {
   XmlRpcVal* retv; va_list argList;
   va_start(argList, fmt); 
   retv=XmlRpcVal_vget(this,fault,&fmt,&argList); 
   va_end(argList);
   return retv;
}
#endif



typedef struct XmlRpcFiber
{
#ifdef __cplusplus

      
      ThreadMutex* getMutex();

      
      XmlRpcVal* getFirstVal();

      
      HttpSession* getSession();

      
      AuthenticatedUser* getUser();

      

      U32 getSessionId();

      
      void terminate();
#endif
      HttpFiber super; 
      MqMessage mqNode;
      char* encoding;
      struct XmlRpcPage* page;
      U32 sessionId;
} XmlRpcFiber;

#ifdef __cplusplus
extern "C" {
#endif
#define XmlRpcFiber_getMutex(o) \
   SoDisp_getMutex(HttpConnection_getDispatcher((HttpConnection*)(o))) 
#define XmlRpcFiber_getFirstVal(o)  \
   ((XmlRpcVal*)(((U8*)HttpFiber_getData((HttpFiber*)(o))) + \
    *((U16*)HttpFiber_getData((HttpFiber*)(o)))))
#define XmlRpcFiber_getSessionId(o) (o)->sessionId
#define XmlRpcFiber_getSession(o) \
   HttpServer_getSession(HttpFiber_getServer((HttpFiber*)(o)), (o)->sessionId)
#define XmlRpcFiber_getUser(o) AuthenticatedUser_get2(XmlRpcFiber_getSession(o))
BA_API void XmlRpcFiber_terminate(XmlRpcFiber* o);
#ifdef __cplusplus
}
inline ThreadMutex* XmlRpcFiber::getMutex() {
   return XmlRpcFiber_getMutex(this);
}
inline XmlRpcVal* XmlRpcFiber::getFirstVal() {
   return XmlRpcFiber_getFirstVal(this); }
inline void XmlRpcFiber::terminate() {
   XmlRpcFiber_terminate(this); }
inline HttpSession* XmlRpcFiber::getSession() {
   return XmlRpcFiber_getSession(this); }
inline U32 XmlRpcFiber::getSessionId() {
   return XmlRpcFiber_getSessionId(this); }
inline AuthenticatedUser* XmlRpcFiber::getUser() {
   return XmlRpcFiber_getUser(this); }
#endif


#ifndef __DOXYGEN__
typedef struct
{
      char* nextPtr; 
      char* endPtr; 
      XmlRpcElemType curElem;
      BaBool emptyElem;
} ElemLexer;
#endif


typedef struct XmlRpcParser
{
#ifdef __cplusplus
      
      XmlRpcParser(char* buf, U16 size);
      
      int parse(XmlRpcVal** firstVal);
#endif
      ElemLexer lexer;
      char* encoding;
}XmlRpcParser;
 

#ifdef __cplusplus
extern "C" {
#endif
BA_API int XmlRpcParser_parseMethod(XmlRpcParser* o, XmlRpcVal** val, char** methodName);
BA_API void XmlRpcParser_constructor(XmlRpcParser* o, char* buf, U16 size);
BA_API int XmlRpcParser_parse(XmlRpcParser* o, XmlRpcVal** val);
#ifdef __cplusplus
}
inline XmlRpcParser::XmlRpcParser(char* buf, U16 size) {
   XmlRpcParser_constructor(this, buf, size);
}
inline int XmlRpcParser::parse(XmlRpcVal** val) {
   return XmlRpcParser_parse(this, val);
}

#endif




typedef struct XmlRpcSerializer
{
#ifdef __cplusplus
      
      XmlRpcSerializer(int startSize,int expandSize=0,AllocatorIntf* alloc=0);

      
      ~XmlRpcSerializer();

      
      const char* getXmlBuf();

      
      void erase();

      
      U32 getXmlBufSize();
      
      
      void sendResponse(XmlRpcFiber** fiber);

      
      int setInt(S32 val);
#ifndef NO_DOUBLE

      
      int setDouble(double val);
#endif

      
      int setString(const char* val);

      
      int setBoolean(bool val);

      
      int setBase64(const void* val, int len);

      
      int setDateTime(BaTime val);

      
      int setIso8601(const char* time);

      
      int setX(struct XmlRpcVal* val, bool iterateNext=false);

      
      int set(const char* fmt, ...);

      
      int setMemberName(const char* name);

      

      
      void setMultipleParam();

      
      int beginStruct();

      
      int endStruct();

      
      int beginArray();

      
      int endArray();

      
      XmlRpcFault* getFault();
#endif
      DynBuffer super; 
      XmlRpcFault fault;
      struct
      {
            U8 level;
            U8 data[8];
      }structStack;
      BaBool structMember;
      BaBool param; 
      BaBool multipleParamOK;
} XmlRpcSerializer;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void XmlRpcSerializer_constructor(
   XmlRpcSerializer* o,
   int startSize,
   int expandSize,
   AllocatorIntf* alloc);
BA_API void XmlRpcSerializer_destructor(XmlRpcSerializer* o);
BA_API void XmlRpcSerializer_erase(XmlRpcSerializer* o);
#define XmlRpcSerializer_getXmlBuf(o) (((BufPrint*)o)->buf)
#define XmlRpcSerializer_getXmlBufSize(o) (((BufPrint*)o)->cursor)
#define XmlRpcSerializer_getFault(o) (&(o)->fault)
BA_API void XmlRpcSerializer_sendResponse(
   XmlRpcSerializer* o, XmlRpcFiber** fiber);
BA_API int XmlRpcSerializer_setInt(XmlRpcSerializer* o, S32 val);
#ifdef NO_DOUBLE
#define XmlRpcSerializer_setDouble XmlRpcSerializer_setInt
#else
BA_API int XmlRpcSerializer_setDouble(XmlRpcSerializer* o, double val);
#endif
BA_API int XmlRpcSerializer_setString(XmlRpcSerializer* o, const char* val);
BA_API int XmlRpcSerializer_setBoolean(XmlRpcSerializer* o, BaBool val);
BA_API int XmlRpcSerializer_setBase64(
   XmlRpcSerializer* o, const void* val, int len);
BA_API int XmlRpcSerializer_setDateTime(XmlRpcSerializer* o, BaTime val);
BA_API int XmlRpcSerializer_setIso8601(XmlRpcSerializer* o, const char* time);
BA_API int XmlRpcSerializer_setX(
   XmlRpcSerializer* o, struct XmlRpcVal* val, BaBool iterateNext);
BA_API int XmlRpcSerializer_vset(
   XmlRpcSerializer* o,const char** fmt,va_list* argList);
BA_API int XmlRpcSerializer_set(XmlRpcSerializer* o, const char* fmt, ...);
BA_API int XmlRpcSerializer_setMemberName(
   XmlRpcSerializer* o, const char* name);
#define XmlRpcSerializer_setMultipleParam(o) (o)->multipleParamOK=TRUE
BA_API int XmlRpcSerializer_beginStruct(XmlRpcSerializer* o);
BA_API int XmlRpcSerializer_endStruct(XmlRpcSerializer* o);
BA_API int XmlRpcSerializer_beginArray(XmlRpcSerializer* o);
BA_API int XmlRpcSerializer_endArray(XmlRpcSerializer* o);
#ifdef __cplusplus
}
inline XmlRpcSerializer::XmlRpcSerializer(
   int startSize,int expandSize,AllocatorIntf* alloc) {
   XmlRpcSerializer_constructor(this,startSize,expandSize,alloc); }
inline XmlRpcSerializer::~XmlRpcSerializer() {
   XmlRpcSerializer_destructor(this); }
inline void XmlRpcSerializer::erase() {
   XmlRpcSerializer_erase(this); }
inline const char* XmlRpcSerializer::getXmlBuf() {
   return XmlRpcSerializer_getXmlBuf(this); }
inline U32 XmlRpcSerializer::getXmlBufSize() {
   return XmlRpcSerializer_getXmlBufSize(this);
}
inline void XmlRpcSerializer::sendResponse(XmlRpcFiber** fiber) {
   XmlRpcSerializer_sendResponse(this, fiber); }
inline int XmlRpcSerializer::setInt(S32 val) {
   return  XmlRpcSerializer_setInt(this, val); }
#ifndef NO_DOUBLE
inline int XmlRpcSerializer::setDouble(double val) {
   return  XmlRpcSerializer_setDouble(this, val); }
#endif
inline int XmlRpcSerializer::setString(const char* val) {
   return  XmlRpcSerializer_setString(this, val); }
inline int XmlRpcSerializer::setBoolean(bool val) {
   return  XmlRpcSerializer_setBoolean(this, val ? TRUE : FALSE); }
inline int XmlRpcSerializer::setBase64(const void* val, int len) {
   return  XmlRpcSerializer_setBase64(this, val, len); }
inline int XmlRpcSerializer::setDateTime(BaTime val) {
   return  XmlRpcSerializer_setDateTime(this, val); }
inline int XmlRpcSerializer::setIso8601(const char* time) {
   return  XmlRpcSerializer_setIso8601(this, time); }
inline int XmlRpcSerializer::setX(struct XmlRpcVal* val, bool iterateNext) {
   return  XmlRpcSerializer_setX(this,val,iterateNext?TRUE:FALSE); }
inline int XmlRpcSerializer::set(const char* fmt, ...) {
   int retv; va_list argList;
   va_start(argList, fmt); 
   retv=XmlRpcSerializer_vset(this,&fmt,&argList);
   va_end(argList);
   return retv;
}
inline int XmlRpcSerializer::setMemberName(const char* name) {
   return  XmlRpcSerializer_setMemberName(this, name); }
inline void XmlRpcSerializer::setMultipleParam() {
   XmlRpcSerializer_setMultipleParam(this);
}
inline int XmlRpcSerializer::beginStruct() {
   return  XmlRpcSerializer_beginStruct(this); }
inline int XmlRpcSerializer::endStruct() {
   return  XmlRpcSerializer_endStruct(this); }
inline int XmlRpcSerializer::beginArray() {
   return  XmlRpcSerializer_beginArray(this); }
inline int XmlRpcSerializer::endArray() {
   return  XmlRpcSerializer_endArray(this); }
inline XmlRpcFault* XmlRpcSerializer::getFault() {
   return XmlRpcSerializer_getFault(this); }
#endif


typedef struct XmlRpcPage
#ifdef __cplusplus
 : public HttpPage
{

      
      XmlRpcPage(const char* pageName,
                 int dynBufStartSize,
                 int dynBufExpandSize,
                 AllocatorIntf* pool=AllocatorIntf::getDefault(),
                 AllocatorIntf* alloc=AllocatorIntf::getDefault());

      
      void setMessageQueue(MqInterf* mq);
#if 0
}
#endif
#else
{
      HttpPage super; 
#endif
      SplayTree xmlRpcTree; 
      AllocatorIntf* pool;
      int dynBufStartSize;
      int dynBufExpandSize;
      AllocatorIntf* alloc;
      MqInterf* mq;
} XmlRpcPage;


#ifdef __cplusplus
extern "C" {
#endif
BA_API void XmlRpcPage_constructor(
   XmlRpcPage* o,
   const char* pageName,
   int dynBufStartSize,
   int dynBufExpandSize,
   AllocatorIntf* pool,
   AllocatorIntf* alloc);
#define XmlRpcPage_setMessageQueue(o, q) (o)->mq=q

#ifdef __cplusplus
}
inline XmlRpcPage::XmlRpcPage(
   const char* pageName,int dynBufStartSize,
   int dynBufExpandSize,AllocatorIntf* pool,AllocatorIntf* alloc) {
      XmlRpcPage_constructor(
         this,pageName,dynBufStartSize,dynBufExpandSize,pool,alloc);
}
inline void XmlRpcPage::setMessageQueue(MqInterf* mq) {
   XmlRpcPage_setMessageQueue(this, mq);
}
#endif



typedef struct XmlRpcObj
{
#ifdef __cplusplus
      

      XmlRpcObj(XmlRpcPage* xmlRpcResource, const char* name,
             const struct XmlRpcMethod* methods, int methodsSize);
      ~XmlRpcObj();
      const char* getName();
#endif
      SplayTreeNode super; 

      XmlRpcPage* parentPage;
      const struct XmlRpcMethod* methods;
      int methodsSize;

} XmlRpcObj;
#ifdef __cplusplus
extern "C" {
#endif
BA_API void XmlRpcObj_constructor(
   XmlRpcObj* o,
   XmlRpcPage* parentPage,
   const char* name,
   const struct XmlRpcMethod* methods,
   int methodsSize);
BA_API void XmlRpcObj_destructor(XmlRpcObj* o);
#define XmlRpcObj_getName(o) \
   ((const char*)SplayTreeNode_getKey((SplayTreeNode*)(o)))
#ifdef __cplusplus
}
inline XmlRpcObj::XmlRpcObj(
   XmlRpcPage* parentPage,const char* name,const struct XmlRpcMethod* methods,
   int methodsSize) {
     XmlRpcObj_constructor(this,parentPage,name,methods,methodsSize);
}
inline XmlRpcObj::~XmlRpcObj() {
     XmlRpcObj_destructor(this); }
inline const char* XmlRpcObj::getName() {
   return XmlRpcObj_getName(this); }
#endif


typedef XmlRpcFiber* (*XmlRpcMethodCB)(
   XmlRpcObj* rpc, XmlRpcFiber* fiber, XmlRpcSerializer* serializer);


    
typedef struct XmlRpcMethod
{
        const char* methodName;
      XmlRpcMethodCB rpc;
} XmlRpcMethod;



 

#endif



#ifndef __xparser_h
#define __xparser_h


#ifndef XPARSER_ALLOC
#define XPARSER_ALLOC 2
#endif

#ifdef __cplusplus
extern "C" {
#endif


   struct xparser_context;
   typedef struct xparser_context xparser;


   enum xparser_event {
      
      xparserNOEVENT = 0,
      
      xparserINIT,            
      xparserRESET,           
      xparserTERM,            
      xparserSTART,           
      
      xparserXML,             
      xparserSTART_ELEMENT,   
      xparserEND_ELEMENT,     
      xparserEMPTY_ELEMENT,   
      xparserPI,              
      xparserCOMMENT,         
      xparserCDATA,           
      xparserTEXT,            
      xparserLAST             
   };
   typedef enum xparser_event xparser_event;

   
   extern const char* const xparser_eventname[xparserLAST];



   typedef int (*xparser_callback)(
      xparser* parser,
      void* userdata,
      xparser_event event,
      const char* name, 
      const char** attr, 
      const char* data); 

   typedef xparser_callback xparser_handlers[xparserLAST];



   enum xparser_textmode {xparserPRESERVE=0,xparserSKIPBLANK=1,xparserTRIM=2};


   xparser* xparser_create(void);



   int xparser_init(xparser* parser, xparser_handlers* handlers, void* userdata,unsigned int options);




   int xparser_term(xparser* parser);



   void xparser_destroy(xparser* parser);



   int xparser_reset(xparser* parser, int full);



   int xparser_parse(xparser* parser,const char* pData, size_t datalen);


   const char* xparser_errormsg(xparser* parser);  
   unsigned int xparser_line(xparser* parser);     
   unsigned int xparser_col(xparser* parser);      
   size_t xparser_count(xparser* parser);          
   unsigned int xparser_depth(xparser* parser);    
   unsigned int xparser_flags(xparser* parser);    
   int xparser_has_doc(xparser* parser);           
   void* xparser_userdata(xparser* parser);        


#ifdef __DOXYGEN__


#else

 

#endif  

#if XPARSER_ALLOC

   typedef void * (*xparser_alloc) (
      void *ud, 
      void *ptr, 
      size_t osize, 
      size_t nsize); 


   void xparser_setalloc(xparser_alloc pa,void* ud);

#endif

#ifdef __cplusplus
}
#endif



#endif


#ifndef ldebug_h
#define ldebug_h




#ifndef lstate_h
#define lstate_h




#ifndef lobject_h
#define lobject_h




#ifndef llimits_h
#define llimits_h


typedef unsigned LUA_INT32 lu_int32;

typedef LUAI_UMEM lu_mem;

typedef LUAI_MEM l_mem;




typedef unsigned char lu_byte;


#define MAX_SIZET	((size_t)(~(size_t)0)-2)

#define MAX_LUMEM	((lu_mem)(~(lu_mem)0)-2)

#define MAX_LMEM	((l_mem) ((MAX_LUMEM >> 1) - 2))


#define MAX_INT (INT_MAX-2)  


#define IntPoint(p)  ((unsigned int)(lu_mem)(p))




#if !defined(LUAI_USER_ALIGNMENT_T)
#define LUAI_USER_ALIGNMENT_T	union { double u; void *s; long l; }
#endif

typedef LUAI_USER_ALIGNMENT_T L_Umaxalign;



typedef LUAI_UACNUMBER l_uacNumber;



#if defined(lua_assert)
#define check_exp(c,e)		(lua_assert(c), (e))

#define lua_longassert(c)	{ if (!(c)) lua_assert(0); }
#else
#define lua_assert(c)		((void)0)
#define check_exp(c,e)		(e)
#define lua_longassert(c)	((void)0)
#endif


#if !defined(luai_apicheck)

#if defined(LUA_USE_APICHECK)
#define luai_apicheck(L,e)	assert(e)
#else
#define luai_apicheck(L,e)	lua_assert(e)
#endif

#endif

#define api_check(l,e,msg)	luai_apicheck(l,(e) && msg)


#if !defined(UNUSED)
#define UNUSED(x)	((void)(x))	
#endif


#define cast(t, exp)	((t)(exp))

#define cast_byte(i)	cast(lu_byte, (i))
#define cast_num(i)	cast(lua_Number, (i))
#define cast_int(i)	cast(int, (i))
#define cast_uchar(i)	cast(unsigned char, (i))



#if defined(__GNUC__)
#define l_noret		void __attribute__((noreturn))
#elif defined(_MSC_VER)
#define l_noret		void __declspec(noreturn)
#else
#define l_noret		void
#endif




#if !defined(LUAI_MAXCCALLS)
#define LUAI_MAXCCALLS		200
#endif


#define MAXUPVAL	UCHAR_MAX



typedef lu_int32 Instruction;




#define MAXSTACK	250




#if !defined(MINSTRTABSIZE)
#define MINSTRTABSIZE	32
#endif



#if !defined(LUA_MINBUFFER)
#define LUA_MINBUFFER	32
#endif


#if !defined(lua_lock)
#define lua_lock(L)     ((void) 0)
#define lua_unlock(L)   ((void) 0)
#endif

#if !defined(luai_threadyield)
#define luai_threadyield(L)     {lua_unlock(L); lua_lock(L);}
#endif



#if !defined(luai_userstateopen)
#define luai_userstateopen(L)		((void)L)
#endif

#if !defined(luai_userstateclose)
#define luai_userstateclose(L)		((void)L)
#endif

#if !defined(luai_userstatethread)
#define luai_userstatethread(L,L1)	((void)L)
#endif

#if !defined(luai_userstatefree)
#define luai_userstatefree(L,L1)	((void)L)
#endif

#if !defined(luai_userstateresume)
#define luai_userstateresume(L,n)       ((void)L)
#endif

#if !defined(luai_userstateyield)
#define luai_userstateyield(L,n)        ((void)L)
#endif



#ifndef LUA_NUMBER_INTEGER

#if defined(MS_ASMTRICK) || defined(LUA_MSASMTRICK)	


#define lua_number2int(i,n)  __asm {__asm fld n   __asm fistp i}
#define lua_number2integer(i,n)		lua_number2int(i, n)
#define lua_number2unsigned(i,n)  \
  {__int64 l; __asm {__asm fld n   __asm fistp l} i = (unsigned int)l;}


#elif defined(LUA_IEEE754TRICK)		


union luai_Cast { double l_d; LUA_INT32 l_p[2]; };

#if !defined(LUA_IEEEENDIAN)	
#define LUAI_EXTRAIEEE	\
  static const union luai_Cast ieeeendian = {-(33.0 + 6755399441055744.0)};
#define LUA_IEEEENDIANLOC	(ieeeendian.l_p[1] == 33)
#else
#define LUA_IEEEENDIANLOC	LUA_IEEEENDIAN
#define LUAI_EXTRAIEEE		
#endif				

#define lua_number2int32(i,n,t) \
  { LUAI_EXTRAIEEE \
    volatile union luai_Cast u; u.l_d = (n) + 6755399441055744.0; \
    (i) = (t)u.l_p[LUA_IEEEENDIANLOC]; }

#define luai_hashnum(i,n)  \
  { volatile union luai_Cast u; u.l_d = (n) + 1.0;   \
    (i) = u.l_p[0]; (i) += u.l_p[1]; }  

#define lua_number2int(i,n)		lua_number2int32(i, n, int)
#define lua_number2unsigned(i,n)	lua_number2int32(i, n, lua_Unsigned)


#if defined(LUA_IEEELL)
#define lua_number2integer(i,n)		lua_number2int32(i, n, lua_Integer)
#endif

#endif				

#endif 



#if !defined(lua_number2int)
#define lua_number2int(i,n)	((i)=(int)(n))
#endif

#if !defined(lua_number2integer)
#define lua_number2integer(i,n)	((i)=(lua_Integer)(n))
#endif

#if !defined(lua_number2unsigned)	

#if defined(LUA_NUMBER_DOUBLE) || defined(LUA_NUMBER_FLOAT)
#define SUPUNSIGNED	((lua_Number)(~(lua_Unsigned)0) + 1)
#define lua_number2unsigned(i,n)  \
	((i)=(lua_Unsigned)((n) - floor((n)/SUPUNSIGNED)*SUPUNSIGNED))
#else
#define lua_number2unsigned(i,n)	((i)=(lua_Unsigned)(n))
#endif
#endif				


#if !defined(lua_unsigned2number)

#define lua_unsigned2number(u)  \
    (((u) <= (lua_Unsigned)INT_MAX) ? (lua_Number)(int)(u) : (lua_Number)(u))
#endif



#if defined(ltable_c) && !defined(luai_hashnum)

#define luai_hashnum(i,n) { int e;  \
  n = l_mathop(frexp)(n, &e) * (lua_Number)(INT_MAX - DBL_MAX_EXP);  \
  lua_number2int(i, n); i += e; }

#endif




#if !defined(HARDSTACKTESTS)
#define condmovestack(L)	((void)0)
#else

#define condmovestack(L)	luaD_reallocstack((L), (L)->stacksize)
#endif

#if !defined(HARDMEMTESTS)
#define condchangemem(L)	condmovestack(L)
#else
#define condchangemem(L)  \
	((void)(!(G(L)->gcrunning) || (luaC_fullgc(L, 0), 1)))
#endif

#endif
#define LUA_TPROTO	LUA_NUMTAGS
#define LUA_TUPVAL	(LUA_NUMTAGS+1)
#define LUA_TDEADKEY	(LUA_NUMTAGS+2)


#define LUA_TOTALTAGS	(LUA_TUPVAL+2)




#define VARBITS		(3 << 4)





#define LUA_TLCL	(LUA_TFUNCTION | (0 << 4))  
#define LUA_TLCF	(LUA_TFUNCTION | (1 << 4))  
#define LUA_TCCL	(LUA_TFUNCTION | (2 << 4))  



#define LUA_TSHRSTR	(LUA_TSTRING | (0 << 4))  
#define LUA_TLNGSTR	(LUA_TSTRING | (1 << 4))  



#define BIT_ISCOLLECTABLE	(1 << 6)


#define ctb(t)			((t) | BIT_ISCOLLECTABLE)



typedef union GCObject GCObject;



#define CommonHeader	GCObject *next; lu_byte tt; lu_byte marked



typedef struct GCheader {
  CommonHeader;
} GCheader;




typedef union LValue LValue;


#define numfield	lua_Number n;    





#define TValuefields	LValue value_; int tt_

typedef struct lua_TValue TValue;



#define NILCONSTANT	{NULL}, LUA_TNIL


#define val_(o)		((o)->value_)
#define num_(o)		(val_(o).n)



#define rttype(o)	((o)->tt_)


#define novariant(x)	((x) & 0x0F)


#define ttype(o)	(rttype(o) & 0x3F)


#define ttypenv(o)	(novariant(rttype(o)))



#define checktag(o,t)		(rttype(o) == (t))
#define checktype(o,t)		(ttypenv(o) == (t))
#define ttisnumber(o)		checktag((o), LUA_TNUMBER)
#define ttisnil(o)		checktag((o), LUA_TNIL)
#define ttisboolean(o)		checktag((o), LUA_TBOOLEAN)
#define ttislightuserdata(o)	checktag((o), LUA_TLIGHTUSERDATA)
#define ttisstring(o)		checktype((o), LUA_TSTRING)
#define ttisshrstring(o)	checktag((o), ctb(LUA_TSHRSTR))
#define ttislngstring(o)	checktag((o), ctb(LUA_TLNGSTR))
#define ttistable(o)		checktag((o), ctb(LUA_TTABLE))
#define ttisfunction(o)		checktype(o, LUA_TFUNCTION)
#define ttisclosure(o)		((rttype(o) & 0x1F) == LUA_TFUNCTION)
#define ttisCclosure(o)		checktag((o), ctb(LUA_TCCL))
#define ttisLclosure(o)		checktag((o), ctb(LUA_TLCL))
#define ttislcf(o)		checktag((o), LUA_TLCF)
#define ttisuserdata(o)		checktag((o), ctb(LUA_TUSERDATA))
#define ttisthread(o)		checktag((o), ctb(LUA_TTHREAD))
#define ttisdeadkey(o)		checktag((o), LUA_TDEADKEY)

#define ttisequal(o1,o2)	(rttype(o1) == rttype(o2))


#define nvalue(o)	check_exp(ttisnumber(o), num_(o))
#define gcvalue(o)	check_exp(iscollectable(o), val_(o).gc)
#define pvalue(o)	check_exp(ttislightuserdata(o), val_(o).p)
#define rawtsvalue(o)	check_exp(ttisstring(o), &val_(o).gc->ts)
#define tsvalue(o)	(&rawtsvalue(o)->tsv)
#define rawuvalue(o)	check_exp(ttisuserdata(o), &val_(o).gc->u)
#define uvalue(o)	(&rawuvalue(o)->uv)
#define clvalue(o)	check_exp(ttisclosure(o), &val_(o).gc->cl)
#define clLvalue(o)	check_exp(ttisLclosure(o), &val_(o).gc->cl.l)
#define clCvalue(o)	check_exp(ttisCclosure(o), &val_(o).gc->cl.c)
#define fvalue(o)	check_exp(ttislcf(o), val_(o).f)
#define hvalue(o)	check_exp(ttistable(o), &val_(o).gc->h)
#define bvalue(o)	check_exp(ttisboolean(o), val_(o).b)
#define thvalue(o)	check_exp(ttisthread(o), &val_(o).gc->th)

#define deadvalue(o)	check_exp(ttisdeadkey(o), cast(void *, val_(o).gc))

#define l_isfalse(o)	(ttisnil(o) || (ttisboolean(o) && bvalue(o) == 0))


#define iscollectable(o)	(rttype(o) & BIT_ISCOLLECTABLE)



#define righttt(obj)		(ttype(obj) == gcvalue(obj)->gch.tt)

#define checkliveness(g,obj) \
	lua_longassert(!iscollectable(obj) || \
			(righttt(obj) && !isdead(g,gcvalue(obj))))



#define settt_(o,t)	((o)->tt_=(t))

#define setnvalue(obj,x) \
  { TValue *io=(obj); num_(io)=(x); settt_(io, LUA_TNUMBER); }

#define setnilvalue(obj) settt_(obj, LUA_TNIL)

#define setfvalue(obj,x) \
  { TValue *io=(obj); val_(io).f=(x); settt_(io, LUA_TLCF); }

#define setpvalue(obj,x) \
  { TValue *io=(obj); val_(io).p=(x); settt_(io, LUA_TLIGHTUSERDATA); }

#define setbvalue(obj,x) \
  { TValue *io=(obj); val_(io).b=(x); settt_(io, LUA_TBOOLEAN); }

#define setgcovalue(L,obj,x) \
  { TValue *io=(obj); GCObject *i_g=(x); \
    val_(io).gc=i_g; settt_(io, ctb(gch(i_g)->tt)); }

#define setsvalue(L,obj,x) \
  { TValue *io=(obj); \
    TString *x_ = (x); \
    val_(io).gc=cast(GCObject *, x_); settt_(io, ctb(x_->tsv.tt)); \
    checkliveness(G(L),io); }

#define setuvalue(L,obj,x) \
  { TValue *io=(obj); \
    val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TUSERDATA)); \
    checkliveness(G(L),io); }

#define setthvalue(L,obj,x) \
  { TValue *io=(obj); \
    val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TTHREAD)); \
    checkliveness(G(L),io); }

#define setclLvalue(L,obj,x) \
  { TValue *io=(obj); \
    val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TLCL)); \
    checkliveness(G(L),io); }

#define setclCvalue(L,obj,x) \
  { TValue *io=(obj); \
    val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TCCL)); \
    checkliveness(G(L),io); }

#define sethvalue(L,obj,x) \
  { TValue *io=(obj); \
    val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TTABLE)); \
    checkliveness(G(L),io); }

#define setdeadvalue(obj)	settt_(obj, LUA_TDEADKEY)



#define setobj(L,obj1,obj2) \
	{ const TValue *io2=(obj2); TValue *io1=(obj1); \
	  io1->value_ = io2->value_; io1->tt_ = io2->tt_; \
	  checkliveness(G(L),io1); }





#define setobjs2s	setobj

#define setobj2s	setobj
#define setsvalue2s	setsvalue
#define sethvalue2s	sethvalue
#define setptvalue2s	setptvalue

#define setobjt2t	setobj

#define setobj2t	setobj

#define setobj2n	setobj
#define setsvalue2n	setsvalue



#define luai_checknum(L,o,c)	{  }



#if defined(LUA_NANTRICK)




#if !defined(NNMARK)	


#if !defined(LUA_IEEEENDIAN)
#error option 'LUA_NANTRICK' needs 'LUA_IEEEENDIAN'
#endif


#define NNMARK		0x7FF7A500
#define NNMASK		0x7FFFFF00

#undef TValuefields
#undef NILCONSTANT

#if (LUA_IEEEENDIAN == 0)	


#define TValuefields  \
	union { struct { LValue v__; int tt__; } i; double d__; } u
#define NILCONSTANT	{{{NULL}, tag2tt(LUA_TNIL)}}

#define v_(o)		((o)->u.i.v__)
#define d_(o)		((o)->u.d__)
#define tt_(o)		((o)->u.i.tt__)

#else				


#define TValuefields  \
	union { struct { int tt__; LValue v__; } i; double d__; } u
#define NILCONSTANT	{{tag2tt(LUA_TNIL), {NULL}}}

#define v_(o)		((o)->u.i.v__)
#define d_(o)		((o)->u.d__)
#define tt_(o)		((o)->u.i.tt__)

#endif				

#endif			



#undef val_
#define val_(o)		v_(o)
#undef num_
#define num_(o)		d_(o)


#undef numfield
#define numfield	


#undef ttisnumber
#define ttisnumber(o)	((tt_(o) & NNMASK) != NNMARK)

#define tag2tt(t)	(NNMARK | (t))

#undef rttype
#define rttype(o)	(ttisnumber(o) ? LUA_TNUMBER : tt_(o) & 0xff)

#undef settt_
#define settt_(o,t)	(tt_(o) = tag2tt(t))

#undef setnvalue
#define setnvalue(obj,x) \
	{ TValue *io_=(obj); num_(io_)=(x); lua_assert(ttisnumber(io_)); }

#undef setobj
#define setobj(L,obj1,obj2) \
	{ const TValue *o2_=(obj2); TValue *o1_=(obj1); \
	  o1_->u = o2_->u; \
	  checkliveness(G(L),o1_); }




#undef checktag
#undef checktype
#define checktag(o,t)	(tt_(o) == tag2tt(t))
#define checktype(o,t)	(ctb(tt_(o) | VARBITS) == ctb(tag2tt(t) | VARBITS))

#undef ttisequal
#define ttisequal(o1,o2)  \
	(ttisnumber(o1) ? ttisnumber(o2) : (tt_(o1) == tt_(o2)))


#undef luai_checknum
#define luai_checknum(L,o,c)	{ if (!ttisnumber(o)) c; }

#endif







union LValue {
  GCObject *gc;    
  void *p;         
  int b;           
  lua_CFunction f; 
  numfield         
};


struct lua_TValue {
  TValuefields;
};


typedef TValue *StkId;  





typedef union TString {
  L_Umaxalign dummy;  
  struct {
    CommonHeader;
    lu_byte extra;  
    unsigned int hash;
    size_t len;  
  } tsv;
} TString;



#define getstr(ts)	cast(const char *, (ts) + 1)


#define svalue(o)       getstr(rawtsvalue(o))



typedef union Udata {
  L_Umaxalign dummy;  
  struct {
    CommonHeader;
    struct Table *metatable;
    struct Table *env;
    size_t len;  
  } uv;
} Udata;




typedef struct Upvaldesc {
  TString *name;  
  lu_byte instack;  
  lu_byte idx;  
} Upvaldesc;



typedef struct LocVar {
  TString *varname;
  int startpc;  
  int endpc;    
} LocVar;



typedef struct Proto {
  CommonHeader;
  TValue *k;  
  Instruction *code;
  struct Proto **p;  
  int *lineinfo;  
  LocVar *locvars;  
  Upvaldesc *upvalues;  
  union Closure *cache;  
  TString  *source;  
  int sizeupvalues;  
  int sizek;  
  int sizecode;
  int sizelineinfo;
  int sizep;  
  int sizelocvars;
  int linedefined;
  int lastlinedefined;
  GCObject *gclist;
  lu_byte numparams;  
  lu_byte is_vararg;
  lu_byte maxstacksize;  
} Proto;




typedef struct UpVal {
  CommonHeader;
  TValue *v;  
  union {
    TValue value;  
    struct {  
      struct UpVal *prev;
      struct UpVal *next;
    } l;
  } u;
} UpVal;




#define ClosureHeader \
	CommonHeader; lu_byte nupvalues; GCObject *gclist

typedef struct CClosure {
  ClosureHeader;
  lua_CFunction f;
  TValue upvalue[1];  
} CClosure;


typedef struct LClosure {
  ClosureHeader;
  struct Proto *p;
  UpVal *upvals[1];  
} LClosure;


typedef union Closure {
  CClosure c;
  LClosure l;
} Closure;


#define isLfunction(o)	ttisLclosure(o)

#define getproto(o)	(clLvalue(o)->p)




typedef union TKey {
  struct {
    TValuefields;
    struct Node *next;  
  } nk;
  TValue tvk;
} TKey;


typedef struct Node {
  TValue i_val;
  TKey i_key;
} Node;


typedef struct Table {
  CommonHeader;
  lu_byte flags;  
  lu_byte lsizenode;  
  struct Table *metatable;
  TValue *array;  
  Node *node;
  Node *lastfree;  
  GCObject *gclist;
  int sizearray;  
} Table;




#define lmod(s,size) \
	(check_exp((size&(size-1))==0, (cast(int, (s) & ((size)-1)))))


#define twoto(x)	(1<<(x))
#define sizenode(t)	(twoto((t)->lsizenode))



#define luaO_nilobject		(&luaO_nilobject_)


LUAI_DDEC const TValue luaO_nilobject_;


LUAI_FUNC int luaO_int2fb (unsigned int x);
LUAI_FUNC int luaO_fb2int (int x);
LUAI_FUNC int luaO_ceillog2 (unsigned int x);
LUAI_FUNC lua_Number luaO_arith (int op, lua_Number v1, lua_Number v2);
LUAI_FUNC int luaO_str2d (const char *s, size_t len, lua_Number *result);
LUAI_FUNC int luaO_hexavalue (int c);
LUAI_FUNC const char *luaO_pushvfstring (lua_State *L, const char *fmt,
                                                       va_list argp);
LUAI_FUNC const char *luaO_pushfstring (lua_State *L, const char *fmt, ...);
LUAI_FUNC void luaO_chunkid (char *out, const char *source, size_t len);


#endif



#ifndef ltm_h
#define ltm_h


typedef enum {
  TM_INDEX,
  TM_NEWINDEX,
  TM_GC,
  TM_MODE,
  TM_LEN,
  TM_EQ,  
  TM_ADD,
  TM_SUB,
  TM_MUL,
  TM_DIV,
  TM_MOD,
  TM_POW,
  TM_UNM,
  TM_LT,
  TM_LE,
  TM_CONCAT,
  TM_CALL,
  TM_N		
} TMS;



#define gfasttm(g,et,e) ((et) == NULL ? NULL : \
  ((et)->flags & (1u<<(e))) ? NULL : luaT_gettm(et, e, (g)->tmname[e]))

#define fasttm(l,et,e)	gfasttm(G(l), et, e)

#define ttypename(x)	luaT_typenames_[(x) + 1]
#define objtypename(x)	ttypename(ttypenv(x))

LUAI_DDEC const char *const luaT_typenames_[LUA_TOTALTAGS];


LUAI_FUNC const TValue *luaT_gettm (Table *events, TMS event, TString *ename);
LUAI_FUNC const TValue *luaT_gettmbyobj (lua_State *L, const TValue *o,
                                                       TMS event);
LUAI_FUNC void luaT_init (lua_State *L);

#endif



#ifndef lzio_h
#define lzio_h



#ifndef lmem_h
#define lmem_h


#define luaM_reallocv(L,b,on,n,e) \
  (cast(void, \
     (cast(size_t, (n)+1) > MAX_SIZET/(e)) ? (luaM_toobig(L), 0) : 0), \
   luaM_realloc_(L, (b), (on)*(e), (n)*(e)))

#define luaM_freemem(L, b, s)	luaM_realloc_(L, (b), (s), 0)
#define luaM_free(L, b)		luaM_realloc_(L, (b), sizeof(*(b)), 0)
#define luaM_freearray(L, b, n)   luaM_reallocv(L, (b), n, 0, sizeof((b)[0]))

#define luaM_malloc(L,s)	luaM_realloc_(L, NULL, 0, (s))
#define luaM_new(L,t)		cast(t *, luaM_malloc(L, sizeof(t)))
#define luaM_newvector(L,n,t) \
		cast(t *, luaM_reallocv(L, NULL, 0, n, sizeof(t)))

#define luaM_newobject(L,tag,s)	luaM_realloc_(L, NULL, tag, (s))

#define luaM_growvector(L,v,nelems,size,t,limit,e) \
          if ((nelems)+1 > (size)) \
            ((v)=cast(t *, luaM_growaux_(L,v,&(size),sizeof(t),limit,e)))

#define luaM_reallocvector(L, v,oldn,n,t) \
   ((v)=cast(t *, luaM_reallocv(L, v, oldn, n, sizeof(t))))

LUAI_FUNC l_noret luaM_toobig (lua_State *L);


LUAI_FUNC void *luaM_realloc_ (lua_State *L, void *block, size_t oldsize,
                                                          size_t size);
LUAI_FUNC void *luaM_growaux_ (lua_State *L, void *block, int *size,
                               size_t size_elem, int limit,
                               const char *what);

#endif

#define EOZ	(-1)			

typedef struct Zio ZIO;

#define zgetc(z)  (((z)->n--)>0 ?  cast_uchar(*(z)->p++) : luaZ_fill(z))


typedef struct Mbuffer {
  char *buffer;
  size_t n;
  size_t buffsize;
} Mbuffer;

#define luaZ_initbuffer(L, buff) ((buff)->buffer = NULL, (buff)->buffsize = 0)

#define luaZ_buffer(buff)	((buff)->buffer)
#define luaZ_sizebuffer(buff)	((buff)->buffsize)
#define luaZ_bufflen(buff)	((buff)->n)

#define luaZ_resetbuffer(buff) ((buff)->n = 0)


#define luaZ_resizebuffer(L, buff, size) \
	(luaM_reallocvector(L, (buff)->buffer, (buff)->buffsize, size, char), \
	(buff)->buffsize = size)

#define luaZ_freebuffer(L, buff)	luaZ_resizebuffer(L, buff, 0)


LUAI_FUNC char *luaZ_openspace (lua_State *L, Mbuffer *buff, size_t n);
LUAI_FUNC void luaZ_init (lua_State *L, ZIO *z, lua_Reader reader,
                                        void *data);
LUAI_FUNC size_t luaZ_read (ZIO* z, void* b, size_t n);	





struct Zio {
  size_t n;			
  const char *p;		
  lua_Reader reader;		
  void* data;			
  lua_State *L;			
};


LUAI_FUNC int luaZ_fill (ZIO *z);

#endif
struct lua_longjmp;  




#define EXTRA_STACK   5


#define BASIC_STACK_SIZE        (2*LUA_MINSTACK)



#define KGC_NORMAL	0
#define KGC_EMERGENCY	1	
#define KGC_GEN		2	


typedef struct stringtable {
  GCObject **hash;
  lu_int32 nuse;  
  int size;
} stringtable;



typedef struct CallInfo {
  StkId func;  
  StkId	top;  
  struct CallInfo *previous, *next;  
  short nresults;  
  lu_byte callstatus;
  ptrdiff_t extra;
  union {
    struct {  
      StkId base;  
      const Instruction *savedpc;
    } l;
    struct {  
      int ctx;  
      lua_CFunction k;  
      ptrdiff_t old_errfunc;
      lu_byte old_allowhook;
      lu_byte status;
    } c;
  } u;
} CallInfo;



#define CIST_LUA	(1<<0)	
#define CIST_HOOKED	(1<<1)	
#define CIST_REENTRY	(1<<2)	
#define CIST_YIELDED	(1<<3)	
#define CIST_YPCALL	(1<<4)	
#define CIST_STAT	(1<<5)	
#define CIST_TAIL	(1<<6)	
#define CIST_HOOKYIELD	(1<<7)	


#define isLua(ci)	((ci)->callstatus & CIST_LUA)



typedef struct global_State {
  lua_Alloc frealloc;  
  void *ud;         
  lu_mem totalbytes;  
  l_mem GCdebt;  
  lu_mem GCmemtrav;  
  lu_mem GCestimate;  
  stringtable strt;  
  TValue l_registry;
  unsigned int seed;  
  lu_byte currentwhite;
  lu_byte gcstate;  
  lu_byte gckind;  
  lu_byte gcrunning;  
  int sweepstrgc;  
  GCObject *allgc;  
  GCObject *finobj;  
  GCObject **sweepgc;  
  GCObject **sweepfin;  
  GCObject *gray;  
  GCObject *grayagain;  
  GCObject *weak;  
  GCObject *ephemeron;  
  GCObject *allweak;  
  GCObject *tobefnz;  
  UpVal uvhead;  
  Mbuffer buff;  
  int gcpause;  
  int gcmajorinc;  
  int gcstepmul;  
  lua_CFunction panic;  
  struct lua_State *mainthread;
  const lua_Number *version;  
  TString *memerrmsg;  
  TString *tmname[TM_N];  
  struct Table *mt[LUA_NUMTAGS];  
} global_State;



struct lua_State {
  CommonHeader;
  lu_byte status;
  StkId top;  
  global_State *l_G;
  CallInfo *ci;  
  const Instruction *oldpc;  
  StkId stack_last;  
  StkId stack;  
  int stacksize;
  unsigned short nny;  
  unsigned short nCcalls;  
  lu_byte hookmask;
  lu_byte allowhook;
  int basehookcount;
  int hookcount;
  lua_Hook hook;
  GCObject *openupval;  
  GCObject *gclist;
  struct lua_longjmp *errorJmp;  
  ptrdiff_t errfunc;  
  CallInfo base_ci;  
};


#define G(L)	(L->l_G)



union GCObject {
  GCheader gch;  
  union TString ts;
  union Udata u;
  union Closure cl;
  struct Table h;
  struct Proto p;
  struct UpVal uv;
  struct lua_State th;  
};


#define gch(o)		(&(o)->gch)


#define rawgco2ts(o)  \
	check_exp(novariant((o)->gch.tt) == LUA_TSTRING, &((o)->ts))
#define gco2ts(o)	(&rawgco2ts(o)->tsv)
#define rawgco2u(o)	check_exp((o)->gch.tt == LUA_TUSERDATA, &((o)->u))
#define gco2u(o)	(&rawgco2u(o)->uv)
#define gco2lcl(o)	check_exp((o)->gch.tt == LUA_TLCL, &((o)->cl.l))
#define gco2ccl(o)	check_exp((o)->gch.tt == LUA_TCCL, &((o)->cl.c))
#define gco2cl(o)  \
	check_exp(novariant((o)->gch.tt) == LUA_TFUNCTION, &((o)->cl))
#define gco2t(o)	check_exp((o)->gch.tt == LUA_TTABLE, &((o)->h))
#define gco2p(o)	check_exp((o)->gch.tt == LUA_TPROTO, &((o)->p))
#define gco2uv(o)	check_exp((o)->gch.tt == LUA_TUPVAL, &((o)->uv))
#define gco2th(o)	check_exp((o)->gch.tt == LUA_TTHREAD, &((o)->th))


#define obj2gco(v)	(cast(GCObject *, (v)))



#define gettotalbytes(g)	((g)->totalbytes + (g)->GCdebt)

LUAI_FUNC void luaE_setdebt (global_State *g, l_mem debt);
LUAI_FUNC void luaE_freethread (lua_State *L, lua_State *L1);
LUAI_FUNC CallInfo *luaE_extendCI (lua_State *L);
LUAI_FUNC void luaE_freeCI (lua_State *L);


#endif

#define pcRel(pc, p)	(cast(int, (pc) - (p)->code) - 1)

#define getfuncline(f,pc)	(((f)->lineinfo) ? (f)->lineinfo[pc] : 0)

#define resethookcount(L)	(L->hookcount = L->basehookcount)


#define ci_func(ci)		(clLvalue((ci)->func))


LUAI_FUNC l_noret luaG_typeerror (lua_State *L, const TValue *o,
                                                const char *opname);
LUAI_FUNC l_noret luaG_concaterror (lua_State *L, StkId p1, StkId p2);
LUAI_FUNC l_noret luaG_aritherror (lua_State *L, const TValue *p1,
                                                 const TValue *p2);
LUAI_FUNC l_noret luaG_ordererror (lua_State *L, const TValue *p1,
                                                 const TValue *p2);
LUAI_FUNC l_noret luaG_runerror (lua_State *L, const char *fmt, ...);
LUAI_FUNC l_noret luaG_errormsg (lua_State *L);

#endif


#ifndef ldo_h
#define ldo_h


#define luaD_checkstack(L,n)	if (L->stack_last - L->top <= (n)) \
				    luaD_growstack(L, n); else condmovestack(L);


#define incr_top(L) {L->top++; luaD_checkstack(L,0);}

#define savestack(L,p)		((char *)(p) - (char *)L->stack)
#define restorestack(L,n)	((TValue *)((char *)L->stack + (n)))



typedef void (*Pfunc) (lua_State *L, void *ud);

LUAI_FUNC int luaD_protectedparser (lua_State *L, ZIO *z, const char *name,
                                                  const char *mode);
LUAI_FUNC void luaD_hook (lua_State *L, int event, int line);
LUAI_FUNC int luaD_precall (lua_State *L, StkId func, int nresults);
LUAI_FUNC void luaD_call (lua_State *L, StkId func, int nResults,
                                        int allowyield);
LUAI_FUNC int luaD_pcall (lua_State *L, Pfunc func, void *u,
                                        ptrdiff_t oldtop, ptrdiff_t ef);
LUAI_FUNC int luaD_poscall (lua_State *L, StkId firstResult);
LUAI_FUNC void luaD_reallocstack (lua_State *L, int newsize);
LUAI_FUNC void luaD_growstack (lua_State *L, int n);
LUAI_FUNC void luaD_shrinkstack (lua_State *L);

LUAI_FUNC l_noret luaD_throw (lua_State *L, int errcode);
LUAI_FUNC int luaD_rawrunprotected (lua_State *L, Pfunc f, void *ud);

#endif



#ifndef lgc_h
#define lgc_h


#if !defined(GCSTEPSIZE)

#define GCSTEPSIZE	(cast_int(100 * sizeof(TString)))
#endif



#define GCSpropagate	0
#define GCSatomic	1
#define GCSsweepstring	2
#define GCSsweepudata	3
#define GCSsweep	4
#define GCSpause	5


#define issweepphase(g)  \
	(GCSsweepstring <= (g)->gcstate && (g)->gcstate <= GCSsweep)

#define isgenerational(g)	((g)->gckind == KGC_GEN)



#define keepinvariant(g)	(isgenerational(g) || g->gcstate <= GCSatomic)



#define keepinvariantout(g)  \
  check_exp(g->gcstate == GCSpropagate || !isgenerational(g),  \
            g->gcstate <= GCSatomic)



#define resetbits(x,m)		((x) &= cast(lu_byte, ~(m)))
#define setbits(x,m)		((x) |= (m))
#define testbits(x,m)		((x) & (m))
#define bitmask(b)		(1<<(b))
#define bit2mask(b1,b2)		(bitmask(b1) | bitmask(b2))
#define l_setbit(x,b)		setbits(x, bitmask(b))
#define resetbit(x,b)		resetbits(x, bitmask(b))
#define testbit(x,b)		testbits(x, bitmask(b))



#define WHITE0BIT	0  
#define WHITE1BIT	1  
#define BLACKBIT	2  
#define FINALIZEDBIT	3  
#define SEPARATED	4  
#define FIXEDBIT	5  
#define OLDBIT		6  


#define WHITEBITS	bit2mask(WHITE0BIT, WHITE1BIT)


#define iswhite(x)      testbits((x)->gch.marked, WHITEBITS)
#define isblack(x)      testbit((x)->gch.marked, BLACKBIT)
#define isgray(x)    \
	(!testbits((x)->gch.marked, WHITEBITS | bitmask(BLACKBIT)))

#define isold(x)	testbit((x)->gch.marked, OLDBIT)


#define resetoldbit(o)	resetbit((o)->gch.marked, OLDBIT)

#define otherwhite(g)	(g->currentwhite ^ WHITEBITS)
#define isdeadm(ow,m)	(!(((m) ^ WHITEBITS) & (ow)))
#define isdead(g,v)	isdeadm(otherwhite(g), (v)->gch.marked)

#define changewhite(x)	((x)->gch.marked ^= WHITEBITS)
#define gray2black(x)	l_setbit((x)->gch.marked, BLACKBIT)

#define valiswhite(x)	(iscollectable(x) && iswhite(gcvalue(x)))

#define luaC_white(g)	cast(lu_byte, (g)->currentwhite & WHITEBITS)


#define luaC_condGC(L,c) \
	{if (G(L)->GCdebt > 0) {c;}; condchangemem(L);}
#define luaC_checkGC(L)		luaC_condGC(L, luaC_step(L);)


#define luaC_barrier(L,p,v) { if (valiswhite(v) && isblack(obj2gco(p)))  \
	luaC_barrier_(L,obj2gco(p),gcvalue(v)); }

#define luaC_barrierback(L,p,v) { if (valiswhite(v) && isblack(obj2gco(p)))  \
	luaC_barrierback_(L,p); }

#define luaC_objbarrier(L,p,o)  \
	{ if (iswhite(obj2gco(o)) && isblack(obj2gco(p))) \
		luaC_barrier_(L,obj2gco(p),obj2gco(o)); }

#define luaC_objbarrierback(L,p,o)  \
   { if (iswhite(obj2gco(o)) && isblack(obj2gco(p))) luaC_barrierback_(L,p); }

#define luaC_barrierproto(L,p,c) \
   { if (isblack(obj2gco(p))) luaC_barrierproto_(L,p,c); }

LUAI_FUNC void luaC_freeallobjects (lua_State *L);
LUAI_FUNC void luaC_step (lua_State *L);
LUAI_FUNC void luaC_forcestep (lua_State *L);
LUAI_FUNC void luaC_runtilstate (lua_State *L, int statesmask);
LUAI_FUNC void luaC_fullgc (lua_State *L, int isemergency);
LUAI_FUNC GCObject *luaC_newobj (lua_State *L, int tt, size_t sz,
                                 GCObject **list, int offset);
LUAI_FUNC void luaC_barrier_ (lua_State *L, GCObject *o, GCObject *v);
LUAI_FUNC void luaC_barrierback_ (lua_State *L, GCObject *o);
LUAI_FUNC void luaC_barrierproto_ (lua_State *L, Proto *p, Closure *c);
LUAI_FUNC void luaC_checkfinalizer (lua_State *L, GCObject *o, Table *mt);
LUAI_FUNC void luaC_checkupvalcolor (global_State *g, UpVal *uv);
LUAI_FUNC void luaC_changemode (lua_State *L, int mode);

#endif


#ifndef lstring_h
#define lstring_h

#define sizestring(s)	(sizeof(union TString)+((s)->len+1)*sizeof(char))

#define sizeudata(u)	(sizeof(union Udata)+(u)->len)

#define luaS_newliteral(L, s)	(luaS_newlstr(L, "" s, \
                                 (sizeof(s)/sizeof(char))-1))

#define luaS_fix(s)	l_setbit((s)->tsv.marked, FIXEDBIT)



#define isreserved(s)	((s)->tsv.tt == LUA_TSHRSTR && (s)->tsv.extra > 0)



#define eqshrstr(a,b)	check_exp((a)->tsv.tt == LUA_TSHRSTR, (a) == (b))


LUAI_FUNC unsigned int luaS_hash (const char *str, size_t l, unsigned int seed);
LUAI_FUNC int luaS_eqlngstr (TString *a, TString *b);
LUAI_FUNC int luaS_eqstr (TString *a, TString *b);
LUAI_FUNC void luaS_resize (lua_State *L, int newsize);
LUAI_FUNC Udata *luaS_newudata (lua_State *L, size_t s, Table *e);
LUAI_FUNC TString *luaS_newlstr (lua_State *L, const char *str, size_t l);
LUAI_FUNC TString *luaS_new (lua_State *L, const char *str);


#endif


#ifndef ltable_h
#define ltable_h

#define gnode(t,i)	(&(t)->node[i])
#define gkey(n)		(&(n)->i_key.tvk)
#define gval(n)		(&(n)->i_val)
#define gnext(n)	((n)->i_key.nk.next)

#define invalidateTMcache(t)	((t)->flags = 0)


LUAI_FUNC const TValue *luaH_getint (Table *t, int key);
LUAI_FUNC void luaH_setint (lua_State *L, Table *t, int key, TValue *value);
LUAI_FUNC const TValue *luaH_getstr (Table *t, TString *key);
LUAI_FUNC const TValue *luaH_get (Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_newkey (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_set (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC Table *luaH_new (lua_State *L);
LUAI_FUNC void luaH_resize (lua_State *L, Table *t, int nasize, int nhsize);
LUAI_FUNC void luaH_resizearray (lua_State *L, Table *t, int nasize);
LUAI_FUNC void luaH_free (lua_State *L, Table *t);
LUAI_FUNC int luaH_next (lua_State *L, Table *t, StkId key);
LUAI_FUNC int luaH_getn (Table *t);


#if defined(LUA_DEBUG)
LUAI_FUNC Node *luaH_mainposition (const Table *t, const TValue *key);
LUAI_FUNC int luaH_isdummy (Node *n);
#endif


#endif


#ifndef lvm_h
#define lvm_h


#define tostring(L,o) (ttisstring(o) || (luaV_tostring(L, o)))

#define tonumber(o,n)	(ttisnumber(o) || (((o) = luaV_tonumber(o,n)) != NULL))

#define equalobj(L,o1,o2)  (ttisequal(o1, o2) && luaV_equalobj_(L, o1, o2))

#define luaV_rawequalobj(o1,o2)		equalobj(NULL,o1,o2)



LUAI_FUNC int luaV_equalobj_ (lua_State *L, const TValue *t1, const TValue *t2);


LUAI_FUNC int luaV_lessthan (lua_State *L, const TValue *l, const TValue *r);
LUAI_FUNC int luaV_lessequal (lua_State *L, const TValue *l, const TValue *r);
LUAI_FUNC const TValue *luaV_tonumber (const TValue *obj, TValue *n);
LUAI_FUNC int luaV_tostring (lua_State *L, StkId obj);
LUAI_FUNC void luaV_gettable (lua_State *L, const TValue *t, TValue *key,
                                            StkId val);
LUAI_FUNC void luaV_settable (lua_State *L, const TValue *t, TValue *key,
                                            StkId val);
LUAI_FUNC void luaV_finishOp (lua_State *L);
LUAI_FUNC void luaV_execute (lua_State *L);
LUAI_FUNC void luaV_concat (lua_State *L, int total);
LUAI_FUNC void luaV_arith (lua_State *L, StkId ra, const TValue *rb,
                           const TValue *rc, TMS op);
LUAI_FUNC void luaV_objlen (lua_State *L, StkId ra, const TValue *rb);

#endif


#ifndef lapi_h
#define lapi_h


#define api_incr_top(L)   {L->top++; api_check(L, L->top <= L->ci->top, \
				"stack overflow");}

#define adjustresults(L,nres) \
    { if ((nres) == LUA_MULTRET && L->ci->top < L->top) L->ci->top = L->top; }

#define api_checknelems(L,n)	api_check(L, (n) < (L->top - L->ci->func), \
				  "not enough elements in the stack")


#endif


#ifndef lfunc_h
#define lfunc_h


#define sizeCclosure(n)	(cast(int, sizeof(CClosure)) + \
                         cast(int, sizeof(TValue)*((n)-1)))

#define sizeLclosure(n)	(cast(int, sizeof(LClosure)) + \
                         cast(int, sizeof(TValue *)*((n)-1)))


LUAI_FUNC Proto *luaF_newproto (lua_State *L);
LUAI_FUNC Closure *luaF_newCclosure (lua_State *L, int nelems);
LUAI_FUNC Closure *luaF_newLclosure (lua_State *L, int nelems);
LUAI_FUNC UpVal *luaF_newupval (lua_State *L);
LUAI_FUNC UpVal *luaF_findupval (lua_State *L, StkId level);
LUAI_FUNC void luaF_close (lua_State *L, StkId level);
LUAI_FUNC void luaF_freeproto (lua_State *L, Proto *f);
LUAI_FUNC void luaF_freeupval (lua_State *L, UpVal *uv);
LUAI_FUNC const char *luaF_getlocalname (const Proto *func, int local_number,
                                         int pc);


#endif


#ifndef lundump_h
#define lundump_h

LUAI_FUNC Closure* luaU_undump (lua_State* L, ZIO* Z, Mbuffer* buff, const char* name);


LUAI_FUNC void luaU_header (lu_byte* h);


LUAI_FUNC int luaU_dump (lua_State* L, const Proto* f, lua_Writer w, void* data, int strip);


#define LUAC_TAIL		"\x19\x93\r\n\x1a\n"


#define LUAC_HEADERSIZE		(sizeof(LUA_SIGNATURE)-sizeof(char)+2+6+sizeof(LUAC_TAIL)-sizeof(char))

#endif


#ifndef lcode_h
#define lcode_h



#ifndef llex_h
#define llex_h

#define FIRST_RESERVED	257




enum RESERVED {
  
  TK_AND = FIRST_RESERVED, TK_BREAK,
  TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR, TK_FUNCTION,
  TK_GOTO, TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT,
  TK_RETURN, TK_THEN, TK_TRUE, TK_UNTIL, TK_WHILE,
  
  TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE, TK_DBCOLON, TK_EOS,
  TK_NUMBER, TK_NAME, TK_STRING
};


#define NUM_RESERVED	(cast(int, TK_WHILE-FIRST_RESERVED+1))


typedef union {
  lua_Number r;
  TString *ts;
} SemInfo;  


typedef struct Token {
  int token;
  SemInfo seminfo;
} Token;



typedef struct LexState {
  int current;  
  int linenumber;  
  int lastline;  
  Token t;  
  Token lookahead;  
  struct FuncState *fs;  
  struct lua_State *L;
  ZIO *z;  
  Mbuffer *buff;  
  struct Dyndata *dyd;  
  TString *source;  
  TString *envn;  
  char decpoint;  
} LexState;


LUAI_FUNC void luaX_init (lua_State *L);
LUAI_FUNC void luaX_setinput (lua_State *L, LexState *ls, ZIO *z,
                              TString *source, int firstchar);
LUAI_FUNC TString *luaX_newstring (LexState *ls, const char *str, size_t l);
LUAI_FUNC void luaX_next (LexState *ls);
LUAI_FUNC int luaX_lookahead (LexState *ls);
LUAI_FUNC l_noret luaX_syntaxerror (LexState *ls, const char *s);
LUAI_FUNC const char *luaX_token2str (LexState *ls, int token);


#endif


#ifndef lopcodes_h
#define lopcodes_h

enum OpMode {iABC, iABx, iAsBx, iAx};  



#define SIZE_C		9
#define SIZE_B		9
#define SIZE_Bx		(SIZE_C + SIZE_B)
#define SIZE_A		8
#define SIZE_Ax		(SIZE_C + SIZE_B + SIZE_A)

#define SIZE_OP		6

#define POS_OP		0
#define POS_A		(POS_OP + SIZE_OP)
#define POS_C		(POS_A + SIZE_A)
#define POS_B		(POS_C + SIZE_C)
#define POS_Bx		POS_C
#define POS_Ax		POS_A



#if SIZE_Bx < LUAI_BITSINT-1
#define MAXARG_Bx        ((1<<SIZE_Bx)-1)
#define MAXARG_sBx        (MAXARG_Bx>>1)         
#else
#define MAXARG_Bx        MAX_INT
#define MAXARG_sBx        MAX_INT
#endif

#if SIZE_Ax < LUAI_BITSINT-1
#define MAXARG_Ax	((1<<SIZE_Ax)-1)
#else
#define MAXARG_Ax	MAX_INT
#endif


#define MAXARG_A        ((1<<SIZE_A)-1)
#define MAXARG_B        ((1<<SIZE_B)-1)
#define MAXARG_C        ((1<<SIZE_C)-1)



#define MASK1(n,p)	((~((~(Instruction)0)<<(n)))<<(p))


#define MASK0(n,p)	(~MASK1(n,p))



#define GET_OPCODE(i)	(cast(OpCode, ((i)>>POS_OP) & MASK1(SIZE_OP,0)))
#define SET_OPCODE(i,o)	((i) = (((i)&MASK0(SIZE_OP,POS_OP)) | \
		((cast(Instruction, o)<<POS_OP)&MASK1(SIZE_OP,POS_OP))))

#define getarg(i,pos,size)	(cast(int, ((i)>>pos) & MASK1(size,0)))
#define setarg(i,v,pos,size)	((i) = (((i)&MASK0(size,pos)) | \
                ((cast(Instruction, v)<<pos)&MASK1(size,pos))))

#define GETARG_A(i)	getarg(i, POS_A, SIZE_A)
#define SETARG_A(i,v)	setarg(i, v, POS_A, SIZE_A)

#define GETARG_B(i)	getarg(i, POS_B, SIZE_B)
#define SETARG_B(i,v)	setarg(i, v, POS_B, SIZE_B)

#define GETARG_C(i)	getarg(i, POS_C, SIZE_C)
#define SETARG_C(i,v)	setarg(i, v, POS_C, SIZE_C)

#define GETARG_Bx(i)	getarg(i, POS_Bx, SIZE_Bx)
#define SETARG_Bx(i,v)	setarg(i, v, POS_Bx, SIZE_Bx)

#define GETARG_Ax(i)	getarg(i, POS_Ax, SIZE_Ax)
#define SETARG_Ax(i,v)	setarg(i, v, POS_Ax, SIZE_Ax)

#define GETARG_sBx(i)	(GETARG_Bx(i)-MAXARG_sBx)
#define SETARG_sBx(i,b)	SETARG_Bx((i),cast(unsigned int, (b)+MAXARG_sBx))


#define CREATE_ABC(o,a,b,c)	((cast(Instruction, o)<<POS_OP) \
			| (cast(Instruction, a)<<POS_A) \
			| (cast(Instruction, b)<<POS_B) \
			| (cast(Instruction, c)<<POS_C))

#define CREATE_ABx(o,a,bc)	((cast(Instruction, o)<<POS_OP) \
			| (cast(Instruction, a)<<POS_A) \
			| (cast(Instruction, bc)<<POS_Bx))

#define CREATE_Ax(o,a)		((cast(Instruction, o)<<POS_OP) \
			| (cast(Instruction, a)<<POS_Ax))





#define BITRK		(1 << (SIZE_B - 1))


#define ISK(x)		((x) & BITRK)


#define INDEXK(r)	((int)(r) & ~BITRK)

#define MAXINDEXRK	(BITRK - 1)


#define RKASK(x)	((x) | BITRK)



#define NO_REG		MAXARG_A







typedef enum {

OP_MOVE,
OP_LOADK,
OP_LOADKX,
OP_LOADBOOL,
OP_LOADNIL,
OP_GETUPVAL,

OP_GETTABUP,
OP_GETTABLE,

OP_SETTABUP,
OP_SETUPVAL,
OP_SETTABLE,

OP_NEWTABLE,

OP_SELF,

OP_ADD,
OP_SUB,
OP_MUL,
OP_DIV,
OP_MOD,
OP_POW,
OP_UNM,
OP_NOT,
OP_LEN,

OP_CONCAT,

OP_JMP,
OP_EQ,
OP_LT,
OP_LE,

OP_TEST,
OP_TESTSET,

OP_CALL,
OP_TAILCALL,
OP_RETURN,

OP_FORLOOP,
OP_FORPREP,

OP_TFORCALL,
OP_TFORLOOP,

OP_SETLIST,

OP_CLOSURE,

OP_VARARG,

OP_EXTRAARG
} OpCode;


#define NUM_OPCODES	(cast(int, OP_EXTRAARG) + 1)








enum OpArgMask {
  OpArgN,  
  OpArgU,  
  OpArgR,  
  OpArgK   
};

LUAI_DDEC const lu_byte luaP_opmodes[NUM_OPCODES];

#define getOpMode(m)	(cast(enum OpMode, luaP_opmodes[m] & 3))
#define getBMode(m)	(cast(enum OpArgMask, (luaP_opmodes[m] >> 4) & 3))
#define getCMode(m)	(cast(enum OpArgMask, (luaP_opmodes[m] >> 2) & 3))
#define testAMode(m)	(luaP_opmodes[m] & (1 << 6))
#define testTMode(m)	(luaP_opmodes[m] & (1 << 7))


LUAI_DDEC const char *const luaP_opnames[NUM_OPCODES+1];  



#define LFIELDS_PER_FLUSH	50


#endif


#ifndef lparser_h
#define lparser_h

typedef enum {
  VVOID,	
  VNIL,
  VTRUE,
  VFALSE,
  VK,		
  VKNUM,	
  VNONRELOC,	
  VLOCAL,	
  VUPVAL,       
  VINDEXED,	
  VJMP,		
  VRELOCABLE,	
  VCALL,	
  VVARARG	
} expkind;


#define vkisvar(k)	(VLOCAL <= (k) && (k) <= VINDEXED)
#define vkisinreg(k)	((k) == VNONRELOC || (k) == VLOCAL)

typedef struct expdesc {
  expkind k;
  union {
    struct {  
      short idx;  
      lu_byte t;  
      lu_byte vt;  
    } ind;
    int info;  
    lua_Number nval;  
  } u;
  int t;  
  int f;  
} expdesc;



typedef struct Vardesc {
  short idx;  
} Vardesc;



typedef struct Labeldesc {
  TString *name;  
  int pc;  
  int line;  
  lu_byte nactvar;  
} Labeldesc;



typedef struct Labellist {
  Labeldesc *arr;  
  int n;  
  int size;  
} Labellist;



typedef struct Dyndata {
  struct {  
    Vardesc *arr;
    int n;
    int size;
  } actvar;
  Labellist gt;  
  Labellist label;   
} Dyndata;



struct BlockCnt;  



typedef struct FuncState {
  Proto *f;  
  Table *h;  
  struct FuncState *prev;  
  struct LexState *ls;  
  struct BlockCnt *bl;  
  int pc;  
  int lasttarget;   
  int jpc;  
  int nk;  
  int np;  
  int firstlocal;  
  short nlocvars;  
  lu_byte nactvar;  
  lu_byte nups;  
  lu_byte freereg;  
} FuncState;


LUAI_FUNC Closure *luaY_parser (lua_State *L, ZIO *z, Mbuffer *buff,
                                Dyndata *dyd, const char *name, int firstchar);


#endif
#define NO_JUMP (-1)



typedef enum BinOpr {
  OPR_ADD, OPR_SUB, OPR_MUL, OPR_DIV, OPR_MOD, OPR_POW,
  OPR_CONCAT,
  OPR_EQ, OPR_LT, OPR_LE,
  OPR_NE, OPR_GT, OPR_GE,
  OPR_AND, OPR_OR,
  OPR_NOBINOPR
} BinOpr;


typedef enum UnOpr { OPR_MINUS, OPR_NOT, OPR_LEN, OPR_NOUNOPR } UnOpr;


#define getcode(fs,e)	((fs)->f->code[(e)->u.info])

#define luaK_codeAsBx(fs,o,A,sBx)	luaK_codeABx(fs,o,A,(sBx)+MAXARG_sBx)

#define luaK_setmultret(fs,e)	luaK_setreturns(fs, e, LUA_MULTRET)

#define luaK_jumpto(fs,t)	luaK_patchlist(fs, luaK_jump(fs), t)

LUAI_FUNC int luaK_codeABx (FuncState *fs, OpCode o, int A, unsigned int Bx);
LUAI_FUNC int luaK_codeABC (FuncState *fs, OpCode o, int A, int B, int C);
LUAI_FUNC int luaK_codek (FuncState *fs, int reg, int k);
LUAI_FUNC void luaK_fixline (FuncState *fs, int line);
LUAI_FUNC void luaK_nil (FuncState *fs, int from, int n);
LUAI_FUNC void luaK_reserveregs (FuncState *fs, int n);
LUAI_FUNC void luaK_checkstack (FuncState *fs, int n);
LUAI_FUNC int luaK_stringK (FuncState *fs, TString *s);
LUAI_FUNC int luaK_numberK (FuncState *fs, lua_Number r);
LUAI_FUNC void luaK_dischargevars (FuncState *fs, expdesc *e);
LUAI_FUNC int luaK_exp2anyreg (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_exp2anyregup (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_exp2nextreg (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_exp2val (FuncState *fs, expdesc *e);
LUAI_FUNC int luaK_exp2RK (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_self (FuncState *fs, expdesc *e, expdesc *key);
LUAI_FUNC void luaK_indexed (FuncState *fs, expdesc *t, expdesc *k);
LUAI_FUNC void luaK_goiftrue (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_goiffalse (FuncState *fs, expdesc *e);
LUAI_FUNC void luaK_storevar (FuncState *fs, expdesc *var, expdesc *e);
LUAI_FUNC void luaK_setreturns (FuncState *fs, expdesc *e, int nresults);
LUAI_FUNC void luaK_setoneret (FuncState *fs, expdesc *e);
LUAI_FUNC int luaK_jump (FuncState *fs);
LUAI_FUNC void luaK_ret (FuncState *fs, int first, int nret);
LUAI_FUNC void luaK_patchlist (FuncState *fs, int list, int target);
LUAI_FUNC void luaK_patchtohere (FuncState *fs, int list);
LUAI_FUNC void luaK_patchclose (FuncState *fs, int list, int level);
LUAI_FUNC void luaK_concat (FuncState *fs, int *l1, int l2);
LUAI_FUNC int luaK_getlabel (FuncState *fs);
LUAI_FUNC void luaK_prefix (FuncState *fs, UnOpr op, expdesc *v, int line);
LUAI_FUNC void luaK_infix (FuncState *fs, BinOpr op, expdesc *v);
LUAI_FUNC void luaK_posfix (FuncState *fs, BinOpr op, expdesc *v1,
                            expdesc *v2, int line);
LUAI_FUNC void luaK_setlist (FuncState *fs, int base, int nelems, int tostore);


#endif


#ifndef lctype_h
#define lctype_h

#if !defined(LUA_USE_CTYPE)

#if 'A' == 65 && '0' == 48

#define LUA_USE_CTYPE	0
#else

#define LUA_USE_CTYPE	1
#endif

#endif


#if !LUA_USE_CTYPE	

#define ALPHABIT	0
#define DIGITBIT	1
#define PRINTBIT	2
#define SPACEBIT	3
#define XDIGITBIT	4


#define MASK(B)		(1 << (B))



#define testprop(c,p)	(luai_ctype_[(c)+1] & (p))


#define lislalpha(c)	testprop(c, MASK(ALPHABIT))
#define lislalnum(c)	testprop(c, (MASK(ALPHABIT) | MASK(DIGITBIT)))
#define lisdigit(c)	testprop(c, MASK(DIGITBIT))
#define lisspace(c)	testprop(c, MASK(SPACEBIT))
#define lisprint(c)	testprop(c, MASK(PRINTBIT))
#define lisxdigit(c)	testprop(c, MASK(XDIGITBIT))


#define ltolower(c)	((c) | ('A' ^ 'a'))



LUAI_DDEC const lu_byte luai_ctype_[UCHAR_MAX + 2];


#else			



#define lislalpha(c)	(isalpha(c) || (c) == '_')
#define lislalnum(c)	(isalnum(c) || (c) == '_')
#define lisdigit(c)	(isdigit(c))
#define lisspace(c)	(isspace(c))
#define lisprint(c)	(isprint(c))
#define lisxdigit(c)	(isxdigit(c))

#define ltolower(c)	(tolower(c))

#endif			

#endif



#ifndef _luaintfint_h
#define _luaintfint_h



#ifdef USE_AMALGAMATED_BAS
#else
#endif

#ifndef ThreadLib_hpp
struct ThreadMutex;
#endif

struct BasFuncs;
struct BaTimer;

typedef lua_State *(*Tlua_newstate) (lua_Alloc f, void *ud);
typedef void       (*Tlua_close) (lua_State *L);
typedef lua_State *(*Tlua_newthread) (lua_State *L);
typedef lua_CFunction (*Tlua_atpanic) (lua_State *L, lua_CFunction panicf);
typedef const lua_Number *(*Tlua_version) (lua_State *L);
typedef int   (*Tlua_absindex) (lua_State *L, int idx);
typedef int   (*Tlua_gettop) (lua_State *L);
typedef void  (*Tlua_settop) (lua_State *L, int idx);
typedef void  (*Tlua_pushvalue) (lua_State *L, int idx);
typedef void  (*Tlua_remove) (lua_State *L, int idx);
typedef void  (*Tlua_insert) (lua_State *L, int idx);
typedef void  (*Tlua_replace) (lua_State *L, int idx);
typedef void  (*Tlua_copy) (lua_State *L, int fromidx, int toidx);
typedef int   (*Tlua_checkstack) (lua_State *L, int sz);
typedef void  (*Tlua_xmove) (lua_State *from, lua_State *to, int n);
typedef int             (*Tlua_isnumber) (lua_State *L, int idx);
typedef int             (*Tlua_isstring) (lua_State *L, int idx);
typedef int             (*Tlua_iscfunction) (lua_State *L, int idx);
typedef int             (*Tlua_isuserdata) (lua_State *L, int idx);
typedef int             (*Tlua_type) (lua_State *L, int idx);
typedef const char     *(*Tlua_typename) (lua_State *L, int tp);
typedef lua_Number      (*Tlua_tonumberx) (lua_State *L, int idx, int *isnum);
typedef lua_Integer     (*Tlua_tointegerx) (lua_State *L, int idx, int *isnum);
typedef lua_Unsigned    (*Tlua_tounsignedx) (lua_State *L, int idx, int *isnum);
typedef int             (*Tlua_toboolean) (lua_State *L, int idx);
typedef const char     *(*Tlua_tolstring) (lua_State *L, int idx, size_t *len);
typedef size_t          (*Tlua_rawlen) (lua_State *L, int idx);
typedef lua_CFunction   (*Tlua_tocfunction) (lua_State *L, int idx);
typedef void	       *(*Tlua_touserdata) (lua_State *L, int idx);
typedef lua_State      *(*Tlua_tothread) (lua_State *L, int idx);
typedef const void     *(*Tlua_topointer) (lua_State *L, int idx);
typedef void  (*Tlua_arith) (lua_State *L, int op);
typedef int   (*Tlua_rawequal) (lua_State *L, int idx1, int idx2);
typedef int   (*Tlua_compare) (lua_State *L, int idx1, int idx2, int op);
typedef void        (*Tlua_pushnil) (lua_State *L);
typedef void        (*Tlua_pushnumber) (lua_State *L, lua_Number n);
typedef void        (*Tlua_pushinteger) (lua_State *L, lua_Integer n);
typedef void        (*Tlua_pushunsigned) (lua_State *L, lua_Unsigned n);
typedef const char *(*Tlua_pushlstring) (lua_State *L, const char *s, size_t l);
typedef const char *(*Tlua_pushstring) (lua_State *L, const char *s);
typedef const char *(*Tlua_pushvfstring) (lua_State *L, const char *fmt,
                                          va_list argp);
typedef void  (*Tlua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
typedef void  (*Tlua_pushboolean) (lua_State *L, int b);
typedef void  (*Tlua_pushlightuserdata) (lua_State *L, void *p);
typedef int   (*Tlua_pushthread) (lua_State *L);
typedef void  (*Tlua_getglobal) (lua_State *L, const char *var);
typedef void  (*Tlua_gettable) (lua_State *L, int idx);
typedef void  (*Tlua_getfield) (lua_State *L, int idx, const char *k);
typedef void  (*Tlua_rawget) (lua_State *L, int idx);
typedef void  (*Tlua_rawgeti) (lua_State *L, int idx, int n);
typedef void  (*Tlua_rawgetp) (lua_State *L, int idx, const void *p);
typedef void  (*Tlua_createtable) (lua_State *L, int narr, int nrec);
typedef void *(*Tlua_newuserdata) (lua_State *L, size_t sz);
typedef int   (*Tlua_getmetatable) (lua_State *L, int objindex);
typedef void  (*Tlua_getuservalue) (lua_State *L, int idx);
typedef void  (*Tlua_setglobal) (lua_State *L, const char *var);
typedef void  (*Tlua_settable) (lua_State *L, int idx);
typedef void  (*Tlua_setfield) (lua_State *L, int idx, const char *k);
typedef void  (*Tlua_rawset) (lua_State *L, int idx);
typedef void  (*Tlua_rawseti) (lua_State *L, int idx, int n);
typedef void  (*Tlua_rawsetp) (lua_State *L, int idx, const void *p);
typedef int   (*Tlua_setmetatable) (lua_State *L, int objindex);
typedef void  (*Tlua_setuservalue) (lua_State *L, int idx);
typedef void  (*Tlua_callk) (lua_State *L, int nargs, int nresults, int ctx,
                             lua_CFunction k);
typedef int   (*Tlua_getctx) (lua_State *L, int *ctx);
typedef int   (*Tlua_pcallk) (
   lua_State *L, int nargs, int nresults, int errfunc,
   int ctx, lua_CFunction k);
typedef int   (*Tlua_load) (lua_State *L, lua_Reader reader, void *dt,
                            const char *chunkname,
                            const char *mode);
typedef int (*Tlua_dump) (lua_State *L, lua_Writer writer, void *data);
typedef int  (*Tlua_yieldk) (lua_State *L, int nresults, int ctx,
                             lua_CFunction k);
typedef int  (*Tlua_resume) (lua_State *L, lua_State *from, int narg);
typedef int  (*Tlua_status) (lua_State *L);
typedef int (*Tlua_gc) (lua_State *L, int what, int data);
typedef int   (*Tlua_error) (lua_State *L);
typedef int   (*Tlua_next) (lua_State *L, int idx);
typedef void  (*Tlua_concat) (lua_State *L, int n);
typedef void  (*Tlua_len)    (lua_State *L, int idx);
typedef lua_Alloc (*Tlua_getallocf) (lua_State *L, void **ud);
typedef void      (*Tlua_setallocf) (lua_State *L, lua_Alloc f, void *ud);
typedef int (*Tlua_getstack) (lua_State *L, int level, lua_Debug *ar);
typedef int (*Tlua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
typedef const char *(*Tlua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
typedef const char *(*Tlua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
typedef const char *(*Tlua_getupvalue) (lua_State *L, int funcindex, int n);
typedef const char *(*Tlua_setupvalue) (lua_State *L, int funcindex, int n);
typedef void *(*Tlua_upvalueid) (lua_State *L, int fidx, int n);
typedef void  (*Tlua_upvaluejoin) (lua_State *L, int fidx1, int n1,
                                   int fidx2, int n2);
typedef int (*Tlua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
typedef lua_Hook (*Tlua_gethook) (lua_State *L);
typedef int (*Tlua_gethookmask) (lua_State *L);
typedef int (*Tlua_gethookcount) (lua_State *L);
typedef int (*Tluaopen_base) (lua_State *L);
typedef int (*Tluaopen_coroutine) (lua_State *L);
typedef int (*Tluaopen_table) (lua_State *L);
typedef int (*Tluaopen_io) (lua_State *L);
typedef int (*Tluaopen_os) (lua_State *L);
typedef int (*Tluaopen_string) (lua_State *L);
typedef int (*Tluaopen_bit32) (lua_State *L);
typedef int (*Tluaopen_math) (lua_State *L);
typedef int (*Tluaopen_debug) (lua_State *L);
typedef int (*Tluaopen_package) (lua_State *L);
typedef void (*TluaL_checkversion_) (lua_State *L, lua_Number ver);
typedef int (*TluaL_getmetafield) (lua_State *L, int obj, const char *e);
typedef int (*TluaL_callmeta) (lua_State *L, int obj, const char *e);
typedef const char *(*TluaL_tolstring) (lua_State *L, int idx, size_t *len);
typedef int (*TluaL_argerror) (lua_State *L, int numarg, const char *extramsg);
typedef const char *(*TluaL_checklstring) (lua_State *L, int numArg,
                                           size_t *l);
typedef const char *(*TluaL_optlstring) (lua_State *L, int numArg,
                                         const char *def, size_t *l);
typedef lua_Number (*TluaL_checknumber) (lua_State *L, int numArg);
typedef lua_Number (*TluaL_optnumber) (lua_State *L, int nArg, lua_Number def);
typedef lua_Integer (*TluaL_checkinteger) (lua_State *L, int numArg);
typedef lua_Integer (*TluaL_optinteger) (lua_State *L, int nArg,
                                         lua_Integer def);
typedef lua_Unsigned (*TluaL_checkunsigned) (lua_State *L, int numArg);
typedef lua_Unsigned (*TluaL_optunsigned) (lua_State *L, int numArg,
                                           lua_Unsigned def);
typedef void (*TluaL_checkstack) (lua_State *L, int sz, const char *msg);
typedef void (*TluaL_checktype) (lua_State *L, int narg, int t);
typedef void (*TluaL_checkany) (lua_State *L, int narg);
typedef int   (*TluaL_newmetatable) (lua_State *L, const char *tname);
typedef void  (*TluaL_setmetatable) (lua_State *L, const char *tname);
typedef void *(*TluaL_testudata) (lua_State *L, int ud, const char *tname);
typedef void *(*TluaL_checkudata) (lua_State *L, int ud, const char *tname);
typedef void (*TluaL_where) (lua_State *L, int lvl);
typedef int (*TluaL_checkoption) (lua_State *L, int narg, const char *def,
                                  const char *const lst[]);
typedef int (*TluaL_fileresult) (lua_State *L, int stat, const char *fname);
typedef int (*TluaL_execresult) (lua_State *L, int stat);
typedef int (*TluaL_ref) (lua_State *L, int t);
typedef void (*TluaL_unref) (lua_State *L, int t, int ref);
typedef int (*TluaL_loadfilex) (lua_State *L, const char *filename,
                                const char *mode);
typedef int (*TluaL_loadbufferx) (lua_State *L, const char *buff, size_t sz,
                                  const char *name, const char *mode);
typedef int (*TluaL_loadstring) (lua_State *L, const char *s);
typedef lua_State *(*TluaL_newstate) (void);
typedef int (*TluaL_len) (lua_State *L, int idx);
typedef const char *(*TluaL_gsub) (lua_State *L, const char *s, const char *p,
                                   const char *r);
typedef void (*TluaL_setfuncs) (lua_State *L, const luaL_Reg *l, int nup);
typedef int (*TluaL_getsubtable) (lua_State *L, int idx, const char *fname);
typedef void (*TluaL_traceback) (lua_State *L, lua_State *L1,
                                 const char *msg, int level);
typedef void (*TluaL_requiref) (lua_State *L, const char *modname,
                                lua_CFunction openf, int glb);
typedef void (*TluaL_buffinit) (lua_State *L, luaL_Buffer *B);
typedef char *(*TluaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
typedef void (*TluaL_addlstring) (luaL_Buffer *B, const char *s, size_t l);
typedef void (*TluaL_addstring) (luaL_Buffer *B, const char *s);
typedef void (*TluaL_addvalue) (luaL_Buffer *B);
typedef void (*TluaL_pushresult) (luaL_Buffer *B);
typedef void (*TluaL_pushresultsize) (luaL_Buffer *B, size_t sz);
typedef char *(*TluaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);

typedef struct ThreadMutex* (*TgetDispMutex)(lua_State* L);
typedef void (*TThreadMutex_release)(struct ThreadMutex* o);
typedef void (*TThreadMutex_set)(struct ThreadMutex* o);
typedef struct BaTimer* (*TgetTimer)(lua_State* L);
typedef const struct BasFuncs* (*TgetBasFuncs)(void);

typedef struct {
   Tlua_newstate lua_newstatefp;
   Tlua_close lua_closefp;
   Tlua_newthread lua_newthreadfp;
   Tlua_atpanic lua_atpanicfp;
   Tlua_version lua_versionfp;
   Tlua_absindex lua_absindexfp;
   Tlua_gettop lua_gettopfp;
   Tlua_settop lua_settopfp;
   Tlua_pushvalue lua_pushvaluefp;
   Tlua_remove lua_removefp;
   Tlua_insert lua_insertfp;
   Tlua_replace lua_replacefp;
   Tlua_copy lua_copyfp;
   Tlua_checkstack lua_checkstackfp;
   Tlua_xmove lua_xmovefp;
   Tlua_isnumber lua_isnumberfp;
   Tlua_isstring lua_isstringfp;
   Tlua_iscfunction lua_iscfunctionfp;
   Tlua_isuserdata lua_isuserdatafp;
   Tlua_type lua_typefp;
   Tlua_typename lua_typenamefp;
   Tlua_tonumberx lua_tonumberxfp;
   Tlua_tointegerx lua_tointegerxfp;
   Tlua_tounsignedx lua_tounsignedxfp;
   Tlua_toboolean lua_tobooleanfp;
   Tlua_tolstring lua_tolstringfp;
   Tlua_rawlen lua_rawlenfp;
   Tlua_tocfunction lua_tocfunctionfp;
   Tlua_touserdata lua_touserdatafp;
   Tlua_tothread lua_tothreadfp;
   Tlua_topointer lua_topointerfp;
   Tlua_arith lua_arithfp;
   Tlua_rawequal lua_rawequalfp;
   Tlua_compare lua_comparefp;
   Tlua_pushnil lua_pushnilfp;
   Tlua_pushnumber lua_pushnumberfp;
   Tlua_pushinteger lua_pushintegerfp;
   Tlua_pushunsigned lua_pushunsignedfp;
   Tlua_pushlstring lua_pushlstringfp;
   Tlua_pushstring lua_pushstringfp;
   Tlua_pushvfstring lua_pushvfstringfp;
   Tlua_pushcclosure lua_pushcclosurefp;
   Tlua_pushboolean lua_pushbooleanfp;
   Tlua_pushlightuserdata lua_pushlightuserdatafp;
   Tlua_pushthread lua_pushthreadfp;
   Tlua_getglobal lua_getglobalfp;
   Tlua_gettable lua_gettablefp;
   Tlua_getfield lua_getfieldfp;
   Tlua_rawget lua_rawgetfp;
   Tlua_rawgeti lua_rawgetifp;
   Tlua_rawgetp lua_rawgetpfp;
   Tlua_createtable lua_createtablefp;
   Tlua_newuserdata lua_newuserdatafp;
   Tlua_getmetatable lua_getmetatablefp;
   Tlua_getuservalue lua_getuservaluefp;
   Tlua_setglobal lua_setglobalfp;
   Tlua_settable lua_settablefp;
   Tlua_setfield lua_setfieldfp;
   Tlua_rawset lua_rawsetfp;
   Tlua_rawseti lua_rawsetifp;
   Tlua_rawsetp lua_rawsetpfp;
   Tlua_setmetatable lua_setmetatablefp;
   Tlua_setuservalue lua_setuservaluefp;
   Tlua_callk lua_callkfp;
   Tlua_getctx lua_getctxfp;
   Tlua_pcallk lua_pcallkfp;
   Tlua_load lua_loadfp;
   Tlua_dump lua_dumpfp;
   Tlua_yieldk lua_yieldkfp;
   Tlua_resume lua_resumefp;
   Tlua_status lua_statusfp;
   Tlua_gc lua_gcfp;
   Tlua_error lua_errorfp;
   Tlua_next lua_nextfp;
   Tlua_concat lua_concatfp;
   Tlua_len lua_lenfp;
   Tlua_getallocf lua_getallocffp;
   Tlua_setallocf lua_setallocffp;
   Tlua_getstack lua_getstackfp;
   Tlua_getinfo lua_getinfofp;
   Tlua_getlocal lua_getlocalfp;
   Tlua_setlocal lua_setlocalfp;
   Tlua_getupvalue lua_getupvaluefp;
   Tlua_setupvalue lua_setupvaluefp;
   Tlua_upvalueid lua_upvalueidfp;
   Tlua_upvaluejoin lua_upvaluejoinfp;
   Tlua_sethook lua_sethookfp;
   Tlua_gethook lua_gethookfp;
   Tlua_gethookmask lua_gethookmaskfp;
   Tlua_gethookcount lua_gethookcountfp;
   Tluaopen_base luaopen_basefp;
   Tluaopen_coroutine luaopen_coroutinefp;
   Tluaopen_table luaopen_tablefp;
   Tluaopen_io luaopen_iofp;
   Tluaopen_os luaopen_osfp;
   Tluaopen_string luaopen_stringfp;
   Tluaopen_bit32 luaopen_bit32fp;
   Tluaopen_math luaopen_mathfp;
   Tluaopen_debug luaopen_debugfp;
   Tluaopen_package luaopen_packagefp;
   TluaL_checkversion_ luaL_checkversion_fp;
   TluaL_getmetafield luaL_getmetafieldfp;
   TluaL_callmeta luaL_callmetafp;
   TluaL_tolstring luaL_tolstringfp;
   TluaL_argerror luaL_argerrorfp;
   TluaL_checklstring luaL_checklstringfp;
   TluaL_optlstring luaL_optlstringfp;
   TluaL_checknumber luaL_checknumberfp;
   TluaL_optnumber luaL_optnumberfp;
   TluaL_checkinteger luaL_checkintegerfp;
   TluaL_optinteger luaL_optintegerfp;
   TluaL_checkunsigned luaL_checkunsignedfp;
   TluaL_optunsigned luaL_optunsignedfp;
   TluaL_checkstack luaL_checkstackfp;
   TluaL_checktype luaL_checktypefp;
   TluaL_checkany luaL_checkanyfp;
   TluaL_newmetatable luaL_newmetatablefp;
   TluaL_setmetatable luaL_setmetatablefp;
   TluaL_testudata luaL_testudatafp;
   TluaL_checkudata luaL_checkudatafp;
   TluaL_where luaL_wherefp;
   TluaL_checkoption luaL_checkoptionfp;
   TluaL_fileresult luaL_fileresultfp;
   TluaL_execresult luaL_execresultfp;
   TluaL_ref luaL_reffp;
   TluaL_unref luaL_unreffp;
   TluaL_loadfilex luaL_loadfilexfp;
   TluaL_loadbufferx luaL_loadbufferxfp;
   TluaL_loadstring luaL_loadstringfp;
   TluaL_newstate luaL_newstatefp;
   TluaL_len luaL_lenfp;
   TluaL_gsub luaL_gsubfp;
   TluaL_setfuncs luaL_setfuncsfp;
   TluaL_getsubtable luaL_getsubtablefp;
   TluaL_traceback luaL_tracebackfp;
   TluaL_requiref luaL_requireffp;
   TluaL_buffinit luaL_buffinitfp;
   TluaL_prepbuffsize luaL_prepbuffsizefp;
   TluaL_addlstring luaL_addlstringfp;
   TluaL_addstring luaL_addstringfp;
   TluaL_addvalue luaL_addvaluefp;
   TluaL_pushresult luaL_pushresultfp;
   TluaL_pushresultsize luaL_pushresultsizefp;
   TluaL_buffinitsize luaL_buffinitsizefp;
   TgetDispMutex getDispMutexfp;
   TThreadMutex_release ThreadMutex_releasefp;
   TThreadMutex_set ThreadMutex_setfp;
   TgetTimer getTimerfp;
   TgetBasFuncs getBasFuncsfp;
} LuaFuncs;


void _setBasFuncs(const struct BasFuncs* f);

#ifdef loadlib_c
#ifdef USE_BASINTF


#ifndef _baintfint_h
#define _baintfint_h


#ifdef USE_AMALGAMATED_BAS
#else
#endif


typedef struct AuthenticatedUser* (*TAuthenticatedUser_get2)(struct HttpSession* session);
typedef U32 (*TBaTimer_set)(BaTimer* o, BaTimer_CB cb, void* data, U32 milliSec);
typedef int (*TBaTimer_reset)(BaTimer* o, U32 tkey, U32 milliSec);
typedef int (*TBaTimer_cancel)(BaTimer* o, U32 tkey);
typedef DoubleLink* (*TDoubleList_removeFirst)(DoubleList* o);
typedef struct HttpCommand* (*THttpRequest_getCommand)(HttpRequest*);
typedef const char* (*THttpRequest_getHeaderValue)(HttpRequest* o,const char* name);
typedef struct HttpSession* (*THttpRequest_getSession)(HttpRequest* o, BaBool create);
typedef int (*THttpResponse_flush)(HttpResponse* o);
typedef int (*THttpResponse_sendError1)(HttpResponse* o, int eCode);
typedef int (*THttpResponse_setHeader)(
   HttpResponse* o,const char* name,const char* value, BaBool replace);
typedef int (*THttpResponse_setStatus)(HttpResponse* o, int eCode);
typedef void (*THttpSession_decrRefCntr)(HttpSession* o);
typedef void (*THttpSockaddr_addr2String)(
   HttpSockaddr* o, char* buf, int bufLen, int* status);
typedef int (*THttpSocket_makeClientCon)(
   HttpSocket* o,struct HttpSockaddr* addr,
   const char* interfaceName,U16 port, BaBool nonBlocking);
typedef void (*TSingleList_constructor)(SingleList* o);
typedef SingleLink* (*TSingleList_removeFirst)(SingleList* o);
typedef void* (*TSoDispCon_allocAsynchBuf)(SoDispCon* o, int* size);
typedef void (*TSoDispCon_constructor)(
   SoDispCon* o, struct SoDisp* dispatcher, SoDispCon_DispRecEv e);
typedef int (*TSoDispCon_getPeerName)(SoDispCon* o,HttpSockaddr* addr,U16* port);
typedef int (*TSoDispCon_getSockName)(SoDispCon* o, HttpSockaddr* addr, U16* port);
typedef int (*TSoDispCon_moveCon)(SoDispCon* o, SoDispCon*  newCon);
typedef int (*TSoDispCon_setNonblocking)(SoDispCon* o);
typedef int (*TSoDispCon_setBlocking)(SoDispCon* o);
typedef void (*TSoDispCon_setTCPNoDelay)(SoDispCon* o, int enable);
typedef void (*TSoDispCon_zzCloseCon)(SoDispCon* o, int shutdown);
typedef void (*TSoDisp_activateRec)(SoDisp* o, struct SoDispCon* con);
typedef void (*TSoDisp_deactivateRec)(SoDisp* o, struct SoDispCon* con);
typedef void (*TSoDisp_activateSend)(SoDisp* o, struct SoDispCon* con);
typedef void (*TSoDisp_deactivateSend)(SoDisp* o, struct SoDispCon* con); 
typedef void (*TSoDisp_addConnection)(SoDisp* o, struct SoDispCon* con);
typedef void (*TSoDisp_constructor)(SoDisp* o, ThreadMutex* mutex);
typedef void (*TSoDisp_run)(SoDisp* o, S32 timeout);
typedef void (*TSplayTreeNode_constructor)(SplayTreeNode* o, SplayTreeKey key);
typedef SplayTreeNode* (*TSplayTree_find)(SplayTree* o, SplayTreeKey key);
typedef int (*TSplayTree_insert)(SplayTree* o, SplayTreeNode* n);
typedef int (*TSplayTree_remove)(SplayTree* o, SplayTreeNode* n);
typedef void (*TThread_constructor)(
   ThreadBase* o, Thread_Run r, ThreadPriority priority, int stackSize);
typedef U32 (*TU32_atoi)(const char* s);
typedef void (*TbaFatalEf)(BaFatalErrorCodes ecode1, unsigned int ecode2,
                           const char* file, int line);

typedef void* (*T_baluaENV_isudtype)(lua_State* L, int udIx, int mtid, int check);
typedef HttpDir* (*TbaluaENV_createDir)(lua_State* L,int mtId,size_t dirSize);
typedef void (*TbaluaENV_register)(
   lua_State *L, int mtid, int inheritmtid, const luaL_Reg* lib);
typedef void (*THttpDir_constructor)(HttpDir* o, const char* name, S8 priority);
typedef void (*THttpDir_destructor)(HttpDir* o); 
typedef HttpDir_Service (*THttpDir_overloadService)(HttpDir*o, HttpDir_Service s);
typedef int (*TClientConnection_open)(ClientConnection* o,
                                      const char* host,
                                      U16 port,
                                      BaBool nonBlocking,
                                      const void* intfName,
                                      BaBool useIp6);
typedef void (*TClientConnection_constructor)(ClientConnection* o,
                                              struct SoDisp* dispatcher,
                                              SoDispCon_DispRecEv re,
                                              SoDispCon_DispSendEv se); 
#ifndef ThreadMutex_constructor
typedef void (*TThreadMutex_constructor)(struct ThreadMutexBase* o);
#endif
#ifndef ThreadMutex_start
typedef void (*TThread_start)(Thread* o);
#endif

struct BasFuncs {
   TAuthenticatedUser_get2 AuthenticatedUser_get2Fp;
   TBaTimer_cancel BaTimer_cancelFp;
   TBaTimer_set BaTimer_setFp;
   TBaTimer_reset BaTimer_resetFp;
   TDoubleList_removeFirst DoubleList_removeFirstFp;
   THttpRequest_getCommand HttpRequest_getCommandFp;
   THttpRequest_getHeaderValue HttpRequest_getHeaderValueFp;
   THttpRequest_getSession HttpRequest_getSessionFp;
   THttpResponse_flush HttpResponse_flushFp;
   THttpResponse_sendError1 HttpResponse_sendError1Fp;
   THttpResponse_setHeader HttpResponse_setHeaderFp;
   THttpResponse_setStatus HttpResponse_setStatusFp;
   THttpSession_decrRefCntr HttpSession_decrRefCntrFp;
   THttpSockaddr_addr2String HttpSockaddr_addr2StringFp;
   THttpSocket_makeClientCon HttpSocket_makeClientConFp;
   TSingleList_constructor SingleList_constructorFp;
   TSingleList_removeFirst SingleList_removeFirstFp;
   TSoDispCon_allocAsynchBuf SoDispCon_allocAsynchBufFp;
   TSoDispCon_constructor SoDispCon_constructorFp;
   TSoDispCon_getPeerName SoDispCon_getPeerNameFp;
   TSoDispCon_getSockName SoDispCon_getSockNameFp;
   TSoDispCon_moveCon SoDispCon_moveConFp;
   TSoDispCon_setNonblocking SoDispCon_setNonblockingFp;
   TSoDispCon_setBlocking SoDispCon_setBlockingFp;
   TSoDispCon_setTCPNoDelay SoDispCon_setTCPNoDelayFp;
   TSoDispCon_zzCloseCon SoDispCon_zzCloseConFp;
   TSoDisp_activateRec SoDisp_activateRecFp;
   TSoDisp_activateSend SoDisp_activateSendFp;
   TSoDisp_addConnection SoDisp_addConnectionFp;
   TSoDisp_constructor SoDisp_constructorFp;
   TSoDisp_deactivateRec SoDisp_deactivateRecFp;
   TSoDisp_deactivateSend SoDisp_deactivateSendFp;
   TSoDisp_run SoDisp_runFp;
   TSplayTreeNode_constructor SplayTreeNode_constructorFp;
   TSplayTree_find SplayTree_findFp;
   TSplayTree_insert SplayTree_insertFp;
   TSplayTree_remove SplayTree_removeFp;
   TThread_constructor Thread_constructorFp;
   TU32_atoi U32_atoiFp;
   TbaFatalEf baFatalEfFp;

   T_baluaENV_isudtype _baluaENV_isudtypeFp;
   TbaluaENV_createDir baluaENV_createDirFp;
   TbaluaENV_register baluaENV_registerFp;
   THttpDir_constructor HttpDir_constructorFp;
   THttpDir_destructor HttpDir_destructorFp;
   THttpDir_overloadService HttpDir_overloadServiceFp;
   TClientConnection_open ClientConnection_openFp;
   TClientConnection_constructor  ClientConnection_constructorFp;
#ifndef ThreadMutex_constructor
   TThreadMutex_constructor ThreadMutex_constructorFp;
#endif
#ifndef ThreadMutex_start
   TThread_start Thread_startFp;
#endif
};


#ifdef loadlib_c
static const struct BasFuncs basFuncs={
   AuthenticatedUser_get2,
   BaTimer_cancel,
   BaTimer_set,
   BaTimer_reset,
   DoubleList_removeFirst,
   HttpRequest_getCommand,
   HttpRequest_getHeaderValue,
   HttpRequest_getSession,
   HttpResponse_flush,
   HttpResponse_sendError1,
   HttpResponse_setHeader,
   HttpResponse_setStatus,
   HttpSession_decrRefCntr,
   HttpSockaddr_addr2String,
   HttpSocket_makeClientCon,
   SingleList_constructor,
   SingleList_removeFirst,
   SoDispCon_allocAsynchBuf,
   SoDispCon_constructor,
   SoDispCon_getPeerName,
   SoDispCon_getSockName,
   SoDispCon_moveCon,
   SoDispCon_setNonblocking,
   SoDispCon_setBlocking,
   SoDispCon_setTCPNoDelay,
   SoDispCon_zzCloseCon,
   SoDisp_activateRec,
   SoDisp_activateSend,
   SoDisp_addConnection,
   SoDisp_constructor,
   SoDisp_deactivateRec,
   SoDisp_deactivateSend,
   SoDisp_run,
   SplayTreeNode_constructor,
   SplayTree_find,
   SplayTree_insert,
   SplayTree_remove,
   Thread_constructor,
   U32_atoi,
   baFatalEf,
   _baluaENV_isudtype,
   baluaENV_createDir,
   baluaENV_register,
   HttpDir_constructor,
   HttpDir_destructor,
   HttpDir_overloadService,
   ClientConnection_open,
   ClientConnection_constructor
#ifndef ThreadMutex_constructor
   ,ThreadMutex_constructor
#endif
#ifndef ThreadMutex_start
   ,Thread_start
#endif

};
#endif

#endif
static const struct BasFuncs* getBasFuncs(void) { return &basFuncs; }
#else
static const struct BasFuncs* getBasFuncs(void) { return 0; }
#endif

static BaLua_param* getBaParem(lua_State* L)
{
  BaLua_param* p;
  balua_pushbatab(L);
  lua_rawgeti(L, -1, BA_VMPTR);
  p = (BaLua_param*)lua_touserdata(L, -1);
  lua_pop(L,2);
  return p;
}
static struct ThreadMutex* getDispMutex(lua_State* L)
{
   BaLua_param* p = getBaParem(L);
   return p ? p->mutex : 0;
}
static struct BaTimer* getTimer(lua_State* L)
{
   BaLua_param* p = getBaParem(L);
   return p ? p->timer : 0;
}
static void ThreadMutex_releaseWrapper(struct ThreadMutex* o)
{
   if(o) ThreadMutex_release(o);
}
static void ThreadMutex_setWrapper(struct ThreadMutex* o)
{
   if(o) ThreadMutex_set(o);
}
static const LuaFuncs luaFuncs={
   lua_newstate,
   lua_close,
   lua_newthread,
   lua_atpanic,
   lua_version,
   lua_absindex,
   lua_gettop,
   lua_settop,
   lua_pushvalue,
   lua_remove,
   lua_insert,
   lua_replace,
   lua_copy,
   lua_checkstack,
   lua_xmove,
   lua_isnumber,
   lua_isstring,
   lua_iscfunction,
   lua_isuserdata,
   lua_type,
   lua_typename,
   lua_tonumberx,
   lua_tointegerx,
   lua_tounsignedx,
   lua_toboolean,
   lua_tolstring,
   lua_rawlen,
   lua_tocfunction,
   lua_touserdata,
   lua_tothread,
   lua_topointer,
   lua_arith,
   lua_rawequal,
   lua_compare,
   lua_pushnil,
   lua_pushnumber,
   lua_pushinteger,
   lua_pushunsigned,
   lua_pushlstring,
   lua_pushstring,
   lua_pushvfstring,
   lua_pushcclosure,
   lua_pushboolean,
   lua_pushlightuserdata,
   lua_pushthread,
   lua_getglobal,
   lua_gettable,
   lua_getfield,
   lua_rawget,
   lua_rawgeti,
   lua_rawgetp,
   lua_createtable,
   lua_newuserdata,
   lua_getmetatable,
   lua_getuservalue,
   lua_setglobal,
   lua_settable,
   lua_setfield,
   lua_rawset,
   lua_rawseti,
   lua_rawsetp,
   lua_setmetatable,
   lua_setuservalue,
   lua_callk,
   lua_getctx,
   lua_pcallk,
   lua_load,
   lua_dump,
   lua_yieldk,
   lua_resume,
   lua_status,
   lua_gc,
   lua_error,
   lua_next,
   lua_concat,
   lua_len,
   lua_getallocf,
   lua_setallocf,
   lua_getstack,
   lua_getinfo,
   lua_getlocal,
   lua_setlocal,
   lua_getupvalue,
   lua_setupvalue,
   lua_upvalueid,
   lua_upvaluejoin,
   lua_sethook,
   lua_gethook,
   lua_gethookmask,
   lua_gethookcount,
   luaopen_base,
   luaopen_coroutine,
   luaopen_table,
   luaopen_io,
   luaopen_os,
   luaopen_string,
   luaopen_bit32,
   luaopen_math,
   luaopen_debug,
   luaopen_package,
   luaL_checkversion_,
   luaL_getmetafield,
   luaL_callmeta,
   luaL_tolstring,
   luaL_argerror,
   luaL_checklstring,
   luaL_optlstring,
   luaL_checknumber,
   luaL_optnumber,
   luaL_checkinteger,
   luaL_optinteger,
   luaL_checkunsigned,
   luaL_optunsigned,
   luaL_checkstack,
   luaL_checktype,
   luaL_checkany,
   luaL_newmetatable,
   luaL_setmetatable,
   luaL_testudata,
   luaL_checkudata,
   luaL_where,
   luaL_checkoption,
   luaL_fileresult,
   luaL_execresult,
   luaL_ref,
   luaL_unref,
   luaL_loadfilex,
   luaL_loadbufferx,
   luaL_loadstring,
   luaL_newstate,
   luaL_len,
   luaL_gsub,
   luaL_setfuncs,
   luaL_getsubtable,
   luaL_traceback,
   luaL_requiref,
   luaL_buffinit,
   luaL_prepbuffsize,
   luaL_addlstring,
   luaL_addstring,
   luaL_addvalue,
   luaL_pushresult,
   luaL_pushresultsize,
   luaL_buffinitsize,
   getDispMutex,
   ThreadMutex_releaseWrapper,
   ThreadMutex_setWrapper,
   getTimer,
   getBasFuncs,
};
#endif

#endif

#ifndef __HttpClient_h
#define __HttpClient_h

struct HttpClient;





typedef struct
{
      const char* key;
      const char* val;
} HttpClientKeyVal;




typedef struct
{
#ifdef __cplusplus
      
      const char* getKey(HttpClient* c);
      
      const char* getVal(HttpClient* c);
#endif
      U16 key;
      U16 val;
} HttpClientHeader;

#define HttpClientHeader_key(c,o) ((c)->db.super.buf + (o)->key)
#define HttpClientHeader_val(c,o) ((c)->db.super.buf + (o)->val)


#define HTTP_CLIENT_MAX_HEADERS 16

#define HttpClient_SocksProxy 1
#define HttpClient_Persistent 2
#define HttpClient_IPv6       4


typedef struct HttpClient
#ifdef __cplusplus
: public ClientConnection
{
      
      HttpClient(SoDisp* disp, U8 mode=HttpClient_Persistent);

      
      ~HttpClient();

      
      void setSSL(SharkSsl* ssl);

      
      void setReadTmo(BaTime timeout);

      
      static int isURL(const char* url);

      
      int trusted(void);

      
      void setAcceptTrusted(bool acceptTrusted);

      
      int request(HttpMethod methodType,
                  const char* url,
                  const char* userPass=0,
                  const HttpClientKeyVal* query=0,
                  const HttpClientKeyVal* headers=0,
                  BaFileSize size=0);

      
      int sendData(const void* data, int len);

      int getBufSize();

      
      int readData(void* buf, int bufSize);

      
      const char* getHeaderValue(const char* name);

      
      HttpClientHeader* getHeaders(int* hlen);

      
      void close();

      
      int getStatus();

      
      int getError();

   
   SharkSslCon* getSharkSslCon();

      SoDispCon* getSoDispCon();
#else
{
      ClientConnection super;
#endif
      DynBuffer db;
      HttpClientHeader headers[HTTP_CLIENT_MAX_HEADERS];

      struct SharkSsl* sharkSslClient; 

      
      const char* proxy; 
      const char* proxyUserPass; 
      const char* intfName; 

      char* data; 
      char* host; 
      BaFileSize size; 
      BaTime readTmo; 
      int chunkSize;
      int lastError;
      int portNo; 
      U16 proxyPortNo; 
      U16 headerLen;
      U16 httpStatus;
      BaBool chunkEncoding;
      BaBool respManaged; 
      BaBool closeCon;
      BaBool acceptTrusted; 
      
      U8 mode;
      U8 methodType;
} HttpClient;

#ifdef __cplusplus
extern "C" {
#endif

void HttpClient_constructor(HttpClient* o, SoDisp* disp, U8 mode);
#define HttpClient_setSSL(o, ssl) (o)->sharkSslClient=ssl
#define HttpClient_setReadTmo(o, timeout) (o)->readTmo=timeout
SharkSslCon* HttpClient_getSharkSslCon(HttpClient* o);

void HttpClient_destructor(HttpClient* o);
int HttpClient_isURL(const char* url);
int HttpClient_request(HttpClient* o,
                       HttpMethod methodType,
                       const char* url,
                       const char* userPass,
                       const HttpClientKeyVal* params,
                       const HttpClientKeyVal* headers,
                       BaFileSize size);

int HttpClient_sendData(HttpClient* o, const void* data, int len);
int HttpClient_getBufSize(HttpClient* o);
int HttpClient_readData(HttpClient* o, void* buf, int bufSize);
const char* HttpClient_getHeaderValue(HttpClient* o, const char* name);
HttpClientHeader* HttpClient_getHeaders(HttpClient* o, int* hlen);
void HttpClient_close(HttpClient* o);
int HttpClient_getStatus(HttpClient* o);
#define HttpClient_getError(o) (o)->lastError
#define HttpClient_getSoDispCon(o) ((SoDispCon*)(o))
int HttpClient_trusted(HttpClient* o);
#define HttpClient_setAcceptTrusted(o, t) (o)->acceptTrusted=t

#ifdef __cplusplus
}

inline HttpClient::HttpClient(SoDisp* disp, U8 mode) {
   HttpClient_constructor(this,disp, mode);
}

inline HttpClient::~HttpClient() {
   HttpClient_destructor(this);
}

inline void HttpClient::setSSL(SharkSsl* ssl) {
   HttpClient_setSSL(this,ssl);
}

inline void HttpClient::setReadTmo(BaTime timeout) {
   HttpClient_setReadTmo(this,timeout);
}

inline int HttpClient::isURL(const char* url) {
   return HttpClient_isURL(url);
}


inline int HttpClient::trusted(void){
   return HttpClient_trusted(this);
}

inline void HttpClient::setAcceptTrusted(bool t) {
   HttpClient_setAcceptTrusted(this, t?TRUE:FALSE);
}


inline SharkSslCon* HttpClient::getSharkSslCon() {
   return HttpClient_getSharkSslCon(this);
}


inline int HttpClient::request(HttpMethod methodType,
                               const char* url,
                               const char* userPass,
                               const HttpClientKeyVal* params,
                               const HttpClientKeyVal* headers,
                               BaFileSize size)
{
   return HttpClient_request(this,methodType,url,userPass,params,headers,size);
}

inline int HttpClient::sendData(const void* data, int len) {
   return HttpClient_sendData(this, data, len);
}

inline int HttpClient::getBufSize() {
   return HttpClient_getBufSize(this);
}

inline int HttpClient::readData(void* buf, int bufSize) {
   return HttpClient_readData(this, buf, bufSize);
}

inline const char* HttpClient::getHeaderValue(const char* name) {
   return HttpClient_getHeaderValue(this, name);
}

inline HttpClientHeader* HttpClient::getHeaders(int* hlen) {
   return HttpClient_getHeaders(this, hlen);
}

inline void HttpClient::close() {
   HttpClient_close(this);
}

inline int HttpClient::getStatus() {
   return HttpClient_getStatus(this);
}


inline int HttpClient::getError() {
   return HttpClient_getError(this);
}

inline SoDispCon* HttpClient::getSoDispCon() {
   return HttpClient_getSoDispCon(this);
}

inline const char* HttpClientHeader::getKey(HttpClient* c) {
   return c->db.buf + key;
}
inline const char* HttpClientHeader::getVal(HttpClient* c) {
   return c->db.buf + val;
}
#endif

 


#endif
