#Makefile, including cross compilation examples.


#Enable module support: http://makoserver.net/documentation/c-modules/
CFLAGS += -DUSE_LUAINTF

#Enable the BAS functions required by the BarracudaDrive plugin (see basintf.h)
CFLAGS += -DUSE_BASINTF

#Enable forkpty and reverse proxy
CFLAGS += -DBAS_LOADED

# if compiled as: make build=debug
ifeq (debug,$(build))
CFLAGS += -g
else 
#Optimize
CFLAGS += -O3 -Os
endif

#Defaults to native compilation
ifndef
CC=gcc
endif
ifndef
STRIP=strip
endif

BITS := $(shell getconf LONG_BIT)
ifeq ($(BITS), 64)
#The code will crash on 64 bit if BA_64BIT is not set. 
CC+= -DBA_64BIT -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
endif




#--------------------   Cross compilation examples:
#Command: make DD_WRT=true MIPS=true
ifdef DD_WRT
ifdef MIPS
ENDIAN=B_BIG_ENDIAN
GCCHOME=/disk2/toolchain-mips_r2_gcc-linaro_uClibc-0.9.32/
CC=$(GCCHOME)/bin/mips-openwrt-linux-gcc
STRIP=$(GCCHOME)/bin/mips-openwrt-linux-strip
endif
endif

#Command: make BEAGLEBOARD=true
ifdef BEAGLEBOARD
GCCHOME=/usr/local/ti-sdk-am335x-evm/linux-devkit
CC=$(GCCHOME)/bin/arm-arago-linux-gnueabi-gcc
STRIP=$(GCCHOME)/bin/arm-arago-linux-gnueabi-strip
endif

ifdef SHEEVAPLUG
GCCHOME=/FIXME
CC=$(GCCHOME)/bin/arm-none-linux-gnueabi-gcc
STRIP=$(GCCHOME)/bin/arm-none-linux-gnueabi-strip
endif


#Default is little endian CPU type
ifndef ENDIAN
ENDIAN=B_LITTLE_ENDIAN
$(warning Little endian assumed!)
endif


#----------------- Build
mako:*.c
	$(CC) $(CFLAGS) -D$(ENDIAN) -DUSE_AMALGAMATED_BAS -fmerge-all-constants -finline-limit=50 -o mako -I./ *.c -lpthread -ldl -lm -lrt
ifneq (debug,$(build))
	$(STRIP) mako
endif

