#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


int binarySearch(vector<int>&, int);	
void quickSort(vector<int>&, vector<int>&, int, int);


int main()
{ 

	ifstream dogfile;
	ifstream examinefile;
	ifstream vetfile;
	int vid,fee,x_did;

	int did,age;

	int v_vid, v_elevel;
	int index=0;

	vector<int> dog_did;
	vector<int> dog_age;

	vector<int> age_array;
	vector<int> examine_fee;
	vector<int> examine_vid;


	vector<int> vet_vid;
	vector<int> vet_elevel;
	vector<int> vet_fee;

//opening files
//reading dogs
	dogfile.open("DFile");
	if (dogfile){
		while(dogfile >> did >> age){
			if (age > 7 && age < 11){
				dog_did.push_back(did);
				dog_age.push_back(age);
				index ++;
			}
		}
	}
	else{
		cout<<"File error \n"<<endl;
	}
	dogfile.close();
	quickSort(dog_did,dog_age,0,index-1);
	
//reading examine
	int k = 0;
	examinefile.open("EFile");
	while(examinefile >> vid >> x_did >> fee)
	{
		int val = binarySearch(dog_did,x_did);
		if (val !=-1){
			if(fee > 50 && fee < 300){
				examine_fee.push_back(fee);
			examine_vid.push_back(vid);
			k++;
			}
			
		}
	}
	examinefile.close();
	quickSort(examine_vid,examine_fee,0,k-1);

//reading vets
	int vet_index =0;
	vetfile.open("VFile");
	while (vetfile >> v_vid >> v_elevel)
	{
		int check = binarySearch(examine_vid,v_vid);
		if (check !=-1)
		{
			vet_elevel.push_back(v_elevel);
			vet_fee.push_back(examine_fee[check]);
			vet_index++;
		}
	}
    vetfile.close();
    quickSort(vet_elevel,vet_fee,0,vet_index-1);

//used to query and display
	int n=0; 
	int temp_fee = 0; 
	int temp_age = 0; 
	int elevel=0; 
	int counter =0; 
	int max=0;
	
	cout<< left << setw(9) << "elevel";
	cout<< left << setw(12) << "Count";
	cout<< left << setw(6) << "AvgSum";
	cout<< right << setw(10) << "AvgAge"; 
    cout<< "\n--------------------------------------\n";

		while (n < vet_index){
			counter++;
			elevel = vet_elevel[n];
			temp_fee += vet_fee[n];
			temp_age += dog_age[n];
			if (elevel != vet_elevel[n+1]){
				float average = (float)temp_fee/counter;
				float avgAge = (float)temp_age/counter;
				if(elevel > 1){
					cout << "  "<<elevel<< "      "
						 <<counter<< "     " 
						 <<average<<"    "
						 <<avgAge<< "    "<<endl;
					temp_fee=0;
					temp_age = 0;
					counter =0;
					max =0;
				}
				temp_fee=0;
				temp_age = 0;
				counter =0;
				max =0;
			}
			n++;
		}
	
	return 0;
}

int binarySearch(vector<int>& V1, int num){

	int mid, first = 0;
	int last = V1.size();

	while (first < last){

		mid = first + (last - first)/2;
		if (num > V1[mid])
			first = mid+1;
		else if (num < V1[mid])
			last = mid;
		else return mid;
	}
	return -1;
}

void quickSort(vector<int>& V1,vector<int>& V2, int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = V1[(left + right) / 2];
      while (i <= j)
        {
            while (V1[i] < pivot)
                  i++;
            while (V1[j] > pivot)
                  j--;
            if (i <= j)
            {
                  tmp = V1[i];
                  V1[i] = V1[j];
                  V1[j] = tmp;
                  tmp = V2[i];
                  V2[i] = V2[j];
                  V2[j] = tmp;

                  i++;
                  j--;
            }
      }
      if (left < j)
            quickSort(V1, V2, left, j);
      if (i < right)
            quickSort(V1, V2, i, right);
} 

