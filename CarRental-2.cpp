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



The default vehicle information of the leasing company is as follows：
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


Test cases1：
Input：
1 SUV Benz 2.0
1 Sedan BMW 2.0
2 0001
3
1 SUV Hummer 2.0
4
5

Expected output：
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

Test cases2：
Input：
1 Sedan BMW 2.0
1 Sedan Benz 2.0
2 0005
2 0003
1 SUV Hummer 2.0
3 1.5
4
5

Expected output：
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


Test cases3：
Input：
1 Sedan Hummer 1.5
1 Sedan Benz 1.5
1 SUV BMW 2.0
1 SUV BMW 2.0
2 0005
3 1.5
2 0007
4
5
Expected output：
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

Test cases4：
Input：
1 Sedan Benz 2.0
1 Sedan Benz 2.0
1 Sedan BWM 2.0
1 Sedan BWM 2.0
3 2.0
4
2 0010
5
Expected output：
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

Test cases5：
Input：
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
Expected output：
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


Test cases6：
Input：
1 Sedan BMW 2.0
3 2.a
3 s
1 Sedan Benz 2.0
1 Sedan Benz 1.5
2 0001
4
5
Expected output：
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

//定义租赁公司最大的汽车数量
#define MAXNMB 100


//定义汽车类，包含汽车的属性
class Car
{
private:
	string mId; //编号
	string mBrand;//汽车品牌
	string mType;//类型 轿车、SUV、卡车
	double mVol; //容量

public:
	//无参构造函数
	Car() {
		mId = "";
		mBrand = "";
		mType = "";
		mVol = 1.0;
	}
	//带参构造函数
	Car(string id, string brand, string type, double vol) {
		mId = id;
		mBrand = brand;
		mType = type;
		mVol = vol;
	}

	//setter 也就是修改器函数
	//设置汽车编号
	void setId(string id) { mId = id; }  
	//设置汽车品牌
	void setBrand(string brand) { mBrand = brand; }
	//设置汽车类型
	void setType(string type) { mType = type; }
	//设置汽车容量
	void setVol(double vol) { mVol = vol; }

	//getter  也就是访问器函数
	//获取汽车编号
	string getId() { return mId; }
	//获取汽车品牌
	string getBrand() { return mBrand; }
	//获取汽车类型
	string getType() { return mType; }
	//获取汽车容量
	double getVol() { return mVol; }

	//显示车辆信息
	void show()
	{
		cout << mId << " " << mBrand << " " << mType << " ";
		cout <<fixed << setprecision(1) << mVol << endl; //容量保留1位小数
	}
};

//汽车租赁系统
class CarRental
{
private:
	Car mAllCars[MAXNMB]; //租赁公司所拥有的所有车辆信息
	string mOut[MAXNMB];  //已出租的车辆的编号
	int mNmbAll;  //租赁公司的汽车数量
	int mNmbOut;  //已出租的汽车数量
private:
	void initCars();  //初始化租赁公司所有的车辆信息（满足题目要求的 硬编码 要求）
	void setCarInfo(Car &c, string id, string brand, string type, double vol); //设置汽车信息
	int isout(string id); //根据车辆编号判断该车辆是否已经出租

	void showKcbyBrand(); //根据品牌显示库存
	void showKcbyType(); //根据类型显示库存
public:
	CarRental() { initCars(); } //构造函数，构造函数中调用initCars()函数初始化租赁公司的所有汽车
	void showList(); //显示特定容量的汽车列表
	void showKc(); //显示库存
	void rental(); //出租
	void back();  //归还
};

//设置某辆汽车的信息
void CarRental::setCarInfo(Car& c, string id, string brand, string type, double vol)
{
	c.setId(id);
	c.setBrand(brand);
	c.setType(type);
	c.setVol(vol);
}

//初始化租赁公司所有的车辆信息（硬编码：无需用户输入即可输入汽车详细信息）
void CarRental::initCars()
{
	mNmbAll = 10; //初始车辆数量
	mNmbOut = 0; //初始化已出租的数量
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

//根据车辆编号判断该车辆是否已经出租
int CarRental::isout(string id)
{
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(id) == 0) //id在已出租车辆数组中，返回1
			return 1;
	}
	return 0;
}

//显示特定容量的汽车列表
void CarRental::showList()
{
	char buf[20] = { 0 }; //输入缓存，逐个字符读取，以便判断输入的格式是否符合要求
	int i = 0;
	int flag = 0; //是否显示全部汽车 flag=1时，表示显示所有容量的汽车
	int cntdot = 0; //小数点的个数
	int cnt = 0; //符合要求的车辆个数

	
	//cout << "请输入容量：";
	cin.get(buf[i]);
	while (1)
	{
		cin.get(buf[i]);
		if (buf[i] == ' ' && i == 0) //如果是空格
			continue;

		if (buf[i] == '\n') //输入回车结束
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
				cntdot++; //记录小数点数量
			}
			else
			{
				cout << "ERROR" << endl;
				//cout << "输入必须为格式规范的数字！" << endl;
				return;
			}
				
		}
	}

	if (flag == 1) //显示所有容量的汽车
	{
		for (int i = 0; i < mNmbAll; i++)
		{
			if (!isout(mAllCars[i].getId())) //显示所有未租赁的车辆信息
			{
				mAllCars[i].show();
				cnt++;
			}
				
		}
	}
	else
	{
		//显示特定容量的汽车
		double vol = atof(buf);
		for (int i = 0; i < mNmbAll; i++)
		{
			if ((!isout(mAllCars[i].getId())) && (mAllCars[i].getVol() == vol)) //显示所有未租赁的vol容量的车辆信息
			{
				mAllCars[i].show();
				cnt++;
			}
				
		}
	}

	//如果没有符合条件的车辆，输入null
	if (cnt == 0)
		cout << "NULL" << endl;

}

