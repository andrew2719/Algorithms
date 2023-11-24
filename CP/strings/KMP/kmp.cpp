// C++ program for implementation of KMP pattern searching
// algorithm

#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver code
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}




// // KMP pattern matching algotrithm 

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> calc_lps(string pattern){
//     vector<int> lps(pattern.size());
    
//     int i=1,n = pattern.size(),len=0;
//     while(i<n){
//         if(pattern[i]==pattern[len]){
//             lps[i] = len+1;
//             len+=1;
//             i+=1;
//         }

//         else{
//             if(len!=0){
//                 len = lps[len-1]; // this just goes back to where there would be match i mean 
//                                     //  after the if , if that if is not satisfied that mean we need to go back right?
//                                     // this else part does that by reducing the len to lps[len-1]
//                                     // lps stores the longest prefix-suffiz length at that index 
//                                     // for calculating less we directly jump to the lps[len-1]
//             }
//             else{
//                 lps[i] = 0;
//                 i+=1;
//             }
//         }
//     }
//     return lps;
// }

// void kmpSearch(string pattern, string s){
//     int n = s.size();
//     cout<<n<<endl;
//     int m = pattern.size();
//     vector<int> lps = calc_lps(pattern);
//     int i=0,j=0;
//     while((n-i)>=(m-j)){
//         cout<<i<<endl;
//         if(s[i]==pattern[j]){
//             i++;
//             j++;
//         }
//         if(j==m){
            
//             cout<<"ans :"<<i-j<<endl;
//             j = lps[j-1];
//         }
//         else if(i<n && s[i]!=pattern[j]){
//             if(j!=0){
//                 j = lps[j-1];
//             }
//             else{
//                 i+=1;
//             }
//         }
        
//     }
// }




// int main(){
//     string pattern = "aabaaac";
//     string s = "aabaaacaadvsaabaac" ;
//     vector<int> lps = calc_lps(pattern);
//     cout<<pattern<<endl;
//     for(int x:lps){
//         cout<<x<<" ";
//     }

//     kmpSearch(pattern,s);

// }