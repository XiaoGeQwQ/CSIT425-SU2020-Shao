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
	cout << "Please enter capacity��";
	while (1)
	{
		cin.get(buf[i]);
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
				cout << "ERROR!" << endl;
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
	mOut[0] = "0003";
	mOut[1] = "0005";
	mOut[2] = "0008";
	mNmbOut = 3;
}
//�黹������ͨ��Ӳ����ʵ��
void CarRental::back()
{
	string bk = "0005";//�黹�ĳ���
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(bk) == 0) //���ҹ黹����ID
		{
			for (int j = i; j < mNmbOut - 1; j++) //��bk���ѳ��⳵��������ɾ��
				mOut[j] = mOut[j + 1];
			mNmbOut--;
		}
	}
}

//���Գ���
int main()
{
	CarRental cc;  //���������������ʵ��
	cc.rental(); //��������
	cc.back(); //�����黹
	cc.showList(); //����������ʾ���������б�
	cc.showKc(); //��ʾ���
	return 0;
}

/*
��������1������Ϊ��ʱ�����Ϊ���������ġ���δ�������������
���룺�գ�Ҳ����ֱ������س���
���������
0001 BMW Sedan 2.0
0002 BMW Sedan 1.5
0004 BMW SUV 2.0
0005 Benz Sedan 2.0
0006 Benz SUV 2.0
0007 Benz Sedan 1.5
0009 Hummer SUV 2.0
0010 Hummer Truck 2.0
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 3
Truck 1

��������2��
���룺1.5
���������
0002 BMW Sedan 1.5
0007 Benz Sedan 1.5
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 3
Truck 1


��������3��
���룺2
���������
0001 BMW Sedan 2.0
0004 BMW SUV 2.0
0005 Benz Sedan 2.0
0006 Benz SUV 2.0
0009 Hummer SUV 2.0
0010 Hummer Truck 2.0
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 3
Truck 1



��������4��
���룺2.5
���������
NULL
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 3
Truck 1



��������5��
���룺2.A
���������
ERROR!
CNT:8
CNT BY BRAND:
BMW 3
Benz 3
Hummer 2
CNT BY TYPE:
Sedan 4
SUV 3
Truck 1



*/


