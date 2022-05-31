#include<iostream>
#include<string>
#define clearshow system("cls")

using namespace std;
//Khai báo MSCN
string password = "12345678";
//Khai báo biến vận tốc
int speed;
//Số thứ tự
char number;
//chuyển số bất ngờ
int number_changed = 0;

//đăng nhập
void sign_in(string password)
{
	do {
		cout << "NHAP MA SO CA NHAN: ";
		cin >> password;
		if (password == "12345678")
		{
			cout << "DA MO KHOA." << endl;
		}
		else
		{
			clearshow;
			cout << "BAN DA NHAP SAI MA SO CA NHAN. " << endl;
			cout << "XIN MOI NHAP LAI." << endl;
		}
	} while (password != "12345678");
	clearshow;
}

//menu_first xuất hiện ở thông báo đầu tiên
void menu_first()
{
	cout << "XIN CHAO " << password << endl;
	cout << "XIN MOI LUA CHON: " << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;
	cout << ">> ";
	cin >> number;
}

//menu_selection xuất hiện ở các bảng thông báo lựa chọn
void menu_selection()
{
	cout << "XIN MOI LUA CHON: " << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;
	cout << ">> ";
	cin >> number;
}

//menu tăng tốc, giảm tốc
void show_menu_change_speed()
{
	cout << "MOI LUA CHON." << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO VE MENU" << endl;
	cout << ">> ";
	cin >> number;
}

//menu của chế độ R
void menu_reverse()
{
	cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
	show_menu_change_speed();
	do
	{
		clearshow;
		switch (number)
		{
			//tăng tốc - acceleration
		case '1':
			speed += 5;
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			if (speed >= 60)
			{
				cout << "TOC DO NGUY HIEM. BAN NEN GIAM TOC" << endl;
			}
			show_menu_change_speed();
			break;
			//giảm tốc - deceleration
		case '2':
			speed -= 5;
			if (speed <= 0)
			{
				speed = 0;
			}
			if (speed >= 60)
			{
				cout << "TOC DO NGUY HIEM. BAN NEN GIAM TOC" << endl;
			}
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			show_menu_change_speed();
			break;
			//Phanh - Brake
		case '3':
			speed = 0;
			cout << "XE DA PHANH." << endl;
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			show_menu_change_speed();
			break;
		default:
			cout << "PHIM NHAP KHONG HOP LE. MOI BAN NHAP LAI. " << endl;
			show_menu_change_speed();
			break;
		}
	} while (number != '4');
	clearshow;
	menu_first();
}

//menu của chế độ D
void menu_drive()
{
	cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
	show_menu_change_speed();
	do
	{
		clearshow;
		switch (number)
		{
			// tăng tốc - acceleration
		case '1':
			speed += 5;
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			if (speed >= 20)
			{
				cout << "TOC DO NGUY HIEM. BAN NEN GIAM TOC" << endl;
			}
			show_menu_change_speed();
			break;
			//giảm tốc - deceleration
		case '2':
			speed -= 5;
			if (speed <= 0)
			{
				speed = 0;
			}
			if (speed >= 20)
			{
				cout << "TOC DO NGUY HIEM. BAN NEN GIAM TOC" << endl;
			}
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			show_menu_change_speed();
			break;
			//Phanh - Brake
		case '3':
			speed = 0;
			cout << "XE DA PHANH." << endl;
			cout << "TOC DO HIEN TAI CUA XE: " << speed << "KM/H" << endl;
			show_menu_change_speed();
			break;
		default:
			cout << "KHONG HOP LE, MOI BAN NHAP LAI" << endl;
			show_menu_change_speed();
		}
	} while (number != '4');
	clearshow;
	menu_first();
}

//menu của hộp số
void menu_gear()
{
	menu_first();
	while (number != '5')
	{
		clearshow;
		switch (number)
		{
			//P
		case '1':
			if (speed == 0)
			{
				cout << "DA VE SO P." << endl;
				cout << "CHU Y SU DUNG TAY PHANH DE DAM BAO AN TOAN." << endl;
				cout << " " << endl;
				menu_selection();
				break;
			}
			else
			{
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA: " << speed << " KM/H" << endl;
				cout << " " << endl;
				menu_selection();
				break;
			}
			//R
		case '2':
			if (speed == 0 || number_changed == 0 || number_changed == 2)
			{
				number_changed = 2;
				speed = 7;
				menu_reverse();
			}
			else
			{
				cout << "HAY DUA TOC DO VE 0KM/H DE CHUYEN TU D SANG R." << endl;
				cout << "VAN TOC HIEN TAI CUA XE LA: " << speed << " KM/H" << endl;
				cout << "" << endl;
				menu_selection();
			}
			break;
			//N
		case '3':
			if (speed == 0)
			{
				cout << "DA VE SO N." << endl;
				cout << "TAM DUNG XE." << endl;
				cout << " " << endl;
				menu_selection();
				break;
			}
			else
			{
				cout << "DE CHUYEN SANG SO N. HAY DUA TOC DO VE 0 KM/H " << endl;
				cout << "VAN TOC HIEN TAI CUA XE LA: " << speed << " KM/H" << endl;
				cout << "" << endl;
				menu_selection();
				break;
			}
			//D
		case '4':
			if (speed == 0 || number_changed == 0 || number_changed == 4)
			{
				number_changed = 4;
				speed = 7;
				menu_drive();
			}
			else
			{
				cout << "DE CO THE LUI XE. HAY DUA TOC DO VE 0 KM/H DE CHUYEN TU SO R SANG D." << endl;
				cout << "VAN TOC HIEN TAI CUA XE LA: " << speed << " KM/H" << endl;
				cout << "" << endl;
				menu_selection();
			}
			break;
		default:
			cout << "kHONG HOP LE. MOI BAN NHAP LAI." << endl;
			menu_selection();
			break;
		}
	}
	clearshow;
	cout << "HEN GAP LAI." << endl;

}

//Chương trình chính
int main()
{
	sign_in(password);
	clearshow;
	menu_gear();
}