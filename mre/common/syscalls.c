#include <console.h>
#include <vmsys.h>
#include <vmio.h>
#include <vmchset.h>
#include <vmstdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <vmsys.h>
#include <fcntl.h>
#include <sys/types.h>

#include <thread.h>

VMWCHAR wpath_buf[256];

#define SYSCALL(ret_type, func_name, args_def) \
    ret_type _##func_name args_def __attribute__((alias(#func_name))); \
    ret_type func_name args_def

SYSCALL(int, write, (int fd, const void* buffer, unsigned int count)){
    if (fd < 3) {
        for (int i = 0; i < count; ++i)
            console_put_char(((const char*)buffer)[i]);
        return count;
    }

    uint32_t writen = 0;
    int res = vm_file_write(fd - 3, buffer, count, &writen);
    return writen;
}

SYSCALL(ssize_t, read, (int fd, void *buf, size_t count)){
    if(fd<3)
        return 0;

    uint32_t writen = 0;
    int res = vm_file_read(fd - 3, buf, count, &writen);
    return writen;
}

SYSCALL(void*, sbrk, (ptrdiff_t __incr)) {
    exit(-100);
}

SYSCALL(int, close, (int fd)) {
    if(fd < 3)
        return 0;

    vm_file_close(fd - 3);
    return 0;
}

SYSCALL(off_t, lseek, (int fd, off_t offset, int whence)) {}

SYSCALL(int, open, (const char *pathname, int flags, ...)) {
    VMUINT mre_mode = 0;
    if (flags == O_RDONLY)
        mre_mode = MODE_READ;
    if (flags & O_WRONLY)
        mre_mode |= MODE_WRITE;
    if (flags & O_RDWR)
        mre_mode |= MODE_WRITE | MODE_READ;
    if (flags & O_CREAT)
        mre_mode |= MODE_CREATE_ALWAYS_WRITE;
    if (flags & O_APPEND)
        mre_mode |= MODE_APPEND;

    vm_ascii_to_ucs2(wpath_buf, 256, pathname);
    int fd = vm_file_open(wpath_buf, mre_mode, 1);
    //cprintf("open(%s, %d) = %d\n", pathname, flags, fd);
    if (fd < 0)
        return -1;
    else
        return fd + 3;
}

SYSCALL(void, exit, (int status)) {
	cprintf("exit(%d)\n", status);

    vm_exit_app();
	flush_layer();
    thread_next();
}

SYSCALL(void, abort, ()){
	cprintf("abort()\n");
	exit(-12);
}

SYSCALL(pid_t, getpid, (void)) {
    return 20;
}

SYSCALL(void, kill, ()) {}

SYSCALL(int, fstat, (int fd, struct stat *buf)) {
    if (fd < 3)
        return -1;
    VMUINT file_size;
    if(vm_file_getfilesize(fd - 3, &file_size)<0)
        return -1;
    buf->st_dev = 0;
    buf->st_ino = 0;
    buf->st_mode = S_IFREG | S_IFMT | S_IRWXU | S_IRWXG | S_IRWXO;
    buf->st_nlink = 0;
    buf->st_uid = 0;
    buf->st_gid = 0;
    buf->st_rdev = 0;
    buf->st_size = file_size;
    buf->st_blksize = 2048;
    buf->st_blocks = file_size/512;
    return 0;
}

SYSCALL(int, isatty, (int fd)) {}

SYSCALL(int, stat, (const char *path, struct stat *sbuf)) {}

#ifdef WIN32
#define MODET
#else
#define MODET , mode_t __mode
#endif

int mkdir(const char *_path, mode_t __mode) {
    vm_ascii_to_ucs2(wpath_buf, 256, _path);
    return vm_file_mkdir(wpath_buf);
}

int rmdir(const char *dirname) {}

SYSCALL(int, link_r, (char *old, char *new)) {
	return -1;
}

SYSCALL(int, unlink_r, (char *name)) {
	return -1;
}

int fork(){
	return -1;
}

int waitpid(){
	return -1;
}

int execvp(){
	return -1;
}

int execv(){
	return -1;
}

int pipe(){
	return -1;
}

int log(){
	return -1;
}

int usleep(){
	return -1;
}

int ceil(){
	return -1;
}

int dup2(){
	return -1;
}

int fcntl (int, int, ...){}

#include <time.h>

SYSCALL(int, gettimeofday, (struct timeval *tv, struct timezone *tz)) {
	if (tv)
	{
		VMUINT sec = 0;
		vm_get_curr_utc(&sec);
		tv->tv_sec = sec;
		tv->tv_usec = 0;
	}
	return 0;
}

int getentropy (void *buf,
	 size_t buflen)
{
	for(int i=0;i<buflen;++i)
		((unsigned char*)buf)[i]=rand()%256;
	return 0;
}