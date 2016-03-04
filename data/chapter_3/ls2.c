/* ls2.c
 * 
 * purpose list contents of directories
 * action if no args, use . else list files in args
 * <note> uses `stat` and `pwd.h` and `grp.h`
 * BUG: try ls2 /tmp
 * */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void do_ls(char []);
void dostat(char *);
void show_file_info(char *, struct stat *);
void mode_to_name(uid_t);
char *uid_to_name(uid_t);
char *gid_to_name(git_t);

void main(int ac, char *av[])
{

  if (ac == 1)
     do_ls(".");
  else
     while (--ac) {
       printf("%s\n", * ++av);
       do_ls(*av);
     }
}

void do_ls(char dirname[])
/*
 * list files in directory called dirname 
 * */
{
  DIR *dir_ptr;           /* the directory */
  struct dirent *direntp; /* each entry */

  if ((dir_ptr = opendir(dirname)) == NULL )
     fprintf(stderr, "ls2:cannot open %s\n", dirname);
  else {
     while ((direntp = readdir(dir_ptr)) != NULL )
         dostat(direntp->d_name);
     closedir(dir_ptr);
  }
}


void dostat(char *filename)
{
  struct stat info;
  if (stat(filename, &info) == -1)    /* cannot stat */
    perror(filename);                 /* say why */
  else
   show_file_info(filename, &info);

}

void show_file_info(file)
/*
 * display the info about filename. The info is stored in struct at *info_p
 * */
{
  

