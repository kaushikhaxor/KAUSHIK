#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <thread>

int handle;

typedef char PACKAGENAME;
typedef int8_t BYTE;
long int get_module_base(int pid, const char *module_name)
{
 FILE *fp;
 long addr = 0;
 char *pch;
 char filename[32];
 char line[1024];
 snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
 fp = fopen(filename, "r");
 if (fp != NULL)
 {
  while (fgets(line, sizeof(line), fp))
  {
   if (strstr(line, module_name))
   {
    pch = strtok(line, "-");
    addr = strtoul(pch, NULL, 16);
    break;
   }
  }
  fclose(fp);
 }
 return addr;
}

int WriteFLOAT(long int addr, float value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}

int WriteDword(long int addr, int value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}
int WriteQword(long int addr, int value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}

int WriteBYTE(long int addr, BYTE value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}

int getPID(PACKAGENAME * PackageName)
{
 DIR *dir = NULL;
 struct dirent *ptr = NULL;
 FILE *fp = NULL;
 char filepath[256];
 char filetext[128];
 dir = opendir("/proc");
 if (NULL != dir)
 {
  while ((ptr = readdir(dir)) != NULL)
  {

   if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0))
    continue;
   if (ptr->d_type != DT_DIR)
    continue;
   sprintf(filepath, "/proc/%s/cmdline", ptr->d_name);
   fp = fopen(filepath, "r");
   if (NULL != fp)
   {
    fgets(filetext, sizeof(filetext), fp);
    if (strcmp(filetext, PackageName) == 0)
    {

     break;
    }
    fclose(fp);
   }
  }
 }
 if (readdir(dir) == NULL)
 {
  return 0;
 }
 closedir(dir);
 return atoi(ptr->d_name);
}

