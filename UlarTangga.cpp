#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void board();
int roll();
void check_location(int &p, int &cm, int s1, int s2, int s3, int l1, int l2, int l3);
void check_progress(int x, int y);
char Pemain[100];
char Komputer[100];
string snakes[2000];

int main()
{
srand(time(NULL));
for (int i = 1; i <= 100; i++)
{ //mengosongkan semua area yang diberi label pemain dan komputer .
	Pemain[i] = ' ';
	Komputer[i] = ' ';
}
for (int i = 1; i <= 100; i++)
{ // mengosongkan semua area yang diberi label snakes.
	snakes[i] = "  ";
}
// Membuat posisi ular dan tangga secara acak untuk tiap permainannya
int s1 = rand() % (20) + 1;
int s2 = rand() % (50) + 20;
int s3 = rand() % (100) + 50;
int l1 = rand() % (20) + 1;
int l2 = rand() % (50) + 20;
int l3 = rand() % (100) + 50;
int p = 0;
snakes[s1] = "Ul";
snakes[s2] = "U2";
snakes[s3] = "U3";
snakes[l1] = "T1";
snakes[l2] = "T2";
snakes[l3] = "T3";
char n;
int r,r2;
int c;
int cm = 0;
while (p != 100 || cm != 100)
{
	Pemain[p] = ' ';
	Komputer[cm] = ' ';
	cout << "Tekan r untuk mengacak dadu : ";
	cin >> n;
	if (n == 'r')
	{
	if (p > 100)
		p = p;
	else
	{
	r = roll();
	p = p + r;
	if (p > 100)
	{
		p = p - r;
	}
	cout << "Pemain(P) mendapat " << r << ", Posisi sekarang di " << p << endl;
	if (r == 6)
	{
	r = roll();
	p = p + r;
	if (p > 100)
	{
		p = p - r;
	}
	cout << "Pemain(P) mendapat " << r << " pada putaran kedua" << ", Posisi sekarang di " << p << endl;
	if (r == 6)
	{
	r = roll();
	p = p + r;
	if (p > 100 && r != 6)
	{
		p = p - r;
	}
	if (r == 6)
	{
	p = p - 6 - 6;
	cout << "Pemain(P) Mendapatkan hukuman setelah 3x mendapatkan 6, total dadu menjadi 0" << endl;
	}
	else
	cout << "Pemain(P) mendapat " << r << "pada putaran ketiga" << ", Posisi sekarang di " << p << endl;
	}
	}
}
	}
	if (n == 'r')
	{
	if (cm > 100)
		cm = cm;
	else
	{
	r = roll();
	cm = cm + r;
	if (cm > 100)
	{
		cm = cm - r;
	}
	cout << "Komputer(C) mendapat " << r << ", Posisi sekarang di " << cm << endl;
	if (r == 6)
	{
	r = roll();
	cm = cm + r;
	if (cm > 100)
	{
		cm = cm - r;
	}
	cout << "Komputer(C) mendapat " << r << ", Posisi sekarang di " << cm << endl;
	if (r == 6)
	{
	r = roll();
	cm = cm + r;
	cout << "Komputer(C) mendapat " << r << ", Posisi sekarang di " << cm << endl;
	if (cm > 100 && r != 6)
	{
		cm = cm - r;
	}
	if (r == 6)
	{
		cm = cm - 6 - 6;
		cout << "Komputer(C) Mendapatkan hukuman setelah 3x mendapatkan 6, total dadu menjadi 0" << endl;
	}
	}
	}
	}
	}
	Pemain[p] = 'P';
	Komputer[cm] = 'C';
	board();
	check_location(p, cm, s1, s2, s3, l1, l2, l3);
	if (p == 100 && cm == 100)
	cout << "DRAW!!!";
	else if (p == 100)
	{
	cout << "Pemain telah Menang!!!";
	break;
	}
	else if (cm == 100)
	{
	cout << "Komputer telah Menang!!!";
	break;
	}
	system("pause");
	system("cls");
}
}

