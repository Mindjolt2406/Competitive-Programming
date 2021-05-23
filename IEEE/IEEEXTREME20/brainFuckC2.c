#include <stdio.h>
#include <stdlib.h>

int readInt()
{
	int thisChar = getchar();
	int n = 0;
	while (thisChar != EOF && thisChar != '\n') {
			n = n * 10 + thisChar - '0';
			thisChar = getchar();
	}
	return n;
}

int main(int argc, char **argv)
{
	int t;
	t = readInt();
	while(t--){
	unsigned char *cell = calloc(300, 1);
	unsigned char *cells = cell;
	if (!cell) {
		fprintf(stderr, "Error allocating memory.\n");
		return 1;
	}
		++cell;
		*cell = getchar();
		++cell;
		*cell = getchar();
		++cell;
		*cell = getchar();
		--cell;
	{
		*(cell+1) -= *(cell);
		*(cell+2) += *(cell);
		*cell = 0;
	}

	unsigned char *ptr = cell;
	cell += 2;
	*ptr += *cell;
	*cell -= *cell;
	cell -= 3;

	{
		*(cell+1) -= *(cell);
		*(cell-1) += *(cell);
		*(cell) = 0;
	}

		--cell;

	{
		*(cell+1) += *(cell);
		*cell = 0;
	}

		cell += 6;
		++*cell;
		cell += 7;
		++*cell;

	printf("Hoof\n");
	while (*cell) {
		cell += 4;
		*cell = 0;
		--cell;
		*cell = 0;
		--cell;
		*cell = 0;
		--cell;
		*cell = 0;
		--cell;
		*cell = 0;
		cell -= 12;
	
	{
		*(cell+7) += *(cell);
		*(cell+13) += *(cell);
		*cell = 0;
	}

		++cell;
	{
		*(cell+7) += *(cell);
		*(cell+13) += *(cell);
		*cell = 0;
	}
		++cell;
	
	{
		*(cell+7) += *(cell);
		*(cell+13) += *(cell);
		*cell = 0;
	}
		cell += 2;
		++*cell;
		++cell;
		++*cell;

	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;

	// Okay
	while (*cell) {
		--*cell;
		cell += 2;
		++*cell;
		cell -= 3;
	}
		cell += 4;
	
	{
		*(cell-7) += *(cell);
		*cell = 0;
	}
		++cell;
	{
		*(cell-7) += *(cell);
		*cell = 0;
	}
		++cell;
	{
		*(cell-7) += *(cell);
		*cell = 0;
	}
		cell += 7;
		++*cell;

	while (*cell) {
			--*cell;
			cell -= 11;
		{
			*(cell+2) += *(cell);
			*(cell+4) += *(cell);
			*cell = 0;
		}

			++cell;
		{
			*(cell+2) += *(cell);
			*(cell+4) += *(cell);
			*cell = 0;
		}
			++cell;

		{
			*(cell-2) += *(cell);
			*cell = 0;
		}
			++cell;
		{
			*(cell-2) += *(cell);
			*cell = 0;
		}
			++*cell;
			
		while (*cell) {
		
			*cell = 0;
			++*cell;
			++cell;

			// Okay
		while (*cell) {
			--cell;
			--*cell;
		}
			--cell;
			// Okay
		while (*cell) {
			--*cell;
			cell += 2;
			--*cell;
			cell -= 3;
		}
			cell += 2;
			--*cell;
			cell += 3;
			++*cell;
			++cell;

			// Okay
		while (*cell) {
			--cell;
			--*cell;
		}
			--cell;
			// Okay
		while (*cell) {
			--*cell;
			++cell;
			++*cell;
			++cell;
			// Okay
		while (*cell) {
			--*cell;
			--cell;
			--*cell;
		}
			--cell;
		while (*cell) {
			cell += 2;
		while (*cell) {
			--*cell;
			cell -= 2;
			--*cell;
			++cell;
		}
			--*cell;
			cell -= 2;
		while (*cell) {
			--*cell;
			++cell;
			--*cell;
			cell += 2;
			--*cell;
			cell -= 4;
		}
		}
			--cell;
		}
			cell += 2;
			--*cell;
			cell -= 5;
			++*cell;
			++cell;

			// Okay
		while (*cell) {
			--cell;
			--*cell;
		}
			--cell;

			// Okay
		while (*cell) {
			cell += 2;
		while (*cell) {
			cell -= 2;
			--*cell;
			++cell;
		}
			cell -= 2;

			// Okay
		while (*cell) {
			--cell;
		}

		}
			++cell;
			--*cell;
		}
			cell += 8;
			++*cell;
	}

		--*cell;
		cell -= 4;
		++*cell;
		++cell;
		++*cell;

	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	while (*cell) {
		cell += 2;
		++*cell;
		// Okay
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;
		while (*cell) 
		{
			cell += 3;
			++*cell;
			while (*cell) 
			{
				cell -= 3;
				--*cell;
				cell += 2;
			}
			cell -= 3;
			while (*cell) 
			{
				--cell;
			}
		}
	}
		++cell;
		--*cell;
	}
	printf("Hoof\n");
		cell += 4;
	*cell = 0;
		cell -= 14;
	*cell = 0;
		cell += 2;
		++*cell;
		++cell;
		++*cell;
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	
	// Okay
	while (*cell) {
		--*cell;
		cell += 2;
		++*cell;
		cell -= 3;
	}

	++cell;
	++*cell;
	++cell;

	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}

		--cell;
	// Okkay
	while (*cell) {
		cell += 2;
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;

	//Okay
	while (*cell) {
		--cell;
	}
	}

		++cell;
		--*cell;
	// Okay
	while (*cell) {
		++*cell;
		cell += 6;
		*cell += 10;
		cell -= 6;
		++*cell;
		++cell;
	
	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	
	// Okay
	while (*cell) {
		cell += 2;
		while (*cell) {
			cell -= 2;
			--*cell;
			++cell;
		}
			cell -= 2;
		while (*cell) {
			--cell;
		}
	}
		++cell;
		--*cell;
		// Okay
	while (*cell) {
		*cell += 2;
		++cell;
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
		// Okay
	while (*cell) {
		--*cell;
		cell += 2;
		--*cell;
		cell -= 3;
	}
		cell += 2;
		--*cell;
		cell += 2;
		++*cell;
		cell += 2;
		++*cell;
		++cell;
		--*cell;
		// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
		// Okay
	while (*cell) {
		cell -= 2;
	
	{
		*(cell+3) += *(cell);
		*(cell) = 0;
	}
	
		cell += 5;
		++*cell;
		++cell;
		++*cell;

	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
		// Okay
	while (*cell) {
		--*cell;
		cell += 2;
		++*cell;
		cell -= 3;
	}
		cell -= 2;
		--*cell;
		--cell;
	}
		cell -= 4;
		++*cell;
		++cell;
		// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	// Okay
	while (*cell) {
		cell += 2;
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;
	while (*cell) {
		--cell;
	}
	}
		++cell;
		--*cell;
	}
		cell += 2;
		*cell += 8;
	
	{
		*(cell+1) += 6*(*(cell));
		*cell = 0;
	}

		++cell;
	{
		*(cell-4) += (*cell);
		*cell -= *cell;
	}

		cell += 5;
		++*cell;
		++cell;

	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	while (*cell) {
		cell += 2;
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;
	while (*cell) {
		--cell;
	}
	}
		++cell;
		--*cell;
	while (*cell) {
		*cell += 2;
		++cell;
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	while (*cell) {
		--*cell;
		cell += 2;
		--*cell;
		cell -= 3;
	}
		cell += 2;
		--*cell;
		cell -= 8;
		++*cell;
		++cell;
		++*cell;
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	while (*cell) {
		--*cell;
		cell += 2;
		++*cell;
		cell -= 3;
	}
		cell += 8;
		++*cell;
		++cell;
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
		
	// Okay
	while (*cell) {
		cell += 2;
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;
	while (*cell) {
		--cell;
	}
	}
		++cell;
		--*cell;
	}
		cell -= 2;
		*cell = 0;
		cell -= 5;
		++*cell;
		++cell;

	// Okay
	while (*cell) {
		--cell;
		--*cell;
	}
		--cell;
	
	// Okay
	while (*cell) {
		cell += 2;
		// Okay
	while (*cell) {
		cell -= 2;
		--*cell;
		++cell;
	}
		cell -= 2;
	// Okay
	while (*cell) {
		--cell;
	}
	}
		++cell;
		--*cell;
	}
		cell -= 2;
	while (*cell) {
		putchar(*cell);
		--cell;
	}

	// free(cells);
	putchar('\n');
	if(t!=0) getchar();
	}
	return 0;
}

