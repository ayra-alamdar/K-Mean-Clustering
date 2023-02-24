////Ayra Alamdar - 21i-2968
////DS Assignment # 01
////BS(CS) - D
//#include<iostream>
//#include<string>
//#include<ctime>
//#include<fstream>
//#include<cstdlib>
//#include<sstream>
//using namespace std;
//
//int string_to_int(string a)
//{
//	int ans = 0;
//	for (int i = 0; i < a.length(); i++)
//	{
//		if (a[i] == '.')
//		{
//			break;
//		}
//		ans *= 10;
//		ans += static_cast<int>(a[i]) - '0';
//	}
//	return ans;
//}
//
//float string_to_float(string a)
//{
//	float ans = 0;
//
//	float temp;
//	int position = 1;
//	bool flag = true;
//	for (int i = 0; i < a.length(); i++)
//	{
//		if (a[i] == '.')
//		{
//			flag = false;
//			continue;
//		}
//		if (flag == true) {
//			ans *= 10;
//			ans += static_cast<int>(a[i]) - '0';
//		}
//		else
//		{
//			position *= 10;
//			temp = static_cast<int>(a[i]) - '0';
//			temp /= position;
//			ans += temp;
//		}
//	}
//	return ans;
//}
//
////for shortest path 
//int ShortestPath(int arr[5], int val)	//5 parameters array for 5 clusters
//{
//	int index = 0;
//	int smallest = 0;		//keeps track of the smallest value
//	smallest = val - arr[0];	//by default keeping the smallest value at the first index
//	if (smallest < 0)
//	{
//		smallest *= -1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		int temp = val - arr[i];
//		if (temp < 0)
//		{
//			temp *= -1;
//		}
//		if (temp < smallest)
//		{
//			smallest = temp;
//			index = i;
//		}
//	}
//	return index + 1;		//to start with (1 to 5) instead of (0 to 4) values in the cluster array
//}
//
////function for clustering
//void clustering(double*** arr)
//{
//	int newClusterLocation[5];		//array for new cluster locations
//	for (int i = 0; i < 5; i++)
//	{
//		newClusterLocation[i] = 0;	//initializing "newClusterLocation" array with 0
//	}
//	int ary[5];						//making 5 clusters
//	srand(time(NULL));
//	for (int i = 0; i < 5; i++)		//loop for getting random values
//	{
//		ary[i] = rand() % 201;
//	}
//	int counter[5];
//	for (int i = 0; i < 5; i++)
//	{
//		counter[i] = 1;				//initializing "counter" array with 1
//	}
//	int sum[5];
//	for (int i = 0; i < 5; i++)
//	{
//		sum[i] = 0;					//initializing "sum" array with 0
//	}
//
//	//*/*/*/*/*/*/*/*/*/*/*/* K MEANS CLUSTERING STARTS HERE*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
//	//the code within this while loop locates where the clusters should be
//	while (1)
//	{
//		for (int i = 0; i < 201; i++)
//		{
//			for (int j = 0; j < 201; j++)
//			{
//				for (int k = 0; k < 201; k++)
//				{
//					int var;
//					var = ShortestPath(ary, arr[i][j][k]);
//					if (var == 1)
//					{						//counting how many points are near that point in which cluster
//						counter[0]++;		//increment in the zeroth elements of counter array
//						sum[0] += arr[i][j][k];	//if not this cluster then finding the nearest cluster. Taking sum of all clusters
//					}
//					else if (var == 2)
//					{
//						counter[1]++;
//						sum[1] += arr[i][j][k];
//					}
//					else if (var == 3)
//					{
//						counter[2]++;
//						sum[2] += arr[i][j][k];
//					}
//					else if (var == 4)
//					{
//						counter[3]++;
//						sum[3] += arr[i][j][k];
//					}
//					else if (var == 5)
//					{
//						counter[4]++;
//						sum[4] += arr[i][j][k];
//					}
//				}
//			}
//		}
//		for (int i = 0; i < 5; i++)		//reallocating clusters into arrangements (K MEANS DRIVER CODE)
//		{
//			newClusterLocation[i] = sum[i] / counter[i];	//finding the location of new clusters according to supplied formula
//		}
//
//		for (int i = 0; i < 5; i++)		//initializing the values of sum and counter array with default values so that no issue arises when rechecking for clusters
//		{
//			sum[i] = 0;
//			counter[i] = 1;
//		}
//
//		// reference: https://www.youtube.com/watch?v=YWgcKSa_2ag
//
//		bool flag = 0;
//		for (int i = 0; i < 5; i++)
//		{
//			if (newClusterLocation[i] != ary[i])		//checking if the location of the cluster is changing or not
//			{
//				flag = 1;
//			}
//		}
//
//		for (int i = 0; i < 5; i++)
//		{
//			ary[i] = newClusterLocation[i];		//putting new locations of clusters in the original location array of the clusters
//		}
//
//		if (flag == 0)
//		{
//			break;		//if all 5 clusters are equal the condition will never be fulfilled then the while loop breaks
//		}
//	}
//	//*/*/*/*/*/*/*/*/*/*/*/* K MEANS CLUSTERING ENDS HERE*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
//
//	//-=-=-=-=-=-= FILE WRITING -=-=-=-=-=-=-=-=//
//
//	fstream anyfile;
//	anyfile.open("output_file2.csv", ios::out | ios::app);
//	ifstream MYfile;
//	MYfile.open("Segmented Customer 1.csv");		//opening the file
//	string variable;
//	getline(MYfile, variable, '\n');
//	anyfile << variable << ", cluster number\n";
//
//	int counter_flag = 0;
//	while (1)
//	{
//		MYfile >> variable;
//		stringstream var(variable);
//		string str1[5];		//5 cols
//		getline(var, str1[0], ',');
//		getline(var, str1[1], ',');
//		getline(var, str1[2], ',');
//		getline(var, str1[3], ',');
//		getline(var, str1[4], '\n');
//		anyfile << str1[0] << ',' << str1[1] << ',' << str1[2] << ',' << str1[3] << ',' << str1[4] << ',' << ShortestPath(newClusterLocation, arr[string_to_int(str1[0])][string_to_int(str1[3])][string_to_int(str1[4])]) << '\n';
//		counter_flag++;
//		if (counter_flag > 201)
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//
//	ifstream MYfile;
//	MYfile.open("Segmented Customer 1.csv");		//opening the file
//	double*** a1 = new double** [201];		//creating a 2D dynamically allocated array
//	for (int i = 0; i < 201; i++)
//	{
//		a1[i] = new double* [201];
//		for (int j = 0; j < 201; j++)
//		{
//			a1[i][j] = new double[201];			//every row is pointing to a 2D array
//		}
//	}
//	for (int i = 0; i < 201; i++)		//nested loop for accessing the 2D array
//	{
//		for (int j = 0; j < 201; j++)
//		{
//			for (int k = 0; k < 201; k++)
//			{
//				a1[i][j][k] = 0;				//initializing the array with "0"
//			}
//		}
//	}
//	string str;
//	bool flag = true;
//	int counterFlag = 0;
//	while (getline(MYfile, str, '\n'))
//	{
//		if (flag == true)
//		{
			flag = false;
			continue;
		}
		counterFlag++;
		if (counterFlag == 201)
		{
			break;
		}
		if (str == "" || str == "\n")
		{
			break;
		}
		stringstream var(str);
		string str1[5];		//5 cols
		getline(var, str1[0], ',');
		getline(var, str1[1], ',');
		getline(var, str1[2], ',');
		getline(var, str1[3], ',');
		getline(var, str1[4], '\n');
		a1[string_to_int(str1[0])][string_to_int(str1[3])][string_to_int(str1[4])] = string_to_int(str1[4]);		//2D array is populated and the data is saved 
	}
//	//for (int i = 0; i < 500; i++)
//	//{
//	//	for (int j = 0; j < 500; j++)
//	//	{
//	//		if(a1[i][j]!=0)
//	//		cout << a1[i][j] << " ";
//	//		
//	//	}
//	//	//cout << endl;
//	//}
	clustering(a1);
}
