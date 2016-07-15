
#include <asm-generic/funcs.h>
#include <aim/initcalls.h>
#include <fs/vfs.h>
#include <fs/mount.h>
#include <fs/vnode.h>
#include <fs/specdev.h>
#include <fs/ufs/ufs.h>
#include <fs/ufs/ext2fs/ext2fs.h>
#include <panic.h>

struct vfsops ext2fs_vfsops = {
	.root = ufs_root,
	.vget = ext2fs_vget
};

struct vops ext2fs_vops = {
	.open = NOTSUP,
	.close = NOTSUP,
	.read = ext2fs_read,
	.write = NOTSUP,
	.inactive = ext2fs_inactive,
	.reclaim = ext2fs_reclaim,
	.strategy = ufs_strategy,
	.lookup = ext2fs_lookup,
	.bmap = ext2fs_bmap,
};

/*
 * Special file operations on an ext2 file system.
 * This is a combination of the ordinal spec ops and ext2 ops.
 */
struct vops ext2fs_specvops = {
	.open = spec_open,
	.close = spec_close,	/* shall we clean inode etc? */
	.read = spec_read,
	.write = spec_write,
	.inactive = ext2fs_inactive,
	.reclaim = ext2fs_reclaim,
	.strategy = spec_strategy,
	.lookup = NOTSUP,
	.bmap = NOTSUP
};

int
ext2fs_register(void)
{
	registerfs("ext2fs", &ext2fs_vfsops);
	register_mountroot(ext2fs_mountroot);
	return 0;
}
INITCALL_FS(ext2fs_register);