void board()
{
cout << " ______________________________________________________________________" << endl;
cout << "|  " << "100  " << "|  " << "99  " << "|  " << "98  " << "|  " << "97  " << "|  " << "96  " << "|  " << "95  " << "|  " << "94  " << "|  " << "93  " << "|  " << "92  " << "|  " << "91  |" << endl;
cout << "|" << snakes[100] << " " << Pemain[100] << Komputer[100] << "  |" << snakes[99] << " " << Pemain[99] << Komputer[99] << " |" << snakes[98] << " " << Pemain[98] << Komputer[98] << " |" << snakes[97] << " " << Pemain[97] << Komputer[97] << " |" << snakes[96] << " " << Pemain[96] << Komputer[96] << " |" << snakes[95] << " " << Pemain[95] << Komputer[95] << " |" << snakes[94] << " " << Pemain[94] << Komputer[94] << " |" << snakes[93] << " " << Pemain[93] << Komputer[93] << " |" << snakes[92] << " " << Pemain[92] << Komputer[92] << " |" << snakes[91] << " " << Pemain[91] << Komputer[91] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "81   " << "|  " << "82  " << "|  " << "83  " << "|  " << "84  " << "|  " << "85  " << "|  " << "86  " << "|  " << "87  " << "|  " << "88  " << "|  " << "89  " << "|  " << "90  |" << endl;
cout << "|" << snakes[81] << " " << Pemain[81] << Komputer[81] << "  |" << snakes[82] << " " << Pemain[82] << Komputer[82] << " |" << snakes[83] << " " << Pemain[83] << Komputer[83] << " |" << snakes[84] << " " << Pemain[84] << Komputer[84] << " |" << snakes[85] << " " << Pemain[85] << Komputer[85] << " |" << snakes[86] << " " << Pemain[86] << Komputer[86] << " |" << snakes[87] << " " << Pemain[87] << Komputer[87] << " |" << snakes[88] << " " << Pemain[88] << Komputer[88] << " |" << snakes[89] << " " << Pemain[89] << Komputer[89] << " |" << snakes[90] << " " << Pemain[90] << Komputer[90] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "80   " << "|  " << "79  " << "|  " << "78  " << "|  " << "77  " << "|  " << "76  " << "|  " << "75  " << "|  " << "74  " << "|  " << "73  " << "|  " << "72  " << "|  " << "71  |" << endl;
cout << "|" << snakes[80] << " " << Pemain[80] << Komputer[80] << "  |" << snakes[79] << " " << Pemain[79] << Komputer[79] << " |" << snakes[78] << " " << Pemain[78] << Komputer[78] << " |" << snakes[77] << " " << Pemain[77] << Komputer[77] << " |" << snakes[76] << " " << Pemain[76] << Komputer[76] << " |" << snakes[75] << " " << Pemain[75] << Komputer[75] << " |" << snakes[74] << " " << Pemain[74] << Komputer[74] << " |" << snakes[73] << " " << Pemain[73] << Komputer[73] << " |" << snakes[72] << " " << Pemain[72] << Komputer[72] << " |" << snakes[71] << " " << Pemain[71] << Komputer[71] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "61   " << "|  " << "62  " << "|  " << "63  " << "|  " << "64  " << "|  " << "65  " << "|  " << "66  " << "|  " << "67  " << "|  " << "68  " << "|  " << "69  " << "|  " << "70  |" << endl;
cout << "|" << snakes[61] << " " << Pemain[61] << Komputer[61] << "  |" << snakes[62] << " " << Pemain[62] << Komputer[62] << " |" << snakes[63] << " " << Pemain[63] << Komputer[63] << " |" << snakes[64] << " " << Pemain[64] << Komputer[64] << " |" << snakes[65] << " " << Pemain[65] << Komputer[65] << " |" << snakes[66] << " " << Pemain[66] << Komputer[66] << " |" << snakes[67] << " " << Pemain[67] << Komputer[67] << " |" << snakes[68] << " " << Pemain[68] << Komputer[68] << " |" << snakes[69] << " " << Pemain[69] << Komputer[69] << " |" << snakes[70] << " " << Pemain[70] << Komputer[70] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "60   " << "|  " << "59  " << "|  " << "58  " << "|  " << "57  " << "|  " << "56  " << "|  " << "55  " << "|  " << "54  " << "|  " << "53  " << "|  " << "52  " << "|  " << "51  |" << endl;
cout << "|" << snakes[60] << " " << Pemain[60] << Komputer[60] << "  |" << snakes[59] << " " << Pemain[59] << Komputer[59] << " |" << snakes[58] << " " << Pemain[58] << Komputer[58] << " |" << snakes[57] << " " << Pemain[57] << Komputer[57] << " |" << snakes[56] << " " << Pemain[56] << Komputer[56] << " |" << snakes[55] << " " << Pemain[55] << Komputer[55] << " |" << snakes[54] << " " << Pemain[54] << Komputer[54] << " |" << snakes[53] << " " << Pemain[53] << Komputer[53] << " |" << snakes[52] << " " << Pemain[52] << Komputer[52] << " |" << snakes[51] << " " << Pemain[51] << Komputer[51] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "41   " << "|  " << "42  " << "|  " << "43  " << "|  " << "44  " << "|  " << "45  " << "|  " << "46  " << "|  " << "47  " << "|  " << "48  " << "|  " << "49  " << "|  " << "50  |" << endl;
cout << "|" << snakes[41] << " " << Pemain[41] << Komputer[41] << "  |" << snakes[42] << " " << Pemain[42] << Komputer[42] << " |" << snakes[43] << " " << Pemain[43] << Komputer[43] << " |" << snakes[44] << " " << Pemain[44] << Komputer[44] << " |" << snakes[45] << " " << Pemain[45] << Komputer[45] << " |" << snakes[46] << " " << Pemain[46] << Komputer[46] << " |" << snakes[47] << " " << Pemain[47] << Komputer[47] << " |" << snakes[48] << " " << Pemain[48] << Komputer[48] << " |" << snakes[49] << " " << Pemain[49] << Komputer[49] << " |" << snakes[50] << " " << Pemain[50] << Komputer[50] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "40   " << "|  " << "39  " << "|  " << "38  " << "|  " << "37  " << "|  " << "36  " << "|  " << "35  " << "|  " << "34  " << "|  " << "33  " << "|  " << "32  " << "|  " << "31  |" << endl;
cout << "|" << snakes[40] << " " << Pemain[40] << Komputer[40] << "  |" << snakes[39] << " " << Pemain[39] << Komputer[39] << " |" << snakes[38] << " " << Pemain[38] << Komputer[38] << " |" << snakes[37] << " " << Pemain[37] << Komputer[37] << " |" << snakes[36] << " " << Pemain[36] << Komputer[36] << " |" << snakes[35] << " " << Pemain[35] << Komputer[35] << " |" << snakes[34] << " " << Pemain[34] << Komputer[34] << " |" << snakes[33] << " " << Pemain[33] << Komputer[33] << " |" << snakes[32] << " " << Pemain[32] << Komputer[32] << " |" << snakes[31] << " " << Pemain[31] << Komputer[31] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "21   " << "|  " << "22  " << "|  " << "23  " << "|  " << "24  " << "|  " << "25  " << "|  " << "26  " << "|  " << "27  " << "|  " << "28  " << "|  " << "29  " << "|  " << "30  |" << endl;
cout << "|" << snakes[21] << " " << Pemain[21] << Komputer[21] << "  |" << snakes[22] << " " << Pemain[22] << Komputer[22] << " |" << snakes[23] << " " << Pemain[23] << Komputer[23] << " |" << snakes[24] << " " << Pemain[24] << Komputer[24] << " |" << snakes[25] << " " << Pemain[25] << Komputer[25] << " |" << snakes[26] << " " << Pemain[26] << Komputer[26] << " |" << snakes[27] << " " << Pemain[27] << Komputer[27] << " |" << snakes[28] << " " << Pemain[28] << Komputer[28] << " |" << snakes[29] << " " << Pemain[29] << Komputer[29] << " |" << snakes[30] << " " << Pemain[30] << Komputer[30] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "20   " << "|  " << "19  " << "|  " << "18  " << "|  " << "17  " << "|  " << "16  " << "|  " << "15  " << "|  " << "14  " << "|  " << "13  " << "|  " << "12  " << "|  " << "11  |" << endl;
cout << "|" << snakes[20] << " " << Pemain[20] << Komputer[20] << "  |" << snakes[19] << " " << Pemain[19] << Komputer[19] << " |" << snakes[18] << " " << Pemain[18] << Komputer[18] << " |" << snakes[17] << " " << Pemain[17] << Komputer[17] << " |" << snakes[16] << " " << Pemain[16] << Komputer[16] << " |" << snakes[15] << " " << Pemain[15] << Komputer[15] << " |" << snakes[14] << " " << Pemain[14] << Komputer[14] << " |" << snakes[13] << " " << Pemain[13] << Komputer[13] << " |" << snakes[12] << " " << Pemain[12] << Komputer[12] << " |" << snakes[11] << " " << Pemain[11] << Komputer[11] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
cout << "|  " << "1    " << "|  " << "2   " << "|  " << "3   " << "|  " << "4   " << "|  " << "5   " << "|  " << "6   " << "|  " << "7   " << "|  " << "8   " << "|  " << "9   " << "|  " << "10  |" << endl;
cout << "|" << snakes[1] << " " << Pemain[1] << Komputer[1] << "  |" << snakes[2] << " " << Pemain[2] << Komputer[2] << " |" << snakes[3] << " " << Pemain[3] << Komputer[3] << " |" << snakes[4] << " " << Pemain[4] << Komputer[4] << " |" << snakes[5] << " " << Pemain[5] << Komputer[5] << " |" << snakes[6] << " " << Pemain[6] << Komputer[6] << " |" << snakes[7] << " " << Pemain[7] << Komputer[7] << " |" << snakes[8] << " " << Pemain[8] << Komputer[8] << " |" << snakes[9] << " " << Pemain[9] << Komputer[9] << " |" << snakes[10] << " " << Pemain[10] << Komputer[10] << " |";
cout << endl
	 << " ----------------------------------------------------------------------" << endl;
}
int roll()
{
	int p;
	p = rand() % (6) + 1;
	return p;
}
void check_location(int &p, int &cm, int s1, int s2, int s3, int l1, int l2, int l3)
{
int flag = 0;
int t, tc;
if (p == s1)
{
t = p;
p = p - 5;
if (p < 0)
{
	p = 0;
}
cout << "\nPemain(P) tergigit ular di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
else if (p == s2)
{
t = p;
p = p - 9;
if (p < 0)
{
	p = 0;
}
cout << "\nPemain(P) tergigit ular di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
else if (p == s3)
{
t = p;
p = p - 13;
if (p < 0)
{
	p = 0;
}
cout << "\nPemain(P) tergigit ular di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
if (cm == s1)
{
tc = cm;
cm = cm - 5;
if (cm < 0)
{
	cm = 0;
}
cout << "\nKomputer(C) tergigit ular di " << tc << " kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
else if (cm == s2)
{
tc = cm;
cm = cm - 9;
if (cm < 0)
{
	cm = 0;
}
cout << "\nKomputer(C) tergigit ular di " << tc << "  kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
else if (cm == s3)
{
tc = cm;
cm = cm - 13;
if (cm < 0)
{
	cm = 0;
}
cout << "\nKomputer(C) tergigit ular di " << tc << "  kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
if (p == l1)
{
t = p;
p = p + 4;
cout << "\nPemain(P) menemukan Tangga!1!1 di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
else if (p == l2)
{
t = p;
p = p + 8;
cout << "\nPemain(P) menemukan Tangga!1!1 di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
else if (p == l3)
{
t = p;
p = p + 12;
cout << "\nPemain(P) menemukan Tangga!1!1 di " << t << " kamu dipindahkan ke posisi " << p << endl;
flag = 1;
}
if (cm == l1)
{
tc = cm;
cm = cm + 4;
cout << "\nKomputer() menemukan Tangga!1!1 di " << tc << " kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
else if (cm == l2)
{
tc = cm;
cm = cm + 8;
cout << "\nKomputer(C) menemukan Tangga!1!1 di " << tc << " kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
else if (cm == l3)
{
tc = cm;
cm = cm + 12;
cout << "\nKomputer(C) menemukan Tangga!1!1 di " << tc << " kamu dipindahkan ke posisi " << cm << endl;
flag = 2;
}
if (flag == 1)
{
cout << "-";
Pemain[p] = 'P';
Komputer[cm] = 'C';
Pemain[t] = ' ';
board();
}
else if (flag == 2)
{
cout << "-";
Pemain[p] = 'P';
Komputer[cm] = 'C';
Komputer[tc] = ' ';
board();
}
}
