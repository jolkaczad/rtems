/*---------------------------------------------------------------------------------
	$Id$

	access object in a GBFS file

	Copyright 2002-2005 Damian Yerrick

	Additional code Dave Murphy

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
	BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
	AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
	OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.

	$Log$
	Revision 1.1  2008/04/16 18:37:33  joel
	2008-04-16	Matthieu Bucchianeri <mbucchia@gmail.com>

		* ChangeLog, Makefile.am, README, bsp_specs, configure.ac,
		mk_libnds.sh, patch.libnds, preinstall.am, block/block.c,
		clock/clock.c, console/console.c, coproc/coproc.S, coproc/coproc.c,
		coproc/coproc.ld, dswifi/dswifi_license.txt, dswifi/makefile,
		dswifi/arm7/makefile, dswifi/arm7/source/wifi_arm7.c,
		dswifi/arm7/source/wifi_arm7.h, dswifi/arm9/makefile,
		dswifi/arm9/source/sgIP.c, dswifi/arm9/source/sgIP.h,
		dswifi/arm9/source/sgIP_ARP.c, dswifi/arm9/source/sgIP_ARP.h,
		dswifi/arm9/source/sgIP_Config.h, dswifi/arm9/source/sgIP_DHCP.c,
		dswifi/arm9/source/sgIP_DHCP.h, dswifi/arm9/source/sgIP_DNS.c,
		dswifi/arm9/source/sgIP_DNS.h, dswifi/arm9/source/sgIP_Hub.c,
		dswifi/arm9/source/sgIP_Hub.h, dswifi/arm9/source/sgIP_ICMP.c,
		dswifi/arm9/source/sgIP_ICMP.h, dswifi/arm9/source/sgIP_IP.c,
		dswifi/arm9/source/sgIP_IP.h, dswifi/arm9/source/sgIP_TCP.c,
		dswifi/arm9/source/sgIP_TCP.h, dswifi/arm9/source/sgIP_UDP.c,
		dswifi/arm9/source/sgIP_UDP.h, dswifi/arm9/source/sgIP_memblock.c,
		dswifi/arm9/source/sgIP_memblock.h,
		dswifi/arm9/source/sgIP_sockets.c, dswifi/arm9/source/sgIP_sockets.h,
		dswifi/arm9/source/wifi_arm9.c, dswifi/arm9/source/wifi_arm9.h,
		dswifi/common/source/dsregs.h, dswifi/common/source/spinlock.h,
		dswifi/common/source/spinlock.s, dswifi/common/source/wifi_shared.h,
		dswifi/include/dswifi7.h, dswifi/include/dswifi9.h,
		dswifi/include/dswifi_version.h, dswifi/include/netdb.h,
		dswifi/include/sgIP_errno.h, dswifi/include/netinet/in.h, fb/fb.c,
		fb/fb.h, include/bsp.h, include/my_ipc.h, include/tm27.h,
		include/types.h, include/sys/iosupport.h, irq/irq.c, irq/irq.h,
		libfat/gba/include/fat.h, libfat/include/fat.h,
		libfat/nds/include/fat.h, libfat/source/bit_ops.h,
		libfat/source/cache.c, libfat/source/cache.h, libfat/source/common.h,
		libfat/source/directory.c, libfat/source/directory.h,
		libfat/source/fatdir.c, libfat/source/fatdir.h,
		libfat/source/fatfile.c, libfat/source/fatfile.h,
		libfat/source/file_allocation_table.c,
		libfat/source/file_allocation_table.h, libfat/source/filetime.c,
		libfat/source/filetime.h, libfat/source/libfat.c,
		libfat/source/mem_allocate.h, libfat/source/partition.c,
		libfat/source/partition.h, libfat/source/disc_io/disc.c,
		libfat/source/disc_io/disc.h, libfat/source/disc_io/disc_io.h,
		libfat/source/disc_io/io_cf_common.c,
		libfat/source/disc_io/io_cf_common.h,
		libfat/source/disc_io/io_dldi.h, libfat/source/disc_io/io_dldi.s,
		libfat/source/disc_io/io_efa2.c, libfat/source/disc_io/io_efa2.h,
		libfat/source/disc_io/io_fcsr.c, libfat/source/disc_io/io_fcsr.h,
		libfat/source/disc_io/io_m3_common.c,
		libfat/source/disc_io/io_m3_common.h,
		libfat/source/disc_io/io_m3cf.c, libfat/source/disc_io/io_m3cf.h,
		libfat/source/disc_io/io_m3sd.c, libfat/source/disc_io/io_m3sd.h,
		libfat/source/disc_io/io_mpcf.c, libfat/source/disc_io/io_mpcf.h,
		libfat/source/disc_io/io_njsd.c, libfat/source/disc_io/io_njsd.h,
		libfat/source/disc_io/io_nmmc.c, libfat/source/disc_io/io_nmmc.h,
		libfat/source/disc_io/io_sc_common.c,
		libfat/source/disc_io/io_sc_common.h,
		libfat/source/disc_io/io_sccf.c, libfat/source/disc_io/io_sccf.h,
		libfat/source/disc_io/io_scsd.c, libfat/source/disc_io/io_scsd.h,
		libfat/source/disc_io/io_scsd_s.s,
		libfat/source/disc_io/io_sd_common.c,
		libfat/source/disc_io/io_sd_common.h, libnds/Makefile.arm7,
		libnds/Makefile.arm9, libnds/libnds_license.txt,
		libnds/basicARM7/source/defaultARM7.c,
		libnds/include/default_font_bin.h, libnds/include/gbfs.h,
		libnds/include/nds.h, libnds/include/nds/bios.h,
		libnds/include/nds/card.h, libnds/include/nds/dma.h,
		libnds/include/nds/interrupts.h, libnds/include/nds/ipc.h,
		libnds/include/nds/jtypes.h, libnds/include/nds/memory.h,
		libnds/include/nds/registers_alt.h, libnds/include/nds/reload.h,
		libnds/include/nds/system.h, libnds/include/nds/timers.h,
		libnds/include/nds/arm7/audio.h, libnds/include/nds/arm7/clock.h,
		libnds/include/nds/arm7/serial.h, libnds/include/nds/arm7/touch.h,
		libnds/include/nds/arm9/background.h,
		libnds/include/nds/arm9/boxtest.h, libnds/include/nds/arm9/cache.h,
		libnds/include/nds/arm9/console.h,
		libnds/include/nds/arm9/exceptions.h,
		libnds/include/nds/arm9/image.h, libnds/include/nds/arm9/input.h,
		libnds/include/nds/arm9/math.h, libnds/include/nds/arm9/ndsmotion.h,
		libnds/include/nds/arm9/pcx.h, libnds/include/nds/arm9/postest.h,
		libnds/include/nds/arm9/rumble.h, libnds/include/nds/arm9/sound.h,
		libnds/include/nds/arm9/sprite.h, libnds/include/nds/arm9/trig_lut.h,
		libnds/include/nds/arm9/video.h, libnds/include/nds/arm9/videoGL.h,
		libnds/source/arm7/audio.c, libnds/source/arm7/clock.c,
		libnds/source/arm7/microphone.c, libnds/source/arm7/spi.c,
		libnds/source/arm7/touch.c, libnds/source/arm7/userSettings.c,
		libnds/source/arm9/COS.bin, libnds/source/arm9/COS.s,
		libnds/source/arm9/SIN.bin, libnds/source/arm9/SIN.s,
		libnds/source/arm9/TAN.bin, libnds/source/arm9/TAN.s,
		libnds/source/arm9/boxtest.c, libnds/source/arm9/console.c,
		libnds/source/arm9/dcache.s, libnds/source/arm9/default_font.bin,
		libnds/source/arm9/default_font.s,
		libnds/source/arm9/exceptionHandler.S,
		libnds/source/arm9/exceptionHandler.s,
		libnds/source/arm9/exceptions.c, libnds/source/arm9/gurumeditation.c,
		libnds/source/arm9/icache.s, libnds/source/arm9/image.c,
		libnds/source/arm9/initSystem.c, libnds/source/arm9/keys.c,
		libnds/source/arm9/ndsmotion.c, libnds/source/arm9/pcx.c,
		libnds/source/arm9/rumble.c, libnds/source/arm9/sound.c,
		libnds/source/arm9/system.c, libnds/source/arm9/touch.c,
		libnds/source/arm9/video.c, libnds/source/arm9/videoGL.c,
		libnds/source/common/biosCalls.s, libnds/source/common/card.c,
		libnds/source/common/gbfs.c,
		libnds/source/common/interruptDispatcher.s,
		libnds/source/common/interrupts.c, rtc/rtc.c, sound/sound.c,
		sound/sound.h, start/start.S, startup/linkcmds, startup/start.c,
		timer/timer.c, tools/Makefile.am, tools/bin2s, tools/bin2s.c,
		tools/configure.ac, tools/runtest,
		tools/ndstool/include/arm7_sha1_homebrew.h,
		tools/ndstool/include/arm7_sha1_nintendo.h,
		tools/ndstool/include/banner.h, tools/ndstool/include/bigint.h,
		tools/ndstool/include/crc.h, tools/ndstool/include/default_icon.h,
		tools/ndstool/include/encryption.h, tools/ndstool/include/header.h,
		tools/ndstool/include/hook.h, tools/ndstool/include/little.h,
		tools/ndstool/include/loadme.h, tools/ndstool/include/logo.h,
		tools/ndstool/include/ndscreate.h,
		tools/ndstool/include/ndsextract.h, tools/ndstool/include/ndstool.h,
		tools/ndstool/include/ndstree.h, tools/ndstool/include/overlay.h,
		tools/ndstool/include/passme.h, tools/ndstool/include/passme_sram.h,
		tools/ndstool/include/passme_vhd1.h,
		tools/ndstool/include/passme_vhd2.h, tools/ndstool/include/raster.h,
		tools/ndstool/include/sha1.h, tools/ndstool/include/types.h,
		tools/ndstool/source/arm7_sha1_homebrew.c,
		tools/ndstool/source/arm7_sha1_nintendo.c,
		tools/ndstool/source/banner.cpp, tools/ndstool/source/bigint.cpp,
		tools/ndstool/source/compile_date.c, tools/ndstool/source/crc.cpp,
		tools/ndstool/source/default_icon.c,
		tools/ndstool/source/encryption.cpp, tools/ndstool/source/header.cpp,
		tools/ndstool/source/hook.cpp, tools/ndstool/source/loadme.c,
		tools/ndstool/source/logo.cpp, tools/ndstool/source/ndscodes.cpp,
		tools/ndstool/source/ndscreate.cpp,
		tools/ndstool/source/ndsextract.cpp,
		tools/ndstool/source/ndstool.cpp, tools/ndstool/source/ndstree.cpp,
		tools/ndstool/source/passme.cpp, tools/ndstool/source/passme_sram.c,
		tools/ndstool/source/raster.cpp, tools/ndstool/source/sha1.cpp,
		touchscreen/README.reco, touchscreen/parser.c, touchscreen/reco.c,
		touchscreen/reco.h, touchscreen/touchscreen.c,
		touchscreen/touchscreen.h, wifi/compat.c, wifi/compat.h, wifi/wifi.c:
		New files.

	Revision 1.5  2006/05/05 05:32:06  wntrmute
	consistency formatting

	Revision 1.4  2006/02/25 02:31:12  wntrmute
	tabs, not spaces

	Revision 1.3  2005/09/20 04:59:44  wntrmute
	*** empty log message ***

	Revision 1.2  2005/08/23 17:06:10  wntrmute
	converted all endings to unix

	Revision 1.1  2005/08/04 17:55:44  wntrmute
	added gbfs


---------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
	This code assumes a LITTLE ENDIAN target.  It'll need a boatload
	of itohs and itohl calls if converted to run on Sega Genesis.  It
	also assumes that the target uses 16-bit short and 32-bit longs.
---------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <nds/jtypes.h>
#include "gbfs.h"

/*---------------------------------------------------------------------------------
	change this to the end of your ROM,
	or to 0x02040000 for gba multiboot
	or to 0x24000000 for nds main ram
---------------------------------------------------------------------------------*/

