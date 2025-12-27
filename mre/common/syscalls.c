#include <console.h>
#include <vmsys.h>
//#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

ssize_t _write(int fd, const void *buf, size_t count) __attribute__((alias("write")));
int write(int fd, const void* buffer, unsigned int count) {
	for (int i = 0; i < count; ++i)
		console_put_char(((const char*)buffer)[i]);
	return count;
}

ssize_t _read(int fd, void *buf, size_t count) __attribute__((alias("read")));
ssize_t read(int fd, void *buf, size_t count) {}

void * _sbrk(ptrdiff_t __incr) __attribute__((alias("sbrk")));
void * sbrk(ptrdiff_t __incr) {}

int _close(int fd) __attribute__((alias("close")));
int close(int fd) {}

off_t _lseek(int fd, off_t offset, int whence) __attribute__((alias("lseek")));
off_t lseek(int fd, off_t offset, int whence) {}

int _open(const char *_Filename,int _OpenFlag, ...) __attribute__((alias("open")));
int open(const char *_Filename,int _OpenFlag, ...) {}

void _exit(int status) __attribute__((alias("exit")));
void exit(int status) {}

pid_t _getpid(void) __attribute__((alias("getpid")));
pid_t getpid(void) { return 20;}

void _kill() __attribute__((alias("kill")));
void kill() {}

int _fstat(int fd, struct stat *buf) __attribute__((alias("fstat")));
int fstat(int fd, struct stat *buf) {
	return -1;
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

int mkdir(const char *_path, mode_t __mode) {}

int rmdir(const char *dirname) {}

int _link_r(char *old, char *new) __attribute__((alias("link_r")));
int link_r(char *old, char *new) {
	return -1;
}

int _unlink_r(char *name) __attribute__((alias("unlink_r")));
int unlink_r(char *name) {
	return -1;
}


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