#include <iostream>
#include<vector>
using namespace std;

// Function to find the last occurrence of a target element in a sorted vector
// using binary search
int lastOcc(vector<int> arr, int target) {
  // Initialize start, end, and middle indices
  int s = 0;
  int e = arr.size() - 1;
  int mid = s + (e-s)/2;
  int ans = -1; // Initialize answer as not found

  // Perform binary search
  while(s <= e) {
    if(arr[mid] == target) {
      // If element found, store index and continue searching to the right
      // for the last occurrence
      ans = mid;
      s = mid + 1;
    }
    else if(target < arr[mid]) {
      // If element is smaller, search in the left half
      e = mid - 1;
    }
    else {
      // If element is larger, search in the right half
      s = mid + 1;
    }
    // Update middle index for next iteration
    mid = s + (e-s)/2;
  }
  // Return the index of the last occurrence, or -1 if not found
  return ans;
}

int main() {
  // Create a sorted vector and initialize a target value
  vector<int> v{1,3,7,7,7,7,7,7,7,7,7,7,7,7,9};
  int target = 7;

  // Find the last occurrence of the target element
  int ans = lastOcc(v, target);

  // Print the result
  if (ans != -1) {
    cout << "Last occurence of "<<target<<" is at " << ans << "th index."<< endl;
  } else {
    cout << "Target element not found." << endl;
  }

  return 0;
}