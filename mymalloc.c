#include "mymalloc.h"

// this reports error when you have problems and it tells what lines and number of bytes too
void report_malloc_error(char *file, int line, int Bytes, char *reason)
{
         //Printing Errors by line number.
	printf("\nError: In file %s at line %d. We Cannot malloc %d bytes. %s.\n\n", file,line,Bytes,reason);
}

int heapStat(void)
{
	if (myblock[0] == 'b' && myblock[1] == 'o' && myblock[2]=='t')
		return 1;
	
	return 0;
}


void *mymalloc(int bytesNeeded,char *file, int line)
{
     //Using the function checkHeapstatus() we determine if heap is intialized or not.
	if (heapStat() == 0)
	  {
	    int k=3;
	    do
	      {
		myblock[k] = 0;
		++k;
	      }while(k<4096);
	
	    meta_tag *data = (meta_tag *)(&myblock[3]);	
		data->status= 2;
		data->memorySize = 4089;
	
		myblock[0] = 'b';
		myblock[1] = 'o';
		myblock[2] ='t';
        
	  }
	//if the requested size is more than which is available it should report error
	if((4096-sizeof(meta_tag))<bytesNeeded || bytesNeeded<=0)
	{
		report_malloc_error(file, line, bytesNeeded, " My heap doesn't have enough space to allocate this much amount of the memory");
		return NULL;
	}

	char *frontPosition = find(&myblock[3], bytesNeeded);
	if (frontPosition == NULL)
	{
		report_malloc_error(file, line, bytesNeeded, "For the requested size we cannot find the empty slot");
	//printf("\nError: In file %s at line %d. We Cannot malloc %d bytes. %s.\n\n", file,line,bytesNeeded);
		return NULL;
	}

	frontPosition = divide(frontPosition, bytesNeeded);
	//The void pointer which points to the start of the heap is returned.
	return (void *)(frontPosition);
}

char *find(char *start, int bytesNeeded)
{
	char *ptr1 = start;
	// It is taking the starting position of the heap.
	int memory;
	memory = 4089;
	// We save the address in memory, we can use a bigger value for address        but we opted a smaller number. 
	//Creating new meta_tag
	meta_tag *temp = (meta_tag *)(ptr1);
	do
	{
		temp = (meta_tag *)(ptr1);
		// if it is empty space available
		if (temp->status== 1)
		  {
			memory =memory -temp->memorySize;
		  }
     //Checks if Bytes fit inside the range
		if(bytesNeeded <= temp->memorySize && (temp->status==0 || temp->status==2))
		  {
		    return ptr1;
		  }
	//If it successfull, the pointer to the meta_tag will be returned and we will call memPartition().
		if (( temp->status!= 2 && 0>=memory))
		  {
			return NULL;
		  }
	// Returns Null when they are not in range.
			// This is turn makes the mymalloc() return null too.
		int location;
		location = temp->memorySize + sizeof(meta_tag);
		ptr1 = ptr1+location;
	//Strong the new position in ptr1
	} while (temp->status!= 2);

	return NULL;
}

char *divide(char *start, int bytesNeeded)
{
	meta_tag *temp = (meta_tag *)(start);

	int oldSize = temp->memorySize;
	temp->memorySize = bytesNeeded;
	temp->status= 1;

	char* ptr11=start+sizeof(meta_tag);
//Divinding the memory that is still available.	
	  if (oldSize>= (bytesNeeded + sizeof(meta_tag)))
	    {
	      meta_tag *newData = (meta_tag *)(bytesNeeded+(start+sizeof(meta_tag)));
		newData->memorySize = oldSize - bytesNeeded - sizeof(meta_tag);
		newData->status = 2;
	    }
       	//This function will be successfull when the address exist in heap and not already been free.
	else if(bytesNeeded != 4089)
	  {
     		temp->status= 2;
	  }
	return ptr11;
	//When this function is unsuccessfull it will show an error, which was because the address used was not present in the heap.
}
void myfree(void *memory, char *file, int line)
{
	// Intially, we verify whether the heap is empty or not.
	if (heapStat() == 0)
	  {
	    int k=3;
	  do
	    {
	      myblock[k]=0;
	      ++k;
	    }while(k<4096);
          //Initializing meta_tag
	    meta_tag *data = (meta_tag *)(&myblock[3]);	
	    data->status= 2;
	    data->memorySize = 4089;
	
	    myblock[0] = 'b';
	    myblock[1] = 'o';
	    myblock[2] = 't';

	  }
	char *ptr1 = &myblock[3];
	char targetFound = 0;
	int combineLinks = 0;


	int k;
	meta_tag *currTag = (meta_tag*)(ptr1);
	do
	{
		currTag = (meta_tag *)(ptr1);
           //For checking the status
		if(currTag->status ==1)
		  {
		    if(ptr1+sizeof(meta_tag)==memory)
		     {
			currTag->status= 0;
			if (currTag->memorySize == 4089)
				{ 
				currTag->status= 2;
				}
			targetFound = 1;
//if target is found we update the variable.
		     }
		  }
		
				if (currTag->status== 0)
		  {    
 //Updating the meta_tag
			meta_tag *adjacentTag = (meta_tag *)(ptr1 + (currTag->memorySize + sizeof(meta_tag)));
	//Checking the status of the adjacent tag.
			if (adjacentTag->status == 2)
			{
			        
				currTag->memorySize= currTag->memorySize+adjacentTag->memorySize + sizeof(meta_tag);
				currTag->status= 2;
				targetFound = 1;
				++combineLinks;
				break;
			}
			if (adjacentTag->status== 0)
			{
				currTag->memorySize =currTag->memorySize + adjacentTag->memorySize + sizeof(meta_tag);
				targetFound = 1;
				++combineLinks;
				continue;
			}
		        
			if ((char *)(ptr1 +(currTag->memorySize + sizeof(meta_tag)) + sizeof(meta_tag)) == memory)
			{
				adjacentTag->status= 0;
				currTag->memorySize= currTag->memorySize+adjacentTag->memorySize + sizeof(meta_tag);
				targetFound = 1;
				++combineLinks;
				continue;
			}
	//Updating ptr1 to new location
			int location;
			location = ((meta_tag *)(ptr1))->memorySize + sizeof(meta_tag);
			ptr1= ptr1+location;
			continue;
		}

			int location;
			location = ((meta_tag *)(ptr1))->memorySize + sizeof(meta_tag);
			ptr1 = ptr1+location;

	} while (currTag->status != 2);
		if (!targetFound)
			printf("\nERROR: in file %s on line %d.Memory does not exist in the heap \n\n", file, line);
	//This function will be unsuccessfull when the memory is not available in the heap.
		
}