static const u32 * GBFS_1ST_SEARCH_LIMIT = (const u32 *)0x02400000;
static const u32 * GBFS_2ND_SEARCH_START = (const u32 *)0x08000000;
static const u32 * GBFS_2ND_SEARCH_LIMIT = (const u32 *)0x0a000000;
/*---------------------------------------------------------------------------------
	a power of two, less than or equal to the argument passed to
	padbin.  Increasing the stride makes find_first_gbfs_file()
	faster at the cost of a slightly larger binary.
---------------------------------------------------------------------------------*/
static int GBFS_STRIDE = 256;

/*---------------------------------------------------------------------------------
	Set the search limits and stride for searching
---------------------------------------------------------------------------------*/
void gbfs_search_range(
	u32 gbfs_1st_limit,
	u32 gbfs_2nd_start, u32 gbfs_2nd_limit,
	u32 gbfs_stride
) {
//---------------------------------------------------------------------------------
	if ( NULL != gbfs_1st_limit ) GBFS_1ST_SEARCH_LIMIT = (u32 *)gbfs_1st_limit;
	if ( NULL != gbfs_2nd_limit ) GBFS_2ND_SEARCH_LIMIT = (u32 *)gbfs_2nd_limit;
	if ( NULL != gbfs_2nd_start ) GBFS_2ND_SEARCH_START = (u32 *)gbfs_2nd_start;
	if ( NULL != gbfs_stride ) GBFS_STRIDE = gbfs_stride;

}

