#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);

int main(){
   int *nums=NULL;
   int size=0;
   time stop, start;

   fill_array(&nums, &size);
   print_array(nums, size);

   //Time the function here
   gettimeofday(&start, NULL);

   //bubble_sort(nums, size);
   //selection_sort(nums, size);
   //insertion_sort(nums, size);
   //merge_sort(nums, 0, size-1);


   gettimeofday(&stop, NULL);

   printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
   //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   print_array(nums, size);
   free(nums);

   return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
   int i;

   printf("The array elements are:\n");
   for(i=0; i<size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
void merge(int *nums, int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];

   lower_half=left;  //this splits the array into two, this is the left
   upper_half=mid+1;  //this splits the right half of the array

   //this loops through all of the values of the array
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      //this swaps the numbers if they are not in correct order
      if(nums[lower_half]<=nums[upper_half]){
	 temp[i]=nums[lower_half];
	 lower_half++;
      }
      //this starts adding the numbers back upwards into the larger array
      else{
	 temp[i]=nums[upper_half];
	 upper_half++;
      }
   }

   //this should check if the left half is larger than the right half
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
	 temp[i]=nums[j];
   //loops through lower half and moves values to temp array
   else
      for(j=lower_half;j<=mid;j++, i++)
	       temp[i]=nums[j];

   //this should move back into the numbers array from the temporary array
   for(j=0,i=left;i<=right;i++,j++)
      nums[i]=temp[j];
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
void merge_sort(int *nums, int left, int right) {
   int mid;
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(nums, left, mid);  //this will sort the left half
      merge_sort(nums, mid+1, right); //sort the right half
      merge(nums, left, mid, right);  //merges the two halves togethor
   }
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //loops through the array until one before the end
   for(i=0; i<size-1; i++) {
      min=i;
      //loops a second time for each value of the loop
      for(j=i; j<size; j++)
	 if(nums[j]<nums[min])
	    min=j;
      //swapping next in list of uncompleted with next lowest val
      temp=nums[i];
      nums[i]=nums[min];
      nums[min]=temp;
   }
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //this will loop throguh the whole array until the end.
   for(i=0; i<size; i++) {
      temp=nums[i];
      //this loop will continue until the sorted value has reached its destination in the sorted list in the correct location
      for(j=i; j>0 && nums[j-1]>temp; j--)
	 nums[j]=nums[j-1];
      //this will swap the values to move the sorted value to the correct location
      nums[j]=temp;
   }
}

/*************************************************
 * YOU WILL WRITE THE HEADER FOR THIS
 * ***********************************************/
void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //this iwll loop through the whole array
   for(i=0; i<size; i++) {
      //this loop will reduce by the length each time to swap only to a certain index
      for(j=0; j<size-i-1; j++) {
	 if(nums[j]>nums[j+1]) {
	    temp=nums[j];
	    nums[j]=nums[j+1];
	    nums[j+1]=temp;
	 }
      }
   }
}

/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
   int *old_nums, i;

   *size+=1;
   old_nums=*nums;
   *nums=(int *) malloc(sizeof(int)*(*size));

   for(i=0; i<*size-1; i++)
      (*nums)[i]=old_nums[i];
   (*nums)[*size-1]=num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];

   printf("Enter the filename: ");
   scanf("%s",filename);
   fptr=fopen(filename,"r");

   while(fscanf(fptr,"%s", num)!=EOF){
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}