//显示库存
void CarRental::showKc()
{
	cout << "CNT:" << mNmbAll - mNmbOut << endl; //输出当前库存数量
	//cout << "当前总库存:" << mNmbAll - mNmbOut << endl; //输出当前库存数量
	//1.根据品牌显示库存
	cout << "CNT BY BRAND:" << endl;
	//cout << "根据品牌显示库存:" << endl;
	showKcbyBrand();
	//2.根据类型显示库存
	cout << "CNT BY TYPE:" << endl;
	//cout << "根据汽车类型显示库存:" << endl;
	showKcbyType();
}
//根据品牌显示库存（库存为0的也显示）
void CarRental::showKcbyBrand()
{
	string allbrand[MAXNMB]; //存储所有品牌
	int nmbBrand[MAXNMB];    //对应每个品牌的库存
	int cnt = 0; //品牌的个数

	for (int i = 0; i < mNmbAll; i++)
	{
		int j = 0;
		//查找该品牌是否已经记录
		for (j = 0; j < cnt; j++)
		{
			if (allbrand[j].compare(mAllCars[i].getBrand()) == 0) //判断该品牌是否已经记录
				break;
		}
		if (j < cnt) //如果已经记录
		{
			//判断该车辆是否已经出租，如果已出租，库存不变，否则+1
			if (!isout(mAllCars[i].getId()))
				nmbBrand[j] += 1;
		}
		else //该品牌尚未记录
		{
			allbrand[cnt] = mAllCars[i].getBrand();
			//判断该车辆是否已经出租，如果已出租，库存不变，否则+1
			if (isout(mAllCars[i].getId()))
				nmbBrand[cnt] = 0;
			else
				nmbBrand[cnt] = 1; //记录该品牌
			cnt++; //品牌数量+1
		}
	}
	//显示每种品牌的库存
	for (int i = 0; i < cnt; i++)
		cout << allbrand[i] << " " << nmbBrand[i] << endl;

}
//根据类型显示库存（库存为0的也显示）
void CarRental::showKcbyType()
{
	string allType[MAXNMB]; //存储所有类型
	int nmbBrand[MAXNMB];    //对应每个品牌的库存
	int cnt = 0; //品牌的个数

	for (int i = 0; i < mNmbAll; i++)
	{
		int j = 0;
		//查找该类型是否已经记录
		for (j = 0; j < cnt; j++)
		{
			if (allType[j].compare(mAllCars[i].getType()) == 0) //判断该类型是否已经记录
				break;
		}
		if (j < cnt) //如果已经记录
		{
			//判断该车辆是否已经出租，如果已出租，库存不变，否则+1
			if (!isout(mAllCars[i].getId()))
				nmbBrand[j] += 1;
		}
		else //该类型尚未记录
		{
			allType[cnt] = mAllCars[i].getType();
			//判断该车辆是否已经出租，如果已出租，库存不变，否则+1
			if (isout(mAllCars[i].getId()))
				nmbBrand[cnt] = 0;
			else
				nmbBrand[cnt] = 1; //记录该类型
			cnt++; //类型数量+1
		}
	}
	//显示每种类型的库存
	for (int i = 0; i < cnt; i++)
		cout << allType[i] << " " << nmbBrand[i] << endl;
}

//出租，这里通过硬编码实现
void CarRental::rental()
{
	string type, brand;
	double vol;
	int cnt = 0;
	int index = -1;
	
	//cout << "请输入需要租赁的汽车类型：";
	cin >> type;
	//cout << "请输入需要租赁的汽车品牌：";
	cin >> brand;
	//cout << "请输入要租赁的汽车容量：";
	cin >> vol;
	//查找符合条件的、尚未出租的汽车
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
		//cout << "未找到符合条件的车辆" << endl;
	}
	else
	{
		mAllCars[index].show();
		mOut[mNmbOut] = mAllCars[index].getId();
		mNmbOut++;
	}
}
//归还，这里通过硬编码实现
void CarRental::back()
{
	string bk;// = "0005";//归还的车辆
	int flag = 0;
	//cout << "请输入归还车辆编号：";
	//cout << "input car id: ";
	cin >> bk;
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(bk) == 0) //查找归还车辆ID
		{
			flag = 1; //表示找到
			for (int j = i; j < mNmbOut - 1; j++) //把bk从已出租车辆数组中删除
				mOut[j] = mOut[j + 1];
			mNmbOut--;
			cout << "BACK" << endl;
			return;
		}
	}
	if (flag == 0)
		cout << "ERROR ID" << endl; //输入的车辆编号不是该租赁公司的汽车
}

//测试程序
int main()
{
	CarRental cc;  //声明汽车租赁类的实例

	int op;

	while (1)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cc.rental(); break;//汽车出租
		case 2:
			cc.back(); break;//汽车归还
		case 3:
			cc.showList(); break; //根据容量显示所有汽车列表
		case 4:
			cc.showKc(); break; //显示库存
		case 5:
			return 0;
		}
		
	}


}







