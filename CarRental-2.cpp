/*
Enter n lines of instructions, each line containing more than 1 parameter
The first parameter of each line is the operation instruction, as follows.
1 means car rental, and when you enter 1, there are 3 parameters behind it, separated by spaces, which indicate the car type, car brand, and capacity, respectively, indicating the requirements of the car to be rented.
  If there is a matching vehicle, display the vehicle information, with each attribute of the vehicle information separated by a space. If there is no vehicle that meets the requirements, output NULL
2 means the car is returned, and when 2 is entered, there is 1 parameter after it, which indicates the car number.
  If the number is the rental car number of the rental company, output BACK, otherwise output ERROR ID
3 means display the list of cars, followed by 0-1 parameters, indicating the required car capacity, the reference can be a number, empty (carriage return directly after 3), other characters
  If the input is a number, all unrented cars of the capacity will be displayed, if there are no cars that meet the requirements, NULL will be displayed
  If you enter NULL, all unrented cars of the capacity are displayed
  If the input is non-numeric or empty (invalid character), output ERROR
4 means displaying inventory with no parameters after it (enter directly after entering 4)
  Output the first line: CNT: total inventory number
  Output the second line: CNT BY BRAND:
  The next m rows of each brand and the corresponding inventory of the brand of cars, separated by spaces, each brand occupies 1 line
  Output row m+3: CNT BY TYPE:
  followed by x rows for each type and the inventory corresponding to that type of car, separated by spaces, 1 row for each type
5 indicates the end of the program



The default vehicle information of the leasing company is as follows��
0001 BMW Sedan 2.0 
0002 BMW Sedan 1.5 
0003 BMW Sedan 1.5 
0004 BMW SUV 2.0 
0005 Benz Sedan 2.0 
0006 Benz SUV 2.0 
0007 Benz Sedan 1.5 
0008 Hummer Truck 2.0 
0009 Hummer SUV 2.0 
0010 Hummer Truck 2.0 


Test cases1��
Input��
1 SUV Benz 2.0
1 Sedan BMW 2.0
2 0001
3
1 SUV Hummer 2.0
4
5

Expected output��
0006 Benz SUV 2.0
0001 BMW Sedan 2.0
BACK
0001 BMW Sedan 2.0
0002 BMW Sedan 1.5
0003 BMW Sedan 1.5
0004 BMW SUV 2.0
0005 Benz Sedan 2.0
0007 Benz Sedan 1.5
0008 Hummer Truck 2.0
0009 Hummer SUV 2.0
0010 Hummer Truck 2.0
CNT:8
CNT BY BRAND:
BMW 4
Benz 2
Hummer 2
CNT BY TYPE:
Sedan 5
SUV 1
Truck 2

Test cases2��
Input��
1 Sedan BMW 2.0
1 Sedan Benz 2.0
2 0005
2 0003
1 SUV Hummer 2.0
3 1.5
4
5

Expected output��
0001 BMW Sedan 2.0
0005 Benz Sedan 2.0
BACK
ERROR ID
0009 Hummer SUV 2.0
0002 BMW Sedan 1.5
0003 BMW Sedan 1.5
0007 Benz Sedan 1.5
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 2
Truck 2


Test cases3��
Input��
1 Sedan Hummer 1.5
1 Sedan Benz 1.5
1 SUV BMW 2.0
1 SUV BMW 2.0
2 0005
3 1.5
2 0007
4
5
Expected output��
NULL
0007 Benz Sedan 1.5
0004 BMW SUV 2.0
NULL
1 Truck Hummer 2.0
0008 Hummer Truck 2.0
ERROR ID
0002 BMW Sedan 1.5
0003 BMW Sedan 1.5
BACK
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 5
SUV 2
Truck 1

Test cases4��
Input��
1 Sedan Benz 2.0
1 Sedan Benz 2.0
1 Sedan BWM 2.0
1 Sedan BWM 2.0
3 2.0
4
2 0010
5
Expected output��
0005 Benz Sedan 2.0
NULL
0001 BMW Sedan 2.0
NULL
0004 BMW SUV 2.0
0006 Benz SUV 2.0
0008 Hummer Truck 2.0
0009 Hummer SUV 2.0
0010 Hummer Truck 2.0
CNT:7
CNT BY BRAND:
BMW 3
Benz 2
Hummer 2
CNT BY TYPE:
Sedan 3
SUV 3
Truck 1
ERROR ID

Test cases5��
Input��
1 Sedan Benz 2.0
1 SUV Benz 2.0
1 SUV Benz 2.0
1 SUV Benz 1.5
3 3.3
3 1.5
1 Truck Hummer 2.0
2 0008
4
5
Expected output��
0005 Benz Sedan 2.0
0006 Benz SUV 2.0
NULL
0007 Benz Sedan 1.5
NULL
0002 BMW Sedan 1.5
0003 BMW Sedan 1.5
0008 Hummer Truck 2.0
BACK
CNT:7
CNT BY BRAND:
BMW 4
Benz 0
Hummer 3
CNT BY TYPE:
Sedan 3
SUV 2
Truck 2


Test cases6��
Input��
1 Sedan BMW 2.0
3 2.a
3 s
1 Sedan Benz 2.0
1 Sedan Benz 1.5
2 0001
4
5
Expected output��
0001 BMW Sedan 2.0 
ERROR
ERROR
0005 Benz Sedan 2.0
0007 Benz Sedan 1.5
BACK
CNT:8
CNT BY BRAND:
BMW 4
Benz 1
Hummer 3
CNT BY TYPE:
Sedan 3
SUV 3
Truck 2



*/

