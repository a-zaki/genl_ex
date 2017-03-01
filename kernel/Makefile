
obj-m := genl_ex.o
nl_test-y = genl_ex.o

THIS_DIR := $(shell pwd)

.phony: all
all: genl_ex.ko

genl_ex.ko: $(KOBJS) Makefile
	$(MAKE) -C $(KERNEL_DIR) M=$(THIS_DIR) modules c=2

.phony: install
install:
	$(MAKE) -C $(KERNEL_DIR) INSTALL_MOD_PATH=$(rootfs) M=$(THIS_DIR) -e modules_install

.phony: clean
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(THIS_DIR) clean
