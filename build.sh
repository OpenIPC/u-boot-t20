#!/bin/sh

set -e

export ARCH=mips
export CROSS_COMPILE=${CROSS_COMPILE:-mips-linux-gnu-}

OUTPUTDIR="${HOME}/src/hisi/uboot"
SOCS="t10 t20"

for soc in ${SOCS};do

make clean
make isvp_${soc}_sfcnor
make -j 8

cp u-boot-with-spl.bin u-boot-${soc}.bin
cp u-boot-${soc}.bin ${OUTPUTDIR}/u-boot-${soc}-universal.bin

done