//Code
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//�������޹�˾������������
#define MAXNMB 100


//���������࣬��������������
class Car
{
private:
	string mId; //���
	string mBrand;//����Ʒ��
	string mType;//���� �γ���SUV������
	double mVol; //����

public:
	//�޲ι��캯��
	Car() {
		mId = "";
		mBrand = "";
		mType = "";
		mVol = 1.0;
	}
	//���ι��캯��
	Car(string id, string brand, string type, double vol) {
		mId = id;
		mBrand = brand;
		mType = type;
		mVol = vol;
	}

	//setter Ҳ�����޸�������
	//�����������
	void setId(string id) { mId = id; }  
	//��������Ʒ��
	void setBrand(string brand) { mBrand = brand; }
	//������������
	void setType(string type) { mType = type; }
	//������������
	void setVol(double vol) { mVol = vol; }

	//getter  Ҳ���Ƿ���������
	//��ȡ�������
	string getId() { return mId; }
	//��ȡ����Ʒ��
	string getBrand() { return mBrand; }
	//��ȡ��������
	string getType() { return mType; }
	//��ȡ��������
	double getVol() { return mVol; }

	//��ʾ������Ϣ
	void show()
	{
		cout << mId << " " << mBrand << " " << mType << " ";
		cout <<fixed << setprecision(1) << mVol << endl; //��������1λС��
	}
};

//��������ϵͳ
class CarRental
{
private:
	Car mAllCars[MAXNMB]; //���޹�˾��ӵ�е����г�����Ϣ
	string mOut[MAXNMB];  //�ѳ���ĳ����ı��
	int mNmbAll;  //���޹�˾����������
	int mNmbOut;  //�ѳ������������
private:
	void initCars();  //��ʼ�����޹�˾���еĳ�����Ϣ��������ĿҪ��� Ӳ���� Ҫ��
	void setCarInfo(Car &c, string id, string brand, string type, double vol); //����������Ϣ
	int isout(string id); //���ݳ�������жϸó����Ƿ��Ѿ�����

	void showKcbyBrand(); //����Ʒ����ʾ���
	void showKcbyType(); //����������ʾ���
public:
	CarRental() { initCars(); } //���캯�������캯���е���initCars()������ʼ�����޹�˾����������
	void showList(); //��ʾ�ض������������б�
	void showKc(); //��ʾ���
	void rental(); //����
	void back();  //�黹
};

//����ĳ����������Ϣ
void CarRental::setCarInfo(Car& c, string id, string brand, string type, double vol)
{
	c.setId(id);
	c.setBrand(brand);
	c.setType(type);
	c.setVol(vol);
}

