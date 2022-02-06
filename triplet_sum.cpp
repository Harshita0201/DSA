// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

//only func ans->
#include<set>

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
     vector<vector<int>> a;
     set< vector<int> > visited;  
     sort(arr.begin(), arr.end());
 
    // check if triplet is formed by nums[i] and a pair from
    // subarray nums[i+1…n)
    for (int i = 0; i <= n - 3; i++)
    {
        // remaining sum
        int k2 = K - arr[i];
 
        // maintain two indices pointing to endpoints of the
        // subarray nums[i+1…n)
        int low = i + 1, high = n - 1;
 
        // loop if `low` is less than `high`
        while (low < high)
        {
            // increment `low` index if the total is less than the remaining sum
            if (arr[low] + arr[high] < k2) {
                low++;
            }
 
            // decrement `high` index if the total is more than the remaining sum
            else if (arr[low] + arr[high] > k2) {
                high--;
            }
 
            // triplet with the given sum is found
            else {
//                 // print the triplet
//                 cout << "(" << nums[i] << " " << nums[low] << " " <<
//                         nums[high] << ")\n";
                   vector<int> temp;
                   temp.push_back(arr[i]);
                   temp.push_back(arr[low]);
                   temp.push_back(arr[high]);
                   sort(temp.begin(), temp.end()); //to store triplet in ascending order
                     if (visited.find(temp) == visited.end()) { //if this triplet is not yet included in a

                       a.push_back(temp);

                       visited.insert(temp); //add in  vector of vistited triplets 

                   }
                   
   
                // increment `low` index and decrement `high` index
                low++, high--;
            }
        }
    }
    return a;
}