//---------------------------------------------------------------------------------
const GBFS_FILE * find_first_gbfs_file(const void *start) {
//---------------------------------------------------------------------------------
	/* align the pointer */
	const u32 *here = (const u32 *)
											((unsigned long)start & (-GBFS_STRIDE));
	const char rest_of_magic[] = "ightGBFS\r\n\x1a\n";

	/* Linear-search first in multiboot space. */
	while(here < GBFS_1ST_SEARCH_LIMIT)
	{
		/*	We have to keep the magic code in two pieces; otherwise,
			this function may find itself and think it's a GBFS file.
			This obviously won't work if your compiler stores this
			numeric literal just before the literal string, but Devkit
			Advance R4 and R5 seem to keep numeric constant pools
			separate enough from string pools for this to work.
		*/
		if(*here == 0x456e6950) { /* ASCII code for little endian "PinE" */
			/*	We've matched the first four bytes.
				If the rest of the magic matches, then we've found a file. */
			if(!memcmp(here + 1, rest_of_magic, 12))
				return (const GBFS_FILE *)here;
		}
		here += GBFS_STRIDE / sizeof(here);
 }

	/* Now search in ROM space. */
	if(here < GBFS_2ND_SEARCH_START)
		here = GBFS_2ND_SEARCH_START;
	while(here < GBFS_2ND_SEARCH_LIMIT) {
		/* Search loop same as above. */
		if(*here == 0x456e6950) {  /* ASCII code for little endian "PinE" */
			if(!memcmp(here + 1, rest_of_magic, 12))
				return (const GBFS_FILE *)here;
		}
		here += GBFS_STRIDE / sizeof(*here);
	}
	return 0;
}


