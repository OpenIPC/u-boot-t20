#define CONFIG_BOOTARGS "\${osmem} console=ttyS1,115200 panic=20 root=/dev/mtdblock3 rootfstype=squashfs init=/init mtdparts=\${mtdparts}"
#define CONFIG_BOOTCOMMAND "setenv setargs setenv bootargs ${bootargs}; run setargs; sf probe 0; sf read ${baseaddr} 0x50000 0x200000; bootm ${baseaddr}; reset"

#define CONFIG_EXTRA_ENV_SETTINGS \
    "baseaddr=0x82000000\0" \
    "uknor8m=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} uImage.${soc} && sf probe 0; sf erase 0x50000 0x200000; sf write ${baseaddr} 0x50000 ${filesize}\0" \
    "uknor16m=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} uImage.${soc} && sf probe 0; sf erase 0x50000 0x300000; sf write ${baseaddr} 0x50000 ${filesize}\0" \
    "urnor8m=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} rootfs.squashfs.${soc} && sf probe 0; sf erase 0x250000 0x500000; sf write ${baseaddr} 0x250000 ${filesize}\0" \
    "urnor16m=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} rootfs.squashfs.${soc} && sf probe 0; sf erase 0x350000 0xa00000; sf write ${baseaddr} 0x350000 ${filesize}\0" \
    "uknand=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} uImage.${soc} && nand erase 0x100000 0x300000; nand write ${baseaddr} 0x100000 0x300000\0" \
    "urnand=mw.b ${baseaddr} ff 1000000; tftpboot ${baseaddr} rootfs.ubi.${soc} && nand erase 0x400000 0x7c00000; nand write ${baseaddr} 0x400000 ${filesize}\0" \
    "mtdparts=jz_sfc:256k(boot),64k(env),2048k(kernel),5120k(rootfs),-(rootfs_data)\0" \
    "mtdpartsubi=setenv mtdparts jz_nand:256k(boot),768k(wtf),3072k(kernel),-(ubi)\0" \
    "mtdpartsnand=setenv mtdparts jz_nand:256k(boot),768k(wtf),3072k(kernel),10240k(rootfs),-(rootfs_data)\0" \
    "mtdpartsnor8m=setenv mtdparts jz_sfc:256k(boot),64k(env),2048k(kernel),5120k(rootfs),-(rootfs_data)\0" \
    "mtdpartsnor16m=setenv mtdparts jz_sfc:256k(boot),64k(env),3072k(kernel),10240k(rootfs),-(rootfs_data)\0" \
    "nfsroot=/srv/nfs/"CONFIG_PRODUCTNAME"\0" \
    "bootargsnfs=mem=\${osmem} console=ttyS1,115200 panic=20 root=/dev/nfs rootfstype=nfs ip=${ipaddr}:::255.255.255.0::eth0 nfsroot=${serverip}:${nfsroot},v3,nolock rw\0" \
    "bootargsubi=mem=\${osmem} console=ttyS1,115200 panic=20 init=/init root=ubi0:rootfs rootfstype=ubifs ubi.mtd=3,2048 mtdparts=\${mtdparts}\0" \
    "bootnfs=setenv setargs setenv bootargs ${bootargsnfs}; run setargs; tftpboot ${baseaddr} uImage.${soc}; bootm ${baseaddr}\0" \
    "bootcmdnand=setenv setargs setenv bootargs ${bootargs}; run setargs; nand read ${baseaddr} 0x100000 0x300000; bootm ${baseaddr}\0" \
    "bootcmdubi=setenv setargs setenv bootargs ${bootargsubi}; run setargs; nand read ${baseaddr} 0x100000 0x300000; bootm ${baseaddr}\0" \
    "bootcmdnor=setenv setargs setenv bootargs ${bootargs}; run setargs; sf probe 0; sf read ${baseaddr} 0x50000 0x200000; bootm ${baseaddr}\0" \
    "setnand=run mtdpartsubi; setenv bootcmd ${bootcmdubi}; saveenv; reset\0" \
    "setnor8m=run mtdpartsnor8m; setenv bootcmd ${bootcmdnor}; saveenv; reset\0" \
    "setnor16m=run mtdpartsnor16m; setenv bootcmd ${bootcmdnor}; saveenv; reset\0" \
    "restore=n\0" \
    "osmem=mem=39M@0x0 ispmem=5M@0x2700000 rmem=20M@0x2c00000\0" \
    "soc="CONFIG_PRODUCTNAME

#undef CONFIG_OSD_ENABLE

#ifndef CONFIG_XM_COMPATIBLE
    #define CONFIG_ENV_OFFSET       0x40000
#else
    #define CONFIG_ENV_OFFSET       0x30000
#endif
#define CONFIG_ENV_SIZE         0x10000

#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT	"OpenIPC # "

#define CONFIG_CMD_RUN 1
#define CONFIG_BOOTDELAY 1
#define CONFIG_KERNEL_LOAD_ADDR 0x82000000
#define CONFIG_CMD_TFTPPUT 1
#define CONFIG_CMD_FAT 1
#define CONFIG_CMD_FS_GENERIC 1
#define CONFIG_NETMASK 255.255.255.0
#define CONFIG_GATEWAYIP 192.168.1.1
#define CONFIG_SERVERIP 192.168.1.1
#define CONFIG_IPADDR 192.168.1.10