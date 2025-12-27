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

ssize_t _write(int fd, const void *buf, size_t count) __attribute__((alias("write")));
int write(int fd, const void* buffer, unsigned int count) {
    if (fd < 3) {
        for (int i = 0; i < count; ++i)
            console_put_char(((const char*)buffer)[i]);
        return count;
    }

    uint32_t writen = 0;
    int res = vm_file_write(fd - 3, buffer, count, &writen);
    return writen;
}

ssize_t _read(int fd, void *buf, size_t count) __attribute__((alias("read")));
ssize_t read(int fd, void *buf, size_t count) {
    if(fd<3)
        return 0;

    uint32_t writen = 0;
    int res = vm_file_read(fd - 3, buf, count, &writen);
    return writen;
}

void * _sbrk(ptrdiff_t __incr) __attribute__((alias("sbrk")));
void * sbrk(ptrdiff_t __incr)
{
    exit(-100);
}

int _close(int fd) __attribute__((alias("close")));
int close(int fd) {
    if(fd < 3)
        return 0;

    vm_file_close(fd - 3);
    return 0;
}

off_t _lseek(int fd, off_t offset, int whence) __attribute__((alias("lseek")));
off_t lseek(int fd, off_t offset, int whence) {}

int _open(const char *pathname, int flags, ...) __attribute__((alias("open")));
int open(const char *pathname, int flags, ...)
{
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

void _exit(int status) __attribute__((alias("exit")));
void exit(int status)
{
	cprintf("exit(%d)\n", status);

    vm_exit_app();
	flush_layer();
    thread_next();
}

void abort(){
	cprintf("abort()\n");
	exit(-12);
}

pid_t _getpid(void) __attribute__((alias("getpid")));
pid_t getpid(void) { return 20;}

void _kill() __attribute__((alias("kill")));
void kill() {}

int _fstat(int fd, struct stat *buf) __attribute__((alias("fstat")));
int fstat(int fd, struct stat *buf) {
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

int _isatty(int fd) __attribute__((alias("isatty")));
int isatty(int fd) {}

int _stat(const char *path, struct stat *sbuf) __attribute__((alias("stat")));
int stat(const char *path, struct stat *sbuf) {}

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

int _link_r(char *old, char *new) __attribute__((alias("link_r")));
int link_r(char *old, char *new) {
	return -1;
}

int _unlink_r(char *name) __attribute__((alias("unlink_r")));
int unlink_r(char *name) {
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

int _gettimeofday(struct timeval *tv, struct timezone *tz) __attribute__((alias("gettimeofday")));
int gettimeofday(struct timeval *tv, struct timezone *tz) {
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