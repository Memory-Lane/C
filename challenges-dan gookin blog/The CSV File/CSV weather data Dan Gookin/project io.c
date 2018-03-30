/********************************
 * Michael Otyeno               *
 * April 10 2017                *
 * Dan Gookin Solution          *
 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 80

int main()
{
	char filename[] = "C:\\Users\\PC\\Downloads\\Essentials\\Self Taught\\challenges-dan gookin blog\\The CSV File\\weather_data original.csv";
	char buffer[BSIZE];
	FILE *f;
	char *field;
	int i,year,month,day;
	float high,low;
	char *months[] = { "January", "February", "March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December" };

	/* open the CSV file */
	f = fopen(filename,"r");
	if( f == NULL)
	{
		printf("Unable to open file '%s'\n",filename);
		exit(1);
	}

	/* process the data */
	/* the file contains 5 fields in a specific order:
	   year,month,day,high,low
	   separated by commas */
	i = 1;
	while(fgets(buffer,BSIZE,f))
	{
		/* get year */
		field=strtok(buffer,",");
		year=atoi(field);
		/* get month */
		field=strtok(NULL,",");
		month=atoi(field);
		month--;	/* for the months[] array */
		/* get day */
		field=strtok(NULL,",");
		day=atoi(field);
		/* get high */
		field=strtok(NULL,",");
		high=atof(field);
		/* get low */
		field=strtok(NULL,",");
		low=atof(field);
		/* display the result in the proper format */
		printf("%2i.%10s %2d %d:\tHigh %.1f\tLow %.1f\n",
                i++,
				months[month],
				day,
				year,
				high,
				low);
	}

	/* close file */
	fclose(f);

	return(0);
}

