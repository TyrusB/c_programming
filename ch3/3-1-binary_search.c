/* This exercise requires modifying a binary search code to only have two tests inside the body of the main loop */


/* Binary Search w/ args of what we're searching for (x), SORTED array to search in (v[]) of size n */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  
  low = 0;
  high = n - 1;
  mid = (low+high) / 2;
  
  while (low <= high && v[mid] != x) {
    if (x < v[mid])
      high = mid - 1;
    else 
      low = mid + 1;
  }
  
  if (v[mid] == x)
    return mid;
  else
    return -1;
}