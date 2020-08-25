# Filename: Makefile
# Version: 1.0
# Description: Makefile for Linux PCIe device driver.


# You must specify the following variables. You can leave the defaults if you
# like, but make sure they will work in your system.
# The VENDOR_ID _must_ match what is configured on your FPGA's PCIe endpoint 
# header. 
NAME := serica
VENDOR_ID := 5352

ccflags-y := -Wno-unknown-pragmas #ignore pragmas predefine

ifneq ($(KERNELRELEASE),)
	obj-m := $(NAME).o
	$(NAME)-y := init.o seqfile.o

else
	KDIR := /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

$(NAME).ko: *.c
	$(call assert-variables)
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.mod.c *.ko *.symvers *.order *.makers .*.cmd .tmp_versions *.s

load: $(NAME).ko
	insmod $(NAME).ko
	
unload:
	rmmod $(NAME)
	dmesg -c

assemble:
	$(CC) -S *.c
endif
