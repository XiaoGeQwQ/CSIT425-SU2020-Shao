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
	cout << "Please enter capacity：";
	while (1)
	{
		cin.get(buf[i]);
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
				cout << "ERROR!" << endl;
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
	mOut[0] = "0003";
	mOut[1] = "0005";
	mOut[2] = "0008";
	mNmbOut = 3;
}
//归还，这里通过硬编码实现
void CarRental::back()
{
	string bk = "0005";//归还的车辆
	for (int i = 0; i < mNmbOut; i++)
	{
		if (mOut[i].compare(bk) == 0) //查找归还车辆ID
		{
			for (int j = i; j < mNmbOut - 1; j++) //把bk从已出租车辆数组中删除
				mOut[j] = mOut[j + 1];
			mNmbOut--;
		}
	}
}

//测试程序
int main()
{
	CarRental cc;  //声明汽车租赁类的实例
	cc.rental(); //汽车出租
	cc.back(); //汽车归还
	cc.showList(); //根据容量显示所有汽车列表
	cc.showKc(); //显示库存
	return 0;
}

/*
测试用例1（输入为空时，输出为所有容量的、尚未出租的汽车）：
输入：空（也就是直接输入回车）
期望输出：
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

测试用例2：
输入：1.5
期望输出：
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


测试用例3：
输入：2
期望输出：
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



测试用例4：
输入：2.5
期望输出：
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



测试用例5：
输入：2.A
期望输出：
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


