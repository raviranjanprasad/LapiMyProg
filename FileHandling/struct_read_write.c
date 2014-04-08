#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * http://www.daniweb.com/code/snippet278.html
 */
char *mygetline(char *line, int size)
{
	if ( fgets(line, size, stdin) )
	{
		char *newline = strchr(line, '\n'); /* check for trailing '\n' */
		if ( newline )
		{
			*newline = '\0'; /* overwrite the '\n' with a terminating null */
		}
	}
	return line;
}

/*
 * http://www.daniweb.com/code/snippet266.html
 */
int mygeti(int *result)
{
	char buff [ 13 ]; /* signed 32-bit value, extra room for '\n' and '\0' */
	return fgets(buff, sizeof buff, stdin) && sscanf(buff, "%d", result) == 1;
}

struct record
{
	char name[30];
	int age;
};

void record_write(const char *filename)
{
	FILE *file = fopen(filename, "ab"); /* append to the file in binary mode */
	if ( file != NULL )
	{
		struct record data;
		/*
		 * Read a string from the user. Put it into the structure.
		 */
		printf("Enter name: ");
		fflush(stdout);
		mygetline(data.name, sizeof data.name);
		/*
		 * Read a string from the user. Put it into the structure.
		 */
		do
		{
			printf("Enter age: ");
			fflush(stdout);
		} while ( !mygeti(&data.age) );
		/*
		 * Write the data to the file.
		 */
		fwrite(&data, sizeof data, 1, file);
		fclose(file);
	}
}

void record_readall(const char *filename)
{
	FILE *file = fopen(filename, "rb"); /* read from the file in binary mode */
	if ( file != NULL )
	{
		struct record data;
		while ( fread(&data, sizeof data, 1, file) == 1 ) /* read all records */
		{
			printf("%s,%d\n", data.name, data.age); /* print each */
		}
		fclose(file);
	}
}

int main()
{
	static const char filename[] = "output.dat";
	/*
	 * Loop as long as the user wants to add records.
	 */
	for ( ;; )
	{
		char line[10];
		fputs("Add record (Y/N)? ", stdout);
		fflush(stdout);
		mygetline(line, sizeof line);
		if ( tolower(*line) == 'n' )
		{
			break;
		}
		record_write(filename);
	}
	/*
	 * Show all records in the file.
	 */
	record_readall(filename);
	return 0;

}

