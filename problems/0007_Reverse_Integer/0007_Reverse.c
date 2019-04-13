int reverse(int x) {
 int shang, yu;
long long result;
shang = x / 10;
yu = x % 10;
result = yu;
int flog1 = 0x7fffffff;
int flog2 = (int)0x80000000;
while (shang)
{
	yu = shang % 10;
	shang = shang / 10;
	result = result * 10 + yu;
}

if (result>flog1||result<flog2)
	return 0;
return (int)result;
}