

/*
 * Date:2021-12-28 10:27
 * filename:02_继承中的函数调用的输出问题.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class MD {
protected:
	float miles;

public:
	void setDist(float d) {
		miles = d;
	}
	virtual float getDist() {
		return miles;
	}
	float square() {
		return getDist() * getDist();
	}
};

class FeetDist : public MD {
protected:
	float feet;
public:
	void setDist(float);
	float getDist() {
		return feet;
	}
	float getMiles() {
		return miles;
	}
};

void FeetDist::setDist(float ft) {
	feet = ft;
	MD::setDist(feet / 2);
}

int main() {
	FeetDist feet;
	feet.setDist(8);
	cout << feet.getDist() << "," << feet.getMiles() << "," << feet.square() << endl;
}

//feet.setDist() 调用FeetDist中的setDist 那么feet = 8;
//然后调用MD::setDist(feet / 2);
//miles = 4
//因为Feet中没有实现MD中的getMile的方法，就用MD::getMile()

//feet.square() = FeetDist::getDist() * MD::getDist(); 错误
//feet.square() = FeetDist::getDist() * FeetDist::getDist();