//��ʼ�����޹�˾���еĳ�����Ϣ��Ӳ���룺�����û����뼴������������ϸ��Ϣ��
void CarRental::initCars()
{
	mNmbAll = 10; //��ʼ��������
	mNmbOut = 0; //��ʼ���ѳ��������
	setCarInfo(mAllCars[0], "0001", "BMW", "Sedan", 2.0);
	setCarInfo(mAllCars[1], "0002", "BMW", "Sedan", 1.5);
	setCarInfo(mAllCars[2], "0003", "BMW", "Sedan", 1.5);
	setCarInfo(mAllCars[3], "0004", "BMW", "SUV", 2.0);
	setCarInfo(mAllCars[4], "0005", "Benz", "Sedan", 2.0);
	setCarInfo(mAllCars[5], "0006", "Benz", "SUV", 2.0);
	setCarInfo(mAllCars[6], "0007", "Benz", "Sedan", 1.5);
	setCarInfo(mAllCars[7], "0008", "Hummer", "Truck", 2.0);
	setCarInfo(mAllCars[8], "0009", "Hummer", "SUV", 2.0);
	setCarInfo(mAllCars[9], "0010", "Hummer", "Truck", 2.0);
}

//���ݳ�������жϸó����Ƿ��Ѿ�����
int CarRental::isout(string id)
{
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(id) == 0) //id���ѳ��⳵�������У�����1
			return 1;
	}
	return 0;
}

//��ʾ�ض������������б�
void CarRental::showList()
{
	char buf[20] = { 0 }; //���뻺�棬����ַ���ȡ���Ա��ж�����ĸ�ʽ�Ƿ����Ҫ��
	int i = 0;
	int flag = 0; //�Ƿ���ʾȫ������ flag=1ʱ����ʾ��ʾ��������������
	int cntdot = 0; //С����ĸ���
	int cnt = 0; //����Ҫ��ĳ�������

	
	//cout << "������������";
	cin.get(buf[i]);
	while (1)
	{
		cin.get(buf[i]);
		if (buf[i] == ' ' && i == 0) //����ǿո�
			continue;

		if (buf[i] == '\n') //����س�����
		{
			if (i == 0)
				flag = 1;
			break;
		}
		else
		{
			if (buf[i] >= '0' && buf[i] <= '9')
				i++;
			else if (buf[i] == '.' && cntdot == 0)
			{
				i++;
				cntdot++; //��¼С��������
			}
			else
			{
				cout << "ERROR" << endl;
				//cout << "�������Ϊ��ʽ�淶�����֣�" << endl;
				return;
			}
				
		}
	}

	if (flag == 1) //��ʾ��������������
	{
		for (int i = 0; i < mNmbAll; i++)
		{
			if (!isout(mAllCars[i].getId())) //��ʾ����δ���޵ĳ�����Ϣ
			{
				mAllCars[i].show();
				cnt++;
			}
				
		}
	}
	else
	{
		//��ʾ�ض�����������
		double vol = atof(buf);
		for (int i = 0; i < mNmbAll; i++)
		{
			if ((!isout(mAllCars[i].getId())) && (mAllCars[i].getVol() == vol)) //��ʾ����δ���޵�vol�����ĳ�����Ϣ
			{
				mAllCars[i].show();
				cnt++;
			}
				
		}
	}

	//���û�з��������ĳ���������null
	if (cnt == 0)
		cout << "NULL" << endl;

}

