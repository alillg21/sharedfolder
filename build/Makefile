#  makefile 模板
#  编译POS机应用程序
#  张文晖 2013/12/06; 卢永宁修改 2014/05/28
#  版本 V1.1

#export POSDIR=$(shell pwd)
POSDIR=..

#默认编译输出文件
#MACHINEMODE = KF615

ifeq ($(Plat),BRCM)
  $(warning arm-brcm-linux-gnueabi)
  #ARCH	= /opt/brcm-armtools-64bit/tools/le_arm11_external_20090306/bin/arm-brcm-linux-gnueabi
  ARCH	= arm-brcm-linux-gnueabi
else
  $(warning arm-unknown-linux-gnu)
  #ARCH	= /opt/gcc-4.0.2-glibc-2.3.5/arm-unknown-linux-gnu/bin/arm-unknown-linux-gnu
  ARCH	= arm-unknown-linux-gnu
endif

CC  = $(ARCH)-gcc
CPP = $(ARCH)-g++
AR  = $(ARCH)-ar

CFLAGS += -Os -s -Wall
CPPFLAGS = $(CFLAGS) -Wno-non-virtual-dtor

#参数变量判断
ifeq ($(debugflag),debug)
CFLAGS += -DKF_DEBUG
endif

#传入机型
ifeq ($(MACHINEMODE),KF351)
	CFLAGS += -DKF351=1
endif
ifeq ($(MACHINEMODE),KF352)
	CFLAGS += -DKF352=2
endif
ifeq ($(MACHINEMODE),KF600)
	CFLAGS += -DKF600=3
endif
ifeq ($(MACHINEMODE),KF605)
	CFLAGS += -DKF605=4
endif
ifeq ($(MACHINEMODE),KF615)
	CFLAGS += -DKF615=5
endif
ifeq ($(MACHINEMODE),KF900)
	CFLAGS += -DKF900=6
endif
ifeq ($(MACHINEMODE),KF951)
	CFLAGS += -DKF951=7
endif
CFLAGS += -DPOS_TYPE=$(MACHINEMODE)

ifeq ($(OUT_TARGET),dll)
	BUILD_LIB = -shared -fPIC
else
	ifeq ($(OUT_TARGET),slib)
		BUILD_LIB = rcs
	else
		BUILD_LIB = -Wl,-rpath,/data/lib
	endif
endif

# 包含应用的编译信息文件，用户自定义的头文件、源文件和目标文件
include makeinclude.in

# 头文件
SDK_INC += -I$(LIBHEAD)/$(MACHINEMODE)/BaseSdk-inc
SDK_INC += -I$(LIBHEAD)/$(MACHINEMODE)/PubSdk-inc
INCLUDES += $(SDK_INC) $(APP_INC) $(APP_LIBINC)

# 库文件
#-L库 个别没有库，用宏变量控制
SUPPORT_LIB = true
ifdef SUPPORT_LIB

SDK_DLLPTAH += -L$(LIBHEAD)/$(MACHINEMODE)/

SDK_DLL += $(notdir $(wildcard $(LIBHEAD)/$(MACHINEMODE)/*/*/*.so))
SDK_DLL += $(notdir $(wildcard $(LIBHEAD)/$(MACHINEMODE)/*/*.so))
SDK_DLL += $(notdir $(wildcard $(LIBHEAD)/$(MACHINEMODE)/*.so))

SDK_DLL2 += $(patsubst lib%.so, -l%, $(SDK_DLL))
SDK_LIBS += $(SDK_DLLPTAH) $(SDK_DLL2)

# 共享库
SHARE_LIBS += $(SDK_LIBS) $(APP_LIBS)
SHARE_LIBS += -ldl -lrt -lpthread

# 静态库
SDK_OBJS += $(wildcard $(LIBHEAD)/$(MACHINEMODE)/*.a)
STATIC_LIBS += $(SDK_OBJS) $(APP_OBJS)
endif

# 各目标文件命名处理
	outfilename=
	outfilename1=
	#outfilename2=-d.so
	outfilename3=
ifeq ($(OUT_TARGET),dll)
	outfilename=lib
	#outfilename1=-dll
	outfilename3=.so
else
	ifeq ($(OUT_TARGET),slib)
		#outfilename1=-slib
		outfilename3=.a
	else
		#outfilename1=-exe
		outfilename3=
	endif
endif

ifeq ($(debugflag),debug)
	outfilename2=-d
else
	outfilename2=-r
endif

# 目标文件
TARGET = $(outfilename)$(MACHINEMODE)$(outfilename1)$(outfilename2)$(outfilename3)
#APP_TARGET=DEMO

all: $(TARGET)
	cp $(TARGET) $(APP_TARGET)
	@echo -e "Compiled in: " > datemd5.txt
	@date +%Y/%m/%d_%H:%M:%S >> datemd5.txt
	@echo -e "\n\r" >> datemd5.txt
	@openssl dgst -md5 $(TARGET) >> datemd5.txt

$(TARGET) : $(OBJS) $(OBJSCPP) 
ifeq ($(OUT_TARGET),slib)
	$(AR) $(BUILD_LIB) $@ $^
else
	$(CC) $(CFLAGS) $(SHARE_LIBS) $(BUILD_LIB) -o $@ $^ $(STATIC_LIBS)
endif

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(ALLSRC:.c=.o) : $(POSDIR)/inc/*.h

%.o : %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) -o $@ -c $<

$(ALLSRC:.cpp=.o) : $(POSDIR)/inc/*.h


clean:
	rm -f $(TARGET)  $(POSDIR)/*.o $(POSDIR)/*/*.o $(POSDIR)/*/*/*.o $(POSDIR)/*/*/*/*.o
	rm -f $(TARGET)  $(POSDIR)/*.bak $(POSDIR)/*/*.bak $(POSDIR)/*/*/*.bak $(POSDIR)/*/*/*/*.bak
	rm -f $(APP_TARGET)  compile.txt datemd5.txt
