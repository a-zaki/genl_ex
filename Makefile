
PKG_CONFIG=$(shell dirname ${CROSS_COMPILE})/pkg-config
NL_LIBNAME=libnl-genl-3.0

NL_LIB_FLAGS=$(shell $(PKG_CONFIG) --cflags $(NL_LIBNAME))
NL_LIBS_L=$(shell $(PKG_CONFIG) --libs-only-L $(NL_LIBNAME))
NL_LIBS_l=$(shell $(PKG_CONFIG) --libs-only-l $(NL_LIBNAME))

CC=${CROSS_COMPILE}gcc

.PHONY:all
all: genl_ex genl_ex.ko

genl_ex: genl_ex.h genl_ex.c
	$(CC) -Wextra -Wall -Werror -Wno-unused-parameter genl_ex.c $(NL_LIB_FLAGS) $(NL_LIBS_L) $(NL_LIBS_l) -o genl_ex

genl_ex.ko:
	$(MAKE) -C $(shell pwd)/kernel KERNEL_DIR=$(KERNEL_DIR) 

.PHONY: install
install:
	$(MAKE) -C $(shell pwd)/kernel install

.PHONY: clean
clean:
	rm -f *.o genl_ex
	$(MAKE) -C $(shell pwd)/kernel KERNEL_DIR=$(KERNEL_DIR) clean

