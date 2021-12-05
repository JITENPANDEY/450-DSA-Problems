float getMedian(int num1[], int num2[], int size) { 
   // base cases
   if (size <= 0)
      return -1
   if (size == 1)
      return (num1[0] + num2[0]) / 2
   if (size == 2)
      return (max(num1[0], num2[0]) + min(num1[1], num2[1])) / 2
   int med1 = median(num1, size)
   int med2 = median(num2, size)
   // compare the medians
   if (med1 == med2)
      return med1 
   if (med1 < med2) {
      // recurse for the subarray num1[m1 to size] and num2[0 to m2]
      if (size % 2 == 0)
         return getMedian(num1 + size/2 - 1, num2, size - size/2 + 1)
      else
         return getMedian(num1 + size / 2, num2, size - size / 2)
   } else {
      // recurse for the subarray num1[0 to m1] and num2[m2 to n]
      if (size % 2 == 0)
         return getMedian(num2 + size / 2 - 1, num1, size - size / 2 + 1) 
      else
         return getMedian(num2 + size / 2, num1, size - size / 2) 
}
// Utility function to find median of array
int median(int arr[], int array_size) { 
   if (array_size % 2 == 0)
      return (arr[array_size / 2] + arr[array_size / 2 - 1]) / 2
   else
      return arr[array_size / 2]
}