int main(int argc, char **argv)
{

 int ipid = getPID("com.pubg.imobile");
 if (ipid == 0)
 {
  ipid = getPID("com.pubg.krmobile");
  if (ipid == 0)
  {
   ipid = getPID("com.rekoo.pubgm");
   if (ipid == 0)
   {
    ipid = getPID("com.tencent.iglite");
          if (ipid == 0)
    {
     puts("PUBGM not running!");
     exit(1);
    }
   }
  }
 }
 char lj[64];
 sprintf(lj, "/proc/%d/mem", ipid);
 handle = open(lj, O_RDWR);
 if (handle == -1)
 {
  puts("Failed to initialise memory!\n");
  exit(1);
 }
 
puts("\n\n\KAUSHIK");
puts("\n\n\KAUSHIK");
puts("\n\n\KAUSHIK");
puts("\n\n\KAUSHIK");
puts("\n\n\KAUSHIK");
puts("Tg - @mrkaushikhaxor");

 char mname[] = "libUE4.so";
 char nname[] = "libanogs.so";
 
  long int UE4 = get_module_base(ipid, mname);
  long int anogs = get_module_base(ipid, nname);
  

WriteDword(anogs + 0xCC300,-0x29a0fc40); 
WriteDword(anogs + 0xCC328,-0x29a0fc40); 
WriteDword(anogs + 0xCC360,-0x29a0fc40);
WriteDword(anogs + 0xCCF94,-0x29a0fc40);
WriteDword(anogs + 0xCCFA8,-0x29a0fc40);
WriteDword(anogs + 0xCCFB0,-0x29a0fc40);
WriteDword(anogs + 0xCCFBC,-0x29a0fc40);
WriteDword(anogs + 0xCCFCC,-0x29a0fc40);
WriteDword(anogs + 0xCCF00,-0x29a0fc40);
WriteDword(anogs + 0xC9734,-0x29a0fc40);
WriteDword(anogs + 0x368B24,-0x29a0fc40);
WriteDword(anogs + 0x3682D0,-0x29a0fc40);
WriteDword(anogs + 0xCB684,-0x29a0fc40);
WriteDword(anogs + 0xCB76C,-0x29a0fc40);
WriteDword(anogs + 0xCB6CC,-0x29a0fc40);
WriteDword(anogs + 0xC9FDC,-0x29a0fc40);
WriteDword(anogs + 0xCCE20,-0x29a0fc40);
WriteDword(anogs + 0xCB4D8,-0x29a0fc40);
WriteDword(anogs + 0xCCF38,-0x29a0fc40);
WriteDword(anogs + 0xCCF64,-0x29a0fc40);
WriteDword(anogs + 0x17B70C,-0x29a0fc40);
WriteDword(anogs + 0x17B710,-0x29a0fc40);
WriteDword(anogs + 0x11CB60,-0x29a0fc40);
WriteDword(anogs + 0x183B80,-0x29a0fc40);
WriteDword(anogs + 0x2CBC84,-0x29a0fc40);
WriteDword(anogs + 0x2A30C4,-0x29a0fc40);
WriteDword(anogs + 0x2CBCF0,-0x29a0fc40);
WriteDword(anogs + 0x2A3040,-0x29a0fc40);
WriteDword(anogs + 0x2850F8,-0x29a0fc40);
WriteDword(anogs + 0x2686E4,-0x29a0fc40);
WriteDword(anogs + 0x253734,-0x29a0fc40);
WriteDword(anogs + 0x225730,-0x29a0fc40);
WriteDword(anogs + 0x2254D4,-0x29a0fc40);
WriteDword(anogs + 0x21E2C0,-0x29a0fc40);
WriteDword(anogs + 0x20C674,-0x29a0fc40);
WriteDword(anogs + 0x2069E4,-0x29a0fc40);
WriteDword(anogs + 0x2067CC,-0x29a0fc40);
WriteDword(anogs + 0x1F1BE4,-0x29a0fc40);
WriteDword(anogs + 0x1F1B48,-0x29a0fc40);
WriteDword(anogs + 0x194AF4,-0x29a0fc40);
WriteDword(anogs + 0x13B22C,-0x29a0fc40);
WriteDword(anogs + 0x133738,-0x29a0fc40);
WriteDword(anogs + 0xD4F58,-0x29a0fc40);
WriteDword(anogs + 0xCCF8C,-0x29a0fc40);
WriteDword(anogs + 0xCCCA0,-0x29a0fc40);
WriteDword(anogs + 0xCC390,-0x29a0fc40);
WriteDword(anogs + 0xCC2EC,-0x29a0fc40);
WriteDword(anogs + 0xCC0E4,-0x29a0fc40);
WriteDword(anogs + 0xCBBCC,-0x29a0fc40);
WriteDword(anogs + 0xCBC2C,-0x29a0fc40);
WriteDword(anogs + 0xCBB74,-0x29a0fc40);
WriteDword(anogs + 0xCB6F4,-0x29a0fc40);
WriteDword(anogs + 0xCB324,-0x29a0fc40);
WriteDword(anogs + 0xC9FDC,-0x29a0fc40);
WriteDword(anogs + 0xC9FAC,-0x29a0fc40);
WriteDword(anogs + 0x12C060,-0x29a0fc40);
WriteDword(anogs + 0x12C7FC,-0x29a0fc40);
WriteDword(anogs + 0x34C260,-0x29a0fc40);
WriteDword(anogs + 0xC9A24,-0x29a0fc40);
WriteDword(anogs + 0x1051A8,-0x29a0fc40);
WriteDword(anogs + 0x34CB44,-0x29a0fc40);
WriteDword(anogs + 0xCA3D4,-0x29a0fc40);
WriteDword(anogs + 0x34E55C,-0x29a0fc40);
WriteDword(anogs + 0x34E390,-0x29a0fc40);
WriteDword(anogs + 0x322778,-0x29a0fc40);
WriteDword(anogs + 0x388BA0,-0x29a0fc40);
WriteDword(anogs + 0x3AAF60,-0x29a0fc40); 
WriteDword(anogs + 0xCA250,-0x29a0fc40); 
WriteDword(anogs + 0x10C7E4,-0x29a0fc40); 
WriteDword(anogs + 0xC7AD0,-0x29a0fc40); 
WriteDword(anogs + 0xC94AC,-0x29a0fc40); 
WriteDword(anogs + 0xC7AD0,-0x29a0fc40); 
WriteDword(anogs + 0xC7AD4,-0x29a0fc40);
WriteDword(anogs + 0xECAB8,-0x29a0fc40); 
WriteDword(anogs + 0xF0E90,-0x29a0fc40); 
WriteDword(anogs + 0xF1860,-0x29a0fc40); 
WriteDword(anogs + 0xF2908,-0x29a0fc40); 
WriteDword(anogs + 0xF2AF0,-0x29a0fc40); 
WriteDword(anogs + 0xF2C84,-0x29a0fc40); 
WriteDword(anogs + 0xF2DC4,-0x29a0fc40); 
WriteDword(anogs + 0xF93BC,-0x29a0fc40); 
WriteDword(anogs + 0xF94E4,-0x29a0fc40); 
WriteDword(anogs + 0xFACE0,-0x29a0fc40); 
WriteDword(anogs + 0x10C330,-0x29a0fc40); 
WriteDword(anogs + 0x115020,-0x29a0fc40); 
WriteDword(anogs + 0x113868,-0x29a0fc40); 
WriteDword(anogs + 0x50BE08,-0x29a0fc40); 
WriteDword(anogs + 0x50BE10,-0x29a0fc40); 
WriteDword(anogs + 0x11B3E4,-0x29a0fc40); 
WriteDword(anogs + 0x4AC280,-0x29a0fc40); 
WriteDword(anogs + 0x4AC2C0,-0x29a0fc40); 
WriteDword(anogs + 0x37300C,-0x29a0fc40); 
WriteDword(anogs + 0x372C74,-0x29a0fc40); 
WriteDword(anogs + 0x3AAF50,-0x29a0fc40); 
WriteDword(anogs + 0x3AA378,-0x29a0fc40); 
WriteDword(anogs + 0x3AD8F8,-0x29a0fc40); 
WriteDword(anogs + 0x3AA418,-0x29a0fc40); 
WriteDword(anogs + 0x3AAA8C,-0x29a0fc40); 
WriteDword(anogs + 0x3AAE64,-0x29a0fc40); 
WriteDword(anogs + 0x3AAEE4,-0x29a0fc40); 
WriteDword(anogs + 0x3AA48C,-0x29a0fc40); 
WriteDword(anogs + 0x3AA4B0,-0x29a0fc40); 
WriteDword(anogs + 0x3AA510,-0x29a0fc40);
WriteDword(anogs + 0xCC300,-0x29a0fc40); 
WriteDword(anogs + 0xCC328,-0x29a0fc40); 
WriteDword(anogs + 0xCC360,-0x29a0fc40);
WriteDword(anogs + 0xCCF94,-0x29a0fc40);
WriteDword(anogs + 0xCCFA8,-0x29a0fc40);
WriteDword(anogs + 0xCCFB0,-0x29a0fc40);
WriteDword(anogs + 0xCCFBC,-0x29a0fc40);
WriteDword(anogs + 0xCCFCC,-0x29a0fc40);
WriteDword(anogs + 0xCCF00,-0x29a0fc40);
WriteDword(anogs + 0xC9734,-0x29a0fc40);
WriteDword(anogs + 0x368B24,-0x29a0fc40);
WriteDword(anogs + 0x3682D0,-0x29a0fc40);
WriteDword(anogs + 0xCB684,-0x29a0fc40);
WriteDword(anogs + 0xCB76C,-0x29a0fc40);
WriteDword(anogs + 0xCB6CC,-0x29a0fc40);
WriteDword(anogs + 0xC9FDC,-0x29a0fc40);
WriteDword(anogs + 0xCCE20,-0x29a0fc40);
WriteDword(anogs + 0xCB4D8,-0x29a0fc40);
WriteDword(anogs + 0xCCF38,-0x29a0fc40);
WriteDword(anogs + 0xCCF64,-0x29a0fc40);
WriteDword(anogs + 0x17B70C,-0x29a0fc40);
WriteDword(anogs + 0x17B710,-0x29a0fc40);
WriteDword(anogs + 0x11CB60,-0x29a0fc40);
WriteDword(anogs + 0x183B80,-0x29a0fc40);
WriteDword(anogs + 0x2CBC84,-0x29a0fc40);
WriteDword(anogs + 0x2A30C4,-0x29a0fc40);
WriteDword(anogs + 0x2CBCF0,-0x29a0fc40);
WriteDword(anogs + 0x2A3040,-0x29a0fc40);
WriteDword(anogs + 0x2850F8,-0x29a0fc40);
WriteDword(anogs + 0x2686E4,-0x29a0fc40);
WriteDword(anogs + 0x253734,-0x29a0fc40);
WriteDword(anogs + 0x225730,-0x29a0fc40);
WriteDword(anogs + 0x2254D4,-0x29a0fc40);
WriteDword(anogs + 0x21E2C0,-0x29a0fc40);
WriteDword(anogs + 0x20C674,-0x29a0fc40);
WriteDword(anogs + 0x2069E4,-0x29a0fc40);
WriteDword(anogs + 0x2067CC,-0x29a0fc40);
WriteDword(anogs + 0x1F1BE4,-0x29a0fc40);
WriteDword(anogs + 0x1F1B48,-0x29a0fc40);
WriteDword(anogs + 0x194AF4,-0x29a0fc40);
WriteDword(anogs + 0x13B22C,-0x29a0fc40);
WriteDword(anogs + 0x133738,-0x29a0fc40);
WriteDword(anogs + 0xD4F58,-0x29a0fc40);
WriteDword(anogs + 0xCCF8C,-0x29a0fc40);
WriteDword(anogs + 0xCCCA0,-0x29a0fc40);
WriteDword(anogs + 0xCC390,-0x29a0fc40);
WriteDword(anogs + 0xCC2EC,-0x29a0fc40);
WriteDword(anogs + 0xCC0E4,-0x29a0fc40);
WriteDword(anogs + 0xCBBCC,-0x29a0fc40);
WriteDword(anogs + 0xCBC2C,-0x29a0fc40);
WriteDword(anogs + 0xCBB74,-0x29a0fc40);
WriteDword(anogs + 0xCB6F4,-0x29a0fc40);
WriteDword(anogs + 0xCB324,-0x29a0fc40);
WriteDword(anogs + 0xC9FDC,-0x29a0fc40);
WriteDword(anogs + 0xC9FAC,-0x29a0fc40);
close(handle);
 return 0;
 }