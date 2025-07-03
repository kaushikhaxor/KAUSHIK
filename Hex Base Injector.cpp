// - Tool by @Mrkaushikhaxor
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <thread>
#include <stdint.h>

typedef unsigned char BYTE;

int handle;
typedef char PACKAGENAME;


//---------------------------------------------------
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

int kaushikqword(long long int addr, long long int value) {
    pwrite64(handle, &value, 8, addr);
    return 0;
}

int kaushikdword(long int addr, int value)
{
	pwrite64(handle, &value, 4, addr);
	return 0;
}

int kaushikfloat(long int addr, float value)
{
	pwrite64(handle, &value, 4, addr);
	return 0;
}

 int kaushikhex(long int addr, BYTE* hex_value, int size)
{
    pwrite64(handle, hex_value, size, addr);
    return 0;
}


void kaushikhex(long int address, char* hex_value) {
    int hex_len = strlen(hex_value) / 3 +1;
    BYTE* hex_bytes = (BYTE*)malloc(hex_len * sizeof(BYTE));
    for (int i = 0; i < hex_len; i++) {
        char byte_str[3] = {hex_value[i*3], hex_value[i*3+1], '\0'};
        hex_bytes[i] = strtol(byte_str, NULL, 16);
    }
   kaushikhex(address, hex_bytes, hex_len);
   BYTE* read_bytes = (BYTE*)malloc(hex_len * sizeof(BYTE));
    pread64(handle, read_bytes, hex_len, address);
    int is_equal = 1;
    for (int i = 0; i < hex_len; i++) {
        if (hex_bytes[i] != read_bytes[i]) {
            is_equal = 0;
            break;
        }
    }

    if (is_equal) {
        printf("Successfully wrote %d bytes to address 0x%lx\n", hex_len, address);
    } else {
        printf("Failed to write bytes to address 0x%lx\n", address);
    }

    free(hex_bytes);
    free(read_bytes);
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

//---------------------------------------------------

int main(int argc, char **argv)
{
	int gs;
	int ipid = getPID("com.pubg.imobile");
	char lj[64];
	sprintf(lj, "/proc/%d/mem", ipid);
	handle = open(lj, O_RDWR);
	if (handle == -1)
	{
		exit(1);
	}


            char mname[] = ("libUE4.so");
            long int libbase = get_module_base(ipid, mname);
            
			char nname[] = "libanogs.so";
	        long int libanogs = get_module_base(ipid, nname);

			char oname[] = "libgcloud.so";
	        long int libgcloud = get_module_base(ipid, oname);

			char pname[] = "libTDataMaster.so";
	        long int libTDataMaster = get_module_base(ipid, pname);
	
// add Bypass 
kaushikhex(libanogs + 0x1B3588, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1BC130, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1BBE04, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1B47BC, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1B13C0, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1B4274, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1BFA08, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1BFBAC, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1B30C8, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1E7C24, "00 00 80 D2 C0 03 5F D6");
kaushikhex(libanogs + 0x1ACC08, "00 00 80 D2 C0 03 5F D6");





	close(handle);
	return 0;
}