//---------------------------------------------------------------------------------
const void *skip_gbfs_file(const GBFS_FILE *file) {
//---------------------------------------------------------------------------------
	return ((char *)file + file->total_len);
}


//---------------------------------------------------------------------------------
static int namecmp(const void *a, const void *b) {
//---------------------------------------------------------------------------------
	return memcmp(a, b, 24);
}


//---------------------------------------------------------------------------------
const void *gbfs_get_obj(	const GBFS_FILE *file,
							const char *name,
							u32 *len) {
//---------------------------------------------------------------------------------
	char key[24] = {0};

	const GBFS_ENTRY *dirbase = (const GBFS_ENTRY *)((const char *)file + file->dir_off);
	size_t n_entries = file->dir_nmemb;
	const GBFS_ENTRY *here;

	strncpy(key, name, 24);

	here = bsearch(	key, dirbase,
					n_entries, sizeof(GBFS_ENTRY),
					 namecmp);
	if(!here)
		return NULL;

	if(len)
		*len = here->len;
	return (char *)file + here->data_offset;
}


//---------------------------------------------------------------------------------
const void *gbfs_get_nth_obj(	const GBFS_FILE *file,
							 	size_t n,
								char *name,
								u32 *len)
//---------------------------------------------------------------------------------
{
	const GBFS_ENTRY *dirbase = (const GBFS_ENTRY *)((const char *)file + file->dir_off);
	size_t n_entries = file->dir_nmemb;
	const GBFS_ENTRY *here = dirbase + n;

	if(n >= n_entries)
		return NULL;

	if(name) {
		strncpy(name, here->name, 24);
		name[24] = 0;
	}

	if(len)
		*len = here->len;

	return (char *)file + here->data_offset;
}


//---------------------------------------------------------------------------------
void *gbfs_copy_obj(	void *dst,
						const GBFS_FILE *file,
						const char *name) {
//---------------------------------------------------------------------------------
	u32 len;
	const void *src = gbfs_get_obj(file, name, &len);

	if(!src)
		return NULL;

	memcpy(dst, src, len);
	return dst;
}


//---------------------------------------------------------------------------------
size_t gbfs_count_objs(const GBFS_FILE *file) {
//---------------------------------------------------------------------------------
	return file ? file->dir_nmemb : 0;
}