//��ʾ���
void CarRental::showKc()
{
	cout << "CNT:" << mNmbAll - mNmbOut << endl; //�����ǰ�������
	//cout << "��ǰ�ܿ��:" << mNmbAll - mNmbOut << endl; //�����ǰ�������
	//1.����Ʒ����ʾ���
	cout << "CNT BY BRAND:" << endl;
	//cout << "����Ʒ����ʾ���:" << endl;
	showKcbyBrand();
	//2.����������ʾ���
	cout << "CNT BY TYPE:" << endl;
	//cout << "��������������ʾ���:" << endl;
	showKcbyType();
}
//����Ʒ����ʾ��棨���Ϊ0��Ҳ��ʾ��
void CarRental::showKcbyBrand()
{
	string allbrand[MAXNMB]; //�洢����Ʒ��
	int nmbBrand[MAXNMB];    //��Ӧÿ��Ʒ�ƵĿ��
	int cnt = 0; //Ʒ�Ƶĸ���

	for (int i = 0; i < mNmbAll; i++)
	{
		int j = 0;
		//���Ҹ�Ʒ���Ƿ��Ѿ���¼
		for (j = 0; j < cnt; j++)
		{
			if (allbrand[j].compare(mAllCars[i].getBrand()) == 0) //�жϸ�Ʒ���Ƿ��Ѿ���¼
				break;
		}
		if (j < cnt) //����Ѿ���¼
		{
			//�жϸó����Ƿ��Ѿ����⣬����ѳ��⣬��治�䣬����+1
			if (!isout(mAllCars[i].getId()))
				nmbBrand[j] += 1;
		}
		else //��Ʒ����δ��¼
		{
			allbrand[cnt] = mAllCars[i].getBrand();
			//�жϸó����Ƿ��Ѿ����⣬����ѳ��⣬��治�䣬����+1
			if (isout(mAllCars[i].getId()))
				nmbBrand[cnt] = 0;
			else
				nmbBrand[cnt] = 1; //��¼��Ʒ��
			cnt++; //Ʒ������+1
		}
	}
	//��ʾÿ��Ʒ�ƵĿ��
	for (int i = 0; i < cnt; i++)
		cout << allbrand[i] << " " << nmbBrand[i] << endl;

}
//����������ʾ��棨���Ϊ0��Ҳ��ʾ��
void CarRental::showKcbyType()
{
	string allType[MAXNMB]; //�洢��������
	int nmbBrand[MAXNMB];    //��Ӧÿ��Ʒ�ƵĿ��
	int cnt = 0; //Ʒ�Ƶĸ���

	for (int i = 0; i < mNmbAll; i++)
	{
		int j = 0;
		//���Ҹ������Ƿ��Ѿ���¼
		for (j = 0; j < cnt; j++)
		{
			if (allType[j].compare(mAllCars[i].getType()) == 0) //�жϸ������Ƿ��Ѿ���¼
				break;
		}
		if (j < cnt) //����Ѿ���¼
		{
			//�жϸó����Ƿ��Ѿ����⣬����ѳ��⣬��治�䣬����+1
			if (!isout(mAllCars[i].getId()))
				nmbBrand[j] += 1;
		}
		else //��������δ��¼
		{
			allType[cnt] = mAllCars[i].getType();
			//�жϸó����Ƿ��Ѿ����⣬����ѳ��⣬��治�䣬����+1
			if (isout(mAllCars[i].getId()))
				nmbBrand[cnt] = 0;
			else
				nmbBrand[cnt] = 1; //��¼������
			cnt++; //��������+1
		}
	}
	//��ʾÿ�����͵Ŀ��
	for (int i = 0; i < cnt; i++)
		cout << allType[i] << " " << nmbBrand[i] << endl;
}

//���⣬����ͨ��Ӳ����ʵ��
void CarRental::rental()
{
	string type, brand;
	double vol;
	int cnt = 0;
	int index = -1;
	
	//cout << "��������Ҫ���޵��������ͣ�";
	cin >> type;
	//cout << "��������Ҫ���޵�����Ʒ�ƣ�";
	cin >> brand;
	//cout << "������Ҫ���޵�����������";
	cin >> vol;
	//���ҷ��������ġ���δ���������
	for (int i = 0; i < mNmbAll; i++)
	{
		if (mAllCars[i].getBrand().compare(brand) == 0 && mAllCars[i].getType().compare(type) == 0 && mAllCars[i].getVol()==vol && (!isout(mAllCars[i].getId())))
		{
			//mAllCars[i].show();
			index = i;
			//id = mAllCars[i].getId();
			cnt++;
			break;
		}
	}
	if (cnt == 0)
	{
		cout << "NULL" << endl;
		//cout << "δ�ҵ����������ĳ���" << endl;
	}
	else
	{
		mAllCars[index].show();
		mOut[mNmbOut] = mAllCars[index].getId();
		mNmbOut++;
	}
}
//�黹������ͨ��Ӳ����ʵ��
void CarRental::back()
{
	string bk;// = "0005";//�黹�ĳ���
	int flag = 0;
	//cout << "������黹������ţ�";
	//cout << "input car id: ";
	cin >> bk;
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(bk) == 0) //���ҹ黹����ID
		{
			flag = 1; //��ʾ�ҵ�
			for (int j = i; j < mNmbOut - 1; j++) //��bk���ѳ��⳵��������ɾ��
				mOut[j] = mOut[j + 1];
			mNmbOut--;
			cout << "BACK" << endl;
			return;
		}
	}
	if (flag == 0)
		cout << "ERROR ID" << endl; //����ĳ�����Ų��Ǹ����޹�˾������
}

//���Գ���
int main()
{
	CarRental cc;  //���������������ʵ��

	int op;

	while (1)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cc.rental(); break;//��������
		case 2:
			cc.back(); break;//�����黹
		case 3:
			cc.showList(); break; //����������ʾ���������б�
		case 4:
			cc.showKc(); break; //��ʾ���
		case 5:
			return 0;
		}
		
	}


}







