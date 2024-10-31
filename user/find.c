#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"


char*
fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return name, ended with a null character; now we have a
  // proper C string
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), '\0', DIRSIZ-strlen(p));
  return buf;
}


void
find(char* path, char* file_name)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  // Check for possible path
  if(strlen(path) + 1 + DIRSIZ + 1 > 512){
    fprintf(2, "find: path too long\n");
    return;
  }

  // Check whether path is directory path
  if((fd = open(path, 0)) < 0){
    fprintf(2, "find: path %s does not exist\n", path);
    return;
  }

  // Check whether path has stats
  if(fstat(fd, &st) < 0){
    fprintf(2, "find: unknown path %s\n", path);
    close(fd);
    return;
  }

  // Copy the path into buffer
  strcpy(buf, path);
  p = buf + strlen(buf);
  *p++ = '/';

  // Loop to go through the directory content
  while(read(fd, &de, sizeof(de)) == sizeof(de)){
    if(de.inum == 0)
      continue;

    // 'st' will keep info for 'buf' which is a string copy of path.
    memmove(p, de.name, DIRSIZ);
    p[DIRSIZ] = 0;
    if(stat(buf, &st) < 0){
      printf("find: cannot stat %s\n", buf);
      continue;
    }

    // Compare the file_name string and the filename extracted from buf
    if (st.type == T_FILE){
      if (strcmp(fmtname(buf), file_name) == 0) {
        printf("%s\n", buf);
      }
    } else if (st.type == T_DIR){
      // No recursive into . and ..
      if (strcmp(fmtname(buf), ".") != 0 && strcmp(fmtname(buf), "..") != 0) {
        // Get new metadata for directory file
        int fd2 = open(buf, 0);
        // Recursive search in found directory
        find(buf, file_name);
        close(fd2);
      }
    }
  }
  close(fd);
}


int
main(int argc, char *argv[])
{
  if(argc < 2 || argc > 4){
    printf("[ERROR] Follow instruction: find [path] [expression]\n");
    exit(1);
  } else{
    find(argv[1], argv[2]);
    exit(0);
  }
}