#include <iostream>
using namespace std;
//using recursive problem 1
/*int fact(int f)
{
	int k;
	k=f;
	if(k==0)
	{
		return 1;
	}
	else
	{
		k*=fact(k-1);
		return k;
	}
}
int main()
{
	int n;
	cout<<"Enter a number:";
	cin>>n;
	cout<<fact(n);
}*/
//using loop problem 1
/*int fact(int f)
{
	if(f==0)
	{
		return 1;
	}
	else
	{	
	for(int i=f-1;i>=1;i--)
	{
		f*=i;
	}
	return f;
	}
}
int main()
{
	int n;
	cout<<"Enter a number:";
	cin>>n;
	cout<<fact(n);
}*/

//problem 2
//recurseviv
/*int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    int n;
    cout << "Enter the number:";
    cin >> n;
    cout << "Fibonacci Sequence:\n";
    for (int i = 0; i < n; ++i) 
	{
        cout << fibonacci(i) <<endl;
    }

    return 0;
}*/
//problem 2
//while loop
/*int main()
{
	int n,x,y,z;
	cout<<"enter a number:";
	cin>>n;
	x=0;
	y=1;
	z=0;
	while(z<=n)
	{
		cout<<z<<endl;
		x=y;
		y=z;
		z=x+y;
	}
	return 0;
}*/

//problen 3
/*int GCD(int x, int y) {
    if (y == 0) {
        return x;
    }
    else {
        return GCD(y, x % y);
    }
}

int main() {
    int x, y;
    cout << "Enter the first nonnegative integer: ";
    cin >> x;
    cout << "Enter the second nonnegative integer: ";
    cin >> y;
    cout << "Greatest Common Divisor (GCD) of " << x << " and " << y << " is: " << GCD(x, y) << endl;
    return 0;
}*/

//calculate power problem 4

/*int RaiseIntToPower(int n, int k) {
    if (k == 0) {
        return 1;
    } else {
        return n * RaiseIntToPower(n, k - 1);
    }
}

int main() {
    int base, exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    cout << base << " raised to the power of " << exponent << " is: " << RaiseIntToPower(base, exponent) << endl;
    
	return 0;
}*/

//problem 5
/*int DigitSum(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + DigitSum(n / 10);
    }
}

int main() {
    int num;
    cout << "Enter a nonnegative integer: ";
    cin >> num;
    cout << "Sum of digits of " << num << " is: " << DigitSum(num) << endl;

    return 0;
}*/

//program 6
string Reverse(string str) {
    if (str.length() <= 1) {
        return str;
    } else {
        return Reverse(str.substr(1)) + str[0];
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "Reverse of the string: " << Reverse(input) << endl;

    return 0;
}



